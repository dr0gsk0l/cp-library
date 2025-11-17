---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C.test.cpp
    title: test/AOJ/ALDS1_11_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/shortest_path/BFS.hpp\"\ntemplate <typename\
    \ GRAPH>\nstd::pair<std::vector<int>, std::vector<int>> BFS(const GRAPH &g, int\
    \ s = 0) {\n    assert(g.is_prepared());\n    std::vector<int> d(g.n, -1), pre(g.n,\
    \ -1);\n    std::queue<int> que;\n    d[s] = 0;\n    que.push(s);\n    while (que.size())\
    \ {\n        int v = que.front();\n        que.pop();\n        for (int to : g[v])\n\
    \            if (d[to] < 0) {\n                d[to] = d[v] + 1;\n           \
    \     que.push(to);\n            }\n    }\n    return {d, pre};\n}\n"
  code: "#pragma once\ntemplate <typename GRAPH>\nstd::pair<std::vector<int>, std::vector<int>>\
    \ BFS(const GRAPH &g, int s = 0) {\n    assert(g.is_prepared());\n    std::vector<int>\
    \ d(g.n, -1), pre(g.n, -1);\n    std::queue<int> que;\n    d[s] = 0;\n    que.push(s);\n\
    \    while (que.size()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (int to : g[v])\n            if (d[to] < 0) {\n                d[to]\
    \ = d[v] + 1;\n                que.push(to);\n            }\n    }\n    return\
    \ {d, pre};\n}"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/graph/shortest_path/BFS.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_11_C.test.cpp
documentation_of: library/graph/shortest_path/BFS.hpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/BFS.hpp
- /library/library/graph/shortest_path/BFS.hpp.html
title: library/graph/shortest_path/BFS.hpp
---
