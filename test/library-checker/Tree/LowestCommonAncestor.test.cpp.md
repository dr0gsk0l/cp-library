---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/HLD.cpp
    title: library/tree/HLD.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/library-checker/Tree/LowestCommonAncestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    \n#line 2 \"library/tree/HLD.cpp\"\ntemplate <typename TREE> struct HLD {\n  \
    \  int n;\n    TREE T;\n    std::vector<int> sz, head, id, id2;\n    bool prepared;\n\
    \    HLD(TREE T_)\n        : T(T_), n(T_.n), sz(n), head(n), id(n), id2(n), prepared(false)\
    \ {}\n    HLD() = default;\n\n  private:\n    void dfs_sz(int v) {\n        sz[v]\
    \ = 1;\n        for (auto &e : T.son(v)) {\n            dfs_sz(e.to);\n      \
    \      sz[v] += sz[e.to];\n            if (sz[e.to] > sz[T.son(v)[0].to])\n  \
    \              std::swap(e, T.son(v)[0]);\n        }\n    }\n    void dfs_hld(int\
    \ v, int &k) {\n        id[v] = k++;\n        for (int i = 0; i < T.son(v).size();\
    \ i++) {\n            int to = T.son(v)[i];\n            head[to] = (i ? to :\
    \ head[v]);\n            dfs_hld(to, k);\n        }\n        id2[v] = k;\n   \
    \ }\n\n  public:\n    std::vector<int> build(int r = 0) {\n        assert(!prepared);\n\
    \        prepared = true;\n        if (~T.root)\n            assert(T.root ==\
    \ r);\n        else\n            T.build(r);\n        head[r] = r;\n        dfs_sz(r);\n\
    \        int k = 0;\n        dfs_hld(r, k);\n        return id;\n    }\n\n   \
    \ int lca(int u, int v) {\n        assert(prepared);\n        while (head[u] !=\
    \ head[v])\n            if (T.depth[head[u]] > T.depth[head[v]])\n           \
    \     u = T.parent(head[u]);\n            else\n                v = T.parent(head[v]);\n\
    \        return (T.depth[u] < T.depth[v] ? u : v);\n    }\n    int distance(int\
    \ u, int v) {\n        int w = lca(u, v);\n        return T.depth[u] + T.depth[v]\
    \ - T.depth[w] * 2;\n    }\n\n    // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001\
    [u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\
    \u307F\u3067\u8FD4\u3059\n    using path_t = std::vector<std::pair<int, int>>;\n\
    \    std::pair<path_t, path_t> path(int u, int v) {\n        assert(prepared);\n\
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
    \ int> subtree(int v) {\n        assert(prepared);\n        return {id[v], id2[v]};\n\
    \    }\n};\n#line 2 \"library/graph/Graph.cpp\"\nstruct Edge {\n    int from,\
    \ to;\n    Edge() = default;\n    Edge(int from, int to) : from(from), to(to)\
    \ {}\n    operator int() const { return to; }\n};\n\nstruct Graph {\n    int n;\n\
    \    using edge_type = Edge;\n    std::vector<edge_type> edges;\n\n  protected:\n\
    \    std::vector<int> in_deg;\n    bool prepared;\n    class OutgoingEdges {\n\
    \        Graph *g;\n        int l, r;\n\n      public:\n        OutgoingEdges(Graph\
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
    \        }\n    }\n};\n#line 3 \"library/tree/Tree.cpp\"\nstruct Tree : Graph\
    \ {\n    using Graph::Graph;\n    Tree() = default;\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       add_edge(p - indexed, i);\n        }\n        build();\n    }\n    void\
    \ scan(int indexed = 1) {\n        Graph::scan(n - 1, false, indexed);\n     \
    \   build();\n    }\n\n    edge_type &parent(int v) {\n        assert(~root and\
    \ root != v);\n        return (*this)[v][0];\n    }\n    OutgoingEdges son(int\
    \ v) {\n        assert(~root);\n        if (v == root)\n            return {this,\
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
    \       }\n    }\n};\n#line 6 \"test/library-checker/Tree/LowestCommonAncestor.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    Tree t(n);\n   \
    \ t.scan_root(0);\n    HLD hld(t);\n    hld.build();\n    while (q--) {\n    \
    \    int u, v;\n        std::cin >> u >> v;\n        std::cout << hld.lca(u, v)\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <bits/stdc++.h>\n\
    \n#include \"library/tree/HLD.cpp\"\n#include \"library/tree/Tree.cpp\"\n\nint\
    \ main() {\n    int n, q;\n    std::cin >> n >> q;\n    Tree t(n);\n    t.scan_root(0);\n\
    \    HLD hld(t);\n    hld.build();\n    while (q--) {\n        int u, v;\n   \
    \     std::cin >> u >> v;\n        std::cout << hld.lca(u, v) << \"\\n\";\n  \
    \  }\n}"
  dependsOn:
  - library/tree/HLD.cpp
  - library/tree/Tree.cpp
  - library/graph/Graph.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 09:29:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Tree/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/LowestCommonAncestor.test.cpp
- /verify/test/library-checker/Tree/LowestCommonAncestor.test.cpp.html
title: test/library-checker/Tree/LowestCommonAncestor.test.cpp
---
