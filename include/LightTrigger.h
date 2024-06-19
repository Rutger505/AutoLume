#pragma once

#include <functional>

class LightTrigger {
public:
    virtual ~LightTrigger() {}
    virtual void onTrigger(std::function<void()> handler) = 0;
};
