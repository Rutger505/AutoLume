#pragma once

#include "LightSwitch.h"

class RelayModule : public LightSwitch {
private:
    int pin;
public:
    explicit RelayModule(int pin);

    void on() override;

    void off() override;
};
