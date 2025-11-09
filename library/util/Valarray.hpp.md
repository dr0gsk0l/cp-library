---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/formalpowerseries/Base.hpp
    title: library/formalpowerseries/Base.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/ComposeEXP.hpp
    title: library/formalpowerseries/ComposeEXP.hpp
  - icon: ':x:'
    path: library/formalpowerseries/DivMod.hpp
    title: library/formalpowerseries/DivMod.hpp
  - icon: ':x:'
    path: library/formalpowerseries/MultipointEvaluation.hpp
    title: library/formalpowerseries/MultipointEvaluation.hpp
  - icon: ':x:'
    path: library/formalpowerseries/Prod.hpp
    title: library/formalpowerseries/Prod.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/RationalSum.hpp
    title: library/formalpowerseries/RationalSum.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/Sqrt.hpp
    title: library/formalpowerseries/Sqrt.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/composition.hpp
    title: library/formalpowerseries/functions/composition.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/differential.hpp
    title: library/formalpowerseries/functions/differential.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/exp.hpp
    title: library/formalpowerseries/functions/exp.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/integral.hpp
    title: library/formalpowerseries/functions/integral.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/log.hpp
    title: library/formalpowerseries/functions/log.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/pow.hpp
    title: library/formalpowerseries/functions/pow.hpp
  - icon: ':warning:'
    path: library/formalpowerseries/functions/taylor_shift.hpp
    title: library/formalpowerseries/functions/taylor_shift.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Polynomial/Composition.test.cpp
    title: test/library-checker/Polynomial/Composition.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
    title: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/Exp.test.cpp
    title: test/library-checker/Polynomial/Exp.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/Inv.test.cpp
    title: test/library-checker/Polynomial/Inv.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/Log.test.cpp
    title: test/library-checker/Polynomial/Log.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
    title: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/Pow.test.cpp
    title: test/library-checker/Polynomial/Pow.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
    title: test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
  - icon: ':x:'
    path: test/library-checker/Polynomial/TaylorShift.test.cpp
    title: test/library-checker/Polynomial/TaylorShift.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/Valarray.hpp\"\n#include <vector>\n#include\
    \ <functional>\n#include <ranges>\n\ntemplate <typename T> struct Valarray : std::vector<T>\
    \ {\n    using std::vector<T>::vector; // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u7D99\u627F\n\n  private:\n    template <typename Op>\n    Valarray &apply_inplace(const\
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
    \ Valarray &b) { return a /= b; }\n};\n"
  code: "#include <vector>\n#include <functional>\n#include <ranges>\n\ntemplate <typename\
    \ T> struct Valarray : std::vector<T> {\n    using std::vector<T>::vector; //\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u7D99\u627F\n\n  private:\n    template\
    \ <typename Op>\n    Valarray &apply_inplace(const Valarray &other, Op op) {\n\
    \        if (this->size() < other.size())\n            this->resize(other.size(),\
    \ T(0));\n\n        for (auto [a, b] : std::views::zip(*this, other))\n      \
    \      a = op(a, b);\n\n        return *this;\n    }\n\n  public:\n    Valarray\
    \ &operator+=(const Valarray &other) {\n        return apply_inplace(other, std::plus<>());\n\
    \    }\n    Valarray &operator-=(const Valarray &other) {\n        return apply_inplace(other,\
    \ std::minus<>());\n    }\n    Valarray &operator*=(const Valarray &other) {\n\
    \        return apply_inplace(other, std::multiplies<>());\n    }\n    Valarray\
    \ &operator/=(const Valarray &other) {\n        return apply_inplace(other, std::divides<>());\n\
    \    }\n\n    friend Valarray operator+(Valarray a, const Valarray &b) { return\
    \ a += b; }\n    friend Valarray operator-(Valarray a, const Valarray &b) { return\
    \ a -= b; }\n    friend Valarray operator*(Valarray a, const Valarray &b) { return\
    \ a *= b; }\n    friend Valarray operator/(Valarray a, const Valarray &b) { return\
    \ a /= b; }\n};"
  dependsOn: []
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
  timestamp: '2025-11-09 20:16:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
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
