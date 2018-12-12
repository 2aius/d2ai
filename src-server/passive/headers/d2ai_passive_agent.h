#pragma once

#include <vector>
#include <string>
#include "d2ai_agent.h"

namespace d2ai {

class PassiveAgent : public Agent {
private:

    static int LANE_ID;
    std::map<std::string, int> lanes;

public:

    explicit PassiveAgent();

    std::string select(const CaptainInfo& cap);

    std::vector<Action> process(const Observation& obs);
};

} /* namespace d2ai */
