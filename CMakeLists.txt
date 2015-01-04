if (NOT PERST_BUILD_MODE)
    set (PERST_BUILD_MODE STATIC)
endif ()

include(pile_support)
pileInclude (PerSt)
perstInit(${PERST_BUILD_MODE})
