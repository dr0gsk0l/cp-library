---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':x:'
    path: library/segtree/SegmentTree.cpp
    title: library/segtree/SegmentTree.cpp
  - icon: ':x:'
    path: library/tree/HLD.cpp
    title: library/tree/HLD.cpp
  - icon: ':x:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  - icon: ':x:'
    path: library/tree/TreeMonoid.cpp
    title: library/tree/TreeMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/library-checker/Tree/vertex_add_path_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/algebra/group/Add.cpp\"\
    \ntemplate<typename X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ void Rchop(X&x, const X&y){ x+=y; }\n  static constexpr void Lchop(const X&x,\
    \ X&y){ y+=x; }\n  static constexpr X inverse(const X &x) noexcept { return -x;\
    \ }\n  static constexpr X power(const X &x, long long n) noexcept { return X(n)\
    \ * x; }\n  static constexpr X unit() { return X(0); }\n  static constexpr bool\
    \ commute = true;\n};\n#line 2 \"library/graph/Graph.cpp\"\nstruct Edge{\n  int\
    \ from,to;\n  Edge()=default;\n  Edge(int from,int to):from(from),to(to){}\n \
    \ operator int()const{ return to; }\n};\n\nstruct Graph{\n  int n;\n  using edge_type=Edge;\n\
    \  vector<edge_type> edges;\nprotected:\n  vector<int> in_deg;\n  bool prepared;\n\
    \  class OutgoingEdges{\n    Graph* g;\n    int l,r;\n  public:\n    OutgoingEdges(Graph*\
    \ g,int l,int r):g(g),l(l),r(r){}\n    edge_type* begin(){ return &(g->edges[l]);\
    \ }\n    edge_type* end(){ return &(g->edges[r]); }\n    edge_type& operator[](int\
    \ i){ return g->edges[l+i]; }\n    int size()const{ return r-l; }\n  };\n  class\
    \ ConstOutgoingEdges{\n    const Graph* g;\n    int l,r;\n  public:\n    ConstOutgoingEdges(const\
    \ Graph* g,int l,int r):g(g),l(l),r(r){}\n    const edge_type* begin()const{ return\
    \ &(g->edges[l]); }\n    const edge_type* end()const{ return &(g->edges[r]); }\n\
    \    const edge_type& operator[](int i)const{ return g->edges[l+i]; }\n    int\
    \ size()const{ return r-l; }\n  };\npublic:\n  OutgoingEdges operator[](int v){\n\
    \    assert(prepared);\n    return { this,in_deg[v],in_deg[v+1] };\n  }\n  const\
    \ ConstOutgoingEdges operator[](int v)const{\n    assert(prepared);\n    return\
    \ { this,in_deg[v],in_deg[v+1] };\n  }\n\n  bool is_prepared()const{ return prepared;\
    \ }\n\n  Graph():n(0),in_deg(1,0),prepared(false){}\n  Graph(int n):n(n),in_deg(n+1,0),prepared(false){}\n\
    \  Graph(int n,int m,bool directed=false,int indexed=1):\n    n(n),in_deg(n+1,0),prepared(false){\
    \ scan(m,directed,indexed); }\n\n  void resize(int n){n=n;}\n\n  void add_arc(int\
    \ from,int to){\n    assert(!prepared);\n    assert(0<=from and from<n and 0<=to\
    \ and to<n);\n    edges.emplace_back(from,to);\n    in_deg[from+1]++;\n  }\n \
    \ void add_edge(int u,int v){\n    add_arc(u,v);\n    add_arc(v,u);\n  }\n  void\
    \ add_arc(const edge_type&e){\n    add_arc(e.from,e.to);\n  }\n  void add_edge(const\
    \ edge_type&e){\n    add_edge(e.from,e.to);\n  }\n\n  void scan(int m,bool directed=false,int\
    \ indexed=1){\n    edges.reserve(directed?m:2*m);\n    while(m--){\n      int\
    \ u,v;cin>>u>>v;u-=indexed;v-=indexed;\n      if(directed)add_arc(u,v);\n    \
    \  else add_edge(u,v);\n    }\n    build();\n  }\n\n  void build(){\n    assert(!prepared);prepared=true;\n\
    \    for(int v=0;v<n;v++)in_deg[v+1]+=in_deg[v];\n    vector<edge_type> new_edges(in_deg.back());\n\
    \    auto counter=in_deg;\n    for(auto&&e:edges)new_edges[ counter[e.from]++\
    \ ]=e;\n    edges=new_edges;\n  }\n\n  void graph_debug()const{\n  #ifndef __LOCAL\n\
    \    return;\n  #endif\n    assert(prepared);\n    for(int from=0;from<n;from++){\n\
    \      cerr<<from<<\";\";\n      for(int i=in_deg[from];i<in_deg[from+1];i++)\n\
    \        cerr<<edges[i].to<<\" \";\n      cerr<<\"\\n\";\n    }\n  }\n};\n#line\
    \ 3 \"library/tree/Tree.cpp\"\nstruct Tree:Graph{\n  using Graph::Graph;\n  Tree()=default;\n\
    \  int root=-1;\n  vector<int> DFS,BFS,depth;\n\n  void scan_root(int indexed=1){\n\
    \    for(int i=1;i<n;i++){\n      int p;cin>>p;\n      add_edge(p-indexed,i);\n\
    \    }\n    build();\n  }\n  void scan(int indexed=1){\n    Graph::scan(n-1,false,indexed);\n\
    \    build();\n  }\n\n  edge_type& parent(int v){\n    assert(~root and root!=v);\n\
    \    return (*this)[v][0];\n  }\n  OutgoingEdges son(int v){\n    assert(~root);\n\
    \    if(v==root)return {this,in_deg[v],in_deg[v+1]};\n    return {this,in_deg[v]+1,in_deg[v+1]};\n\
    \  }\n\nprivate:\n  void dfs(int v,int pre=-1){\n    for(auto&e:(*this)[v]){\n\
    \      if(e.to==pre)swap((*this)[v][0],e);\n      else{\n        depth[e.to]=depth[v]+1;\n\
    \        dfs(e.to,v);\n      }\n    }\n    DFS.push_back(v);\n  }\npublic:\n \
    \ void build(int r=0){\n    if(!is_prepared())Graph::build();\n    if(~root){\n\
    \      assert(r==root);\n      return;\n    }\n    root=r;\n    depth=vector<int>(n,0);\n\
    \    DFS.reserve(n);BFS.reserve(n);\n    dfs(root);\n    queue<int> que;\n   \
    \ que.push(root);\n    while(que.size()){\n      int p=que.front();que.pop();\n\
    \      BFS.push_back(p);\n      for(const auto&e:son(p))que.push(e.to);\n    }\n\
    \  }\n};\n#line 2 \"library/segtree/SegmentTree.cpp\"\ntemplate<class Monoid>\n\
    class SegmentTree{\n  using X=typename Monoid::value_type;\n  vector<X> dat;\n\
    \  int n,log,size;\n\n  void update(int i){ dat[i]=Monoid::op(dat[2*i],dat[2*i+1]);\
    \ }\npublic:\n  SegmentTree():SegmentTree(0){}\n  SegmentTree(int n):SegmentTree(vector<X>(n,\
    \ Monoid::unit())){}\n  SegmentTree(vector<X> v):n(v.size()){\n    for(log=1;(1<<log)<n;log++){}\n\
    \    size=1<<log;\n    dat.assign(size<<1,Monoid::unit());\n    for (int i=0;i<n;++i)dat[size+i]=v[i];\n\
    \    for (int i=size-1;i>=1;--i) update(i);\n  }\n\n  X operator[](int i)const{\
    \ return dat[size+i]; }\n\n  void set(int i,const X&x){\n    assert(0<=i and i<n);\n\
    \    dat[i+=size]=x;\n    while(i>>=1)update(i);\n  }\n  void multiply(int i,const\
    \ X&x){ set(i,Monoid::op(dat[i+size],x));}\n\n  X prod(int L,int R)const{\n  \
    \  assert(0<=L and L<=R and R<=n);\n    X vl=Monoid::unit(),vr=Monoid::unit();\n\
    \    L+=size, R+=size;\n    while(L<R){\n      if(L&1)Monoid::Rchop(vl,dat[L++]);\n\
    \      if(R&1)Monoid::Lchop(dat[--R],vr);\n      L>>=1,R>>=1;\n    }\n    return\
    \ Monoid::op(vl,vr);\n  }\n  X prod_all()const{ return dat[1]; }\n\n  template\
    \ <class F>\n  int max_right(F& check,int L){\n    assert(0<=L && L<=n && check(Monoid::unit()));\n\
    \    if(L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L <<= 1;\n          if (check(Monoid::op(sm,\
    \ dat[L])))\n            Monoid::Rchop(sm, dat[L++]);\n        }\n        return\
    \ L - size;\n      }\n      Monoid::Rchop(sm, dat[L++]);\n    } while ((L & -L)\
    \ != L);\n    return n;\n  }\n\n  template <class F>\n  int min_left(F& check,\
    \ int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R\
    \ == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n    \
    \  --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          ( R <<= 1 )++;\n          if\
    \ (check(Monoid::op(dat[R], sm)))\n            Monoid::Lchop(dat[R--], sm);\n\
    \        }\n        return R + 1 - size;\n      }\n      Monoid::Lchop(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\
    \u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n  X Xor_prod(int\
    \ l, int r, int xor_val) {\n    assert(Monoid::commute);\n    X x = Monoid::unit();\n\
    \    for (int k = 0; k < log + 1; ++k) {\n      if (l >= r) break;\n      if (l\
    \ & 1) { Monoid::Rchop(x, dat[(size >> k) + ((l++) ^ xor_val)]); }\n      if (r\
    \ & 1) { Monoid::Rchop(x, dat[(size >> k) + ((--r) ^ xor_val)]); }\n      l /=\
    \ 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ SegmentTree&seg){\n    os<<\"(\";\n    for(int L=1;L<=seg.size;L<<=1){\n   \
    \   os<<\"[\";\n      for(int j=L;j<(L<<1);j++){\n        os<<seg.dat[j];\n  \
    \      if(j+1<(L<<1))os<<\",\";\n      }\n      os<<\"]\";\n    }\n    os<<\"\
    )\";\n    return os;\n  }\n};\n#line 2 \"library/algebra/Reverse.cpp\"\ntemplate<typename\
    \ Algebra>\nstruct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n\
    \  static constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n\
    \  static constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static\
    \ constexpr void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 2 \"\
    library/tree/HLD.cpp\"\ntemplate<typename TREE>\nstruct HLD{\n  int n;\n  TREE\
    \ T;\n  vector<int> sz,head,id,id2;\n  bool prepared;\n  HLD(TREE T_):T(T_),n(T_.n),sz(n),head(n),id(n),id2(n),prepared(false){}\n\
    \  HLD()=default;\nprivate:\n  void dfs_sz(int v){\n    sz[v]=1;\n    for(auto&e:T.son(v)){\n\
    \      dfs_sz(e.to);\n      sz[v]+=sz[e.to];\n      if(sz[e.to]>sz[T.son(v)[0].to])swap(e,T.son(v)[0]);\n\
    \    }\n  }\n  void dfs_hld(int v,int& k){\n    id[v]=k++;\n    for(int i=0;i<T.son(v).size();i++){\n\
    \      int to=T.son(v)[i];\n      head[to]=(i?to:head[v]);\n      dfs_hld(to,k);\n\
    \    }\n    id2[v]=k;\n  }\npublic:\n  vector<int> build(int r=0){\n    assert(!prepared);prepared=true;\n\
    \    if(~T.root)assert(T.root==r);\n    else T.build(r);\n    head[r]=r;\n   \
    \ dfs_sz(r);\n    int k=0;\n    dfs_hld(r,k);\n    return id;\n  }\n\n  int lca(int\
    \ u,int v){\n    assert(prepared);\n    while(head[u]!=head[v])\n      if(T.depth[head[u]]>T.depth[head[v]])\n\
    \        u=T.parent(head[u]);\n      else \n        v=T.parent(head[v]);\n   \
    \ return (T.depth[u]<T.depth[v]?u:v);\n  }\n  int distance(int u,int v){\n   \
    \ int w=lca(u,v);\n    return T.depth[u]+T.depth[v]-T.depth[w]*2;\n  }\n\n  //\
    \ l=lca(u,v) \u3068\u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\
    \u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\n  using path_t=vector<pair<int,int>>;\n\
    \  pair<path_t,path_t> path(int u,int v){\n    assert(prepared);\n    path_t path_u,path_v;\n\
    \    while(u!=v){\n      if(head[u]==head[v]){\n        if(T.depth[u]<T.depth[v])\n\
    \          path_v.emplace_back(id[v],id[u]);\n        else\n          path_u.emplace_back(id[u],id[v]);\n\
    \        break;\n      }\n      if(T.depth[head[u]]<T.depth[head[v]]){\n     \
    \   path_v.emplace_back(id[v],id[head[v]]);\n        v=T.parent(head[v]);\n  \
    \    }\n      else{\n        path_u.emplace_back(id[u],id[head[u]]);\n       \
    \ u=T.parent(head[u]);\n      }\n    }\n    if(u==v)path_u.emplace_back(id[u],id[u]);\n\
    \    return {path_u,path_v};\n  }\n\n  // [l,r) \u304C v \u306E\u90E8\u5206\u6728\
    \n  pair<int,int> subtree(int v){\n    assert(prepared);\n    return {id[v],id2[v]};\
    \ \n  }\n};\n#line 5 \"library/tree/TreeMonoid.cpp\"\ntemplate<typename TREE,typename\
    \ Monoid>\nstruct TreeMonoid{\n  using X=typename Monoid::value_type;\n  using\
    \ Monoid_r=AlgebraReverse<Monoid>;\n  int n;\n  TREE T;\n  HLD<Tree> hld;\n  vector<int>\
    \ hld_id,euler_in,euler_out;\n  SegmentTree<Monoid> seg;\n  SegmentTree<Monoid_r>\
    \ seg_r; \n  \n  TreeMonoid(TREE T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){\n\
    \    T.build(r);\n    hld_id=hld.build(r);\n  }\n  TreeMonoid(TREE T,vector<X>\
    \ a,int r=0):T(T),hld(T),n(T.n){\n    T.build(r);\n    hld_id=hld.build(r);\n\
    \    vector<X> hld_a(n);\n    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];\n   \
    \ seg=SegmentTree<Monoid>(hld_a);\n    if(!Monoid::commute)seg_r=SegmentTree<Monoid_r>(hld_a);\n\
    \  }\n\n  void set(int v,X x){\n    seg.set(hld_id[v],x);\n    if(!Monoid::commute)seg_r.set(hld_id[v],x);\n\
    \  }\n  void multiply(int v,X x){\n    seg.multiply(hld_id[v],x);\n    if(!Monoid::commute)seg_r.multiply(hld_id[v],x);\n\
    \  }\n  X get(int v){ return seg.get(hld_id[v]); }\n  \n  // [u,v]\u30D1\u30B9\
    \u306E monoid \u7A4D\n  X path_prod(int u,int v){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    X prod_u=Monoid::unit(),prod_v=Monoid::unit();\n    for(const auto&[l,r]:path_u){\n\
    \      X val=(Monoid::commute?seg.prod(r,l+1):seg_r.prod(r,l+1));\n      Monoid::Rchop(prod_u,val);\n\
    \    }\n    for(const auto&[l,r]:path_v){\n      X val=seg.prod(r,l+1);\n    \
    \  Monoid::Lchop(val,prod_v);\n    }\n    return Monoid::op(prod_u,prod_v);\n\
    \  }\n  // root -> path\n  X path_root(int v){ return path(T.root,v); }\n\n  X\
    \ subtree_prod(int v){\n    assert(Monoid::commute);\n    auto [l,r]=hld.subtree(v);\n\
    \    return seg.prod(l,r);\n  }\n};\n#line 8 \"test/library-checker/Tree/vertex_add_path_sum.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  using\
    \ G=GroupAdd<long long>;\n\n  int n,q;cin>>n>>q; \n  vector<long long> a(n);\n\
    \  for(int i=0;i<n;i++)cin>>a[i];\n\n  Tree t(n);\n  t.scan(0);\n\n  TreeMonoid<Tree,G>\
    \ TM(t,a);\n\n  while(q--){\n    int c;cin>>c;\n    if(c){\n      int u,v;cin>>u>>v;\n\
    \      cout<< TM.path_prod(u,v) <<\"\\n\";\n    }\n    else{\n      int p,x;cin>>p>>x;\n\
    \      TM.multiply(p,x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/algebra/group/Add.cpp\"\
    \n#include \"library/tree/Tree.cpp\"\n#include \"library/tree/TreeMonoid.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  using\
    \ G=GroupAdd<long long>;\n\n  int n,q;cin>>n>>q; \n  vector<long long> a(n);\n\
    \  for(int i=0;i<n;i++)cin>>a[i];\n\n  Tree t(n);\n  t.scan(0);\n\n  TreeMonoid<Tree,G>\
    \ TM(t,a);\n\n  while(q--){\n    int c;cin>>c;\n    if(c){\n      int u,v;cin>>u>>v;\n\
    \      cout<< TM.path_prod(u,v) <<\"\\n\";\n    }\n    else{\n      int p,x;cin>>p>>x;\n\
    \      TM.multiply(p,x);\n    }\n  }\n}"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/tree/Tree.cpp
  - library/graph/Graph.cpp
  - library/tree/TreeMonoid.cpp
  - library/segtree/SegmentTree.cpp
  - library/algebra/Reverse.cpp
  - library/tree/HLD.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Tree/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/vertex_add_path_sum.test.cpp
- /verify/test/library-checker/Tree/vertex_add_path_sum.test.cpp.html
title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
---
