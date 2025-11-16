---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
  - icon: ':question:'
    path: library/mod/Modint.hpp
    title: library/mod/Modint.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/formalpowerseries/Sqrt.hpp
    title: library/formalpowerseries/Sqrt.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/ExtraGCD.hpp\"\nusing ll = long long;\nstd::pair<ll,\
    \ ll> ext_gcd(ll a, ll b) {\n    if (b == 0)\n        return {1, 0};\n    auto\
    \ [X, Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b = a -\
    \ b(a/b)\n    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X - (a\
    \ / b) * Y;\n    return {x, y};\n}\n#line 3 \"library/mod/Modint.hpp\"\ntemplate\
    \ <typename T, T MOD = 998244353> struct Mint {\n    inline static constexpr T\
    \ mod = MOD;\n    T v;\n    Mint() : v(0) {}\n    Mint(signed v) : v(v) {}\n \
    \   Mint(long long t) {\n        v = t % MOD;\n        if (v < 0)\n          \
    \  v += MOD;\n    }\n\n    static Mint raw(int v) {\n        Mint x;\n       \
    \ x.v = v;\n        return x;\n    }\n\n    Mint pow(long long k) const {\n  \
    \      Mint res(1), tmp(v);\n        while (k) {\n            if (k & 1)\n   \
    \             res *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    static Mint add_identity() { return\
    \ Mint(0); }\n    static Mint mul_identity() { return Mint(1); }\n\n    // Mint\
    \ inv()const{return pow(MOD-2);}\n    Mint inv() const { return Mint(ext_gcd(v,\
    \ mod).first); }\n\n    Mint &operator+=(Mint a) {\n        v += a.v;\n      \
    \  if (v >= MOD)\n            v -= MOD;\n        return *this;\n    }\n    Mint\
    \ &operator-=(Mint a) {\n        v += MOD - a.v;\n        if (v >= MOD)\n    \
    \        v -= MOD;\n        return *this;\n    }\n    Mint &operator*=(Mint a)\
    \ {\n        v = 1LL * v * a.v % MOD;\n        return *this;\n    }\n    Mint\
    \ &operator/=(Mint a) { return (*this) *= a.inv(); }\n\n    Mint operator+(Mint\
    \ a) const { return Mint(v) += a; }\n    Mint operator-(Mint a) const { return\
    \ Mint(v) -= a; }\n    Mint operator*(Mint a) const { return Mint(v) *= a; }\n\
    \    Mint operator/(Mint a) const { return Mint(v) /= a; }\n#define FRIEND(op)\
    \                                                             \\\n    friend Mint\
    \ operator op(int a, Mint b) { return Mint(a) op b; }\n    FRIEND(+);\n    FRIEND(-);\n\
    \    FRIEND(*);\n    FRIEND(/);\n#undef FRIEND\n    Mint operator+() const { return\
    \ *this; }\n    Mint operator-() const { return v ? Mint(MOD - v) : Mint(v); }\n\
    \n    bool operator==(const Mint a) const { return v == a.v; }\n    bool operator!=(const\
    \ Mint a) const { return v != a.v; }\n\n    static Mint comb(long long n, int\
    \ k) {\n        Mint num(1), dom(1);\n        for (int i = 0; i < k; i++) {\n\
    \            num *= Mint(n - i);\n            dom *= Mint(i + 1);\n        }\n\
    \        return num / dom;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Mint &m) {\n        os << m.v;\n        return os;\n    }\n    friend\
    \ std::istream &operator>>(std::istream &is, Mint &m) {\n        is >> m.v;\n\
    \        m.v %= MOD;\n        if (m.v < 0)\n            m.v += MOD;\n        return\
    \ is;\n    }\n};\n#line 3 \"library/math/ModularSqrt.hpp\"\n#include <optional>\n\
    #include <random>\n#include <chrono>\n\ntemplate <typename T, T MOD>\nbool is_quadratic_residue(Mint<T,\
    \ MOD> a) {\n    if (a == 0) return true;\n    return a.pow((MOD - 1) / 2) ==\
    \ 1;\n}\n\ntemplate <typename T, T MOD>\nstd::optional<Mint<T, MOD>> mod_sqrt(Mint<T,\
    \ MOD> a) {\n    if (a == 0) return Mint<T, MOD>(0);\n    if (MOD == 2) return\
    \ a;\n    if (!is_quadratic_residue(a)) return std::nullopt;\n\n    if (MOD %\
    \ 4 == 3) {\n        return a.pow((MOD + 1) / 4);\n    }\n\n    // Tonelli-Shanks\n\
    \    long long s = 0, q = MOD - 1;\n    while (q % 2 == 0) {\n        q /= 2;\n\
    \        s++;\n    }\n\n    // Find a non-quadratic residue z\n    std::mt19937_64\
    \ rng(std::chrono::steady_clock::now().time_since_epoch().count());\n    Mint<T,\
    \ MOD> z;\n    do {\n        z = rng() % MOD;\n    } while (is_quadratic_residue(z));\n\
    \n    long long m = s;\n    Mint<T, MOD> c = z.pow(q);\n    Mint<T, MOD> t = a.pow(q);\n\
    \    Mint<T, MOD> r = a.pow((q + 1) / 2);\n\n    while (t != 1) {\n        if\
    \ (t == 0) return Mint<T, MOD>(0);\n        long long i = 0;\n        Mint<T,\
    \ MOD> temp = t;\n        while (temp != 1) {\n            temp *= temp;\n   \
    \         i++;\n            if (i == m) return std::nullopt; // Should not happen\
    \ for quadratic residues\n        }\n\n        Mint<T, MOD> b = c.pow(1LL << (m\
    \ - i - 1));\n        m = i;\n        c = b * b;\n        t *= c;\n        r *=\
    \ b;\n    }\n    return r;\n}\n"
  code: "#pragma once\n#include \"library/mod/Modint.hpp\"\n#include <optional>\n\
    #include <random>\n#include <chrono>\n\ntemplate <typename T, T MOD>\nbool is_quadratic_residue(Mint<T,\
    \ MOD> a) {\n    if (a == 0) return true;\n    return a.pow((MOD - 1) / 2) ==\
    \ 1;\n}\n\ntemplate <typename T, T MOD>\nstd::optional<Mint<T, MOD>> mod_sqrt(Mint<T,\
    \ MOD> a) {\n    if (a == 0) return Mint<T, MOD>(0);\n    if (MOD == 2) return\
    \ a;\n    if (!is_quadratic_residue(a)) return std::nullopt;\n\n    if (MOD %\
    \ 4 == 3) {\n        return a.pow((MOD + 1) / 4);\n    }\n\n    // Tonelli-Shanks\n\
    \    long long s = 0, q = MOD - 1;\n    while (q % 2 == 0) {\n        q /= 2;\n\
    \        s++;\n    }\n\n    // Find a non-quadratic residue z\n    std::mt19937_64\
    \ rng(std::chrono::steady_clock::now().time_since_epoch().count());\n    Mint<T,\
    \ MOD> z;\n    do {\n        z = rng() % MOD;\n    } while (is_quadratic_residue(z));\n\
    \n    long long m = s;\n    Mint<T, MOD> c = z.pow(q);\n    Mint<T, MOD> t = a.pow(q);\n\
    \    Mint<T, MOD> r = a.pow((q + 1) / 2);\n\n    while (t != 1) {\n        if\
    \ (t == 0) return Mint<T, MOD>(0);\n        long long i = 0;\n        Mint<T,\
    \ MOD> temp = t;\n        while (temp != 1) {\n            temp *= temp;\n   \
    \         i++;\n            if (i == m) return std::nullopt; // Should not happen\
    \ for quadratic residues\n        }\n\n        Mint<T, MOD> b = c.pow(1LL << (m\
    \ - i - 1));\n        m = i;\n        c = b * b;\n        t *= c;\n        r *=\
    \ b;\n    }\n    return r;\n}\n"
  dependsOn:
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  isVerificationFile: false
  path: library/math/ModularSqrt.hpp
  requiredBy:
  - library/formalpowerseries/Sqrt.hpp
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/ModularSqrt.hpp
layout: document
redirect_from:
- /library/library/math/ModularSqrt.hpp
- /library/library/math/ModularSqrt.hpp.html
title: library/math/ModularSqrt.hpp
---
