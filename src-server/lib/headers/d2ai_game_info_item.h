/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <string>

namespace d2ai {

// item
class GameInfoItem final {
private:

    std::string name;
    int cost;
    bool purchasedFromSecretShop;
    bool purchasedFromSideShop;

public:

    static const GameInfoItem NOT_DECODED;

    explicit GameInfoItem(
        const std::string& name,
        int cost,
        bool purchasedFromSecretShop,
        bool purchasedFromSideShop);

    // under-the-hood name of the item
    const std::string& getName() const { return name; }

    // item cost
    int getCost() const { return cost; }

    // item is purchased from secret shop
    bool isPurchasedFromSecretShop() const { return purchasedFromSecretShop; }

    // item is purchased from side shop
    bool isPurchasedFromSideShop() const { return purchasedFromSideShop; }
};

} /* namespace d2ai */
