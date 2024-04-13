---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/WeightedGraph.cpp
    title: library/graph/WeightedGraph.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/graph/matching/BipartiteMatching.cpp
    title: library/graph/matching/BipartiteMatching.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  - icon: ':x:'
    path: test/AOJ/GRL_7_A.test.cpp
    title: test/AOJ/GRL_7_A.test.cpp
  - icon: ':x:'
    path: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
    title: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://misawa.github.io/others/flow/dinic_time_complexity.html
  bundledCode: "#line 2 \"library/flow/Dinic.cpp\"\n\n// https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    #line 2 \"library/graph/WeightedGraph.cpp\"\ntemplate <typename T> struct WeightedEdge\
    \ {\n    WeightedEdge() = default;\n    WeightedEdge(int from, int to, T weight)\n\
    \        : from(from), to(to), weight(weight) {}\n    int from, to;\n    T weight;\n\
    \    operator int() const { return to; }\n};\n\ntemplate <typename T> struct WeightedGraph\
    \ {\n    int n;\n    using weight_type = T;\n    using edge_type = WeightedEdge<T>;\n\
    \    std::vector<edge_type> edges;\n\n  protected:\n    std::vector<int> in_deg;\n\
    \    bool prepared;\n    class OutgoingEdges {\n        WeightedGraph *g;\n  \
    \      int l, r;\n\n      public:\n        OutgoingEdges(WeightedGraph *g, int\
    \ l, int r) : g(g), l(l), r(r) {}\n        edge_type *begin() { return &(g->edges[l]);\
    \ }\n        edge_type *end() { return &(g->edges[r]); }\n        edge_type &operator[](int\
    \ i) { return g->edges[l + i]; }\n        int size() const { return r - l; }\n\
    \    };\n    class ConstOutgoingEdges {\n        const WeightedGraph *g;\n   \
    \     int l, r;\n\n      public:\n        ConstOutgoingEdges(const WeightedGraph\
    \ *g, int l, int r)\n            : g(g), l(l), r(r) {}\n        const edge_type\
    \ *begin() const { return &(g->edges[l]); }\n        const edge_type *end() const\
    \ { return &(g->edges[r]); }\n        const edge_type &operator[](int i) const\
    \ { return g->edges[l + i]; }\n        int size() const { return r - l; }\n  \
    \  };\n\n  public:\n    OutgoingEdges operator[](int v) {\n        assert(prepared);\n\
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
    \        cerr << \"\\n\";\n        }\n    }\n};\n#line 5 \"library/flow/Dinic.cpp\"\
    \ntemplate <typename T> class Dinic {\n    struct EdgeInfo {\n        T cap;\n\
    \        int rev;\n    };\n    WeightedGraph<EdgeInfo> G;\n    std::vector<int>\
    \ level, current_edge, out_deg;\n    int s, t;\n    std::vector<std::pair<int,\
    \ int>> edge_memo;\n\n    std::queue<int> que;\n    void bfs() {\n        // level[v]\u3092\
    \uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\u306B\u3059\u308B\n        // \u5230\u9054\u51FA\u6765\
    \u306A\u3051\u308C\u3070-1\n        fill(level.begin(), level.end(), -1);\n  \
    \      level[s] = 0;\n        que.emplace(s);\n        while (que.size()) {\n\
    \            int v = que.front();\n            que.pop();\n            for (const\
    \ auto &e : G[v]) {\n                const auto &[cap, rev] = e.weight;\n    \
    \            if (cap == 0 || ~level[e.to])\n                    continue;\n  \
    \              level[e.to] = level[v] + 1;\n                que.emplace(e.to);\n\
    \            }\n        }\n    }\n    T dfs(int v, T f) {\n        // v\u304B\u3089\
    t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\
    \u3063\u3066\u3053\u308C\u305F\u6C34\u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\
    \u308A\u5024\n        if (v == t)\n            return f;\n        for (int &i\
    \ = current_edge[v]; i < G[v].size();\n             i++) { // \u3053\u306Edfs\u3067\
    \u4F7F\u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\
    \u308F\u308C\u308B\u3053\u3068\u306F\u306A\u3044\n            auto &e = G[v][i];\n\
    \            auto &[cap, rev] = e.weight;\n            if (cap > 0 &&\n      \
    \          level[v] <\n                    level\n                        [e.to])\
    \ { // bfs\u3092\u3057\u3066\u3044\u308B\u306E\u3067level[v]<level[e.to]\u306A\
    \u3089level[v]+1==level[e.to]\n                T d = dfs(e.to, min(f, cap));\n\
    \                if (d == 0)\n                    continue;\n                cap\
    \ -= d;\n                G[e.to][rev].weight.cap += d;\n                return\
    \ d; // \u4E00\u672C\u6D41\u305B\u305F\u3089return\n            }\n        }\n\
    \        return 0;\n    }\n\n  public:\n    Dinic() = default;\n    Dinic(int\
    \ n, int s = 0, int t_ = -1)\n        : G(n), level(n), current_edge(n), out_deg(n,\
    \ 0), s(s), t(t_) {\n        if (t < 0)\n            t = n - 1;\n    }\n\n   \
    \ // 0-indexed \u3067 edge_id \u756A\u76EE\u306B\u8FFD\u52A0\u3057\u305F\u8FBA\
    \u306B\u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n    T operator[](const int edge_id)\
    \ const {\n        assert(G.is_prepared());\n        const auto &[from, id] =\
    \ edge_memo[edge_id];\n        return G.edge[from][id].weight.cap;\n    }\n  \
    \  // \u8FBA\u3092\u8FFD\u52A0\u3057\u305F\u9806\u756A\u306B [from,to,\u6D41\u91CF\
    ]\n    std::vector<tuple<int, int, T>> all_edge() {\n        assert(G.is_prepared());\n\
    \        std::vector<tuple<int, int, T>> res;\n        res.reserve(edge_memo.size());\n\
    \        for (const auto &[v, id] : edge_memo) {\n            const auto &[to,\
    \ from, weight] = G[v][id];\n            res.emplace_back(from, to, weight.cap);\n\
    \        }\n        return res;\n    }\n\n    void add_arc(int from, int to, T\
    \ cap) {\n        G.add_arc(from, to, {cap, out_deg[to]});\n        G.add_arc(to,\
    \ from, {0, out_deg[from]++});\n        edge_memo.emplace_back(to, out_deg[to]++);\n\
    \    }\n    T flow(T lim = numeric_limits<T>::max() / 2) {\n        if (!G.is_prepared())\n\
    \            G.build();\n        T fl = 0;\n        while (lim > 0) {\n      \
    \      bfs();\n            if (level[t] < 0)\n                break;\n       \
    \     fill(current_edge.begin(), current_edge.end(), 0);\n            while (true)\
    \ {\n                T f = dfs(s, lim);\n                if (f == 0)\n       \
    \             break;\n                fl += f;\n                lim -= f;\n  \
    \          }\n        }\n        return fl;\n    }\n\n    T st_flow(int s_, int\
    \ t_, T lim = numeric_limits<T>::max() / 2) {\n        s = s_;\n        t = t_;\n\
    \        return flow(lim);\n    }\n};\n"
  code: "#pragma once\n\n// https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    #include \"library/graph/WeightedGraph.cpp\"\ntemplate <typename T> class Dinic\
    \ {\n    struct EdgeInfo {\n        T cap;\n        int rev;\n    };\n    WeightedGraph<EdgeInfo>\
    \ G;\n    std::vector<int> level, current_edge, out_deg;\n    int s, t;\n    std::vector<std::pair<int,\
    \ int>> edge_memo;\n\n    std::queue<int> que;\n    void bfs() {\n        // level[v]\u3092\
    \uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\u306B\u3059\u308B\n        // \u5230\u9054\u51FA\u6765\
    \u306A\u3051\u308C\u3070-1\n        fill(level.begin(), level.end(), -1);\n  \
    \      level[s] = 0;\n        que.emplace(s);\n        while (que.size()) {\n\
    \            int v = que.front();\n            que.pop();\n            for (const\
    \ auto &e : G[v]) {\n                const auto &[cap, rev] = e.weight;\n    \
    \            if (cap == 0 || ~level[e.to])\n                    continue;\n  \
    \              level[e.to] = level[v] + 1;\n                que.emplace(e.to);\n\
    \            }\n        }\n    }\n    T dfs(int v, T f) {\n        // v\u304B\u3089\
    t\u306B\u6700\u77ED\u8DEF\u3067\u6C34\u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\
    \u3063\u3066\u3053\u308C\u305F\u6C34\u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\
    \u308A\u5024\n        if (v == t)\n            return f;\n        for (int &i\
    \ = current_edge[v]; i < G[v].size();\n             i++) { // \u3053\u306Edfs\u3067\
    \u4F7F\u308F\u306A\u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\
    \u308F\u308C\u308B\u3053\u3068\u306F\u306A\u3044\n            auto &e = G[v][i];\n\
    \            auto &[cap, rev] = e.weight;\n            if (cap > 0 &&\n      \
    \          level[v] <\n                    level\n                        [e.to])\
    \ { // bfs\u3092\u3057\u3066\u3044\u308B\u306E\u3067level[v]<level[e.to]\u306A\
    \u3089level[v]+1==level[e.to]\n                T d = dfs(e.to, min(f, cap));\n\
    \                if (d == 0)\n                    continue;\n                cap\
    \ -= d;\n                G[e.to][rev].weight.cap += d;\n                return\
    \ d; // \u4E00\u672C\u6D41\u305B\u305F\u3089return\n            }\n        }\n\
    \        return 0;\n    }\n\n  public:\n    Dinic() = default;\n    Dinic(int\
    \ n, int s = 0, int t_ = -1)\n        : G(n), level(n), current_edge(n), out_deg(n,\
    \ 0), s(s), t(t_) {\n        if (t < 0)\n            t = n - 1;\n    }\n\n   \
    \ // 0-indexed \u3067 edge_id \u756A\u76EE\u306B\u8FFD\u52A0\u3057\u305F\u8FBA\
    \u306B\u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n    T operator[](const int edge_id)\
    \ const {\n        assert(G.is_prepared());\n        const auto &[from, id] =\
    \ edge_memo[edge_id];\n        return G.edge[from][id].weight.cap;\n    }\n  \
    \  // \u8FBA\u3092\u8FFD\u52A0\u3057\u305F\u9806\u756A\u306B [from,to,\u6D41\u91CF\
    ]\n    std::vector<tuple<int, int, T>> all_edge() {\n        assert(G.is_prepared());\n\
    \        std::vector<tuple<int, int, T>> res;\n        res.reserve(edge_memo.size());\n\
    \        for (const auto &[v, id] : edge_memo) {\n            const auto &[to,\
    \ from, weight] = G[v][id];\n            res.emplace_back(from, to, weight.cap);\n\
    \        }\n        return res;\n    }\n\n    void add_arc(int from, int to, T\
    \ cap) {\n        G.add_arc(from, to, {cap, out_deg[to]});\n        G.add_arc(to,\
    \ from, {0, out_deg[from]++});\n        edge_memo.emplace_back(to, out_deg[to]++);\n\
    \    }\n    T flow(T lim = numeric_limits<T>::max() / 2) {\n        if (!G.is_prepared())\n\
    \            G.build();\n        T fl = 0;\n        while (lim > 0) {\n      \
    \      bfs();\n            if (level[t] < 0)\n                break;\n       \
    \     fill(current_edge.begin(), current_edge.end(), 0);\n            while (true)\
    \ {\n                T f = dfs(s, lim);\n                if (f == 0)\n       \
    \             break;\n                fl += f;\n                lim -= f;\n  \
    \          }\n        }\n        return fl;\n    }\n\n    T st_flow(int s_, int\
    \ t_, T lim = numeric_limits<T>::max() / 2) {\n        s = s_;\n        t = t_;\n\
    \        return flow(lim);\n    }\n};"
  dependsOn:
  - library/graph/WeightedGraph.cpp
  isVerificationFile: false
  path: library/flow/Dinic.cpp
  requiredBy:
  - library/graph/matching/BipartiteMatching.cpp
  timestamp: '2024-04-13 18:46:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  - test/AOJ/GRL_7_A.test.cpp
  - test/AOJ/GRL_6_A.test.cpp
documentation_of: library/flow/Dinic.cpp
layout: document
redirect_from:
- /library/library/flow/Dinic.cpp
- /library/library/flow/Dinic.cpp.html
title: library/flow/Dinic.cpp
---
