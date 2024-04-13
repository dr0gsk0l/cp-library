---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  - icon: ':heavy_check_mark:'
    path: library/util/Subsequence.cpp
    title: "\u90E8\u5206\u5217\u306E\u7A2E\u985E\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"test/library-checker/New/NumberOfSubsequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"library/math/ExtraGCD.cpp\"\nusing ll = long long;\n\
    std::pair<ll, ll> ext_gcd(ll a, ll b) {\n    if (b == 0)\n        return {1, 0};\n\
    \    auto [X, Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b\
    \ = a - b(a/b)\n    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X\
    \ - (a / b) * Y;\n    return {x, y};\n}\n#line 3 \"library/mod/Modint.cpp\"\n\
    template <typename T, T MOD = 998244353> struct Mint {\n    inline static constexpr\
    \ T mod = MOD;\n    T v;\n    Mint() : v(0) {}\n    Mint(signed v) : v(v) {}\n\
    \    Mint(long long t) {\n        v = t % MOD;\n        if (v < 0)\n         \
    \   v += MOD;\n    }\n\n    static Mint raw(int v) {\n        Mint x;\n      \
    \  x.v = v;\n        return x;\n    }\n\n    Mint pow(long long k) const {\n \
    \       Mint res(1), tmp(v);\n        while (k) {\n            if (k & 1)\n  \
    \              res *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n  \
    \      }\n        return res;\n    }\n\n    static Mint add_identity() { return\
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
    \ is;\n    }\n};\n#line 1 \"library/util/Subsequence.cpp\"\ntemplate <typename\
    \ T, typename U>\nT sparse_subsequence(const std::vector<U> &v) {\n    std::map<U,\
    \ T> mp;\n    T res = 1;\n    for (const U &p : v) {\n        T tmp = res;\n \
    \       res = res * 2 - mp[p];\n        mp[p] = tmp;\n    }\n    return res;\n\
    }\ntemplate <typename T, int SIZE> T subsequence(const std::vector<int> &v) {\n\
    \    std::vector<T> memo(SIZE, 0);\n    T res = 1;\n    for (int p : v) {\n  \
    \      T tmp = res;\n        res = res * 2 - memo[p];\n        memo[p] = tmp;\n\
    \    }\n    return res;\n}\ntemplate <typename T> T subsequence_alphabet(const\
    \ std::string &s) {\n    std::vector<int> v;\n    v.reserve(s.size());\n    for\
    \ (char c : s)\n        v.push_back(c - (c <= 'Z' ? 'A' : 'a'));\n    return subsequence<T,\
    \ 26>(v);\n}\n#line 6 \"test/library-checker/New/NumberOfSubsequence.test.cpp\"\
    \nusing mint = Mint<long long>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    std::vector<int>\
    \ v(n);\n    for (int i = 0; i < n; i++)\n        std::cin >> v[i];\n    std::cout\
    \ << sparse_subsequence<mint, int>(v) - 1 << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/mod/Modint.cpp\"\n#include \"\
    library/util/Subsequence.cpp\"\nusing mint = Mint<long long>;\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n;\n    std::cin >> n;\n    std::vector<int> v(n);\n    for (int i = 0; i <\
    \ n; i++)\n        std::cin >> v[i];\n    std::cout << sparse_subsequence<mint,\
    \ int>(v) - 1 << std::endl;\n}"
  dependsOn:
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  - library/util/Subsequence.cpp
  isVerificationFile: true
  path: test/library-checker/New/NumberOfSubsequence.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/New/NumberOfSubsequence.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/New/NumberOfSubsequence.test.cpp
- /verify/test/library-checker/New/NumberOfSubsequence.test.cpp.html
title: test/library-checker/New/NumberOfSubsequence.test.cpp
---
