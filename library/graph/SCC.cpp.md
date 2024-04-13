---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/ReverseGraph.cpp
    title: library/graph/ReverseGraph.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/SCC.test.cpp
    title: test/library-checker/Graph/SCC.test.cpp
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
    \        }\n    }\n};\n#line 2 \"library/graph/ReverseGraph.cpp\"\ntemplate <typename\
    \ GRAPH> GRAPH reverse_graph(const GRAPH &g) {\n    GRAPH r(g.n);\n    for (auto\
    \ e : g.edges) {\n        std::swap(e.from, e.to);\n        r.add_arc(e);\n  \
    \  }\n    r.build();\n    return r;\n}\n#line 4 \"library/graph/SCC.cpp\"\n#define\
    \ ALL_(v) v.begin(), v.end()\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n\
    template <typename DirectedGraph> class SCC {\n    int n;\n    DirectedGraph G,\
    \ R;\n    std::vector<int> visit, belong;\n    std::vector<bool> used;\n    void\
    \ dfs(int v) {\n        used[v] = true;\n        for (int to : G[v])\n       \
    \     if (!used[to])\n                dfs(to);\n        visit.push_back(v);\n\
    \    }\n    void rdfs(int v, int k) {\n        used[v] = true;\n        belong[v]\
    \ = k;\n        for (int to : R[v])\n            if (!used[to])\n            \
    \    rdfs(to, k);\n    }\n\n  public:\n    Graph DAG;\n    std::vector<std::vector<int>>\
    \ component;\n    SCC(const DirectedGraph &G) : n(G.n), G(G), belong(n), used(n,\
    \ false) {\n        assert(G.is_prepared());\n        visit.reserve(n);\n    \
    \    R = reverse_graph(G);\n        REP_(v, n) if (!used[v]) dfs(v);\n       \
    \ fill(ALL_(used), false);\n        std::reverse(ALL_(visit));\n        int k\
    \ = 0;\n        for (const int &v : visit)\n            if (!used[v])\n      \
    \          rdfs(v, k++);\n        std::vector<std::vector<int>> edges(k);\n  \
    \      component.resize(k);\n        REP_(v, n) {\n            component[belong[v]].push_back(v);\n\
    \            for (int to : G[v])\n                if (belong[v] != belong[to])\n\
    \                    edges[belong[v]].push_back(belong[to]);\n        }\n    \
    \    DAG = Graph(k);\n        REP_(from, k) {\n            std::sort(ALL_(edges[from]));\n\
    \            REP_(i, edges[from].size())\n            if (!i || edges[from][i]\
    \ != edges[from][i - 1])\n                DAG.add_arc(from, edges[from][i]);\n\
    \        }\n    }\n    int operator[](int k) { return belong[k]; }\n};\n#undef\
    \ ALL_\n#undef REP_\n"
  code: "#pragma once\n#include \"library/graph/Graph.cpp\"\n#include \"library/graph/ReverseGraph.cpp\"\
    \n#define ALL_(v) v.begin(), v.end()\n#define REP_(i, n) for (int i = 0; i < (n);\
    \ i++)\ntemplate <typename DirectedGraph> class SCC {\n    int n;\n    DirectedGraph\
    \ G, R;\n    std::vector<int> visit, belong;\n    std::vector<bool> used;\n  \
    \  void dfs(int v) {\n        used[v] = true;\n        for (int to : G[v])\n \
    \           if (!used[to])\n                dfs(to);\n        visit.push_back(v);\n\
    \    }\n    void rdfs(int v, int k) {\n        used[v] = true;\n        belong[v]\
    \ = k;\n        for (int to : R[v])\n            if (!used[to])\n            \
    \    rdfs(to, k);\n    }\n\n  public:\n    Graph DAG;\n    std::vector<std::vector<int>>\
    \ component;\n    SCC(const DirectedGraph &G) : n(G.n), G(G), belong(n), used(n,\
    \ false) {\n        assert(G.is_prepared());\n        visit.reserve(n);\n    \
    \    R = reverse_graph(G);\n        REP_(v, n) if (!used[v]) dfs(v);\n       \
    \ fill(ALL_(used), false);\n        std::reverse(ALL_(visit));\n        int k\
    \ = 0;\n        for (const int &v : visit)\n            if (!used[v])\n      \
    \          rdfs(v, k++);\n        std::vector<std::vector<int>> edges(k);\n  \
    \      component.resize(k);\n        REP_(v, n) {\n            component[belong[v]].push_back(v);\n\
    \            for (int to : G[v])\n                if (belong[v] != belong[to])\n\
    \                    edges[belong[v]].push_back(belong[to]);\n        }\n    \
    \    DAG = Graph(k);\n        REP_(from, k) {\n            std::sort(ALL_(edges[from]));\n\
    \            REP_(i, edges[from].size())\n            if (!i || edges[from][i]\
    \ != edges[from][i - 1])\n                DAG.add_arc(from, edges[from][i]);\n\
    \        }\n    }\n    int operator[](int k) { return belong[k]; }\n};\n#undef\
    \ ALL_\n#undef REP_"
  dependsOn:
  - library/graph/Graph.cpp
  - library/graph/ReverseGraph.cpp
  isVerificationFile: false
  path: library/graph/SCC.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:59:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/SCC.test.cpp
documentation_of: library/graph/SCC.cpp
layout: document
redirect_from:
- /library/library/graph/SCC.cpp
- /library/library/graph/SCC.cpp.html
title: library/graph/SCC.cpp
---
