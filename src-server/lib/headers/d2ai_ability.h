/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <string>

namespace d2ai {

// ability or item (same under the hood)
class Ability final {
private:

    int slot;
    std::string name;
    bool upgradable;
    bool autoCast;
    bool toggled;
    bool toggle;
    bool activated;
    bool channeling;
    bool cooldownReady;
    bool fullyCastable;
    bool hidden;
    bool inAbilityPhase;
    bool ownersManaEnough;
    bool passive;
    bool stealable;
    bool stolen;
    bool trained;
    bool procsMagicStick;
    bool behaviorPassive;
    bool behaviorNoTarget;
    bool behaviorUnitTarget;
    bool behaviorPoint;
    bool behaviorAoe;
    bool behaviorNotLearnable;
    bool behaviorChannelled;
    double castPoint;
    int castRange;
    int channelledManaCostPerSecond;
    double channelTime;
    double duration;
    double cooldownTimeRemaining;
    int currentCharges;
    int damage;
    int damageType;
    int heroLevelRequiredToUpgrade;
    int initialCharges;
    int level;
    int manaCost;
    int maxLevel;
    int secondaryCharges;
    int targetTeam;
    int targetType;
    bool item;
    bool disassemblable;
    bool combineLocked;

public:

    static const Ability NOT_DECODED;

    explicit Ability(
        int slot,
        const std::string& name,
        bool upgradable,
        bool autoCast,
        bool toggled,
        bool toggle,
        bool activated,
        bool channeling,
        bool cooldownReady,
        bool fullyCastable,
        bool hidden,
        bool inAbilityPhase,
        bool ownersManaEnough,
        bool passive,
        bool stealable,
        bool stolen,
        bool trained,
        bool procsMagicStick,
        bool behaviorPassive,
        bool behaviorNoTarget,
        bool behaviorUnitTarget,
        bool behaviorPoint,
        bool behaviorAoe,
        bool behaviorNotLearnable,
        bool behaviorChannelled,
        double castPoint,
        int castRange,
        int channelledManaCostPerSecond,
        double channelTime,
        double duration,
        double cooldownTimeRemaining,
        int currentCharges,
        int damage,
        int damageType,
        int heroLevelRequiredToUpgrade,
        int initialCharges,
        int level,
        int manaCost,
        int maxLevel,
        int secondaryCharges,
        int targetTeam,
        int targetType,
        bool item,
        bool disassemblable,
        bool combineLocked);

    // ability or item slot
    int getSlot() const { return slot; }

    // under-the-hood name
    const std::string& getName() const { return name; }

    // can be upgraded
    bool isUpgradable() const { return upgradable; }

    // is auto cast
    bool isAutoCast() const { return autoCast; }

    // is toggled
    bool isToggled() const { return toggled; }

    // is toggle
    bool isToggle() const { return toggle; }

    // is activated
    bool isActivated() const { return activated; }

    // is channeling
    bool isChanneling() const { return channeling; }

    // is cooldown ready
    bool isCooldownReady() const { return cooldownReady; }

    // is fully castable
    bool isFullyCastable() const { return fullyCastable; }

    // is hidden
    bool isHidden() const { return hidden; }

    // is in ability phase
    bool isInAbilityPhase() const { return inAbilityPhase; }

    // is owners mana enough
    bool isOwnersManaEnough() const { return ownersManaEnough; }

    // is passive
    bool isPassive() const { return passive; }

    // is stealable
    bool isStealable() const { return stealable; }

    // is stolen
    bool isStolen() const { return stolen; }

    // is trained
    bool isTrained() const { return trained; }

    // is procs magic stick
    bool isProcsMagicStick() const { return procsMagicStick; }

    // is behavior passive
    bool isBehaviorPassive() const { return behaviorPassive; }

    // is behavior no target
    bool isBehaviorNoTarget() const { return behaviorNoTarget; }

    // is behavior unit target
    bool isBehaviorUnitTarget() const { return behaviorUnitTarget; }

    // is behavior point
    bool isBehaviorPoint() const { return behaviorPoint; }

    // is behavior aoe
    bool isBehaviorAoe() const { return behaviorAoe; }

    // is behavior not learnable
    bool isBehaviorNotLearnable() const { return behaviorNotLearnable; }

    // is behavior channelled
    bool isBehaviorChannelled() const { return behaviorChannelled; }

    // cast point
    double getCastPoint() const { return castPoint; }

    // cast range
    int getCastRange() const { return castRange; }

    // channelled mana cost per second
    int getChannelledManaCostPerSecond() const { return channelledManaCostPerSecond; }

    // channel time
    double getChannelTime() const { return channelTime; }

    // duration
    double getDuration() const { return duration; }

    // cooldown time remaining (only works on allies)
    double getCooldownTimeRemaining() const { return cooldownTimeRemaining; }

    // current charges
    int getCurrentCharges() const { return currentCharges; }

    // damage
    int getDamage() const { return damage; }

    // damage type
    int getDamageType() const { return damageType; }

    // hero level required to upgrade
    int getHeroLevelRequiredToUpgrade() const { return heroLevelRequiredToUpgrade; }

    // initial charges
    int getInitialCharges() const { return initialCharges; }

    // level
    int getLevel() const { return level; }

    // mana cost
    int getManaCost() const { return manaCost; }

    // max level
    int getMaxLevel() const { return maxLevel; }

    // secondary charges
    int getSecondaryCharges() const { return secondaryCharges; }

    // target team
    int getTargetTeam() const { return targetTeam; }

    // target type
    int getTargetType() const { return targetType; }

    // is item
    bool isItem() const { return item; }

    // is disassemblable
    bool isDisassemblable() const { return disassemblable; }

    // is combine locked
    bool isCombineLocked() const { return combineLocked; }
};

} /* namespace d2ai */
