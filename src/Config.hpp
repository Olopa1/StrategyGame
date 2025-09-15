#pragma once

#include <stdint.h>

struct Config
{
    unsigned int windowWidht = 1920;
    unsigned int windowHeight = 1080;
    uint32_t fpsCap = 30;
    float volume = 100.f;
};
