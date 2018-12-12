/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_hero_info.h"

namespace d2ai {

const HeroInfo HeroInfo::NOT_DECODED{
    "",
    false,
    false
};

HeroInfo::HeroInfo(
        const std::string& name,
        bool banned,
        bool picked)
    : name(name),
      banned(banned),
      picked(picked) {
}

} /* namespace d2ai */
