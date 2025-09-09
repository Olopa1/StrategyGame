#include "Population.h"

Population::Population()
{
}

Population::~Population()
{
}

void Population::calculateReligiousConversion(){
    religiousConversionRates = baseReligiousConversionRates;
    for (auto& rate : religiousConversionRates) {
        for (const auto& modifier : religiousConversionRateModifiers[rate.first]) {
            rate.second += modifier.first;
        }
    }

    std::vector<Pop> newChunks;
    for (auto& popChunk : popChunks) {
        float conversionRate = religiousConversionRates[popChunk.getSocialClass()];

        if(popChunk.getMainReligion() == dominantReligion) {
            continue; // No conversion needed
        }

        if (auto converted = popChunk.convertReligion(conversionRate, dominantReligion)) {
            newChunks.push_back(*converted);
        }
    }
    popChunks.insert(popChunks.end(), newChunks.begin(), newChunks.end());
}

void Population::calculateCulturalConversion(){
    culturalConversionRates = baseCulturalConversionRates;
    for (auto& rate : culturalConversionRates) {
        for (const auto& modifier : culturalConversionRateModifiers[rate.first]) {
            rate.second += modifier.first;
        }
    }

    std::vector<Pop> newChunks;
    for (auto& popChunk : popChunks) {
        float conversionRate = culturalConversionRates[popChunk.getSocialClass()];

        if(popChunk.getMainCulture() == dominantCulture) {
            continue; // No conversion needed
        }

        if (auto converted = popChunk.convertCulture(conversionRate, dominantCulture)) {
            newChunks.push_back(*converted);
        }
    }
    popChunks.insert(popChunks.end(), newChunks.begin(), newChunks.end());
}

void Population::calculateEndOfMonth(){
    // Recalculate growth rate
    growthRate = baseGrowthRate;
    for (const auto& modifier : growthRateModifiers) {
        growthRate += modifier.first;
    }

    // Update population statistics and demographics
    std::vector<Pop> newChunks;
    for (auto& popChunk : popChunks) {
        if (auto growthResult = popChunk.calculateGrowth(growthRate)) {
            newChunks.push_back(*growthResult);
        }
    }
    popChunks.insert(popChunks.end(), newChunks.begin(), newChunks.end());

    calculateReligiousConversion();
    calculateCulturalConversion();

    consolidatePopChunks();

    // Recalculate overall population metrics
}

void Population::consolidatePopChunks() {
    std::map<std::tuple<ReligionType, CultureType, SocialClassType>, uint16_t> chunkMap;

    for (const auto& chunk : popChunks) {
        auto key = std::make_tuple(chunk.getMainReligion(), chunk.getMainCulture(), chunk.getSocialClass());
        chunkMap[key] += chunk.getCurrentPopSize();
    }

    popChunks.clear();
    for (const auto& [key, size] : chunkMap) {
        ReligionType religion;
        CultureType culture;
        SocialClassType socialClass;
        std::tie(religion, culture, socialClass) = key;

        Pop newChunk;
        newChunk.setMainReligion(religion);
        newChunk.setMainCulture(culture);
        newChunk.setSocialClass(socialClass);
        newChunk.setCurrentPopSize(size);
        popChunks.push_back(newChunk);
    }
}
