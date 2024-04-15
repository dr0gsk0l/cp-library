---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/ReRooting.cpp
    title: ReRooting
  - icon: ':heavy_check_mark:'
    path: library/tree/WeightedTree.cpp
    title: library/tree/WeightedTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/AOJ/GRL_5_A.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/tree/ReRooting.cpp\"\ntemplate\
    \ <typename TREE, typename Data> class ReRooting {\n    int n;\n    TREE T;\n\n\
    \  public:\n    ReRooting(const TREE &T) : T(T), n(T.n) {}\n\n    template <typename\
    \ F1, typename F2>\n    std::vector<Data> build(const F1 &score, const F2 &merge,\n\
    \                            const Data &unit) {\n        if (!~T.root)\n    \
    \        T.build(0);\n        std::vector<Data> dp1(n, unit), dp2(n);\n      \
    \  for (int v : T.DFS)\n            for (const auto &e : T.son(v)) {\n       \
    \         dp2[e.to] = score(dp1[e.to], e);\n                merge(dp1[v], dp2[e.to]);\n\
    \            }\n        std::vector<Data> top(n, unit), res(n);\n        for (int\
    \ v : T.BFS) {\n            Data now = (T.root == v ? unit : score(top[v], T.parent(v)));\n\
    \            for (int to : T.son(v)) {\n                top[to] = now;\n     \
    \           merge(now, dp2[to]);\n            }\n            res[v] = now;\n \
    \           now = unit;\n            for (int i = T.son(v).size() - 1; i >= 0;\
    \ i--) {\n                int to = T.son(v)[i];\n                merge(top[to],\
    \ now);\n                merge(now, dp2[to]);\n            }\n        }\n    \
    \    return res;\n    }\n};\n#line 2 \"library/graph/WeightedGraph.cpp\"\ntemplate\
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
    \    }\n};\n#line 3 \"library/tree/WeightedTree.cpp\"\ntemplate <typename T> struct\
    \ WeightedTree : WeightedGraph<T> {\n    using WeightedGraph<T>::WeightedGraph;\n\
    \    using edge_type = typename WeightedGraph<T>::edge_type;\n    using OutgoingEdges\
    \ = typename WeightedGraph<T>::OutgoingEdges;\n    using WeightedGraph<T>::n;\n\
    \    using WeightedGraph<T>::in_deg;\n\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       T weight;\n            std::cin >> weight;\n            add_edge(p - indexed,\
    \ i, weight);\n        }\n        build();\n    }\n    void scan(int indexed =\
    \ 1) {\n        WeightedGraph<T>::scan(n - 1, false, indexed);\n        build();\n\
    \    }\n\n    edge_type &parent(int v) {\n        assert(~root and root != v);\n\
    \        return (*this)[v][0];\n    }\n    OutgoingEdges son(int v) {\n      \
    \  assert(~root);\n        if (v == root)\n            return {this, in_deg[v],\
    \ in_deg[v + 1]};\n        return {this, in_deg[v] + 1, in_deg[v + 1]};\n    }\n\
    \n  private:\n    void dfs(int v, int pre = -1) {\n        for (auto &e : (*this)[v])\
    \ {\n            if (e.to == pre)\n                std::swap((*this)[v][0], e);\n\
    \            else {\n                depth[e.to] = depth[v] + 1;\n           \
    \     dfs(e.to, v);\n            }\n        }\n        DFS.push_back(v);\n   \
    \ }\n\n  public:\n    void build(int r = 0) {\n        if (!WeightedGraph<T>::is_prepared())\n\
    \            WeightedGraph<T>::build();\n        if (~root) {\n            assert(r\
    \ == root);\n            return;\n        }\n        root = r;\n        depth\
    \ = std::vector<int>(n, 0);\n        DFS.reserve(n);\n        BFS.reserve(n);\n\
    \        dfs(root);\n        std::queue<int> que;\n        que.push(root);\n \
    \       while (que.size()) {\n            int p = que.front();\n            que.pop();\n\
    \            BFS.push_back(p);\n            for (const auto &e : son(p))\n   \
    \             que.push(e.to);\n        }\n    }\n};\n#line 7 \"test/AOJ/GRL_5_A.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n    WeightedTree<int> t(n);\n    t.scan(0);\n\
    \n    ReRooting<WeightedTree<int>, int> RR(t);\n    auto score = [&](int now,\
    \ auto &e) { return now + e.weight; };\n    auto merge = [&](int &now, int add)\
    \ {\n        if (now < add)\n            now = add;\n    };\n    auto ans = RR.build(score,\
    \ merge, 0);\n\n    int fans = 0;\n    for (int p : ans)\n        fans = std::max(fans,\
    \ p);\n    std::cout << fans << std::endl;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/tree/ReRooting.cpp\"\n#include\
    \ \"library/tree/WeightedTree.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    WeightedTree<int>\
    \ t(n);\n    t.scan(0);\n\n    ReRooting<WeightedTree<int>, int> RR(t);\n    auto\
    \ score = [&](int now, auto &e) { return now + e.weight; };\n    auto merge =\
    \ [&](int &now, int add) {\n        if (now < add)\n            now = add;\n \
    \   };\n    auto ans = RR.build(score, merge, 0);\n\n    int fans = 0;\n    for\
    \ (int p : ans)\n        fans = std::max(fans, p);\n    std::cout << fans << std::endl;\n\
    }"
  dependsOn:
  - library/tree/ReRooting.cpp
  - library/tree/WeightedTree.cpp
  - library/graph/WeightedGraph.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 09:29:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_A.test.cpp
- /verify/test/AOJ/GRL_5_A.test.cpp.html
title: test/AOJ/GRL_5_A.test.cpp
---
