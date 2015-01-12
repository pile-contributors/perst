/**
 * @file perst.h
 * @brief Declarations for PerSt class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_PERST_H_INCLUDE
#define GUARD_PERST_H_INCLUDE

#include <perst/perst-config.h>
#include <stdint.h>

//! Interface class for persistent storage
class PERST_EXPORT PerSt {

public:
    struct KbData;

    //! Indicate the type of an entry.
    enum EntryType {
        EGROUP, /**< The entry is a group. */
        EARRAY, /**< The entry is an array. */
        EVALUE  /**< The entry is a value. */
    };

    //! Values that the kbForEach can return
    enum KbForEachResult {
        KBFER_CONTINUE, /**< Normal return, iteration continues. */
        KBFER_BREAK, /**< Break iteration, exit immediatelly. */
        KBFER_SKIP_KIDS /**< Same as continue but skip kids, if any. */
    };

    //! Callback used for iteration; use false to terminate.
    typedef KbForEachResult (*kbForEach) (
            KbData * data,
            const PERST_STRING & name,
            EntryType kind);

    //! Structure used for iterating the whole tree.
    struct KbData {
        kbForEach group_start_;
        kbForEach group_end_;
        kbForEach array_start_;
        kbForEach array_end_;
        kbForEach value_;
        void * opaque_;
    };

protected:

    //! Default constructor.
    PerSt ();

public:

    //! Destructor.
    virtual ~PerSt();

    //! Storage location
    virtual PERST_STRING location () {
        return location_;
    }

    //! Starts a group; internal state is altered.
    virtual bool
    beginGroup (
            const PERST_STRING & name) = 0;

    //! Ends a group; internal state is altered.
    virtual bool
    endGroup (
            const PERST_STRING & name = "") = 0;

    //! Starts writing an array; internal state is altered.
    virtual bool
    beginWriteArray (
            const PERST_STRING & name,
            int predicted_count = -1) = 0;

    //! Starts reading an array; internal state is altered.
    virtual int
    beginReadArray (
            const PERST_STRING & name) = 0;

    //! Ends an array; internal state is altered.
    virtual bool
    endArray (
            const PERST_STRING & name = "") = 0;

    //! Get current index of an array.
    int
    arrayIndex () const {
        return array_index_;
    }

    //! Set current index of an array.
    virtual bool
    setArrayIndex (
            int index) = 0;

    //! Tell the name of current group (arrays are also groups).
    PERST_STRING
    group () const {
        return current_group_name_;
    }

    //! Tell the full path of current group (arrays are also groups).
    PERST_SLIST
    groupPath () const {
        return current_group_path_;
    }

    //! Tell if a given key exists (relative to current group).
    virtual bool
    hasKey (
            const PERST_STRING & name) = 0;

    //! Tell if a given path exists (relative to current group).
    virtual bool
    hasKey (
            const PERST_SLIST & name) = 0;


    //! Get the string value for a key; the value type MUST be string.
    virtual PERST_STRING
    valueS (
            const PERST_STRING & name) = 0;

    //! Get the string list for a key; the value type MUST be an array of strings.
    virtual PERST_SLIST
    valueSList (
            const PERST_STRING & name) = 0;

    //! Get the integer value for a key; the value type MUST be integer.
    virtual int64_t
    valueInt (
            const PERST_STRING & name) = 0;

    //! Get the integer value for a key; the value type MUST be integer.
    virtual uint64_t
    valueUInt (
            const PERST_STRING & name) = 0;

    //! Get the real value for a key; the value type MUST be real.
    virtual double
    valueDbl (
            const PERST_STRING & name) = 0;

    //! Set the string value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const PERST_STRING & value) = 0;

    //! Set the string list for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const PERST_SLIST & value) = 0;

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            int64_t value) = 0;

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            uint64_t value) = 0;

    //! Set the real value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            double value) = 0;


protected:

    //! Alters internal state by appending the group name.
    bool
    beginGroupInternal (
            const PERST_STRING & name);

    //! Alters internal state by removing last group name.
    bool
    endGroupInternal (
            const PERST_STRING &name = "");

    //! Makes sure that a value can be saved.
    bool
    preSaveValue (
            const PERST_STRING & name);


    //! Storage location
    virtual void setLocation (
            const PERST_STRING & value) {
        location_ = value;
    }

private:
    PERST_STRING location_; /**< Location of the storage (may be a file). */
    PERST_SLIST current_group_path_; /**< List of elements; last one is current group.*/
    PERST_STRING current_group_name_; /**< Current group's name. */
    int array_index_; /**< current index in the array, if any */

};

#endif // GUARD_PERST_H_INCLUDE
