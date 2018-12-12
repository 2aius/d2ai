/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <string>

namespace d2ai {

// player info
class GameInfoPlayer final {
private:

    int teamId;
    int playerId;
    std::string heroName;
    bool bot;

public:

    static const GameInfoPlayer NOT_DECODED;

    explicit GameInfoPlayer(
        int teamId,
        int playerId,
        const std::string& heroName,
        bool bot);

    // team ID
    int getTeamId() const { return teamId; }

    // player ID
    int getPlayerId() const { return playerId; }

    // player hero name
    const std::string& getHeroName() const { return heroName; }

    // player is bot
    bool isBot() const { return bot; }
};

} /* namespace d2ai */
