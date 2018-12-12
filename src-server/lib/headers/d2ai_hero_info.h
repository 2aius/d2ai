/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <string>

namespace d2ai {

// info about specific hero during CAPTAINS MODE selection
class HeroInfo final {
private:

    std::string name;
    bool banned;
    bool picked;

public:

    static const HeroInfo NOT_DECODED;

    explicit HeroInfo(
        const std::string& name,
        bool banned,
        bool picked);

    // under-the-hood name of the hero
    const std::string& getName() const { return name; }

    // hero is already banned
    bool isBanned() const { return banned; }

    // hero is already picked
    bool isPicked() const { return picked; }
};

} /* namespace d2ai */
