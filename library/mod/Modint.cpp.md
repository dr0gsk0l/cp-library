---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2971.test.cpp
    title: test/AOJ/2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  - icon: ':x:'
    path: test/library-checker/Convolution/SubsetConvolution.test.cpp
    title: test/library-checker/Convolution/SubsetConvolution.test.cpp
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
    path: test/library-checker/Matrix/Det.test.cpp
    title: test/library-checker/Matrix/Det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Inverse.test.cpp
    title: test/library-checker/Matrix/Inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Product.test.cpp
    title: test/library-checker/Matrix/Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/New/NumberOfSubsequence.test.cpp
    title: test/library-checker/New/NumberOfSubsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Convolution.test.cpp
    title: test/library-checker/Polynomial/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1502.test.cpp
    title: test/yukicoder/1502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/ExtraGCD.cpp\"\nusing ll = long long;\nstd::pair<ll,\
    \ ll> ext_gcd(ll a, ll b) {\n    if (b == 0)\n        return {1, 0};\n    auto\
    \ [X, Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b = a -\
    \ b(a/b)\n    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X - (a\
    \ / b) * Y;\n    return {x, y};\n}\n#line 3 \"library/mod/Modint.cpp\"\ntemplate\
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
    \ is;\n    }\n};\n"
  code: "#pragma once\n#include \"library/math/ExtraGCD.cpp\"\ntemplate <typename\
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
    \ 0)\n            m.v += MOD;\n        return is;\n    }\n};"
  dependsOn:
  - library/math/ExtraGCD.cpp
  isVerificationFile: false
  path: library/mod/Modint.cpp
  requiredBy: []
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/New/NumberOfSubsequence.test.cpp
  - test/library-checker/Matrix/Inverse.test.cpp
  - test/library-checker/Matrix/Product.test.cpp
  - test/library-checker/Matrix/Det.test.cpp
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  - test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - test/library-checker/Convolution/SubsetConvolution.test.cpp
  - test/library-checker/Polynomial/Convolution.test.cpp
  - test/yukicoder/1502.test.cpp
  - test/yukicoder/650.test.cpp
  - test/yukicoder/117.test.cpp
  - test/AOJ/2971.test.cpp
documentation_of: library/mod/Modint.cpp
layout: document
redirect_from:
- /library/library/mod/Modint.cpp
- /library/library/mod/Modint.cpp.html
title: library/mod/Modint.cpp
---
