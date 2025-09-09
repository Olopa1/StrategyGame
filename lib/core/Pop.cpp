#include <Pop.h>

#include <cmath> 

Pop::Pop(/* args */)
{
}

Pop::~Pop()
{
}

void Pop::calculateEfficiency(){
    
}

std::optional<Pop> Pop::calculateGrowth(float growthRate){
    uint16_t newPopSize = static_cast<uint16_t>(currentPopSize * (1 + growthRate));
    uint16_t excessPop = (newPopSize > MAX_POP_IN_CHANK) ? (newPopSize - MAX_POP_IN_CHANK) : 0;
    currentPopSize = (newPopSize > MAX_POP_IN_CHANK) ? MAX_POP_IN_CHANK : newPopSize;

    if (excessPop > 0) {
        Pop newChunk = *this;
        newChunk.setCurrentPopSize(excessPop);
        return newChunk;
    }
    return std::nullopt;
}

std::optional<Pop> Pop::convertReligion(float conversionRate, ReligionType targetReligion){
    if (conversionRate >= 1.0f) {
        // Full conversion
        mainReligion = targetReligion;
        return std::nullopt; // All converted
    } else if (conversionRate > 0.0f && targetReligion != mainReligion) {
        // Partial conversion based on rate
        uint16_t converted = static_cast<uint16_t>(std::ceil(currentPopSize * conversionRate));
        currentPopSize -= converted;
        Pop newChunk = *this;
        newChunk.setCurrentPopSize(converted);
        newChunk.setMainReligion(targetReligion);
        return newChunk;
    }
    return std::nullopt; // No conversion
}

std::optional<Pop> Pop::convertCulture(float conversionRate, CultureType targetCulture){
    if (conversionRate >= 1.0f) {
        // Full conversion
        mainCulture = targetCulture;
        return std::nullopt; // All converted
    } else if (conversionRate > 0.0f && targetCulture != mainCulture) {
        // Partial conversion based on rate
        uint16_t converted = static_cast<uint16_t>(std::ceil(currentPopSize * conversionRate));
        currentPopSize -= converted;
        Pop newChunk = *this;
        newChunk.setCurrentPopSize(converted);
        newChunk.setMainCulture(targetCulture);
        return newChunk;
    }
    return std::nullopt; // No conversion
}
