/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#include "d2ai_dropped_item.h"

namespace d2ai {

const DroppedItem DroppedItem::NOT_DECODED{
    0,
    "",
    Vector3d::NOT_DECODED
};

DroppedItem::DroppedItem(
        int handleId,
        const std::string& name,
        const Vector3d& location)
    : handleId(handleId),
      name(name),
      location(location) {
}

} /* namespace d2ai */
