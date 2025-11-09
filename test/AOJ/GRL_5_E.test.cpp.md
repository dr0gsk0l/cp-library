---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.hpp
    title: library/algebra/Reverse.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.hpp
    title: library/algebra/group/Add.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.hpp
    title: library/algebra/group/CntSum.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddSum.hpp
    title: library/algebra/lazy/AddSum.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/Reverse.hpp
    title: library/algebra/lazy/Reverse.hpp
  - icon: ':question:'
    path: library/graph/Graph.hpp
    title: library/graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/LazySegmentTree.hpp
    title: library/segtree/LazySegmentTree.hpp
  - icon: ':question:'
    path: library/tree/HLD.hpp
    title: library/tree/HLD.hpp
  - icon: ':question:'
    path: library/tree/Tree.hpp
    title: library/tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.hpp
    title: library/tree/TreeLazy.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
  bundledCode: "#line 1 \"test/AOJ/GRL_5_E.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#line 2 \"library/algebra/group/Add.hpp\"\ntemplate<typename X>\nstruct GroupAdd\
    \ {\n  using value_type = X;\n  static constexpr X op(const X &x, const X &y)\
    \ noexcept { return x + y; }\n  static constexpr void Rchop(X&x, const X&y){ x+=y;\
    \ }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr X unit()\
    \ { return X(0); }\n  static constexpr bool commute = true;\n};\n#line 1 \"library/algebra/group/CntSum.hpp\"\
    \ntemplate <typename X> struct GroupCntSum {\n    using P = std::pair<X, X>;\n\
    \    using value_type = P;\n    static constexpr P op(const P &x, const P &y)\
    \ {\n        return {x.first + y.first, x.second + y.second};\n    }\n    static\
    \ constexpr void Rchop(P &x, const P &y) {\n        x.first += y.first;\n    \
    \    x.second += y.second;\n    }\n    static constexpr void Lchop(const P &x,\
    \ P &y) {\n        y.first += x.first;\n        y.second += x.second;\n    }\n\
    \    static constexpr P inverse(const P &x) { return {-x.fi, -x.se}; }\n    static\
    \ constexpr P unit() { return {0, 0}; }\n    static constexpr bool commute = true;\n\
    };\ntemplate <typename X> std::vector<std::pair<X, X>> cnt_init(int n, const X\
    \ &x) {\n    return std::vector<std::pair<X, X>>(n, {x, 1});\n}\ntemplate <typename\
    \ X>\nstd::vector<std::pair<X, X>> cnt_init(const std::vector<X> &v) {\n    int\
    \ n = v.size();\n    std::vector<std::pair<X, X>> res(n);\n    for (int i = 0;\
    \ i < n; i++)\n        res[i] = {v[i], 1};\n    return res;\n}\n#line 4 \"library/algebra/lazy/AddSum.hpp\"\
    \ntemplate <typename X> struct LazyAddSum {\n    using MX = GroupCntSum<X>;\n\
    \    using MF = GroupAdd<X>;\n    using S = typename MX::value_type;\n    static\
    \ constexpr S mapping(const X &f, const S &x) {\n        return {x.first + f *\
    \ x.second, x.second};\n    }\n};\n#line 2 \"library/graph/Graph.hpp\"\n\n#line\
    \ 6 \"library/graph/Graph.hpp\"\n\nstruct Edge {\n    int from, to;\n    Edge()\
    \ = default;\n    Edge(int from, int to) : from(from), to(to) {}\n    operator\
    \ int() const { return to; }\n};\n\nstruct Graph {\n    int n;\n    using edge_type\
    \ = Edge;\n    std::vector<edge_type> edges;\n\n  protected:\n    std::vector<int>\
    \ in_deg;\n    bool prepared;\n    class OutgoingEdges {\n        Graph *g;\n\
    \        int l, r;\n\n      public:\n        OutgoingEdges(Graph *g, int l, int\
    \ r) : g(g), l(l), r(r) {}\n        edge_type *begin() { return &(g->edges[l]);\
    \ }\n        edge_type *end() { return &(g->edges[r]); }\n        edge_type &operator[](int\
    \ i) { return g->edges[l + i]; }\n        int size() const { return r - l; }\n\
    \    };\n    class ConstOutgoingEdges {\n        const Graph *g;\n        int\
    \ l, r;\n\n      public:\n        ConstOutgoingEdges(const Graph *g, int l, int\
    \ r) : g(g), l(l), r(r) {}\n        const edge_type *begin() const { return &(g->edges[l]);\
    \ }\n        const edge_type *end() const { return &(g->edges[r]); }\n       \
    \ const edge_type &operator[](int i) const { return g->edges[l + i]; }\n     \
    \   int size() const { return r - l; }\n    };\n\n  public:\n    OutgoingEdges\
    \ operator[](int v) {\n        assert(prepared);\n        return {this, in_deg[v],\
    \ in_deg[v + 1]};\n    }\n    const ConstOutgoingEdges operator[](int v) const\
    \ {\n        assert(prepared);\n        return {this, in_deg[v], in_deg[v + 1]};\n\
    \    }\n\n    bool is_prepared() const { return prepared; }\n\n    Graph() : n(0),\
    \ in_deg(1, 0), prepared(false) {}\n    Graph(int n) : n(n), in_deg(n + 1, 0),\
    \ prepared(false) {}\n    Graph(int n, int m, bool directed = false, int indexed\
    \ = 1)\n        : n(n), in_deg(n + 1, 0), prepared(false) {\n        scan(m, directed,\
    \ indexed);\n    }\n\n    void resize(int n) { n = n; }\n\n    void add_arc(int\
    \ from, int to) {\n        assert(!prepared);\n        assert(0 <= from and from\
    \ < n and 0 <= to and to < n);\n        edges.emplace_back(from, to);\n      \
    \  in_deg[from + 1]++;\n    }\n    void add_edge(int u, int v) {\n        add_arc(u,\
    \ v);\n        add_arc(v, u);\n    }\n    void add_arc(const edge_type &e) { add_arc(e.from,\
    \ e.to); }\n    void add_edge(const edge_type &e) { add_edge(e.from, e.to); }\n\
    \n    void scan(int m, bool directed = false, int indexed = 1) {\n        edges.reserve(directed\
    \ ? m : 2 * m);\n        while (m--) {\n            int u, v;\n            std::cin\
    \ >> u >> v;\n            u -= indexed;\n            v -= indexed;\n         \
    \   if (directed)\n                add_arc(u, v);\n            else\n        \
    \        add_edge(u, v);\n        }\n        build();\n    }\n\n    void build()\
    \ {\n        assert(!prepared);\n        prepared = true;\n        for (int v\
    \ = 0; v < n; v++)\n            in_deg[v + 1] += in_deg[v];\n        std::vector<edge_type>\
    \ new_edges(in_deg.back());\n        auto counter = in_deg;\n        for (auto\
    \ &&e : edges)\n            new_edges[counter[e.from]++] = e;\n        edges =\
    \ new_edges;\n    }\n\n    void graph_debug() const {\n#ifndef __LOCAL\n     \
    \   return;\n#endif\n        assert(prepared);\n        for (int from = 0; from\
    \ < n; from++) {\n            std::cerr << from << \";\";\n            for (int\
    \ i = in_deg[from]; i < in_deg[from + 1]; i++)\n                std::cerr << edges[i].to\
    \ << \" \";\n            std::cerr << \"\\n\";\n        }\n    }\n};\n#line 3\
    \ \"library/tree/Tree.hpp\"\nstruct Tree : Graph {\n    using Graph::Graph;\n\
    \    Tree() = default;\n    int root = -1;\n    std::vector<int> DFS, BFS, depth;\n\
    \n    void scan_root(int indexed = 1) {\n        for (int i = 1; i < n; i++) {\n\
    \            int p;\n            std::cin >> p;\n            add_edge(p - indexed,\
    \ i);\n        }\n        build();\n    }\n    void scan(int indexed = 1) {\n\
    \        Graph::scan(n - 1, false, indexed);\n        build();\n    }\n\n    edge_type\
    \ &parent(int v) {\n        assert(~root and root != v);\n        return (*this)[v][0];\n\
    \    }\n    const edge_type &parent(int v) const {\n        assert(~root and root\
    \ != v);\n        return (*this)[v][0];\n    }\n\n    OutgoingEdges son(int v)\
    \ {\n        assert(~root);\n        if (v == root)\n            return {this,\
    \ in_deg[v], in_deg[v + 1]};\n        return {this, in_deg[v] + 1, in_deg[v +\
    \ 1]};\n    }\n\n  private:\n    void dfs(int v, int pre = -1) {\n        for\
    \ (auto &e : (*this)[v]) {\n            if (e.to == pre)\n                std::swap((*this)[v][0],\
    \ e);\n            else {\n                depth[e.to] = depth[v] + 1;\n     \
    \           dfs(e.to, v);\n            }\n        }\n        DFS.push_back(v);\n\
    \    }\n\n  public:\n    void build(int r = 0) {\n        if (!is_prepared())\n\
    \            Graph::build();\n        if (~root) {\n            assert(r == root);\n\
    \            return;\n        }\n        root = r;\n        depth = std::vector<int>(n,\
    \ 0);\n        DFS.reserve(n);\n        BFS.reserve(n);\n        dfs(root);\n\
    \        std::queue<int> que;\n        que.push(root);\n        while (que.size())\
    \ {\n            int p = que.front();\n            que.pop();\n            BFS.push_back(p);\n\
    \            for (const auto &e : son(p))\n                que.push(e.to);\n \
    \       }\n    }\n};\n#line 2 \"library/algebra/Reverse.hpp\"\ntemplate<typename\
    \ Algebra>\nstruct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n\
    \  static constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n\
    \  static constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static\
    \ constexpr void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 3 \"\
    library/algebra/lazy/Reverse.hpp\"\ntemplate <typename Lazy> struct LazyReverse\
    \ : Lazy {\n    using MX = AlgebraReverse<typename Lazy::MX>;\n};\n#line 2 \"\
    library/segtree/LazySegmentTree.hpp\"\n\ntemplate <typename Lazy> class LazySegmentTree\
    \ {\n    using MX = typename Lazy::MX;\n    using MF = typename Lazy::MF;\n  \
    \  using X = typename MX::value_type;\n    using F = typename MF::value_type;\n\
    \    int n, log, size;\n    std::vector<X> dat;\n    std::vector<F> laz;\n\n \
    \   X reflect(int k) {\n        if (k < size)\n            return Lazy::mapping(laz[k],\
    \ dat[k]);\n        return dat[k];\n    }\n    void point_apply(int k, const F\
    \ &f) {\n        if (k < size)\n            MF::Lchop(f, laz[k]);\n        else\n\
    \            dat[k] = Lazy::mapping(f, dat[k]);\n    }\n    void push(int k) {\n\
    \        dat[k] = reflect(k);\n        point_apply(2 * k, laz[k]);\n        point_apply(2\
    \ * k + 1, laz[k]);\n        laz[k] = MF::unit();\n    }\n    void thrust(int\
    \ k) {\n        for (int i = log; i; i--)\n            push(k >> i);\n    }\n\
    \    void update(int i) { dat[i] = MX::op(reflect(2 * i), reflect(2 * i + 1));\
    \ }\n    void recalc(int k) {\n        while (k >>= 1)\n            update(k);\n\
    \    }\n\n  public:\n    LazySegmentTree() : LazySegmentTree(0) {}\n    LazySegmentTree(int\
    \ n) : LazySegmentTree(std::vector<X>(n, MX::unit())) {}\n    LazySegmentTree(const\
    \ std::vector<X> &v) : n(v.size()) {\n        for (log = 1; (1 << log) < n; log++)\
    \ {\n        }\n        size = 1 << log;\n        dat.assign(size << 1, MX::unit());\n\
    \        laz.assign(size, MF::unit());\n        for (int i = 0; i < n; ++i)\n\
    \            dat[size + i] = v[i];\n        for (int i = size - 1; i >= 1; --i)\n\
    \            update(i);\n    }\n\n    void set(int p, X x) {\n        assert(0\
    \ <= p and p < n);\n        thrust(p += size);\n        dat[p] = x;\n        recalc(p);\n\
    \    }\n\n    X operator[](int p) {\n        assert(0 <= p and p < n);\n     \
    \   thrust(p += size);\n        return reflect(p);\n    }\n\n    X prod(int L,\
    \ int R) {\n        assert(0 <= L and L <= R and R <= n);\n        if (L == R)\n\
    \            return MX::unit();\n        thrust(L += size);\n        thrust((R\
    \ += size - 1)++);\n        X vl = MX::unit(), vr = MX::unit();\n        while\
    \ (L < R) {\n            if (L & 1)\n                MX::Rchop(vl, reflect(L++));\n\
    \            if (R & 1)\n                MX::Lchop(reflect(--R), vr);\n      \
    \      L >>= 1, R >>= 1;\n        }\n        return MX::op(vl, vr);\n    }\n\n\
    \    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (l == r)\n            return;\n        thrust(l += size);\n\
    \        thrust(r += size - 1);\n        for (int L = l, R = r + 1; L < R; L >>=\
    \ 1, R >>= 1) {\n            if (L & 1)\n                point_apply(L++, f);\n\
    \            if (R & 1)\n                point_apply(--R, f);\n        }\n   \
    \     recalc(l);\n        recalc(r);\n    }\n};\n#line 2 \"library/tree/HLD.hpp\"\
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
    \            seg_r.apply(l, r, f);\n    }\n};\n#line 10 \"test/AOJ/GRL_5_E.test.cpp\"\
    \nusing ll = long long;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n\n    Tree t(n);\n\
    \    REP (i, n) {\n        int k;\n        std::cin >> k;\n        REP (_, k)\
    \ {\n            int c;\n            std::cin >> c;\n            t.add_edge(i,\
    \ c);\n        }\n    }\n    t.build(0);\n\n    TreeLazy<Tree, LazyAddSum<ll>>\
    \ TL(t, cnt_init(n, 0LL));\n    // \u8FBA\u306E\u60C5\u5831\u306F\u5B50\u306B\u6301\
    \u305F\u305B\u308B\n    // \u5404\u9802\u70B9 v \u306B\u3064\u3044\u3066\u3001\
    \u6839\u304B\u3089 1 \u79FB\u52D5\u3057\u305F\u70B9\u304C\u5FC5\u8981\n    //\
    \ Tree \u306B jump \u3092\u5B9F\u88C5\u3057\u3066\u306A\u3044\u306E\u3067\u7121\
    \u7406\u304F\u308A\u6C42\u3081\u308B\n    std::vector<int> root2(n, -1);\n   \
    \ for (int v : t.BFS) {\n        if (v == 0)\n            continue;\n        int\
    \ p = t.parent(v).to;\n        if (p == 0)\n            root2[v] = v;\n      \
    \  else\n            root2[v] = root2[p];\n    }\n\n    int q;\n    std::cin >>\
    \ q;\n    REP (_, q) {\n        int c;\n        std::cin >> c;\n        if (c)\
    \ {\n            int u;\n            std::cin >> u;\n            std::cout <<\
    \ TL.path_prod(u, root2[u]).first << \"\\n\";\n        } else {\n            int\
    \ v, w;\n            std::cin >> v >> w;\n            TL.path_apply(v, root2[v],\
    \ w);\n        }\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include \"library/algebra/lazy/AddSum.hpp\"\n#include \"library/tree/Tree.hpp\"\
    \n#include \"library/tree/TreeLazy.hpp\"\nusing ll = long long;\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int n;\n    std::cin >> n;\n\n    Tree t(n);\n    REP (i, n) {\n        int\
    \ k;\n        std::cin >> k;\n        REP (_, k) {\n            int c;\n     \
    \       std::cin >> c;\n            t.add_edge(i, c);\n        }\n    }\n    t.build(0);\n\
    \n    TreeLazy<Tree, LazyAddSum<ll>> TL(t, cnt_init(n, 0LL));\n    // \u8FBA\u306E\
    \u60C5\u5831\u306F\u5B50\u306B\u6301\u305F\u305B\u308B\n    // \u5404\u9802\u70B9\
    \ v \u306B\u3064\u3044\u3066\u3001\u6839\u304B\u3089 1 \u79FB\u52D5\u3057\u305F\
    \u70B9\u304C\u5FC5\u8981\n    // Tree \u306B jump \u3092\u5B9F\u88C5\u3057\u3066\
    \u306A\u3044\u306E\u3067\u7121\u7406\u304F\u308A\u6C42\u3081\u308B\n    std::vector<int>\
    \ root2(n, -1);\n    for (int v : t.BFS) {\n        if (v == 0)\n            continue;\n\
    \        int p = t.parent(v).to;\n        if (p == 0)\n            root2[v] =\
    \ v;\n        else\n            root2[v] = root2[p];\n    }\n\n    int q;\n  \
    \  std::cin >> q;\n    REP (_, q) {\n        int c;\n        std::cin >> c;\n\
    \        if (c) {\n            int u;\n            std::cin >> u;\n          \
    \  std::cout << TL.path_prod(u, root2[u]).first << \"\\n\";\n        } else {\n\
    \            int v, w;\n            std::cin >> v >> w;\n            TL.path_apply(v,\
    \ root2[v], w);\n        }\n    }\n}\n"
  dependsOn:
  - library/algebra/lazy/AddSum.hpp
  - library/algebra/group/Add.hpp
  - library/algebra/group/CntSum.hpp
  - library/tree/Tree.hpp
  - library/graph/Graph.hpp
  - library/tree/TreeLazy.hpp
  - library/algebra/lazy/Reverse.hpp
  - library/algebra/Reverse.hpp
  - library/segtree/LazySegmentTree.hpp
  - library/tree/HLD.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_5_E.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_E.test.cpp
- /verify/test/AOJ/GRL_5_E.test.cpp.html
title: test/AOJ/GRL_5_E.test.cpp
---
