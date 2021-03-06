/**
 * @file perst.cc
 * @brief Definitions for PerSt class.
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#include "perst.h"
#include "perst-private.h"

/**
 * @class PerSt
 *
 * The string type is currently either QString, if Qt is available, or
 * std::string.
 *
 * The class maintains an internal group path; as a result even
 * read methods are not const.
 */

/* ------------------------------------------------------------------------- */
/**
 * Only the implementation is allowed to use the constructor.
 */
PerSt::PerSt() :
    location_(),
    current_group_path_(),
    current_group_name_(),
    array_index_(-1),
    array_indexes_()
{
    PERST_TRACE_ENTRY;
    PERST_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * .
 */
PerSt::~PerSt()
{
    PERST_TRACE_ENTRY;

    PERST_TRACE_EXIT;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::beginGroup
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::endGroup
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::beginWriteArray
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::beginReadArray
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::endArray
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::arrayIndex
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::setArrayIndex
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::group
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::groupPath
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::hasKey(PERST_STRING)
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::hasKey(PERST_SLIST)
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::valueS
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::valueSList
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::valueInt
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::valueDbl
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @func PerSt::setValue
 * .
 */
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * The method begins a new group with the index as name.
 *
 * @return false if the index is negative.
 */
bool PerSt::setArrayIndexInternal (int value)
{
    if (value < 0) return false;
    if (array_index_ >= 0) {
        endGroupInternal (
                    PERST_STRING::number (array_index_));
    }
    bool b_ret = beginGroupInternal (PERST_STRING::number (value));
    array_index_ = value;
    array_indexes_.back () = value;
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * The method ends the group with the index as name.
 *
 * @return false if we're not inside an array.
 */
bool PerSt::endArrayInternal (const PERST_STRING & name)
{
    if (array_index_ < 0) return false;
    bool b_ret = endGroupInternal (PERST_STRING::number (array_index_));
    array_index_ = -1;
    array_indexes_.back () = array_index_;
    b_ret = b_ret & endGroupInternal (name);
    return b_ret;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @return false if the name is empty, true otherwise.
 */
bool PerSt::beginGroupInternal (const PERST_STRING & name)
{
    if (name.length () == 0) return false;

    current_group_name_ = name;
    current_group_path_.push_back (name);
    array_index_ = -1;
    array_indexes_.push_back (array_index_);

    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @return false if we're at the root or the name does not match, true otherwise.
 */
bool PerSt::endGroupInternal (const PERST_STRING &name)
{
    if (current_group_path_.size() == 0) return false;
    if (name.size() > 0) {
        if (name != current_group_name_) {
            return false;
        }
    }

    array_indexes_.pop_back();
    if (array_indexes_.empty ()) {
        array_index_ = -1;
    } else {
        array_index_ = array_indexes_.back();
    }

    current_group_path_.pop_back();
    if (current_group_path_.empty ()) {
        current_group_name_.clear();
    } else {
        current_group_name_ = current_group_path_.back();
    }

    return true;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
/**
 * @return false if no group is defined or name is empty.
 */
bool PerSt::preSaveValue (const PERST_STRING & name)
{
    if (name.length () == 0) return false;
    if (current_group_name_.size() == 0) return false;

    return true;
}
/* ========================================================================= */

void PerSt::anchorVtable() const {}
