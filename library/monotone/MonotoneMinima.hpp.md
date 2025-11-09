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
  bundledCode: "#line 1 \"library/monotone/MonotoneMinima.hpp\"\ntemplate <typename\
    \ F>\nstd::vector<int> internal_monotone_minima(int u, int d, int l, int r,\n\
    \                                          const F &argmin) {\n    if (u == d)\n\
    \        return {};\n    std::vector<int> ret(d - u);\n    int m = (u + d) >>\
    \ 1;\n    ret[m - u] = argmin(m, l, r);\n    auto v1 = internal_monotone_minima(u,\
    \ m, l, ret[m - u] + 1, argmin);\n    std::ranges::copy(v1, ret.begin());\n  \
    \  auto v2 = internal_monotone_minima(m + 1, d, ret[m - u], r, argmin);\n    std::ranges::copy(v2,\
    \ ret.begin() + m - u + 1);\n    return ret;\n}\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F &argmin) {\n    return internal_monotone_minima(0,\
    \ n, 0, m, argmin);\n}\n"
  code: "template <typename F>\nstd::vector<int> internal_monotone_minima(int u, int\
    \ d, int l, int r,\n                                          const F &argmin)\
    \ {\n    if (u == d)\n        return {};\n    std::vector<int> ret(d - u);\n \
    \   int m = (u + d) >> 1;\n    ret[m - u] = argmin(m, l, r);\n    auto v1 = internal_monotone_minima(u,\
    \ m, l, ret[m - u] + 1, argmin);\n    std::ranges::copy(v1, ret.begin());\n  \
    \  auto v2 = internal_monotone_minima(m + 1, d, ret[m - u], r, argmin);\n    std::ranges::copy(v2,\
    \ ret.begin() + m - u + 1);\n    return ret;\n}\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F &argmin) {\n    return internal_monotone_minima(0,\
    \ n, 0, m, argmin);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/monotone/MonotoneMinima.hpp
  requiredBy: []
  timestamp: '2025-11-09 23:27:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/monotone/MonotoneMinima.hpp
layout: document
redirect_from:
- /library/library/monotone/MonotoneMinima.hpp
- /library/library/monotone/MonotoneMinima.hpp.html
title: library/monotone/MonotoneMinima.hpp
---
