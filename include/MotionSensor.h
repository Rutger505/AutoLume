#pragma once

#include <ctime>

class MotionSensor {
private:
    int pin;
    std::time_t lastMotion;
public:
    MotionSensor(int pin);
    void startSensingMotion();
};
