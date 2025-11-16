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
  bundledCode: "#line 1 \"library/query/OfflineRangeQuery.hpp\"\n#include <vector>\n\
    \nclass OfflineRangeQuery {\n    size_t n, cnt;\n\n    void add_query(size_t b_l,\
    \ size_t b_r, size_t l, size_t r) {\n        if (b_r < l || r < b_l)\n       \
    \     return;\n        if (l <= b_l and b_r <= r) {\n            querys[b_r].first.push_back(cnt);\n\
    \            querys[b_l].second.push_back(cnt);\n            return;\n       \
    \ }\n        add_query(b_l, (b_l + b_r) >> 1, l, r);\n        add_query((b_l +\
    \ b_r) >> 1, b_r, l, r);\n    }\n\n  public:\n    std::vector<std::pair<std::vector<size_t>,\
    \ std::vector<size_t>>> querys;\n\n    OfflineRangeQuery(size_t n_) : n(1), cnt(0),\
    \ querys(n + 1) {\n        while (n < n_)\n            n <<= 1;\n    }\n\n   \
    \ size_t add_query(size_t l, size_t r) {\n        add_query(0, n, l, r);\n   \
    \     return cnt++;\n    }\n};\n"
  code: "#include <vector>\n\nclass OfflineRangeQuery {\n    size_t n, cnt;\n\n  \
    \  void add_query(size_t b_l, size_t b_r, size_t l, size_t r) {\n        if (b_r\
    \ < l || r < b_l)\n            return;\n        if (l <= b_l and b_r <= r) {\n\
    \            querys[b_r].first.push_back(cnt);\n            querys[b_l].second.push_back(cnt);\n\
    \            return;\n        }\n        add_query(b_l, (b_l + b_r) >> 1, l, r);\n\
    \        add_query((b_l + b_r) >> 1, b_r, l, r);\n    }\n\n  public:\n    std::vector<std::pair<std::vector<size_t>,\
    \ std::vector<size_t>>> querys;\n\n    OfflineRangeQuery(size_t n_) : n(1), cnt(0),\
    \ querys(n + 1) {\n        while (n < n_)\n            n <<= 1;\n    }\n\n   \
    \ size_t add_query(size_t l, size_t r) {\n        add_query(0, n, l, r);\n   \
    \     return cnt++;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/query/OfflineRangeQuery.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/query/OfflineRangeQuery.hpp
layout: document
redirect_from:
- /library/library/query/OfflineRangeQuery.hpp
- /library/library/query/OfflineRangeQuery.hpp.html
title: library/query/OfflineRangeQuery.hpp
---
