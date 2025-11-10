---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/Graph.hpp
    title: library/graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/LowLink.hpp\"\n#include <numeric>\n#include\
    \ <ranges>\n#include <utility>\n#include <vector>\n\n#line 2 \"library/graph/Graph.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#line 6 \"library/graph/Graph.hpp\"\
    \n\nstruct Edge {\n    int from, to;\n    Edge() = default;\n    Edge(int from,\
    \ int to) : from(from), to(to) {}\n    operator int() const { return to; }\n};\n\
    \nstruct Graph {\n    int n;\n    using edge_type = Edge;\n    std::vector<edge_type>\
    \ edges;\n\n  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n \
    \   class OutgoingEdges {\n        Graph *g;\n        int l, r;\n\n      public:\n\
    \        OutgoingEdges(Graph *g, int l, int r) : g(g), l(l), r(r) {}\n       \
    \ edge_type *begin() { return &(g->edges[l]); }\n        edge_type *end() { return\
    \ &(g->edges[r]); }\n        edge_type &operator[](int i) { return g->edges[l\
    \ + i]; }\n        int size() const { return r - l; }\n    };\n    class ConstOutgoingEdges\
    \ {\n        const Graph *g;\n        int l, r;\n\n      public:\n        ConstOutgoingEdges(const\
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
    \        }\n    }\n};\n#line 7 \"library/graph/LowLink.hpp\"\n\nclass LowLink\
    \ {\n    Graph g;\n    std::vector<int> ord, low_link;\n    int cnt;\n\n    static\
    \ inline void chmin(int &a, int b) { a = std::min(a, b); }\n\n    void dfs(int\
    \ p, int v) {\n        ord[v] = cnt++;\n        for (int to : g[v])\n        \
    \    if (~ord[to]) {\n                if (to != p)\n                    chmin(low_link[v],\
    \ to);\n            } else {\n                dfs(v, to);\n                chmin(low_link[v],\
    \ low_link[to]);\n            }\n    }\n\n  public:\n    LowLink(const Graph &g)\
    \ : g(g), ord(g.n, -1), low_link(g.n), cnt(0) {\n        std::iota(low_link.begin(),\
    \ low_link.end(), 0);\n        assert(g.is_prepared());\n        for (int v =\
    \ 0; v < g.n; v++)\n            if (ord[v] < 0)\n                dfs(-1, v);\n\
    \    }\n\n    int get_ord(int v) const { return ord[v]; }\n    int get_low_link(int\
    \ v) const { return low_link[v]; }\n    bool is_bridge(int u, int v) const {\n\
    \        if (ord[u] > ord[v])\n            std::swap(u, v);\n        return ord[u]\
    \ < low_link[v];\n    }\n};\n"
  code: "#include <numeric>\n#include <ranges>\n#include <utility>\n#include <vector>\n\
    \n#include \"library/graph/Graph.hpp\"\n\nclass LowLink {\n    Graph g;\n    std::vector<int>\
    \ ord, low_link;\n    int cnt;\n\n    static inline void chmin(int &a, int b)\
    \ { a = std::min(a, b); }\n\n    void dfs(int p, int v) {\n        ord[v] = cnt++;\n\
    \        for (int to : g[v])\n            if (~ord[to]) {\n                if\
    \ (to != p)\n                    chmin(low_link[v], to);\n            } else {\n\
    \                dfs(v, to);\n                chmin(low_link[v], low_link[to]);\n\
    \            }\n    }\n\n  public:\n    LowLink(const Graph &g) : g(g), ord(g.n,\
    \ -1), low_link(g.n), cnt(0) {\n        std::iota(low_link.begin(), low_link.end(),\
    \ 0);\n        assert(g.is_prepared());\n        for (int v = 0; v < g.n; v++)\n\
    \            if (ord[v] < 0)\n                dfs(-1, v);\n    }\n\n    int get_ord(int\
    \ v) const { return ord[v]; }\n    int get_low_link(int v) const { return low_link[v];\
    \ }\n    bool is_bridge(int u, int v) const {\n        if (ord[u] > ord[v])\n\
    \            std::swap(u, v);\n        return ord[u] < low_link[v];\n    }\n};"
  dependsOn:
  - library/graph/Graph.hpp
  isVerificationFile: false
  path: library/graph/LowLink.hpp
  requiredBy: []
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/LowLink.hpp
layout: document
redirect_from:
- /library/library/graph/LowLink.hpp
- /library/library/graph/LowLink.hpp.html
title: library/graph/LowLink.hpp
---
