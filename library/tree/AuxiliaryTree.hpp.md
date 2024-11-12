---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.hpp
    title: library/graph/Graph.hpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.hpp
    title: library/graph/WeightedGraph.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/HLD.hpp
    title: library/tree/HLD.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.hpp
    title: library/tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/WeightedTree.hpp
    title: library/tree/WeightedTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/util/Compress.hpp
    title: library/util/Compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/tree/AuxiliaryTree.hpp\"\n\n#line 2 \"library/tree/HLD.hpp\"\
    \ntemplate <typename TREE> struct HLD {\n    int n;\n    TREE T;\n    std::vector<int>\
    \ sz, head, id, id2;\n    bool prepared;\n    HLD(TREE T_)\n        : T(T_), n(T_.n),\
    \ sz(n), head(n), id(n), id2(n), prepared(false) {}\n    HLD() = default;\n\n\
    \  private:\n    void dfs_sz(int v) {\n        sz[v] = 1;\n        for (auto &e\
    \ : T.son(v)) {\n            dfs_sz(e.to);\n            sz[v] += sz[e.to];\n \
    \           if (sz[e.to] > sz[T.son(v)[0].to])\n                std::swap(e, T.son(v)[0]);\n\
    \        }\n    }\n    void dfs_hld(int v, int &k) {\n        id[v] = k++;\n \
    \       for (int i = 0; i < T.son(v).size(); i++) {\n            int to = T.son(v)[i];\n\
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
    \ // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\
    \u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\n    using\
    \ path_t = std::vector<std::pair<int, int>>;\n    std::pair<path_t, path_t> path(int\
    \ u, int v) const {\n        assert(prepared);\n        path_t path_u, path_v;\n\
    \        while (u != v) {\n            if (head[u] == head[v]) {\n           \
    \     if (T.depth[u] < T.depth[v])\n                    path_v.emplace_back(id[v],\
    \ id[u]);\n                else\n                    path_u.emplace_back(id[u],\
    \ id[v]);\n                break;\n            }\n            if (T.depth[head[u]]\
    \ < T.depth[head[v]]) {\n                path_v.emplace_back(id[v], id[head[v]]);\n\
    \                v = T.parent(head[v]);\n            } else {\n              \
    \  path_u.emplace_back(id[u], id[head[u]]);\n                u = T.parent(head[u]);\n\
    \            }\n        }\n        if (u == v)\n            path_u.emplace_back(id[u],\
    \ id[u]);\n        return {path_u, path_v};\n    }\n\n    // [l,r) \u304C v \u306E\
    \u90E8\u5206\u6728\n    std::pair<int, int> subtree(int v) const {\n        assert(prepared);\n\
    \        return {id[v], id2[v]};\n    }\n};\n#line 2 \"library/graph/Graph.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\nstruct Edge\
    \ {\n    int from, to;\n    Edge() = default;\n    Edge(int from, int to) : from(from),\
    \ to(to) {}\n    operator int() const { return to; }\n};\n\nstruct Graph {\n \
    \   int n;\n    using edge_type = Edge;\n    std::vector<edge_type> edges;\n\n\
    \  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n    class OutgoingEdges\
    \ {\n        Graph *g;\n        int l, r;\n\n      public:\n        OutgoingEdges(Graph\
    \ *g, int l, int r) : g(g), l(l), r(r) {}\n        edge_type *begin() { return\
    \ &(g->edges[l]); }\n        edge_type *end() { return &(g->edges[r]); }\n   \
    \     edge_type &operator[](int i) { return g->edges[l + i]; }\n        int size()\
    \ const { return r - l; }\n    };\n    class ConstOutgoingEdges {\n        const\
    \ Graph *g;\n        int l, r;\n\n      public:\n        ConstOutgoingEdges(const\
    \ Graph *g, int l, int r) : g(g), l(l), r(r) {}\n        const edge_type *begin()\
    \ const { return &(g->edges[l]); }\n        const edge_type *end() const { return\
    \ &(g->edges[r]); }\n        const edge_type &operator[](int i) const { return\
    \ g->edges[l + i]; }\n        int size() const { return r - l; }\n    };\n\n \
    \ public:\n    OutgoingEdges operator[](int v) {\n        assert(prepared);\n\
    \        return {this, in_deg[v], in_deg[v + 1]};\n    }\n    const ConstOutgoingEdges\
    \ operator[](int v) const {\n        assert(prepared);\n        return {this,\
    \ in_deg[v], in_deg[v + 1]};\n    }\n\n    bool is_prepared() const { return prepared;\
    \ }\n\n    Graph() : n(0), in_deg(1, 0), prepared(false) {}\n    Graph(int n)\
    \ : n(n), in_deg(n + 1, 0), prepared(false) {}\n    Graph(int n, int m, bool directed\
    \ = false, int indexed = 1)\n        : n(n), in_deg(n + 1, 0), prepared(false)\
    \ {\n        scan(m, directed, indexed);\n    }\n\n    void resize(int n) { n\
    \ = n; }\n\n    void add_arc(int from, int to) {\n        assert(!prepared);\n\
    \        assert(0 <= from and from < n and 0 <= to and to < n);\n        edges.emplace_back(from,\
    \ to);\n        in_deg[from + 1]++;\n    }\n    void add_edge(int u, int v) {\n\
    \        add_arc(u, v);\n        add_arc(v, u);\n    }\n    void add_arc(const\
    \ edge_type &e) { add_arc(e.from, e.to); }\n    void add_edge(const edge_type\
    \ &e) { add_edge(e.from, e.to); }\n\n    void scan(int m, bool directed = false,\
    \ int indexed = 1) {\n        edges.reserve(directed ? m : 2 * m);\n        while\
    \ (m--) {\n            int u, v;\n            std::cin >> u >> v;\n          \
    \  u -= indexed;\n            v -= indexed;\n            if (directed)\n     \
    \           add_arc(u, v);\n            else\n                add_edge(u, v);\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        prepared = true;\n        for (int v = 0; v < n; v++)\n            in_deg[v\
    \ + 1] += in_deg[v];\n        std::vector<edge_type> new_edges(in_deg.back());\n\
    \        auto counter = in_deg;\n        for (auto &&e : edges)\n            new_edges[counter[e.from]++]\
    \ = e;\n        edges = new_edges;\n    }\n\n    void graph_debug() const {\n\
    #ifndef __LOCAL\n        return;\n#endif\n        assert(prepared);\n        for\
    \ (int from = 0; from < n; from++) {\n            std::cerr << from << \";\";\n\
    \            for (int i = in_deg[from]; i < in_deg[from + 1]; i++)\n         \
    \       std::cerr << edges[i].to << \" \";\n            std::cerr << \"\\n\";\n\
    \        }\n    }\n};\n#line 3 \"library/tree/Tree.hpp\"\nstruct Tree : Graph\
    \ {\n    using Graph::Graph;\n    Tree() = default;\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       add_edge(p - indexed, i);\n        }\n        build();\n    }\n    void\
    \ scan(int indexed = 1) {\n        Graph::scan(n - 1, false, indexed);\n     \
    \   build();\n    }\n\n    edge_type &parent(int v) {\n        assert(~root and\
    \ root != v);\n        return (*this)[v][0];\n    }\n    const edge_type &parent(int\
    \ v) const {\n        assert(~root and root != v);\n        return (*this)[v][0];\n\
    \    }\n\n    OutgoingEdges son(int v) {\n        assert(~root);\n        if (v\
    \ == root)\n            return {this, in_deg[v], in_deg[v + 1]};\n        return\
    \ {this, in_deg[v] + 1, in_deg[v + 1]};\n    }\n\n  private:\n    void dfs(int\
    \ v, int pre = -1) {\n        for (auto &e : (*this)[v]) {\n            if (e.to\
    \ == pre)\n                std::swap((*this)[v][0], e);\n            else {\n\
    \                depth[e.to] = depth[v] + 1;\n                dfs(e.to, v);\n\
    \            }\n        }\n        DFS.push_back(v);\n    }\n\n  public:\n   \
    \ void build(int r = 0) {\n        if (!is_prepared())\n            Graph::build();\n\
    \        if (~root) {\n            assert(r == root);\n            return;\n \
    \       }\n        root = r;\n        depth = std::vector<int>(n, 0);\n      \
    \  DFS.reserve(n);\n        BFS.reserve(n);\n        dfs(root);\n        std::queue<int>\
    \ que;\n        que.push(root);\n        while (que.size()) {\n            int\
    \ p = que.front();\n            que.pop();\n            BFS.push_back(p);\n  \
    \          for (const auto &e : son(p))\n                que.push(e.to);\n   \
    \     }\n    }\n};\n#line 2 \"library/graph/WeightedGraph.hpp\"\ntemplate <typename\
    \ T> struct WeightedEdge {\n    WeightedEdge() = default;\n    WeightedEdge(int\
    \ from, int to, T weight)\n        : from(from), to(to), weight(weight) {}\n \
    \   int from, to;\n    T weight;\n    operator int() const { return to; }\n};\n\
    \ntemplate <typename T> struct WeightedGraph {\n    int n;\n    using weight_type\
    \ = T;\n    using edge_type = WeightedEdge<T>;\n    std::vector<edge_type> edges;\n\
    \n  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n    class OutgoingEdges\
    \ {\n        WeightedGraph *g;\n        int l, r;\n\n      public:\n        OutgoingEdges(WeightedGraph\
    \ *g, int l, int r) : g(g), l(l), r(r) {}\n        edge_type *begin() { return\
    \ &(g->edges[l]); }\n        edge_type *end() { return &(g->edges[r]); }\n   \
    \     edge_type &operator[](int i) { return g->edges[l + i]; }\n        int size()\
    \ const { return r - l; }\n    };\n    class ConstOutgoingEdges {\n        const\
    \ WeightedGraph *g;\n        int l, r;\n\n      public:\n        ConstOutgoingEdges(const\
    \ WeightedGraph *g, int l, int r)\n            : g(g), l(l), r(r) {}\n       \
    \ const edge_type *begin() const { return &(g->edges[l]); }\n        const edge_type\
    \ *end() const { return &(g->edges[r]); }\n        const edge_type &operator[](int\
    \ i) const { return g->edges[l + i]; }\n        int size() const { return r -\
    \ l; }\n    };\n\n  public:\n    OutgoingEdges operator[](int v) {\n        assert(prepared);\n\
    \        return {this, in_deg[v], in_deg[v + 1]};\n    }\n    const ConstOutgoingEdges\
    \ operator[](int v) const {\n        assert(prepared);\n        return {this,\
    \ in_deg[v], in_deg[v + 1]};\n    }\n\n    bool is_prepared() const { return prepared;\
    \ }\n\n    WeightedGraph() : n(0), in_deg(1, 0), prepared(false) {}\n    WeightedGraph(int\
    \ n) : n(n), in_deg(n + 1, 0), prepared(false) {}\n    WeightedGraph(int n, int\
    \ m, bool directed = false, int indexed = 1)\n        : n(n), in_deg(n + 1, 0),\
    \ prepared(false) {\n        scan(m, directed, indexed);\n    }\n\n    void resize(int\
    \ n) { n = n; }\n\n    void add_arc(int from, int to, T weight) {\n        assert(!prepared);\n\
    \        assert(0 <= from and from < n and 0 <= to and to < n);\n        edges.emplace_back(from,\
    \ to, weight);\n        in_deg[from + 1]++;\n    }\n    void add_edge(int u, int\
    \ v, T weight) {\n        add_arc(u, v, weight);\n        add_arc(v, u, weight);\n\
    \    }\n    void add_arc(const edge_type &e) { add_arc(e.from, e.to, e.weight);\
    \ }\n    void add_edge(const edge_type &e) { add_edge(e.from, e.to, e.weight);\
    \ }\n\n    void scan(int m, bool directed = false, int indexed = 1) {\n      \
    \  edges.reserve(directed ? m : 2 * m);\n        while (m--) {\n            int\
    \ u, v;\n            std::cin >> u >> v;\n            u -= indexed;\n        \
    \    v -= indexed;\n            T weight;\n            std::cin >> weight;\n \
    \           if (directed)\n                add_arc(u, v, weight);\n          \
    \  else\n                add_edge(u, v, weight);\n        }\n        build();\n\
    \    }\n\n    void build() {\n        assert(!prepared);\n        prepared = true;\n\
    \        for (int v = 0; v < n; v++)\n            in_deg[v + 1] += in_deg[v];\n\
    \        std::vector<edge_type> new_edges(in_deg.back());\n        auto counter\
    \ = in_deg;\n        for (auto &&e : edges)\n            new_edges[counter[e.from]++]\
    \ = e;\n        edges = new_edges;\n    }\n\n    void graph_debug() const {\n\
    #ifndef __DEBUG\n        return;\n#endif\n        assert(prepared);\n        for\
    \ (int from = 0; from < n; from++) {\n            std::cerr << from << \";\";\n\
    \            for (int i = in_deg[from]; i < in_deg[from + 1]; i++)\n         \
    \       std::cerr << \"(\" << edges[i].to << \",\" << edges[i].weight\n      \
    \                    << \")\";\n            std::cerr << \"\\n\";\n        }\n\
    \    }\n};\n#line 3 \"library/tree/WeightedTree.hpp\"\ntemplate <typename T> struct\
    \ WeightedTree : WeightedGraph<T> {\n    using WeightedGraph<T>::WeightedGraph;\n\
    \    using edge_type = typename WeightedGraph<T>::edge_type;\n    using OutgoingEdges\
    \ = typename WeightedGraph<T>::OutgoingEdges;\n    using WeightedGraph<T>::n;\n\
    \    using WeightedGraph<T>::in_deg;\n\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       T weight;\n            std::cin >> weight;\n            add_edge(p - indexed,\
    \ i, weight);\n        }\n        build();\n    }\n    void scan(int indexed =\
    \ 1) {\n        WeightedGraph<T>::scan(n - 1, false, indexed);\n        build();\n\
    \    }\n\n    edge_type &parent(int v) {\n        assert(~root and root != v);\n\
    \        return (*this)[v][0];\n    }\n    OutgoingEdges son(int v) {\n      \
    \  assert(~root);\n        if (v == root)\n            return {this, in_deg[v],\
    \ in_deg[v + 1]};\n        return {this, in_deg[v] + 1, in_deg[v + 1]};\n    }\n\
    \n  private:\n    void dfs(int v, int pre = -1) {\n        for (auto &e : (*this)[v])\
    \ {\n            if (e.to == pre)\n                std::swap((*this)[v][0], e);\n\
    \            else {\n                depth[e.to] = depth[v] + 1;\n           \
    \     dfs(e.to, v);\n            }\n        }\n        DFS.push_back(v);\n   \
    \ }\n\n  public:\n    void build(int r = 0) {\n        if (!WeightedGraph<T>::is_prepared())\n\
    \            WeightedGraph<T>::build();\n        if (~root) {\n            assert(r\
    \ == root);\n            return;\n        }\n        root = r;\n        depth\
    \ = std::vector<int>(n, 0);\n        DFS.reserve(n);\n        BFS.reserve(n);\n\
    \        dfs(root);\n        std::queue<int> que;\n        que.push(root);\n \
    \       while (que.size()) {\n            int p = que.front();\n            que.pop();\n\
    \            BFS.push_back(p);\n            for (const auto &e : son(p))\n   \
    \             que.push(e.to);\n        }\n    }\n};\n#line 2 \"library/util/Compress.hpp\"\
    \ntemplate <typename T, bool Sentinel = false> class Compress {\n    std::vector<T>\
    \ v;\n    bool prepared;\n\n  public:\n    Compress() : prepared(false) {\n  \
    \      if constexpr (Sentinel) {\n            static_assert(std::numeric_limits<T>::is_specialized,\n\
    \                          \"cannot use Sentinel\");\n            v = {std::numeric_limits<T>::min(),\
    \ std::numeric_limits<T>::max()};\n        }\n    }\n    Compress(const std::vector<T>\
    \ &w) : v(w), prepared(false) {\n        if constexpr (Sentinel) {\n         \
    \   static_assert(std::numeric_limits<T>::is_specialized,\n                  \
    \        \"cannot use Sentinel\");\n            v.push_back(std::numeric_limits<T>::min());\n\
    \            v.push_back(std::numeric_limits<T>::max());\n        }\n        build();\n\
    \    }\n\n    void add(T a) {\n        assert(!prepared);\n        v.push_back(a);\n\
    \    }\n    void build() {\n        assert(!prepared);\n        prepared = true;\n\
    \        std::ranges::sort(v);\n        auto result = std::ranges::unique(v);\n\
    \        v.erase(result.begin(), result.end());\n    }\n\n    bool is_prepared()\
    \ const { return prepared; }\n\n    int operator[](const T &a) const {\n     \
    \   assert(prepared);\n        auto it = std::ranges::lower_bound(v, a);\n   \
    \     assert(*it == a);\n        return std::distance(v.begin(), it);\n    }\n\
    \    int geq(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ std::ranges::lower_bound(v, a);\n        return std::distance(v.begin(), it);\n\
    \    }\n    int gt(const T &a) const {\n        assert(prepared);\n        auto\
    \ it = std::ranges::upper_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    int leq(const T &a) const {\n        assert(prepared);\n  \
    \      auto it = --std::ranges::upper_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    int lt(const T &a) const {\n        assert(prepared);\n   \
    \     auto it = --std::ranges::lower_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    T r(int id) const {\n        assert(prepared);\n        return\
    \ v[id];\n    }\n    bool exist(const T &a) const {\n        assert(prepared);\n\
    \        return (*std::ranges::lower_bound(v, a)) == a;\n    }\n    int size()\
    \ const { return v.size(); }\n    T max() const { return v.back(); }\n    T min()\
    \ const { return v[0]; }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Compress &C) {\n        for (int i = 0; i < C.v.size(); i++)\n       \
    \     os << C.v[i] << \":\" << i << \" \";\n        return os;\n    }\n};\n#line\
    \ 7 \"library/tree/AuxiliaryTree.hpp\"\n\ntemplate <typename TREE>\nstd::pair<WeightedTree<int>,\
    \ std::vector<int>>\nauxiliary_tree(const HLD<TREE> &hld, std::vector<int> vs)\
    \ {\n    assert(hld.prepared);\n    std::ranges::sort(vs, [&](int u, int v) {\
    \ return hld.id[u] < hld.id[v]; });\n\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::stack<int> sta;\n    sta.push(vs[0]);\n\n    for (int i = 0; i + 1 <\
    \ vs.size(); i++) {\n        int w = hld.lca(vs[i], vs[i + 1]);\n        if (w\
    \ != vs[i]) {\n            int l = sta.top();\n            sta.pop();\n      \
    \      while (sta.size() and hld.T.depth[w] < hld.T.depth[sta.top()]) {\n    \
    \            edges.emplace_back(sta.top(), l);\n                l = sta.top();\n\
    \                sta.pop();\n            }\n            if (sta.empty() or sta.top()\
    \ != w)\n                sta.push(w);\n            edges.emplace_back(w, l);\n\
    \        }\n        sta.push(vs[i + 1]);\n    }\n    while (sta.size() > 1) {\n\
    \        int c = sta.top();\n        sta.pop();\n        edges.emplace_back(c,\
    \ sta.top());\n    }\n\n    Compress<int> C;\n    for (const auto &[u, v] : edges)\n\
    \        C.add(u), C.add(v);\n\n    C.build();\n\n    WeightedTree<int> t(C.size());\n\
    \    for (const auto &[u, v] : edges)\n        t.add_edge(C[u], C[v], abs(hld.T.depth[u]\
    \ - hld.T.depth[v]));\n    t.build();\n\n    std::vector<int> pre_vertex(C.size());\n\
    \    for (int i = 0; i < C.size(); i++)\n        pre_vertex[i] = C.r(i);\n   \
    \ return std::make_pair(t, pre_vertex);\n}\n"
  code: "#pragma once\n\n#include \"library/tree/HLD.hpp\"\n#include \"library/tree/Tree.hpp\"\
    \n#include \"library/tree/WeightedTree.hpp\"\n#include \"library/util/Compress.hpp\"\
    \n\ntemplate <typename TREE>\nstd::pair<WeightedTree<int>, std::vector<int>>\n\
    auxiliary_tree(const HLD<TREE> &hld, std::vector<int> vs) {\n    assert(hld.prepared);\n\
    \    std::ranges::sort(vs, [&](int u, int v) { return hld.id[u] < hld.id[v]; });\n\
    \n    std::vector<std::pair<int, int>> edges;\n    std::stack<int> sta;\n    sta.push(vs[0]);\n\
    \n    for (int i = 0; i + 1 < vs.size(); i++) {\n        int w = hld.lca(vs[i],\
    \ vs[i + 1]);\n        if (w != vs[i]) {\n            int l = sta.top();\n   \
    \         sta.pop();\n            while (sta.size() and hld.T.depth[w] < hld.T.depth[sta.top()])\
    \ {\n                edges.emplace_back(sta.top(), l);\n                l = sta.top();\n\
    \                sta.pop();\n            }\n            if (sta.empty() or sta.top()\
    \ != w)\n                sta.push(w);\n            edges.emplace_back(w, l);\n\
    \        }\n        sta.push(vs[i + 1]);\n    }\n    while (sta.size() > 1) {\n\
    \        int c = sta.top();\n        sta.pop();\n        edges.emplace_back(c,\
    \ sta.top());\n    }\n\n    Compress<int> C;\n    for (const auto &[u, v] : edges)\n\
    \        C.add(u), C.add(v);\n\n    C.build();\n\n    WeightedTree<int> t(C.size());\n\
    \    for (const auto &[u, v] : edges)\n        t.add_edge(C[u], C[v], abs(hld.T.depth[u]\
    \ - hld.T.depth[v]));\n    t.build();\n\n    std::vector<int> pre_vertex(C.size());\n\
    \    for (int i = 0; i < C.size(); i++)\n        pre_vertex[i] = C.r(i);\n   \
    \ return std::make_pair(t, pre_vertex);\n}\n"
  dependsOn:
  - library/tree/HLD.hpp
  - library/tree/Tree.hpp
  - library/graph/Graph.hpp
  - library/tree/WeightedTree.hpp
  - library/graph/WeightedGraph.hpp
  - library/util/Compress.hpp
  isVerificationFile: false
  path: library/tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/library/tree/AuxiliaryTree.hpp
- /library/library/tree/AuxiliaryTree.hpp.html
title: library/tree/AuxiliaryTree.hpp
---
