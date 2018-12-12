#include <map>
#include "d2ai_protocol.h"
#include "d2ai_util.h"

namespace d2ai {

const char Protocol::LEVEL1{'&'};
const char Protocol::LEVEL2{'@'};
const char Protocol::LEVEL3{'#'};
const char Protocol::LEVEL4{'%'};
const char Protocol::LEVEL5{'^'};

const std::string Protocol::VERSION{"0.1.0"};

const std::string Protocol::VERSION_MESSAGE_TYPE{"V"};
const std::string Protocol::CAPTAIN_INFO_MESSAGE_TYPE{"C"};
const std::string Protocol::GAME_INFO_MESSAGE_TYPE{"I"};
const std::string Protocol::OBSERVATION_MESSAGE_TYPE{"O"};

std::string Protocol::decodeVersion(const std::string& message) {
    std::string version{"INVALID"};
    std::vector<std::string> sv1 = Util::split(message, Protocol::LEVEL1);
    // [1] PROTOCOL VERSION
    if ((sv1.size() == 2)
            && (sv1[0] == Protocol::VERSION_MESSAGE_TYPE))
        version = sv1[1];
    return version;
}

CaptainInfo Protocol::decodeCaptainInfo(const std::string& message) {
    std::vector<std::string> sv1 = Util::split(message, Protocol::LEVEL1);
    if ((sv1.size() != 5)
            || (sv1[0] != Protocol::CAPTAIN_INFO_MESSAGE_TYPE)) {
        Util::print("CaptainInfo size must be 5 (size = " + std::to_string(sv1.size())
                    + ") Message = " + message);
        return CaptainInfo::NOT_DECODED;
    }
    // [1] Team ID
    int teamId{std::stoi(sv1[1])};
    // [2] Is Ban Phase
    bool inBanPhase{std::stoi(sv1[2]) != 0};
    // [3] Is Pick Phase
    bool inPickPhase{std::stoi(sv1[3]) != 0};
    // [4] Hero Infos
    std::vector<HeroInfo> heroes;
    std::vector<std::string> sv2 = Util::split(sv1[4], Protocol::LEVEL2);
    for (auto const& h : sv2) {
        std::vector<std::string> sv3 = Util::split(h, Protocol::LEVEL3);
        if (sv3.size() != 3) {
            Util::print("HeroInfo size must be 3 (size = " + std::to_string(sv3.size())
                + ") Message = " + h);
            return CaptainInfo::NOT_DECODED;
        }
        std::string name{sv3[0]};
        bool banned{std::stoi(sv3[1]) != 0};
        bool picked{std::stoi(sv3[2]) != 0};
        HeroInfo hero(
                name,
                banned,
                picked);
        heroes.push_back(hero);
    }
    // return decoded CaptainInfo
    CaptainInfo cap(
            true,
            teamId,
            inBanPhase,
            inPickPhase,
            heroes);
    return cap;
}

Vector3d Protocol::decodeVector(const std::string& str, const char levelChar) {
    std::vector<std::string> sv = Util::split(str, levelChar);
    if (sv.size() != 3) {
        Util::print("Vector size must be 3 (size = " + std::to_string(sv.size())
            + ") Message = " + str);
        return Vector3d::NOT_DECODED;
    }
    return Vector3d(std::stod(sv[0]), std::stod(sv[1]), std::stod(sv[2]));
}

bool Protocol::decodeAbility(const std::string& str,
        std::vector<Ability>& abilities, const char levelChar) {
    std::vector<std::string> sv = Util::split(str, levelChar);
    if (sv.size() != 45) {
        Util::print("Ability size must be 45 (size = " + std::to_string(sv.size())
            + ") Message = " + str);
        return false;
    }
    int i = 0;
    int slot{std::stoi(sv[i++])};
    std::string name{sv[i++]};
    bool upgradable{std::stoi(sv[i++]) != 0};
    bool autoCast{std::stoi(sv[i++]) != 0};
    bool toggled{std::stoi(sv[i++]) != 0};
    bool toggle{std::stoi(sv[i++]) != 0};
    bool activated{std::stoi(sv[i++]) != 0};
    bool channeling{std::stoi(sv[i++]) != 0};
    bool cooldownReady{std::stoi(sv[i++]) != 0};
    bool fullyCastable{std::stoi(sv[i++]) != 0};
    bool hidden{std::stoi(sv[i++]) != 0};
    bool inAbilityPhase{std::stoi(sv[i++]) != 0};
    bool ownersManaEnough{std::stoi(sv[i++]) != 0};
    bool passive{std::stoi(sv[i++]) != 0};
    bool stealable{std::stoi(sv[i++]) != 0};
    bool stolen{std::stoi(sv[i++]) != 0};
    bool trained{std::stoi(sv[i++]) != 0};
    bool procsMagicStick{std::stoi(sv[i++]) != 0};
    bool behaviorPassive{std::stoi(sv[i++]) != 0};
    bool behaviorNoTarget{std::stoi(sv[i++]) != 0};
    bool behaviorUnitTarget{std::stoi(sv[i++]) != 0};
    bool behaviorPoint{std::stoi(sv[i++]) != 0};
    bool behaviorAoe{std::stoi(sv[i++]) != 0};
    bool behaviorNotLearnable{std::stoi(sv[i++]) != 0};
    bool behaviorChannelled{std::stoi(sv[i++]) != 0};
    double castPoint{std::stod(sv[i++])};
    int castRange{std::stoi(sv[i++])};
    int channelledManaCostPerSecond{std::stoi(sv[i++])};
    double channelTime{std::stod(sv[i++])};
    double duration{std::stod(sv[i++])};
    double cooldownTimeRemaining{std::stod(sv[i++])};
    int currentCharges{std::stoi(sv[i++])};
    int damage{std::stoi(sv[i++])};
    int damageType{std::stoi(sv[i++])};
    int heroLevelRequiredToUpgrade{std::stoi(sv[i++])};
    int initialCharges{std::stoi(sv[i++])};
    int level{std::stoi(sv[i++])};
    int manaCost{std::stoi(sv[i++])};
    int maxLevel{std::stoi(sv[i++])};
    int secondaryCharges{std::stoi(sv[i++])};
    int targetTeam{std::stoi(sv[i++])};
    int targetType{std::stoi(sv[i++])};
    bool item{std::stoi(sv[i++]) != 0};
    bool disassemblable{std::stoi(sv[i++]) != 0};
    bool combineLocked{std::stoi(sv[i++]) != 0}; // 45
    Ability a (
            slot,
            name,
            upgradable,
            autoCast,
            toggled,
            toggle,
            activated,
            channeling,
            cooldownReady,
            fullyCastable,
            hidden,
            inAbilityPhase,
            ownersManaEnough,
            passive,
            stealable,
            stolen,
            trained,
            procsMagicStick,
            behaviorPassive,
            behaviorNoTarget,
            behaviorUnitTarget,
            behaviorPoint,
            behaviorAoe,
            behaviorNotLearnable,
            behaviorChannelled,
            castPoint,
            castRange,
            channelledManaCostPerSecond,
            channelTime,
            duration,
            cooldownTimeRemaining,
            currentCharges,
            damage,
            damageType,
            heroLevelRequiredToUpgrade,
            initialCharges,
            level,
            manaCost,
            maxLevel,
            secondaryCharges,
            targetTeam,
            targetType,
            item,
            disassemblable,
            combineLocked);
    abilities.push_back(a);
    return true;
}

GameInfo Protocol::decodeGameInfo(const std::string& message) {
    std::vector<std::string> sv1 = Util::split(message, Protocol::LEVEL1);
    if ((sv1.size() != 27)
            || (sv1[0] != Protocol::GAME_INFO_MESSAGE_TYPE)) {
        Util::print("GameInfo size must be 27 (size = "
                + std::to_string(sv1.size()) + ") Message = " + message);
        return GameInfo::NOT_DECODED;
    }
    // [1] Game Time
    double gameTime{std::stod(sv1[1])};
    // [2] Dota Time
    double dotaTime{std::stod(sv1[2])};
    // [3] Damage Type Enum
    std::vector<std::string> sv2 = Util::split(sv1[3], Protocol::LEVEL2);
    if (sv2.size() != 4) return GameInfo::NOT_DECODED;
    int damageTypePhysical{std::stoi(sv2[0])};
    int damageTypeMagical{std::stoi(sv2[1])};
    int damageTypePure{std::stoi(sv2[2])};
    int damageTypeAll{std::stoi(sv2[3])};
    // [4] Team Enum
    sv2 = Util::split(sv1[4], Protocol::LEVEL2);
    if (sv2.size() != 4) return GameInfo::NOT_DECODED;
    int teamRadiant{std::stoi(sv2[0])};
    int teamDire{std::stoi(sv2[1])};
    int teamNeutral{std::stoi(sv2[2])};
    int teamNone{std::stoi(sv2[3])};
    // [5] Rune Type Enum
    sv2 = Util::split(sv1[5], Protocol::LEVEL2);
    if (sv2.size() != 8) return GameInfo::NOT_DECODED;
    int runeTypeInvalid{std::stoi(sv2[0])};
    int runeTypeDoubleDamage{std::stoi(sv2[1])};
    int runeTypeHaste{std::stoi(sv2[2])};
    int runeTypeIllusion{std::stoi(sv2[3])};
    int runeTypeInvisibility{std::stoi(sv2[4])};
    int runeTypeRegeneration{std::stoi(sv2[5])};
    int runeTypeBounty{std::stoi(sv2[6])};
    int runeTypeArcane{std::stoi(sv2[7])};
    // [6] Rune Status Enum
    sv2 = Util::split(sv1[6], Protocol::LEVEL2);
    if (sv2.size() != 3) return GameInfo::NOT_DECODED;
    int runeStatusUnknown{std::stoi(sv2[0])};
    int runeStatusAvailable{std::stoi(sv2[1])};
    int runeStatusMissing{std::stoi(sv2[2])};
    // [7] Rune Spawn Enum
    sv2 = Util::split(sv1[7], Protocol::LEVEL2);
    if (sv2.size() != 6) return GameInfo::NOT_DECODED;
    int runeSpawnPowerup1{std::stoi(sv2[0])};
    int runeSpawnPowerup2{std::stoi(sv2[1])};
    int runeSpawnBounty1{std::stoi(sv2[2])};
    int runeSpawnBounty2{std::stoi(sv2[3])};
    int runeSpawnBounty3{std::stoi(sv2[4])};
    int runeSpawnBounty4{std::stoi(sv2[5])};
    // [8] Item Slot Enum
    sv2 = Util::split(sv1[8], Protocol::LEVEL2);
    if (sv2.size() != 4) return GameInfo::NOT_DECODED;
    int itemSlotTypeInvalid{std::stoi(sv2[0])};
    int itemSlotTypeMain{std::stoi(sv2[1])};
    int itemSlotTypeBackpack{std::stoi(sv2[2])};
    int itemSlotTypeStash{std::stoi(sv2[3])};
    // [9] Bot Action Type Enum
    sv2 = Util::split(sv1[9], Protocol::LEVEL2);
    if (sv2.size() != 12) return GameInfo::NOT_DECODED;
    int botActionTypeNone{std::stoi(sv2[0])};
    int botActionTypeIdle{std::stoi(sv2[1])};
    int botActionTypeMoveTo{std::stoi(sv2[2])};
    int botActionTypeMoveToDirectly{std::stoi(sv2[3])};
    int botActionTypeAttack{std::stoi(sv2[4])};
    int botActionTypeAttackMove{std::stoi(sv2[5])};
    int botActionTypeUseAbility{std::stoi(sv2[6])};
    int botActionTypePickUpRune{std::stoi(sv2[7])};
    int botActionTypePickUpItem{std::stoi(sv2[8])};
    int botActionTypeDropItem{std::stoi(sv2[9])};
    int botActionTypeShrine{std::stoi(sv2[10])};
    int botActionTypeDelay{std::stoi(sv2[11])};
    // [10] Courier Action Enum
    sv2 = Util::split(sv1[10], Protocol::LEVEL2);
    if (sv2.size() != 9) return GameInfo::NOT_DECODED;
    int courierActionBurst{std::stoi(sv2[0])};
    int courierActionEnemySecretShop{std::stoi(sv2[1])};
    int courierActionReturn{std::stoi(sv2[2])};
    int courierActionSecretShop{std::stoi(sv2[3])};
    int courierActionSideShop{std::stoi(sv2[4])};
    int courierActionSideShop2{std::stoi(sv2[5])};
    int courierActionTakeStashItems{std::stoi(sv2[6])};
    int courierActionTakeAndTransferItems{std::stoi(sv2[7])};
    int courierActionTransferItems{std::stoi(sv2[8])};
    // [11] Courier State Enum
    sv2 = Util::split(sv1[11], Protocol::LEVEL2);
    if (sv2.size() != 6) return GameInfo::NOT_DECODED;
    int courierStateIdle{std::stoi(sv2[0])};
    int courierStateAtBase{std::stoi(sv2[1])};
    int courierStateMoving{std::stoi(sv2[2])};
    int courierStateDeliveringItems{std::stoi(sv2[3])};
    int courierStateReturningToBase{std::stoi(sv2[4])};
    int courierStateDead{std::stoi(sv2[5])};
    // [12] Shop Enum
    sv2 = Util::split(sv1[12], Protocol::LEVEL2);
    if (sv2.size() != 5) return GameInfo::NOT_DECODED;
    int shopHome{std::stoi(sv2[0])};
    int shopSide{std::stoi(sv2[1])};
    int shopSecret{std::stoi(sv2[2])};
    int shopSide2{std::stoi(sv2[3])};
    int shopSecret2{std::stoi(sv2[4])};
    // [13] Ability Target Team Enum
    sv2 = Util::split(sv1[13], Protocol::LEVEL2);
    if (sv2.size() != 3) return GameInfo::NOT_DECODED;
    int abilityTargetTeamNone{std::stoi(sv2[0])};
    int abilityTargetTeamFriendly{std::stoi(sv2[1])};
    int abilityTargetTeamEnemy{std::stoi(sv2[2])};
    // [14] Ability Target Type Enum
    sv2 = Util::split(sv1[14], Protocol::LEVEL2);
    if (sv2.size() != 9) return GameInfo::NOT_DECODED;
    int abilityTargetTypeNone{std::stoi(sv2[0])};
    int abilityTargetTypeHero{std::stoi(sv2[1])};
    int abilityTargetTypeCreep{std::stoi(sv2[2])};
    int abilityTargetTypeBuilding{std::stoi(sv2[3])};
    int abilityTargetTypeCourier{std::stoi(sv2[4])};
    int abilityTargetTypeOther{std::stoi(sv2[5])};
    int abilityTargetTypeTree{std::stoi(sv2[6])};
    int abilityTargetTypeBasic{std::stoi(sv2[7])};
    int abilityTargetTypeAll{std::stoi(sv2[8])};
    // [15] Lane Enum
    sv2 = Util::split(sv1[15], Protocol::LEVEL2);
    if (sv2.size() != 4) return GameInfo::NOT_DECODED;
    int laneNone{std::stoi(sv2[0])};
    int laneTop{std::stoi(sv2[1])};
    int laneMid{std::stoi(sv2[2])};
    int laneBot{std::stoi(sv2[3])};
    GameInfoEnums enums(
            damageTypePhysical,
            damageTypeMagical,
            damageTypePure,
            damageTypeAll,
            teamRadiant,
            teamDire,
            teamNeutral,
            teamNone,
            runeTypeInvalid,
            runeTypeDoubleDamage,
            runeTypeHaste,
            runeTypeIllusion,
            runeTypeInvisibility,
            runeTypeRegeneration,
            runeTypeBounty,
            runeTypeArcane,
            runeStatusUnknown,
            runeStatusAvailable,
            runeStatusMissing,
            runeSpawnPowerup1,
            runeSpawnPowerup2,
            runeSpawnBounty1,
            runeSpawnBounty2,
            runeSpawnBounty3,
            runeSpawnBounty4,
            itemSlotTypeInvalid,
            itemSlotTypeMain,
            itemSlotTypeBackpack,
            itemSlotTypeStash,
            botActionTypeNone,
            botActionTypeIdle,
            botActionTypeMoveTo,
            botActionTypeMoveToDirectly,
            botActionTypeAttack,
            botActionTypeAttackMove,
            botActionTypeUseAbility,
            botActionTypePickUpRune,
            botActionTypePickUpItem,
            botActionTypeDropItem,
            botActionTypeShrine,
            botActionTypeDelay,
            courierActionBurst,
            courierActionEnemySecretShop,
            courierActionReturn,
            courierActionSecretShop,
            courierActionSideShop,
            courierActionSideShop2,
            courierActionTakeStashItems,
            courierActionTakeAndTransferItems,
            courierActionTransferItems,
            courierStateIdle,
            courierStateAtBase,
            courierStateMoving,
            courierStateDeliveringItems,
            courierStateReturningToBase,
            courierStateDead,
            shopHome,
            shopSide,
            shopSecret,
            shopSide2,
            shopSecret2,
            abilityTargetTeamNone,
            abilityTargetTeamFriendly,
            abilityTargetTeamEnemy,
            abilityTargetTypeNone,
            abilityTargetTypeHero,
            abilityTargetTypeCreep,
            abilityTargetTypeBuilding,
            abilityTargetTypeCourier,
            abilityTargetTypeOther,
            abilityTargetTypeTree,
            abilityTargetTypeBasic,
            abilityTargetTypeAll,
            laneNone,
            laneTop,
            laneMid,
            laneBot);
    // [16] Allied Team ID
    int alliedTeamId{std::stoi(sv1[16])};
    // [17] Enemy Team ID
    int enemyTeamId{std::stoi(sv1[17])};
    // [18] Players
    sv2 = Util::split(sv1[18], Protocol::LEVEL2);
    if (sv2.size() != 10) return GameInfo::NOT_DECODED; // 5 RADIANT + 5 DIRE
    std::map<int, GameInfoPlayer> players;
    for (auto const& p : sv2) {
        std::vector<std::string> sv3 = Util::split(p, Protocol::LEVEL3);
        if (sv3.size() != 4) return GameInfo::NOT_DECODED;
        int teamId{std::stoi(sv3[0])};
        int playerId{std::stoi(sv3[1])};
        std::string heroName{sv3[2]};
        bool bot{std::stoi(sv3[3]) != 0};
        GameInfoPlayer player{teamId, playerId, heroName, bot};
        players.insert(std::pair<int, GameInfoPlayer>(playerId, player));
    }
    // [19] World Bounds min X
    double minWorldBoundsX{std::stod(sv1[19])};
    // [20] World Bounds min Y
    double minWorldBoundsY{std::stod(sv1[20])};
    // [21] World Bounds max X
    double maxWorldBoundsX{std::stod(sv1[21])};
    // [22] World Bounds max Y
    double maxWorldBoundsY{std::stod(sv1[22])};
    Vector3d minWorldBounds{minWorldBoundsX, minWorldBoundsY, 0.};
    Vector3d maxWorldBounds{maxWorldBoundsX, maxWorldBoundsY, 0.};
    // [23] Shop Locations
    sv2 = Util::split(sv1[23], Protocol::LEVEL2);
    if (sv2.size() != 10) return GameInfo::NOT_DECODED;
    Vector3d vRadiantShopHome{decodeVector(sv2[0], Protocol::LEVEL3)};
    Vector3d vRadiantShopSide{decodeVector(sv2[1], Protocol::LEVEL3)};
    Vector3d vRadiantShopSecret{decodeVector(sv2[2], Protocol::LEVEL3)};
    Vector3d vRadiantShopSide2{decodeVector(sv2[3], Protocol::LEVEL3)};
    Vector3d vRadiantShopSecret2{decodeVector(sv2[4], Protocol::LEVEL3)};
    Vector3d vDireShopHome{decodeVector(sv2[5], Protocol::LEVEL3)};
    Vector3d vDireShopSide{decodeVector(sv2[6], Protocol::LEVEL3)};
    Vector3d vDireShopSecret{decodeVector(sv2[7], Protocol::LEVEL3)};
    Vector3d vDireShopSide2{decodeVector(sv2[8], Protocol::LEVEL3)};
    Vector3d vDireShopSecret2{decodeVector(sv2[9], Protocol::LEVEL3)};
    // [24] Rune Spawn Locations
    sv2 = Util::split(sv1[24], Protocol::LEVEL2);
    if (sv2.size() != 6) return GameInfo::NOT_DECODED;
    Vector3d vRuneSpawnPowerup1{decodeVector(sv2[0], Protocol::LEVEL3)};
    Vector3d vRuneSpawnPowerup2{decodeVector(sv2[1], Protocol::LEVEL3)};
    Vector3d vRuneSpawnBounty1{decodeVector(sv2[2], Protocol::LEVEL3)};
    Vector3d vRuneSpawnBounty2{decodeVector(sv2[3], Protocol::LEVEL3)};
    Vector3d vRuneSpawnBounty3{decodeVector(sv2[4], Protocol::LEVEL3)};
    Vector3d vRuneSpawnBounty4{decodeVector(sv2[5], Protocol::LEVEL3)};
    // [25] Ancient Locations
    sv2 = Util::split(sv1[25], Protocol::LEVEL2);
    if (sv2.size() != 2) return GameInfo::NOT_DECODED;
    Vector3d vRadiantAncient{decodeVector(sv2[0], Protocol::LEVEL3)};
    Vector3d vDireAncient{decodeVector(sv2[1], Protocol::LEVEL3)};
    GameInfoLocations locations(
            vRadiantShopHome,
            vRadiantShopSide,
            vRadiantShopSecret,
            vRadiantShopSide2,
            vRadiantShopSecret2,
            vDireShopHome,
            vDireShopSide,
            vDireShopSecret,
            vDireShopSide2,
            vDireShopSecret2,
            vRuneSpawnPowerup1,
            vRuneSpawnPowerup2,
            vRuneSpawnBounty1,
            vRuneSpawnBounty2,
            vRuneSpawnBounty3,
            vRuneSpawnBounty4,
            vRadiantAncient,
            vDireAncient
    );
    // [26] Items
    sv2 = Util::split(sv1[26], Protocol::LEVEL2);
    std::vector<GameInfoItem> items;
    for (auto const& i : sv2) {
        std::vector<std::string> sv3 = Util::split(i, Protocol::LEVEL3);
        if (sv3.size() != 4) {
            Util::print("Item size must be 4 (size = " + std::to_string(sv3.size())
                + ") Message = " + i);
            return GameInfo::NOT_DECODED;
        }
        std::string name{sv3[0]};
        int cost{std::stoi(sv3[1])};
        bool purchasedFromSecretShop{std::stoi(sv3[2]) != 0};
        bool purchasedFromSideShop{std::stoi(sv3[3]) != 0};
        GameInfoItem item(
                name,
                cost,
                purchasedFromSecretShop,
                purchasedFromSideShop);
        items.push_back(item);
    }
    // return decoded GameInfo
    GameInfo info(
            true,
            gameTime,
            dotaTime,
            enums,
            alliedTeamId,
            enemyTeamId,
            players,
            minWorldBounds,
            maxWorldBounds,
            locations,
            items);
    return info;
}

Observation Protocol::decodeObservation(const std::string& message,
        int alliedTeamId, int enemyTeamId) {
    std::vector<std::string> sv1 = Util::split(message, Protocol::LEVEL1);
    if ((sv1.size() != 13)
            || (sv1[0] != Protocol::OBSERVATION_MESSAGE_TYPE)) {
        Util::print("Observation size must be 13 (size = "
                + std::to_string(sv1.size()) + ") Message = " + message);
        return Observation::NOT_DECODED;
    }
    // [1] Game Time
    double gameTime{std::stod(sv1[1])};
    // [2] Dota Time
    double dotaTime{std::stod(sv1[2])};
    // [3] Player ID
    int playerId{std::stoi(sv1[3])};
    // [4] Player Current Action Type
    int playerCurrentActionType{std::stoi(sv1[4])};
    // [5] Time of Day
    double timeOfDay{std::stod(sv1[5])};
    // [6] Glyph Cooldown
    double glyphCooldown{std::stod(sv1[6])};
    // [7] Roshan Kill Time
    double roshanKillTime{std::stod(sv1[7])};
    // [8] Courier Available
    bool courierAvailable{std::stoi(sv1[8]) != 0};
    // [9] Units
    std::vector<std::string> sv2 = Util::split(sv1[9], Protocol::LEVEL2);
    Unit controlledHero{Unit::NOT_DECODED};
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
    for (auto const& p : sv2) {
        std::vector<std::string> sv3 = Util::split(p, Protocol::LEVEL3);
        if (sv3.size() != 91) {
            Util::print("Unit size must be 91 (size = " + std::to_string(sv3.size())
                + ") Message = " + p);
            return Observation::NOT_DECODED;
        }
        int i = 0;
        int handleId{std::stoi(sv3[i++])};
        int playerId{std::stoi(sv3[i++])};
        int teamId{std::stoi(sv3[i++])};
        std::string name{sv3[i++]};
        int currentActionType{stoi(sv3[i++])};
        bool controlled{std::stoi(sv3[i++]) != 0};
        bool hero{std::stoi(sv3[i++]) != 0};
        bool creep{std::stoi(sv3[i++]) != 0};
        bool ancientCreep{std::stoi(sv3[i++]) != 0};
        bool building{std::stoi(sv3[i++]) != 0};
        bool tower{std::stoi(sv3[i++]) != 0};
        bool fort{std::stoi(sv3[i++]) != 0};
        int courierState{std::stoi(sv3[i++])};
        int courierValue{std::stoi(sv3[i++])};
        bool courierFlying{std::stoi(sv3[i++]) != 0};
        bool illusion{std::stoi(sv3[i++]) != 0};
        bool seeable{std::stoi(sv3[i++]) != 0};
        Vector3d location{decodeVector(sv3[i++], Protocol::LEVEL4)};
        int facing{std::stoi(sv3[i++])};
        Vector3d velocity{decodeVector(sv3[i++], Protocol::LEVEL4)};
        int health{std::stoi(sv3[i++])};
        int maxHealth{std::stoi(sv3[i++])};
        int healthRegen{std::stoi(sv3[i++])};
        int mana{std::stoi(sv3[i++])};
        int maxMana{std::stoi(sv3[i++])};
        int manaRegen{std::stoi(sv3[i++])};
        int baseMovementSpeed{std::stoi(sv3[i++])};
        int currentMovementSpeed{std::stoi(sv3[i++])};
        bool alive{std::stoi(sv3[i++]) != 0};
        double respawnTime{std::stod(sv3[i++])};
        bool buybackAvailable{std::stoi(sv3[i++]) != 0};
        int buybackCost{std::stoi(sv3[i++])};
        double buybackCooldown{std::stod(sv3[i++])};
        double remainingLifespan{std::stod(sv3[i++])};
        double baseDamage{std::stod(sv3[i++])};
        double baseDamageVariance{std::stod(sv3[i++])};
        double attackDamage{std::stod(sv3[i++])};
        int attackRange{std::stoi(sv3[i++])};
        int attackSpeed{std::stoi(sv3[i++])};
        double secondsPerAttack{std::stod(sv3[i++])};
        double lastAttackTime{std::stod(sv3[i++])};
        int acquisitionRange{std::stoi(sv3[i++])};
        int attackProjectileSpeed{std::stoi(sv3[i++])};
        double spellAmp{std::stod(sv3[i++])};
        double armor{std::stod(sv3[i++])};
        double magicResist{std::stod(sv3[i++])};
        double evasion{std::stod(sv3[i++])};
        int bountyXp{std::stoi(sv3[i++])};
        int bountyGoldMin{std::stoi(sv3[i++])};
        int bountyGoldMax{std::stoi(sv3[i++])};
        int xpNeededToLevel{std::stoi(sv3[i++])};
        int abilityPoints{std::stoi(sv3[i++])};
        int level{std::stoi(sv3[i++])};
        int gold{std::stoi(sv3[i++])};
        int netWorth{std::stoi(sv3[i++])};
        int stashValue{std::stoi(sv3[i++])};
        int lastHits{std::stoi(sv3[i++])};
        int denies{std::stoi(sv3[i++])};
        double boundingRadius{std::stod(sv3[i++])};
        int dayTimeVisionRange{std::stoi(sv3[i++])};
        int nightTimeVisionRange{std::stoi(sv3[i++])};
        int currentVisionRange{std::stoi(sv3[i++])};
        int healthRegenPerStr{std::stoi(sv3[i++])};
        int manaRegenPerInt{std::stoi(sv3[i++])};
        bool channeling{std::stoi(sv3[i++]) != 0};
        bool usingAbility{std::stoi(sv3[i++]) != 0};
        bool castingAbility{std::stoi(sv3[i++]) != 0};
        bool attackImmune{std::stoi(sv3[i++]) != 0};
        bool blind{std::stoi(sv3[i++]) != 0};
        bool blockDisabled{std::stoi(sv3[i++]) != 0};
        bool disarmed{std::stoi(sv3[i++]) != 0};
        bool dominated{std::stoi(sv3[i++]) != 0};
        bool evadeDisabled{std::stoi(sv3[i++]) != 0};
        bool hexed{std::stoi(sv3[i++]) != 0};
        bool invisible{std::stoi(sv3[i++]) != 0};
        bool invulnerable{std::stoi(sv3[i++]) != 0};
        bool magicImmune{std::stoi(sv3[i++]) != 0};
        bool muted{std::stoi(sv3[i++]) != 0};
        bool nightmared{std::stoi(sv3[i++]) != 0};
        bool rooted{std::stoi(sv3[i++]) != 0};
        bool silenced{std::stoi(sv3[i++]) != 0};
        bool speciallyDeniable{std::stoi(sv3[i++]) != 0};
        bool stunned{std::stoi(sv3[i++]) != 0};
        bool unableToMiss{std::stoi(sv3[i++]) != 0};
        bool scepterOwned{std::stoi(sv3[i++]) != 0};
        double timeSinceDamagedByAnyHero{std::stod(sv3[i++])};
        double timeSinceDamagedByCreep{std::stod(sv3[i++])};
        double timeSinceDamagedByTower{std::stod(sv3[i++])};
        std::vector<Ability> abilities;
        std::vector<std::string> sv4 = Util::split(sv3[i++], Protocol::LEVEL4);
        for (auto const& str : sv4)
            if (!str.empty() && !decodeAbility(str, abilities, Protocol::LEVEL5))
                return Observation::NOT_DECODED;
        std::vector<Ability> items;
        sv4 = Util::split(sv3[i++], Protocol::LEVEL4);
        for (auto const& str : sv4)
            if (!str.empty() && !decodeAbility(str, items, Protocol::LEVEL5))
                return Observation::NOT_DECODED;
        std::vector<int> nearbyTrees; // 91
        sv4 = Util::split(sv3[i++], Protocol::LEVEL4);
        for (auto const& str : sv4)
            if (!str.empty()) nearbyTrees.push_back(std::stoi(str));
        Unit unit(
                handleId,
                playerId,
                teamId,
                name,
                currentActionType,
                controlled,
                hero,
                creep,
                ancientCreep,
                building,
                tower,
                fort,
                courierState,
                courierValue,
                courierFlying,
                illusion,
                seeable,
                location,
                facing,
                velocity,
                health,
                maxHealth,
                healthRegen,
                mana,
                maxMana,
                manaRegen,
                baseMovementSpeed,
                currentMovementSpeed,
                alive,
                respawnTime,
                buybackAvailable,
                buybackCost,
                buybackCooldown,
                remainingLifespan,
                baseDamage,
                baseDamageVariance,
                attackDamage,
                attackRange,
                attackSpeed,
                secondsPerAttack,
                lastAttackTime,
                acquisitionRange,
                attackProjectileSpeed,
                spellAmp,
                armor,
                magicResist,
                evasion,
                bountyXp,
                bountyGoldMin,
                bountyGoldMax,
                xpNeededToLevel,
                abilityPoints,
                level,
                gold,
                netWorth,
                stashValue,
                lastHits,
                denies,
                boundingRadius,
                dayTimeVisionRange,
                nightTimeVisionRange,
                currentVisionRange,
                healthRegenPerStr,
                manaRegenPerInt,
                channeling,
                usingAbility,
                castingAbility,
                attackImmune,
                blind,
                blockDisabled,
                disarmed,
                dominated,
                evadeDisabled,
                hexed,
                invisible,
                invulnerable,
                magicImmune,
                muted,
                nightmared,
                rooted,
                silenced,
                speciallyDeniable,
                stunned,
                unableToMiss,
                scepterOwned,
                timeSinceDamagedByAnyHero,
                timeSinceDamagedByCreep,
                timeSinceDamagedByTower,
                abilities,
                items,
                nearbyTrees);
        // filter unit
        if (unit.isControlled()) {
            controlledHero = unit;
        } else if (unit.getTeamId() == alliedTeamId) {
            if (unit.isHero()) alliedHeroes.push_back(unit);
            else if (unit.isBuilding()) alliedBuildings.push_back(unit);
            else if (unit.isCreep() || unit.isAncientCreep())
                alliedCreeps.push_back(unit);
            else if (unit.getName().find("courier") != std::string::npos)
                alliedCouriers.push_back(unit);
            else if (unit.getName().find("ward") != std::string::npos)
                alliedWards.push_back(unit);
        } else if (unit.getTeamId() == enemyTeamId) {
            if (unit.isHero()) enemyHeroes.push_back(unit);
            else if (unit.isBuilding()) enemyBuildings.push_back(unit);
            else if (unit.isCreep() || unit.isAncientCreep())
                enemyCreeps.push_back(unit);
            else if (unit.getName().find("courier") != std::string::npos)
                enemyCouriers.push_back(unit);
            else if (unit.getName().find("ward") != std::string::npos)
                enemyWards.push_back(unit);
        } else if (unit.isCreep() || unit.isAncientCreep()) {
            neutralCreeps.push_back(unit);
        }
    }
    Units units(
            controlledHero,
            alliedHeroes,
            alliedBuildings,
            alliedCreeps,
            alliedWards,
            alliedCouriers,
            enemyHeroes,
            enemyBuildings,
            enemyCreeps,
            enemyWards,
            enemyCouriers,
            neutralCreeps);
    // [10] Dropped Items
    sv2 = Util::split(sv1[10], Protocol::LEVEL2);
    std::vector<DroppedItem> droppedItems;
    for (auto const& di : sv2) if (!di.empty()) {
        std::vector<std::string> sv3 = Util::split(di, Protocol::LEVEL3);
        if (sv3.size() != 3) {
            Util::print("Dropped Item size must be 3 (size = " + std::to_string(sv3.size())
            + ") Message = " + di);
            return Observation::NOT_DECODED;
        }
        int handleId{std::stoi(sv3[0])};
        std::string name{sv3[1]};
        Vector3d location{decodeVector(sv3[2], Protocol::LEVEL4)};
        DroppedItem droppedItem(
                handleId,
                name,
                location);
        droppedItems.push_back(droppedItem);
    }
    // [11] Runes
    sv2 = Util::split(sv1[11], Protocol::LEVEL2);
    std::vector<Rune> runes;
    for (auto const& r : sv2) if (!r.empty()) {
        std::vector<std::string> sv3 = Util::split(r, Protocol::LEVEL3);
        if (sv3.size() != 4) {
            Util::print("Rune size must be 4 (size = " + std::to_string(sv3.size())
            + ") Message = " + r);
            return Observation::NOT_DECODED;
        }
        int runeSpawn{std::stoi(sv3[0])};
        int runeType{std::stoi(sv3[1])};
        int runeStatus{std::stoi(sv3[2])};
        double timeSinceSeen{std::stod(sv3[3])};
        Rune rune(
                runeSpawn,
                runeType,
                runeStatus,
                timeSinceSeen);
        runes.push_back(rune);
    }
    // [12] Lane Front
    sv2 = Util::split(sv1[12], Protocol::LEVEL2);
    if (sv2.size() != 3) {
        Util::print("Lane Fronts size must be 3 (size = " + std::to_string(sv2.size())
        + ") Message = " + sv1[12]);
        return Observation::NOT_DECODED;
    }
    Vector3d laneFrontTop{decodeVector(sv2[0], Protocol::LEVEL3)};
    Vector3d laneFrontMid{decodeVector(sv2[1], Protocol::LEVEL3)};
    Vector3d laneFrontBot{decodeVector(sv2[2], Protocol::LEVEL3)};
    // return decoded Observation
    Observation observation(
            true,
            gameTime,
            dotaTime,
            playerId,
            playerCurrentActionType,
            timeOfDay,
            glyphCooldown,
            roshanKillTime,
            courierAvailable,
            units,
            droppedItems,
            runes,
            laneFrontTop,
            laneFrontMid,
            laneFrontBot);
    return observation;
}

std::string Protocol::encodeActions(const std::vector<Action>& actions) {
    static const std::string LVL1{Protocol::LEVEL1};
    static const std::string LVL2{Protocol::LEVEL2};
    std::string encoded{""};
    bool isFirstAction = true;
    for (auto const& act : actions) {
        if (isFirstAction) isFirstAction = false;
        else encoded += LVL1;
        encoded += std::to_string(act.getType());
        for (auto const& arg : act.getArgs()) encoded += (LVL2 + arg);
    }
    return encoded;
}

} /* namespace d2ai */
