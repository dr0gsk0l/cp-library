---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/WeightedGraph.cpp\"\ntemplate <typename T>\
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
    \    }\n};\n#line 3 \"library/graph/shortest_path/01BFS.cpp\"\ntemplate <typename\
    \ WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<T>, std::vector<int>>\
    \ bfs01(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n    std::vector<T>\
    \ d(g.n, -1);\n    std::vector<int> pre(g.n, -1);\n    std::deque<std::pair<T,\
    \ int>> deq;\n    d[s] = 0;\n    deq.emplace_back(0, s);\n    while (deq.size())\
    \ {\n        auto [now, id] = deq.front();\n        deq.pop_front();\n       \
    \ if (d[id] < now)\n            continue;\n        for (const auto &e : g[id])\
    \ {\n            assert(e.weight == 0 || e.weight == 1);\n            if (d[e.to]\
    \ == -1 || d[e.to] > now + e.weight) {\n                d[e.to] = now + e.weight;\n\
    \                pre[e.to] = id;\n                if (e.weight == 0)\n       \
    \             deq.emplace_front(d[e.to], e.to);\n                else\n      \
    \              deq.emplace_back(d[e.to], e.to);\n            }\n        }\n  \
    \  }\n    return {d, pre};\n}\n"
  code: "#pragma once\n#include \"library/graph/WeightedGraph.cpp\"\ntemplate <typename\
    \ WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<T>, std::vector<int>>\
    \ bfs01(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n    std::vector<T>\
    \ d(g.n, -1);\n    std::vector<int> pre(g.n, -1);\n    std::deque<std::pair<T,\
    \ int>> deq;\n    d[s] = 0;\n    deq.emplace_back(0, s);\n    while (deq.size())\
    \ {\n        auto [now, id] = deq.front();\n        deq.pop_front();\n       \
    \ if (d[id] < now)\n            continue;\n        for (const auto &e : g[id])\
    \ {\n            assert(e.weight == 0 || e.weight == 1);\n            if (d[e.to]\
    \ == -1 || d[e.to] > now + e.weight) {\n                d[e.to] = now + e.weight;\n\
    \                pre[e.to] = id;\n                if (e.weight == 0)\n       \
    \             deq.emplace_front(d[e.to], e.to);\n                else\n      \
    \              deq.emplace_back(d[e.to], e.to);\n            }\n        }\n  \
    \  }\n    return {d, pre};\n}"
  dependsOn:
  - library/graph/WeightedGraph.cpp
  isVerificationFile: false
  path: library/graph/shortest_path/01BFS.cpp
  requiredBy: []
  timestamp: '2024-04-14 23:11:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/shortest_path/01BFS.cpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/01BFS.cpp
- /library/library/graph/shortest_path/01BFS.cpp.html
title: library/graph/shortest_path/01BFS.cpp
---
