---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/SCC.cpp
    title: library/graph/SCC.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/SCC.test.cpp
    title: test/library-checker/Graph/SCC.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/ReverseGraph.cpp\"\ntemplate <typename GRAPH>\
    \ GRAPH reverse_graph(const GRAPH &g) {\n    GRAPH r(g.n);\n    for (auto e :\
    \ g.edges) {\n        std::swap(e.from, e.to);\n        r.add_arc(e);\n    }\n\
    \    r.build();\n    return r;\n}\n"
  code: "#pragma once\ntemplate <typename GRAPH> GRAPH reverse_graph(const GRAPH &g)\
    \ {\n    GRAPH r(g.n);\n    for (auto e : g.edges) {\n        std::swap(e.from,\
    \ e.to);\n        r.add_arc(e);\n    }\n    r.build();\n    return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/ReverseGraph.cpp
  requiredBy:
  - library/graph/SCC.cpp
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/SCC.test.cpp
documentation_of: library/graph/ReverseGraph.cpp
layout: document
redirect_from:
- /library/library/graph/ReverseGraph.cpp
- /library/library/graph/ReverseGraph.cpp.html
title: library/graph/ReverseGraph.cpp
---