---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/linearalgebra/Linear.hpp
    title: library/linearalgebra/Linear.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AffineSum.hpp
    title: library/algebra/lazy/AffineSum.hpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/Linear.hpp\"\ntemplate <typename T>\
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
    \ << -l.b;\n        return os;\n    }\n};\n#line 3 \"library/algebra/group/Affine.hpp\"\
    \ntemplate <typename T> struct GroupAffine {\n    using L = Line<T>;\n    using\
    \ value_type = L;\n    static constexpr L op(const L &f, const L &g) noexcept\
    \ { return f(g); }\n    static constexpr void Rchop(L &f, const L &g) {\n    \
    \    f.b += f.a * g.b;\n        f.a *= g.a;\n    }\n    static constexpr void\
    \ Lchop(const L &f, L &g) {\n        (g.b *= f.a) += f.b;\n        g.a *= f.a;\n\
    \    }\n    static constexpr L inverse(const L &f) { return f.inv(); }\n    /*\n\
    \    static constexpr L power(const L& f,long long n) noexcept {\n      if(a==1)return\
    \ {1,n*b};\n      K an=power(a,n);\n      return {an,b*((1-an)/(1-a))};\n    }\n\
    \    */\n    static constexpr L unit() { return L(1, 0); }\n    static constexpr\
    \ bool commute = false;\n};\n"
  code: "#pragma once\n#include \"library/linearalgebra/Linear.hpp\"\ntemplate <typename\
    \ T> struct GroupAffine {\n    using L = Line<T>;\n    using value_type = L;\n\
    \    static constexpr L op(const L &f, const L &g) noexcept { return f(g); }\n\
    \    static constexpr void Rchop(L &f, const L &g) {\n        f.b += f.a * g.b;\n\
    \        f.a *= g.a;\n    }\n    static constexpr void Lchop(const L &f, L &g)\
    \ {\n        (g.b *= f.a) += f.b;\n        g.a *= f.a;\n    }\n    static constexpr\
    \ L inverse(const L &f) { return f.inv(); }\n    /*\n    static constexpr L power(const\
    \ L& f,long long n) noexcept {\n      if(a==1)return {1,n*b};\n      K an=power(a,n);\n\
    \      return {an,b*((1-an)/(1-a))};\n    }\n    */\n    static constexpr L unit()\
    \ { return L(1, 0); }\n    static constexpr bool commute = false;\n};"
  dependsOn:
  - library/linearalgebra/Linear.hpp
  isVerificationFile: false
  path: library/algebra/group/Affine.hpp
  requiredBy:
  - library/algebra/lazy/AffineSum.hpp
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
documentation_of: library/algebra/group/Affine.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Affine.hpp
- /library/library/algebra/group/Affine.hpp.html
title: library/algebra/group/Affine.hpp
---
