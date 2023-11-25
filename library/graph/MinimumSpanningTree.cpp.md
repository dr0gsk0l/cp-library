---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.cpp
    title: library/datastructure/unionfind/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \  }\n  \n  int count()const{\n    return num;\n  }\n};\n#line 2 \"library/graph/MinimumSpanningTree.cpp\"\
    \ntemplate<typename WG,typename W=typename WG::weight_type>\npair<W,vector<int>>\
    \ minimum_spanning_tree(const WG&g){\n  assert(g.is_prepared());\n  int n=g.n,m=g.edges.size();\n\
    \  UnionFind uf(n);\n  vector<int> id(m);\n  iota(id.begin(),id.end(),0);\n  sort(id.begin(),id.end(),[&](const\
    \ int i,const int j){\n    return g.edges[i].weight<g.edges[j].weight;\n  });\n\
    \  W res=0;\n  vector<int> tree;\n  tree.reserve(n-1);\n  for(int i:id){\n   \
    \ const auto&[from,to,weight]=g.edges[i];\n    if(uf.same(from,to))continue;\n\
    \    tree.push_back(i);\n    uf.merge(from,to);\n    res+=weight;\n  }\n  assert(uf.count()==1);\n\
    \  return {res,tree};\n}\n"
  code: "#include \"library/datastructure/unionfind/UnionFind.cpp\"\ntemplate<typename\
    \ WG,typename W=typename WG::weight_type>\npair<W,vector<int>> minimum_spanning_tree(const\
    \ WG&g){\n  assert(g.is_prepared());\n  int n=g.n,m=g.edges.size();\n  UnionFind\
    \ uf(n);\n  vector<int> id(m);\n  iota(id.begin(),id.end(),0);\n  sort(id.begin(),id.end(),[&](const\
    \ int i,const int j){\n    return g.edges[i].weight<g.edges[j].weight;\n  });\n\
    \  W res=0;\n  vector<int> tree;\n  tree.reserve(n-1);\n  for(int i:id){\n   \
    \ const auto&[from,to,weight]=g.edges[i];\n    if(uf.same(from,to))continue;\n\
    \    tree.push_back(i);\n    uf.merge(from,to);\n    res+=weight;\n  }\n  assert(uf.count()==1);\n\
    \  return {res,tree};\n}"
  dependsOn:
  - library/datastructure/unionfind/UnionFind.cpp
  isVerificationFile: false
  path: library/graph/MinimumSpanningTree.cpp
  requiredBy: []
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_2_A.test.cpp
documentation_of: library/graph/MinimumSpanningTree.cpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningTree.cpp
- /library/library/graph/MinimumSpanningTree.cpp.html
title: library/graph/MinimumSpanningTree.cpp
---
