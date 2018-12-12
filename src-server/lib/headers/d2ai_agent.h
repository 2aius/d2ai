#pragma once

#include <string>
#include <vector>
#include "d2ai_game_info.h"
#include "d2ai_captain_info.h"
#include "d2ai_observation.h"
#include "d2ai_action.h"

namespace d2ai {

class Agent {
private:

    std::string name;
    GameInfo gameInfo;

public:

    explicit Agent(const std::string& name);
    virtual ~Agent() {}

    const std::string& getName() const { return name; }

    const GameInfo& getGameInfo() const { return gameInfo; }

    void setGameInfo(const GameInfo& gameInfo) { this->gameInfo = gameInfo; }

    /*
     * Functions to be implemented by specific Agent
     */

    virtual std::string select(const CaptainInfo& cap);

    virtual std::vector<Action> process(const Observation& obs);
};

} /* namespace d2ai */
