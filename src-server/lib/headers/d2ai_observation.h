/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <vector>
#include "d2ai_units.h"
#include "d2ai_dropped_item.h"
#include "d2ai_rune.h"

namespace d2ai {

// observation
class Observation final {
private:

    bool decoded;
    double gameTime;
    double dotaTime;
    int playerId;
    int playerCurrentActionType;
    double timeOfDay;
    double glyphCooldown;
    double roshanKillTime;
    bool courierAvailable;
    Units units;
    std::vector<DroppedItem> droppedItems;
    std::vector<Rune> runes;
    Vector3d laneFrontTop;
    Vector3d laneFrontMid;
    Vector3d laneFrontBot;

public:

    static const Observation NOT_DECODED;

    explicit Observation(
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
        const Vector3d& laneFrontBot);

    // is successfully decoded
    bool isDecoded() const { return decoded; }

    // game time when Observation was generated
    double getGameTime() const { return gameTime; }

    // dota time when Observation was generated
    double getDotaTime() const { return dotaTime; }

    // player ID that generated the Observation
    int getPlayerId() const { return playerId; }

    // player current action type
    int getPlayerCurrentActionType() const { return playerCurrentActionType; }

    // time of day
    double getTimeOfDay() const { return timeOfDay; }

    // glyph cooldown in seconds
    double getGlyphCooldown() const { return glyphCooldown; }

    // roshan kill time in seconds
    double getRoshanKillTime() const { return roshanKillTime; }

    // is courier available
    bool isCourierAvailable() const { return courierAvailable; }

    // units
    const Units& getUnits() const { return units; }

    // dropped items
    const std::vector<DroppedItem>& getDroppedItems() const { return droppedItems; }

    // runes
    const std::vector<Rune>& getRunes() const { return runes; }

    // lane front top location
    const Vector3d& getLaneFrontTop() const { return laneFrontTop; }

    // lane front mid location
    const Vector3d& getLaneFrontMid() const { return laneFrontMid; }

    // lane front bot location
    const Vector3d& getLaneFrontBot() const { return laneFrontBot; }
};

} /* namespace d2ai */
