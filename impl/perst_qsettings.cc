/**
 * @file perst.cc
 * @brief Definitions for PerStQSettings class.
 * @author
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "perst_qsettings.h"
#include "../perst-private.h"

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
    PerSt()
{
    PERST_TRACE_ENTRY;

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
bool PerStQSettings::beginGroup(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::endGroup()
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::beginWriteArray(const PERST_STRING &name, int predicted_count)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int PerStQSettings::beginReadArray(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::endArray()
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setArrayIndex(int index)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::hasKey(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::hasKey(const PERST_SLIST &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_STRING PerStQSettings::valueS(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
PERST_SLIST PerStQSettings::valueSList(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int64_t PerStQSettings::valueInt(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
double PerStQSettings::valueDbl(const PERST_STRING &name)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue(
        const PERST_STRING &name, const PERST_STRING & value)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue (
        const PERST_STRING &name, const PERST_SLIST &value)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue(const PERST_STRING &name, int64_t value)
{

}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
bool PerStQSettings::setValue(const PERST_STRING &name, double value)
{

}
/* ========================================================================= */
