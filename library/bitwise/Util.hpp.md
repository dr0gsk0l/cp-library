---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/And.hpp
    title: library/bitwise/And.hpp
  - icon: ':warning:'
    path: library/bitwise/Or.hpp
    title: library/bitwise/Or.hpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Ranked.hpp
    title: library/bitwise/Ranked.hpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Xor.hpp
    title: library/bitwise/Xor.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Base.hpp
    title: library/setpowerseries/Base.hpp
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Compose.hpp
    title: library/setpowerseries/Compose.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
    title: test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
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
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n"
  code: "#pragma once\nnamespace bitwise{\n  static int log2(int N){\n    int n=__builtin_ffs(N)-1;\n\
    \    assert((1<<n)==N);\n    return n;\n  }\n  static bool in(int S,int a){ return\
    \ (S>>a)&1; }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/bitwise/Util.hpp
  requiredBy:
  - library/setpowerseries/Base.hpp
  - library/setpowerseries/Compose.hpp
  - library/bitwise/Ranked.hpp
  - library/bitwise/Or.hpp
  - library/bitwise/And.hpp
  - library/bitwise/Xor.hpp
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  - test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - test/library-checker/Convolution/SubsetConvolution.test.cpp
  - test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
documentation_of: library/bitwise/Util.hpp
layout: document
redirect_from:
- /library/library/bitwise/Util.hpp
- /library/library/bitwise/Util.hpp.html
title: library/bitwise/Util.hpp
---
