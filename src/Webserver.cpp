#include <stdexcept>
#include "Webserver.h"

Webserver::Webserver(const std::string &ip, int port)
        : ip(ip), port(port) {}

void Webserver::startWebserver() {
    throw std::runtime_error("Not implemented");
}
