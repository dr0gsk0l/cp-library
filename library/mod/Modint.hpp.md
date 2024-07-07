---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/math/ExtraGCD.cpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: library/mod/Modint.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mod/Modint.hpp
layout: document
redirect_from:
- /library/library/mod/Modint.hpp
- /library/library/mod/Modint.hpp.html
title: library/mod/Modint.hpp
---
