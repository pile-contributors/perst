/**
 * @file perst.h
 * @brief Declarations for PerSt class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_PERST_FACTORY_H_INCLUDE
#define GUARD_PERST_FACTORY_H_INCLUDE

#include <perst/perst-config.h>

class PerSt;
struct PerStProvider;

//! Factory class that produces PerSt instances.
class PERST_EXPORT PerStFactory {

public:

    //! callback used to create PerSt instances by providers.
    typedef PerSt * (*kbCreate) (
            const PERST_STRING & name,
            const PERST_STRING & value,
            void * user_data);

    //! callback used to iterate all providers.
    typedef bool (*kbForEach) (
            int index,
            const PERST_STRING & name,
            kbCreate kb,
            void * user_data,
            void * for_each_user_data);

private:
    PerStFactory();
    PerStFactory(const PerStFactory & other);
    ~PerStFactory();

public:

    //! Start-up.
    static void
    init ();

    //! End-up.
    static void
    end ();

    //! Create a new instance.
    static PerSt *
    create (
            const PERST_STRING & name,
            const PERST_STRING & value);

    //! Register a new kind.
    static bool
    addProvider (
            const PERST_STRING & name,
            kbCreate kb,
            void * user_data);

    //! Unregister a custom kind.
    static bool
    delProvider (
            const PERST_STRING & name);

    //! Tell if a name is registered.
    static bool
    hasProvider (
            const PERST_STRING & name);

    //! Iterate all providers (includes build-ins).
    static bool
    forEachProvider (
            kbForEach kb,
            void * for_each_user_data);

private:

    //! Start-up.
    static void
    autocreate();

    //! locate provider
    PerStProvider *
    find (
            const PERST_STRING & name);

    std::list<PerStProvider*> providers_; /**< The list of providers. */
    static PerStFactory * singleton_; /**< The one and only instance. */
};

#endif // GUARD_PERST_FACTORY_H_INCLUDE
