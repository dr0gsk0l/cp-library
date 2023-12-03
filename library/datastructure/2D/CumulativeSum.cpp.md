---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/755.test.cpp
    title: test/yukicoder/755.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/2D/CumulativeSum.cpp\"\ntemplate<typename\
    \ T>\nclass CumulativeSum2D{\n  using U=conditional_t< is_same_v<T,int>,long long,T\
    \ >;\n  int h,w;\n  vector<vector<U>> A;\n  bool prepared;\npublic:\n  CumulativeSum2D(int\
    \ h=0,int w=0):h(h),w(w),A(h+1,vector<U>(w+1,0)),prepared(false){}\n  CumulativeSum2D(const\
    \ vector<vector<T>>&v):h(v.size()),w(v[0].size()),A(h+1,vector<U>(w+1,0)),prepared(false){\n\
    \    for(int i=0;i<h;i++)for(int j=0;j<w;j++)A[i+1][j+1]=v[i][j];\n    build();\n\
    \  }\n  void add(int y,int x,const T&val=1){\n    assert(!prepared);\n    assert(0<=y\
    \ and y<h and 0<=x and x<w);\n    A[y+1][x+1]+=val;\n  }\n  void build(){\n  \
    \  assert(!prepared);prepared=true;\n    for(int i=0;i<h;i++)for(int j=0;j<=w;j++)A[i+1][j]+=A[i][j];\n\
    \    for(int i=0;i<=h;i++)for(int j=0;j<w;j++)A[i][j+1]+=A[i][j];\n  }\n  U sum(int\
    \ u,int d,int l,int r){\n    assert(prepared);\n    assert(0<=u and u<=d and u<=h);\n\
    \    assert(0<=l and l<=r and r<=w);\n    return A[d][r]-A[d][l]-A[u][r]+A[u][l];\n\
    \  }\n  U sum(){\n    assert(prepared);\n    return A.back().back();\n  }\n};\n"
  code: "template<typename T>\nclass CumulativeSum2D{\n  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T >;\n  int h,w;\n  vector<vector<U>> A;\n  bool prepared;\npublic:\n \
    \ CumulativeSum2D(int h=0,int w=0):h(h),w(w),A(h+1,vector<U>(w+1,0)),prepared(false){}\n\
    \  CumulativeSum2D(const vector<vector<T>>&v):h(v.size()),w(v[0].size()),A(h+1,vector<U>(w+1,0)),prepared(false){\n\
    \    for(int i=0;i<h;i++)for(int j=0;j<w;j++)A[i+1][j+1]=v[i][j];\n    build();\n\
    \  }\n  void add(int y,int x,const T&val=1){\n    assert(!prepared);\n    assert(0<=y\
    \ and y<h and 0<=x and x<w);\n    A[y+1][x+1]+=val;\n  }\n  void build(){\n  \
    \  assert(!prepared);prepared=true;\n    for(int i=0;i<h;i++)for(int j=0;j<=w;j++)A[i+1][j]+=A[i][j];\n\
    \    for(int i=0;i<=h;i++)for(int j=0;j<w;j++)A[i][j+1]+=A[i][j];\n  }\n  U sum(int\
    \ u,int d,int l,int r){\n    assert(prepared);\n    assert(0<=u and u<=d and u<=h);\n\
    \    assert(0<=l and l<=r and r<=w);\n    return A[d][r]-A[d][l]-A[u][r]+A[u][l];\n\
    \  }\n  U sum(){\n    assert(prepared);\n    return A.back().back();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/2D/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/755.test.cpp
documentation_of: library/datastructure/2D/CumulativeSum.cpp
layout: document
redirect_from:
- /library/library/datastructure/2D/CumulativeSum.cpp
- /library/library/datastructure/2D/CumulativeSum.cpp.html
title: library/datastructure/2D/CumulativeSum.cpp
---
