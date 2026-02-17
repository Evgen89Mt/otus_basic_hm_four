#pragma once
#include <string>

namespace motivation {
    // declaration
    struct Point;

    std::string toString(const Point& point);

    struct Point {
        int x;
        int y;
    };
} // namespace motivation

namespace methods {
    class Point {
    public:
        int x;
        int y;

        std::string toString() const;
    };
} // namespace methods
