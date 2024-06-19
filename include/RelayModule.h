#pragma once

#include "LightSwitch.h"

class RelayModule : public LightSwitch {
private:
    int pin;
public:
    RelayModule(int pin);
    void on() override;
    void off() override;
};
