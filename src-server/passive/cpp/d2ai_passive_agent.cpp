#include <iostream>
#include <iomanip>
#include "d2ai_passive_agent.h"

namespace d2ai {

int PassiveAgent::LANE_ID{0};

PassiveAgent::PassiveAgent()
    : Agent("PASSIVE") {
}

std::string PassiveAgent::select(const CaptainInfo& cap) {
    // ban or pick first available hero
    for (auto const& h : cap.getHeroes())
        if (!h.isBanned() && !h.isPicked())
            return h.getName();
    return "";
}

std::vector<Action> PassiveAgent::process(const Observation& obs) {
    // assign lane
    std::string heroName{obs.getUnits().getControlledHero().getName()};
    if (lanes.find(heroName) == lanes.end())
        lanes.insert(std::pair<std::string, int>(heroName, LANE_ID++));
    int lane = lanes.find(heroName)->second;
    // move hero
    std::vector<Action> actions;
    if ((lane == 0) || (lane == 1))
        actions.push_back(Action::moveDirectly(obs.getLaneFrontTop()));
    else if (lane == 2)
        actions.push_back(Action::moveDirectly(obs.getLaneFrontMid()));
    else
        actions.push_back(Action::moveDirectly(obs.getLaneFrontBot()));
    return actions;
}

} /* namespace d2ai */
