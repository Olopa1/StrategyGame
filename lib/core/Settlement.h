#pragma once

#include <vector>
#include <string>

#include "../utils/DataType.h"
#include "Pop.h"

class Settlement
{
private:
    std::string name;
    std::vector<Pop> pops;

public:
    Settlement(const std::string& name);
    ~Settlement();
};
