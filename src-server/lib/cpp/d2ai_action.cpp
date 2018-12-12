#include "d2ai_action.h"

namespace d2ai {

Action::Action(ActionType type,
        const std::vector<std::string>& args)
: type(type), args(args) {
}

Action Action::none() {
    std::vector<std::string> args;
    return Action{ACTION_NONE, args};
}

Action Action::clearActions(bool stop) {
    std::vector<std::string> args{(stop ? "1" : "0")};
    return Action{ACTION_CLEAR_ACTIONS, args};;
}

Action Action::movePathfinder(const Vector3d& location) {
    std::vector<std::string> args{std::to_string(location.getX()),
        std::to_string(location.getY()), std::to_string(location.getZ())};
    return Action{ACTION_MOVE_PATHFINDER, args};
}

Action Action::moveDirectly(const Vector3d& location) {
    std::vector<std::string> args{std::to_string(location.getX()),
        std::to_string(location.getY()), std::to_string(location.getZ())};
    return Action{ACTION_MOVE_DIRECTLY, args};
}

Action Action::movePath(const std::vector<Vector3d>& locations) {
    if (locations.empty()) return Action::none();
    std::vector<std::string> args;
    args.push_back(std::to_string(locations.size()));
    for (auto const& loc : locations) {
        args.push_back(std::to_string(loc.getX()));
        args.push_back(std::to_string(loc.getY()));
        args.push_back(std::to_string(loc.getZ()));
    }
    return Action{ACTION_MOVE_PATH, args};
}

Action Action::moveToUnit(int handleId) {
    std::vector<std::string> args{std::to_string(handleId)};
    return Action{ACTION_MOVE_TO_UNIT, args};
}

Action Action::attackUnit(int handleId, bool stop) {
    std::vector<std::string> args{std::to_string(handleId), (stop ? "1" : "0")};
    return Action{ACTION_ATTACK_UNIT, args};
}

Action Action::attackMove(const Vector3d& location) {
    std::vector<std::string> args{std::to_string(location.getX()),
        std::to_string(location.getY()), std::to_string(location.getZ())};
    return Action{ACTION_ATTACK_MOVE, args};
}

Action Action::useAbility(int slot) {
    std::vector<std::string> args{std::to_string(slot)};
    return Action{ACTION_USE_ABILITY, args};
}

Action Action::useAbilityOnUnit(int slot, int handleId) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(handleId)};
    return Action{ACTION_USE_ABILITY_ON_UNIT, args};
}

Action Action::useAbilityOnLocation(int slot, const Vector3d& location) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(location.getX()),
        std::to_string(location.getY()), std::to_string(location.getZ())};
    return Action{ACTION_USE_ABILITY_ON_LOCATION, args};
}

Action Action::useAbilityOnTree(int slot, int treeId) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(treeId)};
    return Action{ACTION_USE_ABILITY_ON_TREE, args};
}

Action Action::useItem(int slot) {
    std::vector<std::string> args{std::to_string(slot)};
    return Action{ACTION_USE_ITEM, args};
}

Action Action::useItemOnUnit(int slot, int handleId) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(handleId)};
    return Action{ACTION_USE_ITEM_ON_UNIT, args};
}

Action Action::useItemOnLocation(int slot, const Vector3d& location) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(location.getX()),
        std::to_string(location.getY()), std::to_string(location.getZ())};
    return Action{ACTION_USE_ITEM_ON_LOCATION, args};
}

Action Action::useItemOnTree(int slot, int treeId) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(treeId)};
    return Action{ACTION_USE_ITEM_ON_TREE, args};
}

Action Action::pickUpRune(int nRune) {
    std::vector<std::string> args{std::to_string(nRune)};
    return Action{ACTION_PICK_UP_RUNE, args};
}

Action Action::pickUpItem(int handleId) {
    std::vector<std::string> args{std::to_string(handleId)};
    return Action{ACTION_PICK_UP_ITEM, args};
}

Action Action::dropItem(int slot, const Vector3d& location) {
    std::vector<std::string> args{std::to_string(slot), std::to_string(location.getX()),
        std::to_string(location.getY()), std::to_string(location.getZ())};
    return Action{ACTION_DROP_ITEM, args};
}

Action Action::useShrine(int handleId) {
    std::vector<std::string> args{std::to_string(handleId)};
    return Action{ACTION_USE_SHRINE, args};
}

Action Action::delay(double time) {
    std::vector<std::string> args{std::to_string(time)};
    return Action{ACTION_DELAY, args};
}

Action Action::purchaseItem(const std::string& name) {
    std::vector<std::string> args{name};
    return Action{ACTION_PURCHASE_ITEM, args};
}

Action Action::sellItem(int slot) {
    std::vector<std::string> args{std::to_string(slot)};
    return Action{ACTION_SELL_ITEM, args};
}

Action Action::disassembleItem(int slot) {
    std::vector<std::string> args{std::to_string(slot)};
    return Action{ACTION_DISASSEMBLE_ITEM, args};
}

Action Action::setItemCombineLock(int slot, bool locked) {
    std::vector<std::string> args{std::to_string(slot), (locked ? "1" : "0")};
    return Action{ACTION_SET_ITEM_COMBINE_LOCK, args};
}

Action Action::swapItems(int slot1, int slot2) {
    std::vector<std::string> args{std::to_string(slot1), std::to_string(slot2)};
    return Action{ACTION_SWAP_ITEMS, args};
}

Action Action::commandCourier(int nCourier, int nAction) {
    std::vector<std::string> args{std::to_string(nCourier), std::to_string(nAction)};
    return Action{ACTION_COURIER, args};
}

Action Action::buyback() {
    std::vector<std::string> args{};
    return Action{ACTION_BUYBACK, args};
}

Action Action::useGlyph() {
    std::vector<std::string> args{};
    return Action{ACTION_GLYPH, args};
}

Action Action::levelAbility(const std::string& name) {
    std::vector<std::string> args{name};
    return Action{ACTION_LEVEL_ABILITY, args};
}

Action Action::chat(const std::string& message, bool toAll) {
    std::vector<std::string> args{message, (toAll ? "1" : "0")};
    return Action{ACTION_CHAT, args};
}

Action Action::debugDrawLine(const Vector3d& start, const Vector3d& end,
        int red, int green, int blue) {
    std::vector<std::string> args{std::to_string(start.getX()),
        std::to_string(start.getY()), std::to_string(start.getZ()),
        std::to_string(end.getX()), std::to_string(end.getY()),
        std::to_string(end.getZ()), std::to_string(red),
        std::to_string(green), std::to_string(blue)};
    return Action{ACTION_DEBUG_DRAW_LINE, args};
}

Action Action::debugDrawCircle(const Vector3d& center, double radius,
        int red, int green, int blue){
    std::vector<std::string> args{std::to_string(center.getX()),
        std::to_string(center.getY()), std::to_string(center.getZ()),
        std::to_string(radius), std::to_string(red), std::to_string(green),
        std::to_string(blue)};
    return Action{ACTION_DEBUG_DRAW_CIRCLE, args};
}

Action Action::debugDrawText(double x, double y, const std::string& text,
        int red, int green, int blue) {
    std::vector<std::string> args{std::to_string(x), std::to_string(y),
        text, std::to_string(red), std::to_string(green), std::to_string(blue)};
    return Action{ACTION_DEBUG_DRAW_TEXT, args};
}

} /* namespace d2ai */
