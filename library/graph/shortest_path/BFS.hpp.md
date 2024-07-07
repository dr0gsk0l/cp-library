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
  dependsOn: []
  isVerificationFile: false
  path: library/graph/shortest_path/BFS.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/shortest_path/BFS.hpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/BFS.hpp
- /library/library/graph/shortest_path/BFS.hpp.html
title: library/graph/shortest_path/BFS.hpp
---
