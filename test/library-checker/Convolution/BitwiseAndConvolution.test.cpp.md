---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/And.hpp
    title: library/bitwise/And.hpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.hpp
    title: library/bitwise/Util.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library-checker/Convolution/BitwiseAndConvolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n\
    #line 2 \"library/bitwise/Util.hpp\"\nnamespace bitwise{\n  static int log2(int\
    \ N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n    return n;\n\
    \  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line 3 \"library/bitwise/And.hpp\"\
    \n#define REP_(i, n) for (int i = 0; i < (n); i++)\nstruct BitwiseAnd {\n    template\
    \ <typename T> static void zeta(std::vector<T> &A) {\n        int n = bitwise::log2(A.size());\n\
    \        REP_(k, n)\n        REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] += A[S\
    \ ^ (1 << k)];\n    }\n    template <typename T> static void mobius(std::vector<T>\
    \ &A) {\n        int n = bitwise::log2(A.size());\n        REP_(k, n)\n      \
    \  REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] -= A[S ^ (1 << k)];\n    }\n \
    \   template <typename T>\n    static std::vector<T> convolution(std::vector<T>\
    \ A, std::vector<T> B) {\n        assert(A.size() == B.size());\n        zeta(A);\n\
    \        zeta(B);\n        REP_(i, A.size()) A[i] *= B[i];\n        mobius(A);\n\
    \        return A;\n    }\n};\n#undef REP_\n#line 2 \"library/math/ExtraGCD.hpp\"\
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
    \ is;\n    }\n};\n#line 8 \"test/library-checker/Convolution/BitwiseAndConvolution.test.cpp\"\
    \n\nusing mint = Mint<long long>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    int N = 1 <<\
    \ n;\n    std::vector<mint> a(N), b(N);\n    REP (i, N)\n        std::cin >> a[i];\n\
    \    REP (i, N)\n        std::cin >> b[i];\n    auto c = BitwiseAnd::convolution(a,\
    \ b);\n    REP (i, N)\n        std::cout << c[i] << \"\\n \"[i + 1 < N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include \"library/bitwise/And.hpp\"\n#include \"library/mod/Modint.hpp\"\n\n\
    using mint = Mint<long long>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    int N = 1 <<\
    \ n;\n    std::vector<mint> a(N), b(N);\n    REP (i, N)\n        std::cin >> a[i];\n\
    \    REP (i, N)\n        std::cin >> b[i];\n    auto c = BitwiseAnd::convolution(a,\
    \ b);\n    REP (i, N)\n        std::cout << c[i] << \"\\n \"[i + 1 < N];\n}"
  dependsOn:
  - library/bitwise/And.hpp
  - library/bitwise/Util.hpp
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  isVerificationFile: true
  path: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
- /verify/test/library-checker/Convolution/BitwiseAndConvolution.test.cpp.html
title: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
---
