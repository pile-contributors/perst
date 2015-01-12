/**
 * @file perst.cc
 * @brief Definitions for PerStQXml class.
 * @author 
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "perst_qxml.h"
#include "../perst-private.h"

/**
 * @class PerStQXml
 *
 *
 */
const PERST_STRING PerStQXml::XML = "xml";

/* ------------------------------------------------------------------------- */
/**
 * Only the implementation is allowed to use the constructor.
 */
PerStQXml::PerStQXml(const PERST_STRING & file) :
    PerSt()
{
    PERST_TRACE_ENTRY;
    setLocation (file);
    PERST_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * .
 */
PerStQXml::~PerStQXml()
{
    PERST_TRACE_ENTRY;

    PERST_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::beginGroup(const PERST_STRING &name)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::endGroup(const PERST_STRING &name)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::beginWriteArray(const PERST_STRING &name, int predicted_count)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int PerStQXml::beginReadArray(const PERST_STRING &name)
{
    //! @todo
    return 0;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::endArray(const PERST_STRING &name)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::setArrayIndex(int index)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::hasKey(const PERST_STRING &name)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::hasKey(const PERST_SLIST &name)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_STRING PerStQXml::valueS (const PERST_STRING &name)
{
    //! @todo
    return "";
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_SLIST PerStQXml::valueSList (const PERST_STRING &name)
{
    //! @todo
    return PERST_SLIST();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int64_t PerStQXml::valueInt (const PERST_STRING &name)
{
    //! @todo
    return 0;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
uint64_t PerStQXml::valueUInt (const PERST_STRING &name)
{
    //! @todo
    return 0;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
double PerStQXml::valueDbl (const PERST_STRING &name)
{
    //! @todo
    return 0.0;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::setValue (
        const PERST_STRING &name, const PERST_STRING & value)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::setValue (
        const PERST_STRING &name, const PERST_SLIST &value)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::setValue(const PERST_STRING &name, int64_t value)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::setValue(const PERST_STRING &name, uint64_t value)
{
    //! @todo
    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQXml::setValue(const PERST_STRING &name, double value)
{
    //! @todo
    return true;
}
/* ========================================================================= */
