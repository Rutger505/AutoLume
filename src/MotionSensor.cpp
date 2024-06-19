#include "MotionSensor.h"

MotionSensor::MotionSensor(int pin) : pin(pin), lastMotion(std::time(nullptr)) {}

void MotionSensor::startSensingMotion() {
    // Implement motion sensing logic
}
