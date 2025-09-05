#pragma once

#include "../utils/DataType.h"

class Pop
{
private:
    uint16_t currentPopSize;
    float happiness;
    float efficiency;
    ReligionType mainReligion;
    CultureType mainCulture;
    SocialClassType socialClass;
    bool isMobilised;
public:
    Pop(/* args */);
    ~Pop();
    void calculateEfficiency(/*all needed args*/ );

};


