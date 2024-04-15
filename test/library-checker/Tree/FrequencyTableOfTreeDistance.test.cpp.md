---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/CentroidDecomposition.cpp
    title: library/tree/CentroidDecomposition.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n#include <bits/stdc++.h>\n\n#include <atcoder/convolution>\nusing namespace\
    \ atcoder;\n\n#line 1 \"library/tree/CentroidDecomposition.cpp\"\ntemplate <typename\
    \ TREE> class CentroidDecomposition {\n    TREE T;\n    std::vector<int> sz, pre,\
    \ timing;\n\n    int find_centroid(int v) {\n        std::vector<int> S{v};\n\
    \        pre[v] = -1;\n        for (int i = 0; i < S.size(); i++) {\n        \
    \    const int u = S[i];\n            sz[u] = 1;\n            for (int to : T[u])\
    \ {\n                if (to == pre[u] || ~timing[to])\n                    continue;\n\
    \                pre[to] = u;\n                S.push_back(to);\n            }\n\
    \        }\n        int SZ = S.size();\n        std::ranges::reverse(S);\n   \
    \     for (int u : S) {\n            if (SZ - sz[u] <= SZ / 2)\n             \
    \   return u;\n            sz[pre[u]] += sz[u];\n        }\n        assert(false);\n\
    \        return -1;\n    };\n\n  public:\n    std::vector<int> order;\n    CentroidDecomposition(TREE\
    \ T) : T(T), sz(T.n), pre(T.n), timing(T.n, -1) {\n        order.reserve(T.n);\n\
    \        std::queue<int> que;\n        que.push(0);\n        while (que.size())\
    \ {\n            int c = find_centroid(que.front());\n            que.pop();\n\
    \            timing[c] = order.size();\n            order.push_back(c);\n    \
    \        for (int to : T[c])\n                if (timing[to] < 0)\n          \
    \          que.push(to);\n        }\n    }\n\n    template <typename X, typename\
    \ F, typename G, typename H>\n    void calc(int root, X initial_val, const F &next_val,\
    \ const G &action,\n              const H &finish) {\n        std::queue<std::tuple<int,\
    \ int, X>> que;\n\n        auto f = [&](int v_, int pre_, X val_, bool is_all)\
    \ {\n            que.emplace(v_, pre_, val_);\n            while (que.size())\
    \ {\n                auto [v, pre, val] = que.front();\n                que.pop();\n\
    \                action(val, is_all);\n                for (const auto &e : T[v])\
    \ {\n                    if (e.to == pre || timing[e.to] <= timing[root])\n  \
    \                      continue;\n                    que.emplace(e.to, v, next_val(val,\
    \ e));\n                }\n            }\n            finish(is_all);\n      \
    \  };\n\n        for (const auto &e : T[root])\n            if (timing[e.to] >\
    \ timing[root])\n                f(e.to, root, next_val(initial_val, e), false);\n\
    \n        f(root, -1, initial_val, true);\n    }\n\n    template <typename X,\
    \ typename F, typename G, typename H>\n    void all_calc(X initial_val, const\
    \ F &next_val, const G &action,\n                  const H &finish) {\n      \
    \  for (int i = 0; i < T.n; i++)\n            calc(i, initial_val, next_val, action,\
    \ finish);\n    }\n};\n#line 2 \"library/graph/Graph.cpp\"\nstruct Edge {\n  \
    \  int from, to;\n    Edge() = default;\n    Edge(int from, int to) : from(from),\
    \ to(to) {}\n    operator int() const { return to; }\n};\n\nstruct Graph {\n \
    \   int n;\n    using edge_type = Edge;\n    std::vector<edge_type> edges;\n\n\
    \  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n    class OutgoingEdges\
    \ {\n        Graph *g;\n        int l, r;\n\n      public:\n        OutgoingEdges(Graph\
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
    \        }\n    }\n};\n#line 3 \"library/tree/Tree.cpp\"\nstruct Tree : Graph\
    \ {\n    using Graph::Graph;\n    Tree() = default;\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       add_edge(p - indexed, i);\n        }\n        build();\n    }\n    void\
    \ scan(int indexed = 1) {\n        Graph::scan(n - 1, false, indexed);\n     \
    \   build();\n    }\n\n    edge_type &parent(int v) {\n        assert(~root and\
    \ root != v);\n        return (*this)[v][0];\n    }\n    OutgoingEdges son(int\
    \ v) {\n        assert(~root);\n        if (v == root)\n            return {this,\
    \ in_deg[v], in_deg[v + 1]};\n        return {this, in_deg[v] + 1, in_deg[v +\
    \ 1]};\n    }\n\n  private:\n    void dfs(int v, int pre = -1) {\n        for\
    \ (auto &e : (*this)[v]) {\n            if (e.to == pre)\n                std::swap((*this)[v][0],\
    \ e);\n            else {\n                depth[e.to] = depth[v] + 1;\n     \
    \           dfs(e.to, v);\n            }\n        }\n        DFS.push_back(v);\n\
    \    }\n\n  public:\n    void build(int r = 0) {\n        if (!is_prepared())\n\
    \            Graph::build();\n        if (~root) {\n            assert(r == root);\n\
    \            return;\n        }\n        root = r;\n        depth = std::vector<int>(n,\
    \ 0);\n        DFS.reserve(n);\n        BFS.reserve(n);\n        dfs(root);\n\
    \        std::queue<int> que;\n        que.push(root);\n        while (que.size())\
    \ {\n            int p = que.front();\n            que.pop();\n            BFS.push_back(p);\n\
    \            for (const auto &e : son(p))\n                que.push(e.to);\n \
    \       }\n    }\n};\n#line 10 \"test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    Tree T(n);\n\
    \    T.scan(0);\n\n    CentroidDecomposition CD(T);\n\n    std::vector<ll> ans(n,\
    \ 0), D{0};\n\n    auto next_val = [&](int d, auto &e) { return d + 1; };\n  \
    \  auto action = [&](int d, bool add) {\n        if (D.size() <= d)\n        \
    \    D.push_back(0);\n        D[d]++;\n    };\n    auto finish = [&](bool add)\
    \ {\n        auto D2 = convolution_ll(D, D);\n        for (int i = 0; i < D2.size()\
    \ and i < n; i++)\n            if (add)\n                ans[i] += D2[i];\n  \
    \          else\n                ans[i] -= D2[i];\n        D = std::vector<ll>{0};\n\
    \    };\n\n    CD.all_calc(0, next_val, action, finish);\n\n    for (int i = 1;\
    \ i < n; i++)\n        std::cout << ans[i] / 2 << \"\\n \"[i + 1 < n];\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n#include <bits/stdc++.h>\n\n#include <atcoder/convolution>\nusing namespace\
    \ atcoder;\n\n#include \"library/tree/CentroidDecomposition.cpp\"\n#include \"\
    library/tree/Tree.cpp\"\n\nusing ll = long long;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    Tree T(n);\n\
    \    T.scan(0);\n\n    CentroidDecomposition CD(T);\n\n    std::vector<ll> ans(n,\
    \ 0), D{0};\n\n    auto next_val = [&](int d, auto &e) { return d + 1; };\n  \
    \  auto action = [&](int d, bool add) {\n        if (D.size() <= d)\n        \
    \    D.push_back(0);\n        D[d]++;\n    };\n    auto finish = [&](bool add)\
    \ {\n        auto D2 = convolution_ll(D, D);\n        for (int i = 0; i < D2.size()\
    \ and i < n; i++)\n            if (add)\n                ans[i] += D2[i];\n  \
    \          else\n                ans[i] -= D2[i];\n        D = std::vector<ll>{0};\n\
    \    };\n\n    CD.all_calc(0, next_val, action, finish);\n\n    for (int i = 1;\
    \ i < n; i++)\n        std::cout << ans[i] / 2 << \"\\n \"[i + 1 < n];\n}"
  dependsOn:
  - library/tree/CentroidDecomposition.cpp
  - library/tree/Tree.cpp
  - library/graph/Graph.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
- /verify/test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp.html
title: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
---
