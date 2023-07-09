---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/MonoidUnionFind.cpp\"\n\
    template<typename AbelMonoid>\nclass UnionFind{\n  using T=typename AbelMonoid::value_type;\n\
    \  int n,num;\n  vector<int> sz,parent;\n  vector<T> value;\npublic:\n  UnionFind()=default;\n\
    \  UnionFind(int n):n(n),num(n),sz(n,1),parent(n),value(n,AbelMonoid::unit()){\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n  UnionFind(const vector<T>&v):n(v.size()),num(n),sz(n,1),parent(n),value(v){\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n  \n  int leader(int x){ \n  \
    \  assert(0<=x and x<n);\n    return (x==parent[x]? x : parent[x]=leader(parent[x]));\
    \ \n  }\n\n  T sum(int x){ return value[leader(x)]; }\n\n  void multiply(int x,T\
    \ a){\n    AbelMonoid::Rchop(value[leader(x)],a);\n  }\n  \n  bool same(int x,int\
    \ y){\n    assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y);\
    \ \n  }\n  \n  bool merge(int x,int y){\n    assert(0<=x and x<n and 0<=y and\
    \ y<n);\n    x=leader(x);y=leader(y);\n    if(x==y)return false;\n    if(sz[x]<sz[y])swap(x,y);\n\
    \    sz[x]+=sz[y];\n    parent[y]=x;\n    AbelMonoid::Rchop(value[x],value[y]);\n\
    \    num--;\n    return true;\n  }\n  \n  int size(const int x){\n    assert(0<=x\
    \ and x<n);\n    return sz[leader(x)];\n  }\n  \n  int count()const{\n    return\
    \ num;\n  }\n};\n"
  code: "template<typename AbelMonoid>\nclass UnionFind{\n  using T=typename AbelMonoid::value_type;\n\
    \  int n,num;\n  vector<int> sz,parent;\n  vector<T> value;\npublic:\n  UnionFind()=default;\n\
    \  UnionFind(int n):n(n),num(n),sz(n,1),parent(n),value(n,AbelMonoid::unit()){\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n  UnionFind(const vector<T>&v):n(v.size()),num(n),sz(n,1),parent(n),value(v){\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n  \n  int leader(int x){ \n  \
    \  assert(0<=x and x<n);\n    return (x==parent[x]? x : parent[x]=leader(parent[x]));\
    \ \n  }\n\n  T sum(int x){ return value[leader(x)]; }\n\n  void multiply(int x,T\
    \ a){\n    AbelMonoid::Rchop(value[leader(x)],a);\n  }\n  \n  bool same(int x,int\
    \ y){\n    assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y);\
    \ \n  }\n  \n  bool merge(int x,int y){\n    assert(0<=x and x<n and 0<=y and\
    \ y<n);\n    x=leader(x);y=leader(y);\n    if(x==y)return false;\n    if(sz[x]<sz[y])swap(x,y);\n\
    \    sz[x]+=sz[y];\n    parent[y]=x;\n    AbelMonoid::Rchop(value[x],value[y]);\n\
    \    num--;\n    return true;\n  }\n  \n  int size(const int x){\n    assert(0<=x\
    \ and x<n);\n    return sz[leader(x)];\n  }\n  \n  int count()const{\n    return\
    \ num;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/MonoidUnionFind.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/MonoidUnionFind.cpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/MonoidUnionFind.cpp
- /library/library/datastructure/unionfind/MonoidUnionFind.cpp.html
title: library/datastructure/unionfind/MonoidUnionFind.cpp
---
