/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_game_info_item.h"

namespace d2ai {

const GameInfoItem GameInfoItem::NOT_DECODED{
    "",
    0,
    false,
    false
};

GameInfoItem::GameInfoItem(
        const std::string& name,
        int cost,
        bool purchasedFromSecretShop,
        bool purchasedFromSideShop)
    : name(name),
      cost(cost),
      purchasedFromSecretShop(purchasedFromSecretShop),
      purchasedFromSideShop(purchasedFromSideShop) {
}

} /* namespace d2ai */
