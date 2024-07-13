#include "AmbientLight.h"

AmbientLight::AmbientLight(LuxMeter &luxMeter, uint16_t enoughLuxThreshold)
        : luxMeter(luxMeter), enoughLuxThreshold(enoughLuxThreshold) {}

bool AmbientLight::enoughLux() {
    return luxMeter.measureLux() > enoughLuxThreshold;
}
