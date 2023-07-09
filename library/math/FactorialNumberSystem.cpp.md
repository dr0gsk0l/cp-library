---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ [&k](T x){ return x<=k; } );\n  }\n};\n#line 3 \"library/math/FactorialNumberSystem.cpp\"\
    \nnamespace factorial_number_system{\n  // vector<int> \u3067\u8868\u3059\n  //\
    \ v[i]*i! \u306E\u7DCF\u548C\u3092\u8868\u73FE\u3057\u3066\u3044\u308B(0<=v[i]<=i)\n\
    \  // \u7279\u306B v[0]=0 \u306F\u78BA\u5B9A\n\n  // N \u6841\u306E\u968E\u4E57\
    \u9032\u6570 K \u306B\u5BFE\u3057\u3066\u3001N \u306E\u9806\u5217\u3067 0-indexed\
    \ K \u756A\u76EE\u3092\u8FD4\u3059\n  static vector<int> to_permutation(const\
    \ vector<int>&v){\n    int N=v.size();\n    vector<int> p(N);\n    FenwickTree<GroupAdd<int>>\
    \ ft(vector<int>(N,1));\n    for(int i=0;i<N;i++){\n      p[i]=ft.kth(v[N-1-i]);\n\
    \      ft.add(p[i],-1);\n    }\n    return p;\n  }\n\n  // N \u306E\u9806\u5217\
    \u304C 0-indexed K \u756A\u76EE\u3067\u3042\u308B\u3068\u304D\u3001N \u6841\u306E\
    \u968E\u4E57\u9032\u6570 K \u3092\u8FD4\u3059\n  static vector<int> to_factorial(const\
    \ vector<int>&p){\n    int N=p.size();\n    vector<int> v(N);\n    FenwickTree<GroupAdd<int>>\
    \ ft(vector<int>(N,1));\n    for(int i=0;i<N;i++){\n      int k=ft.sum(p[i]);\n\
    \      v[N-1-i]=k;\n      ft.add(p[i],-1);\n    }\n    return v;\n  }\n\n  //\
    \ N \u6841\u306E\u968E\u4E57\u9032\u6570\u306E\u548C mod N!\n  vector<int> sum(vector<int>\
    \ p,const vector<int>&q){\n    int N=p.size();\n    assert(q.size()==N);\n   \
    \ for(int i=0;i<N;i++){\n      p[i] += q[i];\n      if(p[i]>i){\n        p[i]-=i+1;\n\
    \        if(i+1<N)p[i+1]++;\n      }\n    }\n    return p;\n  }\n\n  // sum(p,q)=0\
    \ \u3068\u306A\u308B q \u3092\u8FD4\u3059\n  vector<int> inv(vector<int> p){\n\
    \    int N=p.size();\n    vector<int> q(N);\n    for(int i=0;i<N;i++){\n     \
    \ if(p[i]){\n        q[i] = i+1-p[i];\n        if(i+1<N)p[i+1]++;\n      }\n \
    \     else q[i]=0;\n    }\n    return q;\n  }\n}\n"
  code: "#pragma once\n#include \"library/datastructure/FenwickTree.cpp\"\nnamespace\
    \ factorial_number_system{\n  // vector<int> \u3067\u8868\u3059\n  // v[i]*i!\
    \ \u306E\u7DCF\u548C\u3092\u8868\u73FE\u3057\u3066\u3044\u308B(0<=v[i]<=i)\n \
    \ // \u7279\u306B v[0]=0 \u306F\u78BA\u5B9A\n\n  // N \u6841\u306E\u968E\u4E57\
    \u9032\u6570 K \u306B\u5BFE\u3057\u3066\u3001N \u306E\u9806\u5217\u3067 0-indexed\
    \ K \u756A\u76EE\u3092\u8FD4\u3059\n  static vector<int> to_permutation(const\
    \ vector<int>&v){\n    int N=v.size();\n    vector<int> p(N);\n    FenwickTree<GroupAdd<int>>\
    \ ft(vector<int>(N,1));\n    for(int i=0;i<N;i++){\n      p[i]=ft.kth(v[N-1-i]);\n\
    \      ft.add(p[i],-1);\n    }\n    return p;\n  }\n\n  // N \u306E\u9806\u5217\
    \u304C 0-indexed K \u756A\u76EE\u3067\u3042\u308B\u3068\u304D\u3001N \u6841\u306E\
    \u968E\u4E57\u9032\u6570 K \u3092\u8FD4\u3059\n  static vector<int> to_factorial(const\
    \ vector<int>&p){\n    int N=p.size();\n    vector<int> v(N);\n    FenwickTree<GroupAdd<int>>\
    \ ft(vector<int>(N,1));\n    for(int i=0;i<N;i++){\n      int k=ft.sum(p[i]);\n\
    \      v[N-1-i]=k;\n      ft.add(p[i],-1);\n    }\n    return v;\n  }\n\n  //\
    \ N \u6841\u306E\u968E\u4E57\u9032\u6570\u306E\u548C mod N!\n  vector<int> sum(vector<int>\
    \ p,const vector<int>&q){\n    int N=p.size();\n    assert(q.size()==N);\n   \
    \ for(int i=0;i<N;i++){\n      p[i] += q[i];\n      if(p[i]>i){\n        p[i]-=i+1;\n\
    \        if(i+1<N)p[i+1]++;\n      }\n    }\n    return p;\n  }\n\n  // sum(p,q)=0\
    \ \u3068\u306A\u308B q \u3092\u8FD4\u3059\n  vector<int> inv(vector<int> p){\n\
    \    int N=p.size();\n    vector<int> q(N);\n    for(int i=0;i<N;i++){\n     \
    \ if(p[i]){\n        q[i] = i+1-p[i];\n        if(i+1<N)p[i+1]++;\n      }\n \
    \     else q[i]=0;\n    }\n    return q;\n  }\n}\n"
  dependsOn:
  - library/datastructure/FenwickTree.cpp
  - library/algebra/group/Add.cpp
  isVerificationFile: false
  path: library/math/FactorialNumberSystem.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/FactorialNumberSystem.cpp
layout: document
redirect_from:
- /library/library/math/FactorialNumberSystem.cpp
- /library/library/math/FactorialNumberSystem.cpp.html
title: library/math/FactorialNumberSystem.cpp
---
