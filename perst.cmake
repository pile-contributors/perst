
# enable/disable cmake debug messages related to this pile
set (PERST_DEBUG_MSG ON)

# make sure support code is present; no harm
# in including it twice; the user, however, should have used
# pileInclude() from pile_support.cmake module.
include(pile_support)

# initialize this module
macro    (perstInit
          perst_use_mode)

    # default name
    if (NOT PERST_INIT_NAME)
        set(PERST_INIT_NAME "PerSt")
    endif ()

    # implementations
    if (NOT PERST_EXCLUDE_QSETTINGS)
        set(PERST_WITH_QSETTINGS ON)
    endif ()
    if (NOT PERST_EXCLUDE_QXML)
        set(PERST_WITH_QXML ON)
    endif ()

    # compose the list of headers and sources
    set(PERST_HEADERS
        "perst.h"
        "perst_factory.h")
    set(PERST_SOURCES
        "perst.cc"
        "perst_factory.cc")
    set(PERST_QT_MODS)

    if (PERST_WITH_QSETTINGS)
        list (APPEND PERST_HEADERS "impl/perst_qsettings.h")
        list (APPEND PERST_SOURCES "impl/perst_qsettings.cc")
    endif()
    if (PERST_WITH_QXML)
        list (APPEND PERST_HEADERS "impl/perst_qxml.h")
        list (APPEND PERST_SOURCES "impl/perst_qxml.cc")
    endif()
    if (PERST_WITH_QSETTINGS OR PERST_WITH_QXML)
        list (APPEND PERST_QT_MODS Core)
    endif()

    pileSetSources(
        "${PERST_INIT_NAME}"
        "${PERST_HEADERS}"
        "${PERST_SOURCES}")

    pileSetCommon(
        "${PERST_INIT_NAME}"
        "0;0;1;d"
        "ON"
        "${perst_use_mode}"
        ""
        "basics"
        "storage;persistent;settings;file")

endmacro ()
