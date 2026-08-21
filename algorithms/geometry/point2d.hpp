#pragma once
#include <cmath>
#include <iostream>

template <typename T = double>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(T scalar) const { return Point(x * scalar, y * scalar); }
    
    T dot(const Point& o) const { return x * o.x + y * o.y; }
    T cross(const Point& o) const { return x * o.y - y * o.x; }
    T norm_sq() const { return x * x + y * y; }
    double dist() const { return std::sqrt(norm_sq()); }

    bool operator<(const Point& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};
