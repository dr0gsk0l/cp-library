---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/Graph.cpp\"\nstruct Edge {\n    int from,\
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
    \       }\n    }\n};\n#line 3 \"library/tree/EdgeVertex.cpp\"\nclass EdgeVertex{\n\
    \  int n,m;\n  Tree T;\npublic:\n  EdgeVertex(int n):n(n),m(0),T(n*2-1){}\n\n\
    \  int add_edge(int u,int v){\n    assert(0<=u and u<n);\n    assert(0<=v and\
    \ v<n);\n    int w=n+(m++);\n    assert(w<T.n);\n    T.add_edge(u,w);\n    T.add_edge(w,v);\n\
    \    return w;\n  }\n\n  Tree build(int root=0){\n    assert(m==n-1);\n    T.build(root);\n\
    \    return T;\n  }\n};\n"
  code: "#pragma once\n#include \"library/tree/Tree.cpp\"\nclass EdgeVertex{\n  int\
    \ n,m;\n  Tree T;\npublic:\n  EdgeVertex(int n):n(n),m(0),T(n*2-1){}\n\n  int\
    \ add_edge(int u,int v){\n    assert(0<=u and u<n);\n    assert(0<=v and v<n);\n\
    \    int w=n+(m++);\n    assert(w<T.n);\n    T.add_edge(u,w);\n    T.add_edge(w,v);\n\
    \    return w;\n  }\n\n  Tree build(int root=0){\n    assert(m==n-1);\n    T.build(root);\n\
    \    return T;\n  }\n};"
  dependsOn:
  - library/tree/Tree.cpp
  - library/graph/Graph.cpp
  isVerificationFile: false
  path: library/tree/EdgeVertex.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/650.test.cpp
documentation_of: library/tree/EdgeVertex.cpp
layout: document
redirect_from:
- /library/library/tree/EdgeVertex.cpp
- /library/library/tree/EdgeVertex.cpp.html
title: library/tree/EdgeVertex.cpp
---