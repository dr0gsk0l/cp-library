---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/graph/MinimumSpanningArborescence.cpp
    title: library/graph/MinimumSpanningArborescence.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/MinimumSpanningTree.cpp
    title: library/graph/MinimumSpanningTree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2647.test.cpp
    title: test/AOJ/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_B.test.cpp
    title: test/AOJ/GRL_2_B.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/unionfind.test.cpp
    title: test/library-checker/DataStructure/unionfind.test.cpp
  - icon: ':x:'
    path: test/library-checker/Graph/DirectedMST.test.cpp
    title: test/library-checker/Graph/DirectedMST.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/UnionFind.cpp\"\nclass UnionFind{\n\
    \  int n,num;\n  vector<int> sz,parent;\npublic:\n  UnionFind()=default;\n  UnionFind(int\
    \ n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}\n \
    \ \n  int leader(int x){ \n    assert(0<=x and x<n);\n    return (x==parent[x]?\
    \ x : parent[x]=leader(parent[x])); \n  }\n  \n  bool same(int x,int y){\n   \
    \ assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y); \n\
    \  }\n  \n  bool merge(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    x=leader(x);y=leader(y);\n    if(x==y)return false;\n    if(sz[x]<sz[y])swap(x,y);\n\
    \    sz[x]+=sz[y];\n    parent[y]=x;\n    num--;\n    return true;\n  }\n  \n\
    \  int size(const int x){\n    assert(0<=x and x<n);\n    return sz[leader(x)];\n\
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n"
  code: "class UnionFind{\n  int n,num;\n  vector<int> sz,parent;\npublic:\n  UnionFind()=default;\n\
    \  UnionFind(int n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}\n\
    \  \n  int leader(int x){ \n    assert(0<=x and x<n);\n    return (x==parent[x]?\
    \ x : parent[x]=leader(parent[x])); \n  }\n  \n  bool same(int x,int y){\n   \
    \ assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y); \n\
    \  }\n  \n  bool merge(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    x=leader(x);y=leader(y);\n    if(x==y)return false;\n    if(sz[x]<sz[y])swap(x,y);\n\
    \    sz[x]+=sz[y];\n    parent[y]=x;\n    num--;\n    return true;\n  }\n  \n\
    \  int size(const int x){\n    assert(0<=x and x<n);\n    return sz[leader(x)];\n\
    \  }\n  \n  int count()const{\n    return num;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/UnionFind.cpp
  requiredBy:
  - library/graph/MinimumSpanningArborescence.cpp
  - library/graph/MinimumSpanningTree.cpp
  timestamp: '2023-12-03 15:49:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/Graph/DirectedMST.test.cpp
  - test/library-checker/DataStructure/unionfind.test.cpp
  - test/AOJ/2647.test.cpp
  - test/AOJ/GRL_2_B.test.cpp
  - test/AOJ/GRL_2_A.test.cpp
documentation_of: library/datastructure/unionfind/UnionFind.cpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/UnionFind.cpp
- /library/library/datastructure/unionfind/UnionFind.cpp.html
title: library/datastructure/unionfind/UnionFind.cpp
---
