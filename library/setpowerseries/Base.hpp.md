---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Ranked.hpp
    title: library/bitwise/Ranked.hpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.hpp
    title: library/bitwise/Util.hpp
  - icon: ':question:'
    path: library/util/Valarray.hpp
    title: library/util/Valarray.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Compose.hpp
    title: library/setpowerseries/Compose.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
    title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.hpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/Ranked.hpp\"\n#define REP_(i, n) for (int i = 0; i < (n);\
    \ i++)\n#define RREP_(i, n) for (int i = (n) - 1; i >= 0; i--)\nclass BitwiseRanked\
    \ {\n    static int popcount(int S) { return __builtin_popcount(S); }\n\n  public:\n\
    \    template <typename T>\n    static std::vector<std::vector<T>> zeta(const\
    \ std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n     \
    \   std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));\n      \
    \  REP_(S, 1 << n) RA[S][popcount(S)] = A[S];\n        REP_(i, n)\n        REP_(S,\
    \ 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n + 1) RA[S |\
    \ (1 << i)][d] += RA[S][d];\n        return RA;\n    }\n    template <typename\
    \ T>\n    static std::vector<T> mobius(std::vector<std::vector<T>> RA) {\n   \
    \     const int n = bitwise::log2(RA.size());\n        REP_(i, n)\n        REP_(S,\
    \ 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n + 1) RA[S |\
    \ (1 << i)][d] -= RA[S][d];\n        std::vector<T> A(1 << n);\n        REP_(S,\
    \ 1 << n) A[S] = RA[S][popcount(S)];\n        return A;\n    }\n    template <typename\
    \ T>\n    static std::vector<T> convolution(const std::vector<T> &A,\n       \
    \                               const std::vector<T> &B) {\n        const int\
    \ n = bitwise::log2(A.size());\n        auto RA = zeta(A);\n        auto RB =\
    \ zeta(B);\n        REP_(S, 1 << n) {\n            auto &ra = RA[S], rb = RB[S];\n\
    \            RREP_(d, n + 1) {\n                ra[d] *= rb[0];\n            \
    \    REP_(i, d) ra[d] += ra[i] * rb[d - i];\n            }\n        }\n      \
    \  return mobius(RA);\n    }\n};\n#undef REP_\n#undef RREP_\n#line 1 \"library/util/Valarray.hpp\"\
    \n#include <functional>\n#include <ranges>\n#include <vector>\n\ntemplate <typename\
    \ T> struct Valarray : std::vector<T> {\n    using std::vector<T>::vector; //\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u7D99\u627F\n    Valarray(const std::vector<T>\
    \ &v) : std::vector<T>(v.begin(), v.end()) {}\n\n  private:\n    template <typename\
    \ Op>\n    Valarray &apply_inplace(const Valarray &other, Op op) {\n        if\
    \ (this->size() < other.size())\n            this->resize(other.size(), T(0));\n\
    \n        for (auto [a, b] : std::views::zip(*this, other))\n            a = op(a,\
    \ b);\n\n        return *this;\n    }\n\n  public:\n    Valarray &operator+=(const\
    \ Valarray &other) {\n        return apply_inplace(other, std::plus<>());\n  \
    \  }\n    Valarray &operator-=(const Valarray &other) {\n        return apply_inplace(other,\
    \ std::minus<>());\n    }\n    Valarray &operator*=(const Valarray &other) {\n\
    \        return apply_inplace(other, std::multiplies<>());\n    }\n    Valarray\
    \ &operator/=(const Valarray &other) {\n        return apply_inplace(other, std::divides<>());\n\
    \    }\n\n    friend Valarray operator+(Valarray a, const Valarray &b) { return\
    \ a += b; }\n    friend Valarray operator-(Valarray a, const Valarray &b) { return\
    \ a -= b; }\n    friend Valarray operator*(Valarray a, const Valarray &b) { return\
    \ a *= b; }\n    friend Valarray operator/(Valarray a, const Valarray &b) { return\
    \ a /= b; }\n\n    Valarray operator-() const {\n        Valarray g = *this;\n\
    \        for (T &a : g)\n            a = -a;\n        return g;\n    }\n};\n#line\
    \ 4 \"library/setpowerseries/Base.hpp\"\n\ntemplate <typename T> struct SetPowerSeries\
    \ : Valarray<T> {\n    using SPS = SetPowerSeries;\n    using Valarray<T>::Valarray;\n\
    \    using Valarray<T>::size;\n    using Valarray<T>::at;\n    using value_type\
    \ = T;\n\n    SetPowerSeries(const std::vector<T> &f) : Valarray<T>(f) {}\n\n\
    \    SPS operator-() const { return SPS(Valarray<T>::operator-()); }\n    SPS\
    \ operator*(const SPS &b) const {\n        return SPS(BitwiseRanked::convolution<T>(*this,\
    \ b));\n    }\n    SPS &operator*=(const SPS &b) { return (*this) = (*this) *\
    \ b; }\n};\n"
  code: "#pragma once\n#include \"library/bitwise/Ranked.hpp\"\n#include \"library/util/Valarray.hpp\"\
    \n\ntemplate <typename T> struct SetPowerSeries : Valarray<T> {\n    using SPS\
    \ = SetPowerSeries;\n    using Valarray<T>::Valarray;\n    using Valarray<T>::size;\n\
    \    using Valarray<T>::at;\n    using value_type = T;\n\n    SetPowerSeries(const\
    \ std::vector<T> &f) : Valarray<T>(f) {}\n\n    SPS operator-() const { return\
    \ SPS(Valarray<T>::operator-()); }\n    SPS operator*(const SPS &b) const {\n\
    \        return SPS(BitwiseRanked::convolution<T>(*this, b));\n    }\n    SPS\
    \ &operator*=(const SPS &b) { return (*this) = (*this) * b; }\n};\n"
  dependsOn:
  - library/bitwise/Ranked.hpp
  - library/bitwise/Util.hpp
  - library/util/Valarray.hpp
  isVerificationFile: false
  path: library/setpowerseries/Base.hpp
  requiredBy:
  - library/setpowerseries/Compose.hpp
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
documentation_of: library/setpowerseries/Base.hpp
layout: document
redirect_from:
- /library/library/setpowerseries/Base.hpp
- /library/library/setpowerseries/Base.hpp.html
title: library/setpowerseries/Base.hpp
---
