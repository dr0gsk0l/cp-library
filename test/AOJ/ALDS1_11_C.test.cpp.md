---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/shortest_path/BFS.cpp
    title: library/graph/shortest_path/BFS.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_11_C.test.cpp\"\n#define PROBLEM        \
    \                                                        \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#line 2 \"library/graph/Graph.cpp\"\nstruct Edge {\n    int from, to;\n    Edge()\
    \ = default;\n    Edge(int from, int to) : from(from), to(to) {}\n    operator\
    \ int() const { return to; }\n};\n\nstruct Graph {\n    int n;\n    using edge_type\
    \ = Edge;\n    std::vector<edge_type> edges;\n\n  protected:\n    std::vector<int>\
    \ in_deg;\n    bool prepared;\n    class OutgoingEdges {\n        Graph *g;\n\
    \        int l, r;\n\n      public:\n        OutgoingEdges(Graph *g, int l, int\
    \ r) : g(g), l(l), r(r) {}\n        edge_type *begin() { return &(g->edges[l]);\
    \ }\n        edge_type *end() { return &(g->edges[r]); }\n        edge_type &operator[](int\
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
    \ << \" \";\n            std::cerr << \"\\n\";\n        }\n    }\n};\n#line 2\
    \ \"library/graph/shortest_path/BFS.cpp\"\ntemplate <typename GRAPH>\nstd::pair<std::vector<int>,\
    \ std::vector<int>> BFS(const GRAPH &g, int s = 0) {\n    assert(g.is_prepared());\n\
    \    std::vector<int> d(g.n, -1), pre(g.n, -1);\n    std::queue<int> que;\n  \
    \  d[s] = 0;\n    que.push(s);\n    while (que.size()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (int to : g[v])\n            if (d[to] < 0) {\n\
    \                d[to] = d[v] + 1;\n                que.push(to);\n          \
    \  }\n    }\n    return {d, pre};\n}\n#line 9 \"test/AOJ/ALDS1_11_C.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n    Graph g(n);\n    REP (_, n) {\n        int\
    \ u, k;\n        std::cin >> u >> k;\n        u--;\n        REP (_, k) {\n   \
    \         int v;\n            std::cin >> v;\n            v--;\n            g.add_arc(u,\
    \ v);\n        }\n    }\n    g.build();\n    auto [d, pre] = BFS(g);\n    REP\
    \ (i, n)\n        std::cout << i + 1 << \" \" << d[i] << \"\\n\";\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include \"library/graph/Graph.cpp\"\n#include \"library/graph/shortest_path/BFS.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n    Graph g(n);\n    REP (_, n) {\n        int\
    \ u, k;\n        std::cin >> u >> k;\n        u--;\n        REP (_, k) {\n   \
    \         int v;\n            std::cin >> v;\n            v--;\n            g.add_arc(u,\
    \ v);\n        }\n    }\n    g.build();\n    auto [d, pre] = BFS(g);\n    REP\
    \ (i, n)\n        std::cout << i + 1 << \" \" << d[i] << \"\\n\";\n}\n"
  dependsOn:
  - library/graph/Graph.cpp
  - library/graph/shortest_path/BFS.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 09:29:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_11_C.test.cpp
- /verify/test/AOJ/ALDS1_11_C.test.cpp.html
title: test/AOJ/ALDS1_11_C.test.cpp
---
