---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.hpp
    title: library/datastructure/unionfind/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/MinimumSpanningTree.hpp
    title: library/graph/MinimumSpanningTree.hpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.hpp
    title: library/graph/WeightedGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/AOJ/GRL_2_A.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <bits/stdc++.h>\n\n#line 3 \"library/datastructure/unionfind/UnionFind.hpp\"\
    \n\nclass UnionFind {\n    int n, num;\n    std::vector<int> sz, parent;\n\n \
    \ public:\n    UnionFind() = default;\n    UnionFind(int n) : n(n), num(n), sz(n,\
    \ 1), parent(n, 0) {\n        std::iota(parent.begin(), parent.end(), 0);\n  \
    \  }\n\n    int leader(int x) {\n        assert(0 <= x and x < n);\n        return\
    \ (x == parent[x] ? x : parent[x] = leader(parent[x]));\n    }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    bool merge(int x, int y) {\n \
    \       assert(0 <= x and x < n and 0 <= y and y < n);\n        x = leader(x);\n\
    \        y = leader(y);\n        if (x == y)\n            return false;\n    \
    \    if (sz[x] < sz[y])\n            std::swap(x, y);\n        sz[x] += sz[y];\n\
    \        parent[y] = x;\n        num--;\n        return true;\n    }\n\n    int\
    \ size(const int x) {\n        assert(0 <= x and x < n);\n        return sz[leader(x)];\n\
    \    }\n\n    int count() const { return num; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<std::vector<int>> res(n);\n        for (int\
    \ i = 0; i < n; i++)\n            res[leader(i)].push_back(i);\n        std::erase_if(res,\
    \ [](const auto &vec) { return vec.empty(); });\n        return res;\n    }\n\
    };\n#line 2 \"library/graph/MinimumSpanningTree.hpp\"\ntemplate <typename WG,\
    \ typename W = typename WG::weight_type>\nstd::pair<W, std::vector<int>> minimum_spanning_tree(const\
    \ WG &g) {\n    assert(g.is_prepared());\n    int n = g.n, m = g.edges.size();\n\
    \    UnionFind uf(n);\n    std::vector<int> id(m);\n    std::iota(id.begin(),\
    \ id.end(), 0);\n    std::ranges::sort(id, [&](const int i, const int j) {\n \
    \       return g.edges[i].weight < g.edges[j].weight;\n    });\n    W res = 0;\n\
    \    std::vector<int> tree;\n    tree.reserve(n - 1);\n    for (int i : id) {\n\
    \        const auto &[from, to, weight] = g.edges[i];\n        if (uf.same(from,\
    \ to))\n            continue;\n        tree.push_back(i);\n        uf.merge(from,\
    \ to);\n        res += weight;\n    }\n    assert(uf.count() == 1);\n    return\
    \ {res, tree};\n}\n#line 2 \"library/graph/WeightedGraph.hpp\"\ntemplate <typename\
    \ T> struct WeightedEdge {\n    WeightedEdge() = default;\n    WeightedEdge(int\
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
    \    }\n};\n#line 7 \"test/AOJ/GRL_2_A.test.cpp\"\n\nint main() {\n    int n,\
    \ m;\n    std::cin >> n >> m;\n    WeightedGraph<int> g(n, m, false, 0);\n   \
    \ auto [sum, tree] = minimum_spanning_tree(g);\n    std::cout << sum << std::endl;\n\
    }\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/graph/MinimumSpanningTree.hpp\"\
    \n#include \"library/graph/WeightedGraph.hpp\"\n\nint main() {\n    int n, m;\n\
    \    std::cin >> n >> m;\n    WeightedGraph<int> g(n, m, false, 0);\n    auto\
    \ [sum, tree] = minimum_spanning_tree(g);\n    std::cout << sum << std::endl;\n\
    }"
  dependsOn:
  - library/graph/MinimumSpanningTree.hpp
  - library/datastructure/unionfind/UnionFind.hpp
  - library/graph/WeightedGraph.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_2_A.test.cpp
- /verify/test/AOJ/GRL_2_A.test.cpp.html
title: test/AOJ/GRL_2_A.test.cpp
---
