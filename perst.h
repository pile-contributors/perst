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
#include <perst/perst_interface.h>

//! Interface class for persistent storage
class PERST_EXPORT PerSt : public PerstInterface {

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

    //! Get current index of an array.
    int
    arrayIndex () const {
        return array_index_;
    }

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

protected:

    //! Alters internal state by appending the group name.
    bool
    setArrayIndexInternal (
            int value);

    //! Alters internal state by removing last group name.
    bool endArrayInternal (
            const PERST_STRING & name);

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
    PERST_STRING location_; /**< Location of the
                                 storage (may be a file). */
    PERST_SLIST current_group_path_; /**< List of elements;
                                          last one is current group.*/
    PERST_STRING current_group_name_; /**< Current group's name. */
    int array_index_; /**< current index in the array, if any */
    std::list<int> array_indices_; /**< stores nested indices */
};

#endif // GUARD_PERST_H_INCLUDE
