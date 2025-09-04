#pragma once

#include "../utils/DataType.h"

class Pop
{
private:
    uint16_t currentPopSize;
    float happiness;
    ReligionType mainReligion;
    CultureType mainCulture;
    SocialClassType socialClass;
    bool isMobilised;
public:
    Pop(/* args */);
    ~Pop();
};


