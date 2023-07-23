---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/flow/Dinic.cpp
    title: library/flow/Dinic.cpp
  - icon: ':heavy_check_mark:'
    path: library/flow/MCF.cpp
    title: library/flow/MCF.cpp
  - icon: ':heavy_check_mark:'
    path: library/flow/NondecreasingMCF.cpp
    title: library/flow/NondecreasingMCF.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/Grid.cpp
    title: library/graph/Grid.cpp
  - icon: ':warning:'
    path: library/graph/Grid8.cpp
    title: library/graph/Grid8.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/matching/BipartiteMatching.cpp
    title: library/graph/matching/BipartiteMatching.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/matching/WeightedBipartiteMatching.cpp
    title: library/graph/matching/WeightedBipartiteMatching.cpp
  - icon: ':warning:'
    path: library/graph/shortest_path/01BFS.cpp
    title: library/graph/shortest_path/01BFS.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/Dial.cpp
    title: library/graph/shortest_path/Dial.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/CartesianTree.cpp
    title: library/tree/CartesianTree.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/WeightedTree.cpp
    title: library/tree/WeightedTree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2647.test.cpp
    title: test/AOJ/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/3297.test.cpp
    title: test/AOJ/3297.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_12_B.test.cpp
    title: test/AOJ/ALDS1_12_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_3_B.test.cpp
    title: test/AOJ/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_3_C.test.cpp
    title: test/AOJ/DPL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_B.test.cpp
    title: test/AOJ/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_A.test.cpp
    title: test/AOJ/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_B.test.cpp
    title: test/AOJ/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_7_A.test.cpp
    title: test/AOJ/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/AssignmentProblem.test.cpp
    title: test/library-checker/Graph/AssignmentProblem.test.cpp
  - icon: ':x:'
    path: test/library-checker/Graph/DirectedMST.test.cpp
    title: test/library-checker/Graph/DirectedMST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
    title: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/ShortestPath.test.cpp
    title: test/library-checker/Graph/ShortestPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/CartesianTree.test.cpp
    title: test/library-checker/Tree/CartesianTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1002.test.cpp
    title: test/yukicoder/1002.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/WeightedGraph.cpp\"\ntemplate<typename T>\n\
    struct WeightedEdge{\n  WeightedEdge()=default;\n  WeightedEdge(int from,int to,T\
    \ weight):from(from),to(to),weight(weight){}\n  int from,to;\n  T weight;\n  operator\
    \ int()const{ return to; }\n};\n\ntemplate<typename T>\nstruct WeightedGraph{\n\
    \  int n;\n  using weight_type=T;\n  using edge_type=WeightedEdge<T>;\n  vector<edge_type>\
    \ edges;\nprotected:\n  vector<int> in_deg;\n  bool prepared;\n  class OutgoingEdges{\n\
    \    WeightedGraph* g;\n    int l,r;\n  public:\n    OutgoingEdges(WeightedGraph*\
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
    \\n\";\n    }\n  }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct WeightedEdge{\n  WeightedEdge()=default;\n\
    \  WeightedEdge(int from,int to,T weight):from(from),to(to),weight(weight){}\n\
    \  int from,to;\n  T weight;\n  operator int()const{ return to; }\n};\n\ntemplate<typename\
    \ T>\nstruct WeightedGraph{\n  int n;\n  using weight_type=T;\n  using edge_type=WeightedEdge<T>;\n\
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
    \\n\";\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/WeightedGraph.cpp
  requiredBy:
  - library/flow/NondecreasingMCF.cpp
  - library/flow/MCF.cpp
  - library/flow/Dinic.cpp
  - library/tree/CartesianTree.cpp
  - library/tree/WeightedTree.cpp
  - library/graph/matching/WeightedBipartiteMatching.cpp
  - library/graph/matching/BipartiteMatching.cpp
  - library/graph/Grid.cpp
  - library/graph/Grid8.cpp
  - library/graph/shortest_path/01BFS.cpp
  - library/graph/shortest_path/Dial.cpp
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1002.test.cpp
  - test/library-checker/Graph/DirectedMST.test.cpp
  - test/library-checker/Graph/ShortestPath.test.cpp
  - test/library-checker/Graph/AssignmentProblem.test.cpp
  - test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  - test/library-checker/Tree/CartesianTree.test.cpp
  - test/AOJ/GRL_2_B.test.cpp
  - test/AOJ/DPL_3_C.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
  - test/AOJ/2647.test.cpp
  - test/AOJ/3297.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/GRL_2_A.test.cpp
  - test/AOJ/GRL_5_A.test.cpp
  - test/AOJ/ALDS1_12_B.test.cpp
  - test/AOJ/GRL_7_A.test.cpp
  - test/AOJ/GRL_6_B.test.cpp
  - test/AOJ/2212.test.cpp
  - test/AOJ/DPL_3_B.test.cpp
  - test/AOJ/GRL_6_A.test.cpp
documentation_of: library/graph/WeightedGraph.cpp
layout: document
redirect_from:
- /library/library/graph/WeightedGraph.cpp
- /library/library/graph/WeightedGraph.cpp.html
title: library/graph/WeightedGraph.cpp
---