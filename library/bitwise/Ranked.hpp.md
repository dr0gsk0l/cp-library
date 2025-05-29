---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.hpp
    title: library/bitwise/Util.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Base.hpp
    title: library/setpowerseries/Base.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Compose.hpp
    title: library/setpowerseries/Compose.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/SubsetConvolution.test.cpp
    title: test/library-checker/Convolution/SubsetConvolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
    title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.hpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/Ranked.hpp\"\n#define REP_(i, n) for (int i = 0; i < (n);\
    \ i++)\n#define RREP_(i, n) for (int i = (n) - 1; i >= 0; i--)\nclass BitwiseRanked\
    \ {\n    static int popcount(int S) { return __builtin_popcount(S); }\n\n  public:\n\
    \    template <typename T>\n    static std::vector<std::vector<T>> zeta(const\
    \ std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n     \
    \   std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));\n      \
    \  REP_(S, 1 << n) RA[S][popcount(S)] = A[S];\n        REP_(i, n)\n        REP_(S,\
    \ 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n + 1) RA[S |\
    \ (1 << i)][d] += RA[S][d];\n        return RA;\n    }\n    template <typename\
    \ T>\n    static std::vector<T> mobius(std::vector<std::vector<T>> RA) {\n   \
    \     const int n = bitwise::log2(RA.size());\n        REP_(i, n)\n        REP_(S,\
    \ 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n + 1) RA[S |\
    \ (1 << i)][d] -= RA[S][d];\n        std::vector<T> A(1 << n);\n        REP_(S,\
    \ 1 << n) A[S] = RA[S][popcount(S)];\n        return A;\n    }\n    template <typename\
    \ T>\n    static std::vector<T> convolution(const std::vector<T> &A,\n       \
    \                               const std::vector<T> &B) {\n        const int\
    \ n = bitwise::log2(A.size());\n        auto RA = zeta(A);\n        auto RB =\
    \ zeta(B);\n        REP_(S, 1 << n) {\n            auto &ra = RA[S], rb = RB[S];\n\
    \            RREP_(d, n + 1) {\n                ra[d] *= rb[0];\n            \
    \    REP_(i, d) ra[d] += ra[i] * rb[d - i];\n            }\n        }\n      \
    \  return mobius(RA);\n    }\n};\n#undef REP_\n#undef RREP_\n"
  code: "#pragma once\n#include \"library/bitwise/Util.hpp\"\n#define REP_(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int i = (n) - 1; i >= 0;\
    \ i--)\nclass BitwiseRanked {\n    static int popcount(int S) { return __builtin_popcount(S);\
    \ }\n\n  public:\n    template <typename T>\n    static std::vector<std::vector<T>>\
    \ zeta(const std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n\
    \        std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));\n \
    \       REP_(S, 1 << n) RA[S][popcount(S)] = A[S];\n        REP_(i, n)\n     \
    \   REP_(S, 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n +\
    \ 1) RA[S | (1 << i)][d] += RA[S][d];\n        return RA;\n    }\n    template\
    \ <typename T>\n    static std::vector<T> mobius(std::vector<std::vector<T>> RA)\
    \ {\n        const int n = bitwise::log2(RA.size());\n        REP_(i, n)\n   \
    \     REP_(S, 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n\
    \ + 1) RA[S | (1 << i)][d] -= RA[S][d];\n        std::vector<T> A(1 << n);\n \
    \       REP_(S, 1 << n) A[S] = RA[S][popcount(S)];\n        return A;\n    }\n\
    \    template <typename T>\n    static std::vector<T> convolution(const std::vector<T>\
    \ &A,\n                                      const std::vector<T> &B) {\n    \
    \    const int n = bitwise::log2(A.size());\n        auto RA = zeta(A);\n    \
    \    auto RB = zeta(B);\n        REP_(S, 1 << n) {\n            auto &ra = RA[S],\
    \ rb = RB[S];\n            RREP_(d, n + 1) {\n                ra[d] *= rb[0];\n\
    \                REP_(i, d) ra[d] += ra[i] * rb[d - i];\n            }\n     \
    \   }\n        return mobius(RA);\n    }\n};\n#undef REP_\n#undef RREP_"
  dependsOn:
  - library/bitwise/Util.hpp
  isVerificationFile: false
  path: library/bitwise/Ranked.hpp
  requiredBy:
  - library/setpowerseries/Compose.hpp
  - library/setpowerseries/Base.hpp
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Convolution/SubsetConvolution.test.cpp
  - test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
documentation_of: library/bitwise/Ranked.hpp
layout: document
redirect_from:
- /library/library/bitwise/Ranked.hpp
- /library/library/bitwise/Ranked.hpp.html
title: library/bitwise/Ranked.hpp
---
