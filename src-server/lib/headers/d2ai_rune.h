/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once


namespace d2ai {

// rune
class Rune final {
private:

    int runeSpawn;
    int runeType;
    int runeStatus;
    double timeSinceSeen;

public:

    static const Rune NOT_DECODED;

    explicit Rune(
        int runeSpawn,
        int runeType,
        int runeStatus,
        double timeSinceSeen);

    // rune spawn (enum in GameInfo)
    int getRuneSpawn() const { return runeSpawn; }

    // rune type (enum in GameInfo)
    int getRuneType() const { return runeType; }

    // rune status (enum in GameInfo)
    int getRuneStatus() const { return runeStatus; }

    // time since seen in seconds
    double getTimeSinceSeen() const { return timeSinceSeen; }
};

} /* namespace d2ai */
