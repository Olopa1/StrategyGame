#pragma once
#include <stdint.h>

#define MAX_POP_IN_CHANK 1000

enum ReligionType{
    NONE = 0,
    CHRISTIANITY_ORTODOX,
    CHRYSTIANITY_LATIN,
    CHRYSTIANITY_SYRIAC,
    CHRYSTIANITY_COPTIC,
    CHRYSTIANITY_ARMENIAN,
    MUSLIM_SHIA,
    MUSLIM_SUNNI,
    PAGAN_SLAVIC,
    PAGAN_NORSE,
    PAGAN_DRUIDIC,
    HERESY,
};

enum CultureType{
    NONE = 0,
    LATIN,
    GREEK,
    SLAVIC,
    GERMANIC,
    CELTIC,
    NORSE,
    ARABIC,
    BERBERIC,
    TURKS,
};

enum TerrainType{
    PLAIN,
    OCEAN,
    MOUNTAIN,
    HILLS,
    FOREST,
    DESERT,
    RIVER,
};

enum DistrictType{
    RELIGIOUS,
    HARBOUR,
    FARMING,
    ARTISAN, // CRAFTSMAN
    MERCANTILE,
    MILITARY,
};

enum SocialClassType{
    NOBLE,
    CLERIC,
    BURGHER, // urbanite
    PEASANT,  
};
