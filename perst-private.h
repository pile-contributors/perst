/**
 * @file perst-private.h
 * @brief Declarations for PerSt class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_PERST_PRIVATE_H_INCLUDE
#define GUARD_PERST_PRIVATE_H_INCLUDE

#include <perst/perst-config.h>

#if 0
#    define PERST_DEBUGM printf
#else
#    define PERST_DEBUGM black_hole
#endif

#if 0
#    define PERST_TRACE_ENTRY printf("PERST ENTRY %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define PERST_TRACE_ENTRY
#endif

#if 0
#    define PERST_TRACE_EXIT printf("PERST EXIT %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define PERST_TRACE_EXIT
#endif


static inline void black_hole (...)
{}

#endif // GUARD_PERST_PRIVATE_H_INCLUDE
