---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/ShortestPath.test.cpp
    title: test/library-checker/Graph/ShortestPath.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/shortest_path/Dijkstra.cpp\"\ntemplate <typename\
    \ WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<T>, std::vector<int>>\
    \ dijkstra(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n    std::vector<T>\
    \ d(g.n, -1);\n    std::vector<int> pre(g.n, -1);\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
    \ int>>>\n        que;\n    d[s] = 0;\n    que.emplace(0, s);\n    while (que.size())\
    \ {\n        auto [now, id] = que.top();\n        que.pop();\n        if (d[id]\
    \ < now)\n            continue;\n        for (const auto &e : g[id])\n       \
    \     if (d[e.to] == -1 || d[e.to] > now + e.weight) {\n                d[e.to]\
    \ = now + e.weight;\n                pre[e.to] = id;\n                que.emplace(d[e.to],\
    \ e.to);\n            }\n    }\n    return {d, pre};\n}\n"
  code: "template <typename WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> dijkstra(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n\
    \    std::vector<T> d(g.n, -1);\n    std::vector<int> pre(g.n, -1);\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
    \ int>>>\n        que;\n    d[s] = 0;\n    que.emplace(0, s);\n    while (que.size())\
    \ {\n        auto [now, id] = que.top();\n        que.pop();\n        if (d[id]\
    \ < now)\n            continue;\n        for (const auto &e : g[id])\n       \
    \     if (d[e.to] == -1 || d[e.to] > now + e.weight) {\n                d[e.to]\
    \ = now + e.weight;\n                pre[e.to] = id;\n                que.emplace(d[e.to],\
    \ e.to);\n            }\n    }\n    return {d, pre};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/shortest_path/Dijkstra.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/ShortestPath.test.cpp
documentation_of: library/graph/shortest_path/Dijkstra.cpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/Dijkstra.cpp
- /library/library/graph/shortest_path/Dijkstra.cpp.html
title: library/graph/shortest_path/Dijkstra.cpp
---
