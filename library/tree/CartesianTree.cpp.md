---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/WeightedTree.cpp
    title: library/tree/WeightedTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_3_B.test.cpp
    title: test/AOJ/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_3_C.test.cpp
    title: test/AOJ/DPL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/CartesianTree.test.cpp
    title: test/library-checker/Tree/CartesianTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \\n\";\n    }\n  }\n};\n#line 3 \"library/tree/WeightedTree.cpp\"\ntemplate<typename\
    \ T>\nstruct WeightedTree:WeightedGraph<T>{\n  using WeightedGraph<T>::WeightedGraph;\n\
    \  using edge_type=typename WeightedGraph<T>::edge_type;\n  using OutgoingEdges=typename\
    \ WeightedGraph<T>::OutgoingEdges;\n  using WeightedGraph<T>::n;\n  using WeightedGraph<T>::in_deg;\n\
    \  \n  int root=-1;\n  vector<int> DFS,BFS,depth;\n\n  void scan_root(int indexed=1){\n\
    \    for(int i=1;i<n;i++){\n      int p;cin>>p;\n      T weight;cin>>weight;\n\
    \      add_edge(p-indexed,i,weight);\n    }\n    build();\n  }\n  void scan(int\
    \ indexed=1){\n    WeightedGraph<T>::scan(n-1,false,indexed);\n    build();\n\
    \  }\n\n  edge_type& parent(int v){\n    assert(~root and root!=v);\n    return\
    \ (*this)[v][0];\n  }\n  OutgoingEdges son(int v){\n    assert(~root);\n    if(v==root)return\
    \ {this,in_deg[v],in_deg[v+1]};\n    return {this,in_deg[v]+1,in_deg[v+1]};\n\
    \  }\n\nprivate:\n  void dfs(int v,int pre=-1){\n    for(auto&e:(*this)[v]){\n\
    \      if(e.to==pre)swap((*this)[v][0],e);\n      else{\n        depth[e.to]=depth[v]+1;\n\
    \        dfs(e.to,v);\n      }\n    }\n    DFS.push_back(v);\n  }\npublic:\n \
    \ void build(int r=0){\n    if(!WeightedGraph<T>::is_prepared())WeightedGraph<T>::build();\n\
    \    if(~root){\n      assert(r==root);\n      return;\n    }\n    root=r;\n \
    \   depth=vector<int>(n,0);\n    DFS.reserve(n);BFS.reserve(n);\n    dfs(root);\n\
    \    queue<int> que;\n    que.push(root);\n    while(que.size()){\n      int p=que.front();que.pop();\n\
    \      BFS.push_back(p);\n      for(const auto&e:son(p))que.push(e.to);\n    }\n\
    \  }\n};\n#line 2 \"library/tree/CartesianTree.cpp\"\n\n// \u6700\u5C0F\u5024\u3067\
    \u5206\u5272 \u6839\u4ED8\u304D\u6728\u3092\u6E21\u3059 \u6839\u304C\u6700\u5C0F\
    \u5024\u306Eindex\n// \u7B49\u3057\u3044\u5024\u306B\u95A2\u3057\u3066\u306F index\
    \ \u306E\u5927\u5C0F\u3092\u6BD4\u8F03\u3059\u308B\n// \u8FBA\u306E\u91CD\u307F\
    \u306F\u5B50\u306E\u90E8\u5206\u6728\u304C\u62C5\u5F53\u3059\u308B\u534A\u958B\
    \u533A\u9593\ntemplate<typename T>\nWeightedTree<pair<int,int>> cartesian_tree(const\
    \ vector<T>&v){\n  int n=v.size();\n  vector<pair<int,int>> lr(n,{0,n});\n  stack<int>\
    \ sta;\n  for(int i=0;i<n;i++){\n    while(sta.size() and v[i]<v[sta.top()]){\n\
    \      lr[sta.top()].second=i;\n      sta.pop();\n    }\n    if(sta.size())lr[i].first=sta.top()+1;\n\
    \    sta.push(i);\n  }\n  WeightedTree<pair<int,int>> t(n);\n  int root;\n  for(int\
    \ i=0;i<n;i++){\n    const auto&[l,r]=lr[i];\n    if(l==0 and r==n)\n      root=i;\n\
    \    else{\n      if(l==0)t.add_edge(r,i,lr[i]);\n      if(r==n)t.add_edge(l-1,i,lr[i]);\n\
    \      if(l!=0 and r!=n)\n        if(v[l-1]>v[r])t.add_edge(l-1,i,lr[i]);\n  \
    \      else t.add_edge(r,i,lr[i]);\n    }\n  }\n  t.build(root);\n  return t;\n\
    }\n"
  code: "#include \"library/tree/WeightedTree.cpp\"\n\n// \u6700\u5C0F\u5024\u3067\
    \u5206\u5272 \u6839\u4ED8\u304D\u6728\u3092\u6E21\u3059 \u6839\u304C\u6700\u5C0F\
    \u5024\u306Eindex\n// \u7B49\u3057\u3044\u5024\u306B\u95A2\u3057\u3066\u306F index\
    \ \u306E\u5927\u5C0F\u3092\u6BD4\u8F03\u3059\u308B\n// \u8FBA\u306E\u91CD\u307F\
    \u306F\u5B50\u306E\u90E8\u5206\u6728\u304C\u62C5\u5F53\u3059\u308B\u534A\u958B\
    \u533A\u9593\ntemplate<typename T>\nWeightedTree<pair<int,int>> cartesian_tree(const\
    \ vector<T>&v){\n  int n=v.size();\n  vector<pair<int,int>> lr(n,{0,n});\n  stack<int>\
    \ sta;\n  for(int i=0;i<n;i++){\n    while(sta.size() and v[i]<v[sta.top()]){\n\
    \      lr[sta.top()].second=i;\n      sta.pop();\n    }\n    if(sta.size())lr[i].first=sta.top()+1;\n\
    \    sta.push(i);\n  }\n  WeightedTree<pair<int,int>> t(n);\n  int root;\n  for(int\
    \ i=0;i<n;i++){\n    const auto&[l,r]=lr[i];\n    if(l==0 and r==n)\n      root=i;\n\
    \    else{\n      if(l==0)t.add_edge(r,i,lr[i]);\n      if(r==n)t.add_edge(l-1,i,lr[i]);\n\
    \      if(l!=0 and r!=n)\n        if(v[l-1]>v[r])t.add_edge(l-1,i,lr[i]);\n  \
    \      else t.add_edge(r,i,lr[i]);\n    }\n  }\n  t.build(root);\n  return t;\n\
    }\n"
  dependsOn:
  - library/tree/WeightedTree.cpp
  - library/graph/WeightedGraph.cpp
  isVerificationFile: false
  path: library/tree/CartesianTree.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_3_B.test.cpp
  - test/AOJ/DPL_3_C.test.cpp
  - test/library-checker/Tree/CartesianTree.test.cpp
documentation_of: library/tree/CartesianTree.cpp
layout: document
redirect_from:
- /library/library/tree/CartesianTree.cpp
- /library/library/tree/CartesianTree.cpp.html
title: library/tree/CartesianTree.cpp
---
