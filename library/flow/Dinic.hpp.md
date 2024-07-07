---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://misawa.github.io/others/flow/dinic_time_complexity.html
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
  code: "#pragma once\n\n// https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    #include \"library/graph/WeightedGraph.cpp\"\ntemplate <typename T> class Dinic\
    \ {\n    struct EdgeInfo {\n        T cap;\n        int rev;\n    };\n    WeightedGraph<EdgeInfo>\
    \ G;\n    std::vector<int> level, current_edge, out_deg;\n    int s, t;\n    std::vector<std::pair<int,\
    \ int>> edge_memo;\n\n    std::queue<int> que;\n    void bfs() {\n        // level[v]\u3092\
    \uFF08\u5BB9\u91CF\u6B63\u306E\u8FBA\u306B\u3088\u308B\uFF09s\u304B\u3089\u306E\
    \u6700\u77ED\u8DDD\u96E2\u306B\u3059\u308B\n        // \u5230\u9054\u51FA\u6765\
    \u306A\u3051\u308C\u3070-1\n        std::ranges::fill(level, -1);\n        level[s]\
    \ = 0;\n        que.emplace(s);\n        while (que.size()) {\n            int\
    \ v = que.front();\n            que.pop();\n            for (const auto &e : G[v])\
    \ {\n                const auto &[cap, rev] = e.weight;\n                if (cap\
    \ == 0 || ~level[e.to])\n                    continue;\n                level[e.to]\
    \ = level[v] + 1;\n                que.emplace(e.to);\n            }\n       \
    \ }\n    }\n    T dfs(int v, T f) {\n        // v\u304B\u3089t\u306B\u6700\u77ED\
    \u8DEF\u3067\u6C34\u3092\u6D41\u3059 f\u304Cv\u307E\u3067\u6301\u3063\u3066\u3053\
    \u308C\u305F\u6C34\u91CF \u6D41\u305B\u305F\u91CF\u304C\u8FD4\u308A\u5024\n  \
    \      if (v == t)\n            return f;\n        for (int &i = current_edge[v];\
    \ i < G[v].size();\n             i++) { // \u3053\u306Edfs\u3067\u4F7F\u308F\u306A\
    \u304B\u3063\u305F\u8FBA\u306F\u6B21\u306EBFS\u307E\u3067\u4F7F\u308F\u308C\u308B\
    \u3053\u3068\u306F\u306A\u3044\n            auto &e = G[v][i];\n            auto\
    \ &[cap, rev] = e.weight;\n            if (cap > 0 &&\n                level[v]\
    \ <\n                    level\n                        [e.to]) { // bfs\u3092\
    \u3057\u3066\u3044\u308B\u306E\u3067level[v]<level[e.to]\u306A\u3089level[v]+1==level[e.to]\n\
    \                T d = dfs(e.to, std::min(f, cap));\n                if (d ==\
    \ 0)\n                    continue;\n                cap -= d;\n             \
    \   G[e.to][rev].weight.cap += d;\n                return d; // \u4E00\u672C\u6D41\
    \u305B\u305F\u3089return\n            }\n        }\n        return 0;\n    }\n\
    \n  public:\n    Dinic() = default;\n    Dinic(int n, int s = 0, int t_ = -1)\n\
    \        : G(n), level(n), current_edge(n), out_deg(n, 0), s(s), t(t_) {\n   \
    \     if (t < 0)\n            t = n - 1;\n    }\n\n    // 0-indexed \u3067 edge_id\
    \ \u756A\u76EE\u306B\u8FFD\u52A0\u3057\u305F\u8FBA\u306B\u6D41\u3057\u305F\u91CF\
    \u3092\u8FD4\u3059\n    T operator[](const int edge_id) const {\n        assert(G.is_prepared());\n\
    \        const auto &[from, id] = edge_memo[edge_id];\n        return G.edge[from][id].weight.cap;\n\
    \    }\n    // \u8FBA\u3092\u8FFD\u52A0\u3057\u305F\u9806\u756A\u306B [from,to,\u6D41\
    \u91CF]\n    std::vector<std::tuple<int, int, T>> all_edge() {\n        assert(G.is_prepared());\n\
    \        std::vector<std::tuple<int, int, T>> res;\n        res.reserve(edge_memo.size());\n\
    \        for (const auto &[v, id] : edge_memo) {\n            const auto &[to,\
    \ from, weight] = G[v][id];\n            res.emplace_back(from, to, weight.cap);\n\
    \        }\n        return res;\n    }\n\n    void add_arc(int from, int to, T\
    \ cap) {\n        G.add_arc(from, to, {cap, out_deg[to]});\n        G.add_arc(to,\
    \ from, {0, out_deg[from]++});\n        edge_memo.emplace_back(to, out_deg[to]++);\n\
    \    }\n    T flow(T lim = std::numeric_limits<T>::max() / 2) {\n        if (!G.is_prepared())\n\
    \            G.build();\n        T fl = 0;\n        while (lim > 0) {\n      \
    \      bfs();\n            if (level[t] < 0)\n                break;\n       \
    \     std::ranges::fill(current_edge, 0);\n            while (true) {\n      \
    \          T f = dfs(s, lim);\n                if (f == 0)\n                 \
    \   break;\n                fl += f;\n                lim -= f;\n            }\n\
    \        }\n        return fl;\n    }\n\n    T st_flow(int s_, int t_, T lim =\
    \ std::numeric_limits<T>::max() / 2) {\n        s = s_;\n        t = t_;\n   \
    \     return flow(lim);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/Dinic.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/flow/Dinic.hpp
layout: document
redirect_from:
- /library/library/flow/Dinic.hpp
- /library/library/flow/Dinic.hpp.html
title: library/flow/Dinic.hpp
---
