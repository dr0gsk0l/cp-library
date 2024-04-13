---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/r2/XY.cpp
    title: library/r2/XY.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/geometry/Judge.cpp
    title: library/geometry/Judge.cpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/UtilFunction.cpp
    title: library/geometry/UtilFunction.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_4_A.test.cpp
    title: test/AOJ/CGL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/r2/XY.cpp\"\ntemplate <typename T> struct XY {\n\
    \    T x, y;\n    XY() = default;\n    XY(T x, T y) : x(x), y(y) {}\n    XY(const\
    \ std::pair<T, T> &xy) : x(xy.first), y(xy.second) {}\n\n    XY operator+() const\
    \ { return *this; }\n    XY operator-() const { return XY(-x, -y); }\n\n    XY\
    \ &operator++() {\n        x++;\n        y++;\n        return *this;\n    }\n\
    \    XY &operator--() {\n        x--;\n        y--;\n        return *this;\n \
    \   }\n    XY &operator++(int) {\n        XY a = *this;\n        ++*this;\n  \
    \      return a;\n    }\n    XY &operator--(int) {\n        XY a = *this;\n  \
    \      --*this;\n        return a;\n    }\n\n    XY &operator+=(const XY &v) {\n\
    \        x += v.x;\n        y += v.y;\n        return *this;\n    }\n    XY &operator-=(const\
    \ XY &v) {\n        x -= v.x;\n        y -= v.y;\n        return *this;\n    }\n\
    \    XY &operator*=(const T &a) {\n        x *= a;\n        y *= a;\n        return\
    \ *this;\n    }\n    XY &operator/=(const T &a) {\n        x /= a;\n        y\
    \ /= a;\n        return *this;\n    }\n\n    friend XY operator+(const XY &u,\
    \ const XY &v) { return XY(u) += v; }\n    friend XY operator-(const XY &u, const\
    \ XY &v) { return XY(u) -= v; }\n    friend XY operator*(const XY &u, const T\
    \ &a) { return XY(u) *= a; }\n    friend XY operator*(const T &a, const XY &u)\
    \ { return XY(u) *= a; }\n    friend XY operator/(const XY &u, const T &a) { return\
    \ XY(u) /= a; }\n\n    bool operator<(const XY &v) const { return x != v.x ? x\
    \ < v.x : y < v.y; }\n    bool operator>(const XY &v) const { return x != v.x\
    \ ? x > v.x : y > v.y; }\n    bool operator==(const XY &v) const { return x ==\
    \ v.x and y == v.y; }\n    bool operator!=(const XY &v) const { return !(*this\
    \ == v); }\n\n    double arg() const { return atan2(y, x); }\n\n    // [0,2pi)\
    \ \u3067 \u03B8(u)<\u03B8(v) \u306E\u6642 true\n    // (0,0) \u306F 2pi \u306B\
    \u76F8\u5F53\n    // static bool angle_cmp(const XY&u,const XY&v){\n    //  using\
    \ U=conditional_t< is_same_v<T,int>,long long,T>;\n    //  if(u==XY(0,0))return\
    \ false;\n    //  if(v==XY(0,0))return true;\n    //  if(u.y==0){\n    //    if(u.x>0)return\
    \ true;\n    //    if(v.y==0)return v.x<0;\n    //    return v.y<0;\n    //  }\n\
    \    //  if(u.y>0){\n    //    if(v.y==0)return v.x<0;\n    //    if(v.y<0)return\
    \ true;\n    //    return U(v.x)*u.y <= U(u.x)*v.y;\n    //  }\n    //  if(v.y>=0)return\
    \ false;\n    //  return U(v.x)*u.y <= U(u.x)*v.y;\n    //}\n\n    friend T dot(const\
    \ XY &u, const XY &v) { return u.x * v.x + u.y * v.y; }\n    T norm() { return\
    \ dot(*this, *this); }\n    T abs() { return sqrt(norm()); }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, XY &v) {\n        is >> v.x >> v.y;\n        return\
    \ is;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const XY &v)\
    \ {\n        os << v.x << \" \" << v.y;\n        return os;\n    }\n\n    static\
    \ XY direction(const char &c) {\n        if (c == 'R')\n            return {1,\
    \ 0};\n        if (c == 'L')\n            return {-1, 0};\n        if (c == 'U')\n\
    \            return {0, -1};\n        if (c == 'D')\n            return {0, 1};\n\
    \        return {0, 0};\n    }\n};\n#line 3 \"library/geometry/Base.cpp\"\nnamespace\
    \ geometry {\nconstexpr double EPS = 1e-10, PI = acos(-1);\n\nbool is_equal(double\
    \ a, double b) { return abs(a - b) < EPS; }\n\nusing Point = XY<double>;\nbool\
    \ cmp_y(const Point &p1, const Point &p2) {\n    return p1.y != p2.y ? p1.y <\
    \ p2.y : p1.x < p2.x;\n}\n\nusing Vector = Point;\nusing Polygon = std::vector<Point>;\n\
    \nstd::istream &operator>>(std::istream &is, Polygon &p) {\n    for (Point &c\
    \ : p)\n        is >> c;\n    return is;\n}\n\nstruct Segment {\n    Point p1,\
    \ p2;\n    Segment() {}\n    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}\n\
    \    friend std::istream &operator>>(std::istream &is, Segment &s) {\n       \
    \ is >> s.p1 >> s.p2;\n        return is;\n    }\n    double arg() const { return\
    \ (p2 - p1).arg(); }\n};\nusing Line = Segment;\n\nstruct Circle {\n    Point\
    \ c;\n    double r;\n    Circle() {}\n    Circle(Point c, double r) : c(c), r(r)\
    \ {}\n    friend std::istream &operator>>(std::istream &is, Circle &c) {\n   \
    \     is >> c.c >> c.r;\n        return is;\n    }\n};\n} // namespace geometry\n"
  code: "#pragma once\n#include \"library/r2/XY.cpp\"\nnamespace geometry {\nconstexpr\
    \ double EPS = 1e-10, PI = acos(-1);\n\nbool is_equal(double a, double b) { return\
    \ abs(a - b) < EPS; }\n\nusing Point = XY<double>;\nbool cmp_y(const Point &p1,\
    \ const Point &p2) {\n    return p1.y != p2.y ? p1.y < p2.y : p1.x < p2.x;\n}\n\
    \nusing Vector = Point;\nusing Polygon = std::vector<Point>;\n\nstd::istream &operator>>(std::istream\
    \ &is, Polygon &p) {\n    for (Point &c : p)\n        is >> c;\n    return is;\n\
    }\n\nstruct Segment {\n    Point p1, p2;\n    Segment() {}\n    Segment(Point\
    \ p1, Point p2) : p1(p1), p2(p2) {}\n    friend std::istream &operator>>(std::istream\
    \ &is, Segment &s) {\n        is >> s.p1 >> s.p2;\n        return is;\n    }\n\
    \    double arg() const { return (p2 - p1).arg(); }\n};\nusing Line = Segment;\n\
    \nstruct Circle {\n    Point c;\n    double r;\n    Circle() {}\n    Circle(Point\
    \ c, double r) : c(c), r(r) {}\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) {\n        is >> c.c >> c.r;\n        return is;\n    }\n};\n\
    } // namespace geometry"
  dependsOn:
  - library/r2/XY.cpp
  isVerificationFile: false
  path: library/geometry/Base.cpp
  requiredBy:
  - library/geometry/Judge.cpp
  - library/geometry/UtilFunction.cpp
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_4_A.test.cpp
documentation_of: library/geometry/Base.cpp
layout: document
redirect_from:
- /library/library/geometry/Base.cpp
- /library/library/geometry/Base.cpp.html
title: library/geometry/Base.cpp
---
