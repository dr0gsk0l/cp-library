---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/WeightedGraph.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n// \u8FBA\u306E\u91CD\u307F\u304C\u6D41\u91CF\u306B\u5BFE\u3057\
    \u3066\u5358\u8ABF\u5897\u52A0\u306A\u95A2\u6570\n// \u73FE\u5728\u306E\u6D41\u91CF\
    \u3092\u5F15\u6570\u3068\u3057\u3066\u3001\u305D\u3053\u306B\u65B0\u305F\u306B\
    \ 1 \u6D41\u3059\u6642\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FD4\u3059\
    \u95A2\u6570\u3092\u6E21\u3059\n#include \"library/graph/WeightedGraph.cpp\"\n\
    #define REP_(i, n) for (int i = 0; i < (n); i++)\ntemplate <typename TC> class\
    \ NondecreasingMCF {\n    using F = std::function<TC(int)>;\n    struct EdgeInfo\
    \ {\n        int cap, flow, rev;\n        bool reverse_edge;\n        F cost_func;\n\
    \n        EdgeInfo() = default;\n        EdgeInfo(int cap, F cost_func, int rev,\
    \ bool reverse_edge)\n            : cap(cap), cost_func(cost_func), rev(rev),\n\
    \              reverse_edge(reverse_edge), flow(0) {}\n\n        TC cost() const\
    \ {\n            if (!reverse_edge)\n                return cost_func(flow);\n\
    \            return -cost_func(cap - 1);\n        }\n    };\n    int n;\n    WeightedGraph<EdgeInfo>\
    \ G;\n    std::vector<TC> potential, dist;\n    static constexpr TC INF = std::is_same_v<TC,\
    \ __int128>\n                                  ? TC(1e30)\n                  \
    \                : std::numeric_limits<TC>::max() / 2;\n    //  std::numeric_limits<__int128\
    \ >::max() \u306F AOJ \u3067\u30D0\u30B0\u3063\u305F\n    std::vector<std::pair<int,\
    \ int>> pre; // pre[v]=[u,i] : G[u][i] \u3067 v \u306B\u6765\u305F\n    std::vector<int>\
    \ in_deg, out_deg;\n    std::priority_queue<std::pair<TC, int>, std::vector<std::pair<TC,\
    \ int>>,\n                        std::greater<std::pair<TC, int>>>\n        que;\n\
    \    bool negative = false; // \u8CA0\u8FBA\u5B58\u5728\u3059\u308B\u304B\n\n\
    \    template <typename T> bool chmin(T &a, const T &b) {\n        return (a >\
    \ b and (a = b, true));\n    }\n    bool SP_update(int from, int edge_id) {\n\
    \        const auto &e = G[from][edge_id];\n        if ((e.weight).cap == 0)\n\
    \            return false;\n        if (chmin(dist[e.to], dist[from] + (e.weight).cost()\
    \ + potential[from] -\n                                  potential[e.to])) {\n\
    \            pre[e.to] = {from, edge_id};\n            return true;\n        }\n\
    \        return false;\n    }\n\n    void dijkstra(int s) { // dist[i]:s\u304B\
    \u3089\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\u8FBA\u306E\u91CD\u307F\u306B\u3088\
    \u308Bi\u3078\u306E\u6700\u77ED\u8DEF\n                           // \u3068\u306A\
    \u308B\u3088\u3046\u306Bdist\u3092\u4F5C\u308B\n        std::ranges::fill(dist,\
    \ INF);\n        dist[s] = 0;\n        que.emplace(0, s);\n        while (que.size())\
    \ {\n            const auto [now, v] = que.top();\n            que.pop();\n  \
    \          if (dist[v] < now)\n                continue;\n            REP_(i,\
    \ G[v].size())\n            if (SP_update(v, i))\n                que.emplace(dist[G[v][i].to],\
    \ G[v][i].to);\n        }\n    }\n\n    void DAG(int s) {\n        negative =\
    \ false;\n        std::ranges::fill(dist, INF);\n        dist[s] = 0;\n      \
    \  std::queue<int> que;\n        REP_(i, n) if (!in_deg[i]) que.push(i);\n   \
    \     while (que.size()) {\n            int v = que.front();\n            que.pop();\n\
    \            REP_(i, G[v].size()) {\n                SP_update(v, i);\n      \
    \          if (!--in_deg[G[v][i].to])\n                    que.push(G[v][i].to);\n\
    \            }\n        }\n    }\n\n  public:\n    NondecreasingMCF() {}\n   \
    \ NondecreasingMCF(int n_)\n        : n(n_), G(n_), potential(n_, 0), dist(n_),\
    \ pre(n_), in_deg(n_, 0),\n          out_deg(n_, 0), negative(false) {}\n\n  \
    \  void add_arc(int u, int v, int cap, F cost_func) {\n        G.add_arc(u, v,\
    \ {cap, cost_func, out_deg[v], false});\n        G.add_arc(v, u, {0, cost_func,\
    \ out_deg[u], true});\n        out_deg[v]++;\n        out_deg[u]++;\n        if\
    \ (cap > 0) {\n            in_deg[v]++;\n            negative |= cost_func(0)\
    \ < 0;\n        }\n    }\n\n    std::pair<TC, bool> flow(int s, int t, int f)\
    \ {\n        if (!G.is_prepared())\n            G.build();\n        TC res = 0;\n\
    \        std::ranges::fill(potential, 0);\n        for (int i = 0; i < f; i++)\
    \ {\n            if (negative)\n                DAG(s);\n            else\n  \
    \              dijkstra(s);\n            if (dist[t] == INF)\n               \
    \ return std::make_pair(res, false);\n            REP_(v, n) if (dist[v] != INF)\
    \ potential[v] += dist[v];\n            res += potential[t];\n            for\
    \ (int v = t; v != s; v = pre[v].first) {\n                auto &w = G[pre[v].first][pre[v].second].weight;\n\
    \                w.cap--;\n                w.flow++;\n                auto &r\
    \ = G[v][w.rev].weight;\n                r.cap++;\n                r.flow--;\n\
    \            }\n        }\n        return std::make_pair(res, true);\n    }\n\
    };\n#undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/NondecreasingMCF.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/flow/NondecreasingMCF.hpp
layout: document
redirect_from:
- /library/library/flow/NondecreasingMCF.hpp
- /library/library/flow/NondecreasingMCF.hpp.html
title: library/flow/NondecreasingMCF.hpp
---
