#include <stdexcept>
#include "RelayModule.h"

RelayModule::RelayModule(int pin) : pin(pin) {}

void RelayModule::on() {
    throw std::runtime_error("Not implemented");
}

void RelayModule::off() {
    throw std::runtime_error("Not implemented");
}
