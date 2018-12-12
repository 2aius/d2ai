/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_units.h"

namespace d2ai {

const Units Units::NOT_DECODED{
    Unit::NOT_DECODED,
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>(),
    std::vector<Unit>()
};

Units::Units(
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
        const std::vector<Unit>& neutralCreeps)
    : controlledHero(controlledHero),
      alliedHeroes(alliedHeroes),
      alliedBuildings(alliedBuildings),
      alliedCreeps(alliedCreeps),
      alliedWards(alliedWards),
      alliedCouriers(alliedCouriers),
      enemyHeroes(enemyHeroes),
      enemyBuildings(enemyBuildings),
      enemyCreeps(enemyCreeps),
      enemyWards(enemyWards),
      enemyCouriers(enemyCouriers),
      neutralCreeps(neutralCreeps) {
}

} /* namespace d2ai */
