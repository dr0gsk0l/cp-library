---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.cpp
    title: library/datastructure/unionfind/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2647.test.cpp
    title: test/AOJ/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_B.test.cpp
    title: test/AOJ/GRL_2_B.test.cpp
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
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n#line 3 \"library/graph/MinimumSpanningArborescence.cpp\"\
    \ntemplate<typename WG,typename W=typename WG::weight_type>\noptional< pair<W,vector<int>>\
    \ > minimum_spanning_arborescence(WG g,int r=0){\n  int n=g.n;\n  W res=0;\n \
    \ vector<W> new_add(n,0);\n  vector<int> tree(n),pre(n),state(n,0);\n  UnionFind\
    \ uf(n);\n  state[r]=2;\n\n  auto compare=[&](const int&a,const int&b){return\
    \ g.edges[a].weight>g.edges[b].weight;};\n  using PQ=priority_queue<int,vector<int>,decltype(compare)>;\n\
    \  vector< pair<PQ,W> > pq_add(n,{PQ{compare},0});\n  for(int i=0;i<g.edges.size();i++)\n\
    \    pq_add[g.edges[i].to].first.push(i);\n  vector<int> pq_id(n);\n  iota(pq_id.begin(),pq_id.end(),0);\n\
    \  \n  auto merge=[&](int u,int v){\n    u=uf.leader(u);v=uf.leader(v);\n    if(u==v)return;\n\
    \    uf.merge(u,v);\n    auto&[pq1,add1]=pq_add[pq_id[u]];\n    auto&[pq2,add2]=pq_add[pq_id[v]];\n\
    \    if(pq1.size()>pq2.size()){\n      while(pq2.size()){\n        int edge_id=pq2.top();pq2.pop();\n\
    \        g.edges[edge_id].weight-=add2-add1;\n        pq1.push(edge_id);\n   \
    \   }\n      pq_id[uf.leader(v)]=pq_id[u];\n    }\n    else{\n      while(pq1.size()){\n\
    \        int edge_id=pq1.top();pq1.pop();\n        g.edges[edge_id].weight-=add1-add2;\n\
    \        pq2.push(edge_id);\n      }\n      pq_id[uf.leader(v)]=pq_id[v];\n  \
    \  }\n  };\n  \n  for(int i=0;i<n;i++){\n    int now=uf.leader(i);\n    if(state[now])continue;\n\
    \    vector<int> processing;\n    while(state[now]!=2){\n      processing.push_back(now);\n\
    \      state[now]=1;\n      auto&[pq,add]=pq_add[pq_id[now]];\n      if(!pq.size())return\
    \ nullopt;\n      int edge_id=pq.top();pq.pop();\n      auto&e=g.edges[edge_id];\n\
    \      res+=e.weight-add;\n      tree[e.to]=edge_id;\n      pre[now]=uf.leader(e.from);\n\
    \      new_add[now]=e.weight;\n      if(state[pre[now]]==1){\n        int v=now;\n\
    \        do{\n          pq_add[pq_id[v]].second=new_add[v];\n          merge(v,now);\n\
    \          v=uf.leader(pre[v]);\n        }while(!uf.same(v,now));\n        now=uf.leader(now);\n\
    \      }\n      else\n        now=uf.leader(pre[now]);\n    }\n    for(int v:processing)state[v]=2;\n\
    \  }\n  tree.erase(tree.begin()+r);\n  return make_pair(res,tree);\n}\n"
  code: "#pragma once\n#include \"library/datastructure/unionfind/UnionFind.cpp\"\n\
    template<typename WG,typename W=typename WG::weight_type>\noptional< pair<W,vector<int>>\
    \ > minimum_spanning_arborescence(WG g,int r=0){\n  int n=g.n;\n  W res=0;\n \
    \ vector<W> new_add(n,0);\n  vector<int> tree(n),pre(n),state(n,0);\n  UnionFind\
    \ uf(n);\n  state[r]=2;\n\n  auto compare=[&](const int&a,const int&b){return\
    \ g.edges[a].weight>g.edges[b].weight;};\n  using PQ=priority_queue<int,vector<int>,decltype(compare)>;\n\
    \  vector< pair<PQ,W> > pq_add(n,{PQ{compare},0});\n  for(int i=0;i<g.edges.size();i++)\n\
    \    pq_add[g.edges[i].to].first.push(i);\n  vector<int> pq_id(n);\n  iota(pq_id.begin(),pq_id.end(),0);\n\
    \  \n  auto merge=[&](int u,int v){\n    u=uf.leader(u);v=uf.leader(v);\n    if(u==v)return;\n\
    \    uf.merge(u,v);\n    auto&[pq1,add1]=pq_add[pq_id[u]];\n    auto&[pq2,add2]=pq_add[pq_id[v]];\n\
    \    if(pq1.size()>pq2.size()){\n      while(pq2.size()){\n        int edge_id=pq2.top();pq2.pop();\n\
    \        g.edges[edge_id].weight-=add2-add1;\n        pq1.push(edge_id);\n   \
    \   }\n      pq_id[uf.leader(v)]=pq_id[u];\n    }\n    else{\n      while(pq1.size()){\n\
    \        int edge_id=pq1.top();pq1.pop();\n        g.edges[edge_id].weight-=add1-add2;\n\
    \        pq2.push(edge_id);\n      }\n      pq_id[uf.leader(v)]=pq_id[v];\n  \
    \  }\n  };\n  \n  for(int i=0;i<n;i++){\n    int now=uf.leader(i);\n    if(state[now])continue;\n\
    \    vector<int> processing;\n    while(state[now]!=2){\n      processing.push_back(now);\n\
    \      state[now]=1;\n      auto&[pq,add]=pq_add[pq_id[now]];\n      if(!pq.size())return\
    \ nullopt;\n      int edge_id=pq.top();pq.pop();\n      auto&e=g.edges[edge_id];\n\
    \      res+=e.weight-add;\n      tree[e.to]=edge_id;\n      pre[now]=uf.leader(e.from);\n\
    \      new_add[now]=e.weight;\n      if(state[pre[now]]==1){\n        int v=now;\n\
    \        do{\n          pq_add[pq_id[v]].second=new_add[v];\n          merge(v,now);\n\
    \          v=uf.leader(pre[v]);\n        }while(!uf.same(v,now));\n        now=uf.leader(now);\n\
    \      }\n      else\n        now=uf.leader(pre[now]);\n    }\n    for(int v:processing)state[v]=2;\n\
    \  }\n  tree.erase(tree.begin()+r);\n  return make_pair(res,tree);\n}\n"
  dependsOn:
  - library/datastructure/unionfind/UnionFind.cpp
  isVerificationFile: false
  path: library/graph/MinimumSpanningArborescence.cpp
  requiredBy: []
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/Graph/DirectedMST.test.cpp
  - test/AOJ/2647.test.cpp
  - test/AOJ/GRL_2_B.test.cpp
documentation_of: library/graph/MinimumSpanningArborescence.cpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningArborescence.cpp
- /library/library/graph/MinimumSpanningArborescence.cpp.html
title: library/graph/MinimumSpanningArborescence.cpp
---
