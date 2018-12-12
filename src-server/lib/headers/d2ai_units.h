/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <vector>
#include "d2ai_unit.h"

namespace d2ai {

// units
class Units final {
private:

    Unit controlledHero;
    std::vector<Unit> alliedHeroes;
    std::vector<Unit> alliedBuildings;
    std::vector<Unit> alliedCreeps;
    std::vector<Unit> alliedWards;
    std::vector<Unit> alliedCouriers;
    std::vector<Unit> enemyHeroes;
    std::vector<Unit> enemyBuildings;
    std::vector<Unit> enemyCreeps;
    std::vector<Unit> enemyWards;
    std::vector<Unit> enemyCouriers;
    std::vector<Unit> neutralCreeps;

public:

    static const Units NOT_DECODED;

    explicit Units(
        const Unit& controlledHero,
        const std::vector<Unit>& alliedHeroes,
        const std::vector<Unit>& alliedBuildings,
        const std::vector<Unit>& alliedCreeps,
        const std::vector<Unit>& alliedWards,
        const std::vector<Unit>& alliedCouriers,
        const std::vector<Unit>& enemyHeroes,
        const std::vector<Unit>& enemyBuildings,
        const std::vector<Unit>& enemyCreeps,
        const std::vector<Unit>& enemyWards,
        const std::vector<Unit>& enemyCouriers,
        const std::vector<Unit>& neutralCreeps);

    // hero being controlled by agent
    const Unit& getControlledHero() const { return controlledHero; }

    // allied heroes
    const std::vector<Unit>& getAlliedHeroes() const { return alliedHeroes; }

    // allied buildings
    const std::vector<Unit>& getAlliedBuildings() const { return alliedBuildings; }

    // allied creeps
    const std::vector<Unit>& getAlliedCreeps() const { return alliedCreeps; }

    // allied wards
    const std::vector<Unit>& getAlliedWards() const { return alliedWards; }

    // allied couriers
    const std::vector<Unit>& getAlliedCouriers() const { return alliedCouriers; }

    // enemy heroes
    const std::vector<Unit>& getEnemyHeroes() const { return enemyHeroes; }

    // enemy buildings
    const std::vector<Unit>& getEnemyBuildings() const { return enemyBuildings; }

    // enemy creeps
    const std::vector<Unit>& getEnemyCreeps() const { return enemyCreeps; }

    // enemy wards
    const std::vector<Unit>& getEnemyWards() const { return enemyWards; }

    // enemy couriers
    const std::vector<Unit>& getEnemyCouriers() const { return enemyCouriers; }

    // neutral creeps
    const std::vector<Unit>& getNeutralCreeps() const { return neutralCreeps; }
};

} /* namespace d2ai */
