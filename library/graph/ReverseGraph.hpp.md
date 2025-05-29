---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/SCC.hpp
    title: library/graph/SCC.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Graph/SCC.test.cpp
    title: test/library-checker/Graph/SCC.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/ReverseGraph.hpp\"\ntemplate <typename GRAPH>\
    \ GRAPH reverse_graph(const GRAPH &g) {\n    GRAPH r(g.n);\n    for (auto e :\
    \ g.edges) {\n        std::swap(e.from, e.to);\n        r.add_arc(e);\n    }\n\
    \    r.build();\n    return r;\n}\n"
  code: "#pragma once\ntemplate <typename GRAPH> GRAPH reverse_graph(const GRAPH &g)\
    \ {\n    GRAPH r(g.n);\n    for (auto e : g.edges) {\n        std::swap(e.from,\
    \ e.to);\n        r.add_arc(e);\n    }\n    r.build();\n    return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/ReverseGraph.hpp
  requiredBy:
  - library/graph/SCC.hpp
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Graph/SCC.test.cpp
documentation_of: library/graph/ReverseGraph.hpp
layout: document
redirect_from:
- /library/library/graph/ReverseGraph.hpp
- /library/library/graph/ReverseGraph.hpp.html
title: library/graph/ReverseGraph.hpp
---
