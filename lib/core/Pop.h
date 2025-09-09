#pragma once

#include <optional>

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
    std::optional<Pop> calculateGrowth(float growthRate);
    std::optional<Pop> convertReligion(float conversionRate, ReligionType targetReligion);
    std::optional<Pop> convertCulture(float conversionRate, CultureType targetCulture);
    
    // Getters and setters
    uint16_t getCurrentPopSize() const { return currentPopSize; }
    void setCurrentPopSize(uint16_t size) { currentPopSize = size; }    
    float getHappiness() const { return happiness; }
    void setHappiness(float happy) { happiness = happy; }
    float getEfficiency() const { return efficiency; }
    void setEfficiency(float eff) { efficiency = eff; }
    ReligionType getMainReligion() const { return mainReligion; }
    void setMainReligion(ReligionType religion) { mainReligion = religion; }
    CultureType getMainCulture() const { return mainCulture; }
    void setMainCulture(CultureType culture) { mainCulture = culture; }
    SocialClassType getSocialClass() const { return socialClass; }
    void setSocialClass(SocialClassType socialClass) { this->socialClass = socialClass; }
};


