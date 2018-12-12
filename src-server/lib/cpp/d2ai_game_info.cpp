/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_game_info.h"

namespace d2ai {

const GameInfo GameInfo::NOT_DECODED{
    false,
    0.,
    0.,
    GameInfoEnums::NOT_DECODED,
    0,
    0,
    std::map<int, GameInfoPlayer>(),
    Vector3d::NOT_DECODED,
    Vector3d::NOT_DECODED,
    GameInfoLocations::NOT_DECODED,
    std::vector<GameInfoItem>()
};

GameInfo::GameInfo(
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
        const std::vector<GameInfoItem>& items)
    : decoded(decoded),
      gameTime(gameTime),
      dotaTime(dotaTime),
      enums(enums),
      alliedTeamId(alliedTeamId),
      enemyTeamId(enemyTeamId),
      players(players),
      minWorldBounds(minWorldBounds),
      maxWorldBounds(maxWorldBounds),
      locations(locations),
      items(items) {
}

} /* namespace d2ai */
