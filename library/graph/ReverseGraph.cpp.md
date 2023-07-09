---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/graph/SCC.cpp
    title: library/graph/SCC.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Graph/SCC.test.cpp
    title: test/library-checker/Graph/SCC.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/ReverseGraph.cpp\"\ntemplate<typename GRAPH>\n\
    GRAPH reverse_graph(const GRAPH&g){\n  GRAPH r(g.n);\n  for(auto e:g.edges){\n\
    \    swap(e.from,e.to);\n    r.add_arc(e);\n  }\n  r.build();\n  return r;\n}\n"
  code: "#pragma once\ntemplate<typename GRAPH>\nGRAPH reverse_graph(const GRAPH&g){\n\
    \  GRAPH r(g.n);\n  for(auto e:g.edges){\n    swap(e.from,e.to);\n    r.add_arc(e);\n\
    \  }\n  r.build();\n  return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/ReverseGraph.cpp
  requiredBy:
  - library/graph/SCC.cpp
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Graph/SCC.test.cpp
documentation_of: library/graph/ReverseGraph.cpp
layout: document
redirect_from:
- /library/library/graph/ReverseGraph.cpp
- /library/library/graph/ReverseGraph.cpp.html
title: library/graph/ReverseGraph.cpp
---
