---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/Base.hpp
    title: library/geometry/Base.hpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/UtilFunction.hpp
    title: library/geometry/UtilFunction.hpp
  - icon: ':question:'
    path: library/r2/XY.hpp
    title: library/r2/XY.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"test/AOJ/CGL_4_A.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/r2/XY.hpp\"\ntemplate <typename\
    \ T> struct XY {\n    T x, y;\n    XY() = default;\n    XY(T x, T y) : x(x), y(y)\
    \ {}\n    XY(const std::pair<T, T> &xy) : x(xy.first), y(xy.second) {}\n\n   \
    \ XY operator+() const { return *this; }\n    XY operator-() const { return XY(-x,\
    \ -y); }\n\n    XY &operator++() {\n        x++;\n        y++;\n        return\
    \ *this;\n    }\n    XY &operator--() {\n        x--;\n        y--;\n        return\
    \ *this;\n    }\n    XY &operator++(int) {\n        XY a = *this;\n        ++*this;\n\
    \        return a;\n    }\n    XY &operator--(int) {\n        XY a = *this;\n\
    \        --*this;\n        return a;\n    }\n\n    XY &operator+=(const XY &v)\
    \ {\n        x += v.x;\n        y += v.y;\n        return *this;\n    }\n    XY\
    \ &operator-=(const XY &v) {\n        x -= v.x;\n        y -= v.y;\n        return\
    \ *this;\n    }\n    XY &operator*=(const T &a) {\n        x *= a;\n        y\
    \ *= a;\n        return *this;\n    }\n    XY &operator/=(const T &a) {\n    \
    \    x /= a;\n        y /= a;\n        return *this;\n    }\n\n    friend XY operator+(const\
    \ XY &u, const XY &v) { return XY(u) += v; }\n    friend XY operator-(const XY\
    \ &u, const XY &v) { return XY(u) -= v; }\n    friend XY operator*(const XY &u,\
    \ const T &a) { return XY(u) *= a; }\n    friend XY operator*(const T &a, const\
    \ XY &u) { return XY(u) *= a; }\n    friend XY operator/(const XY &u, const T\
    \ &a) { return XY(u) /= a; }\n\n    bool operator<(const XY &v) const { return\
    \ x != v.x ? x < v.x : y < v.y; }\n    bool operator>(const XY &v) const { return\
    \ x != v.x ? x > v.x : y > v.y; }\n    bool operator==(const XY &v) const { return\
    \ x == v.x and y == v.y; }\n    bool operator<=(const XY &v) const { return !(*this\
    \ > v); }\n    bool operator>=(const XY &v) const { return !(*this < v); }\n \
    \   bool operator!=(const XY &v) const { return !(*this == v); }\n\n    double\
    \ arg() const { return atan2(y, x); }\n\n    // [0,2pi) \u3067 \u03B8(u)<\u03B8\
    (v) \u306E\u6642 true\n    // (0,0) \u306F 2pi \u306B\u76F8\u5F53\n    // static\
    \ bool angle_cmp(const XY&u,const XY&v){\n    //  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T>;\n    //  if(u==XY(0,0))return false;\n    //  if(v==XY(0,0))return\
    \ true;\n    //  if(u.y==0){\n    //    if(u.x>0)return true;\n    //    if(v.y==0)return\
    \ v.x<0;\n    //    return v.y<0;\n    //  }\n    //  if(u.y>0){\n    //    if(v.y==0)return\
    \ v.x<0;\n    //    if(v.y<0)return true;\n    //    return U(v.x)*u.y <= U(u.x)*v.y;\n\
    \    //  }\n    //  if(v.y>=0)return false;\n    //  return U(v.x)*u.y <= U(u.x)*v.y;\n\
    \    //}\n\n    friend T dot(const XY &u, const XY &v) { return u.x * v.x + u.y\
    \ * v.y; }\n    T norm() { return dot(*this, *this); }\n    T abs() { return sqrt(norm());\
    \ }\n\n    friend std::istream &operator>>(std::istream &is, XY &v) {\n      \
    \  is >> v.x >> v.y;\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const XY &v) {\n        os << v.x << \" \" << v.y;\n        return os;\n\
    \    }\n\n    static XY direction(const char &c) {\n        if (c == 'R')\n  \
    \          return {1, 0};\n        if (c == 'L')\n            return {-1, 0};\n\
    \        if (c == 'U')\n            return {0, -1};\n        if (c == 'D')\n \
    \           return {0, 1};\n        return {0, 0};\n    }\n};\n#line 3 \"library/geometry/Base.hpp\"\
    \nnamespace geometry {\nconstexpr double EPS = 1e-10, PI = acos(-1);\n\nbool is_equal(double\
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
    \     is >> c.c >> c.r;\n        return is;\n    }\n};\n} // namespace geometry\n\
    #line 3 \"library/geometry/UtilFunction.hpp\"\nnamespace geometry {\ndouble cross(Vector\
    \ a, Vector b) {\n    // std::cerr << a <<\" \"<<b<<\":\"<<a.x*b.y-a.y*b.x<<endl;\n\
    \    return a.x * b.y - a.y * b.x;\n}\n\nPoint orth(Point p) { return Point(-p.y,\
    \ p.x); }\n\nPoint project(Segment s, Point p) {\n    Vector base = s.p2 - s.p1;\n\
    \    double r = dot(p - s.p1, base) / base.norm();\n    return s.p1 + base * r;\n\
    }\n\nPoint reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0;\
    \ }\n\nPolygon convex_hull(Polygon ps) {\n    int n = ps.size();\n    std::ranges::sort(ps,\
    \ cmp_y);\n    int k = 0;\n    Polygon qs(n * 2);\n    for (int i = 0; i < n;\
    \ i++) {\n        while (k > 1 and cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k -\
    \ 1]) < 0)\n            k--;\n        qs[k++] = ps[i];\n    }\n    for (int i\
    \ = n - 2, t = k; i >= 0; i--) {\n        while (k > t and cross(qs[k - 1] - qs[k\
    \ - 2], ps[i] - qs[k - 1]) < 0)\n            k--;\n        qs[k++] = ps[i];\n\
    \    }\n    qs.resize(k - 1);\n    return qs;\n}\n} // namespace geometry\n#line\
    \ 6 \"test/AOJ/CGL_4_A.test.cpp\"\nusing namespace geometry;\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n;\n    std::cin >> n;\n    Polygon P(n);\n    std::cin >> P;\n\n    Polygon\
    \ Q = convex_hull(P);\n    std::cout << Q.size() << \"\\n\";\n    for (const Point\
    \ &p : Q)\n        std::cout << p << \"\\n\";\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/geometry/UtilFunction.hpp\"\n\
    using namespace geometry;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    Polygon P(n);\n\
    \    std::cin >> P;\n\n    Polygon Q = convex_hull(P);\n    std::cout << Q.size()\
    \ << \"\\n\";\n    for (const Point &p : Q)\n        std::cout << p << \"\\n\"\
    ;\n}"
  dependsOn:
  - library/geometry/UtilFunction.hpp
  - library/geometry/Base.hpp
  - library/r2/XY.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 20:16:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_A.test.cpp
- /verify/test/AOJ/CGL_4_A.test.cpp.html
title: test/AOJ/CGL_4_A.test.cpp
---
