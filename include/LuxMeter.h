#pragma once

class LuxMeter {
public:
    virtual ~LuxMeter() = default;

    virtual double measureLux() = 0;
};
