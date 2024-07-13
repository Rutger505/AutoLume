#pragma once

#include "LuxMeter.h"

class LightDependantResistor : public LuxMeter {
private:
    uint8_t pin;
    double operatingVoltage;
    uint16_t adcResolution;
    uint32_t pullUpResistor;
public:
    explicit LightDependantResistor(uint8_t pin, double operatingVoltage, uint16_t adcResolution,
                                    uint32_t pullUpResistor);

    double measureLux() override;
};
