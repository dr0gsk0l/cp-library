---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/util/Valarray.hpp
    title: library/util/Valarray.hpp
  _extendedRequiredBy:
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
    \ Valarray &b) { return a /= b; }\n};\n#line 3 \"library/formalpowerseries/Base.hpp\"\
    \n\ntemplate <typename T, int MX> struct FormalPowerSeries : Valarray<T> {\n \
    \   using FPS = FormalPowerSeries;\n    static constexpr int max_size = MX;\n\
    \    using Valarray<T>::Valarray;\n    using Valarray<T>::size;\n    using Valarray<T>::resize;\n\
    \    using Valarray<T>::at;\n    using Valarray<T>::begin;\n    using Valarray<T>::end;\n\
    \    using Valarray<T>::back;\n    using Valarray<T>::pop_back;\n    using value_type\
    \ = T;\n\n    void strict(int n) {\n        if (size() > n)\n            resize(n);\n\
    \    }\n    void shrink() {\n        while (size() and back() == 0)\n        \
    \    pop_back();\n    }\n\n    FormalPowerSeries() = default;\n\n    FormalPowerSeries(const\
    \ std::vector<T> &f) : Valarray<T>(f) {\n        strict(MX);\n        shrink();\n\
    \    }\n\n    static FPS unit() { return {1}; }\n    static FPS x() { return {0,\
    \ 1}; }\n#pragma region operator\n    FPS operator-() const {\n        FPS g =\
    \ *this;\n        for (T &a : g)\n            a = -a;\n        return g;\n   \
    \ }\n\n    FPS &operator+=(const T &a) {\n        if (!size())\n            resize(1);\n\
    \        at(0) += a;\n        return *this;\n    }\n    FPS operator+(const T\
    \ &a) const { return FPS(*this) += a; }\n    friend FPS operator+(const T &a,\
    \ const FPS &f) { return f + a; }\n\n    FPS &operator-=(const T &a) {\n     \
    \   if (!size())\n            resize(1);\n        at(0) -= a;\n        return\
    \ *this;\n    }\n    FPS operator-(const T &a) { return FPS(*this) -= a; }\n \
    \   friend FPS operator-(const T &a, const FPS &f) { return a + (-f); }\n\n  \
    \  FPS operator*(const FPS &g) const { return FPS(convolution(*this, g)); }\n\
    \    FPS &operator*=(const FPS &g) { return (*this) = (*this) * g; }\n\n    FPS\
    \ &operator*=(const T &a) {\n        for (size_t i = 0; i < size(); i++) at(i)\
    \ *= a;\n        return *this;\n    }\n    FPS operator*(const T &a) const { return\
    \ FPS(*this) *= a; }\n    friend FPS operator*(const T &a, const FPS &f) { return\
    \ f * a; }\n\n    FPS operator/(const FPS& g) const { return (*this) * g.inv();\
    \ }\n    FPS &operator/=(const FPS &g) { return (*this) = (*this) / g; }\n\n \
    \   FPS &operator/=(const T &a) { return *this *= a.inv(); }\n    FPS operator/(const\
    \ T &a) { return FPS(*this) /= a; }\n\n    FPS &operator<<=(const int d) {\n \
    \       if (d >= MX)\n            return *this = FPS(0);\n        resize(std::min(MX,\
    \ int(size()) + d));\n        for (int i = int(size()) - 1 - d; i >= 0; i--)\n\
    \            at(i + d) = at(i);\n        for (int i = d - 1; i >= 0; i--)\n  \
    \          at(i) = 0;\n        return *this;\n    }\n    FPS operator<<(const\
    \ int d) const { return FPS(*this) <<= d; }\n    FPS &operator>>=(const int d)\
    \ {\n        if (d >= size())\n            return *this = FPS(0);\n        for\
    \ (size_t i = d; i < size(); i++)\n            at(i - d) = at(i);\n        strict(int(size())\
    \ - d);\n        return *this;\n    }\n    FPS operator>>(const int d) const {\
    \ return FPS(*this) >>= d; }\n#pragma endregion operator\n\n    FPS pre(int n)\
    \ const {\n        if (size() <= n)\n            return *this;\n        return\
    \ FPS(Valarray<T>(this->begin(), this->begin() + n));\n    }\n\n    FPS inv(int\
    \ SZ = MX) const {\n        assert(size() and at(0) != 0);\n        FPS res =\
    \ {at(0).inv()};\n        for (int n = 1; n < SZ; n <<= 1) {\n            res\
    \ *= (2 - this->pre(n << 1) * res);\n            res.strict(n << 1);\n       \
    \ }\n        res.strict(SZ);\n        return res;\n    }\n\n    // *this = f_1\
    \ + f_2 x^n \u21D2 [*this\u2190f_1, return f_2]\n    FPS separate(int n) {\n \
    \       if (size() <= n)\n            return FPS(0);\n        FPS f_2(size() -\
    \ n);\n        for (size_t i = n; i < size(); i++)\n            f_2[i - n] = at(i);\n\
    \        strict(n);\n        return f_2;\n    }\n\n    T operator()(T a) const\
    \ {\n        T res = 0, b = 1;\n        for (size_t i = 0; i < size(); i++, b\
    \ *= a)\n            res += at(i) * b;\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"library/util/Valarray.hpp\"\n\ntemplate <typename\
    \ T, int MX> struct FormalPowerSeries : Valarray<T> {\n    using FPS = FormalPowerSeries;\n\
    \    static constexpr int max_size = MX;\n    using Valarray<T>::Valarray;\n \
    \   using Valarray<T>::size;\n    using Valarray<T>::resize;\n    using Valarray<T>::at;\n\
    \    using Valarray<T>::begin;\n    using Valarray<T>::end;\n    using Valarray<T>::back;\n\
    \    using Valarray<T>::pop_back;\n    using value_type = T;\n\n    void strict(int\
    \ n) {\n        if (size() > n)\n            resize(n);\n    }\n    void shrink()\
    \ {\n        while (size() and back() == 0)\n            pop_back();\n    }\n\n\
    \    FormalPowerSeries() = default;\n\n    FormalPowerSeries(const std::vector<T>\
    \ &f) : Valarray<T>(f) {\n        strict(MX);\n        shrink();\n    }\n\n  \
    \  static FPS unit() { return {1}; }\n    static FPS x() { return {0, 1}; }\n\
    #pragma region operator\n    FPS operator-() const {\n        FPS g = *this;\n\
    \        for (T &a : g)\n            a = -a;\n        return g;\n    }\n\n   \
    \ FPS &operator+=(const T &a) {\n        if (!size())\n            resize(1);\n\
    \        at(0) += a;\n        return *this;\n    }\n    FPS operator+(const T\
    \ &a) const { return FPS(*this) += a; }\n    friend FPS operator+(const T &a,\
    \ const FPS &f) { return f + a; }\n\n    FPS &operator-=(const T &a) {\n     \
    \   if (!size())\n            resize(1);\n        at(0) -= a;\n        return\
    \ *this;\n    }\n    FPS operator-(const T &a) { return FPS(*this) -= a; }\n \
    \   friend FPS operator-(const T &a, const FPS &f) { return a + (-f); }\n\n  \
    \  FPS operator*(const FPS &g) const { return FPS(convolution(*this, g)); }\n\
    \    FPS &operator*=(const FPS &g) { return (*this) = (*this) * g; }\n\n    FPS\
    \ &operator*=(const T &a) {\n        for (size_t i = 0; i < size(); i++) at(i)\
    \ *= a;\n        return *this;\n    }\n    FPS operator*(const T &a) const { return\
    \ FPS(*this) *= a; }\n    friend FPS operator*(const T &a, const FPS &f) { return\
    \ f * a; }\n\n    FPS operator/(const FPS& g) const { return (*this) * g.inv();\
    \ }\n    FPS &operator/=(const FPS &g) { return (*this) = (*this) / g; }\n\n \
    \   FPS &operator/=(const T &a) { return *this *= a.inv(); }\n    FPS operator/(const\
    \ T &a) { return FPS(*this) /= a; }\n\n    FPS &operator<<=(const int d) {\n \
    \       if (d >= MX)\n            return *this = FPS(0);\n        resize(std::min(MX,\
    \ int(size()) + d));\n        for (int i = int(size()) - 1 - d; i >= 0; i--)\n\
    \            at(i + d) = at(i);\n        for (int i = d - 1; i >= 0; i--)\n  \
    \          at(i) = 0;\n        return *this;\n    }\n    FPS operator<<(const\
    \ int d) const { return FPS(*this) <<= d; }\n    FPS &operator>>=(const int d)\
    \ {\n        if (d >= size())\n            return *this = FPS(0);\n        for\
    \ (size_t i = d; i < size(); i++)\n            at(i - d) = at(i);\n        strict(int(size())\
    \ - d);\n        return *this;\n    }\n    FPS operator>>(const int d) const {\
    \ return FPS(*this) >>= d; }\n#pragma endregion operator\n\n    FPS pre(int n)\
    \ const {\n        if (size() <= n)\n            return *this;\n        return\
    \ FPS(Valarray<T>(this->begin(), this->begin() + n));\n    }\n\n    FPS inv(int\
    \ SZ = MX) const {\n        assert(size() and at(0) != 0);\n        FPS res =\
    \ {at(0).inv()};\n        for (int n = 1; n < SZ; n <<= 1) {\n            res\
    \ *= (2 - this->pre(n << 1) * res);\n            res.strict(n << 1);\n       \
    \ }\n        res.strict(SZ);\n        return res;\n    }\n\n    // *this = f_1\
    \ + f_2 x^n \u21D2 [*this\u2190f_1, return f_2]\n    FPS separate(int n) {\n \
    \       if (size() <= n)\n            return FPS(0);\n        FPS f_2(size() -\
    \ n);\n        for (size_t i = n; i < size(); i++)\n            f_2[i - n] = at(i);\n\
    \        strict(n);\n        return f_2;\n    }\n\n    T operator()(T a) const\
    \ {\n        T res = 0, b = 1;\n        for (size_t i = 0; i < size(); i++, b\
    \ *= a)\n            res += at(i) * b;\n        return res;\n    }\n};"
  dependsOn:
  - library/util/Valarray.hpp
  isVerificationFile: false
  path: library/formalpowerseries/Base.hpp
  requiredBy:
  - library/formalpowerseries/DivMod.hpp
  - library/formalpowerseries/Sqrt.hpp
  - library/formalpowerseries/RationalSum.hpp
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
  timestamp: '2025-11-09 21:16:52+09:00'
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
documentation_of: library/formalpowerseries/Base.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/Base.hpp
- /library/library/formalpowerseries/Base.hpp.html
title: library/formalpowerseries/Base.hpp
---
