---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.cpp
    title: library/bitwise/Util.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/And.cpp\"\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n\
    struct BitwiseAnd {\n    template <typename T> static void zeta(std::vector<T>\
    \ &A) {\n        int n = bitwise::log2(A.size());\n        REP_(k, n)\n      \
    \  REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] += A[S ^ (1 << k)];\n    }\n \
    \   template <typename T> static void mobius(std::vector<T> &A) {\n        int\
    \ n = bitwise::log2(A.size());\n        REP_(k, n)\n        REP_(S, 1 << n) if\
    \ (!bitwise::in(S, k)) A[S] -= A[S ^ (1 << k)];\n    }\n    template <typename\
    \ T>\n    static std::vector<T> convolution(std::vector<T> A, std::vector<T> B)\
    \ {\n        assert(A.size() == B.size());\n        zeta(A);\n        zeta(B);\n\
    \        REP_(i, A.size()) A[i] *= B[i];\n        mobius(A);\n        return A;\n\
    \    }\n};\n#undef REP_\n"
  code: "#pragma once\n#include \"library/bitwise/Util.cpp\"\n#define REP_(i, n) for\
    \ (int i = 0; i < (n); i++)\nstruct BitwiseAnd {\n    template <typename T> static\
    \ void zeta(std::vector<T> &A) {\n        int n = bitwise::log2(A.size());\n \
    \       REP_(k, n)\n        REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] += A[S\
    \ ^ (1 << k)];\n    }\n    template <typename T> static void mobius(std::vector<T>\
    \ &A) {\n        int n = bitwise::log2(A.size());\n        REP_(k, n)\n      \
    \  REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] -= A[S ^ (1 << k)];\n    }\n \
    \   template <typename T>\n    static std::vector<T> convolution(std::vector<T>\
    \ A, std::vector<T> B) {\n        assert(A.size() == B.size());\n        zeta(A);\n\
    \        zeta(B);\n        REP_(i, A.size()) A[i] *= B[i];\n        mobius(A);\n\
    \        return A;\n    }\n};\n#undef REP_"
  dependsOn:
  - library/bitwise/Util.cpp
  isVerificationFile: false
  path: library/bitwise/And.cpp
  requiredBy: []
  timestamp: '2024-05-26 19:55:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
documentation_of: library/bitwise/And.cpp
layout: document
redirect_from:
- /library/library/bitwise/And.cpp
- /library/library/bitwise/And.cpp.html
title: library/bitwise/And.cpp
---
