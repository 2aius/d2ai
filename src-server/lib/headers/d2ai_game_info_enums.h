/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once


namespace d2ai {

// enums
class GameInfoEnums final {
private:

    int damageTypePhysical;
    int damageTypeMagical;
    int damageTypePure;
    int damageTypeAll;
    int teamRadiant;
    int teamDire;
    int teamNeutral;
    int teamNone;
    int runeTypeInvalid;
    int runeTypeDoubleDamage;
    int runeTypeHaste;
    int runeTypeIllusion;
    int runeTypeInvisibility;
    int runeTypeRegeneration;
    int runeTypeBounty;
    int runeTypeArcane;
    int runeStatusUnknown;
    int runeStatusAvailable;
    int runeStatusMissing;
    int runeSpawnPowerup1;
    int runeSpawnPowerup2;
    int runeSpawnBounty1;
    int runeSpawnBounty2;
    int runeSpawnBounty3;
    int runeSpawnBounty4;
    int itemSlotTypeInvalid;
    int itemSlotTypeMain;
    int itemSlotTypeBackpack;
    int itemSlotTypeStash;
    int botActionTypeNone;
    int botActionTypeIdle;
    int botActionTypeMoveTo;
    int botActionTypeMoveToDirectly;
    int botActionTypeAttack;
    int botActionTypeAttackMove;
    int botActionTypeUseAbility;
    int botActionTypePickUpRune;
    int botActionTypePickUpItem;
    int botActionTypeDropItem;
    int botActionTypeShrine;
    int botActionTypeDelay;
    int courierActionBurst;
    int courierActionEnemySecretShop;
    int courierActionReturn;
    int courierActionSecretShop;
    int courierActionSideShop;
    int courierActionSideShop2;
    int courierActionTakeStashItems;
    int courierActionTakeAndTransferItems;
    int courierActionTransferItems;
    int courierStateIdle;
    int courierStateAtBase;
    int courierStateMoving;
    int courierStateDeliveringItems;
    int courierStateReturningToBase;
    int courierStateDead;
    int shopHome;
    int shopSide;
    int shopSecret;
    int shopSide2;
    int shopSecret2;
    int abilityTargetTeamNone;
    int abilityTargetTeamFriendly;
    int abilityTargetTeamEnemy;
    int abilityTargetTypeNone;
    int abilityTargetTypeHero;
    int abilityTargetTypeCreep;
    int abilityTargetTypeBuilding;
    int abilityTargetTypeCourier;
    int abilityTargetTypeOther;
    int abilityTargetTypeTree;
    int abilityTargetTypeBasic;
    int abilityTargetTypeAll;
    int laneNone;
    int laneTop;
    int laneMid;
    int laneBot;

public:

    static const GameInfoEnums NOT_DECODED;

    explicit GameInfoEnums(
        int damageTypePhysical,
        int damageTypeMagical,
        int damageTypePure,
        int damageTypeAll,
        int teamRadiant,
        int teamDire,
        int teamNeutral,
        int teamNone,
        int runeTypeInvalid,
        int runeTypeDoubleDamage,
        int runeTypeHaste,
        int runeTypeIllusion,
        int runeTypeInvisibility,
        int runeTypeRegeneration,
        int runeTypeBounty,
        int runeTypeArcane,
        int runeStatusUnknown,
        int runeStatusAvailable,
        int runeStatusMissing,
        int runeSpawnPowerup1,
        int runeSpawnPowerup2,
        int runeSpawnBounty1,
        int runeSpawnBounty2,
        int runeSpawnBounty3,
        int runeSpawnBounty4,
        int itemSlotTypeInvalid,
        int itemSlotTypeMain,
        int itemSlotTypeBackpack,
        int itemSlotTypeStash,
        int botActionTypeNone,
        int botActionTypeIdle,
        int botActionTypeMoveTo,
        int botActionTypeMoveToDirectly,
        int botActionTypeAttack,
        int botActionTypeAttackMove,
        int botActionTypeUseAbility,
        int botActionTypePickUpRune,
        int botActionTypePickUpItem,
        int botActionTypeDropItem,
        int botActionTypeShrine,
        int botActionTypeDelay,
        int courierActionBurst,
        int courierActionEnemySecretShop,
        int courierActionReturn,
        int courierActionSecretShop,
        int courierActionSideShop,
        int courierActionSideShop2,
        int courierActionTakeStashItems,
        int courierActionTakeAndTransferItems,
        int courierActionTransferItems,
        int courierStateIdle,
        int courierStateAtBase,
        int courierStateMoving,
        int courierStateDeliveringItems,
        int courierStateReturningToBase,
        int courierStateDead,
        int shopHome,
        int shopSide,
        int shopSecret,
        int shopSide2,
        int shopSecret2,
        int abilityTargetTeamNone,
        int abilityTargetTeamFriendly,
        int abilityTargetTeamEnemy,
        int abilityTargetTypeNone,
        int abilityTargetTypeHero,
        int abilityTargetTypeCreep,
        int abilityTargetTypeBuilding,
        int abilityTargetTypeCourier,
        int abilityTargetTypeOther,
        int abilityTargetTypeTree,
        int abilityTargetTypeBasic,
        int abilityTargetTypeAll,
        int laneNone,
        int laneTop,
        int laneMid,
        int laneBot);

