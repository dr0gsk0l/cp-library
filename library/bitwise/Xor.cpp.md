---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/bitwise/Util.cpp
    title: library/bitwise/Util.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/Xor.cpp\"\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n\
    #define RREP_(i, n) for (int i = (n)-1; i >= 0; i--)\nstruct BitwiseXor {\n  \
    \  template <typename T> static void zeta(std::vector<T> &A) {\n        const\
    \ int n = bitwise::log2(A.size());\n        REP_(i, n)\n        REP_(S, 1 << n)\
    \ {\n            if (bitwise::in(S, i))\n                continue;\n         \
    \   T x = A[S], y = A[S | (1 << i)];\n            A[S] -= y;\n            A[S\
    \ | (1 << i)] += x;\n        }\n    }\n    template <typename T> static void mobius(std::vector<T>\
    \ &A) {\n        const int n = bitwise::log2(A.size());\n        RREP_(i, n)\n\
    \        REP_(S, 1 << n) {\n            if (bitwise::in(S, i))\n             \
    \   continue;\n            T x = A[S], y = A[S | (1 << i)];\n            A[S]\
    \ += y;\n            A[S | (1 << i)] -= x;\n        }\n        T inv = T(1) /\
    \ (1 << n);\n        REP (S, 1 << n)\n            A[S] *= inv;\n    }\n    template\
    \ <typename T>\n    static std::vector<T> convolution(std::vector<T> A, std::vector<T>\
    \ B) {\n        zeta(A);\n        zeta(B);\n        REP (S, A.size())\n      \
    \      A[S] *= B[S];\n        mobius(A);\n        return A;\n    }\n};\n#undef\
    \ REP_\n#undef RREP_\n"
  code: "#pragma once\n#include \"library/bitwise/Util.cpp\"\n#define REP_(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int i = (n)-1; i >= 0; i--)\n\
    struct BitwiseXor {\n    template <typename T> static void zeta(std::vector<T>\
    \ &A) {\n        const int n = bitwise::log2(A.size());\n        REP_(i, n)\n\
    \        REP_(S, 1 << n) {\n            if (bitwise::in(S, i))\n             \
    \   continue;\n            T x = A[S], y = A[S | (1 << i)];\n            A[S]\
    \ -= y;\n            A[S | (1 << i)] += x;\n        }\n    }\n    template <typename\
    \ T> static void mobius(std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n\
    \        RREP_(i, n)\n        REP_(S, 1 << n) {\n            if (bitwise::in(S,\
    \ i))\n                continue;\n            T x = A[S], y = A[S | (1 << i)];\n\
    \            A[S] += y;\n            A[S | (1 << i)] -= x;\n        }\n      \
    \  T inv = T(1) / (1 << n);\n        REP (S, 1 << n)\n            A[S] *= inv;\n\
    \    }\n    template <typename T>\n    static std::vector<T> convolution(std::vector<T>\
    \ A, std::vector<T> B) {\n        zeta(A);\n        zeta(B);\n        REP (S,\
    \ A.size())\n            A[S] *= B[S];\n        mobius(A);\n        return A;\n\
    \    }\n};\n#undef REP_\n#undef RREP_"
  dependsOn:
  - library/bitwise/Util.cpp
  isVerificationFile: false
  path: library/bitwise/Xor.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
documentation_of: library/bitwise/Xor.cpp
layout: document
redirect_from:
- /library/library/bitwise/Xor.cpp
- /library/library/bitwise/Xor.cpp.html
title: library/bitwise/Xor.cpp
---
