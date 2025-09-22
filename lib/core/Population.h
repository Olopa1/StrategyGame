#pragma once

#include <vector>
#include <string>
#include <map>

#include "../utils/DataType.h"
#include "Pop.h"

class Population
{
private:
    std::vector<Pop> popChunks;

    std::map<SocialClassType, float> averageHappiness;
    std::map<SocialClassType, float> averageEfficiency;
    std::map<ReligionType, uint16_t> religionDistribution;
    std::map<CultureType, uint16_t> cultureDistribution;
    std::map<SocialClassType, uint16_t> socialClassDistribution;

    float baseGrowthRate;
    std::map<uint16_t, std::string> growthRateModifiers;
    float growthRate;

    ReligionType dominantReligion;
    std::map<SocialClassType, float> baseReligiousConversionRates;
    std::map<SocialClassType, std::vector<std::pair<float, std::string>>> religiousConversionRateModifiers;
    std::map<SocialClassType, float> religiousConversionRates;

    CultureType dominantCulture;
    std::map<SocialClassType, float> baseCulturalConversionRates;
    std::map<SocialClassType, std::vector<std::pair<float, std::string>>> culturalConversionRateModifiers;
    std::map<SocialClassType, float> culturalConversionRates;

    public:
    Population();
    ~Population();
    void calculatePopulationGrowth();
    void calculateReligiousConversion();
    void calculateCulturalConversion();
    void calculateEndOfMonth();
    void calculateEndOfYear();
    void consolidatePopChunks();

};