    // DAMAGE_TYPE_PHYSICAL
    int getDamageTypePhysical() const { return damageTypePhysical; }

    // DAMAGE_TYPE_MAGICAL
    int getDamageTypeMagical() const { return damageTypeMagical; }

    // DAMAGE_TYPE_PURE
    int getDamageTypePure() const { return damageTypePure; }

    // DAMAGE_TYPE_ALL
    int getDamageTypeAll() const { return damageTypeAll; }

    // TEAM_RADIANT
    int getTeamRadiant() const { return teamRadiant; }

    // TEAM_DIRE
    int getTeamDire() const { return teamDire; }

    // TEAM_NEUTRAL
    int getTeamNeutral() const { return teamNeutral; }

    // TEAM_NONE
    int getTeamNone() const { return teamNone; }

    // RUNE_TYPE_INVALID
    int getRuneTypeInvalid() const { return runeTypeInvalid; }

    // RUNE_TYPE_DOUBLE_DAMAGE
    int getRuneTypeDoubleDamage() const { return runeTypeDoubleDamage; }

    // RUNE_TYPE_HASTE
    int getRuneTypeHaste() const { return runeTypeHaste; }

    // RUNE_TYPE_ILLUSION
    int getRuneTypeIllusion() const { return runeTypeIllusion; }

    // RUNE_TYPE_INVISIBILITY
    int getRuneTypeInvisibility() const { return runeTypeInvisibility; }

    // RUNE_TYPE_REGENERATION
    int getRuneTypeRegeneration() const { return runeTypeRegeneration; }

    // RUNE_TYPE_BOUNTY
    int getRuneTypeBounty() const { return runeTypeBounty; }

    // RUNE_TYPE_ARCANE
    int getRuneTypeArcane() const { return runeTypeArcane; }

    // RUNE_STATUS_UNKNOWN
    int getRuneStatusUnknown() const { return runeStatusUnknown; }

    // RUNE_STATUS_AVAILABLE
    int getRuneStatusAvailable() const { return runeStatusAvailable; }

    // RUNE_STATUS_MISSING
    int getRuneStatusMissing() const { return runeStatusMissing; }

    // RUNE_SPAWN_POWERUP1
    int getRuneSpawnPowerup1() const { return runeSpawnPowerup1; }

    // RUNE_SPAWN_POWERUP2
    int getRuneSpawnPowerup2() const { return runeSpawnPowerup2; }

    // RUNE_SPAWN_BOUNTY1
    int getRuneSpawnBounty1() const { return runeSpawnBounty1; }

    // RUNE_SPAWN_BOUNTY2
    int getRuneSpawnBounty2() const { return runeSpawnBounty2; }

    // RUNE_SPAWN_BOUNTY3
    int getRuneSpawnBounty3() const { return runeSpawnBounty3; }

    // RUNE_SPAWN_BOUNTY4
    int getRuneSpawnBounty4() const { return runeSpawnBounty4; }

    // ITEM_SLOT_TYPE_INVALID
    int getItemSlotTypeInvalid() const { return itemSlotTypeInvalid; }

    // ITEM_SLOT_TYPE_MAIN
    int getItemSlotTypeMain() const { return itemSlotTypeMain; }

    // ITEM_SLOT_TYPE_BACKPACK
    int getItemSlotTypeBackpack() const { return itemSlotTypeBackpack; }

    // ITEM_SLOT_TYPE_STASH
    int getItemSlotTypeStash() const { return itemSlotTypeStash; }

    // BOT_ACTION_TYPE_NONE
    int getBotActionTypeNone() const { return botActionTypeNone; }

    // BOT_ACTION_TYPE_IDLE
    int getBotActionTypeIdle() const { return botActionTypeIdle; }

    // BOT_ACTION_TYPE_MOVE_TO
    int getBotActionTypeMoveTo() const { return botActionTypeMoveTo; }

    // BOT_ACTION_TYPE_MOVE_TO_DIRECTLY
    int getBotActionTypeMoveToDirectly() const { return botActionTypeMoveToDirectly; }

    // BOT_ACTION_TYPE_ATTACK
    int getBotActionTypeAttack() const { return botActionTypeAttack; }

    // BOT_ACTION_TYPE_ATTACK_MOVE
    int getBotActionTypeAttackMove() const { return botActionTypeAttackMove; }

    // BOT_ACTION_TYPE_USE_ABILITY
    int getBotActionTypeUseAbility() const { return botActionTypeUseAbility; }

    // BOT_ACTION_TYPE_PICK_UP_RUNE
    int getBotActionTypePickUpRune() const { return botActionTypePickUpRune; }

