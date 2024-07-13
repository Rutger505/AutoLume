#include <Arduino.h>
#include "LightDependantResistor.h"

LightDependantResistor::LightDependantResistor(uint8_t pin, double operatingVoltage, uint16_t adcResolution,
                                               uint32_t pullUpResistor)
        : pin(pin), operatingVoltage(operatingVoltage), adcResolution(adcResolution), pullUpResistor(pullUpResistor) {
    pinMode(pin, INPUT);
}

double LightDependantResistor::measureLux() {
    int analogValue = analogRead(pin);

    double voltage = analogValue * (operatingVoltage / (adcResolution - 1));

    double ldrResistance = (operatingVoltage * pullUpResistor / voltage) - pullUpResistor;

    double lux = 100.0 / (ldrResistance / 1000); // Converting Ω to kΩ

    return lux;
}
