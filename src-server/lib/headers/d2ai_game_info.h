/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <map>
#include <vector>
#include "d2ai_game_info_enums.h"
#include "d2ai_game_info_player.h"
#include "d2ai_vector3d.h"
#include "d2ai_game_info_locations.h"
#include "d2ai_game_info_item.h"

namespace d2ai {

// static data that are constant during the game
class GameInfo final {
private:

    bool decoded;
    double gameTime;
    double dotaTime;
    GameInfoEnums enums;
    int alliedTeamId;
    int enemyTeamId;
    std::map<int, GameInfoPlayer> players;
    Vector3d minWorldBounds;
    Vector3d maxWorldBounds;
    GameInfoLocations locations;
    std::vector<GameInfoItem> items;

public:

    static const GameInfo NOT_DECODED;

    explicit GameInfo(
        bool decoded,
        double gameTime,
        double dotaTime,
        const GameInfoEnums& enums,
        int alliedTeamId,
        int enemyTeamId,
        const std::map<int, GameInfoPlayer>& players,
        const Vector3d& minWorldBounds,
        const Vector3d& maxWorldBounds,
        const GameInfoLocations& locations,
        const std::vector<GameInfoItem>& items);

    // is successfully decoded
    bool isDecoded() const { return decoded; }

    // game time when GameInfo was generated
    double getGameTime() const { return gameTime; }

    // dota time when GameInfo was generated
    double getDotaTime() const { return dotaTime; }

    // enums
    const GameInfoEnums& getEnums() const { return enums; }

    // allied team ID
    int getAlliedTeamId() const { return alliedTeamId; }

    // enemy team ID
    int getEnemyTeamId() const { return enemyTeamId; }

    // players
    const std::map<int, GameInfoPlayer>& getPlayers() const { return players; }

    // min world bounds
    const Vector3d& getMinWorldBounds() const { return minWorldBounds; }

    // max world bounds
    const Vector3d& getMaxWorldBounds() const { return maxWorldBounds; }

    // locations of all buildings
    const GameInfoLocations& getLocations() const { return locations; }

    // available items
    const std::vector<GameInfoItem>& getItems() const { return items; }
};

} /* namespace d2ai */
