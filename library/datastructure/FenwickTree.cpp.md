---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.cpp
    title: library/math/FactorialNumberSystem.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename X>\n\
    struct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x, const\
    \ X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 3 \"library/datastructure/FenwickTree.cpp\"\ntemplate<typename AbelGroup=GroupAdd<long\
    \ long>>\nclass FenwickTree{\n  using G=AbelGroup;\n  using T=typename G::value_type;\n\
    \  int n;\n  vector<T> dat,raw;\npublic:\n  FenwickTree(){\n    assert(G::commute);\n\
    \  }\n  FenwickTree(int n):n(n){\n    assert(G::commute);\n    dat=raw=vector<T>(n,G::unit());\n\
    \  }\n  FenwickTree(const vector<T>&v):n(v.size()),raw(v),dat(v){\n    assert(G::commute);\n\
    \    for(int i=1;i<=n;i++){\n      int j=i+(i&-i);\n      if(j<=n)G::Rchop(dat[j-1],dat[i-1]);\n\
    \    }\n  }\n\n  T operator[](int k)const{ return raw[k]; }\n  T get(int k)const{\
    \ return raw[k]; }\n\n  void multiply(int k,const T&x){\n    G::Rchop(raw[k],x);\n\
    \    for(++k;k<=n;k+=k&-k)G::Rchop(dat[k-1],x);\n  }\n  void add(int k,const T&x){\
    \ multiply(k,x); }\n  void set(int k,const T&x){ multiply(k,G::op(x,G::inverse(raw[k])));\
    \ }\n\n  T prod(int k)const{\n    T res=G::unit();\n    while(k>0){\n      G::Rchop(res,\
    \ dat[k-1]);\n      k -= k&-k;\n    }\n    return res;\n  }\n  T sum(int k)const{\
    \ return prod(k); }\n  T prod(int L,int R)const{\n    T pos=G::unit();\n    while(L<R){\n\
    \      G::Rchop(pos,dat[R-1]);\n      R -= R&-R;\n    }\n    T neg=G::unit();\n\
    \    while(R<L){\n      G::Rchop(neg,dat[L-1]);\n      L -= L&-L;\n    }\n   \
    \ return G::op(pos,G::inverse(neg));\n  }\n  T sum(int L,int R)const{ return prod(L,R);\
    \ }\n\n  template<class F>\n  int max_right(const F check)const{\n    assert(check(G::unit()));\n\
    \    int r=0;\n    T sum=G::unit();\n    int k=1;\n    while(2*k<=n)k<<=1;\n \
    \   while(k){\n      if(r+k-1<dat.size())\n        if(check(G::op(sum,dat[r+k-1]))){\n\
    \          G::Rchop(sum,dat[r+k-1]);\n          r += k;\n        }\n      k >>=\
    \ 1;\n    }\n    return r;\n  }\n\n  int kth(T k)const{\n    return max_right(\
    \ [&k](T x){ return x<=k; } );\n  }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/Add.cpp\"\ntemplate<typename\
    \ AbelGroup=GroupAdd<long long>>\nclass FenwickTree{\n  using G=AbelGroup;\n \
    \ using T=typename G::value_type;\n  int n;\n  vector<T> dat,raw;\npublic:\n \
    \ FenwickTree(){\n    assert(G::commute);\n  }\n  FenwickTree(int n):n(n){\n \
    \   assert(G::commute);\n    dat=raw=vector<T>(n,G::unit());\n  }\n  FenwickTree(const\
    \ vector<T>&v):n(v.size()),raw(v),dat(v){\n    assert(G::commute);\n    for(int\
    \ i=1;i<=n;i++){\n      int j=i+(i&-i);\n      if(j<=n)G::Rchop(dat[j-1],dat[i-1]);\n\
    \    }\n  }\n\n  T operator[](int k)const{ return raw[k]; }\n  T get(int k)const{\
    \ return raw[k]; }\n\n  void multiply(int k,const T&x){\n    G::Rchop(raw[k],x);\n\
    \    for(++k;k<=n;k+=k&-k)G::Rchop(dat[k-1],x);\n  }\n  void add(int k,const T&x){\
    \ multiply(k,x); }\n  void set(int k,const T&x){ multiply(k,G::op(x,G::inverse(raw[k])));\
    \ }\n\n  T prod(int k)const{\n    T res=G::unit();\n    while(k>0){\n      G::Rchop(res,\
    \ dat[k-1]);\n      k -= k&-k;\n    }\n    return res;\n  }\n  T sum(int k)const{\
    \ return prod(k); }\n  T prod(int L,int R)const{\n    T pos=G::unit();\n    while(L<R){\n\
    \      G::Rchop(pos,dat[R-1]);\n      R -= R&-R;\n    }\n    T neg=G::unit();\n\
    \    while(R<L){\n      G::Rchop(neg,dat[L-1]);\n      L -= L&-L;\n    }\n   \
    \ return G::op(pos,G::inverse(neg));\n  }\n  T sum(int L,int R)const{ return prod(L,R);\
    \ }\n\n  template<class F>\n  int max_right(const F check)const{\n    assert(check(G::unit()));\n\
    \    int r=0;\n    T sum=G::unit();\n    int k=1;\n    while(2*k<=n)k<<=1;\n \
    \   while(k){\n      if(r+k-1<dat.size())\n        if(check(G::op(sum,dat[r+k-1]))){\n\
    \          G::Rchop(sum,dat[r+k-1]);\n          r += k;\n        }\n      k >>=\
    \ 1;\n    }\n    return r;\n  }\n\n  int kth(T k)const{\n    return max_right(\
    \ [&k](T x){ return x<=k; } );\n  }\n};"
  dependsOn:
  - library/algebra/group/Add.cpp
  isVerificationFile: false
  path: library/datastructure/FenwickTree.cpp
  requiredBy:
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/math/FactorialNumberSystem.cpp
  timestamp: '2023-12-03 14:54:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/yukicoder/924.test.cpp
documentation_of: library/datastructure/FenwickTree.cpp
layout: document
redirect_from:
- /library/library/datastructure/FenwickTree.cpp
- /library/library/datastructure/FenwickTree.cpp.html
title: library/datastructure/FenwickTree.cpp
---
