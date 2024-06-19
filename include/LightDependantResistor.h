#pragma once

#include "LuxMeter.h"

class LightDependantResistor : public LuxMeter {
private:
    int pin;
public:
    LightDependantResistor(int pin);
    double measureLux() override;
};
