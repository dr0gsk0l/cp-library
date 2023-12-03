---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.cpp
    title: library/datastructure/unionfind/UnionFind.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/MinimumSpanningTree.cpp
    title: library/graph/MinimumSpanningTree.cpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/AOJ/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/graph/WeightedGraph.cpp\"\
    \ntemplate<typename T>\nstruct WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int\
    \ from,int to,T weight):from(from),to(to),weight(weight){}\n  int from,to;\n \
    \ T weight;\n  operator int()const{ return to; }\n};\n\ntemplate<typename T>\n\
    struct WeightedGraph{\n  int n;\n  using weight_type=T;\n  using edge_type=WeightedEdge<T>;\n\
    \  vector<edge_type> edges;\nprotected:\n  vector<int> in_deg;\n  bool prepared;\n\
    \  class OutgoingEdges{\n    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]);\
    \ }\n    edge_type* end(){ return &(g->edges[r]); }\n    edge_type& operator[](int\
    \ i){ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\n  class\
    \ ConstOutgoingEdges{\n    const WeightedGraph* g;\n    int l,r;\n  public:\n\
    \    ConstOutgoingEdges(const WeightedGraph* g,int l,int r):g(g),l(l),r(r){}\n\
    \    const edge_type* begin()const{ return &(g->edges[l]); }\n    const edge_type*\
    \ end()const{ return &(g->edges[r]); }\n    const edge_type& operator[](int i)const{\
    \ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\npublic:\n\
    \  OutgoingEdges operator[](int v){\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1]\
    \ };\n  }\n  const ConstOutgoingEdges operator[](int v)const{\n    assert(prepared);\n\
    \    return { this,in_deg[v],in_deg[v+1] };\n  }\n\n  bool is_prepared()const{\
    \ return prepared; }\n\n  WeightedGraph():n(0),in_deg(1,0),prepared(false){}\n\
    \  WeightedGraph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  WeightedGraph(int\
    \ n,int m,bool directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){\
    \ scan(m,directed,indexed); }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int\
    \ from,int to,T weight){\n    assert(!prepared);\n    assert(0<=from and from<n\
    \ and 0<=to and to<n);\n    edges.emplace_back(from,to,weight);\n    in_deg[from+1]++;\n\
    \  }\n  void add_edge(int u,int v,T weight){\n    add_arc(u,v,weight);\n    add_arc(v,u,weight);\n\
    \  }\n  void add_arc(const edge_type&e){\n    add_arc(e.from,e.to,e.weight);\n\
    \  }\n  void add_edge(const edge_type&e){\n    add_edge(e.from,e.to,e.weight);\n\
    \  }\n\n  void scan(int m,bool directed=false,int indexed=1){\n    edges.reserve(directed?m:2*m);\n\
    \    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      T weight;cin>>weight;\n\
    \      if(directed)add_arc(u,v,weight);\n      else add_edge(u,v,weight);\n  \
    \  }\n    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __DEBUG\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<\"(\"<<edges[i].to<<\",\"<<edges[i].weight<<\")\";\n      cerr<<\"\
    \\n\";\n    }\n  }\n};\n#line 1 \"library/datastructure/unionfind/UnionFind.cpp\"\
    \nclass UnionFind{\n  int n,num;\n  vector<int> sz,parent;\npublic:\n  UnionFind()=default;\n\
    \  UnionFind(int n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}\n\
    \  \n  int leader(int x){ \n    assert(0<=x and x<n);\n    return (x==parent[x]?\
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
    \  return {res,tree};\n}\n#line 7 \"test/AOJ/GRL_2_A.test.cpp\"\n\nint main(){\n\
    \  int n,m;cin>>n>>m;\n  WeightedGraph<int> g(n,m,false,0);\n  auto [sum,tree]=minimum_spanning_tree(g);\n\
    \  cout<<sum<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/graph/WeightedGraph.cpp\"\
    \n#include \"library/graph/MinimumSpanningTree.cpp\"\n\nint main(){\n  int n,m;cin>>n>>m;\n\
    \  WeightedGraph<int> g(n,m,false,0);\n  auto [sum,tree]=minimum_spanning_tree(g);\n\
    \  cout<<sum<<endl;\n}"
  dependsOn:
  - library/graph/WeightedGraph.cpp
  - library/graph/MinimumSpanningTree.cpp
  - library/datastructure/unionfind/UnionFind.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_2_A.test.cpp
- /verify/test/AOJ/GRL_2_A.test.cpp.html
title: test/AOJ/GRL_2_A.test.cpp
---
