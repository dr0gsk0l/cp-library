---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/416.test.cpp
    title: test/yukicoder/416.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://tiramister.net/blog/posts/persistent-unionfind/
  bundledCode: "#line 2 \"library/datastructure/unionfind/PartialPersistentUnionFind.cpp\"\
    \n// https://tiramister.net/blog/posts/persistent-unionfind/\nclass PartialPersistentUnionFind{\n\
    \  int now; // \u73FE\u5728\u6642\u523B\n  vector<int> par,rank,time;\n  vector<vector<pair<int,int>>>\
    \ sz;\n  static constexpr int NOW=numeric_limits<int>::max();\npublic:\n  PartialPersistentUnionFind(int\
    \ n):now(0),par(n),rank(n,0),time(n,0),sz(n){\n    iota(par.begin(),par.end(),0);\n\
    \  }\n\n  // \u6642\u523B t \u306E leader\n  int find(int x, int t=NOW){\n   \
    \ while(x!=par[x] and time[x]<t)x=par[x];\n    return x;\n  }\n  // \u6642\u523B\
    \ t \u3067 x,y \u304C\u9023\u7D50\u304B\n  bool same(int x,int y,int t=NOW){\n\
    \    return find(x,t)==find(y,t);\n  }\n  // x \u3068 y \u304C\u3044\u3064\u9023\
    \u7D50\u306B\u306A\u3063\u305F\u304B\uFF08\u307E\u3060\u975E\u9023\u7D50\u306A\
    \u3089 -1 \uFF09\n  // stack \u3092\u4F7F\u3046\u5B9F\u88C5\u3082\u8003\u3048\u305F\
    \u3051\u3069\u5C11\u3057\u9045\u305D\u3046 atcoder/submissions/37116694\n  int\
    \ when_same(int x,int y){\n    int diff=0; // x \u306E\u6DF1\u3055 - y \u306E\u6DF1\
    \u3055\n    int X=x,Y=y;\n    while(par[x]!=x){\n      x=par[x];\n      diff++;\n\
    \    }\n    while(par[y]!=y){\n      y=par[y];\n      diff--;\n    }\n    if(x!=y)return\
    \ -1;\n    int res=0;\n    while(X!=Y){\n      if(diff>0){\n        res=max(res,time[X]);\n\
    \        X=par[X];\n        diff--;\n      }\n      else{\n        res=max(res,time[Y]);\n\
    \        Y=par[Y];\n        diff++;\n      }\n    }\n    return res;\n  }\n  //\
    \ merge \u304C\u6210\u529F\u3057\u305F\u3089\u6642\u523B\u3092 1 \u9032\u3081\u305F\
    \u3042\u3068\u305D\u306E\u6642\u523B\u3092\u8FD4\u3059\n  // \u5931\u6557\u3057\
    \u305F\u3089 stop \u304C false \u306A\u3089\u6642\u523B\u3092\u9032\u3081\u3066\
    \u3001-1 \u3092\u8FD4\u3059 \n  int merge(int x,int y,bool stop=false){\n    now++;\n\
    \    x=find(x);\n    y=find(y);\n    if(x==y){\n      if(stop)now--;\n      return\
    \ -1;\n    }\n    if(rank[x]<rank[y])swap(x,y);\n    sz[x].emplace_back(now, size(x)+size(y));\n\
    \    if(rank[x]==rank[y])rank[x]++;\n    par[y]=x;\n    return time[y]=now;\n\
    \  }\n  // \u6642\u523B t \u306E\u9023\u7D50\u6210\u5206 x \u306E\u30B5\u30A4\u30BA\
    \n  int size(int x,int t=NOW){\n    x=find(x,t);\n    int ok=-1,ng=sz[x].size();\n\
    \    while(ng-ok>1){\n      int mid=(ok+ng)>>1;\n      (sz[x][mid].first <= t?ok:ng)=mid;\n\
    \    }\n    return ( ~ok ? sz[x][ok].second : 1 );\n  }\n};\n"
  code: "#pragma once\n// https://tiramister.net/blog/posts/persistent-unionfind/\n\
    class PartialPersistentUnionFind{\n  int now; // \u73FE\u5728\u6642\u523B\n  vector<int>\
    \ par,rank,time;\n  vector<vector<pair<int,int>>> sz;\n  static constexpr int\
    \ NOW=numeric_limits<int>::max();\npublic:\n  PartialPersistentUnionFind(int n):now(0),par(n),rank(n,0),time(n,0),sz(n){\n\
    \    iota(par.begin(),par.end(),0);\n  }\n\n  // \u6642\u523B t \u306E leader\n\
    \  int find(int x, int t=NOW){\n    while(x!=par[x] and time[x]<t)x=par[x];\n\
    \    return x;\n  }\n  // \u6642\u523B t \u3067 x,y \u304C\u9023\u7D50\u304B\n\
    \  bool same(int x,int y,int t=NOW){\n    return find(x,t)==find(y,t);\n  }\n\
    \  // x \u3068 y \u304C\u3044\u3064\u9023\u7D50\u306B\u306A\u3063\u305F\u304B\uFF08\
    \u307E\u3060\u975E\u9023\u7D50\u306A\u3089 -1 \uFF09\n  // stack \u3092\u4F7F\u3046\
    \u5B9F\u88C5\u3082\u8003\u3048\u305F\u3051\u3069\u5C11\u3057\u9045\u305D\u3046\
    \ atcoder/submissions/37116694\n  int when_same(int x,int y){\n    int diff=0;\
    \ // x \u306E\u6DF1\u3055 - y \u306E\u6DF1\u3055\n    int X=x,Y=y;\n    while(par[x]!=x){\n\
    \      x=par[x];\n      diff++;\n    }\n    while(par[y]!=y){\n      y=par[y];\n\
    \      diff--;\n    }\n    if(x!=y)return -1;\n    int res=0;\n    while(X!=Y){\n\
    \      if(diff>0){\n        res=max(res,time[X]);\n        X=par[X];\n       \
    \ diff--;\n      }\n      else{\n        res=max(res,time[Y]);\n        Y=par[Y];\n\
    \        diff++;\n      }\n    }\n    return res;\n  }\n  // merge \u304C\u6210\
    \u529F\u3057\u305F\u3089\u6642\u523B\u3092 1 \u9032\u3081\u305F\u3042\u3068\u305D\
    \u306E\u6642\u523B\u3092\u8FD4\u3059\n  // \u5931\u6557\u3057\u305F\u3089 stop\
    \ \u304C false \u306A\u3089\u6642\u523B\u3092\u9032\u3081\u3066\u3001-1 \u3092\
    \u8FD4\u3059 \n  int merge(int x,int y,bool stop=false){\n    now++;\n    x=find(x);\n\
    \    y=find(y);\n    if(x==y){\n      if(stop)now--;\n      return -1;\n    }\n\
    \    if(rank[x]<rank[y])swap(x,y);\n    sz[x].emplace_back(now, size(x)+size(y));\n\
    \    if(rank[x]==rank[y])rank[x]++;\n    par[y]=x;\n    return time[y]=now;\n\
    \  }\n  // \u6642\u523B t \u306E\u9023\u7D50\u6210\u5206 x \u306E\u30B5\u30A4\u30BA\
    \n  int size(int x,int t=NOW){\n    x=find(x,t);\n    int ok=-1,ng=sz[x].size();\n\
    \    while(ng-ok>1){\n      int mid=(ok+ng)>>1;\n      (sz[x][mid].first <= t?ok:ng)=mid;\n\
    \    }\n    return ( ~ok ? sz[x][ok].second : 1 );\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/PartialPersistentUnionFind.cpp
  requiredBy: []
  timestamp: '2023-12-03 15:49:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/416.test.cpp
documentation_of: library/datastructure/unionfind/PartialPersistentUnionFind.cpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/PartialPersistentUnionFind.cpp
- /library/library/datastructure/unionfind/PartialPersistentUnionFind.cpp.html
title: library/datastructure/unionfind/PartialPersistentUnionFind.cpp
---
