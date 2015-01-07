/**
 * @file perst_factory.cc
 * @brief Definitions for PerSt class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "perst_factory.h"
#include "perst.h"
#include "perst-private.h"
#include "impl/perst_qsettings.h"
#include "impl/perst_qxml.h"

/**
 * @class PerStFactory
 *
 */
PerStFactory * PerStFactory::singleton_ = NULL;

//! A provider.
struct PerStProvider {
    const PERST_STRING & name_;
    PerStFactory::kbCreate kb_;
    void * user_data_;

    PerStProvider (
            const PERST_STRING & name, PerStFactory::kbCreate kb,
            void * user_data) :
        name_(name),
        kb_(kb),
        user_data_(user_data)
    {}
};


PerStFactory::PerStFactory() :
    providers_()
{}

PerStFactory::PerStFactory(const PerStFactory & other) :
    providers_(other.providers_)
{}

PerStFactory::~PerStFactory()
{}


/* ------------------------------------------------------------------------- */
/**
 * Creates the singleton.
 */
void PerStFactory::init()
{
    autocreate();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * Deletes the singleton.
 */
void PerStFactory::end()
{
    if (singleton_ != NULL) {
        std::list<PerStProvider*>::iterator i =
                singleton_->providers_.begin();
        std::list<PerStProvider*>::iterator i_end =
                singleton_->providers_.end();
        for(; i != i_end; ++i) {
            delete *i;
        }
        delete singleton_;
        singleton_ = NULL;
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * Creates the singleton if it does not already exists.
 */
void PerStFactory::autocreate()
{
    if (singleton_ == NULL) {
        singleton_ = new PerStFactory();
    }
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 */
PerStProvider *PerStFactory::find (const PERST_STRING &name)
{
    PerStProvider * result = NULL;
    PerStProvider * result_tmp = NULL;
    PERST_TRACE_ENTRY;

    std::list<PerStProvider*>::iterator i =
            providers_.begin();
    std::list<PerStProvider*>::iterator i_end =
            providers_.end();

    if ((name.size() > 0) && (providers_.size () > 0))  {
        for(; i != i_end; ++i) {
            result_tmp = *i;
            if (result_tmp->name_ == name) {
                result = result_tmp;
                break;
            }
        }
    }

    PERST_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 * The method creates the singleton if it does not already exists.
 */
PerSt * PerStFactory::create(
        const PERST_STRING &name, const PERST_STRING &value)
{
    PerSt * result = NULL;
    PERST_TRACE_ENTRY;
    autocreate();

    for (;;) {

        // find in custom providers
        PerStProvider * provider = singleton_->find (name);
        if (provider != NULL) {
            result = provider->kb_ (name, value, provider->user_data_);
            break;
        }

        // find in built-in providers

#       ifdef PERST_WITH_QSETTINGS
#       ifdef WIN32
        if (name == PerStQSettings::REGS) {
            result = new PerStQSettings (value, PerStQSettings::MODE_REGS);
            break;
        }
#       endif // WIN32
        if (name == PerStQSettings::INI) {
            result = new PerStQSettings (value, PerStQSettings::MODE_INI);
            break;
        }
#       endif // PERST_WITH_QSETTINGS


#       ifdef PERST_WITH_QXML
        if (name == PerStQXml::XML) {
            result = new PerStQXml (value);
            break;
        }
#       endif // PERST_WITH_QXML

        break;
    }

    PERST_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 * The method creates the singleton if it does not already exists.
 */
bool PerStFactory::addProvider (
        const PERST_STRING &name, PerStFactory::kbCreate kb, void *user_data)
{
    bool result = false;
    PERST_TRACE_ENTRY;
    autocreate();

    for (;;) {
        if (name.size() == 0) break;
        if (kb == NULL) break;

        // find in custom providers
        PerStProvider * provider = singleton_->find (name);
        if (provider != NULL) {
            provider->kb_ = kb;
            provider->user_data_ = user_data;
        } else {
            provider = new PerStProvider (name, kb, user_data);
            singleton_->providers_.push_back (provider);
        }

        break;
    }

    PERST_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 * The method creates the singleton if it does not already exists.
 */
bool PerStFactory::delProvider (const PERST_STRING &name)
{
    bool result = false;
    PERST_TRACE_ENTRY;
    autocreate();

    for (;;) {
        PerStProvider * provider = singleton_->find (name);
        if (provider == NULL) break;

        singleton_->providers_.remove (provider);
        break;
    }

    PERST_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 * The method creates the singleton if it does not already exists.
 */
bool PerStFactory::hasProvider (const PERST_STRING &name)
{
    bool result = false;
    PERST_TRACE_ENTRY;
    autocreate();

    PerStProvider * provider = singleton_->find (name);
    result = (provider != NULL);

    PERST_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 *
 * The method creates the singleton if it does not already exists.
 */
bool PerStFactory::forEachProvider (
        PerStFactory::kbForEach kb, void *for_each_user_data)
{
    bool result = true;
    PERST_TRACE_ENTRY;
    autocreate();

    int index = 0;
    if (singleton_->providers_.size () > 0)  {
        PerStProvider * prov = NULL;
        std::list<PerStProvider*>::iterator i =
                singleton_->providers_.begin();
        std::list<PerStProvider*>::iterator i_end =
                singleton_->providers_.end();
        for(; i != i_end; ++i) {
            prov = *i;
            result = kb (
                        index,
                        prov->name_,
                        prov->kb_,
                        prov->user_data_,
                        for_each_user_data);
            if (!result) break;
            index++;
        }
    }

    for(;;) {
        if (!result) break;

#       ifdef PERST_WITH_QSETTINGS
#       ifdef WIN32
        result = kb (
                    index,
                    PerStQSettings::REGS,
                    NULL,
                    NULL,
                    for_each_user_data);
        if (!result) break;
        index++;
#       endif // WIN32
        result = kb (
                    index,
                    PerStQSettings::INI,
                    NULL,
                    NULL,
                    for_each_user_data);
        if (!result) break;
        index++;
#       endif // PERST_WITH_QSETTINGS


#       ifdef PERST_WITH_QXML
        result = kb (
                    index,
                    PerStQXml::XML,
                    NULL,
                    NULL,
                    for_each_user_data);
        if (!result) break;
        index++;
#       endif // PERST_WITH_QXML

        break;
    }

    PERST_TRACE_EXIT;
    return result;
}
/* ========================================================================= */

