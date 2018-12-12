/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <string>
#include <vector>
#include "d2ai_vector3d.h"
#include "d2ai_ability.h"

namespace d2ai {

// unit data
class Unit final {
private:

    int handleId;
    int playerId;
    int teamId;
    std::string name;
    int currentActionType;
    bool controlled;
    bool hero;
    bool creep;
    bool ancientCreep;
    bool building;
    bool tower;
    bool fort;
    int courierState;
    int courierValue;
    bool courierFlying;
    bool illusion;
    bool seeable;
    Vector3d location;
    int facing;
    Vector3d velocity;
    int health;
    int maxHealth;
    int healthRegen;
    int mana;
    int maxMana;
    int manaRegen;
    int baseMovementSpeed;
    int currentMovementSpeed;
    bool alive;
    double respawnTime;
    bool buybackAvailable;
    int buybackCost;
    double buybackCooldown;
    double remainingLifespan;
    double baseDamage;
    double baseDamageVariance;
    double attackDamage;
    int attackRange;
    int attackSpeed;
    double secondsPerAttack;
    double lastAttackTime;
    int acquisitionRange;
    int attackProjectileSpeed;
    double spellAmp;
    double armor;
    double magicResist;
    double evasion;
    int bountyXp;
    int bountyGoldMin;
    int bountyGoldMax;
    int xpNeededToLevel;
    int abilityPoints;
    int level;
    int gold;
    int netWorth;
    int stashValue;
    int lastHits;
    int denies;
    double boundingRadius;
    int dayTimeVisionRange;
    int nightTimeVisionRange;
    int currentVisionRange;
    int healthRegenPerStr;
    int manaRegenPerInt;
    bool channeling;
    bool usingAbility;
    bool castingAbility;
    bool attackImmune;
    bool blind;
    bool blockDisabled;
    bool disarmed;
    bool dominated;
    bool evadeDisabled;
    bool hexed;
    bool invisible;
    bool invulnerable;
    bool magicImmune;
    bool muted;
    bool nightmared;
    bool rooted;
    bool silenced;
    bool speciallyDeniable;
    bool stunned;
    bool unableToMiss;
    bool scepterOwned;
    double timeSinceDamagedByAnyHero;
    double timeSinceDamagedByCreep;
    double timeSinceDamagedByTower;
    std::vector<Ability> abilities;
    std::vector<Ability> items;
    std::vector<int> nearbyTrees;

public:

    static const Unit NOT_DECODED;

    explicit Unit(
        int handleId,
        int playerId,
        int teamId,
        const std::string& name,
        int currentActionType,
        bool controlled,
        bool hero,
        bool creep,
        bool ancientCreep,
        bool building,
        bool tower,
        bool fort,
        int courierState,
        int courierValue,
        bool courierFlying,
        bool illusion,
        bool seeable,
        const Vector3d& location,
        int facing,
        const Vector3d& velocity,
        int health,
        int maxHealth,
        int healthRegen,
        int mana,
        int maxMana,
        int manaRegen,
        int baseMovementSpeed,
        int currentMovementSpeed,
        bool alive,
        double respawnTime,
        bool buybackAvailable,
        int buybackCost,
        double buybackCooldown,
        double remainingLifespan,
        double baseDamage,
        double baseDamageVariance,
        double attackDamage,
        int attackRange,
        int attackSpeed,
        double secondsPerAttack,
        double lastAttackTime,
        int acquisitionRange,
        int attackProjectileSpeed,
        double spellAmp,
        double armor,
        double magicResist,
        double evasion,
        int bountyXp,
        int bountyGoldMin,
        int bountyGoldMax,
        int xpNeededToLevel,
        int abilityPoints,
        int level,
        int gold,
        int netWorth,
        int stashValue,
        int lastHits,
        int denies,
        double boundingRadius,
        int dayTimeVisionRange,
        int nightTimeVisionRange,
        int currentVisionRange,
        int healthRegenPerStr,
        int manaRegenPerInt,
        bool channeling,
        bool usingAbility,
        bool castingAbility,
        bool attackImmune,
        bool blind,
        bool blockDisabled,
        bool disarmed,
        bool dominated,
        bool evadeDisabled,
        bool hexed,
        bool invisible,
        bool invulnerable,
        bool magicImmune,
        bool muted,
        bool nightmared,
        bool rooted,
        bool silenced,
        bool speciallyDeniable,
        bool stunned,
        bool unableToMiss,
        bool scepterOwned,
        double timeSinceDamagedByAnyHero,
        double timeSinceDamagedByCreep,
        double timeSinceDamagedByTower,
        const std::vector<Ability>& abilities,
        const std::vector<Ability>& items,
        const std::vector<int>& nearbyTrees);

