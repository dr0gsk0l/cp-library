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
  bundledCode: "#line 1 \"library/util/ForAllPareto.hpp\"\ntemplate <typename F>\n\
    void for_all_pareto(const std::vector<int> &v, const F &f) {\n    int n = v.size();\n\
    \    std::vector<int> a(n, 0);\n    while (true) {\n        f(a);\n        int\
    \ idx = 0;\n        while (idx < n and a[idx] == v[idx])\n            a[idx++]\
    \ = 0;\n        if (idx == n)\n            break;\n        a[idx]++;\n    }\n\
    }\n"
  code: "template <typename F>\nvoid for_all_pareto(const std::vector<int> &v, const\
    \ F &f) {\n    int n = v.size();\n    std::vector<int> a(n, 0);\n    while (true)\
    \ {\n        f(a);\n        int idx = 0;\n        while (idx < n and a[idx] ==\
    \ v[idx])\n            a[idx++] = 0;\n        if (idx == n)\n            break;\n\
    \        a[idx]++;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/ForAllPareto.hpp
  requiredBy: []
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/ForAllPareto.hpp
layout: document
redirect_from:
- /library/library/util/ForAllPareto.hpp
- /library/library/util/ForAllPareto.hpp.html
title: library/util/ForAllPareto.hpp
---
