/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <vector>
#include "d2ai_hero_info.h"

namespace d2ai {

// info provided to Agent during the CAPTAINS MODE selection phase
class CaptainInfo final {
private:

    bool decoded;
    int teamId;
    bool inBanPhase;
    bool inPickPhase;
    std::vector<HeroInfo> heroes;

public:

    static const CaptainInfo NOT_DECODED;

    explicit CaptainInfo(
        bool decoded,
        int teamId,
        bool inBanPhase,
        bool inPickPhase,
        const std::vector<HeroInfo>& heroes);

    // is successfully decoded
    bool isDecoded() const { return decoded; }

    // team ID selecting hero
    int getTeamId() const { return teamId; }

    // is in CAPTAINS MODE ban phase
    bool isInBanPhase() const { return inBanPhase; }

    // is in CAPTAINS MODE pick phase
    bool isInPickPhase() const { return inPickPhase; }

    // info about each available hero
    const std::vector<HeroInfo>& getHeroes() const { return heroes; }
};

} /* namespace d2ai */
