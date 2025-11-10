---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.hpp
    title: library/bitwise/Util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.hpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/Or.hpp\"\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n\
    struct BitwiseOr {\n    template <typename T> static void zeta(std::vector<T>\
    \ &A) {\n        int n = bitwise::log2(A.size());\n        REP_(k, n)\n      \
    \  REP_(S, 1 << n) if (bitwise::in(S, k)) A[S] += A[S ^ (1 << k)];\n    }\n  \
    \  template <typename T> static void mobius(std::vector<T> &A) {\n        int\
    \ n = bitwise::log2(A.size());\n        REP_(k, n)\n        REP_(S, 1 << n) if\
    \ (bitwise::in(S, k)) A[S] -= A[S ^ (1 << k)];\n    }\n    template <typename\
    \ T>\n    static std::vector<T> convolution(std::vector<T> A, std::vector<T> B)\
    \ {\n        assert(A.size() == B.size());\n        zeta(A);\n        zeta(B);\n\
    \        REP_(i, A.size()) A[i] *= B[i];\n        mobius(A);\n        return A;\n\
    \    }\n};\n#undef REP_\n"
  code: "#pragma once\n#include \"library/bitwise/Util.hpp\"\n#define REP_(i, n) for\
    \ (int i = 0; i < (n); i++)\nstruct BitwiseOr {\n    template <typename T> static\
    \ void zeta(std::vector<T> &A) {\n        int n = bitwise::log2(A.size());\n \
    \       REP_(k, n)\n        REP_(S, 1 << n) if (bitwise::in(S, k)) A[S] += A[S\
    \ ^ (1 << k)];\n    }\n    template <typename T> static void mobius(std::vector<T>\
    \ &A) {\n        int n = bitwise::log2(A.size());\n        REP_(k, n)\n      \
    \  REP_(S, 1 << n) if (bitwise::in(S, k)) A[S] -= A[S ^ (1 << k)];\n    }\n  \
    \  template <typename T>\n    static std::vector<T> convolution(std::vector<T>\
    \ A, std::vector<T> B) {\n        assert(A.size() == B.size());\n        zeta(A);\n\
    \        zeta(B);\n        REP_(i, A.size()) A[i] *= B[i];\n        mobius(A);\n\
    \        return A;\n    }\n};\n#undef REP_"
  dependsOn:
  - library/bitwise/Util.hpp
  isVerificationFile: false
  path: library/bitwise/Or.hpp
  requiredBy: []
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/bitwise/Or.hpp
layout: document
redirect_from:
- /library/library/bitwise/Or.hpp
- /library/library/bitwise/Or.hpp.html
title: library/bitwise/Or.hpp
---
