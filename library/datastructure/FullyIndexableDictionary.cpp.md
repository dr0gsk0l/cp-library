---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':question:'
    path: library/datastructure/WaveletMatrix.cpp
    title: library/datastructure/WaveletMatrix.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeKthSmallest.test.cpp
    title: test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
    title: test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/datastructure/FullyIndexableDictionary.cpp\"\nclass\
    \ FullyIndexableDictionary{\n  int n,\n      block; // 64\u500B\u4E8B\u306B\u533A\
    \u5207\u3063\u305F\u30D6\u30ED\u30C3\u30AF\u306E\u500B\u6570\n  vector<unsigned\
    \ long long> bit;\n  vector<unsigned int> sum; // \u30D6\u30ED\u30C3\u30AF\u6BCE\
    \u306E\u7D2F\u7A4D\u548C\n  bool prepared;\npublic:\n  FullyIndexableDictionary(){}\n\
    \  FullyIndexableDictionary(int n)\n    :n(n),block((n+63)>>6),bit(block,0),sum(block+1,0),prepared(false){}\n\
    \n  bool is_prepared(){ return prepared; }\n\n  void set(int k){\n    bit[k>>6]|=1ull<<(k&63);\n\
    \    sum[(k>>6)+1]++;\n  }\n  void build(){ \n    assert(!prepared);\n    prepared=true;\n\
    \    for(int i=0;i<block;i++)sum[i+1]+=sum[i]; \n  }\n\n  bool operator[](int\
    \ k)const{\n    return bool((bit[k>>6]>>(k&63))&1);\n  }\n\n  // [0,j) \u306E\u5408\
    \u8A08\n  int rank(int j,bool f=1){\n    assert(prepared);\n    int a=sum[j>>6]+__builtin_popcountll(bit[j>>6]&((1ull<<(j&63))-1));\n\
    \    return (f?a:j-a);\n  }\n  // 0-indexed \u3067 k \u756A\u76EE\u306E f \u306E\
    \u5834\u6240 \n  int select(int k,bool f=1){\n    assert(prepared);\n    if(k<0\
    \ or rank(n,f)<=k)return -1;\n    int l=0,r=n;\n    while(r-l>1){\n      int m=(l+r)>>1;\n\
    \      (rank(m,f)>=k+1?r:l)=m;\n    }\n    return r-1;\n  }\n  // l\u4EE5\u4E0A\
    \u3067 k \u756A\u76EE\u306E f \u306E\u5834\u6240\n  int select(int k,bool f,int\
    \ l){\n    return select(rank(l,f)+k,f);\n  }\n};\n"
  code: "#pragma once\nclass FullyIndexableDictionary{\n  int n,\n      block; //\
    \ 64\u500B\u4E8B\u306B\u533A\u5207\u3063\u305F\u30D6\u30ED\u30C3\u30AF\u306E\u500B\
    \u6570\n  vector<unsigned long long> bit;\n  vector<unsigned int> sum; // \u30D6\
    \u30ED\u30C3\u30AF\u6BCE\u306E\u7D2F\u7A4D\u548C\n  bool prepared;\npublic:\n\
    \  FullyIndexableDictionary(){}\n  FullyIndexableDictionary(int n)\n    :n(n),block((n+63)>>6),bit(block,0),sum(block+1,0),prepared(false){}\n\
    \n  bool is_prepared(){ return prepared; }\n\n  void set(int k){\n    bit[k>>6]|=1ull<<(k&63);\n\
    \    sum[(k>>6)+1]++;\n  }\n  void build(){ \n    assert(!prepared);\n    prepared=true;\n\
    \    for(int i=0;i<block;i++)sum[i+1]+=sum[i]; \n  }\n\n  bool operator[](int\
    \ k)const{\n    return bool((bit[k>>6]>>(k&63))&1);\n  }\n\n  // [0,j) \u306E\u5408\
    \u8A08\n  int rank(int j,bool f=1){\n    assert(prepared);\n    int a=sum[j>>6]+__builtin_popcountll(bit[j>>6]&((1ull<<(j&63))-1));\n\
    \    return (f?a:j-a);\n  }\n  // 0-indexed \u3067 k \u756A\u76EE\u306E f \u306E\
    \u5834\u6240 \n  int select(int k,bool f=1){\n    assert(prepared);\n    if(k<0\
    \ or rank(n,f)<=k)return -1;\n    int l=0,r=n;\n    while(r-l>1){\n      int m=(l+r)>>1;\n\
    \      (rank(m,f)>=k+1?r:l)=m;\n    }\n    return r-1;\n  }\n  // l\u4EE5\u4E0A\
    \u3067 k \u756A\u76EE\u306E f \u306E\u5834\u6240\n  int select(int k,bool f,int\
    \ l){\n    return select(rank(l,f)+k,f);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/FullyIndexableDictionary.cpp
  requiredBy:
  - library/datastructure/WaveletMatrix.cpp
  - library/datastructure/GroupWaveletMatrix.cpp
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/919.test.cpp
  - test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
documentation_of: library/datastructure/FullyIndexableDictionary.cpp
layout: document
redirect_from:
- /library/library/datastructure/FullyIndexableDictionary.cpp
- /library/library/datastructure/FullyIndexableDictionary.cpp.html
title: library/datastructure/FullyIndexableDictionary.cpp
---
