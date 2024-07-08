---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/r2/YX.hpp\"\ntemplate <typename T> struct YX {\n\
    \    T y, x;\n    YX() = default;\n    YX(T y, T x) : y(y), x(x) {}\n    YX(const\
    \ std::pair<T, T> &yx) : y(yx.first), x(yx.second) {}\n\n    YX operator+() const\
    \ { return *this; }\n    YX operator-() const { return YX(-y, -x); }\n\n    YX\
    \ &operator++() {\n        y++;\n        x++;\n        return *this;\n    }\n\
    \    YX &operator--() {\n        y--;\n        x--;\n        return *this;\n \
    \   }\n    YX &operator++(int) {\n        YX a = *this;\n        ++*this;\n  \
    \      return a;\n    }\n    YX &operator--(int) {\n        YX a = *this;\n  \
    \      --*this;\n        return a;\n    }\n\n    YX &operator+=(const YX &v) {\n\
    \        y += v.y;\n        x += v.x;\n        return *this;\n    }\n    YX &operator-=(const\
    \ YX &v) {\n        y -= v.y;\n        x -= v.x;\n        return *this;\n    }\n\
    \    YX &operator*=(const T &a) {\n        y *= a;\n        x *= a;\n        return\
    \ *this;\n    }\n    YX &operator/=(const T &a) {\n        y /= a;\n        x\
    \ /= a;\n        return *this;\n    }\n\n    friend YX operator+(const YX &u,\
    \ const YX &v) { return YX(u) += v; }\n    friend YX operator-(const YX &u, const\
    \ YX &v) { return YX(u) -= v; }\n    friend YX operator*(const YX &u, const T\
    \ &a) { return YX(u) *= a; }\n    friend YX operator*(const T &a, const YX &u)\
    \ { return YX(u) *= a; }\n    friend YX operator/(const YX &u, const T &a) { return\
    \ YX(u) /= a; }\n\n    bool operator<(const YX &v) const { return y != v.y ? y\
    \ < v.y : x < v.x; }\n    bool operator>(const YX &v) const { return y != v.y\
    \ ? y > v.y : x > v.x; }\n    bool operator==(const YX &v) const { return y ==\
    \ v.y and x == v.x; }\n    bool operator<=(const YX &v) const { return !(*this\
    \ > v); }\n    bool operator>=(const YX &v) const { return !(*this < v); }\n \
    \   bool operator!=(const YX &v) const { return !(*this == v); }\n\n    friend\
    \ T dot(const YX &u, const YX &v) { return u.y * v.y + u.x * v.x; }\n    T square_abs()\
    \ { return dot(*this, *this); }\n    T abs() { return sqrt(square_abs()); }\n\n\
    \    friend std::istream &operator>>(std::istream &is, YX &v) {\n        is >>\
    \ v.y >> v.x;\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const YX &v) {\n        os << v.y << \" \" << v.x;\n        return os;\n\
    \    }\n\n    static YX direction(const char &c) {\n        if (c == 'R')\n  \
    \          return {0, 1};\n        if (c == 'L')\n            return {0, -1};\n\
    \        if (c == 'U')\n            return {-1, 0};\n        if (c == 'D')\n \
    \           return {1, 0};\n        return {0, 0};\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T> struct YX {\n    T y, x;\n    YX() =\
    \ default;\n    YX(T y, T x) : y(y), x(x) {}\n    YX(const std::pair<T, T> &yx)\
    \ : y(yx.first), x(yx.second) {}\n\n    YX operator+() const { return *this; }\n\
    \    YX operator-() const { return YX(-y, -x); }\n\n    YX &operator++() {\n \
    \       y++;\n        x++;\n        return *this;\n    }\n    YX &operator--()\
    \ {\n        y--;\n        x--;\n        return *this;\n    }\n    YX &operator++(int)\
    \ {\n        YX a = *this;\n        ++*this;\n        return a;\n    }\n    YX\
    \ &operator--(int) {\n        YX a = *this;\n        --*this;\n        return\
    \ a;\n    }\n\n    YX &operator+=(const YX &v) {\n        y += v.y;\n        x\
    \ += v.x;\n        return *this;\n    }\n    YX &operator-=(const YX &v) {\n \
    \       y -= v.y;\n        x -= v.x;\n        return *this;\n    }\n    YX &operator*=(const\
    \ T &a) {\n        y *= a;\n        x *= a;\n        return *this;\n    }\n  \
    \  YX &operator/=(const T &a) {\n        y /= a;\n        x /= a;\n        return\
    \ *this;\n    }\n\n    friend YX operator+(const YX &u, const YX &v) { return\
    \ YX(u) += v; }\n    friend YX operator-(const YX &u, const YX &v) { return YX(u)\
    \ -= v; }\n    friend YX operator*(const YX &u, const T &a) { return YX(u) *=\
    \ a; }\n    friend YX operator*(const T &a, const YX &u) { return YX(u) *= a;\
    \ }\n    friend YX operator/(const YX &u, const T &a) { return YX(u) /= a; }\n\
    \n    bool operator<(const YX &v) const { return y != v.y ? y < v.y : x < v.x;\
    \ }\n    bool operator>(const YX &v) const { return y != v.y ? y > v.y : x > v.x;\
    \ }\n    bool operator==(const YX &v) const { return y == v.y and x == v.x; }\n\
    \    bool operator<=(const YX &v) const { return !(*this > v); }\n    bool operator>=(const\
    \ YX &v) const { return !(*this < v); }\n    bool operator!=(const YX &v) const\
    \ { return !(*this == v); }\n\n    friend T dot(const YX &u, const YX &v) { return\
    \ u.y * v.y + u.x * v.x; }\n    T square_abs() { return dot(*this, *this); }\n\
    \    T abs() { return sqrt(square_abs()); }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, YX &v) {\n        is >> v.y >> v.x;\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const YX &v) {\n        os << v.y\
    \ << \" \" << v.x;\n        return os;\n    }\n\n    static YX direction(const\
    \ char &c) {\n        if (c == 'R')\n            return {0, 1};\n        if (c\
    \ == 'L')\n            return {0, -1};\n        if (c == 'U')\n            return\
    \ {-1, 0};\n        if (c == 'D')\n            return {1, 0};\n        return\
    \ {0, 0};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/r2/YX.hpp
  requiredBy: []
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/r2/YX.hpp
layout: document
redirect_from:
- /library/library/r2/YX.hpp
- /library/library/r2/YX.hpp.html
title: library/r2/YX.hpp
---
