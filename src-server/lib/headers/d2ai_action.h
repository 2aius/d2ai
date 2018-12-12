#pragma once

#include <string>
#include <vector>
#include "d2ai_vector3d.h"

namespace d2ai {

enum ActionType {
    ACTION_NONE = 0,
    // non-immediate actions
    ACTION_CLEAR_ACTIONS = 1,
    ACTION_MOVE_PATHFINDER = 2,
    ACTION_MOVE_DIRECTLY = 3,
    ACTION_MOVE_PATH = 4,
    ACTION_MOVE_TO_UNIT = 5,
    ACTION_ATTACK_UNIT = 6,
    ACTION_ATTACK_MOVE = 7,
    ACTION_USE_ABILITY = 8,
    ACTION_USE_ABILITY_ON_UNIT = 9,
    ACTION_USE_ABILITY_ON_LOCATION = 10,
    ACTION_USE_ABILITY_ON_TREE = 11,
    ACTION_USE_ITEM = 12,
    ACTION_USE_ITEM_ON_UNIT = 13,
    ACTION_USE_ITEM_ON_LOCATION = 14,
    ACTION_USE_ITEM_ON_TREE = 15,
    ACTION_PICK_UP_RUNE = 16,
    ACTION_PICK_UP_ITEM = 17,
    ACTION_DROP_ITEM = 18,
    ACTION_USE_SHRINE = 19,
    ACTION_DELAY = 20,
    // immediate actions
    ACTION_PURCHASE_ITEM = 21,
    ACTION_SELL_ITEM = 22,
    ACTION_DISASSEMBLE_ITEM = 23,
    ACTION_SET_ITEM_COMBINE_LOCK = 24,
    ACTION_SWAP_ITEMS = 25,
    ACTION_COURIER = 26,
    ACTION_BUYBACK = 27,
    ACTION_GLYPH = 28,
    ACTION_LEVEL_ABILITY = 29,
    ACTION_CHAT = 30,
    // debug immediate action
    ACTION_DEBUG_DRAW_LINE = 90,
    ACTION_DEBUG_DRAW_CIRCLE = 91,
    ACTION_DEBUG_DRAW_TEXT = 92
};

class Action final {
private:

    ActionType type;
    std::vector<std::string> args;

    explicit Action(ActionType type,
            const std::vector<std::string>& args);

public:

    ActionType getType() const { return type; }
    const std::vector<std::string>& getArgs() const { return args; }

    // do not command any action
    static Action none();

    /*
     * non-immediate actions
     */

    // return to idle and optionally stop in place
    static Action clearActions(bool stop);

    // move to the specified location, this is not a precision move
    static Action movePathfinder(const Vector3d& location);

    // move to the specified location, bypassing the bot pathfinder (= user right-click)
    static Action moveDirectly(const Vector3d& location);

    // move along the specified path (API bug: only works with 2 locations)
    static Action movePath(const std::vector<Vector3d>& locations);

    // move to the specified unit, this will continue to follow the unit
    static Action moveToUnit(int handleId);

    // attack a unit with an option to stop after one attack
    static Action attackUnit(int handleId, bool stop);

    // attack-move a location
    static Action attackMove(const Vector3d& location);

    // use ability
    static Action useAbility(int slot);

    // use ability on unit
    static Action useAbilityOnUnit(int slot, int handleId);

    // use ability on location
    static Action useAbilityOnLocation(int slot, const Vector3d& location);

    // use ability on tree
    static Action useAbilityOnTree(int slot, int treeId);

    // use item
    static Action useItem(int slot);

    // use item on unit
    static Action useItemOnUnit(int slot, int handleId);

    // use item on location
    static Action useItemOnLocation(int slot, const Vector3d& location);

    // use item on tree
    static Action useItemOnTree(int slot, int treeId);

    // pick up rune
    static Action pickUpRune(int nRune);

    // pick up dropped item
    static Action pickUpItem(int handleId);

    // drop item to the specified location
    static Action dropItem(int slot, const Vector3d& location);

    // use shrine
    static Action useShrine(int handleId);

    // delay for the specified amount of time
    static Action delay(double time);

    /*
     * immediate actions
     */

    // purchase the specified item
    static Action purchaseItem(const std::string& name);

    // sell the specified item
    static Action sellItem(int slot);

    // disassemble the specified item
    static Action disassembleItem(int slot);

    // lock or unlock combining of the specified item
    static Action setItemCombineLock(int slot, bool locked);

    // swap items in slot1 and slot2
    static Action swapItems(int slot1, int slot2);

    // command courier (zero based index) to perform action (enum)
    static Action commandCourier(int nCourier, int nAction);

    // buy back from death
    static Action buyback();

    // use Glyph
    static Action useGlyph();

    // level the specified ability
    static Action levelAbility(const std::string& name);

    // say something in team chat, toAll true to say to all chat instead
    static Action chat(const std::string& message, bool toAll);

    /*
     * debug actions (immediate)
     */

    // draw line from start to end in specified color for 1 frame
    static Action debugDrawLine(const Vector3d& start, const Vector3d& end,
            int red, int green, int blue);

    // draw circle at center with radius in specified color for 1 frame
    static Action debugDrawCircle(const Vector3d& center, double radius,
            int red, int green, int blue);

    //  draw specified text at (x,y) on screen in specified color for 1 frame
    static Action debugDrawText(double x, double y, const std::string& text,
            int red, int green, int blue);
};

} /* namespace d2ai */
