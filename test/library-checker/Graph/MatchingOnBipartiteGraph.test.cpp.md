---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/flow/Dinic.cpp
    title: library/flow/Dinic.cpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  - icon: ':question:'
    path: library/graph/matching/BipartiteMatching.cpp
    title: library/graph/matching/BipartiteMatching.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/graph/matching/BipartiteMatching.cpp\"\
    \n\n// \u91CD\u307F\u7121\u3057\n#line 2 \"library/flow/Dinic.cpp\"\n\n// https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    #line 2 \"library/graph/WeightedGraph.cpp\"\ntemplate<typename T>\nstruct WeightedEdge{\n\
    \  WeightedEdge()=default;\n  WeightedEdge(int from,int to,T weight):from(from),to(to),weight(weight){}\n\
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
    \\n\";\n    }\n  }\n};\n#line 5 \"library/flow/Dinic.cpp\"\ntemplate<typename\
    \ T>\nclass Dinic{\n  struct EdgeInfo{\n    T cap;\n    int rev;\n  };\n  WeightedGraph<\
    \ EdgeInfo > G;\n  vector<int> level,current_edge,out_deg;\n  int s,t;\n  vector<pair<int,int>>\
    \ edge_memo;\n\n  queue<int> que;\n  void bfs(){\n    //level[v]\u3092\uFF08\u5BB9\
    \u91CF\u6B63\u306E\u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\u6700\u77ED\
    \u8DDD\u96E2\u306B\u3059\u308B \u5230\u9054\u51FA\u6765\u306A\u3051\u308C\u3070\
    -1\n    fill(level.begin(),level.end(),-1);\n    level[s]=0;\n    que.emplace(s);\n\
    \    while(que.size()){\n      int v=que.front();que.pop();\n      for(const auto&e:G[v]){\n\
    \        const auto&[cap,rev]=e.weight;\n        if(cap==0||~level[e.to])continue;\n\
    \        level[e.to]=level[v]+1;\n        que.emplace(e.to);\n      }\n    }\n\
    \  }\n  T dfs(int v,T f){\n    //v\u304B\u3089t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\
    \u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\u3063\u3066\u3053\u308C\u305F\u6C34\
    \u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\u308A\u5024\n    if(v==t)return f;\n\
    \    for(int &i=current_edge[v];i<G[v].size();i++){//\u3053\u306Edfs\u3067\u4F7F\
    \u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\u308F\
    \u308C\u308B\u3053\u3068\u306F\u306A\u3044\n      auto&e=G[v][i];\n      auto&[cap,rev]=e.weight;\n\
    \      if(cap>0&&level[v]<level[e.to]){//bfs\u3092\u3057\u3066\u3044\u308B\u306E\
    \u3067level[v]<level[e.to]\u306A\u3089level[v]+1==level[e.to]\n        T d=dfs(e.to,min(f,cap));\n\
    \        if(d==0)continue;\n        cap-=d;\n        G[e.to][rev].weight.cap+=d;\n\
    \        return d;//\u4E00\u672C\u6D41\u305B\u305F\u3089return\n      }\n    }\n\
    \    return 0;\n  }\npublic:\n  Dinic()=default;\n  Dinic(int n,int s=0,int t_=-1):G(n),level(n),current_edge(n),out_deg(n,0),s(s),t(t_){\n\
    \    if(t<0)t=n-1;\n  }\n\n  // 0-indexed \u3067 edge_id \u756A\u76EE\u306B\u8FFD\
    \u52A0\u3057\u305F\u8FBA\u306B\u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n  T\
    \ operator[](const int edge_id)const{\n    assert(G.is_prepared());\n    const\
    \ auto&[from,id]=edge_memo[edge_id];\n    return G.edge[from][id].weight.cap;\n\
    \  }\n  // \u8FBA\u3092\u8FFD\u52A0\u3057\u305F\u9806\u756A\u306B [from,to,\u6D41\
    \u91CF]\n  vector< tuple<int,int,T> > all_edge(){\n    assert(G.is_prepared());\n\
    \    vector< tuple<int,int,T> > res;\n    res.reserve(edge_memo.size());\n   \
    \ for(const auto&[v,id]:edge_memo){\n      const auto&[to,from,weight]=G[v][id];\n\
    \      res.emplace_back(from,to,weight.cap);\n    }\n    return res;\n  }\n\n\
    \  void add_arc(int from,int to,T cap){\n    G.add_arc(from,to,{cap,out_deg[to]});\n\
    \    G.add_arc(to,from,{0,out_deg[from]++});\n    edge_memo.emplace_back(to,out_deg[to]++);\n\
    \  }\n  T flow(T lim=numeric_limits<T>::max()/2){\n    if(!G.is_prepared())G.build();\n\
    \    T fl=0;\n    while(lim>0){\n      bfs();\n      if(level[t]<0)break;\n  \
    \    fill(current_edge.begin(),current_edge.end(),0);\n      while(true){\n  \
    \      T f=dfs(s,lim);\n        if(f==0)break;\n        fl+=f;\n        lim-=f;\n\
    \      }\n    }\n    return fl;\n  }\n  \n  T st_flow(int s_, int t_, T lim=numeric_limits<T>::max()/2){\
    \ \n    s=s_;t=t_; \n    return flow(lim);\n  }\n};\n#line 5 \"library/graph/matching/BipartiteMatching.cpp\"\
    \nclass BipartiteMatching{\n  int A,B; // \u5DE6\u53F3\u306E\u9802\u70B9\u6570\
    \n  int S,T;\n  Dinic<int> fl;\npublic:\n  BipartiteMatching(int A,int B):A(A),B(B),S(A+B),T(A+B+1),fl(A+B+2,S,T){\n\
    \    for(int i=0;i<A;i++)fl.add_arc(S,i,1);\n    for(int j=0;j<B;j++)fl.add_arc(A+j,T,1);\n\
    \  }\n  void add_edge(int u,int v){\n    assert(0<=u and u<A);\n    assert(0<=v\
    \ and v<B);\n    fl.add_arc(u,A+v,1);\n  }\n  vector<pair<int,int>> solve(){\n\
    \    int K=fl.flow(min(A,B));\n    vector<pair<int,int>> res;\n    res.reserve(K);\n\
    \    auto all_edge=fl.all_edge();\n    for(int i=A+B;i<all_edge.size();i++){\n\
    \      const auto&[from,to,flow]=all_edge[i];\n      if(flow)res.emplace_back(from,to-A);\n\
    \    }\n    return res;\n  }\n};\n#line 6 \"test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ l,r,m;cin>>l>>r>>m;\n\n  BipartiteMatching BM(l,r);\n  while(m--){\n    int\
    \ a,b;cin>>a>>b;\n    BM.add_edge(a,b);\n  }\n  auto ans=BM.solve();\n  cout<<ans.size()<<\"\
    \\n\";\n  for(const auto&[u,v]:ans)cout<<u<<\" \"<<v<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/graph/matching/BipartiteMatching.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ l,r,m;cin>>l>>r>>m;\n\n  BipartiteMatching BM(l,r);\n  while(m--){\n    int\
    \ a,b;cin>>a>>b;\n    BM.add_edge(a,b);\n  }\n  auto ans=BM.solve();\n  cout<<ans.size()<<\"\
    \\n\";\n  for(const auto&[u,v]:ans)cout<<u<<\" \"<<v<<\"\\n\";\n}"
  dependsOn:
  - library/graph/matching/BipartiteMatching.cpp
  - library/flow/Dinic.cpp
  - library/graph/WeightedGraph.cpp
  isVerificationFile: true
  path: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
- /verify/test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp.html
title: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
---