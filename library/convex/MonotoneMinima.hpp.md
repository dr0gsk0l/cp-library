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
  bundledCode: "#line 2 \"library/convex/MonotoneMinima.hpp\"\n#include <queue>\n\
    #include <tuple>\n#include <vector>\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F &argmin) {\n    // argmin(i,l,r) : argmin_{j\\\
    in[l,r)} A[i][j]\n    std::vector<int> res(n);\n    std::queue<std::tuple<int,\
    \ int, int, int>> que;\n    que.emplace(0, n, 0, m);\n\n    while (que.size())\
    \ {\n        auto [u, d, l, r] = que.front();\n        que.pop();\n\n        if\
    \ (u == d)\n            continue;\n        int m = (u + d) >> 1;\n        res[m]\
    \ = argmin(m, l, r);\n        que.emplace(u, m, l, res[m] + 1);\n        que.emplace(m\
    \ + 1, d, res[m], r);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <tuple>\n#include <vector>\n\ntemplate\
    \ <typename F>\nstd::vector<int> monotone_minima(int n, int m, const F &argmin)\
    \ {\n    // argmin(i,l,r) : argmin_{j\\in[l,r)} A[i][j]\n    std::vector<int>\
    \ res(n);\n    std::queue<std::tuple<int, int, int, int>> que;\n    que.emplace(0,\
    \ n, 0, m);\n\n    while (que.size()) {\n        auto [u, d, l, r] = que.front();\n\
    \        que.pop();\n\n        if (u == d)\n            continue;\n        int\
    \ m = (u + d) >> 1;\n        res[m] = argmin(m, l, r);\n        que.emplace(u,\
    \ m, l, res[m] + 1);\n        que.emplace(m + 1, d, res[m], r);\n    }\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convex/MonotoneMinima.hpp
  requiredBy: []
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/convex/MonotoneMinima.hpp
layout: document
redirect_from:
- /library/library/convex/MonotoneMinima.hpp
- /library/library/convex/MonotoneMinima.hpp.html
title: library/convex/MonotoneMinima.hpp
---
