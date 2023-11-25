---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/BellmanFord.cpp
    title: library/graph/shortest_path/BellmanFord.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/AOJ/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
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
    \\n\";\n    }\n  }\n};\n#line 1 \"library/graph/shortest_path/BellmanFord.cpp\"\
    \n// s \u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\u304C\u5B9A\u307E\u308B\u306A\
    \u3089\u6700\u77ED\u8DDD\u96E2, \u7121\u9650\u306B\u5C0F\u3055\u304F\u51FA\u6765\
    \u308B\u306A\u3089 nullopt\n// \u305D\u3082\u305D\u3082\u5230\u9054\u51FA\u6765\
    \u306A\u3044\u5834\u5408\u306F pre \u304C -1 \u306B\u306A\u3063\u3066\u3044\u308B\
    \ntemplate<typename WG,typename T=typename WG::weight_type>\npair<vector<optional<T>>,vector<int>>\
    \ bellman_ford(const WG&g,int s=0){\n  assert(g.is_prepared());\n  int n=g.n;\n\
    \  static constexpr T INF=numeric_limits<T>::max()/2;\n  vector<T> d(n,INF);\n\
    \  vector<int> pre(n,-1);\n  d[s]=0;\n  for(int _=0;_<n;_++){\n    bool update=false;\n\
    \    for(int v=0;v<n;v++)if(d[v]<INF)\n      for(const auto&e:g[v])\n        if(d[e.to]>d[v]+e.weight){\n\
    \          d[e.to]=d[v]+e.weight;\n          pre[e.to]=v;\n          update=true;\n\
    \        }\n    if(!update){\n      vector<optional<T>> d_(n);\n      for(int\
    \ i=0;i<n;i++)d_[i]=d[i];\n      return {d_,pre};\n    }\n  }\n  auto now_d=d;\n\
    \  for(int v=0;v<n;v++)if(d[v]<INF)\n    for(const auto&e:g[v])\n      if(d[e.to]>d[v]+e.weight)\n\
    \        d[e.to]=d[v]+e.weight;\n  for(int _=1;_<n;_++)\n    for(int v=0;v<n;v++)if(d[v]<now_d[v])\n\
    \      for(const auto&e:g[v])\n        if(d[e.to]>d[v]+e.weight)\n          d[e.to]=d[v]+e.weight;\n\
    \  vector<optional<T>> res(n);\n  for(int v=0;v<n;v++)\n    if(now_d[v]==d[v])res[v]=d[v];\n\
    \    else res[v]=nullopt;\n  return {res,pre};\n}\n#line 7 \"test/AOJ/GRL_1_B.test.cpp\"\
    \n\nusing ll=long long;\n\nint main(){\n  int n,m,s;cin>>n>>m>>s;\n  WeightedGraph<ll>\
    \ g(n,m,true,0);\n  auto [d,pre]=bellman_ford(g,s);\n  for(const auto&p:d)if(!p){\n\
    \    cout<<\"NEGATIVE CYCLE\\n\";\n    return 0;\n  }\n  for(int i=0;i<n;i++)\n\
    \    if(~pre[i]||i==s)cout<<d[i].value()<<\"\\n\";\n    else cout<<\"INF\\n\"\
    ;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/graph/WeightedGraph.cpp\"\
    \n#include \"library/graph/shortest_path/BellmanFord.cpp\"\n\nusing ll=long long;\n\
    \nint main(){\n  int n,m,s;cin>>n>>m>>s;\n  WeightedGraph<ll> g(n,m,true,0);\n\
    \  auto [d,pre]=bellman_ford(g,s);\n  for(const auto&p:d)if(!p){\n    cout<<\"\
    NEGATIVE CYCLE\\n\";\n    return 0;\n  }\n  for(int i=0;i<n;i++)\n    if(~pre[i]||i==s)cout<<d[i].value()<<\"\
    \\n\";\n    else cout<<\"INF\\n\";\n}"
  dependsOn:
  - library/graph/WeightedGraph.cpp
  - library/graph/shortest_path/BellmanFord.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_B.test.cpp
- /verify/test/AOJ/GRL_1_B.test.cpp.html
title: test/AOJ/GRL_1_B.test.cpp
---
