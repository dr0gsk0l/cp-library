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
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/ReverseGraph.hpp
layout: document
redirect_from:
- /library/library/graph/ReverseGraph.hpp
- /library/library/graph/ReverseGraph.hpp.html
title: library/graph/ReverseGraph.hpp
---
