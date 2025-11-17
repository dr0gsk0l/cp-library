---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/formalpowerseries/Base.hpp
    title: library/formalpowerseries/Base.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/ComposeEXP.hpp
    title: library/formalpowerseries/ComposeEXP.hpp
  - icon: ':question:'
    path: library/formalpowerseries/DivMod.hpp
    title: library/formalpowerseries/DivMod.hpp
  - icon: ':x:'
    path: library/formalpowerseries/MultipointEvaluation.hpp
    title: library/formalpowerseries/MultipointEvaluation.hpp
  - icon: ':heavy_check_mark:'
    path: library/formalpowerseries/Prod.hpp
    title: library/formalpowerseries/Prod.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/RationalSum.hpp
    title: library/formalpowerseries/RationalSum.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/Sqrt.hpp
    title: library/formalpowerseries/Sqrt.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/composition.hpp
    title: library/formalpowerseries/functions/composition.hpp
  - icon: ':question:'
    path: library/formalpowerseries/functions/differential.hpp
    title: library/formalpowerseries/functions/differential.hpp
  - icon: ':question:'
    path: library/formalpowerseries/functions/exp.hpp
    title: library/formalpowerseries/functions/exp.hpp
  - icon: ':question:'
    path: library/formalpowerseries/functions/integral.hpp
    title: library/formalpowerseries/functions/integral.hpp
  - icon: ':question:'
    path: library/formalpowerseries/functions/log.hpp
    title: library/formalpowerseries/functions/log.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/pow.hpp
    title: library/formalpowerseries/functions/pow.hpp
  - icon: ':heavy_check_mark:'
    path: library/formalpowerseries/functions/taylor_shift.hpp
    title: library/formalpowerseries/functions/taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Base.hpp
    title: library/setpowerseries/Base.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Compose.hpp
    title: library/setpowerseries/Compose.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Polynomial/Composition.test.cpp
    title: test/library-checker/Polynomial/Composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
    title: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/Exp.test.cpp
    title: test/library-checker/Polynomial/Exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Inv.test.cpp
    title: test/library-checker/Polynomial/Inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Log.test.cpp
    title: test/library-checker/Polynomial/Log.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
    title: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/Pow.test.cpp
    title: test/library-checker/Polynomial/Pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
    title: test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/TaylorShift.test.cpp
    title: test/library-checker/Polynomial/TaylorShift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
    title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/Valarray.hpp\"\n#include <functional>\n#include\
    \ <ranges>\n#include <vector>\n\ntemplate <typename T> struct Valarray : std::vector<T>\
    \ {\n    using std::vector<T>::vector; // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u7D99\u627F\n    Valarray(const std::vector<T> &v) : std::vector<T>(v.begin(),\
    \ v.end()) {}\n\n  private:\n    template <typename Op>\n    Valarray &apply_inplace(const\
    \ Valarray &other, Op op) {\n        if (this->size() < other.size())\n      \
    \      this->resize(other.size(), T(0));\n\n        for (auto [a, b] : std::views::zip(*this,\
    \ other))\n            a = op(a, b);\n\n        return *this;\n    }\n\n  public:\n\
    \    Valarray &operator+=(const Valarray &other) {\n        return apply_inplace(other,\
    \ std::plus<>());\n    }\n    Valarray &operator-=(const Valarray &other) {\n\
    \        return apply_inplace(other, std::minus<>());\n    }\n    Valarray &operator*=(const\
    \ Valarray &other) {\n        return apply_inplace(other, std::multiplies<>());\n\
    \    }\n    Valarray &operator/=(const Valarray &other) {\n        return apply_inplace(other,\
    \ std::divides<>());\n    }\n\n    friend Valarray operator+(Valarray a, const\
    \ Valarray &b) { return a += b; }\n    friend Valarray operator-(Valarray a, const\
    \ Valarray &b) { return a -= b; }\n    friend Valarray operator*(Valarray a, const\
    \ Valarray &b) { return a *= b; }\n    friend Valarray operator/(Valarray a, const\
    \ Valarray &b) { return a /= b; }\n\n    Valarray operator-() const {\n      \
    \  Valarray g = *this;\n        for (T &a : g)\n            a = -a;\n        return\
    \ g;\n    }\n};\n"
  code: "#include <functional>\n#include <ranges>\n#include <vector>\n\ntemplate <typename\
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
    \        for (T &a : g)\n            a = -a;\n        return g;\n    }\n};"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/util/Valarray.hpp
  requiredBy:
  - library/formalpowerseries/DivMod.hpp
  - library/formalpowerseries/Sqrt.hpp
  - library/formalpowerseries/RationalSum.hpp
  - library/formalpowerseries/Base.hpp
  - library/formalpowerseries/Prod.hpp
  - library/formalpowerseries/MultipointEvaluation.hpp
  - library/formalpowerseries/functions/composition.hpp
  - library/formalpowerseries/functions/differential.hpp
  - library/formalpowerseries/functions/exp.hpp
  - library/formalpowerseries/functions/taylor_shift.hpp
  - library/formalpowerseries/functions/log.hpp
  - library/formalpowerseries/functions/pow.hpp
  - library/formalpowerseries/functions/integral.hpp
  - library/formalpowerseries/ComposeEXP.hpp
  - library/setpowerseries/Base.hpp
  - library/setpowerseries/Compose.hpp
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  - test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
  - test/library-checker/Polynomial/Log.test.cpp
  - test/library-checker/Polynomial/TaylorShift.test.cpp
  - test/library-checker/Polynomial/Exp.test.cpp
  - test/library-checker/Polynomial/Inv.test.cpp
  - test/library-checker/Polynomial/Pow.test.cpp
  - test/library-checker/Polynomial/MultipointEvaluation.test.cpp
  - test/library-checker/Polynomial/Composition.test.cpp
  - test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
documentation_of: library/util/Valarray.hpp
layout: document
redirect_from:
- /library/library/util/Valarray.hpp
- /library/library/util/Valarray.hpp.html
title: library/util/Valarray.hpp
---
