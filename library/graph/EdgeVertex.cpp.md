---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \        }\n    }\n};\n#line 3 \"library/graph/EdgeVertex.cpp\"\nclass EdgeVertex\
    \ {\n    int n, N;\n    std::vector<std::tuple<int, int, int>> edges;\n    std::vector<std::tuple<int,\
    \ int, int>> arcs;\n\n  public:\n    EdgeVertex(int n) : n(n), N(n) {}\n\n   \
    \ int add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        edges.emplace_back(u, v, N);\n        return N++;\n\
    \    }\n    int add_arc(int u, int v) {\n        assert(0 <= u and u < n);\n \
    \       assert(0 <= v and v < n);\n        arcs.emplace_back(u, v, N);\n     \
    \   return N++;\n    }\n\n    Graph build() {\n        Graph G(N);\n        for\
    \ (const auto &[u, v, e] : edges) {\n            G.add_edge(u, e);\n         \
    \   G.add_edge(e, v);\n        }\n        for (const auto &[u, v, e] : arcs) {\n\
    \            G.add_arc(u, e);\n            G.add_arc(e, v);\n        }\n     \
    \   G.build();\n        return G;\n    }\n};\n"
  code: "#pragma once\n#include \"library/graph/Graph.cpp\"\nclass EdgeVertex {\n\
    \    int n, N;\n    std::vector<std::tuple<int, int, int>> edges;\n    std::vector<std::tuple<int,\
    \ int, int>> arcs;\n\n  public:\n    EdgeVertex(int n) : n(n), N(n) {}\n\n   \
    \ int add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        edges.emplace_back(u, v, N);\n        return N++;\n\
    \    }\n    int add_arc(int u, int v) {\n        assert(0 <= u and u < n);\n \
    \       assert(0 <= v and v < n);\n        arcs.emplace_back(u, v, N);\n     \
    \   return N++;\n    }\n\n    Graph build() {\n        Graph G(N);\n        for\
    \ (const auto &[u, v, e] : edges) {\n            G.add_edge(u, e);\n         \
    \   G.add_edge(e, v);\n        }\n        for (const auto &[u, v, e] : arcs) {\n\
    \            G.add_arc(u, e);\n            G.add_arc(e, v);\n        }\n     \
    \   G.build();\n        return G;\n    }\n};"
  dependsOn:
  - library/graph/Graph.cpp
  isVerificationFile: false
  path: library/graph/EdgeVertex.cpp
  requiredBy: []
  timestamp: '2024-04-15 12:10:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/EdgeVertex.cpp
layout: document
redirect_from:
- /library/library/graph/EdgeVertex.cpp
- /library/library/graph/EdgeVertex.cpp.html
title: library/graph/EdgeVertex.cpp
---
