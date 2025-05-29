---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
  - icon: ':question:'
    path: library/mod/Modint.hpp
    title: library/mod/Modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"library/convolution/NTT.hpp\"\n#define REP_(i,\
    \ n) for (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int i = (n)-1; i\
    \ >= 0; i--)\n\ntemplate <typename MINT>\nstd::vector<MINT> convolution(std::vector<MINT>\
    \ f, std::vector<MINT> g) {\n    int nf = f.size(), ng = g.size();\n    if (!nf\
    \ or !ng)\n        return std::vector<MINT>{};\n    int M = nf + ng - 1;\n\n \
    \   if (nf <= 60 or ng <= 60) {\n        std::vector<MINT> res(M, 0);\n      \
    \  REP_(i, nf) REP_(j, ng) res[i + j] += f[i] * g[j];\n        return res;\n \
    \   }\n\n    int lg;\n    for (lg = 0; (1 << lg) < M; lg++) {\n    }\n    const\
    \ int N = 1 << lg;\n    f.resize(N, 0);\n    g.resize(N, 0);\n\n    static_assert(MINT::mod\
    \ == 998244353);\n    MINT c = MINT(3).pow((MINT::mod - 1) >> lg);\n    std::vector<MINT>\
    \ cs(N);\n    REP_(i, N) cs[i] = (i ? cs[i - 1] * c : 1);\n\n    std::vector<int>\
    \ x(N, 0);\n    REP_(h, lg)\n    REP_(S, 1 << h)\n    REP_(T, 1 << (lg - h - 1))\
    \ {\n        int l = (S << (lg - h)) | T;\n        int r = l | (1 << (lg - h -\
    \ 1));\n\n        x[l] >>= 1;\n        (x[r] >>= 1) |= 1 << (lg - 1);\n\n    \
    \    MINT a = f[l];\n        f[l] += f[r] * cs[x[l]];\n        (f[r] *= cs[x[r]])\
    \ += a;\n\n        a = g[l];\n        g[l] += g[r] * cs[x[l]];\n        (g[r]\
    \ *= cs[x[r]]) += a;\n    }\n    REP_(i, N) f[i] *= g[i];\n\n    std::ranges::fill(x,\
    \ 0);\n    c = c.inv();\n    REP_(i, N) cs[i] = (i ? cs[i - 1] * c : 1);\n   \
    \ RREP_(h, lg)\n    REP_(S, 1 << h)\n    REP_(T, 1 << (lg - h - 1)) {\n      \
    \  int l = (S << (lg - h)) | T;\n        int r = l | (1 << (lg - h - 1));\n\n\
    \        x[l] >>= 1;\n        (x[r] >>= 1) |= 1 << (lg - 1);\n\n        MINT a\
    \ = f[l];\n        f[l] += f[r] * cs[x[l]];\n        (f[r] *= cs[x[r]]) += a;\n\
    \    }\n    f.resize(M);\n    MINT Ninv = MINT(N).inv();\n    REP_(i, M) f[i]\
    \ *= Ninv;\n    return f;\n}\n#undef REP_\n#undef RREP_\n#line 2 \"library/math/ExtraGCD.hpp\"\
    \nusing ll = long long;\nstd::pair<ll, ll> ext_gcd(ll a, ll b) {\n    if (b ==\
    \ 0)\n        return {1, 0};\n    auto [X, Y] = ext_gcd(b, a % b);\n    // bX\
    \ + (a%b)Y = gcd(a,b)\n    // a%b = a - b(a/b)\n    // \u2234 aY + b(X-(a/b)Y)\
    \ = gcd(a,b)\n    ll x = Y, y = X - (a / b) * Y;\n    return {x, y};\n}\n#line\
    \ 3 \"library/mod/Modint.hpp\"\ntemplate <typename T, T MOD = 998244353> struct\
    \ Mint {\n    inline static constexpr T mod = MOD;\n    T v;\n    Mint() : v(0)\
    \ {}\n    Mint(signed v) : v(v) {}\n    Mint(long long t) {\n        v = t % MOD;\n\
    \        if (v < 0)\n            v += MOD;\n    }\n\n    static Mint raw(int v)\
    \ {\n        Mint x;\n        x.v = v;\n        return x;\n    }\n\n    Mint pow(long\
    \ long k) const {\n        Mint res(1), tmp(v);\n        while (k) {\n       \
    \     if (k & 1)\n                res *= tmp;\n            tmp *= tmp;\n     \
    \       k >>= 1;\n        }\n        return res;\n    }\n\n    static Mint add_identity()\
    \ { return Mint(0); }\n    static Mint mul_identity() { return Mint(1); }\n\n\
    \    // Mint inv()const{return pow(MOD-2);}\n    Mint inv() const { return Mint(ext_gcd(v,\
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
    \ is;\n    }\n};\n#line 6 \"test/library-checker/Polynomial/Convolution.test.cpp\"\
    \n\nusing mint = Mint<long long, 998244353>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ f(n), g(m);\n    for (mint &p : f)\n        std::cin >> p;\n    for (mint &p\
    \ : g)\n        std::cin >> p;\n    auto h = convolution(f, g);\n    for (mint\
    \ &p : h)\n        std::cout << p << \" \";\n    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"library/convolution/NTT.hpp\"\n#include \"library/mod/Modint.hpp\"\
    \n\nusing mint = Mint<long long, 998244353>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ f(n), g(m);\n    for (mint &p : f)\n        std::cin >> p;\n    for (mint &p\
    \ : g)\n        std::cin >> p;\n    auto h = convolution(f, g);\n    for (mint\
    \ &p : h)\n        std::cout << p << \" \";\n    std::cout << std::endl;\n}"
  dependsOn:
  - library/convolution/NTT.hpp
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/Convolution.test.cpp
  requiredBy: []
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Convolution.test.cpp
- /verify/test/library-checker/Polynomial/Convolution.test.cpp.html
title: test/library-checker/Polynomial/Convolution.test.cpp
---
