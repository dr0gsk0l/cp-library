---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  - icon: ':x:'
    path: library/algebra/lazy/Reverse.cpp
    title: library/algebra/lazy/Reverse.cpp
  - icon: ':question:'
    path: library/segtree/LazySegmentTree.cpp
    title: library/segtree/LazySegmentTree.cpp
  - icon: ':question:'
    path: library/tree/HLD.cpp
    title: library/tree/HLD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/LazySegmentTree.cpp\"\n\ntemplate<typename\
    \ Lazy>\nclass LazySegmentTree{\n  using MX = typename Lazy::MX;\n  using MF =\
    \ typename Lazy::MF;\n  using X = typename MX::value_type;\n  using F = typename\
    \ MF::value_type;\n  int n,log,size;\n  vector<X> dat;\n  vector<F> laz;\n\n \
    \ X reflect(int k){\n    if(k<size)return Lazy::mapping(laz[k],dat[k]);\n    return\
    \ dat[k];\n  }\n  void point_apply(int k,const F&f){\n    if(k<size)MF::Lchop(f,laz[k]);\n\
    \    else dat[k]=Lazy::mapping(f,dat[k]);\n  }\n  void push(int k){\n    dat[k]=reflect(k);\n\
    \    point_apply(2*k,laz[k]);\n    point_apply(2*k+1,laz[k]);\n    laz[k]=MF::unit();\n\
    \  }\n  void thrust(int k){ for(int i=log;i;i--)push(k>>i); }\n  void update(int\
    \ i){ dat[i]=MX::op(reflect(2*i),reflect(2*i+1)); }\n  void recalc(int k){ while(k>>=1)update(k);\
    \ }\n\npublic:\n  LazySegmentTree() : LazySegmentTree(0) {}\n  LazySegmentTree(int\
    \ n):LazySegmentTree(vector<X>(n,MX::unit())) {}\n  LazySegmentTree(const vector<X>&v)\
    \ : n(v.size()) {\n    for(log=1;(1<<log)<n;log++){}\n    size=1<<log;\n    dat.assign(size<<1,MX::unit());\n\
    \    laz.assign(size,MF::unit());\n    for(int i=0;i<n;++i)dat[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;--i)update(i);\n  }\n\n  void set(int p,X x){\n   \
    \ assert(0<=p and p<n);\n    thrust(p+=size);\n    dat[p]=x;\n    recalc(p);\n\
    \  }\n\n  X operator[](int p){\n    assert(0<=p and p<n);\n    thrust(p+=size);\n\
    \    return reflect(p);\n  }\n\n  X prod(int L,int R){\n    assert(0<=L and L<=R\
    \ and R<=n);\n    if(L==R)return MX::unit();\n    thrust(L+=size);\n    thrust((R+=size-1)++);\n\
    \    X vl=MX::unit(),vr=MX::unit();\n    while(L<R){\n      if(L&1)MX::Rchop(vl,reflect(L++));\n\
    \      if(R&1)MX::Lchop(reflect(--R),vr);\n      L>>=1,R>>=1;\n    }\n    return\
    \ MX::op(vl,vr);\n  }\n\n  void apply(int l,int r,F f){\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if(l==r)return;\n    thrust(l+=size);\n    thrust(r+=size-1);\n\
    \    for(int L=l,R=r+1;L<R;L>>=1,R>>=1){\n      if(L&1)point_apply(L++,f);\n \
    \     if(R&1)point_apply(--R,f);\n    }\n    recalc(l);\n    recalc(r);\n  }\n\
    };\n#line 2 \"library/algebra/Reverse.cpp\"\ntemplate<typename Algebra>\nstruct\
    \ AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static constexpr\
    \ X op(const X& x, const X& y){ return Algebra::op(y,x); }\n  static constexpr\
    \ void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static constexpr void Lchop(const\
    \ X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 3 \"library/algebra/lazy/Reverse.cpp\"\
    \ntemplate<typename Lazy>\nstruct LazyReverse:Lazy{\n  using MX=AlgebraReverse<typename\
    \ Lazy::MX>;\n};\n#line 2 \"library/tree/HLD.cpp\"\ntemplate<typename TREE>\n\
    struct HLD{\n  int n;\n  TREE T;\n  vector<int> sz,head,id,id2;\n  bool prepared;\n\
    \  HLD(TREE T_):T(T_),n(T_.n),sz(n),head(n),id(n),id2(n),prepared(false){}\n \
    \ HLD()=default;\nprivate:\n  void dfs_sz(int v){\n    sz[v]=1;\n    for(auto&e:T.son(v)){\n\
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
    \ \n  }\n};\n#line 5 \"library/tree/TreeLazy.cpp\"\ntemplate<typename TREE,typename\
    \ Lazy>\nstruct TreeLazy{\n  using MX=typename Lazy::MX;\n  using MF=typename\
    \ Lazy::MF;\n  using X=typename MX::value_type;\n  using F=typename MF::value_type;\n\
    \  using Lazy_r=LazyReverse<Lazy>;\n  int n;\n  TREE&T;\n  HLD<Tree> hld;\n  vector<int>\
    \ hld_id,euler_in,euler_out;\n  LazySegmentTree<Lazy> seg;\n  LazySegmentTree<Lazy_r>\
    \ seg_r; \n  \n  TreeLazy(const TREE&T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){\n\
    \    T.build(r);\n    hld_id=hld.build(r);\n  }\n  TreeLazy(const TREE&T,vector<X>\
    \ a,int r=0):T(T),hld(T),n(T.n){\n    T.build(r);\n    hld_id=hld.build(r);\n\
    \    vector<X> hld_a(n);\n    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];\n   \
    \ seg=LazySegmentTree<Lazy>(hld_a);\n    if(!MX::commute)seg_r=LazySegmentTree<Lazy_r>(hld_a);\n\
    \  }\n\n  void set(int v,X x){\n    seg.set(hld_id[v],x);\n    if(!MX::commute)seg_r.set(hld_id[v],x);\n\
    \  }\n  void multiply(int v,X x){\n    seg.multiply(hld_id[v],x);\n    if(!MX::commute)seg_r.multiply(hld_id[v],x);\n\
    \  }\n  X get(int v){ return seg.get(hld_id[v]); }\n  \n  // [u,v]\u30D1\u30B9\
    \u306E monoid \u7A4D\n  X path_prod(int u,int v){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    X prod_u=MX::unit(),prod_v=MX::unit();\n    for(const auto&[l,r]:path_u){\n\
    \      X val=(MX::commute?seg.prod(r,l+1):seg_r.prod(r,l+1));\n      MX::Rchop(prod_u,val);\n\
    \    }\n    for(const auto&[l,r]:path_v){\n      X val=seg.prod(r,l+1);\n    \
    \  MX::Lchop(val,prod_v);\n    }\n    return MX::op(prod_u,prod_v);\n  }\n  //\
    \ root -> path\n  X path_root_prod(int v){ return path_prod(T.root,v); }\n\n \
    \ void path_apply(int u,int v,const F&f){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    for(const auto&[l,r]:path_u){\n      seg.apply(r,l+1,f);\n      if(!MX::commute)seg_r.apply(r,l+1,f);\n\
    \    }\n    for(const auto&[l,r]:path_v){\n      seg.apply(r,l+1,f);\n      if(!MX::commute)seg_r.apply(r,l+1,f);\n\
    \    }\n  }\n  void path_root_apply(int v,const F&f){ path_apply(T.root,v,f);\
    \ }\n\n  X subtree_prod(int v){\n    assert(MX::commute);\n    auto [l,r]=hld.subtree(v);\n\
    \    return seg.prod(l,r);\n  }\n  void subtree_apply(int v,const F&f){\n    auto\
    \ [l,r]=hld.subtree(v);\n    seg.apply(l,r,f);\n    if(!MX::commute)seg_r.apply(l,r,f);\n\
    \  }\n};\n"
  code: "#pragma once\n#include \"library/segtree/LazySegmentTree.cpp\"\n#include\
    \ \"library/algebra/lazy/Reverse.cpp\"\n#include \"library/tree/HLD.cpp\"\ntemplate<typename\
    \ TREE,typename Lazy>\nstruct TreeLazy{\n  using MX=typename Lazy::MX;\n  using\
    \ MF=typename Lazy::MF;\n  using X=typename MX::value_type;\n  using F=typename\
    \ MF::value_type;\n  using Lazy_r=LazyReverse<Lazy>;\n  int n;\n  TREE&T;\n  HLD<Tree>\
    \ hld;\n  vector<int> hld_id,euler_in,euler_out;\n  LazySegmentTree<Lazy> seg;\n\
    \  LazySegmentTree<Lazy_r> seg_r; \n  \n  TreeLazy(const TREE&T,int r=0):T(T),hld(T),n(T.n),seg(n),seg_r(n){\n\
    \    T.build(r);\n    hld_id=hld.build(r);\n  }\n  TreeLazy(const TREE&T,vector<X>\
    \ a,int r=0):T(T),hld(T),n(T.n){\n    T.build(r);\n    hld_id=hld.build(r);\n\
    \    vector<X> hld_a(n);\n    for(int v=0;v<n;v++)hld_a[hld_id[v]]=a[v];\n   \
    \ seg=LazySegmentTree<Lazy>(hld_a);\n    if(!MX::commute)seg_r=LazySegmentTree<Lazy_r>(hld_a);\n\
    \  }\n\n  void set(int v,X x){\n    seg.set(hld_id[v],x);\n    if(!MX::commute)seg_r.set(hld_id[v],x);\n\
    \  }\n  void multiply(int v,X x){\n    seg.multiply(hld_id[v],x);\n    if(!MX::commute)seg_r.multiply(hld_id[v],x);\n\
    \  }\n  X get(int v){ return seg.get(hld_id[v]); }\n  \n  // [u,v]\u30D1\u30B9\
    \u306E monoid \u7A4D\n  X path_prod(int u,int v){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    X prod_u=MX::unit(),prod_v=MX::unit();\n    for(const auto&[l,r]:path_u){\n\
    \      X val=(MX::commute?seg.prod(r,l+1):seg_r.prod(r,l+1));\n      MX::Rchop(prod_u,val);\n\
    \    }\n    for(const auto&[l,r]:path_v){\n      X val=seg.prod(r,l+1);\n    \
    \  MX::Lchop(val,prod_v);\n    }\n    return MX::op(prod_u,prod_v);\n  }\n  //\
    \ root -> path\n  X path_root_prod(int v){ return path_prod(T.root,v); }\n\n \
    \ void path_apply(int u,int v,const F&f){\n    auto [path_u,path_v]=hld.path(u,v);\n\
    \    for(const auto&[l,r]:path_u){\n      seg.apply(r,l+1,f);\n      if(!MX::commute)seg_r.apply(r,l+1,f);\n\
    \    }\n    for(const auto&[l,r]:path_v){\n      seg.apply(r,l+1,f);\n      if(!MX::commute)seg_r.apply(r,l+1,f);\n\
    \    }\n  }\n  void path_root_apply(int v,const F&f){ path_apply(T.root,v,f);\
    \ }\n\n  X subtree_prod(int v){\n    assert(MX::commute);\n    auto [l,r]=hld.subtree(v);\n\
    \    return seg.prod(l,r);\n  }\n  void subtree_apply(int v,const F&f){\n    auto\
    \ [l,r]=hld.subtree(v);\n    seg.apply(l,r,f);\n    if(!MX::commute)seg_r.apply(l,r,f);\n\
    \  }\n};"
  dependsOn:
  - library/segtree/LazySegmentTree.cpp
  - library/algebra/lazy/Reverse.cpp
  - library/algebra/Reverse.cpp
  - library/tree/HLD.cpp
  isVerificationFile: false
  path: library/tree/TreeLazy.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/tree/TreeLazy.cpp
layout: document
redirect_from:
- /library/library/tree/TreeLazy.cpp
- /library/library/tree/TreeLazy.cpp.html
title: library/tree/TreeLazy.cpp
---
