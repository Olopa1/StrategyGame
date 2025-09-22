#include "Population.h"

Population::Population()
{
}

Population::~Population()
{
}

void Population::calculatePopulationGrowth(){
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

    calculatePopulationGrowth();

    // Recalculate overall population metrics
}

void Population::calculateEndOfYear(){

    calculateReligiousConversion();
    calculateCulturalConversion();

    consolidatePopChunks();

    // Recalculate overall population metrics
}

void Population::consolidatePopChunks() {
    std::map<std::tuple<ReligionType, CultureType, SocialClassType>, std::vector<Pop>> chunkMap;

    for (const auto& chunk : popChunks) {
        auto key = std::make_tuple(chunk.getMainReligion(), chunk.getMainCulture(), chunk.getSocialClass());
        chunkMap[key].push_back(chunk);
    }

    popChunks.clear();
    for (const auto& [key, chunks] : chunkMap) {
        ReligionType religion;
        CultureType culture;
        SocialClassType socialClass;
        std::tie(religion, culture, socialClass) = key;

        uint16_t totalSize = 0;
        for (const auto& chunk : chunks) {
            totalSize += chunk.getCurrentPopSize();
        }

        Pop newChunk;
            newChunk.setMainReligion(religion);
            newChunk.setMainCulture(culture);
            newChunk.setSocialClass(socialClass);

            newChunk.setHappiness(chunks[0].getHappiness());
            newChunk.setEfficiency(chunks[0].getEfficiency());
            newChunk.setIsMobilised(chunks[0].getIsMobilised());

            newChunk.setCurrentPopSize(MAX_POP_IN_CHANK);

        while (totalSize > MAX_POP_IN_CHANK)
        {
            
            totalSize -= MAX_POP_IN_CHANK;
            popChunks.push_back(newChunk);
        }

        if (totalSize > 0) {
            newChunk.setCurrentPopSize(totalSize);
            popChunks.push_back(newChunk);
        }
           
    }
}
