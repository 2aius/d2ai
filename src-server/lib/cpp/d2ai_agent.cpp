#include "d2ai_agent.h"

namespace d2ai {

Agent::Agent(const std::string& name)
    : name(name),
      gameInfo(GameInfo::NOT_DECODED) {
}

std::string Agent::select(const CaptainInfo& cap) {
    // return first available hero
    for (auto const& h : cap.getHeroes())
        if (!h.isBanned() && !h.isPicked()) return h.getName();
    return "";
}

std::vector<Action> Agent::process(const Observation& obs) {
    // do nothing
    std::vector<Action> actions{Action::none()};
    return actions;
}

} /* namespace d2ai */
