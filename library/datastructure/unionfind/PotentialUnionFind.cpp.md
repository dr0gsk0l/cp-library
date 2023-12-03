---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1330.test.cpp
    title: test/AOJ/1330.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2207.test.cpp
    title: test/AOJ/2207.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2971.test.cpp
    title: test/AOJ/2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_B.test.cpp
    title: test/AOJ/DSL_1_B.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1420.test.cpp
    title: test/yukicoder/1420.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/datastructure/unionfind/PotentialUnionFind.cpp\"\
    \ntemplate<typename AbelGroup>\nclass PotentialUnionFind{\n  using T=typename\
    \ AbelGroup::value_type;\n  int n,num;\n  vector<int> sz,parent;\n  vector<T>\
    \ potential; // parent[x] \u3092\u57FA\u6E96\u3068\u3057\u305F\u6642\u306E x \u306E\
    \u5024\npublic:\n  PotentialUnionFind()=default;\n  PotentialUnionFind(int n):n(n),num(n),sz(n,1),parent(n,0),potential(n,AbelGroup::unit()){\n\
    \    assert(AbelGroup::commute);\n    iota(parent.begin(),parent.end(),0);\n \
    \ }\n\n  pair<int,T> from_root(int x){\n    if(x==parent[x])return {x,AbelGroup::unit()};\n\
    \    auto [r,add]=from_root(parent[x]);\n    parent[x]=r;\n    AbelGroup::Rchop(potential[x],add);\n\
    \    return {r,potential[x]};\n  }\n  \n  int leader(int x){ return from_root(x).first;\
    \ }\n  \n  bool same(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    return leader(x)==leader(y); \n  }\n\n  bool merge(int x,int y,T d){\n  \
    \  // potential[y]-potential[x]=d \u306B\u3059\u308B\n    // \u77DB\u76FE\u3059\
    \u308B\u5834\u5408\u306F\u5909\u66F4\u306F\u305B\u305A false \u3092\u8FD4\u3059\
    \n    assert(0<=x and x<n and 0<=y and y<n);\n    auto [rx,dx]=from_root(x);\n\
    \    auto [ry,dy]=from_root(y);\n    AbelGroup::Rchop(d,dx);\n    AbelGroup::Rchop(d,AbelGroup::inverse(dy));\n\
    \    if(rx==ry)return d==AbelGroup::unit();\n    if(sz[rx]<sz[ry]){\n      swap(rx,ry);\n\
    \      d=AbelGroup::inverse(d);\n    }\n    sz[rx]+=sz[ry];\n    parent[ry]=rx;\n\
    \    potential[ry]=d;\n    num--;\n    return true;\n  }\n\n  optional<T> diff(int\
    \ x,int y){\n    // x \u3092\u57FA\u6E96\u3068\u3059\u308B\n    auto [rx,dx]=from_root(x);\n\
    \    auto [ry,dy]=from_root(y);\n    if(rx!=ry)return nullopt;\n    return AbelGroup::op(dy,AbelGroup::inverse(dx));\n\
    \  }\n\n  int size(const int x){\n    assert(0<=x and x<n);\n    return sz[leader(x)];\n\
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n"
  code: "#pragma once\ntemplate<typename AbelGroup>\nclass PotentialUnionFind{\n \
    \ using T=typename AbelGroup::value_type;\n  int n,num;\n  vector<int> sz,parent;\n\
    \  vector<T> potential; // parent[x] \u3092\u57FA\u6E96\u3068\u3057\u305F\u6642\
    \u306E x \u306E\u5024\npublic:\n  PotentialUnionFind()=default;\n  PotentialUnionFind(int\
    \ n):n(n),num(n),sz(n,1),parent(n,0),potential(n,AbelGroup::unit()){\n    assert(AbelGroup::commute);\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n\n  pair<int,T> from_root(int\
    \ x){\n    if(x==parent[x])return {x,AbelGroup::unit()};\n    auto [r,add]=from_root(parent[x]);\n\
    \    parent[x]=r;\n    AbelGroup::Rchop(potential[x],add);\n    return {r,potential[x]};\n\
    \  }\n  \n  int leader(int x){ return from_root(x).first; }\n  \n  bool same(int\
    \ x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n    return leader(x)==leader(y);\
    \ \n  }\n\n  bool merge(int x,int y,T d){\n    // potential[y]-potential[x]=d\
    \ \u306B\u3059\u308B\n    // \u77DB\u76FE\u3059\u308B\u5834\u5408\u306F\u5909\u66F4\
    \u306F\u305B\u305A false \u3092\u8FD4\u3059\n    assert(0<=x and x<n and 0<=y\
    \ and y<n);\n    auto [rx,dx]=from_root(x);\n    auto [ry,dy]=from_root(y);\n\
    \    AbelGroup::Rchop(d,dx);\n    AbelGroup::Rchop(d,AbelGroup::inverse(dy));\n\
    \    if(rx==ry)return d==AbelGroup::unit();\n    if(sz[rx]<sz[ry]){\n      swap(rx,ry);\n\
    \      d=AbelGroup::inverse(d);\n    }\n    sz[rx]+=sz[ry];\n    parent[ry]=rx;\n\
    \    potential[ry]=d;\n    num--;\n    return true;\n  }\n\n  optional<T> diff(int\
    \ x,int y){\n    // x \u3092\u57FA\u6E96\u3068\u3059\u308B\n    auto [rx,dx]=from_root(x);\n\
    \    auto [ry,dy]=from_root(y);\n    if(rx!=ry)return nullopt;\n    return AbelGroup::op(dy,AbelGroup::inverse(dx));\n\
    \  }\n\n  int size(const int x){\n    assert(0<=x and x<n);\n    return sz[leader(x)];\n\
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/PotentialUnionFind.cpp
  requiredBy: []
  timestamp: '2023-12-03 14:54:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/1330.test.cpp
  - test/AOJ/DSL_1_B.test.cpp
  - test/AOJ/2971.test.cpp
  - test/AOJ/2207.test.cpp
  - test/yukicoder/1420.test.cpp
documentation_of: library/datastructure/unionfind/PotentialUnionFind.cpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/PotentialUnionFind.cpp
- /library/library/datastructure/unionfind/PotentialUnionFind.cpp.html
title: library/datastructure/unionfind/PotentialUnionFind.cpp
---
