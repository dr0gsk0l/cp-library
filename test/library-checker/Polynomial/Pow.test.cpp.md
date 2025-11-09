---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/formalpowerseries/Base.hpp
    title: library/formalpowerseries/Base.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/differential.hpp
    title: library/formalpowerseries/functions/differential.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/exp.hpp
    title: library/formalpowerseries/functions/exp.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/integral.hpp
    title: library/formalpowerseries/functions/integral.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/log.hpp
    title: library/formalpowerseries/functions/log.hpp
  - icon: ':x:'
    path: library/formalpowerseries/functions/pow.hpp
    title: library/formalpowerseries/functions/pow.hpp
  - icon: ':x:'
    path: library/util/Valarray.hpp
    title: library/util/Valarray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Pow.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\n#include\
    \ <bits/stdc++.h>\n\n#line 3 \"library/util/Valarray.hpp\"\n#include <ranges>\n\
    \ntemplate <typename T> struct Valarray : std::vector<T> {\n    using std::vector<T>::vector;\
    \ // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u7D99\u627F\n\n  private:\n  \
    \  template <typename Op>\n    Valarray &apply_inplace(const Valarray &other,\
    \ Op op) {\n        if (this->size() < other.size())\n            this->resize(other.size(),\
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
    \ a /= b; }\n};\n#line 3 \"library/formalpowerseries/Base.hpp\"\n\ntemplate <typename\
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
    \ *= a)\n            res += at(i) * b;\n        return res;\n    }\n};\n#line\
    \ 3 \"library/formalpowerseries/functions/differential.hpp\"\n\nnamespace fps\
    \ {\n\ntemplate <typename T, int MX>\nFormalPowerSeries<T, MX> differential(FormalPowerSeries<T,\
    \ MX> f) {\n    if (f.size() <= 1) {\n        return FormalPowerSeries<T, MX>{};\n\
    \    }\n    for (std::size_t i = 0; i < f.size() - 1; i++) {\n        f[i] = (i\
    \ + 1) * f[i + 1];\n    }\n    f.pop_back();\n    return f;\n}\n\n} // namespace\
    \ fps\n#line 3 \"library/formalpowerseries/functions/integral.hpp\"\n\nnamespace\
    \ fps {\n\ntemplate <typename T, int MX>\nFormalPowerSeries<T, MX> integral(FormalPowerSeries<T,\
    \ MX> f) {\n    if (f.size() < MX) {\n        f.resize(f.size() + 1);\n    }\n\
    \    for (int i = f.size() - 1; i > 0; i--) {\n        f[i] = f[i - 1] / i;\n\
    \    }\n    f[0] = 0;\n    return f;\n}\n\n} // namespace fps\n#line 5 \"library/formalpowerseries/functions/log.hpp\"\
    \n\nnamespace fps {\n\ntemplate <typename T, int MX>\nFormalPowerSeries<T, MX>\
    \ log(const FormalPowerSeries<T, MX> &f) {\n    assert(f.size() and f[0] == 1);\n\
    \    return integral(differential(f) / f);\n}\n\n} // namespace fps\n#line 4 \"\
    library/formalpowerseries/functions/exp.hpp\"\n\nnamespace fps {\n\ntemplate <typename\
    \ T, int MX>\nFormalPowerSeries<T, MX> exp(const FormalPowerSeries<T, MX>& f)\
    \ {\n    if (!f.size()) {\n        return {1};\n    }\n    assert(f.size() > 0\
    \ && f[0] == 0);\n    FormalPowerSeries<T, MX> res = {1};\n    for (int n = 1;\
    \ n < MX; n <<= 1) {\n        res = res * (f.pre(n << 1) + 1 - log(res).pre(n\
    \ << 1));\n        res.strict(n << 1);\n    }\n    return res;\n}\n\ntemplate\
    \ <typename T, int MX>\nFormalPowerSeries<T, MX> exp(const T& n) {\n    if (n\
    \ == 0) {\n        return {1};\n    }\n    FormalPowerSeries<T, MX> res(MX);\n\
    \    res[0] = 1;\n    for (int i = 1; i < MX; i++) {\n        res[i] = res[i -\
    \ 1] * n / i;\n    }\n    return res;\n}\n\n} // namespace fps\n#line 5 \"library/formalpowerseries/functions/pow.hpp\"\
    \n\nnamespace fps {\n\ntemplate <typename T, int MX>\nFormalPowerSeries<T, MX>\
    \ pow(FormalPowerSeries<T, MX> f, long long n) {\n    assert(n >= 0);\n    if\
    \ (n == 0) {\n        return {1};\n    }\n    if (n == 1) {\n        return f;\n\
    \    }\n\n    f.shrink();\n    if (!f.size()) {\n        return f;\n    }\n  \
    \  int d = 0;\n    while(d < f.size() && f[d] == 0) {\n        d++;\n    }\n \
    \   \n    if (d > 0 && (unsigned __int128)d * n >= MX) {\n        return FormalPowerSeries<T,\
    \ MX>{};\n    }\n    f >>= d;\n    d *= n;\n\n    if (f[0] == 1) {\n        f\
    \ = exp(n * log(f));\n    } else {\n        f = exp(log(f) * n);\n    }\n    f\
    \ <<= d;\n    \n    return f;\n}\n\n} // namespace fps\n#line 6 \"test/library-checker/Polynomial/Pow.test.cpp\"\
    \n\n#include <atcoder/convolution>\n#include <atcoder/modint>\nusing namespace\
    \ atcoder;\nusing mint = modint998244353;\nstd::ostream &operator<<(std::ostream\
    \ &os, mint a) {\n    os << a.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, mint &a) {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n\
    }\n\nusing FPS = FormalPowerSeries<mint, 500000>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    long long m;\n    std::cin >> n\
    \ >> m;\n    FPS f(n);\n    for (int i = 0; i < n; i++)\n        std::cin >> f[i];\n\
    \    f = fps::pow(f, m);\n    for (int i = 0; i < n; i++)\n        std::cout <<\
    \ (i < f.size() ? f[i] : 0) << \"\\n \"[i + 1 < n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/formalpowerseries/Base.hpp\"\n\
    #include \"library/formalpowerseries/functions/pow.hpp\"\n\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\nusing namespace atcoder;\nusing mint = modint998244353;\n\
    std::ostream &operator<<(std::ostream &os, mint a) {\n    os << a.val();\n   \
    \ return os;\n}\nstd::istream &operator>>(std::istream &is, mint &a) {\n    long\
    \ long b;\n    is >> b;\n    a = b;\n    return is;\n}\n\nusing FPS = FormalPowerSeries<mint,\
    \ 500000>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    long long m;\n    std::cin >> n >> m;\n    FPS f(n);\n    for\
    \ (int i = 0; i < n; i++)\n        std::cin >> f[i];\n    f = fps::pow(f, m);\n\
    \    for (int i = 0; i < n; i++)\n        std::cout << (i < f.size() ? f[i] :\
    \ 0) << \"\\n \"[i + 1 < n];\n}"
  dependsOn:
  - library/formalpowerseries/Base.hpp
  - library/util/Valarray.hpp
  - library/formalpowerseries/functions/pow.hpp
  - library/formalpowerseries/functions/exp.hpp
  - library/formalpowerseries/functions/log.hpp
  - library/formalpowerseries/functions/differential.hpp
  - library/formalpowerseries/functions/integral.hpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/Pow.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 23:27:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Pow.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Pow.test.cpp
- /verify/test/library-checker/Polynomial/Pow.test.cpp.html
title: test/library-checker/Polynomial/Pow.test.cpp
---
