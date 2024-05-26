---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Ranked.cpp
    title: library/bitwise/Ranked.cpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.cpp
    title: library/bitwise/Util.cpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Base.cpp
    title: library/setpowerseries/Base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
    title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90
  bundledCode: "#line 1 \"library/setpowerseries/Compose.cpp\"\n// https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90\n\
    #line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static int log2(int\
    \ N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n    return n;\n\
    \  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line 3 \"library/bitwise/Ranked.cpp\"\
    \n#define REP_(i, n) for (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int\
    \ i = (n)-1; i >= 0; i--)\nclass BitwiseRanked {\n    static int popcount(int\
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
    \ 2 \"library/setpowerseries/Base.cpp\"\ntemplate <typename T> struct SetPowerSeries\
    \ : std::vector<T> {\n    using SPS = SetPowerSeries;\n    using value_type =\
    \ T;\n    using std::vector<T>::vector;\n    using std::vector<T>::resize;\n \
    \   using std::vector<T>::at;\n    using std::vector<T>::size;\n\n    SetPowerSeries(const\
    \ std::vector<T> &f) {\n        resize(f.size());\n        for (int i = 0; i <\
    \ size(); i++)\n            at(i) = f[i];\n    }\n\n    SPS operator-() const\
    \ {\n        SPS ret(*this);\n        for (auto &a : ret)\n            a = -a;\n\
    \        return ret;\n    }\n\n    SPS &operator+=(const SPS &b) {\n        if\
    \ (size() < b.size())\n            resize(b.size(), 0);\n        for (int i =\
    \ 0; i < size(); i++)\n            at(i) += b[i];\n        return *this;\n   \
    \ }\n    SPS operator+(const SPS &b) const { return SPS(*this) += b; }\n\n   \
    \ SPS &operator-=(const SPS &b) {\n        if (size() < b.size())\n          \
    \  resize(b.size(), 0);\n        for (int i = 0; i < size(); i++)\n          \
    \  at(i) -= b[i];\n        return *this;\n    }\n    SPS operator-(const SPS &b)\
    \ const { return SPS(*this) -= b; }\n\n    SPS operator*(const SPS &b) const {\n\
    \        return SPS(BitwiseRanked::convolution<T>(*this, b));\n    }\n    SPS\
    \ &operator*=(const SPS &b) { return (*this) = (*this) * b; }\n};\n#line 3 \"\
    library/setpowerseries/Compose.cpp\"\n#include <vector>\n\ntemplate <typename\
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
    \ SPS_composition(lg, SPS(1, 1) - a);\n}\n"
  code: "// https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90\n\
    #include \"library/setpowerseries/Base.cpp\"\n#include <vector>\n\ntemplate <typename\
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
    \ SPS_composition(lg, SPS(1, 1) - a);\n}\n"
  dependsOn:
  - library/setpowerseries/Base.cpp
  - library/bitwise/Ranked.cpp
  - library/bitwise/Util.cpp
  isVerificationFile: false
  path: library/setpowerseries/Compose.cpp
  requiredBy: []
  timestamp: '2024-05-26 19:55:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
documentation_of: library/setpowerseries/Compose.cpp
layout: document
redirect_from:
- /library/library/setpowerseries/Compose.cpp
- /library/library/setpowerseries/Compose.cpp.html
title: library/setpowerseries/Compose.cpp
---
