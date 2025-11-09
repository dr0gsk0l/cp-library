---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/flow/MCF.hpp
    title: library/flow/MCF.hpp
  - icon: ':question:'
    path: library/graph/WeightedGraph.hpp
    title: library/graph/WeightedGraph.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/matching/WeightedBipartiteMatching.hpp
    title: library/graph/matching/WeightedBipartiteMatching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/library-checker/Graph/AssignmentProblem.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include <bits/stdc++.h>\n\
    \n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n#line 2 \"library/graph/WeightedGraph.hpp\"\
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
    \    }\n};\n#line 3 \"library/flow/MCF.hpp\"\n#define REP_(i, n) for (int i =\
    \ 0; i < (n); i++)\ntemplate <typename TF, typename TC> class MCF {\n    struct\
    \ EdgeInfo {\n        TF cap;\n        TC cost;\n        int rev;\n    };\n  \
    \  int n, s, t;\n    WeightedGraph<EdgeInfo> G;\n    std::vector<TC> potential,\
    \ dist;\n    static constexpr TC INF = std::numeric_limits<TC>::max() / 2;\n \
    \   std::vector<std::pair<int, int>> pre,\n        edge_memo; // pre[v]=[u,i]\
    \ : G[u][i] \u3067 v \u306B\u6765\u305F\n    std::vector<int> in_deg, out_deg;\n\
    \n    bool negative, dag;\n\n    template <typename T> bool chmin(T &a, const\
    \ T &b) {\n        return (a > b and (a = b, true));\n    }\n    bool SP_update(int\
    \ from, int edge_id) {\n        if (dist[from] == INF)\n            return false;\n\
    \        const auto &e = G[from][edge_id];\n        if ((e.weight).cap == 0)\n\
    \            return false;\n        if (chmin(dist[e.to], dist[from] + (e.weight).cost\
    \ + potential[from] -\n                                  potential[e.to])) {\n\
    \            pre[e.to] = {from, edge_id};\n            return true;\n        }\n\
    \        return false;\n    }\n\n    std::priority_queue<std::pair<TC, int>, std::vector<std::pair<TC,\
    \ int>>,\n                        std::greater<std::pair<TC, int>>>\n        que;\n\
    \    void dijkstra() { // dist[i]:s\u304B\u3089\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\
    \u8FBA\u306E\u91CD\u307F\u306B\u3088\u308Bi\u3078\u306E\u6700\u77ED\u8DEF\n  \
    \                    // \u3068\u306A\u308B\u3088\u3046\u306Bdist\u3092\u4F5C\u308B\
    \n        std::ranges::fill(dist, INF);\n        dist[s] = 0;\n        que.emplace(0,\
    \ s);\n        while (que.size()) {\n            const auto [now, v] = que.top();\n\
    \            que.pop();\n            if (dist[v] < now)\n                continue;\n\
    \            REP_(i, G[v].size())\n            if (SP_update(v, i))\n        \
    \        que.emplace(dist[G[v][i].to], G[v][i].to);\n        }\n    }\n\n    void\
    \ DAG() {\n        negative = false;\n        std::ranges::fill(dist, INF);\n\
    \        dist[s] = 0;\n        std::queue<int> que;\n        REP_(i, n) if (!in_deg[i])\
    \ que.push(i);\n        while (que.size()) {\n            int v = que.front();\n\
    \            que.pop();\n            REP_(i, G[v].size()) {\n                SP_update(v,\
    \ i);\n                if (!--in_deg[G[v][i].to])\n                    que.push(G[v][i].to);\n\
    \            }\n        }\n    }\n\n    void BellmanFord() {\n        negative\
    \ = false;\n        std::ranges::fill(dist, INF);\n        dist[s] = 0;\n    \
    \    REP_(_, n) {\n            bool update = false;\n            REP_(v, n)\n\
    \            if (dist[v] < INF)\n                REP_(i, G[v].size()) if (SP_update(v,\
    \ i)) update = true;\n            if (!update)\n                return;\n    \
    \    }\n        assert(false); // \u8CA0\u9589\u8DEF\n    }\n\n  public:\n   \
    \ MCF() {}\n    MCF(int n_, int s_ = 0, int t_ = -1)\n        : n(n_), G(n_),\
    \ potential(n_, 0), dist(n_), pre(n_), in_deg(n_, 0),\n          out_deg(n_, 0),\
    \ negative(false), dag(true), s(s_), t(t_) {\n        if (t < 0)\n           \
    \ t = n - 1;\n    }\n    void use_bellman_ford() { dag = false; }\n\n    TF operator[](const\
    \ int edge_id) const {\n        assert(G.is_prepared());\n        const auto &[from,\
    \ id] = edge_memo[edge_id];\n        return G.edge[from][id].weight.cap;\n   \
    \ }\n    std::vector<std::tuple<int, int, TF, TC>> all_edge() {\n        assert(G.is_prepared());\n\
    \        std::vector<std::tuple<int, int, TF, TC>> res;\n        res.reserve(edge_memo.size());\n\
    \        for (const auto &[v, id] : edge_memo) {\n            const auto &[to,\
    \ from, weight] = G[v][id];\n            res.emplace_back(from, to, weight.cap,\
    \ -weight.cost);\n        }\n        return res;\n    }\n\n    void add_arc(int\
    \ from, int to, TF cap, TC cost) {\n        G.add_arc(from, to, {cap, cost, out_deg[to]});\n\
    \        G.add_arc(to, from, {0, -cost, out_deg[from]++});\n        edge_memo.emplace_back(to,\
    \ out_deg[to]++);\n        if (cap > 0) {\n            in_deg[to]++;\n       \
    \     negative |= cost < 0;\n        }\n    }\n\n    std::pair<TC, bool>\n   \
    \ flow(TF f = std::numeric_limits<\n             TF>::max()) { // second \u304C\
    \ 0\n                           // \u3067\u8FD4\u3063\u3066\u304D\u305F\u5834\u5408\
    \u306F\u305D\u3082\u305D\u3082\u6700\u5927\u6D41\u304Cf\u306B\u9054\u3057\u306A\
    \u3044\n        if (!G.is_prepared())\n            G.build();\n        TC res\
    \ = 0;\n        std::ranges::fill(\n            potential,\n            0); //\
    \ \u4E00\u756A\u6700\u521D\u306F\u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\
    \u7121\u3044\u304B\u3089\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F0\u306B\u3057\
    \u3066\u3044\u3044\n        while (f > 0) {\n            if (negative)\n     \
    \           if (dag)\n                    DAG();\n                else\n     \
    \               BellmanFord();\n            else\n                dijkstra();\n\
    \            if (dist[t] == INF)\n                return std::make_pair(res, false);\n\
    \            REP_(v, n) if (dist[v] < INF) potential[v] += dist[v];\n        \
    \    TF d = f; // d:\u4ECA\u56DE\u6D41\u3059\u91CF\n            for (int v = t;\
    \ v != s; v = pre[v].first)\n                chmin(d, (G[pre[v].first][pre[v].second].weight).cap);\n\
    \            f -= d;\n            res += potential[t] * d;\n            for (int\
    \ v = t; v != s; v = pre[v].first) {\n                auto &[cap, cost, rev] =\
    \ G[pre[v].first][pre[v].second].weight;\n                cap -= d;\n        \
    \        (G[v][rev].weight).cap += d;\n            }\n        } // \u3053\u306E\
    \u30EB\u30FC\u30D7\u3092\u629C\u3051\u3066\u308B\u306A\u3089f\u6D41\u308C\u3066\
    \u308B\n        return std::make_pair(res, true);\n    }\n\n    std::pair<TC,\
    \ bool> st_flow(int s_, int t_,\n                                TF lim = std::numeric_limits<TF>::max()\
    \ / 2) {\n        s = s_;\n        t = t_;\n        return flow(lim);\n    }\n\
    };\n#undef REP_\n#line 3 \"library/graph/matching/WeightedBipartiteMatching.hpp\"\
    \n// \u91CD\u307F\u306E\u6700\u5927\u5316\ntemplate <typename TC> class WeightedBipartiteMatching\
    \ {\n    int A, B; // \u5DE6\u53F3\u306E\u9802\u70B9\u6570\n    int S, T;\n  \
    \  MCF<int, TC> fl;\n\n  public:\n    WeightedBipartiteMatching(int A, int B)\n\
    \        : A(A), B(B), S(A + B), T(A + B + 1), fl(A + B + 2, S, T) {\n       \
    \ for (int i = 0; i < A; i++)\n            fl.add_arc(S, i, 1, 0);\n        for\
    \ (int j = 0; j < B; j++)\n            fl.add_arc(A + j, T, 1, 0);\n    }\n  \
    \  void add_edge(int u, int v, TC weight) {\n        assert(0 <= u and u < A);\n\
    \        assert(0 <= v and v < B);\n        fl.add_arc(u, A + v, 1, -weight);\n\
    \    }\n\n    // first \u306F\u91CD\u307F\u306E\u7DCF\u548C\n    // second \u306F\
    \u30DE\u30C3\u30C1\u3057\u305F\u5404 [u,v,weight]\n    std::pair<TC, std::vector<std::tuple<int,\
    \ int, TC>>> solve() {\n        auto [sum, ok] = fl.flow(std::min(A, B));\n  \
    \      std::vector<std::tuple<int, int, TC>> res;\n        auto all_edge = fl.all_edge();\n\
    \        for (int i = A + B; i < all_edge.size(); i++) {\n            const auto\
    \ &[from, to, flow, cost] = all_edge[i];\n            if (flow)\n            \
    \    res.emplace_back(from, to - A, -cost);\n        }\n        return std::make_pair(-sum,\
    \ res);\n    }\n};\n#line 7 \"test/library-checker/Graph/AssignmentProblem.test.cpp\"\
    \nusing ll = long long;\nconstexpr ll INF = ll(1e9) + 1;\n\nint main() {\n   \
    \ std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int n;\n\
    \    std::cin >> n;\n    WeightedBipartiteMatching<ll> B(n, n);\n    REP (i, n)\n\
    \        REP (j, n) {\n            int a;\n            std::cin >> a;\n      \
    \      B.add_edge(i, j, INF - a);\n        }\n    auto [sum, vec] = B.solve();\n\
    \n    sum -= n * INF;\n    sum = -sum;\n\n    std::vector<int> res(n);\n    for\
    \ (const auto &[from, to, weight] : vec)\n        res[from] = to;\n\n    std::cout\
    \ << sum << \"\\n\";\n    REP (i, n)\n        std::cout << res[i] << \"\\n \"\
    [i + 1 < n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n#include\
    \ \"library/graph/matching/WeightedBipartiteMatching.hpp\"\nusing ll = long long;\n\
    constexpr ll INF = ll(1e9) + 1;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    WeightedBipartiteMatching<ll>\
    \ B(n, n);\n    REP (i, n)\n        REP (j, n) {\n            int a;\n       \
    \     std::cin >> a;\n            B.add_edge(i, j, INF - a);\n        }\n    auto\
    \ [sum, vec] = B.solve();\n\n    sum -= n * INF;\n    sum = -sum;\n\n    std::vector<int>\
    \ res(n);\n    for (const auto &[from, to, weight] : vec)\n        res[from] =\
    \ to;\n\n    std::cout << sum << \"\\n\";\n    REP (i, n)\n        std::cout <<\
    \ res[i] << \"\\n \"[i + 1 < n];\n}\n"
  dependsOn:
  - library/graph/matching/WeightedBipartiteMatching.hpp
  - library/flow/MCF.hpp
  - library/graph/WeightedGraph.hpp
  isVerificationFile: true
  path: test/library-checker/Graph/AssignmentProblem.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Graph/AssignmentProblem.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/AssignmentProblem.test.cpp
- /verify/test/library-checker/Graph/AssignmentProblem.test.cpp.html
title: test/library-checker/Graph/AssignmentProblem.test.cpp
---
