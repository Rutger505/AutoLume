#pragma once

#include <string>
#include <ctime>

class Webserver {
private:
    std::string ip;
    int port;
    std::time_t lastHeartBeat;
public:
    Webserver(const std::string& ip, int port);
    void startWebserver();
};
