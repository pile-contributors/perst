/**
 * @file perst_qxml.h
 * @brief Declarations for PerStQSettings class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_PERST_QSETTINGS_H_INCLUDE
#define GUARD_PERST_QSETTINGS_H_INCLUDE

#include <perst/perst.h>

#ifdef PERST_WITH_QSETTINGS
#include <QSettings>

//! Implements PerSt interface using QtXml as a back-end.
class PERST_EXPORT PerStQSettings : public PerSt {

public:
    enum Mode {
        MODE_INI,
        MODE_REGS
    };

    static const PERST_STRING REGS; /**< identifies the registry provider */
    static const PERST_STRING INI; /**< identifies the xml file provider */

    //! Default constructor.
    PerStQSettings (
            const PERST_STRING & file,
            Mode md);

    //! Destructor.
    virtual ~PerStQSettings();

    //! Starts a group; internal state is altered.
    virtual bool
    beginGroup (
            const PERST_STRING & name);

    //! Ends a group; internal state is altered.
    virtual bool
    endGroup ();

    //! Starts writing an array; internal state is altered.
    virtual bool
    beginWriteArray (
            const PERST_STRING & name,
            int predicted_count = -1);

    //! Starts reading an array; internal state is altered.
    virtual int
    beginReadArray (
            const PERST_STRING & name);

    //! Ends an array; internal state is altered.
    virtual bool
    endArray ();

    //! Set current index of an array.
    virtual bool
    setArrayIndex (
            int index);

    //! Tell if a given key exists (relative to current group).
    virtual bool
    hasKey (
            const PERST_STRING & name);

    //! Tell if a given path exists (relative to current group).
    virtual bool
    hasKey (
            const PERST_SLIST & name);


    //! Get the string value for a key; the value type MUST be string.
    virtual PERST_STRING
    valueS (
            const PERST_STRING & name);

    //! Get the string list for a key; the value type MUST be an array of strings.
    virtual PERST_SLIST
    valueSList (
            const PERST_STRING & name);

    //! Get the integer value for a key; the value type MUST be integer.
    virtual int64_t
    valueInt (
            const PERST_STRING & name);

    //! Get the real value for a key; the value type MUST be real.
    virtual double
    valueDbl (
            const PERST_STRING & name);

    //! Set the string value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const PERST_STRING & value);

    //! Set the string list for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            const PERST_SLIST & value);

    //! Set the integer value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            int64_t value);

    //! Set the real value for a key.
    virtual bool
    setValue (
            const PERST_STRING & name,
            double value);

private:
    QSettings backend_;
};

#endif // PERST_WITH_QSETTINGS
#endif // GUARD_PERST_QSETTINGS_H_INCLUDE
