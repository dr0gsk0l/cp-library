---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/formalpowerseries/Base.hpp
    title: library/formalpowerseries/Base.hpp
  - icon: ':question:'
    path: library/formalpowerseries/DivMod.hpp
    title: library/formalpowerseries/DivMod.hpp
  - icon: ':x:'
    path: library/formalpowerseries/MultipointEvaluation.hpp
    title: library/formalpowerseries/MultipointEvaluation.hpp
  - icon: ':question:'
    path: library/util/Valarray.hpp
    title: library/util/Valarray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation
  bundledCode: "#line 1 \"test/library-checker/Polynomial/MultipointEvaluation.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\n\
    #include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n\
    #include <atcoder/convolution>\n#include <atcoder/modint>\nusing namespace atcoder;\n\
    using mint = modint998244353;\nstd::ostream &operator<<(std::ostream &os, mint\
    \ a) {\n    os << a.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, mint &a) {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n\
    }\n#line 2 \"library/util/Valarray.hpp\"\n#include <ranges>\n#line 4 \"library/util/Valarray.hpp\"\
    \n\ntemplate <typename T> struct Valarray : std::vector<T> {\n    using std::vector<T>::vector;\
    \ // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u7D99\u627F\n    Valarray(const\
    \ std::vector<T> &v) : std::vector<T>(v.begin(), v.end()) {}\n\n  private:\n \
    \   template <typename Op>\n    Valarray &apply_inplace(const Valarray &other,\
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
    \ a /= b; }\n\n    Valarray operator-() const {\n        Valarray g = *this;\n\
    \        for (T &a : g)\n            a = -a;\n        return g;\n    }\n};\n#line\
    \ 3 \"library/formalpowerseries/Base.hpp\"\n\ntemplate <typename T, int MX> struct\
    \ FormalPowerSeries : Valarray<T> {\n    using FPS = FormalPowerSeries;\n    static\
    \ constexpr int max_size = MX;\n    using Valarray<T>::Valarray;\n    using Valarray<T>::size;\n\
    \    using Valarray<T>::resize;\n    using Valarray<T>::at;\n    using Valarray<T>::begin;\n\
    \    using Valarray<T>::end;\n    using Valarray<T>::back;\n    using Valarray<T>::pop_back;\n\
    \    using value_type = T;\n\n    void strict(int n) {\n        if (size() > n)\n\
    \            resize(n);\n    }\n    void shrink() {\n        while (size() and\
    \ back() == 0)\n            pop_back();\n    }\n\n    FormalPowerSeries() = default;\n\
    \n    FormalPowerSeries(const std::vector<T> &f) : Valarray<T>(f) {\n        strict(MX);\n\
    \        shrink();\n    }\n\n    static FPS unit() { return {1}; }\n    static\
    \ FPS x() { return {0, 1}; }\n#pragma region operator\n    FPS operator-() const\
    \ { return FPS(Valarray<T>::operator-()); }\n\n    FPS &operator+=(const FPS &g)\
    \ {\n        Valarray<T>::operator+=(g);\n        shrink();\n        return *this;\n\
    \    }\n    FPS operator+(const FPS &g) const { return FPS(*this) += g; }\n\n\
    \    FPS &operator-=(const FPS &g) {\n        Valarray<T>::operator-=(g);\n  \
    \      shrink();\n        return *this;\n    }\n    FPS operator-(const FPS &g)\
    \ const { return FPS(*this) -= g; }\n\n    FPS &operator+=(const T &a) {\n   \
    \     if (!size())\n            resize(1);\n        at(0) += a;\n        return\
    \ *this;\n    }\n    FPS operator+(const T &a) const { return FPS(*this) += a;\
    \ }\n    friend FPS operator+(const T &a, const FPS &f) { return f + a; }\n\n\
    \    FPS &operator-=(const T &a) {\n        if (!size())\n            resize(1);\n\
    \        at(0) -= a;\n        return *this;\n    }\n    FPS operator-(const T\
    \ &a) { return FPS(*this) -= a; }\n    friend FPS operator-(const T &a, const\
    \ FPS &f) { return a + (-f); }\n\n    FPS operator*(const FPS &g) const { return\
    \ FPS(convolution(*this, g)); }\n    FPS &operator*=(const FPS &g) { return (*this)\
    \ = (*this) * g; }\n\n    FPS &operator*=(const T &a) {\n        for (size_t i\
    \ = 0; i < size(); i++)\n            at(i) *= a;\n        return *this;\n    }\n\
    \    FPS operator*(const T &a) const { return FPS(*this) *= a; }\n    friend FPS\
    \ operator*(const T &a, const FPS &f) { return f * a; }\n\n    FPS operator/(const\
    \ FPS &g) const { return (*this) * g.inv(); }\n    FPS &operator/=(const FPS &g)\
    \ { return (*this) = (*this) / g; }\n\n    FPS &operator/=(const T &a) { return\
    \ *this *= a.inv(); }\n    FPS operator/(const T &a) { return FPS(*this) /= a;\
    \ }\n\n    FPS &operator<<=(const int d) {\n        if (d >= MX)\n           \
    \ return *this = FPS(0);\n        resize(std::min(MX, int(size()) + d));\n   \
    \     for (int i = int(size()) - 1 - d; i >= 0; i--)\n            at(i + d) =\
    \ at(i);\n        for (int i = d - 1; i >= 0; i--)\n            at(i) = 0;\n \
    \       return *this;\n    }\n    FPS operator<<(const int d) const { return FPS(*this)\
    \ <<= d; }\n    FPS &operator>>=(const int d) {\n        if (d >= size())\n  \
    \          return *this = FPS(0);\n        for (size_t i = d; i < size(); i++)\n\
    \            at(i - d) = at(i);\n        strict(int(size()) - d);\n        return\
    \ *this;\n    }\n    FPS operator>>(const int d) const { return FPS(*this) >>=\
    \ d; }\n#pragma endregion operator\n\n    FPS pre(int n) const {\n        if (size()\
    \ <= n)\n            return *this;\n        return FPS(Valarray<T>(this->begin(),\
    \ this->begin() + n));\n    }\n\n    FPS inv(int SZ = MX) const {\n        assert(size()\
    \ and at(0) != 0);\n        FPS res = {at(0).inv()};\n        for (int n = 1;\
    \ n < SZ; n <<= 1) {\n            res *= (2 - this->pre(n << 1) * res);\n    \
    \        res.strict(n << 1);\n        }\n        res.strict(SZ);\n        return\
    \ res;\n    }\n\n    // *this = f_1 + f_2 x^n \u21D2 [*this\u2190f_1, return f_2]\n\
    \    FPS separate(int n) {\n        if (size() <= n)\n            return FPS(0);\n\
    \        FPS f_2(size() - n);\n        for (size_t i = n; i < size(); i++)\n \
    \           f_2[i - n] = at(i);\n        strict(n);\n        return f_2;\n   \
    \ }\n\n    T operator()(T a) const {\n        T res = 0, b = 1;\n        for (size_t\
    \ i = 0; i < size(); i++, b *= a)\n            res += at(i) * b;\n        return\
    \ res;\n    }\n};\n#line 21 \"test/library-checker/Polynomial/MultipointEvaluation.test.cpp\"\
    \nusing FPS = FormalPowerSeries<mint, (1 << 17) + 1>;\n#line 3 \"library/formalpowerseries/DivMod.hpp\"\
    \ntemplate <typename FPS> std::pair<FPS, FPS> div_mod(FPS f, FPS g) {\n    f.shrink();\n\
    \    g.shrink();\n    assert(g.size());\n    if (f.size() < g.size())\n      \
    \  return {FPS(0), f};\n    std::ranges::reverse(f);\n    std::ranges::reverse(g);\n\
    \    int d = f.size() - g.size() + 1;\n    FPS q = (f.pre(d) * g.inv(d)).pre(d);\n\
    \    if (q.size() < d)\n        q.resize(d, 0);\n    std::ranges::reverse(q);\n\
    \    std::ranges::reverse(f);\n    std::ranges::reverse(g);\n    return {q, f\
    \ - q * g};\n}\n#undef REVERSE_\n#line 4 \"library/formalpowerseries/MultipointEvaluation.hpp\"\
    \ntemplate <typename FPS, typename T = typename FPS::value_type>\nstd::vector<T>\
    \ multipoint_evaluation(const FPS &f, std::vector<T> v) {\n    int m = v.size();\n\
    \    int sz;\n    for (sz = 1; sz < m; sz *= 2) {\n    }\n    std::vector<FPS>\
    \ t(sz * 2);\n    for (int i = 0; i < sz; i++)\n        t[sz + i] = {(i < m ?\
    \ -v[i] : 0), 1};\n    for (int i = sz - 1; i > 0; i--)\n        t[i] = t[2 *\
    \ i] * t[2 * i + 1];\n\n    t[0] = f;\n    for (int i = 1; i < sz + m; i++)\n\
    \        t[i] = div_mod(t[i >> 1], t[i]).second;\n\n    for (int i = 0; i < m;\
    \ i++)\n        v[i] = t[sz + i][0];\n    return v;\n}\n#line 23 \"test/library-checker/Polynomial/MultipointEvaluation.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, m;\n    std::cin >> n >> m;\n    FPS f(n);\n    REP (i, n)\n    \
    \    std::cin >> f[i];\n    std::vector<mint> p(m);\n    REP (j, m)\n        std::cin\
    \ >> p[j];\n\n    std::vector<mint> ans = multipoint_evaluation(f, p);\n    REP\
    \ (j, m)\n        std::cout << ans[j] << \"\\n \"[j + 1 < m];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include <atcoder/convolution>\n#include <atcoder/modint>\nusing namespace atcoder;\n\
    using mint = modint998244353;\nstd::ostream &operator<<(std::ostream &os, mint\
    \ a) {\n    os << a.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, mint &a) {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n\
    }\n#include \"library/formalpowerseries/Base.hpp\"\nusing FPS = FormalPowerSeries<mint,\
    \ (1 << 17) + 1>;\n#include \"library/formalpowerseries/MultipointEvaluation.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, m;\n    std::cin >> n >> m;\n    FPS f(n);\n    REP (i, n)\n    \
    \    std::cin >> f[i];\n    std::vector<mint> p(m);\n    REP (j, m)\n        std::cin\
    \ >> p[j];\n\n    std::vector<mint> ans = multipoint_evaluation(f, p);\n    REP\
    \ (j, m)\n        std::cout << ans[j] << \"\\n \"[j + 1 < m];\n}"
  dependsOn:
  - library/formalpowerseries/Base.hpp
  - library/util/Valarray.hpp
  - library/formalpowerseries/MultipointEvaluation.hpp
  - library/formalpowerseries/DivMod.hpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
  requiredBy: []
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/MultipointEvaluation.test.cpp
- /verify/test/library-checker/Polynomial/MultipointEvaluation.test.cpp.html
title: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
---
