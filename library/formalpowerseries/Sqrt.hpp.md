---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/formalpowerseries/Base.hpp
    title: library/formalpowerseries/Base.hpp
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
  - icon: ':warning:'
    path: library/math/ModularSqrt.hpp
    title: library/math/ModularSqrt.hpp
  - icon: ':question:'
    path: library/mod/Modint.hpp
    title: library/mod/Modint.hpp
  - icon: ':question:'
    path: library/util/Valarray.hpp
    title: library/util/Valarray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ g;\n    }\n};\n#line 3 \"library/formalpowerseries/Base.hpp\"\n\ntemplate <typename\
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
    #pragma region operator\n    FPS operator-() const { return FPS(Valarray<T>::operator-());\
    \ }\n\n    FPS &operator+=(const T &a) {\n        if (!size())\n            resize(1);\n\
    \        at(0) += a;\n        return *this;\n    }\n    FPS operator+(const T\
    \ &a) const { return FPS(*this) += a; }\n    friend FPS operator+(const T &a,\
    \ const FPS &f) { return f + a; }\n\n    FPS &operator-=(const T &a) {\n     \
    \   if (!size())\n            resize(1);\n        at(0) -= a;\n        return\
    \ *this;\n    }\n    FPS operator-(const T &a) { return FPS(*this) -= a; }\n \
    \   friend FPS operator-(const T &a, const FPS &f) { return a + (-f); }\n\n  \
    \  FPS operator*(const FPS &g) const { return FPS(convolution(*this, g)); }\n\
    \    FPS &operator*=(const FPS &g) { return (*this) = (*this) * g; }\n\n    FPS\
    \ &operator*=(const T &a) {\n        for (size_t i = 0; i < size(); i++)\n   \
    \         at(i) *= a;\n        return *this;\n    }\n    FPS operator*(const T\
    \ &a) const { return FPS(*this) *= a; }\n    friend FPS operator*(const T &a,\
    \ const FPS &f) { return f * a; }\n\n    FPS operator/(const FPS &g) const { return\
    \ (*this) * g.inv(); }\n    FPS &operator/=(const FPS &g) { return (*this) = (*this)\
    \ / g; }\n\n    FPS &operator/=(const T &a) { return *this *= a.inv(); }\n   \
    \ FPS operator/(const T &a) { return FPS(*this) /= a; }\n\n    FPS &operator<<=(const\
    \ int d) {\n        if (d >= MX)\n            return *this = FPS(0);\n       \
    \ resize(std::min(MX, int(size()) + d));\n        for (int i = int(size()) - 1\
    \ - d; i >= 0; i--)\n            at(i + d) = at(i);\n        for (int i = d -\
    \ 1; i >= 0; i--)\n            at(i) = 0;\n        return *this;\n    }\n    FPS\
    \ operator<<(const int d) const { return FPS(*this) <<= d; }\n    FPS &operator>>=(const\
    \ int d) {\n        if (d >= size())\n            return *this = FPS(0);\n   \
    \     for (size_t i = d; i < size(); i++)\n            at(i - d) = at(i);\n  \
    \      strict(int(size()) - d);\n        return *this;\n    }\n    FPS operator>>(const\
    \ int d) const { return FPS(*this) >>= d; }\n#pragma endregion operator\n\n  \
    \  FPS pre(int n) const {\n        if (size() <= n)\n            return *this;\n\
    \        return FPS(Valarray<T>(this->begin(), this->begin() + n));\n    }\n\n\
    \    FPS inv(int SZ = MX) const {\n        assert(size() and at(0) != 0);\n  \
    \      FPS res = {at(0).inv()};\n        for (int n = 1; n < SZ; n <<= 1) {\n\
    \            res *= (2 - this->pre(n << 1) * res);\n            res.strict(n <<\
    \ 1);\n        }\n        res.strict(SZ);\n        return res;\n    }\n\n    //\
    \ *this = f_1 + f_2 x^n \u21D2 [*this\u2190f_1, return f_2]\n    FPS separate(int\
    \ n) {\n        if (size() <= n)\n            return FPS(0);\n        FPS f_2(size()\
    \ - n);\n        for (size_t i = n; i < size(); i++)\n            f_2[i - n] =\
    \ at(i);\n        strict(n);\n        return f_2;\n    }\n\n    T operator()(T\
    \ a) const {\n        T res = 0, b = 1;\n        for (size_t i = 0; i < size();\
    \ i++, b *= a)\n            res += at(i) * b;\n        return res;\n    }\n};\n\
    #line 2 \"library/math/ExtraGCD.hpp\"\nusing ll = long long;\nstd::pair<ll, ll>\
    \ ext_gcd(ll a, ll b) {\n    if (b == 0)\n        return {1, 0};\n    auto [X,\
    \ Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b = a - b(a/b)\n\
    \    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X - (a / b) * Y;\n\
    \    return {x, y};\n}\n#line 3 \"library/mod/Modint.hpp\"\ntemplate <typename\
    \ T, T MOD = 998244353> struct Mint {\n    inline static constexpr T mod = MOD;\n\
    \    T v;\n    Mint() : v(0) {}\n    Mint(signed v) : v(v) {}\n    Mint(long long\
    \ t) {\n        v = t % MOD;\n        if (v < 0)\n            v += MOD;\n    }\n\
    \n    static Mint raw(int v) {\n        Mint x;\n        x.v = v;\n        return\
    \ x;\n    }\n\n    Mint pow(long long k) const {\n        Mint res(1), tmp(v);\n\
    \        while (k) {\n            if (k & 1)\n                res *= tmp;\n  \
    \          tmp *= tmp;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    static Mint add_identity() { return Mint(0); }\n    static Mint\
    \ mul_identity() { return Mint(1); }\n\n    // Mint inv()const{return pow(MOD-2);}\n\
    \    Mint inv() const { return Mint(ext_gcd(v, mod).first); }\n\n    Mint &operator+=(Mint\
    \ a) {\n        v += a.v;\n        if (v >= MOD)\n            v -= MOD;\n    \
    \    return *this;\n    }\n    Mint &operator-=(Mint a) {\n        v += MOD -\
    \ a.v;\n        if (v >= MOD)\n            v -= MOD;\n        return *this;\n\
    \    }\n    Mint &operator*=(Mint a) {\n        v = 1LL * v * a.v % MOD;\n   \
    \     return *this;\n    }\n    Mint &operator/=(Mint a) { return (*this) *= a.inv();\
    \ }\n\n    Mint operator+(Mint a) const { return Mint(v) += a; }\n    Mint operator-(Mint\
    \ a) const { return Mint(v) -= a; }\n    Mint operator*(Mint a) const { return\
    \ Mint(v) *= a; }\n    Mint operator/(Mint a) const { return Mint(v) /= a; }\n\
    #define FRIEND(op)                                                           \
    \  \\\n    friend Mint operator op(int a, Mint b) { return Mint(a) op b; }\n \
    \   FRIEND(+);\n    FRIEND(-);\n    FRIEND(*);\n    FRIEND(/);\n#undef FRIEND\n\
    \    Mint operator+() const { return *this; }\n    Mint operator-() const { return\
    \ v ? Mint(MOD - v) : Mint(v); }\n\n    bool operator==(const Mint a) const {\
    \ return v == a.v; }\n    bool operator!=(const Mint a) const { return v != a.v;\
    \ }\n\n    static Mint comb(long long n, int k) {\n        Mint num(1), dom(1);\n\
    \        for (int i = 0; i < k; i++) {\n            num *= Mint(n - i);\n    \
    \        dom *= Mint(i + 1);\n        }\n        return num / dom;\n    }\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Mint &m) {\n    \
    \    os << m.v;\n        return os;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, Mint &m) {\n        is >> m.v;\n        m.v %= MOD;\n        if (m.v <\
    \ 0)\n            m.v += MOD;\n        return is;\n    }\n};\n#line 3 \"library/math/ModularSqrt.hpp\"\
    \n#include <optional>\n#include <random>\n#include <chrono>\n\ntemplate <typename\
    \ T, T MOD>\nbool is_quadratic_residue(Mint<T, MOD> a) {\n    if (a == 0) return\
    \ true;\n    return a.pow((MOD - 1) / 2) == 1;\n}\n\ntemplate <typename T, T MOD>\n\
    std::optional<Mint<T, MOD>> mod_sqrt(Mint<T, MOD> a) {\n    if (a == 0) return\
    \ Mint<T, MOD>(0);\n    if (MOD == 2) return a;\n    if (!is_quadratic_residue(a))\
    \ return std::nullopt;\n\n    if (MOD % 4 == 3) {\n        return a.pow((MOD +\
    \ 1) / 4);\n    }\n\n    // Tonelli-Shanks\n    long long s = 0, q = MOD - 1;\n\
    \    while (q % 2 == 0) {\n        q /= 2;\n        s++;\n    }\n\n    // Find\
    \ a non-quadratic residue z\n    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \    Mint<T, MOD> z;\n    do {\n        z = rng() % MOD;\n    } while (is_quadratic_residue(z));\n\
    \n    long long m = s;\n    Mint<T, MOD> c = z.pow(q);\n    Mint<T, MOD> t = a.pow(q);\n\
    \    Mint<T, MOD> r = a.pow((q + 1) / 2);\n\n    while (t != 1) {\n        if\
    \ (t == 0) return Mint<T, MOD>(0);\n        long long i = 0;\n        Mint<T,\
    \ MOD> temp = t;\n        while (temp != 1) {\n            temp *= temp;\n   \
    \         i++;\n            if (i == m) return std::nullopt; // Should not happen\
    \ for quadratic residues\n        }\n\n        Mint<T, MOD> b = c.pow(1LL << (m\
    \ - i - 1));\n        m = i;\n        c = b * b;\n        t *= c;\n        r *=\
    \ b;\n    }\n    return r;\n}\n#line 5 \"library/formalpowerseries/Sqrt.hpp\"\n\
    \n// Computes the square root of a formal power series f.\n// Returns std::nullopt\
    \ if the square root does not exist.\ntemplate <typename FPS> std::optional<FPS>\
    \ sqrt(FPS f) {\n    using T = typename FPS::value_type;\n    f.shrink();\n  \
    \  if (f.size() == 0) {\n        return FPS(0);\n    }\n\n    int d = 0;\n   \
    \ while (d < f.size() && f[d] == 0) {\n        d++;\n    }\n    if (d == f.size())\
    \ {\n        return FPS(0);\n    }\n\n    if (d % 2 != 0) {\n        return std::nullopt;\n\
    \    }\n\n    f >>= d;\n\n    std::optional<T> s0 = mod_sqrt(f[0]);\n    if (!s0)\
    \ {\n        return std::nullopt;\n    }\n\n    FPS res(1, *s0);\n    int n =\
    \ 1;\n    constexpr int MX = FPS::max_size;\n    while (n < MX) {\n        n <<=\
    \ 1;\n        res = (res + f.pre(n) * res.inv(n)) / 2;\n    }\n    res.strict(MX);\n\
    \    res <<= (d / 2);\n    return res;\n}\n"
  code: "#pragma once\n#include \"library/formalpowerseries/Base.hpp\"\n#include \"\
    library/math/ModularSqrt.hpp\"\n#include <optional>\n\n// Computes the square\
    \ root of a formal power series f.\n// Returns std::nullopt if the square root\
    \ does not exist.\ntemplate <typename FPS> std::optional<FPS> sqrt(FPS f) {\n\
    \    using T = typename FPS::value_type;\n    f.shrink();\n    if (f.size() ==\
    \ 0) {\n        return FPS(0);\n    }\n\n    int d = 0;\n    while (d < f.size()\
    \ && f[d] == 0) {\n        d++;\n    }\n    if (d == f.size()) {\n        return\
    \ FPS(0);\n    }\n\n    if (d % 2 != 0) {\n        return std::nullopt;\n    }\n\
    \n    f >>= d;\n\n    std::optional<T> s0 = mod_sqrt(f[0]);\n    if (!s0) {\n\
    \        return std::nullopt;\n    }\n\n    FPS res(1, *s0);\n    int n = 1;\n\
    \    constexpr int MX = FPS::max_size;\n    while (n < MX) {\n        n <<= 1;\n\
    \        res = (res + f.pre(n) * res.inv(n)) / 2;\n    }\n    res.strict(MX);\n\
    \    res <<= (d / 2);\n    return res;\n}"
  dependsOn:
  - library/formalpowerseries/Base.hpp
  - library/util/Valarray.hpp
  - library/math/ModularSqrt.hpp
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  isVerificationFile: false
  path: library/formalpowerseries/Sqrt.hpp
  requiredBy: []
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/Sqrt.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/Sqrt.hpp
- /library/library/formalpowerseries/Sqrt.hpp.html
title: library/formalpowerseries/Sqrt.hpp
---
