---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/NegativeCycleFind.cpp
    title: library/graph/NegativeCycleFind.cpp
  - icon: ':x:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  - icon: ':x:'
    path: library/graph/shortest_path/WarshallFloyd.cpp
    title: library/graph/shortest_path/WarshallFloyd.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/AOJ/GRL_1_C.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/graph/NegativeCycleFind.cpp\"\n\
    // \u30B0\u30E9\u30D5\u5185\u306B\u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\
    \u304B\ntemplate<typename WG>\nbool negative_cycle_find(const WG&g){\n  using\
    \ W=typename WG::weight_type;\n  int n=g.n;\n  std::vector<W> d(n,0);\n  while(n--){\n\
    \    bool update=false;\n    for(const auto&e:g.edges)\n      if(d[e.to]>d[e.from]+e.weight){\n\
    \        d[e.to]=d[e.from]+e.weight;\n        update=true;\n      }\n    if(!update)return\
    \ false;\n  }\n  return true;\n}\n#line 2 \"library/graph/WeightedGraph.cpp\"\n\
    template <typename T> struct WeightedEdge {\n    WeightedEdge() = default;\n \
    \   WeightedEdge(int from, int to, T weight)\n        : from(from), to(to), weight(weight)\
    \ {}\n    int from, to;\n    T weight;\n    operator int() const { return to;\
    \ }\n};\n\ntemplate <typename T> struct WeightedGraph {\n    int n;\n    using\
    \ weight_type = T;\n    using edge_type = WeightedEdge<T>;\n    std::vector<edge_type>\
    \ edges;\n\n  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n \
    \   class OutgoingEdges {\n        WeightedGraph *g;\n        int l, r;\n\n  \
    \    public:\n        OutgoingEdges(WeightedGraph *g, int l, int r) : g(g), l(l),\
    \ r(r) {}\n        edge_type *begin() { return &(g->edges[l]); }\n        edge_type\
    \ *end() { return &(g->edges[r]); }\n        edge_type &operator[](int i) { return\
    \ g->edges[l + i]; }\n        int size() const { return r - l; }\n    };\n   \
    \ class ConstOutgoingEdges {\n        const WeightedGraph *g;\n        int l,\
    \ r;\n\n      public:\n        ConstOutgoingEdges(const WeightedGraph *g, int\
    \ l, int r)\n            : g(g), l(l), r(r) {}\n        const edge_type *begin()\
    \ const { return &(g->edges[l]); }\n        const edge_type *end() const { return\
    \ &(g->edges[r]); }\n        const edge_type &operator[](int i) const { return\
    \ g->edges[l + i]; }\n        int size() const { return r - l; }\n    };\n\n \
    \ public:\n    OutgoingEdges operator[](int v) {\n        assert(prepared);\n\
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
    \ (int from = 0; from < n; from++) {\n            cerr << from << \";\";\n   \
    \         for (int i = in_deg[from]; i < in_deg[from + 1]; i++)\n            \
    \    cerr << \"(\" << edges[i].to << \",\" << edges[i].weight << \")\";\n    \
    \        cerr << \"\\n\";\n        }\n    }\n};\n#line 1 \"library/graph/shortest_path/WarshallFloyd.cpp\"\
    \ntemplate <typename WG, typename T = typename WG::weight_type>\nvector<vector<T>>\
    \ warshall_floyd(const WG &g) {\n    int n = g.n;\n    static constexpr T INF\
    \ = numeric_limits<T>::max() / 2;\n    std::vector d(n, vector<T>(n, INF));\n\
    \    for (int i = 0; i < n; i++)\n        d[i][i] = 0;\n    for (const auto &e\
    \ : g.edges)\n        if (d[e.from][e.to] > e.weight)\n            d[e.from][e.to]\
    \ = e.weight;\n    for (int k = 0; k < n; k++)\n        for (int i = 0; i < n;\
    \ i++)\n            if (d[i][k] < INF)\n                for (int j = 0; j < n;\
    \ j++)\n                    if (d[k][j] < INF)\n                        if (d[i][j]\
    \ > d[i][k] + d[k][j])\n                            d[i][j] = d[i][k] + d[k][j];\n\
    \    return d;\n}\n#line 8 \"test/AOJ/GRL_1_C.test.cpp\"\n\nusing ll = long long;\n\
    \nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    WeightedGraph<ll>\
    \ g(n, m, true, 0);\n    if (negative_cycle_find(g))\n        std::cout << \"\
    NEGATIVE CYCLE\\n\";\n    else {\n        auto d = warshall_floyd(g);\n      \
    \  for (int i = 0; i < n; i++)\n            for (int j = 0; j < n; j++)\n    \
    \            if (d[i][j] < 1e10)\n                    std::cout << d[i][j] <<\
    \ \"\\n \"[j + 1 < n];\n                else\n                    std::cout <<\
    \ \"INF\"\n                              << \"\\n \"[j + 1 < n];\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/graph/NegativeCycleFind.cpp\"\
    \n#include \"library/graph/WeightedGraph.cpp\"\n#include \"library/graph/shortest_path/WarshallFloyd.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    WeightedGraph<ll> g(n, m, true, 0);\n    if (negative_cycle_find(g))\n\
    \        std::cout << \"NEGATIVE CYCLE\\n\";\n    else {\n        auto d = warshall_floyd(g);\n\
    \        for (int i = 0; i < n; i++)\n            for (int j = 0; j < n; j++)\n\
    \                if (d[i][j] < 1e10)\n                    std::cout << d[i][j]\
    \ << \"\\n \"[j + 1 < n];\n                else\n                    std::cout\
    \ << \"INF\"\n                              << \"\\n \"[j + 1 < n];\n    }\n}"
  dependsOn:
  - library/graph/NegativeCycleFind.cpp
  - library/graph/WeightedGraph.cpp
  - library/graph/shortest_path/WarshallFloyd.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 18:46:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_C.test.cpp
- /verify/test/AOJ/GRL_1_C.test.cpp.html
title: test/AOJ/GRL_1_C.test.cpp
---
