/**
 * @file perst.cc
 * @brief Definitions for PerStQSettings class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "perst_qsettings.h"
#include "../perst-private.h"

#include <QDebug>

/**
 * @class PerStQSettings
 *
 *
 */
const PERST_STRING PerStQSettings::REGS = "registry";
const PERST_STRING PerStQSettings::INI = "config";

/* ------------------------------------------------------------------------- */
/**
 * Only the implementation is allowed to use the constructor.
 */
PerStQSettings::PerStQSettings(const PERST_STRING & file, Mode md) :
    PerSt(),
    backend_(file, md == MODE_INI ? QSettings::IniFormat : QSettings::NativeFormat)
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
PerStQSettings::~PerStQSettings()
{
    PERST_TRACE_ENTRY;
    PERST_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::beginGroup (const PERST_STRING &name)
{
    bool b_res = beginGroupInternal (name);
    if (b_res) {
        backend_.beginGroup (name);
    }
    return b_res;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::endGroup(const PERST_STRING &name)
{
    bool b_res = endGroupInternal (name);
    if (b_res) {
        backend_.endGroup ();
    }
    return b_res;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::beginWriteArray (
        const PERST_STRING &name, int predicted_count)
{
    bool b_res = beginGroupInternal (name);
    if (b_res) {
        //b_res = setArrayIndexInternal (0);
        backend_.beginWriteArray (name, predicted_count);
        b_res = b_res & setArrayIndex (0);
    }
    return b_res;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int PerStQSettings::beginReadArray (const PERST_STRING &name)
{
    int result = -1;
    bool b_res = beginGroupInternal (name);
    if (b_res) {
        //b_res = setArrayIndexInternal (0);
        if (b_res) {
            result = backend_.beginReadArray (name);
            b_res = b_res & setArrayIndex (0);
        }
    }
    return result;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::endArray (const PERST_STRING &name)
{
    bool b_res = endArrayInternal (name);
    if (b_res) {
        backend_.endArray ();
    }
    return b_res;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setArrayIndex (int index)
{
    if (index < 0) return false;
    bool b_ret = setArrayIndexInternal (index);
    if (b_ret)
        backend_.setArrayIndex (index);
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::hasKey (const PERST_STRING &name)
{
    return backend_.contains (name);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::hasKey (const PERST_SLIST &name)
{
#   ifndef PILES_HAVE_QT
#   error "Can't have QSettings but no QStrings"
#   endif // PILES_HAVE_QT
    return backend_.contains (name.join ("/"));
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_STRING PerStQSettings::valueS(const PERST_STRING &name)
{
    return backend_.value (name).toString ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_SLIST PerStQSettings::valueSList(const PERST_STRING &name)
{
    return backend_.value (name).toStringList ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int64_t PerStQSettings::valueInt (const PERST_STRING &name)
{
    return backend_.value (name).toLongLong ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
uint64_t PerStQSettings::valueUInt (const PERST_STRING &name)
{
    return backend_.value (name).toULongLong ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
double PerStQSettings::valueDbl(const PERST_STRING &name)
{
    return backend_.value (name).toDouble ();
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue(
        const PERST_STRING &name, const PERST_STRING & value)
{
    if (!preSaveValue(name)) return false;
    backend_.setValue (name, value);
    return backend_.status () == QSettings::NoError;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue (
        const PERST_STRING &name, const PERST_SLIST &value)
{
    if (!preSaveValue(name)) return false;
    backend_.setValue (name, value);
    return backend_.status () == QSettings::NoError;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue (const PERST_STRING &name, int64_t value)
{
    if (!preSaveValue(name)) return false;
    backend_.setValue (name, (qint64)value);
    return backend_.status () == QSettings::NoError;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue (const PERST_STRING &name, uint64_t value)
{
    if (!preSaveValue(name)) return false;
    backend_.setValue (name, (quint64)value);
    return backend_.status () == QSettings::NoError;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue (const PERST_STRING &name, double value)
{
    if (!preSaveValue(name)) return false;
    backend_.setValue (name, value);
    return backend_.status () == QSettings::NoError;
}
/* ========================================================================= */
