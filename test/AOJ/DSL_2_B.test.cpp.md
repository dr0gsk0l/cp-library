---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':x:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/AOJ/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/algebra/group/Add.cpp\"\
    \ntemplate<typename X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ void Rchop(X&x, const X&y){ x+=y; }\n  static constexpr void Lchop(const X&x,\
    \ X&y){ y+=x; }\n  static constexpr X inverse(const X &x) noexcept { return -x;\
    \ }\n  static constexpr X power(const X &x, long long n) noexcept { return X(n)\
    \ * x; }\n  static constexpr X unit() { return X(0); }\n  static constexpr bool\
    \ commute = true;\n};\n#line 3 \"library/datastructure/FenwickTree.cpp\"\ntemplate<typename\
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
    \ [&k](T x){ return x<=k; } );\n  }\n};\n#line 7 \"test/AOJ/DSL_2_B.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,q;cin>>n>>q;\n  FenwickTree<GroupAdd<int>> ft(n);\n  while(q--){\n    int\
    \ c,s,t;cin>>c>>s>>t;s--;\n    if(c){\n      assert(s<=t);\n      cout<<ft.prod(s,t)<<\"\
    \\n\";\n    }\n    else ft.multiply(s,t);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/algebra/group/Add.cpp\"\
    \n#include \"library/datastructure/FenwickTree.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,q;cin>>n>>q;\n  FenwickTree<GroupAdd<int>> ft(n);\n\
    \  while(q--){\n    int c,s,t;cin>>c>>s>>t;s--;\n    if(c){\n      assert(s<=t);\n\
    \      cout<<ft.prod(s,t)<<\"\\n\";\n    }\n    else ft.multiply(s,t);\n  }\n}"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/datastructure/FenwickTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:03:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_B.test.cpp
- /verify/test/AOJ/DSL_2_B.test.cpp.html
title: test/AOJ/DSL_2_B.test.cpp
---
