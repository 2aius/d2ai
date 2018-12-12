#pragma once

#include <string>
#include <set>
#include "d2ai_http_server.h"

namespace d2ai {

class Agent;

class Controller {
private:

    int port;
    HttpServer httpServer;
    Agent *agent;

    mutable std::set<int> controlledPlayers;

public:

    explicit Controller(int port, Agent *agent);

    int getPort() const { return port; }

    void start();

    void process(const std::string& message, std::string& response) const;
};

} /* namespace d2ai */
