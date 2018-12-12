/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <string>
#include "d2ai_vector3d.h"

namespace d2ai {

// dropped item
class DroppedItem final {
private:

    int handleId;
    std::string name;
    Vector3d location;

public:

    static const DroppedItem NOT_DECODED;

    explicit DroppedItem(
        int handleId,
        const std::string& name,
        const Vector3d& location);

    // handle ID to the dropped item
    int getHandleId() const { return handleId; }

    // under-the-hood name of the item
    const std::string& getName() const { return name; }

    // location of the dropped item
    const Vector3d& getLocation() const { return location; }
};

} /* namespace d2ai */
