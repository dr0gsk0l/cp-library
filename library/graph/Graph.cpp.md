---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/graph/EdgeVertex.cpp
    title: library/graph/EdgeVertex.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/SCC.cpp
    title: library/graph/SCC.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/EdgeVertex.cpp
    title: library/tree/EdgeVertex.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C.test.cpp
    title: test/AOJ/ALDS1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/SCC.test.cpp
    title: test/library-checker/Graph/SCC.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
    title: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/LowestCommonAncestor.test.cpp
    title: test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
    title: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
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
    \        }\n    }\n};\n"
  code: "#pragma once\nstruct Edge {\n    int from, to;\n    Edge() = default;\n \
    \   Edge(int from, int to) : from(from), to(to) {}\n    operator int() const {\
    \ return to; }\n};\n\nstruct Graph {\n    int n;\n    using edge_type = Edge;\n\
    \    std::vector<edge_type> edges;\n\n  protected:\n    std::vector<int> in_deg;\n\
    \    bool prepared;\n    class OutgoingEdges {\n        Graph *g;\n        int\
    \ l, r;\n\n      public:\n        OutgoingEdges(Graph *g, int l, int r) : g(g),\
    \ l(l), r(r) {}\n        edge_type *begin() { return &(g->edges[l]); }\n     \
    \   edge_type *end() { return &(g->edges[r]); }\n        edge_type &operator[](int\
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
    \ << \" \";\n            std::cerr << \"\\n\";\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/Graph.cpp
  requiredBy:
  - library/tree/Tree.cpp
  - library/tree/EdgeVertex.cpp
  - library/graph/EdgeVertex.cpp
  - library/graph/SCC.cpp
  timestamp: '2024-04-14 21:36:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/SCC.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
  - test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
  - test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/yukicoder/1038.test.cpp
  - test/yukicoder/650.test.cpp
  - test/AOJ/ALDS1_11_C.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/graph/Graph.cpp
layout: document
redirect_from:
- /library/library/graph/Graph.cpp
- /library/library/graph/Graph.cpp.html
title: library/graph/Graph.cpp
---
