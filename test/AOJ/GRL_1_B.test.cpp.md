---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/WeightedGraph.hpp
    title: library/graph/WeightedGraph.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/BellmanFord.hpp
    title: library/graph/shortest_path/BellmanFord.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/AOJ/GRL_1_B.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/graph/WeightedGraph.hpp\"\ntemplate\
    \ <typename T> struct WeightedEdge {\n    WeightedEdge() = default;\n    WeightedEdge(int\
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
    \    }\n};\n#line 1 \"library/graph/shortest_path/BellmanFord.hpp\"\n// s \u304B\
    \u3089\u306E\u6700\u77ED\u8DDD\u96E2\u304C\u5B9A\u307E\u308B\u306A\u3089\u6700\
    \u77ED\u8DDD\u96E2, \u7121\u9650\u306B\u5C0F\u3055\u304F\u51FA\u6765\u308B\u306A\
    \u3089 std::nullopt\n// \u305D\u3082\u305D\u3082\u5230\u9054\u51FA\u6765\u306A\
    \u3044\u5834\u5408\u306F pre \u304C -1 \u306B\u306A\u3063\u3066\u3044\u308B\n\
    template <typename WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<std::optional<T>>,\
    \ std::vector<int>>\nbellman_ford(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n\
    \    int n = g.n;\n    static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n    std::vector<T> d(n, INF);\n    std::vector<int> pre(n, -1);\n    d[s]\
    \ = 0;\n    for (int _ = 0; _ < n; _++) {\n        bool update = false;\n    \
    \    for (int v = 0; v < n; v++)\n            if (d[v] < INF)\n              \
    \  for (const auto &e : g[v])\n                    if (d[e.to] > d[v] + e.weight)\
    \ {\n                        d[e.to] = d[v] + e.weight;\n                    \
    \    pre[e.to] = v;\n                        update = true;\n                \
    \    }\n        if (!update) {\n            std::vector<std::optional<T>> d_(n);\n\
    \            for (int i = 0; i < n; i++)\n                d_[i] = d[i];\n    \
    \        return {d_, pre};\n        }\n    }\n    auto now_d = d;\n    for (int\
    \ v = 0; v < n; v++)\n        if (d[v] < INF)\n            for (const auto &e\
    \ : g[v])\n                if (d[e.to] > d[v] + e.weight)\n                  \
    \  d[e.to] = d[v] + e.weight;\n    for (int _ = 1; _ < n; _++)\n        for (int\
    \ v = 0; v < n; v++)\n            if (d[v] < now_d[v])\n                for (const\
    \ auto &e : g[v])\n                    if (d[e.to] > d[v] + e.weight)\n      \
    \                  d[e.to] = d[v] + e.weight;\n    std::vector<std::optional<T>>\
    \ res(n);\n    for (int v = 0; v < n; v++)\n        if (now_d[v] == d[v])\n  \
    \          res[v] = d[v];\n        else\n            res[v] = std::nullopt;\n\
    \    return {res, pre};\n}\n#line 7 \"test/AOJ/GRL_1_B.test.cpp\"\n\nusing ll\
    \ = long long;\n\nint main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n\
    \    WeightedGraph<ll> g(n, m, true, 0);\n    auto [d, pre] = bellman_ford(g,\
    \ s);\n    for (const auto &p : d)\n        if (!p) {\n            std::cout <<\
    \ \"NEGATIVE CYCLE\\n\";\n            return 0;\n        }\n    for (int i = 0;\
    \ i < n; i++)\n        if (~pre[i] || i == s)\n            std::cout << d[i].value()\
    \ << \"\\n\";\n        else\n            std::cout << \"INF\\n\";\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/graph/WeightedGraph.hpp\"\n#include\
    \ \"library/graph/shortest_path/BellmanFord.hpp\"\n\nusing ll = long long;\n\n\
    int main() {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n    WeightedGraph<ll>\
    \ g(n, m, true, 0);\n    auto [d, pre] = bellman_ford(g, s);\n    for (const auto\
    \ &p : d)\n        if (!p) {\n            std::cout << \"NEGATIVE CYCLE\\n\";\n\
    \            return 0;\n        }\n    for (int i = 0; i < n; i++)\n        if\
    \ (~pre[i] || i == s)\n            std::cout << d[i].value() << \"\\n\";\n   \
    \     else\n            std::cout << \"INF\\n\";\n}"
  dependsOn:
  - library/graph/WeightedGraph.hpp
  - library/graph/shortest_path/BellmanFord.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_B.test.cpp
- /verify/test/AOJ/GRL_1_B.test.cpp.html
title: test/AOJ/GRL_1_B.test.cpp
---
