---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AffineSum.cpp
    title: library/algebra/lazy/AffineSum.cpp
  - icon: ':x:'
    path: library/linearalgebra/ConvexHullTrick.cpp
    title: library/linearalgebra/ConvexHullTrick.cpp
  - icon: ':warning:'
    path: library/linearalgebra/InsertConvexHullTrick.cpp
    title: library/linearalgebra/InsertConvexHullTrick.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2012.test.cpp
    title: test/yukicoder/2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/Linear.cpp\"\ntemplate <typename T>\
    \ struct Line {\n    T a, b;\n    Line() = default;\n    Line(T a, T b) : a(a),\
    \ b(b) {}\n    Line(std::pair<T, T> l) : a(l.first), b(l.second) {}\n    Line(T\
    \ c) : a(0), b(c) {}\n\n    T operator()(const T x) const { return a * x + b;\
    \ }\n    Line operator()(const Line &l) const { return Line(a * l.a, a * l.b +\
    \ b); }\n\n    bool operator==(const Line &l) const { return a == l.a and b ==\
    \ l.b; }\n    bool operator!=(const Line &l) const { return !(*this == l); }\n\
    \    bool operator<(const Line &l) const {\n        return (a == l.a ? a < l.a\
    \ : b < l.b);\n    }\n\n    Line &operator+=(const Line &l) {\n        a += l.a;\n\
    \        b += l.b;\n        return *this;\n    }\n    Line operator+(const Line\
    \ &l) const { return Line(*this) += l; }\n    Line &operator-=(const Line &l)\
    \ {\n        a -= l.a;\n        b -= l.b;\n        return *this;\n    }\n    Line\
    \ operator-(const Line &l) const { return Line(*this) -= l; }\n    Line operator-()\
    \ const { return Line(-a, -b); }\n\n    Line &operator+=(const T &c) {\n     \
    \   b += c;\n        return *this;\n    }\n    Line operator+(const T &c) const\
    \ { return Line(*this) += c; }\n    Line &operator-=(const T &c) {\n        b\
    \ -= c;\n        return *this;\n    }\n    Line operator-(const T &c) const {\
    \ return Line(*this) -= c; }\n    Line &operator*=(const T &c) {\n        a *=\
    \ c;\n        b *= c;\n        return *this;\n    }\n    Line operator*(const\
    \ T &c) const { return Line(*this) *= c; }\n    Line &operator/=(const T &c) {\n\
    \        a /= c;\n        b /= c;\n        return *this;\n    }\n    Line operator/(const\
    \ T &c) const { return Line(*this) /= c; }\n\n    Line inv() const {\n       \
    \ assert(a != 0);\n        return Line(T(1) / a, -b / a);\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &l) {\n        is >> l.a >>\
    \ l.b;\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &l) {\n        if (l.a == 0 and l.b == 0)\n            os <<\
    \ 0;\n        else if (l.a == 0)\n            os << l.b;\n        else if (l.b\
    \ == 0)\n            os << l.a << \"x\";\n        else if (l.b > 0)\n        \
    \    os << l.a << \"x+\" << l.b;\n        else\n            os << l.a << \"x-\"\
    \ << -l.b;\n        return os;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T> struct Line {\n    T a, b;\n    Line()\
    \ = default;\n    Line(T a, T b) : a(a), b(b) {}\n    Line(std::pair<T, T> l)\
    \ : a(l.first), b(l.second) {}\n    Line(T c) : a(0), b(c) {}\n\n    T operator()(const\
    \ T x) const { return a * x + b; }\n    Line operator()(const Line &l) const {\
    \ return Line(a * l.a, a * l.b + b); }\n\n    bool operator==(const Line &l) const\
    \ { return a == l.a and b == l.b; }\n    bool operator!=(const Line &l) const\
    \ { return !(*this == l); }\n    bool operator<(const Line &l) const {\n     \
    \   return (a == l.a ? a < l.a : b < l.b);\n    }\n\n    Line &operator+=(const\
    \ Line &l) {\n        a += l.a;\n        b += l.b;\n        return *this;\n  \
    \  }\n    Line operator+(const Line &l) const { return Line(*this) += l; }\n \
    \   Line &operator-=(const Line &l) {\n        a -= l.a;\n        b -= l.b;\n\
    \        return *this;\n    }\n    Line operator-(const Line &l) const { return\
    \ Line(*this) -= l; }\n    Line operator-() const { return Line(-a, -b); }\n\n\
    \    Line &operator+=(const T &c) {\n        b += c;\n        return *this;\n\
    \    }\n    Line operator+(const T &c) const { return Line(*this) += c; }\n  \
    \  Line &operator-=(const T &c) {\n        b -= c;\n        return *this;\n  \
    \  }\n    Line operator-(const T &c) const { return Line(*this) -= c; }\n    Line\
    \ &operator*=(const T &c) {\n        a *= c;\n        b *= c;\n        return\
    \ *this;\n    }\n    Line operator*(const T &c) const { return Line(*this) *=\
    \ c; }\n    Line &operator/=(const T &c) {\n        a /= c;\n        b /= c;\n\
    \        return *this;\n    }\n    Line operator/(const T &c) const { return Line(*this)\
    \ /= c; }\n\n    Line inv() const {\n        assert(a != 0);\n        return Line(T(1)\
    \ / a, -b / a);\n    }\n\n    friend std::istream &operator>>(std::istream &is,\
    \ Line &l) {\n        is >> l.a >> l.b;\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Line &l) {\n        if (l.a\
    \ == 0 and l.b == 0)\n            os << 0;\n        else if (l.a == 0)\n     \
    \       os << l.b;\n        else if (l.b == 0)\n            os << l.a << \"x\"\
    ;\n        else if (l.b > 0)\n            os << l.a << \"x+\" << l.b;\n      \
    \  else\n            os << l.a << \"x-\" << -l.b;\n        return os;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/Linear.cpp
  requiredBy:
  - library/algebra/lazy/AffineSum.cpp
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/InsertConvexHullTrick.cpp
  - library/linearalgebra/ConvexHullTrick.cpp
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/yukicoder/2012.test.cpp
documentation_of: library/linearalgebra/Linear.cpp
layout: document
redirect_from:
- /library/library/linearalgebra/Linear.cpp
- /library/library/linearalgebra/Linear.cpp.html
title: library/linearalgebra/Linear.cpp
---