    // BOT_ACTION_TYPE_PICK_UP_ITEM
    int getBotActionTypePickUpItem() const { return botActionTypePickUpItem; }

    // BOT_ACTION_TYPE_DROP_ITEM
    int getBotActionTypeDropItem() const { return botActionTypeDropItem; }

    // BOT_ACTION_TYPE_SHRINE
    int getBotActionTypeShrine() const { return botActionTypeShrine; }

    // BOT_ACTION_TYPE_DELAY
    int getBotActionTypeDelay() const { return botActionTypeDelay; }

    // COURIER_ACTION_BURST
    int getCourierActionBurst() const { return courierActionBurst; }

    // COURIER_ACTION_ENEMY_SECRET_SHOP
    int getCourierActionEnemySecretShop() const { return courierActionEnemySecretShop; }

    // COURIER_ACTION_RETURN
    int getCourierActionReturn() const { return courierActionReturn; }

    // COURIER_ACTION_SECRET_SHOP
    int getCourierActionSecretShop() const { return courierActionSecretShop; }

    // COURIER_ACTION_SIDE_SHOP
    int getCourierActionSideShop() const { return courierActionSideShop; }

    // COURIER_ACTION_SIDE_SHOP2
    int getCourierActionSideShop2() const { return courierActionSideShop2; }

    // COURIER_ACTION_TAKE_STASH_ITEMS
    int getCourierActionTakeStashItems() const { return courierActionTakeStashItems; }

    // COURIER_ACTION_TAKE_AND_TRANSFER_ITEMS
    int getCourierActionTakeAndTransferItems() const { return courierActionTakeAndTransferItems; }

    // COURIER_ACTION_TRANSFER_ITEMS
    int getCourierActionTransferItems() const { return courierActionTransferItems; }

    // COURIER_STATE_IDLE
    int getCourierStateIdle() const { return courierStateIdle; }

    // COURIER_STATE_AT_BASE
    int getCourierStateAtBase() const { return courierStateAtBase; }

    // COURIER_STATE_MOVING
    int getCourierStateMoving() const { return courierStateMoving; }

    // COURIER_STATE_DELIVERING_ITEMS
    int getCourierStateDeliveringItems() const { return courierStateDeliveringItems; }

    // COURIER_STATE_RETURNING_TO_BASE
    int getCourierStateReturningToBase() const { return courierStateReturningToBase; }

    // COURIER_STATE_DEAD
    int getCourierStateDead() const { return courierStateDead; }

    // SHOP_HOME
    int getShopHome() const { return shopHome; }

    // SHOP_SIDE
    int getShopSide() const { return shopSide; }

    // SHOP_SECRET
    int getShopSecret() const { return shopSecret; }

    // SHOP_SIDE2
    int getShopSide2() const { return shopSide2; }

    // SHOP_SECRET2
    int getShopSecret2() const { return shopSecret2; }

    // ABILITY_TARGET_TEAM_NONE
    int getAbilityTargetTeamNone() const { return abilityTargetTeamNone; }

    // ABILITY_TARGET_TEAM_FRIENDLY
    int getAbilityTargetTeamFriendly() const { return abilityTargetTeamFriendly; }

    // ABILITY_TARGET_TEAM_ENEMY
    int getAbilityTargetTeamEnemy() const { return abilityTargetTeamEnemy; }

    // ABILITY_TARGET_TYPE_NONE
    int getAbilityTargetTypeNone() const { return abilityTargetTypeNone; }

    // ABILITY_TARGET_TYPE_HERO
    int getAbilityTargetTypeHero() const { return abilityTargetTypeHero; }

    // ABILITY_TARGET_TYPE_CREEP
    int getAbilityTargetTypeCreep() const { return abilityTargetTypeCreep; }

    // ABILITY_TARGET_TYPE_BUILDING
    int getAbilityTargetTypeBuilding() const { return abilityTargetTypeBuilding; }

    // ABILITY_TARGET_TYPE_COURIER
    int getAbilityTargetTypeCourier() const { return abilityTargetTypeCourier; }

    // ABILITY_TARGET_TYPE_OTHER
    int getAbilityTargetTypeOther() const { return abilityTargetTypeOther; }

    // ABILITY_TARGET_TYPE_TREE
    int getAbilityTargetTypeTree() const { return abilityTargetTypeTree; }

    // ABILITY_TARGET_TYPE_BASIC
    int getAbilityTargetTypeBasic() const { return abilityTargetTypeBasic; }

    // ABILITY_TARGET_TYPE_ALL
    int getAbilityTargetTypeAll() const { return abilityTargetTypeAll; }

    // LANE_NONE
    int getLaneNone() const { return laneNone; }

    // LANE_TOP
    int getLaneTop() const { return laneTop; }

    // LANE_MID
    int getLaneMid() const { return laneMid; }

    // LANE_BOT
    int getLaneBot() const { return laneBot; }
};

} /* namespace d2ai */
