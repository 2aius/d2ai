#pragma once

#include <string>
#include "d2ai_captain_info.h"
#include "d2ai_game_info.h"
#include "d2ai_observation.h"
#include "d2ai_action.h"
#include "d2ai_vector3d.h"
#include "d2ai_ability.h"

namespace d2ai {

class Protocol final {
private:

    static const char LEVEL1;
    static const char LEVEL2;
    static const char LEVEL3;
    static const char LEVEL4;
    static const char LEVEL5;

    static Vector3d decodeVector(const std::string& str, const char levelChar);

    static bool decodeAbility(const std::string& str,
            std::vector<Ability>& abilities, const char levelChar);

public:

    static const std::string VERSION;

    static const std::string VERSION_MESSAGE_TYPE;
    static const std::string CAPTAIN_INFO_MESSAGE_TYPE;
    static const std::string GAME_INFO_MESSAGE_TYPE;
    static const std::string OBSERVATION_MESSAGE_TYPE;

    static std::string decodeVersion(const std::string& message);

    static CaptainInfo decodeCaptainInfo(const std::string& message);

    static GameInfo decodeGameInfo(const std::string& message);

    static Observation decodeObservation(const std::string& message,
            int alliedTeamId, int enemyTeamId);

    static std::string encodeActions(const std::vector<Action>& actions);
};


} /* namespace d2ai */
