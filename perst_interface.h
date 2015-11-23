/**
 * @file perst.h
 * @brief Declarations for PerSt class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_PERST_INTERFACE_H_INCLUDE
#define GUARD_PERST_INTERFACE_H_INCLUDE

#include <perst/perst-config.h>
#include <stdint.h>

//! Interface class for persistent storage
class PERST_EXPORT PerstInterface {

public:

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
    virtual int
    arrayIndex () const = 0;

    //! Set current index of an array.
    virtual bool
    setArrayIndex (
            int index) = 0;

    //! Tell the name of current group (arrays are also groups).
    virtual PERST_STRING
    group () const = 0;

    //! Tell the full path of current group (arrays are also groups).
    virtual PERST_SLIST
    groupPath () const = 0;

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


    //! Get the string value for a key; the value type MUST be string.
    inline PERST_STRING
    valueS (
            const PERST_STRING & name,
            const PERST_STRING & default_val) {
        if (hasKey (name)) return valueS (name);
        else return default_val;
    }

    //! Get the string list for a key; the value type MUST be an array of strings.
    inline PERST_SLIST
    valueSList (
            const PERST_STRING & name,
            const PERST_SLIST & default_val) {
        if (hasKey (name)) return valueSList (name);
        else return default_val;
    }

    //! Get the integer value for a key; the value type MUST be integer.
    inline int64_t
    valueInt (
            const PERST_STRING & name,
            int64_t default_val) {
        if (hasKey (name)) return valueInt (name);
        else return default_val;
    }

    //! Get the integer value for a key; the value type MUST be integer.
    inline uint64_t
    valueUInt (
            const PERST_STRING & name,
            uint64_t default_val) {
        if (hasKey (name)) return valueUInt (name);
        else return default_val;
    }

    //! Get the real value for a key; the value type MUST be real.
    inline double
    valueDbl (
            const PERST_STRING & name,
            double default_val) {
        if (hasKey (name)) return valueDbl (name);
        else return default_val;
    }


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

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            int value) {
        return setValue (name, (int64_t)value);
    }

    //! Set the real value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            double value) = 0;
};

#endif // GUARD_PERST_INTERFACE_H_INCLUDE
