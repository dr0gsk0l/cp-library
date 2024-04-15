---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/r2/XY.cpp
    title: library/r2/XY.cpp
  - icon: ':question:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \        return {0, 0};\n    }\n};\n#line 2 \"library/util/Compress.cpp\"\ntemplate\
    \ <typename T, bool Sentinel = false> class Compress {\n    std::vector<T> v;\n\
    \    bool prepared;\n\n  public:\n    Compress() : prepared(false) {\n       \
    \ if constexpr (Sentinel) {\n            static_assert(std::numeric_limits<T>::is_specialized,\n\
    \                          \"cannot use Sentinel\");\n            v = {std::numeric_limits<T>::min(),\
    \ std::numeric_limits<T>::max()};\n        }\n    }\n    Compress(const std::vector<T>\
    \ &w) : v(w), prepared(false) {\n        if constexpr (Sentinel) {\n         \
    \   static_assert(std::numeric_limits<T>::is_specialized,\n                  \
    \        \"cannot use Sentinel\");\n            v.push_back(std::numeric_limits<T>::min());\n\
    \            v.push_back(std::numeric_limits<T>::max());\n        }\n        build();\n\
    \    }\n\n    void add(T a) {\n        assert(!prepared);\n        v.push_back(a);\n\
    \    }\n    void build() {\n        assert(!prepared);\n        prepared = true;\n\
    \        std::ranges::sort(v);\n        auto result = std::ranges::unique(v);\n\
    \        v.erase(result.begin(), result.end());\n    }\n\n    bool is_prepared()\
    \ const { return prepared; }\n\n    int operator[](const T &a) const {\n     \
    \   assert(prepared);\n        auto it = std::ranges::lower_bound(v, a);\n   \
    \     assert(*it == a);\n        return std::distance(v.begin(), it);\n    }\n\
    \    int geq(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ std::ranges::lower_bound(v, a);\n        return std::distance(v.begin(), it);\n\
    \    }\n    int gt(const T &a) const {\n        assert(prepared);\n        auto\
    \ it = std::ranges::upper_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    int leq(const T &a) const {\n        assert(prepared);\n  \
    \      auto it = --std::ranges::upper_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    int lt(const T &a) const {\n        assert(prepared);\n   \
    \     auto it = --std::ranges::lower_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    T r(int id) const {\n        assert(prepared);\n        return\
    \ v[id];\n    }\n    bool exist(const T &a) const {\n        assert(prepared);\n\
    \        return (*std::ranges::lower_bound(v, a)) == a;\n    }\n    int size()\
    \ const { return v.size(); }\n    T max() const { return v.back(); }\n    T min()\
    \ const { return v[0]; }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Compress &C) {\n        for (int i = 0; i < C.v.size(); i++)\n       \
    \     os << C.v[i] << \":\" << i << \" \";\n        return os;\n    }\n};\n#line\
    \ 4 \"library/r2/Projection.cpp\"\ntemplate <typename T> class Projection {\n\
    \    using r2 = XY<T>;\n    Compress<r2> C;\n\n  public:\n    Projection(const\
    \ std::vector<r2> &v) : C(v) {}\n    int size() { return C.size(); }\n    int\
    \ id(r2 xy) { return C[xy]; }\n    int id(int x, int y) { return C[r2(x, y)];\
    \ }\n    r2 r(int id) { return C.r(id); }\n    //[l,r) \u3092\u8FD4\u3059\n  \
    \  std::pair<int, int> interval(const T &l, const T &r) {\n        if (C.max().x\
    \ < l or r <= C.min().x)\n            return std::make_pair(0, 0);\n        T\
    \ mn = std::numeric_limits<T>::min();\n        int L = C.geq(r2(l, mn));\n   \
    \     int R = C.geq(r2(r, mn));\n        return std::make_pair(L, R);\n    }\n\
    };\n"
  code: "#pragma once\n#include \"library/r2/XY.cpp\"\n#include \"library/util/Compress.cpp\"\
    \ntemplate <typename T> class Projection {\n    using r2 = XY<T>;\n    Compress<r2>\
    \ C;\n\n  public:\n    Projection(const std::vector<r2> &v) : C(v) {}\n    int\
    \ size() { return C.size(); }\n    int id(r2 xy) { return C[xy]; }\n    int id(int\
    \ x, int y) { return C[r2(x, y)]; }\n    r2 r(int id) { return C.r(id); }\n  \
    \  //[l,r) \u3092\u8FD4\u3059\n    std::pair<int, int> interval(const T &l, const\
    \ T &r) {\n        if (C.max().x < l or r <= C.min().x)\n            return std::make_pair(0,\
    \ 0);\n        T mn = std::numeric_limits<T>::min();\n        int L = C.geq(r2(l,\
    \ mn));\n        int R = C.geq(r2(r, mn));\n        return std::make_pair(L, R);\n\
    \    }\n};\n"
  dependsOn:
  - library/r2/XY.cpp
  - library/util/Compress.cpp
  isVerificationFile: false
  path: library/r2/Projection.cpp
  requiredBy: []
  timestamp: '2024-04-15 11:27:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
documentation_of: library/r2/Projection.cpp
layout: document
redirect_from:
- /library/library/r2/Projection.cpp
- /library/library/r2/Projection.cpp.html
title: library/r2/Projection.cpp
---