    // handle ID to the unit
    int getHandleId() const { return handleId; }

    // player ID of the unit
    int getPlayerId() const { return playerId; }

    // team ID of the unit
    int getTeamId() const { return teamId; }

    // under-the-hood name of the unit
    const std::string& getName() const { return name; }

    // current action type of unit
    int getCurrentActionType() const { return currentActionType; }

    // unit is being controlled by agent
    bool isControlled() const { return controlled; }

    // unit is hero
    bool isHero() const { return hero; }

    // unit is creep
    bool isCreep() const { return creep; }

    // unit is ancient creep
    bool isAncientCreep() const { return ancientCreep; }

    // unit is building
    bool isBuilding() const { return building; }

    // unit is tower
    bool isTower() const { return tower; }

    // unit is fort
    bool isFort() const { return fort; }

    // courier state
    int getCourierState() const { return courierState; }

    // courier value
    int getCourierValue() const { return courierValue; }

    // is courier flying
    bool isCourierFlying() const { return courierFlying; }

    // unit is illusion
    bool isIllusion() const { return illusion; }

    // unit is seeable
    bool isSeeable() const { return seeable; }

    // location of the unit
    const Vector3d& getLocation() const { return location; }

    // facing of unit on a 360 degree rotation, east = 0, north = 90, west = 180, south = 270
    int getFacing() const { return facing; }

    // unit current velocity
    const Vector3d& getVelocity() const { return velocity; }

    // current health of the unit
    int getHealth() const { return health; }

    // maximum health of the unit
    int getMaxHealth() const { return maxHealth; }

    // current health regen per second of the unit
    int getHealthRegen() const { return healthRegen; }

    // current mana of the unit
    int getMana() const { return mana; }

    // maximum mana of the unit
    int getMaxMana() const { return maxMana; }

    // current mana regen of the unit
    int getManaRegen() const { return manaRegen; }

    // base movement speed of the unit
    int getBaseMovementSpeed() const { return baseMovementSpeed; }

    // current movement speed (base + modifiers) of the unit
    int getCurrentMovementSpeed() const { return currentMovementSpeed; }

    // is unit alive
    bool isAlive() const { return alive; }

    // number of seconds remaining for the unit to respawn (-1 for non heroes)
    double getRespawnTime() const { return respawnTime; }

    // is buyback available for the unit (false for non allied heroes)
    bool isBuybackAvailable() const { return buybackAvailable; }

    // current gold cost of buyback (-1 for non allied heroes)
    int getBuybackCost() const { return buybackCost; }

    // current cooldown for buyback (-1 for non allied heroes)
    double getBuybackCooldown() const { return buybackCooldown; }

    // remaining lifespan in seconds of units with limited lifespans
    double getRemainingLifespan() const { return remainingLifespan; }

    // average base damage of the unit
    double getBaseDamage() const { return baseDamage; }

    // variance in the base damage of the unit
    double getBaseDamageVariance() const { return baseDamageVariance; }

    // actual attack damage (with bonuses) of the unit
    double getAttackDamage() const { return attackDamage; }

    // range at which the unit can attack another unit
    int getAttackRange() const { return attackRange; }

    // attack speed value of the unit
    int getAttackSpeed() const { return attackSpeed; }

    // number of seconds per attack (including backswing) of the unit
    double getSecondsPerAttack() const { return secondsPerAttack; }

    // time that the unit last executed an attack
    double getLastAttackTime() const { return lastAttackTime; }

    // range at which the unit will attack a target
    int getAcquisitionRange() const { return acquisitionRange; }

    // speed of the attack projectile of the unit
    int getAttackProjectileSpeed() const { return attackProjectileSpeed; }

    // spell amplification debuff percentage of this unit
    double getSpellAmp() const { return spellAmp; }

    // armor of the unit
    double getArmor() const { return armor; }

    // magic resist value of the unit
    double getMagicResist() const { return magicResist; }

    // evasion percentage of the unit
    double getEvasion() const { return evasion; }

    //  XP bounty value for killing this unit
    int getBountyXp() const { return bountyXp; }

