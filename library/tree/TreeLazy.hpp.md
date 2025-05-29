---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.hpp
    title: library/algebra/Reverse.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/Reverse.hpp
    title: library/algebra/lazy/Reverse.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/LazySegmentTree.hpp
    title: library/segtree/LazySegmentTree.hpp
  - icon: ':question:'
    path: library/tree/HLD.hpp
    title: library/tree/HLD.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/Reverse.hpp\"\ntemplate<typename Algebra>\n\
    struct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static\
    \ constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n  static\
    \ constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static constexpr\
    \ void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 3 \"library/algebra/lazy/Reverse.hpp\"\
    \ntemplate <typename Lazy> struct LazyReverse : Lazy {\n    using MX = AlgebraReverse<typename\
    \ Lazy::MX>;\n};\n#line 2 \"library/segtree/LazySegmentTree.hpp\"\n\ntemplate\
    \ <typename Lazy> class LazySegmentTree {\n    using MX = typename Lazy::MX;\n\
    \    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n \
    \   using F = typename MF::value_type;\n    int n, log, size;\n    std::vector<X>\
    \ dat;\n    std::vector<F> laz;\n\n    X reflect(int k) {\n        if (k < size)\n\
    \            return Lazy::mapping(laz[k], dat[k]);\n        return dat[k];\n \
    \   }\n    void point_apply(int k, const F &f) {\n        if (k < size)\n    \
    \        MF::Lchop(f, laz[k]);\n        else\n            dat[k] = Lazy::mapping(f,\
    \ dat[k]);\n    }\n    void push(int k) {\n        dat[k] = reflect(k);\n    \
    \    point_apply(2 * k, laz[k]);\n        point_apply(2 * k + 1, laz[k]);\n  \
    \      laz[k] = MF::unit();\n    }\n    void thrust(int k) {\n        for (int\
    \ i = log; i; i--)\n            push(k >> i);\n    }\n    void update(int i) {\
    \ dat[i] = MX::op(reflect(2 * i), reflect(2 * i + 1)); }\n    void recalc(int\
    \ k) {\n        while (k >>= 1)\n            update(k);\n    }\n\n  public:\n\
    \    LazySegmentTree() : LazySegmentTree(0) {}\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<X>(n,\
    \ MX::unit())) {}\n    LazySegmentTree(const std::vector<X> &v) : n(v.size())\
    \ {\n        for (log = 1; (1 << log) < n; log++) {\n        }\n        size =\
    \ 1 << log;\n        dat.assign(size << 1, MX::unit());\n        laz.assign(size,\
    \ MF::unit());\n        for (int i = 0; i < n; ++i)\n            dat[size + i]\
    \ = v[i];\n        for (int i = size - 1; i >= 1; --i)\n            update(i);\n\
    \    }\n\n    void set(int p, X x) {\n        assert(0 <= p and p < n);\n    \
    \    thrust(p += size);\n        dat[p] = x;\n        recalc(p);\n    }\n\n  \
    \  X operator[](int p) {\n        assert(0 <= p and p < n);\n        thrust(p\
    \ += size);\n        return reflect(p);\n    }\n\n    X prod(int L, int R) {\n\
    \        assert(0 <= L and L <= R and R <= n);\n        if (L == R)\n        \
    \    return MX::unit();\n        thrust(L += size);\n        thrust((R += size\
    \ - 1)++);\n        X vl = MX::unit(), vr = MX::unit();\n        while (L < R)\
    \ {\n            if (L & 1)\n                MX::Rchop(vl, reflect(L++));\n  \
    \          if (R & 1)\n                MX::Lchop(reflect(--R), vr);\n        \
    \    L >>= 1, R >>= 1;\n        }\n        return MX::op(vl, vr);\n    }\n\n \
    \   void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r)\n            return;\n        thrust(l += size);\n      \
    \  thrust(r += size - 1);\n        for (int L = l, R = r + 1; L < R; L >>= 1,\
    \ R >>= 1) {\n            if (L & 1)\n                point_apply(L++, f);\n \
    \           if (R & 1)\n                point_apply(--R, f);\n        }\n    \
    \    recalc(l);\n        recalc(r);\n    }\n};\n#line 2 \"library/tree/HLD.hpp\"\
    \ntemplate <typename TREE> struct HLD {\n    int n;\n    TREE T;\n    std::vector<int>\
    \ sz, head, id, id2, rev_id;\n    bool prepared;\n    HLD(TREE T_)\n        :\
    \ T(T_), n(T_.n), sz(n), head(n), id(n), id2(n), rev_id(n), prepared(false) {}\n\
    \    HLD() = default;\n\n  private:\n    void dfs_sz(int v) {\n        sz[v] =\
    \ 1;\n        for (auto &e : T.son(v)) {\n            dfs_sz(e.to);\n        \
    \    sz[v] += sz[e.to];\n            if (sz[e.to] > sz[T.son(v)[0].to])\n    \
    \            std::swap(e, T.son(v)[0]);\n        }\n    }\n    void dfs_hld(int\
    \ v, int &k) {\n        id[v] = k++;\n        rev_id[id[v]] = v;\n        for\
    \ (int i = 0; i < T.son(v).size(); i++) {\n            int to = T.son(v)[i];\n\
    \            head[to] = (i ? to : head[v]);\n            dfs_hld(to, k);\n   \
    \     }\n        id2[v] = k;\n    }\n\n  public:\n    std::vector<int> build(int\
    \ r = 0) {\n        assert(!prepared);\n        prepared = true;\n        if (~T.root)\n\
    \            assert(T.root == r);\n        else\n            T.build(r);\n   \
    \     head[r] = r;\n        dfs_sz(r);\n        int k = 0;\n        dfs_hld(r,\
    \ k);\n        return id;\n    }\n\n    int lca(int u, int v) const {\n      \
    \  assert(prepared);\n        while (head[u] != head[v])\n            if (T.depth[head[u]]\
    \ > T.depth[head[v]])\n                u = T.parent(head[u]);\n            else\n\
    \                v = T.parent(head[v]);\n        return (T.depth[u] < T.depth[v]\
    \ ? u : v);\n    }\n    int distance(int u, int v) const {\n        int w = lca(u,\
    \ v);\n        return T.depth[u] + T.depth[v] - T.depth[w] * 2;\n    }\n\n   \
    \ // v \u306E k \u500B\u4E0A\u306E\u9802\u70B9\u3092\u8FD4\u3059\n    int kth_parent(int\
    \ v, int k) const {\n        assert(prepared);\n        if(T.depth[v] < k)\n \
    \           return -1;\n        while(T.depth[v] - T.depth[head[v]] < k){\n  \
    \          k -= T.depth[v] - T.depth[head[v]] + 1;\n            v = T.parent(head[v]);\n\
    \        }\n        return rev_id[id[v] - k];\n    }\n\n    // u \u304B\u3089\
    \ v \u3078 k \u56DE\u79FB\u52D5\u3057\u305F\u9802\u70B9\u3092\u8FD4\u3059\n  \
    \  int jump(int u, int v, int k) const {\n        assert(prepared);\n        int\
    \ w = lca(u, v);\n        if(T.depth[u] + T.depth[v] - T.depth[w] * 2 < k)\n \
    \           return -1;\n        if(T.depth[u] - T.depth[w] >= k)\n           \
    \ return kth_parent(u, k);\n        return kth_parent(v, T.depth[u] + T.depth[v]\
    \ - T.depth[w] * 2 - k);\n    }\n\n    // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001\
    [u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\
    \u307F\u3067\u8FD4\u3059\n    using path_t = std::vector<std::pair<int, int>>;\n\
    \    std::pair<path_t, path_t> path(int u, int v) const {\n        assert(prepared);\n\
    \        path_t path_u, path_v;\n        while (u != v) {\n            if (head[u]\
    \ == head[v]) {\n                if (T.depth[u] < T.depth[v])\n              \
    \      path_v.emplace_back(id[v], id[u]);\n                else\n            \
    \        path_u.emplace_back(id[u], id[v]);\n                break;\n        \
    \    }\n            if (T.depth[head[u]] < T.depth[head[v]]) {\n             \
    \   path_v.emplace_back(id[v], id[head[v]]);\n                v = T.parent(head[v]);\n\
    \            } else {\n                path_u.emplace_back(id[u], id[head[u]]);\n\
    \                u = T.parent(head[u]);\n            }\n        }\n        if\
    \ (u == v)\n            path_u.emplace_back(id[u], id[u]);\n        return {path_u,\
    \ path_v};\n    }\n\n    // [l,r) \u304C v \u306E\u90E8\u5206\u6728\n    std::pair<int,\
    \ int> subtree(int v) const {\n        assert(prepared);\n        return {id[v],\
    \ id2[v]};\n    }\n};\n#line 5 \"library/tree/TreeLazy.hpp\"\ntemplate <typename\
    \ TREE, typename Lazy> struct TreeLazy {\n    using MX = typename Lazy::MX;\n\
    \    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n \
    \   using F = typename MF::value_type;\n    using Lazy_r = LazyReverse<Lazy>;\n\
    \    int n;\n    TREE T;\n    HLD<Tree> hld;\n    std::vector<int> hld_id, euler_in,\
    \ euler_out;\n    LazySegmentTree<Lazy> seg;\n    LazySegmentTree<Lazy_r> seg_r;\n\
    \n    TreeLazy(const TREE &T_, int r = 0)\n        : T(T_), hld(T_), n(T_.n),\
    \ seg(n), seg_r(n) {\n        T.build(r);\n        hld_id = hld.build(r);\n  \
    \  }\n    TreeLazy(const TREE &T_, std::vector<X> a, int r = 0)\n        : T(T_),\
    \ hld(T_), n(T_.n) {\n        T.build(r);\n        hld_id = hld.build(r);\n  \
    \      std::vector<X> hld_a(n);\n        for (int v = 0; v < n; v++)\n       \
    \     hld_a[hld_id[v]] = a[v];\n        seg = LazySegmentTree<Lazy>(hld_a);\n\
    \        if (!MX::commute)\n            seg_r = LazySegmentTree<Lazy_r>(hld_a);\n\
    \    }\n\n    void set(int v, X x) {\n        seg.set(hld_id[v], x);\n       \
    \ if (!MX::commute)\n            seg_r.set(hld_id[v], x);\n    }\n    void multiply(int\
    \ v, X x) {\n        seg.multiply(hld_id[v], x);\n        if (!MX::commute)\n\
    \            seg_r.multiply(hld_id[v], x);\n    }\n    X get(int v) { return seg.get(hld_id[v]);\
    \ }\n\n    // [u,v]\u30D1\u30B9\u306E monoid \u7A4D\n    X path_prod(int u, int\
    \ v) {\n        auto [path_u, path_v] = hld.path(u, v);\n        X prod_u = MX::unit(),\
    \ prod_v = MX::unit();\n        for (const auto &[l, r] : path_u) {\n        \
    \    X val = (MX::commute ? seg.prod(r, l + 1) : seg_r.prod(r, l + 1));\n    \
    \        MX::Rchop(prod_u, val);\n        }\n        for (const auto &[l, r] :\
    \ path_v) {\n            X val = seg.prod(r, l + 1);\n            MX::Lchop(val,\
    \ prod_v);\n        }\n        return MX::op(prod_u, prod_v);\n    }\n    // root\
    \ -> path\n    X path_root_prod(int v) { return path_prod(T.root, v); }\n\n  \
    \  void path_apply(int u, int v, const F &f) {\n        auto [path_u, path_v]\
    \ = hld.path(u, v);\n        for (const auto &[l, r] : path_u) {\n           \
    \ seg.apply(r, l + 1, f);\n            if (!MX::commute)\n                seg_r.apply(r,\
    \ l + 1, f);\n        }\n        for (const auto &[l, r] : path_v) {\n       \
    \     seg.apply(r, l + 1, f);\n            if (!MX::commute)\n               \
    \ seg_r.apply(r, l + 1, f);\n        }\n    }\n    void path_root_apply(int v,\
    \ const F &f) { path_apply(T.root, v, f); }\n\n    X subtree_prod(int v) {\n \
    \       assert(MX::commute);\n        auto [l, r] = hld.subtree(v);\n        return\
    \ seg.prod(l, r);\n    }\n    void subtree_apply(int v, const F &f) {\n      \
    \  auto [l, r] = hld.subtree(v);\n        seg.apply(l, r, f);\n        if (!MX::commute)\n\
    \            seg_r.apply(l, r, f);\n    }\n};\n"
  code: "#pragma once\n#include \"library/algebra/lazy/Reverse.hpp\"\n#include \"\
    library/segtree/LazySegmentTree.hpp\"\n#include \"library/tree/HLD.hpp\"\ntemplate\
    \ <typename TREE, typename Lazy> struct TreeLazy {\n    using MX = typename Lazy::MX;\n\
    \    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n \
    \   using F = typename MF::value_type;\n    using Lazy_r = LazyReverse<Lazy>;\n\
    \    int n;\n    TREE T;\n    HLD<Tree> hld;\n    std::vector<int> hld_id, euler_in,\
    \ euler_out;\n    LazySegmentTree<Lazy> seg;\n    LazySegmentTree<Lazy_r> seg_r;\n\
    \n    TreeLazy(const TREE &T_, int r = 0)\n        : T(T_), hld(T_), n(T_.n),\
    \ seg(n), seg_r(n) {\n        T.build(r);\n        hld_id = hld.build(r);\n  \
    \  }\n    TreeLazy(const TREE &T_, std::vector<X> a, int r = 0)\n        : T(T_),\
    \ hld(T_), n(T_.n) {\n        T.build(r);\n        hld_id = hld.build(r);\n  \
    \      std::vector<X> hld_a(n);\n        for (int v = 0; v < n; v++)\n       \
    \     hld_a[hld_id[v]] = a[v];\n        seg = LazySegmentTree<Lazy>(hld_a);\n\
    \        if (!MX::commute)\n            seg_r = LazySegmentTree<Lazy_r>(hld_a);\n\
    \    }\n\n    void set(int v, X x) {\n        seg.set(hld_id[v], x);\n       \
    \ if (!MX::commute)\n            seg_r.set(hld_id[v], x);\n    }\n    void multiply(int\
    \ v, X x) {\n        seg.multiply(hld_id[v], x);\n        if (!MX::commute)\n\
    \            seg_r.multiply(hld_id[v], x);\n    }\n    X get(int v) { return seg.get(hld_id[v]);\
    \ }\n\n    // [u,v]\u30D1\u30B9\u306E monoid \u7A4D\n    X path_prod(int u, int\
    \ v) {\n        auto [path_u, path_v] = hld.path(u, v);\n        X prod_u = MX::unit(),\
    \ prod_v = MX::unit();\n        for (const auto &[l, r] : path_u) {\n        \
    \    X val = (MX::commute ? seg.prod(r, l + 1) : seg_r.prod(r, l + 1));\n    \
    \        MX::Rchop(prod_u, val);\n        }\n        for (const auto &[l, r] :\
    \ path_v) {\n            X val = seg.prod(r, l + 1);\n            MX::Lchop(val,\
    \ prod_v);\n        }\n        return MX::op(prod_u, prod_v);\n    }\n    // root\
    \ -> path\n    X path_root_prod(int v) { return path_prod(T.root, v); }\n\n  \
    \  void path_apply(int u, int v, const F &f) {\n        auto [path_u, path_v]\
    \ = hld.path(u, v);\n        for (const auto &[l, r] : path_u) {\n           \
    \ seg.apply(r, l + 1, f);\n            if (!MX::commute)\n                seg_r.apply(r,\
    \ l + 1, f);\n        }\n        for (const auto &[l, r] : path_v) {\n       \
    \     seg.apply(r, l + 1, f);\n            if (!MX::commute)\n               \
    \ seg_r.apply(r, l + 1, f);\n        }\n    }\n    void path_root_apply(int v,\
    \ const F &f) { path_apply(T.root, v, f); }\n\n    X subtree_prod(int v) {\n \
    \       assert(MX::commute);\n        auto [l, r] = hld.subtree(v);\n        return\
    \ seg.prod(l, r);\n    }\n    void subtree_apply(int v, const F &f) {\n      \
    \  auto [l, r] = hld.subtree(v);\n        seg.apply(l, r, f);\n        if (!MX::commute)\n\
    \            seg_r.apply(l, r, f);\n    }\n};"
  dependsOn:
  - library/algebra/lazy/Reverse.hpp
  - library/algebra/Reverse.hpp
  - library/segtree/LazySegmentTree.hpp
  - library/tree/HLD.hpp
  isVerificationFile: false
  path: library/tree/TreeLazy.hpp
  requiredBy: []
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/tree/TreeLazy.hpp
layout: document
redirect_from:
- /library/library/tree/TreeLazy.hpp
- /library/library/tree/TreeLazy.hpp.html
title: library/tree/TreeLazy.hpp
---
