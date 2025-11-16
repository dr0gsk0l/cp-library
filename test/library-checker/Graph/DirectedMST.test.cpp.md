---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.hpp
    title: library/datastructure/unionfind/UnionFind.hpp
  - icon: ':question:'
    path: library/graph/MinimumSpanningArborescence.hpp
    title: library/graph/MinimumSpanningArborescence.hpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.hpp
    title: library/graph/WeightedGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"test/library-checker/Graph/DirectedMST.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n#define IGNORE\n#include\
    \ <bits/stdc++.h>\n\n#line 3 \"library/datastructure/unionfind/UnionFind.hpp\"\
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
    };\n#line 3 \"library/graph/MinimumSpanningArborescence.hpp\"\ntemplate <typename\
    \ WG, typename W = typename WG::weight_type>\nstd::optional<std::pair<W, std::vector<int>>>\n\
    minimum_spanning_arborescence(WG g, int r = 0) {\n    int n = g.n;\n    W res\
    \ = 0;\n    std::vector<W> new_add(n, 0);\n    std::vector<int> tree(n), pre(n),\
    \ state(n, 0);\n    UnionFind uf(n);\n    state[r] = 2;\n\n    auto compare =\
    \ [&](const int &a, const int &b) {\n        return g.edges[a].weight > g.edges[b].weight;\n\
    \    };\n    using PQ = std::priority_queue<int, std::vector<int>, decltype(compare)>;\n\
    \    std::vector<std::pair<PQ, W>> pq_add(n, {PQ{compare}, 0});\n    for (int\
    \ i = 0; i < g.edges.size(); i++)\n        pq_add[g.edges[i].to].first.push(i);\n\
    \    std::vector<int> pq_id(n);\n    std::iota(pq_id.begin(), pq_id.end(), 0);\n\
    \n    auto merge = [&](int u, int v) {\n        u = uf.leader(u);\n        v =\
    \ uf.leader(v);\n        if (u == v)\n            return;\n        uf.merge(u,\
    \ v);\n        auto &[pq1, add1] = pq_add[pq_id[u]];\n        auto &[pq2, add2]\
    \ = pq_add[pq_id[v]];\n        if (pq1.size() > pq2.size()) {\n            while\
    \ (pq2.size()) {\n                int edge_id = pq2.top();\n                pq2.pop();\n\
    \                g.edges[edge_id].weight -= add2 - add1;\n                pq1.push(edge_id);\n\
    \            }\n            pq_id[uf.leader(v)] = pq_id[u];\n        } else {\n\
    \            while (pq1.size()) {\n                int edge_id = pq1.top();\n\
    \                pq1.pop();\n                g.edges[edge_id].weight -= add1 -\
    \ add2;\n                pq2.push(edge_id);\n            }\n            pq_id[uf.leader(v)]\
    \ = pq_id[v];\n        }\n    };\n\n    for (int i = 0; i < n; i++) {\n      \
    \  int now = uf.leader(i);\n        if (state[now])\n            continue;\n \
    \       std::vector<int> processing;\n        while (state[now] != 2) {\n    \
    \        processing.push_back(now);\n            state[now] = 1;\n           \
    \ auto &[pq, add] = pq_add[pq_id[now]];\n            if (!pq.size())\n       \
    \         return std::nullopt;\n            int edge_id = pq.top();\n        \
    \    pq.pop();\n            auto &e = g.edges[edge_id];\n            res += e.weight\
    \ - add;\n            tree[e.to] = edge_id;\n            pre[now] = uf.leader(e.from);\n\
    \            new_add[now] = e.weight;\n            if (state[pre[now]] == 1) {\n\
    \                int v = now;\n                do {\n                    pq_add[pq_id[v]].second\
    \ = new_add[v];\n                    merge(v, now);\n                    v = uf.leader(pre[v]);\n\
    \                } while (!uf.same(v, now));\n                now = uf.leader(now);\n\
    \            } else\n                now = uf.leader(pre[now]);\n        }\n \
    \       for (int v : processing)\n            state[v] = 2;\n    }\n    tree.erase(tree.begin()\
    \ + r);\n    return std::make_pair(res, tree);\n}\n#line 2 \"library/graph/WeightedGraph.hpp\"\
    \ntemplate <typename T> struct WeightedEdge {\n    WeightedEdge() = default;\n\
    \    WeightedEdge(int from, int to, T weight)\n        : from(from), to(to), weight(weight)\
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
    \ (int from = 0; from < n; from++) {\n            std::cerr << from << \";\";\n\
    \            for (int i = in_deg[from]; i < in_deg[from + 1]; i++)\n         \
    \       std::cerr << \"(\" << edges[i].to << \",\" << edges[i].weight\n      \
    \                    << \")\";\n            std::cerr << \"\\n\";\n        }\n\
    \    }\n};\n#line 7 \"test/library-checker/Graph/DirectedMST.test.cpp\"\nusing\
    \ ll = long long;\n\nint main() {\n    int n, m, s;\n    std::cin >> n >> m >>\
    \ s;\n    WeightedGraph<ll> g(n, m, true, 0);\n    auto ans = minimum_spanning_arborescence(g,\
    \ s);\n    assert(ans.has_value());\n    auto [val, tree] = ans.value();\n   \
    \ std::vector<int> p(n);\n    p[s] = s;\n    ll sum = 0;\n    for (int id : tree)\
    \ {\n        const auto &e = g.edges[id];\n        sum += e.weight;\n        p[e.to]\
    \ = e.from;\n    }\n    val = sum; // assert(sum==val);\n    std::cout << val\
    \ << \"\\n\";\n    for (int v = 0; v < n; v++)\n        std::cout << p[v] << \"\
    \\n \"[v + 1 < n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n#define\
    \ IGNORE\n#include <bits/stdc++.h>\n\n#include \"library/graph/MinimumSpanningArborescence.hpp\"\
    \n#include \"library/graph/WeightedGraph.hpp\"\nusing ll = long long;\n\nint main()\
    \ {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n    WeightedGraph<ll> g(n,\
    \ m, true, 0);\n    auto ans = minimum_spanning_arborescence(g, s);\n    assert(ans.has_value());\n\
    \    auto [val, tree] = ans.value();\n    std::vector<int> p(n);\n    p[s] = s;\n\
    \    ll sum = 0;\n    for (int id : tree) {\n        const auto &e = g.edges[id];\n\
    \        sum += e.weight;\n        p[e.to] = e.from;\n    }\n    val = sum; //\
    \ assert(sum==val);\n    std::cout << val << \"\\n\";\n    for (int v = 0; v <\
    \ n; v++)\n        std::cout << p[v] << \"\\n \"[v + 1 < n];\n}"
  dependsOn:
  - library/graph/MinimumSpanningArborescence.hpp
  - library/datastructure/unionfind/UnionFind.hpp
  - library/graph/WeightedGraph.hpp
  isVerificationFile: true
  path: test/library-checker/Graph/DirectedMST.test.cpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/DirectedMST.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/DirectedMST.test.cpp
- /verify/test/library-checker/Graph/DirectedMST.test.cpp.html
title: test/library-checker/Graph/DirectedMST.test.cpp
---
