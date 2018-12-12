#include <iostream>
#include <string>
#include "d2ai_protocol.h"
#include "d2ai_controller.h"
#include "d2ai_passive_agent.h"

using namespace d2ai;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage:    d2ai-passive <port>" << std::endl
                << "Protocol: " << Protocol::VERSION << std::endl;
    } else {
        int port = std::stoi(argv[1]);
        PassiveAgent *agent = new PassiveAgent();
        Controller controller(port, agent);
        controller.start();
    }
    return 0;
}
