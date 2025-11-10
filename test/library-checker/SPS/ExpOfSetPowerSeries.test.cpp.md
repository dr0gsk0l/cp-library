---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Ranked.hpp
    title: library/bitwise/Ranked.hpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.hpp
    title: library/bitwise/Util.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Base.hpp
    title: library/setpowerseries/Base.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Compose.hpp
    title: library/setpowerseries/Compose.hpp
  - icon: ':question:'
    path: library/util/Valarray.hpp
    title: library/util/Valarray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "#line 1 \"test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\n\
    #include <bits/stdc++.h>\n\n#include <atcoder/convolution>\n#include <atcoder/modint>\n\
    using namespace atcoder;\nusing mint = modint998244353;\nnamespace atcoder {\n\
    std::ostream &operator<<(std::ostream &os, mint a) {\n    os << a.val();\n   \
    \ return os;\n}\nstd::istream &operator>>(std::istream &is, mint &a) {\n    long\
    \ long b;\n    is >> b;\n    a = b;\n    return is;\n}\n} // namespace atcoder\n\
    \n#line 1 \"library/setpowerseries/Compose.hpp\"\n// https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90\n\
    #line 2 \"library/bitwise/Util.hpp\"\nnamespace bitwise{\n  static int log2(int\
    \ N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n    return n;\n\
    \  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line 3 \"library/bitwise/Ranked.hpp\"\
    \n#define REP_(i, n) for (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int\
    \ i = (n) - 1; i >= 0; i--)\nclass BitwiseRanked {\n    static int popcount(int\
    \ S) { return __builtin_popcount(S); }\n\n  public:\n    template <typename T>\n\
    \    static std::vector<std::vector<T>> zeta(const std::vector<T> &A) {\n    \
    \    const int n = bitwise::log2(A.size());\n        std::vector<std::vector<T>>\
    \ RA(1 << n, std::vector<T>(n + 1, 0));\n        REP_(S, 1 << n) RA[S][popcount(S)]\
    \ = A[S];\n        REP_(i, n)\n        REP_(S, 1 << n)\n        if (!bitwise::in(S,\
    \ i))\n            REP_(d, n + 1) RA[S | (1 << i)][d] += RA[S][d];\n        return\
    \ RA;\n    }\n    template <typename T>\n    static std::vector<T> mobius(std::vector<std::vector<T>>\
    \ RA) {\n        const int n = bitwise::log2(RA.size());\n        REP_(i, n)\n\
    \        REP_(S, 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d,\
    \ n + 1) RA[S | (1 << i)][d] -= RA[S][d];\n        std::vector<T> A(1 << n);\n\
    \        REP_(S, 1 << n) A[S] = RA[S][popcount(S)];\n        return A;\n    }\n\
    \    template <typename T>\n    static std::vector<T> convolution(const std::vector<T>\
    \ &A,\n                                      const std::vector<T> &B) {\n    \
    \    const int n = bitwise::log2(A.size());\n        auto RA = zeta(A);\n    \
    \    auto RB = zeta(B);\n        REP_(S, 1 << n) {\n            auto &ra = RA[S],\
    \ rb = RB[S];\n            RREP_(d, n + 1) {\n                ra[d] *= rb[0];\n\
    \                REP_(i, d) ra[d] += ra[i] * rb[d - i];\n            }\n     \
    \   }\n        return mobius(RA);\n    }\n};\n#undef REP_\n#undef RREP_\n#line\
    \ 2 \"library/util/Valarray.hpp\"\n#include <ranges>\n#line 4 \"library/util/Valarray.hpp\"\
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
    \ 4 \"library/setpowerseries/Base.hpp\"\n\ntemplate <typename T> struct SetPowerSeries\
    \ : Valarray<T> {\n    using SPS = SetPowerSeries;\n    using Valarray<T>::Valarray;\n\
    \    using Valarray<T>::size;\n    using Valarray<T>::at;\n    using value_type\
    \ = T;\n\n    SetPowerSeries(const std::vector<T> &f) : Valarray<T>(f) {}\n\n\
    \    SPS operator*(const SPS &b) const {\n        return SPS(BitwiseRanked::convolution<T>(*this,\
    \ b));\n    }\n    SPS &operator*=(const SPS &b) { return (*this) = (*this) *\
    \ b; }\n};\n#line 4 \"library/setpowerseries/Compose.hpp\"\n\ntemplate <typename\
    \ SPS, typename T = typename SPS::value_type>\nSPS SPS_exp_comp(const std::vector<T>\
    \ &f, const SPS &a) {\n    int N = a.size();\n    int n = bitwise::log2(N);\n\n\
    \    std::vector<SPS> ret(n + 1);\n    for (int d = n; d >= 0; d--) {\n      \
    \  ret[d].resize(1 << (n - d));\n        ret[d][0] = f[d];\n        for (int m\
    \ = 0; m < n - d; m++) {\n            // ret[d] \u306E [2^m, 2^{m+1}] \u3092\u6C42\
    \u3081\u308B\n            SPS pre(ret[d + 1].begin(), ret[d + 1].begin() + (1\
    \ << m));\n            SPS a2(a.begin() + (1 << m), a.begin() + (1 << (m + 1)));\n\
    \            pre *= a2;\n            std::ranges::copy(pre, ret[d].begin() + (1\
    \ << m));\n        }\n    }\n    return ret[0];\n}\n\n// sum_k f_k a^k\ntemplate\
    \ <typename SPS, typename T = typename SPS::value_type>\nSPS SPS_composition(const\
    \ std::vector<T> &f, SPS a) {\n    int N = a.size();\n    int n = bitwise::log2(N);\n\
    \n    std::vector<T> c_pow(f.size() + 1, 1);\n    for (int i = 1; i <= f.size();\
    \ i++)\n        c_pow[i] = c_pow[i - 1] * a[0];\n\n    std::vector<T> f2(n + 1,\
    \ 0);\n    for (int i = 0; i < f.size(); i++) {\n        T now = f[i];\n     \
    \   for (int k = 0; k <= std::min(i, n); k++) {\n            f2[k] += now * c_pow[i\
    \ - k];\n            now *= i - k;\n        }\n    }\n    a[0] = 0;\n    return\
    \ SPS_exp_comp(f2, a);\n}\n\ntemplate <typename SPS, typename T = typename SPS::value_type>\
    \ SPS exp(SPS a) {\n    int N = a.size();\n    int n = bitwise::log2(N);\n\n \
    \   SPS ret(N, 1);\n    for (int d = n - 1; d >= 0; d--) {\n        const int\
    \ M = 1 << (n - d - 1);\n        SPS pre(ret.begin(), ret.begin() + M);\n    \
    \    SPS a2(a.begin() + M, a.begin() + 2 * M);\n        pre *= a2;\n        std::ranges::copy(pre,\
    \ ret.begin() + M);\n    }\n    return ret;\n}\n\ntemplate <typename SPS, typename\
    \ T = typename SPS::value_type> SPS log(SPS a) {\n    int n = bitwise::log2(a.size());\n\
    \    assert((1 << n) == a.size() and a[0] == 1);\n    std::vector<T> lg(n + 1,\
    \ 0);\n    for (int k = 1; k <= n; k++)\n        lg[k] = T(-1) / k;\n    return\
    \ SPS_composition(lg, SPS(1, 1) - a);\n}\n#line 22 \"test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp\"\
    \nusing SPS = SetPowerSeries<mint>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n\n    SPS b(1 <<\
    \ n);\n    for (auto &x : b)\n        std::cin >> x;\n\n    SPS c = exp(b);\n\
    \    for (auto &x : c)\n        std::cout << x << \" \";\n    std::cout << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n#include <bits/stdc++.h>\n\n#include <atcoder/convolution>\n#include <atcoder/modint>\n\
    using namespace atcoder;\nusing mint = modint998244353;\nnamespace atcoder {\n\
    std::ostream &operator<<(std::ostream &os, mint a) {\n    os << a.val();\n   \
    \ return os;\n}\nstd::istream &operator>>(std::istream &is, mint &a) {\n    long\
    \ long b;\n    is >> b;\n    a = b;\n    return is;\n}\n} // namespace atcoder\n\
    \n#include \"library/setpowerseries/Compose.hpp\"\nusing SPS = SetPowerSeries<mint>;\n\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n\n    SPS b(1 << n);\n    for (auto &x : b)\n\
    \        std::cin >> x;\n\n    SPS c = exp(b);\n    for (auto &x : c)\n      \
    \  std::cout << x << \" \";\n    std::cout << std::endl;\n}"
  dependsOn:
  - library/setpowerseries/Compose.hpp
  - library/setpowerseries/Base.hpp
  - library/bitwise/Ranked.hpp
  - library/bitwise/Util.hpp
  - library/util/Valarray.hpp
  isVerificationFile: true
  path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  requiredBy: []
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
- /verify/test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp.html
title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
---
