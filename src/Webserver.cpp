#include "Webserver.h"

Webserver::Webserver(const std::string& ip, int port)
        : ip(ip), port(port), lastHeartBeat(std::time(nullptr)) {}

void Webserver::startWebserver() {
    // Implement webserver logic
}
