---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/shortest_path/BellmanFord.cpp\"\n// s \u304B\
    \u3089\u306E\u6700\u77ED\u8DDD\u96E2\u304C\u5B9A\u307E\u308B\u306A\u3089\u6700\
    \u77ED\u8DDD\u96E2, \u7121\u9650\u306B\u5C0F\u3055\u304F\u51FA\u6765\u308B\u306A\
    \u3089 std::nullopt\n// \u305D\u3082\u305D\u3082\u5230\u9054\u51FA\u6765\u306A\
    \u3044\u5834\u5408\u306F pre \u304C -1 \u306B\u306A\u3063\u3066\u3044\u308B\n\
    template <typename WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<std::optional<T>>,\
    \ std::vector<int>>\nbellman_ford(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n\
    \    int n = g.n;\n    static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n    std::vector<T> d(n, INF);\n    std::vector<int> pre(n, -1);\n    d[s]\
    \ = 0;\n    for (int _ = 0; _ < n; _++) {\n        bool update = false;\n    \
    \    for (int v = 0; v < n; v++)\n            if (d[v] < INF)\n              \
    \  for (const auto &e : g[v])\n                    if (d[e.to] > d[v] + e.weight)\
    \ {\n                        d[e.to] = d[v] + e.weight;\n                    \
    \    pre[e.to] = v;\n                        update = true;\n                \
    \    }\n        if (!update) {\n            std::vector<std::optional<T>> d_(n);\n\
    \            for (int i = 0; i < n; i++)\n                d_[i] = d[i];\n    \
    \        return {d_, pre};\n        }\n    }\n    auto now_d = d;\n    for (int\
    \ v = 0; v < n; v++)\n        if (d[v] < INF)\n            for (const auto &e\
    \ : g[v])\n                if (d[e.to] > d[v] + e.weight)\n                  \
    \  d[e.to] = d[v] + e.weight;\n    for (int _ = 1; _ < n; _++)\n        for (int\
    \ v = 0; v < n; v++)\n            if (d[v] < now_d[v])\n                for (const\
    \ auto &e : g[v])\n                    if (d[e.to] > d[v] + e.weight)\n      \
    \                  d[e.to] = d[v] + e.weight;\n    std::vector<std::optional<T>>\
    \ res(n);\n    for (int v = 0; v < n; v++)\n        if (now_d[v] == d[v])\n  \
    \          res[v] = d[v];\n        else\n            res[v] = std::nullopt;\n\
    \    return {res, pre};\n}\n"
  code: "// s \u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\u304C\u5B9A\u307E\u308B\u306A\
    \u3089\u6700\u77ED\u8DDD\u96E2, \u7121\u9650\u306B\u5C0F\u3055\u304F\u51FA\u6765\
    \u308B\u306A\u3089 std::nullopt\n// \u305D\u3082\u305D\u3082\u5230\u9054\u51FA\
    \u6765\u306A\u3044\u5834\u5408\u306F pre \u304C -1 \u306B\u306A\u3063\u3066\u3044\
    \u308B\ntemplate <typename WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<std::optional<T>>,\
    \ std::vector<int>>\nbellman_ford(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n\
    \    int n = g.n;\n    static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n    std::vector<T> d(n, INF);\n    std::vector<int> pre(n, -1);\n    d[s]\
    \ = 0;\n    for (int _ = 0; _ < n; _++) {\n        bool update = false;\n    \
    \    for (int v = 0; v < n; v++)\n            if (d[v] < INF)\n              \
    \  for (const auto &e : g[v])\n                    if (d[e.to] > d[v] + e.weight)\
    \ {\n                        d[e.to] = d[v] + e.weight;\n                    \
    \    pre[e.to] = v;\n                        update = true;\n                \
    \    }\n        if (!update) {\n            std::vector<std::optional<T>> d_(n);\n\
    \            for (int i = 0; i < n; i++)\n                d_[i] = d[i];\n    \
    \        return {d_, pre};\n        }\n    }\n    auto now_d = d;\n    for (int\
    \ v = 0; v < n; v++)\n        if (d[v] < INF)\n            for (const auto &e\
    \ : g[v])\n                if (d[e.to] > d[v] + e.weight)\n                  \
    \  d[e.to] = d[v] + e.weight;\n    for (int _ = 1; _ < n; _++)\n        for (int\
    \ v = 0; v < n; v++)\n            if (d[v] < now_d[v])\n                for (const\
    \ auto &e : g[v])\n                    if (d[e.to] > d[v] + e.weight)\n      \
    \                  d[e.to] = d[v] + e.weight;\n    std::vector<std::optional<T>>\
    \ res(n);\n    for (int v = 0; v < n; v++)\n        if (now_d[v] == d[v])\n  \
    \          res[v] = d[v];\n        else\n            res[v] = std::nullopt;\n\
    \    return {res, pre};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/shortest_path/BellmanFord.cpp
  requiredBy: []
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_B.test.cpp
documentation_of: library/graph/shortest_path/BellmanFord.cpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/BellmanFord.cpp
- /library/library/graph/shortest_path/BellmanFord.cpp.html
title: library/graph/shortest_path/BellmanFord.cpp
---
