---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/NegativeCycleFind.hpp\"\n// \u30B0\u30E9\u30D5\
    \u5185\u306B\u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u304B\ntemplate<typename\
    \ WG>\nbool negative_cycle_find(const WG&g){\n  using W=typename WG::weight_type;\n\
    \  int n=g.n;\n  std::vector<W> d(n,0);\n  while(n--){\n    bool update=false;\n\
    \    for(const auto&e:g.edges)\n      if(d[e.to]>d[e.from]+e.weight){\n      \
    \  d[e.to]=d[e.from]+e.weight;\n        update=true;\n      }\n    if(!update)return\
    \ false;\n  }\n  return true;\n}\n"
  code: "// \u30B0\u30E9\u30D5\u5185\u306B\u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\
    \u308B\u304B\ntemplate<typename WG>\nbool negative_cycle_find(const WG&g){\n \
    \ using W=typename WG::weight_type;\n  int n=g.n;\n  std::vector<W> d(n,0);\n\
    \  while(n--){\n    bool update=false;\n    for(const auto&e:g.edges)\n      if(d[e.to]>d[e.from]+e.weight){\n\
    \        d[e.to]=d[e.from]+e.weight;\n        update=true;\n      }\n    if(!update)return\
    \ false;\n  }\n  return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/NegativeCycleFind.hpp
  requiredBy: []
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_1_C.test.cpp
documentation_of: library/graph/NegativeCycleFind.hpp
layout: document
redirect_from:
- /library/library/graph/NegativeCycleFind.hpp
- /library/library/graph/NegativeCycleFind.hpp.html
title: library/graph/NegativeCycleFind.hpp
---
