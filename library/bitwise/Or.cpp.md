---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.cpp
    title: library/bitwise/Util.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/Or.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\nstruct\
    \ BitwiseOr{\n  template<typename T>\n  static void zeta(vector<T>& A){\n    int\
    \ n=bitwise::log2(A.size());\n    REP_(k,n)REP_(S,1<<n)if(bitwise::in(S,k))A[S]+=A[S^(1<<k)];\n\
    \  }\n  template<typename T>\n  static void mobius(vector<T>& A){\n    int n=bitwise::log2(A.size());\n\
    \    REP_(k,n)REP_(S,1<<n)if(bitwise::in(S,k))A[S]-=A[S^(1<<k)];\n  }\n  template<typename\
    \ T>\n  static vector<T> convolution(vector<T> A,vector<T> B){\n    assert(A.size()==B.size());\n\
    \    zeta(A);\n    zeta(B);\n    REP_(i,A.size())A[i]*=B[i];\n    mobius(A);\n\
    \    return A;\n  }\n};\n#undef REP_\n"
  code: "#pragma once\n#include \"library/bitwise/Util.cpp\"\n#define REP_(i,n) for(int\
    \ i=0;i<(n);i++)\nstruct BitwiseOr{\n  template<typename T>\n  static void zeta(vector<T>&\
    \ A){\n    int n=bitwise::log2(A.size());\n    REP_(k,n)REP_(S,1<<n)if(bitwise::in(S,k))A[S]+=A[S^(1<<k)];\n\
    \  }\n  template<typename T>\n  static void mobius(vector<T>& A){\n    int n=bitwise::log2(A.size());\n\
    \    REP_(k,n)REP_(S,1<<n)if(bitwise::in(S,k))A[S]-=A[S^(1<<k)];\n  }\n  template<typename\
    \ T>\n  static vector<T> convolution(vector<T> A,vector<T> B){\n    assert(A.size()==B.size());\n\
    \    zeta(A);\n    zeta(B);\n    REP_(i,A.size())A[i]*=B[i];\n    mobius(A);\n\
    \    return A;\n  }\n};\n#undef REP_"
  dependsOn:
  - library/bitwise/Util.cpp
  isVerificationFile: false
  path: library/bitwise/Or.cpp
  requiredBy: []
  timestamp: '2023-12-03 16:05:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/bitwise/Or.cpp
layout: document
redirect_from:
- /library/library/bitwise/Or.cpp
- /library/library/bitwise/Or.cpp.html
title: library/bitwise/Or.cpp
---
