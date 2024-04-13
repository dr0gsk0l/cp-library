---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/bitwise/And.cpp
    title: library/bitwise/And.cpp
  - icon: ':warning:'
    path: library/bitwise/Or.cpp
    title: library/bitwise/Or.cpp
  - icon: ':x:'
    path: library/bitwise/Ranked.cpp
    title: library/bitwise/Ranked.cpp
  - icon: ':x:'
    path: library/bitwise/Xor.cpp
    title: library/bitwise/Xor.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - icon: ':x:'
    path: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  - icon: ':x:'
    path: test/library-checker/Convolution/SubsetConvolution.test.cpp
    title: test/library-checker/Convolution/SubsetConvolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n"
  code: "#pragma once\nnamespace bitwise{\n  static int log2(int N){\n    int n=__builtin_ffs(N)-1;\n\
    \    assert((1<<n)==N);\n    return n;\n  }\n  static bool in(int S,int a){ return\
    \ (S>>a)&1; }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/bitwise/Util.cpp
  requiredBy:
  - library/bitwise/Xor.cpp
  - library/bitwise/Or.cpp
  - library/bitwise/And.cpp
  - library/bitwise/Ranked.cpp
  timestamp: '2024-04-13 18:46:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  - test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - test/library-checker/Convolution/SubsetConvolution.test.cpp
documentation_of: library/bitwise/Util.cpp
layout: document
redirect_from:
- /library/library/bitwise/Util.cpp
- /library/library/bitwise/Util.cpp.html
title: library/bitwise/Util.cpp
---
