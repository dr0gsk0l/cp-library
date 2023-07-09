---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.cpp
    title: library/datastructure/unionfind/UnionFind.cpp
  - icon: ':question:'
    path: library/graph/MinimumSpanningArborescence.cpp
    title: library/graph/MinimumSpanningArborescence.cpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"test/library-checker/Graph/DirectedMST.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n#define IGNORE\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/graph/WeightedGraph.cpp\"\
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
    \  }\n  tree.erase(tree.begin()+r);\n  return make_pair(res,tree);\n}\n#line 8\
    \ \"test/library-checker/Graph/DirectedMST.test.cpp\"\nusing ll=long long;\n\n\
    int main(){\n  int n,m,s;cin>>n>>m>>s;\n  WeightedGraph<ll> g(n,m,true,0);\n \
    \ auto ans=minimum_spanning_arborescence(g,s);\n  assert(ans.has_value());\n \
    \ auto [val,tree]=ans.value();\n  vector<int> p(n);\n  p[s]=s;\n  ll sum=0;\n\
    \  for(int id:tree){\n    const auto&e=g.edges[id];\n    sum+=e.weight;\n    p[e.to]=e.from;\n\
    \  }\n  val=sum;//assert(sum==val);\n  cout<<val<<\"\\n\";\n  for(int v=0;v<n;v++)\n\
    \    cout<<p[v]<<\"\\n \"[v+1<n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n#define\
    \ IGNORE\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/graph/WeightedGraph.cpp\"\
    \n#include \"library/graph/MinimumSpanningArborescence.cpp\"\nusing ll=long long;\n\
    \nint main(){\n  int n,m,s;cin>>n>>m>>s;\n  WeightedGraph<ll> g(n,m,true,0);\n\
    \  auto ans=minimum_spanning_arborescence(g,s);\n  assert(ans.has_value());\n\
    \  auto [val,tree]=ans.value();\n  vector<int> p(n);\n  p[s]=s;\n  ll sum=0;\n\
    \  for(int id:tree){\n    const auto&e=g.edges[id];\n    sum+=e.weight;\n    p[e.to]=e.from;\n\
    \  }\n  val=sum;//assert(sum==val);\n  cout<<val<<\"\\n\";\n  for(int v=0;v<n;v++)\n\
    \    cout<<p[v]<<\"\\n \"[v+1<n];\n}"
  dependsOn:
  - library/graph/WeightedGraph.cpp
  - library/graph/MinimumSpanningArborescence.cpp
  - library/datastructure/unionfind/UnionFind.cpp
  isVerificationFile: true
  path: test/library-checker/Graph/DirectedMST.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/DirectedMST.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/DirectedMST.test.cpp
- /verify/test/library-checker/Graph/DirectedMST.test.cpp.html
title: test/library-checker/Graph/DirectedMST.test.cpp
---