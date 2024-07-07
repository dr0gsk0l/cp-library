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
  bundledCode: "#line 1 \"library/graph/shortest_path/WarshallFloyd.hpp\"\ntemplate\
    \ <typename WG, typename T = typename WG::weight_type>\nstd::vector<std::vector<T>>\
    \ warshall_floyd(const WG &g) {\n    int n = g.n;\n    static constexpr T INF\
    \ = std::numeric_limits<T>::max() / 2;\n    std::vector d(n, std::vector<T>(n,\
    \ INF));\n    for (int i = 0; i < n; i++)\n        d[i][i] = 0;\n    for (const\
    \ auto &e : g.edges)\n        if (d[e.from][e.to] > e.weight)\n            d[e.from][e.to]\
    \ = e.weight;\n    for (int k = 0; k < n; k++)\n        for (int i = 0; i < n;\
    \ i++)\n            if (d[i][k] < INF)\n                for (int j = 0; j < n;\
    \ j++)\n                    if (d[k][j] < INF)\n                        if (d[i][j]\
    \ > d[i][k] + d[k][j])\n                            d[i][j] = d[i][k] + d[k][j];\n\
    \    return d;\n}\n"
  code: "template <typename WG, typename T = typename WG::weight_type>\nstd::vector<std::vector<T>>\
    \ warshall_floyd(const WG &g) {\n    int n = g.n;\n    static constexpr T INF\
    \ = std::numeric_limits<T>::max() / 2;\n    std::vector d(n, std::vector<T>(n,\
    \ INF));\n    for (int i = 0; i < n; i++)\n        d[i][i] = 0;\n    for (const\
    \ auto &e : g.edges)\n        if (d[e.from][e.to] > e.weight)\n            d[e.from][e.to]\
    \ = e.weight;\n    for (int k = 0; k < n; k++)\n        for (int i = 0; i < n;\
    \ i++)\n            if (d[i][k] < INF)\n                for (int j = 0; j < n;\
    \ j++)\n                    if (d[k][j] < INF)\n                        if (d[i][j]\
    \ > d[i][k] + d[k][j])\n                            d[i][j] = d[i][k] + d[k][j];\n\
    \    return d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/shortest_path/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/shortest_path/WarshallFloyd.hpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/WarshallFloyd.hpp
- /library/library/graph/shortest_path/WarshallFloyd.hpp.html
title: library/graph/shortest_path/WarshallFloyd.hpp
---
