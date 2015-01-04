
# enable/disable cmake debug messages related to this pile
set (PERST_DEBUG_MSG ON)

# make sure support code is present; no harm
# in including it twice; the user, however, should have used
# pileInclude() from pile_support.cmake module.
include(pile_support)

# initialize this module
macro    (perstInit
          ref_cnt_use_mode)

    # default name
    if (NOT TEM_PILE_INIT_NAME)
        set(TEM_PILE_INIT_NAME "PerSt")
    endif ()

    # compose the list of headers and sources
    set(PERST_HEADERS
        "perst.h")
    set(PERST_SOURCES
        "perst.cc")

    pileSetSources(
        "${TEM_PILE_INIT_NAME}"
        "${PERST_HEADERS}"
        "${PERST_SOURCES}")

    pileSetCommon(
        "${TEM_PILE_INIT_NAME}"
        "0;0;1;d"
        "ON"
        "${ref_cnt_use_mode}"
        ""
        "category1"
        "tag1;tag2")

endmacro ()
