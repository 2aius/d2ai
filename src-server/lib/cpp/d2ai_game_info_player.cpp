/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_game_info_player.h"

namespace d2ai {

const GameInfoPlayer GameInfoPlayer::NOT_DECODED{
    0,
    0,
    "",
    false
};

GameInfoPlayer::GameInfoPlayer(
        int teamId,
        int playerId,
        const std::string& heroName,
        bool bot)
    : teamId(teamId),
      playerId(playerId),
      heroName(heroName),
      bot(bot) {
}

} /* namespace d2ai */
