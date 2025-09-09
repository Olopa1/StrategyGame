#pragma once

#include <vector>
#include <string>

#include "../utils/DataType.h"
#include "Building.h"

class District
{
private:
    DistrictType type;
    std::vector<Building> buildings;

public:
    District();
    ~District();
};
