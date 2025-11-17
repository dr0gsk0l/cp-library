---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/sequence/RollingHash.hpp
    title: library/sequence/RollingHash.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/mod/Modint61.hpp\"\n#include <utility>\nstruct Modint61\
    \ {\n    using ll = long long;\n    static constexpr ll MOD = (1LL << 61) - 1;\n\
    \    ll v;\n    Modint61(const ll x = 0) : v(x) {\n        if (v < 0 || v >= MOD)\
    \ {\n            v %= MOD;\n            if (v < 0)\n                v += MOD;\n\
    \        }\n    }\n    static Modint61 raw(ll v) {\n        Modint61 x;\n    \
    \    x.v = v;\n        return x;\n    }\n\n  private:\n    template <int d> static\
    \ constexpr std::pair<ll, ll> divide(const ll &a) {\n        return {a >> d, a\
    \ & ((1LL << d) - 1)};\n    }\n\n  public:\n    Modint61 pow(long long k) {\n\
    \        Modint61 res(1), tmp(v);\n        while (k) {\n            if (k & 1)\n\
    \                res *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n\n    Modint61 inv() { return pow(MOD\
    \ - 2); }\n\n    Modint61 &operator+=(Modint61 a) {\n        v += a.v;\n     \
    \   if (v >= MOD)\n            v -= MOD;\n        return *this;\n    }\n    Modint61\
    \ &operator-=(Modint61 a) {\n        v += MOD - a.v;\n        if (v >= MOD)\n\
    \            v -= MOD;\n        return *this;\n    }\n    Modint61 &operator*=(Modint61\
    \ a) {\n        const auto [vu, vd] = divide<31>(v);\n        const auto [au,\
    \ ad] = divide<31>(a.v);\n        ll x = vd * au + vu * ad;\n        const auto\
    \ [xu, xd] = divide<30>(x);\n        v = vu * au * 2 + xu + (xd << 31) + vd *\
    \ ad;\n        if (v >= MOD) {\n            const auto [vu2, vd2] = divide<61>(v);\n\
    \            v = vu2 + vd2;\n        }\n        if (v >= MOD)\n            v -=\
    \ MOD;\n        return *this;\n    }\n    Modint61 &operator/=(Modint61 a) { return\
    \ (*this) *= a.inv(); }\n    Modint61 operator+(Modint61 a) const { return Modint61(v)\
    \ += a; }\n    Modint61 operator-(Modint61 a) const { return Modint61(v) -= a;\
    \ }\n    Modint61 operator*(Modint61 a) const { return Modint61(v) *= a; }\n \
    \   Modint61 operator/(Modint61 a) const { return Modint61(v) /= a; }\n\n    Modint61\
    \ operator+() const { return *this; }\n    Modint61 operator-() const { return\
    \ v ? Modint61(MOD - v) : Modint61(v); }\n\n    bool operator==(const Modint61\
    \ a) const { return v == a.v; }\n    bool operator!=(const Modint61 a) const {\
    \ return v != a.v; }\n    bool operator<(const Modint61 a) const { return v <\
    \ a.v; }\n};\n"
  code: "#pragma once\n#include <utility>\nstruct Modint61 {\n    using ll = long\
    \ long;\n    static constexpr ll MOD = (1LL << 61) - 1;\n    ll v;\n    Modint61(const\
    \ ll x = 0) : v(x) {\n        if (v < 0 || v >= MOD) {\n            v %= MOD;\n\
    \            if (v < 0)\n                v += MOD;\n        }\n    }\n    static\
    \ Modint61 raw(ll v) {\n        Modint61 x;\n        x.v = v;\n        return\
    \ x;\n    }\n\n  private:\n    template <int d> static constexpr std::pair<ll,\
    \ ll> divide(const ll &a) {\n        return {a >> d, a & ((1LL << d) - 1)};\n\
    \    }\n\n  public:\n    Modint61 pow(long long k) {\n        Modint61 res(1),\
    \ tmp(v);\n        while (k) {\n            if (k & 1)\n                res *=\
    \ tmp;\n            tmp *= tmp;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    Modint61 inv() { return pow(MOD - 2); }\n\n    Modint61 &operator+=(Modint61\
    \ a) {\n        v += a.v;\n        if (v >= MOD)\n            v -= MOD;\n    \
    \    return *this;\n    }\n    Modint61 &operator-=(Modint61 a) {\n        v +=\
    \ MOD - a.v;\n        if (v >= MOD)\n            v -= MOD;\n        return *this;\n\
    \    }\n    Modint61 &operator*=(Modint61 a) {\n        const auto [vu, vd] =\
    \ divide<31>(v);\n        const auto [au, ad] = divide<31>(a.v);\n        ll x\
    \ = vd * au + vu * ad;\n        const auto [xu, xd] = divide<30>(x);\n       \
    \ v = vu * au * 2 + xu + (xd << 31) + vd * ad;\n        if (v >= MOD) {\n    \
    \        const auto [vu2, vd2] = divide<61>(v);\n            v = vu2 + vd2;\n\
    \        }\n        if (v >= MOD)\n            v -= MOD;\n        return *this;\n\
    \    }\n    Modint61 &operator/=(Modint61 a) { return (*this) *= a.inv(); }\n\
    \    Modint61 operator+(Modint61 a) const { return Modint61(v) += a; }\n    Modint61\
    \ operator-(Modint61 a) const { return Modint61(v) -= a; }\n    Modint61 operator*(Modint61\
    \ a) const { return Modint61(v) *= a; }\n    Modint61 operator/(Modint61 a) const\
    \ { return Modint61(v) /= a; }\n\n    Modint61 operator+() const { return *this;\
    \ }\n    Modint61 operator-() const { return v ? Modint61(MOD - v) : Modint61(v);\
    \ }\n\n    bool operator==(const Modint61 a) const { return v == a.v; }\n    bool\
    \ operator!=(const Modint61 a) const { return v != a.v; }\n    bool operator<(const\
    \ Modint61 a) const { return v < a.v; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/Modint61.hpp
  requiredBy:
  - library/sequence/RollingHash.hpp
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: library/mod/Modint61.hpp
layout: document
redirect_from:
- /library/library/mod/Modint61.hpp
- /library/library/mod/Modint61.hpp.html
title: library/mod/Modint61.hpp
---
