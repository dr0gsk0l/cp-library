---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2971.test.cpp
    title: test/AOJ/2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_E.test.cpp
    title: test/AOJ/NTL_1_E.test.cpp
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
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Det.test.cpp
    title: test/library-checker/Matrix/Det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Inverse.test.cpp
    title: test/library-checker/Matrix/Inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Product.test.cpp
    title: test/library-checker/Matrix/Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/New/NumberOfSubsequence.test.cpp
    title: test/library-checker/New/NumberOfSubsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Convolution.test.cpp
    title: test/library-checker/Polynomial/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1502.test.cpp
    title: test/yukicoder/1502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/ExtraGCD.cpp\"\nusing ll=long long;\npair<ll,ll>\
    \ ext_gcd(ll a,ll b){\n  if(b==0)return {1,0};\n  auto [X,Y]=ext_gcd(b,a%b);\n\
    \  // bX + (a%b)Y = gcd(a,b)\n  // a%b = a - b(a/b)\n  // \u2234 aY + b(X-(a/b)Y)\
    \ = gcd(a,b)\n  ll x=Y,y=X-(a/b)*Y;\n  return {x,y};\n}\n"
  code: "#pragma once\nusing ll=long long;\npair<ll,ll> ext_gcd(ll a,ll b){\n  if(b==0)return\
    \ {1,0};\n  auto [X,Y]=ext_gcd(b,a%b);\n  // bX + (a%b)Y = gcd(a,b)\n  // a%b\
    \ = a - b(a/b)\n  // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n  ll x=Y,y=X-(a/b)*Y;\n\
    \  return {x,y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/ExtraGCD.cpp
  requiredBy:
  - library/mod/Modint.cpp
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1502.test.cpp
  - test/yukicoder/650.test.cpp
  - test/yukicoder/117.test.cpp
  - test/library-checker/Matrix/Product.test.cpp
  - test/library-checker/Matrix/Det.test.cpp
  - test/library-checker/Matrix/Inverse.test.cpp
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/New/NumberOfSubsequence.test.cpp
  - test/library-checker/Polynomial/Convolution.test.cpp
  - test/library-checker/Convolution/SubsetConvolution.test.cpp
  - test/library-checker/Convolution/BitwiseXorConvolution.test.cpp
  - test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/AOJ/2971.test.cpp
  - test/AOJ/NTL_1_E.test.cpp
documentation_of: library/math/ExtraGCD.cpp
layout: document
redirect_from:
- /library/library/math/ExtraGCD.cpp
- /library/library/math/ExtraGCD.cpp.html
title: library/math/ExtraGCD.cpp
---
