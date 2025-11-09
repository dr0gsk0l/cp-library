---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/WeightedGraph.hpp
    title: library/graph/WeightedGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \    }\n};\n#line 3 \"library/graph/Grid.hpp\"\n#define REP_(i, n) for (int i\
    \ = 0; i < (n); i++)\ntemplate <typename T> class Grid {\n    const int h, w;\n\
    \    std::optional<T> ban;\n    // D,R,U,L\n    static constexpr std::pair<int,\
    \ int> d4[4] = {\n        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};\n    template <typename\
    \ vecvecT> void build(const vecvecT &grid) {\n        REP_(y, h) REP_(x, w) {\n\
    \            int p = id(y, x);\n            v[p] = grid[y][x];\n            if\
    \ (ban and v[p] == ban.value())\n                continue;\n            REP_(d,\
    \ 4) {\n                int y2 = y + d4[d].first, x2 = x + d4[d].second;\n   \
    \             if (in(y2, x2) and (!ban or ban.value() != grid[y2][x2]))\n    \
    \                G.add_arc(p, id(y2, x2), d);\n            }\n        }\n    \
    \    G.build();\n    }\n\n  public:\n    std::vector<T> v;\n    WeightedGraph<int>\
    \ G;\n    bool in(int y, int x) const {\n        return 0 <= y and y < h and 0\
    \ <= x and x < w;\n    }\n    int id(int y, int x) const {\n        assert(in(y,\
    \ x));\n        return y * w + x;\n    }\n    std::pair<int, int> r2(int a) const\
    \ {\n        assert(0 <= a and a < h * w);\n        return {a / w, a % w};\n \
    \   }\n\n    Grid(const std::vector<std::vector<T>> &grid,\n         const std::optional<T>\
    \ &ban = std::nullopt)\n        : h(grid.size()), w(grid[0].size()), ban(ban),\
    \ v(h * w), G(h * w) {\n        build(grid);\n    }\n    Grid(const std::vector<std::string>\
    \ &s,\n         const std::optional<T> &ban = std::nullopt)\n        : h(s.size()),\
    \ w(s[0].size()), ban(ban), v(h * w), G(h * w) {\n        static_assert(std::is_same<T,\
    \ char>::value, \"value_type==char\");\n        build(s);\n    }\n\n    int find(const\
    \ T &c) const {\n        REP_(i, h * w) if (v[i] == c) return i;\n        return\
    \ -1;\n    }\n};\n#undef REP_\n"
  code: "#pragma once\n#include \"library/graph/WeightedGraph.hpp\"\n#define REP_(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <typename T> class Grid {\n    const\
    \ int h, w;\n    std::optional<T> ban;\n    // D,R,U,L\n    static constexpr std::pair<int,\
    \ int> d4[4] = {\n        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};\n    template <typename\
    \ vecvecT> void build(const vecvecT &grid) {\n        REP_(y, h) REP_(x, w) {\n\
    \            int p = id(y, x);\n            v[p] = grid[y][x];\n            if\
    \ (ban and v[p] == ban.value())\n                continue;\n            REP_(d,\
    \ 4) {\n                int y2 = y + d4[d].first, x2 = x + d4[d].second;\n   \
    \             if (in(y2, x2) and (!ban or ban.value() != grid[y2][x2]))\n    \
    \                G.add_arc(p, id(y2, x2), d);\n            }\n        }\n    \
    \    G.build();\n    }\n\n  public:\n    std::vector<T> v;\n    WeightedGraph<int>\
    \ G;\n    bool in(int y, int x) const {\n        return 0 <= y and y < h and 0\
    \ <= x and x < w;\n    }\n    int id(int y, int x) const {\n        assert(in(y,\
    \ x));\n        return y * w + x;\n    }\n    std::pair<int, int> r2(int a) const\
    \ {\n        assert(0 <= a and a < h * w);\n        return {a / w, a % w};\n \
    \   }\n\n    Grid(const std::vector<std::vector<T>> &grid,\n         const std::optional<T>\
    \ &ban = std::nullopt)\n        : h(grid.size()), w(grid[0].size()), ban(ban),\
    \ v(h * w), G(h * w) {\n        build(grid);\n    }\n    Grid(const std::vector<std::string>\
    \ &s,\n         const std::optional<T> &ban = std::nullopt)\n        : h(s.size()),\
    \ w(s[0].size()), ban(ban), v(h * w), G(h * w) {\n        static_assert(std::is_same<T,\
    \ char>::value, \"value_type==char\");\n        build(s);\n    }\n\n    int find(const\
    \ T &c) const {\n        REP_(i, h * w) if (v[i] == c) return i;\n        return\
    \ -1;\n    }\n};\n#undef REP_"
  dependsOn:
  - library/graph/WeightedGraph.hpp
  isVerificationFile: false
  path: library/graph/Grid.hpp
  requiredBy: []
  timestamp: '2025-11-09 20:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2212.test.cpp
documentation_of: library/graph/Grid.hpp
layout: document
redirect_from:
- /library/library/graph/Grid.hpp
- /library/library/graph/Grid.hpp.html
title: library/graph/Grid.hpp
---
