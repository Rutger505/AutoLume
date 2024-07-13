#pragma once

#include <cstdint>
#include "LuxMeter.h"

class AmbientLight {
private:
    LuxMeter &luxMeter;
    uint16_t enoughLuxThreshold;
public:
    AmbientLight(LuxMeter &luxMeter, uint16_t enoughLuxThreshold);

    bool enoughLux();
};
