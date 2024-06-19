#include "AmbientLight.h"

AmbientLight::AmbientLight(LuxMeter& luxMeter, int enoughLuxThreshold)
        : luxMeter(luxMeter), enoughLuxThreshold(enoughLuxThreshold) {}

bool AmbientLight::enoughLux() {
    return luxMeter.measureLux() >= enoughLuxThreshold;
}
