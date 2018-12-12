/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include "d2ai_vector3d.h"

namespace d2ai {

// building locations
class GameInfoLocations final {
private:

    Vector3d radiantShopHome;
    Vector3d radiantShopSide;
    Vector3d radiantShopSecret;
    Vector3d radiantShopSide2;
    Vector3d radiantShopSecret2;
    Vector3d direShopHome;
    Vector3d direShopSide;
    Vector3d direShopSecret;
    Vector3d direShopSide2;
    Vector3d direShopSecret2;
    Vector3d runeSpawnPowerup1;
    Vector3d runeSpawnPowerup2;
    Vector3d runeSpawnBounty1;
    Vector3d runeSpawnBounty2;
    Vector3d runeSpawnBounty3;
    Vector3d runeSpawnBounty4;
    Vector3d radiantAncient;
    Vector3d direAncient;

public:

    static const GameInfoLocations NOT_DECODED;

    explicit GameInfoLocations(
        const Vector3d& radiantShopHome,
        const Vector3d& radiantShopSide,
        const Vector3d& radiantShopSecret,
        const Vector3d& radiantShopSide2,
        const Vector3d& radiantShopSecret2,
        const Vector3d& direShopHome,
        const Vector3d& direShopSide,
        const Vector3d& direShopSecret,
        const Vector3d& direShopSide2,
        const Vector3d& direShopSecret2,
        const Vector3d& runeSpawnPowerup1,
        const Vector3d& runeSpawnPowerup2,
        const Vector3d& runeSpawnBounty1,
        const Vector3d& runeSpawnBounty2,
        const Vector3d& runeSpawnBounty3,
        const Vector3d& runeSpawnBounty4,
        const Vector3d& radiantAncient,
        const Vector3d& direAncient);

    // RADIANT_SHOP_HOME location
    const Vector3d& getRadiantShopHome() const { return radiantShopHome; }

    // RADIANT_SHOP_SIDE location
    const Vector3d& getRadiantShopSide() const { return radiantShopSide; }

    // RADIANT_SHOP_SECRET location
    const Vector3d& getRadiantShopSecret() const { return radiantShopSecret; }

    // RADIANT_SHOP_SIDE2 location
    const Vector3d& getRadiantShopSide2() const { return radiantShopSide2; }

    // RADIANT_SHOP_SECRET2 location
    const Vector3d& getRadiantShopSecret2() const { return radiantShopSecret2; }

    // DIRE_SHOP_HOME location
    const Vector3d& getDireShopHome() const { return direShopHome; }

    // DIRE_SHOP_SIDE location
    const Vector3d& getDireShopSide() const { return direShopSide; }

    // DIRE_SHOP_SECRET location
    const Vector3d& getDireShopSecret() const { return direShopSecret; }

    // DIRE_SHOP_SIDE2 location
    const Vector3d& getDireShopSide2() const { return direShopSide2; }

    // DIRE_SHOP_SECRET2 location
    const Vector3d& getDireShopSecret2() const { return direShopSecret2; }

    // RUNE_SPAWN_POWERUP1 location
    const Vector3d& getRuneSpawnPowerup1() const { return runeSpawnPowerup1; }

    // RUNE_SPAWN_POWERUP2 location
    const Vector3d& getRuneSpawnPowerup2() const { return runeSpawnPowerup2; }

    // RUNE_SPAWN_BOUNTY1 location
    const Vector3d& getRuneSpawnBounty1() const { return runeSpawnBounty1; }

    // RUNE_SPAWN_BOUNTY2 location
    const Vector3d& getRuneSpawnBounty2() const { return runeSpawnBounty2; }

    // RUNE_SPAWN_BOUNTY3 location
    const Vector3d& getRuneSpawnBounty3() const { return runeSpawnBounty3; }

    // RUNE_SPAWN_BOUNTY4 location
    const Vector3d& getRuneSpawnBounty4() const { return runeSpawnBounty4; }

    // RADIANT_ANCIENT location
    const Vector3d& getRadiantAncient() const { return radiantAncient; }

    // DIRE_ANCIENT location
    const Vector3d& getDireAncient() const { return direAncient; }
};

} /* namespace d2ai */
