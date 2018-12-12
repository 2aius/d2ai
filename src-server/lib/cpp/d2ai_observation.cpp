/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_observation.h"

namespace d2ai {

const Observation Observation::NOT_DECODED{
    false,
    0.,
    0.,
    0,
    0,
    0.,
    0.,
    0.,
    false,
    Units::NOT_DECODED,
    std::vector<DroppedItem>(),
    std::vector<Rune>(),
    Vector3d::NOT_DECODED,
    Vector3d::NOT_DECODED,
    Vector3d::NOT_DECODED
};

Observation::Observation(
        bool decoded,
        double gameTime,
        double dotaTime,
        int playerId,
        int playerCurrentActionType,
        double timeOfDay,
        double glyphCooldown,
        double roshanKillTime,
        bool courierAvailable,
        const Units& units,
        const std::vector<DroppedItem>& droppedItems,
        const std::vector<Rune>& runes,
        const Vector3d& laneFrontTop,
        const Vector3d& laneFrontMid,
        const Vector3d& laneFrontBot)
    : decoded(decoded),
      gameTime(gameTime),
      dotaTime(dotaTime),
      playerId(playerId),
      playerCurrentActionType(playerCurrentActionType),
      timeOfDay(timeOfDay),
      glyphCooldown(glyphCooldown),
      roshanKillTime(roshanKillTime),
      courierAvailable(courierAvailable),
      units(units),
      droppedItems(droppedItems),
      runes(runes),
      laneFrontTop(laneFrontTop),
      laneFrontMid(laneFrontMid),
      laneFrontBot(laneFrontBot) {
}

} /* namespace d2ai */
