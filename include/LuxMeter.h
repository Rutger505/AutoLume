#pragma once

class LuxMeter {
public:
    virtual ~LuxMeter() {}
    virtual double measureLux() = 0;
};
