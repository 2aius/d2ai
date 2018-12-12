/*
 * THIS FILE IS AUTO-GENERATED - DO NOT EDIT
 */

#pragma once

#include <limits>

namespace d2ai {

// location vector
class Vector3d final {
private:

    double x;
    double y;
    double z;

public:

    static const Vector3d NOT_DECODED;

    explicit Vector3d(
        double x,
        double y,
        double z);

    // x coordinate
    double getX() const { return x; }

    // y coordinate
    double getY() const { return y; }

    // z coordinate
    double getZ() const { return z; }
};

} /* namespace d2ai */
