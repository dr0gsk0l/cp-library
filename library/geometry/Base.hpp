#pragma once
#include "library/r2/XY.hpp"
namespace geometry {
constexpr double EPS = 1e-10, PI = acos(-1);

bool is_equal(double a, double b) { return abs(a - b) < EPS; }

using Point = XY<double>;
bool cmp_y(const Point &p1, const Point &p2) {
    return p1.y != p2.y ? p1.y < p2.y : p1.x < p2.x;
}

using Vector = Point;
using Polygon = std::vector<Point>;

std::istream &operator>>(std::istream &is, Polygon &p) {
    for (Point &c : p)
        is >> c;
    return is;
}

struct Segment {
    Point p1, p2;
    Segment() {}
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
    friend std::istream &operator>>(std::istream &is, Segment &s) {
        is >> s.p1 >> s.p2;
        return is;
    }
    double arg() const { return (p2 - p1).arg(); }
};
using Line = Segment;

struct Circle {
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r) : c(c), r(r) {}
    friend std::istream &operator>>(std::istream &is, Circle &c) {
        is >> c.c >> c.r;
        return is;
    }
};
} // namespace geometry