    // minimum gold bounty value for killing this unit
    int getBountyGoldMin() const { return bountyGoldMin; }

    // maximum gold bounty value for killing this unit
    int getBountyGoldMax() const { return bountyGoldMax; }

    // amount of XP needed for this unit to gain a level (-1 for non heroes)
    int getXpNeededToLevel() const { return xpNeededToLevel; }

    // number of ability points available to this unit
    int getAbilityPoints() const { return abilityPoints; }

    // level of this unit
    int getLevel() const { return level; }

    // current gold amount for this unit
    int getGold() const { return gold; }

    // current total net worth for this unit
    int getNetWorth() const { return netWorth; }

    // current value of all items in this unit stash
    int getStashValue() const { return stashValue; }

    // current last hit count for this unit
    int getLastHits() const { return lastHits; }

    // current deny count for this unit
    int getDenies() const { return denies; }

    // bounding radius of this unit used for attack ranges and collision
    double getBoundingRadius() const { return boundingRadius; }

    // unit vision range during the day
    int getDayTimeVisionRange() const { return dayTimeVisionRange; }

    // unit vision range during the night
    int getNightTimeVisionRange() const { return nightTimeVisionRange; }

    // unit current vision range
    int getCurrentVisionRange() const { return currentVisionRange; }

    // health regen per second per point in strength
    int getHealthRegenPerStr() const { return healthRegenPerStr; }

    // mana regen per second per point in intellect
    int getManaRegenPerInt() const { return manaRegenPerInt; }

    // returns whether the unit is currently channeling an ability or item
    bool isChanneling() const { return channeling; }

    // returns whether the unit active ability is a Use-Ability action
    bool isUsingAbility() const { return usingAbility; }

    // returns whether the unit is actively casting an ability or item (no movement or backswing)
    bool isCastingAbility() const { return castingAbility; }

    // returns whether the unit is immune to attacks
    bool isAttackImmune() const { return attackImmune; }

    // returns whether the unit is blind and will miss all of its attacks
    bool isBlind() const { return blind; }

    // returns whether the unit is disabled from blocking attacks
    bool isBlockDisabled() const { return blockDisabled; }

    // returns whether the unit is disarmed and unable to attack
    bool isDisarmed() const { return disarmed; }

    // returns whether the unit has been dominated
    bool isDominated() const { return dominated; }

    // returns whether the unit is unable to evade attacks
    bool isEvadeDisabled() const { return evadeDisabled; }

    // returns whether the unit is hexed into an adorable animal
    bool isHexed() const { return hexed; }

    // returns whether the unit has an invisibility effect (does NOT guarantee invisibility to the other team)
    bool isInvisible() const { return invisible; }

    // returns whether the unit is invulnerable to damage
    bool isInvulnerable() const { return invulnerable; }

    // returns whether the unit is magic immune
    bool isMagicImmune() const { return magicImmune; }

    // returns whether the unit is item muted
    bool isMuted() const { return muted; }

    // returns whether the unit is having bad dreams
    bool isNightmared() const { return nightmared; }

    // returns whether the unit is rooted in place
    bool isRooted() const { return rooted; }

    // returns whether the unit is silenced and unable to use abilities
    bool isSilenced() const { return silenced; }

    // returns whether the unit is deniable by allies due to a debuff
    bool isSpeciallyDeniable() const { return speciallyDeniable; }

    // returns whether the unit is stunned
    bool isStunned() const { return stunned; }

    // returns whether the unit will not miss due to evasion or attacking uphill
    bool isUnableToMiss() const { return unableToMiss; }

    // returns whether the unit has ultimate scepter upgrades
    bool isScepterOwned() const { return scepterOwned; }

    // amount of time passed the unit has been damaged by a hero
    double getTimeSinceDamagedByAnyHero() const { return timeSinceDamagedByAnyHero; }

    // amount of time passed the unit has been damaged by a creep
    double getTimeSinceDamagedByCreep() const { return timeSinceDamagedByCreep; }

    // amount of time passed the unit has been damaged by a tower
    double getTimeSinceDamagedByTower() const { return timeSinceDamagedByTower; }

    // unit abilities
    const std::vector<Ability>& getAbilities() const { return abilities; }

    // unit items
    const std::vector<Ability>& getItems() const { return items; }

    // nearby trees
    const std::vector<int>& getNearbyTrees() const { return nearbyTrees; }
};

} /* namespace d2ai */
