---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/flow/Dinic.hpp
    title: library/flow/Dinic.hpp
  - icon: ':heavy_check_mark:'
    path: library/flow/MCF.hpp
    title: library/flow/MCF.hpp
  - icon: ':heavy_check_mark:'
    path: library/flow/NondecreasingMCF.hpp
    title: library/flow/NondecreasingMCF.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/Grid.hpp
    title: library/graph/Grid.hpp
  - icon: ':warning:'
    path: library/graph/Grid8.hpp
    title: library/graph/Grid8.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/matching/BipartiteMatching.hpp
    title: library/graph/matching/BipartiteMatching.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/matching/WeightedBipartiteMatching.hpp
    title: library/graph/matching/WeightedBipartiteMatching.hpp
  - icon: ':warning:'
    path: library/graph/shortest_path/01BFS.hpp
    title: library/graph/shortest_path/01BFS.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/Dial.hpp
    title: library/graph/shortest_path/Dial.hpp
  - icon: ':warning:'
    path: library/tree/AuxiliaryTree.hpp
    title: library/tree/AuxiliaryTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/CartesianTree.hpp
    title: library/tree/CartesianTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/WeightedTree.hpp
    title: library/tree/WeightedTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2647.test.cpp
    title: test/AOJ/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/3297.test.cpp
    title: test/AOJ/3297.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_12_B.test.cpp
    title: test/AOJ/ALDS1_12_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_3_B.test.cpp
    title: test/AOJ/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_3_C.test.cpp
    title: test/AOJ/DPL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_B.test.cpp
    title: test/AOJ/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_A.test.cpp
    title: test/AOJ/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_B.test.cpp
    title: test/AOJ/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_7_A.test.cpp
    title: test/AOJ/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/AssignmentProblem.test.cpp
    title: test/library-checker/Graph/AssignmentProblem.test.cpp
  - icon: ':x:'
    path: test/library-checker/Graph/DirectedMST.test.cpp
    title: test/library-checker/Graph/DirectedMST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
    title: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/ShortestPath.test.cpp
    title: test/library-checker/Graph/ShortestPath.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/CartesianTree.test.cpp
    title: test/library-checker/Tree/CartesianTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1002.test.cpp
    title: test/yukicoder/1002.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/WeightedGraph.hpp\"\ntemplate <typename T>\
    \ struct WeightedEdge {\n    WeightedEdge() = default;\n    WeightedEdge(int from,\
    \ int to, T weight)\n        : from(from), to(to), weight(weight) {}\n    int\
    \ from, to;\n    T weight;\n    operator int() const { return to; }\n};\n\ntemplate\
    \ <typename T> struct WeightedGraph {\n    int n;\n    using weight_type = T;\n\
    \    using edge_type = WeightedEdge<T>;\n    std::vector<edge_type> edges;\n\n\
    \  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n    class OutgoingEdges\
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
    \    }\n};\n"
  code: "#pragma once\ntemplate <typename T> struct WeightedEdge {\n    WeightedEdge()\
    \ = default;\n    WeightedEdge(int from, int to, T weight)\n        : from(from),\
    \ to(to), weight(weight) {}\n    int from, to;\n    T weight;\n    operator int()\
    \ const { return to; }\n};\n\ntemplate <typename T> struct WeightedGraph {\n \
    \   int n;\n    using weight_type = T;\n    using edge_type = WeightedEdge<T>;\n\
    \    std::vector<edge_type> edges;\n\n  protected:\n    std::vector<int> in_deg;\n\
    \    bool prepared;\n    class OutgoingEdges {\n        WeightedGraph *g;\n  \
    \      int l, r;\n\n      public:\n        OutgoingEdges(WeightedGraph *g, int\
    \ l, int r) : g(g), l(l), r(r) {}\n        edge_type *begin() { return &(g->edges[l]);\
    \ }\n        edge_type *end() { return &(g->edges[r]); }\n        edge_type &operator[](int\
    \ i) { return g->edges[l + i]; }\n        int size() const { return r - l; }\n\
    \    };\n    class ConstOutgoingEdges {\n        const WeightedGraph *g;\n   \
    \     int l, r;\n\n      public:\n        ConstOutgoingEdges(const WeightedGraph\
    \ *g, int l, int r)\n            : g(g), l(l), r(r) {}\n        const edge_type\
    \ *begin() const { return &(g->edges[l]); }\n        const edge_type *end() const\
    \ { return &(g->edges[r]); }\n        const edge_type &operator[](int i) const\
    \ { return g->edges[l + i]; }\n        int size() const { return r - l; }\n  \
    \  };\n\n  public:\n    OutgoingEdges operator[](int v) {\n        assert(prepared);\n\
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
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/WeightedGraph.hpp
  requiredBy:
  - library/flow/NondecreasingMCF.hpp
  - library/flow/Dinic.hpp
  - library/flow/MCF.hpp
  - library/graph/Grid8.hpp
  - library/graph/matching/BipartiteMatching.hpp
  - library/graph/matching/WeightedBipartiteMatching.hpp
  - library/graph/shortest_path/Dial.hpp
  - library/graph/shortest_path/01BFS.hpp
  - library/graph/Grid.hpp
  - library/tree/WeightedTree.hpp
  - library/tree/CartesianTree.hpp
  - library/tree/AuxiliaryTree.hpp
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/Tree/CartesianTree.test.cpp
  - test/library-checker/Graph/DirectedMST.test.cpp
  - test/library-checker/Graph/AssignmentProblem.test.cpp
  - test/library-checker/Graph/ShortestPath.test.cpp
  - test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  - test/AOJ/3297.test.cpp
  - test/AOJ/GRL_2_A.test.cpp
  - test/AOJ/GRL_7_A.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/GRL_2_B.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
  - test/AOJ/GRL_6_B.test.cpp
  - test/AOJ/GRL_6_A.test.cpp
  - test/AOJ/DPL_3_B.test.cpp
  - test/AOJ/ALDS1_12_B.test.cpp
  - test/AOJ/2647.test.cpp
  - test/AOJ/DPL_3_C.test.cpp
  - test/AOJ/GRL_5_A.test.cpp
  - test/AOJ/2212.test.cpp
  - test/yukicoder/1002.test.cpp
documentation_of: library/graph/WeightedGraph.hpp
layout: document
redirect_from:
- /library/library/graph/WeightedGraph.hpp
- /library/library/graph/WeightedGraph.hpp.html
title: library/graph/WeightedGraph.hpp
---
