/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_captain_info.h"

namespace d2ai {

const CaptainInfo CaptainInfo::NOT_DECODED{
    false,
    0,
    false,
    false,
    std::vector<HeroInfo>()
};

CaptainInfo::CaptainInfo(
        bool decoded,
        int teamId,
        bool inBanPhase,
        bool inPickPhase,
        const std::vector<HeroInfo>& heroes)
    : decoded(decoded),
      teamId(teamId),
      inBanPhase(inBanPhase),
      inPickPhase(inPickPhase),
      heroes(heroes) {
}

} /* namespace d2ai */
