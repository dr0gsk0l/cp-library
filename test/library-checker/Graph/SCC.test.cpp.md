---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/ReverseGraph.cpp
    title: library/graph/ReverseGraph.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/SCC.cpp
    title: library/graph/SCC.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/library-checker/Graph/SCC.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"library/graph/Graph.cpp\"\nstruct Edge{\n  int from,to;\n\
    \  Edge()=default;\n  Edge(int from,int to):from(from),to(to){}\n  operator int()const{\
    \ return to; }\n};\n\nstruct Graph{\n  int n;\n  using edge_type=Edge;\n  vector<edge_type>\
    \ edges;\nprotected:\n  vector<int> in_deg;\n  bool prepared;\n  class OutgoingEdges{\n\
    \    Graph* g;\n    int l,r;\n  public:\n    OutgoingEdges(Graph* g,int l,int\
    \ r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]); }\n    edge_type*\
    \ end(){ return &(g->edges[r]); }\n    edge_type& operator[](int i){ return g->edges[l+i];\
    \ }\n    int size()const{ return r-l; }\n  };\n  class ConstOutgoingEdges{\n \
    \   const Graph* g;\n    int l,r;\n  public:\n    ConstOutgoingEdges(const Graph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    const edge_type* begin()const{ return &(g->edges[l]);\
    \ }\n    const edge_type* end()const{ return &(g->edges[r]); }\n    const edge_type&\
    \ operator[](int i)const{ return g->edges[l+i]; }\n    int size()const{ return\
    \ r-l; }\n  };\npublic:\n  OutgoingEdges operator[](int v){\n    assert(prepared);\n\
    \    return { this,in_deg[v],in_deg[v+1] };\n  }\n  const ConstOutgoingEdges operator[](int\
    \ v)const{\n    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1] };\n\
    \  }\n\n  bool is_prepared()const{ return prepared; }\n\n  Graph():n(0),in_deg(1,0),prepared(false){}\n\
    \  Graph(int n):n(n),in_deg(n+1,0),prepared(false){}\n  Graph(int n,int m,bool\
    \ directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){ scan(m,directed,indexed);\
    \ }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int from,int to){\n    assert(!prepared);\n\
    \    assert(0<=from and from<n and 0<=to and to<n);\n    edges.emplace_back(from,to);\n\
    \    in_deg[from+1]++;\n  }\n  void add_edge(int u,int v){\n    add_arc(u,v);\n\
    \    add_arc(v,u);\n  }\n  void add_arc(const edge_type&e){\n    add_arc(e.from,e.to);\n\
    \  }\n  void add_edge(const edge_type&e){\n    add_edge(e.from,e.to);\n  }\n\n\
    \  void scan(int m,bool directed=false,int indexed=1){\n    edges.reserve(directed?m:2*m);\n\
    \    while(m--){\n      int u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      if(directed)add_arc(u,v);\n\
    \      else add_edge(u,v);\n    }\n    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<edges[i].to<<\" \";\n      cerr<<\"\\n\";\n    }\n  }\n};\n#line\
    \ 2 \"library/graph/ReverseGraph.cpp\"\ntemplate<typename GRAPH>\nGRAPH reverse_graph(const\
    \ GRAPH&g){\n  GRAPH r(g.n);\n  for(auto e:g.edges){\n    swap(e.from,e.to);\n\
    \    r.add_arc(e);\n  }\n  r.build();\n  return r;\n}\n#line 4 \"library/graph/SCC.cpp\"\
    \n#define ALL_(v) v.begin(),v.end()\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
    template<typename DirectedGraph>\nclass SCC{\n  int n;\n  DirectedGraph G,R;\n\
    \  vector<int> visit,belong;\n  vector<bool> used;\n  void dfs(int v){\n    used[v]=true;\n\
    \    for(int to:G[v])if(!used[to])dfs(to);\n    visit.push_back(v);\n  }\n  void\
    \ rdfs(int v,int k){\n    used[v]=true;\n    belong[v]=k;\n    for(int to:R[v])if(!used[to])rdfs(to,k);\n\
    \  }\npublic:\n  Graph DAG;\n  vector<vector<int>> component;\n  SCC(const DirectedGraph&G):n(G.n),G(G),belong(n),used(n,false){\n\
    \    assert(G.is_prepared());\n    visit.reserve(n);\n    R=reverse_graph(G);\n\
    \    REP_(v,n)if(!used[v])dfs(v);\n    fill(ALL_(used),false);\n    reverse(ALL_(visit));\n\
    \    int k=0;\n    for(const int&v:visit)\n      if(!used[v])rdfs(v,k++);\n  \
    \  vector<vector<int>> edges(k);\n    component.resize(k);\n    REP_(v,n){\n \
    \     component[belong[v]].push_back(v);\n      for(int to:G[v])\n        if(belong[v]!=belong[to])\n\
    \          edges[belong[v]].push_back(belong[to]);\n    }\n    DAG=Graph(k);\n\
    \    REP_(from,k){\n      sort(ALL_(edges[from]));\n      REP_(i,edges[from].size())\n\
    \        if(!i || edges[from][i]!=edges[from][i-1])\n          DAG.add_arc(from,edges[from][i]);\n\
    \    }\n  }\n  int operator[](int k){ return belong[k]; }\n};\n#undef ALL_\n#undef\
    \ REP_\n#line 7 \"test/library-checker/Graph/SCC.test.cpp\"\n\nint main(){\n \
    \ ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n,m;cin>>n>>m;\n\
    \  Graph g(n,m,true,0);\n  SCC scc(g);\n  int k=scc.DAG.n;\n  cout<<k<<\"\\n\"\
    ;\n  for(const auto&ve:scc.component){\n    cout<<ve.size();\n    for(int p:ve)cout<<\"\
    \ \"<<p;\n    cout<<\"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"library/graph/Graph.cpp\"\n#include \"library/graph/SCC.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,m;cin>>n>>m;\n  Graph g(n,m,true,0);\n  SCC scc(g);\n  int k=scc.DAG.n;\n\
    \  cout<<k<<\"\\n\";\n  for(const auto&ve:scc.component){\n    cout<<ve.size();\n\
    \    for(int p:ve)cout<<\" \"<<p;\n    cout<<\"\\n\";\n  }\n}"
  dependsOn:
  - library/graph/Graph.cpp
  - library/graph/SCC.cpp
  - library/graph/ReverseGraph.cpp
  isVerificationFile: true
  path: test/library-checker/Graph/SCC.test.cpp
  requiredBy: []
  timestamp: '2023-12-10 20:25:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Graph/SCC.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/SCC.test.cpp
- /verify/test/library-checker/Graph/SCC.test.cpp.html
title: test/library-checker/Graph/SCC.test.cpp
---
