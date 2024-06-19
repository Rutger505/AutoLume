#pragma once

#include "LuxMeter.h"

class AmbientLight {
private:
    LuxMeter& luxMeter;
    int enoughLuxThreshold;
public:
    AmbientLight(LuxMeter& luxMeter, int enoughLuxThreshold);
    bool enoughLux();
};
