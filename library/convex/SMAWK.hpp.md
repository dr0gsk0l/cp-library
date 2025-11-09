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
  bundledCode: "#line 2 \"library/convex/SMAWK.hpp\"\n#include <vector>\n\ntemplate\
    \ <class Select>\nstd::vector<int> smawk(int h, int w, const Select &select) {\n\
    \    // r(k,*) : (0-indexed) k\u56DE\u76EE\u306E\u30EB\u30FC\u30D7\u3067\u8003\
    \u3048\u308B\u884C\u96C6\u5408\n    constexpr static auto r = [](int k, int i)\
    \ { return ((i + 1) << k) - 1; };\n\n    // k \u756A\u76EE\u306B\u306F r(k,*)\
    \ \u306E\u7B54\u3048\u3068\u306A\u308B\u5217\u5019\u88DC\u304C\u5165\u308B\n \
    \   std::vector<std::vector<int>> cols(std::bit_width(size_t(h)));\n    cols[0].resize(w);\n\
    \    std::iota(cols[0].begin(), cols[0].end(), 0);\n\n    for (int k = 1; k <\
    \ cols.size(); k++) {\n        const auto &col = cols[k - 1];\n        auto &nxt\
    \ = cols[k];\n        for (int j : col) {\n            while (nxt.size() and select(r(k,\
    \ nxt.size() - 1), nxt.back(), j))\n                nxt.pop_back();\n        \
    \    if (r(k, nxt.size()) < h)\n                nxt.push_back(j);\n        }\n\
    \    }\n\n    std::vector<int> res(h);\n\n    for (int k = cols.size() - 1; k\
    \ >= 0; k--) {\n        const auto &col = cols[k];\n        for (int i = 0, j\
    \ = 0; r(k, i) < h; i += 2) {\n            res[r(k, i)] = col[j];\n          \
    \  int end = (r(k, i + 1) < h ? res[r(k, i + 1)] : col.back());\n            while\
    \ (col[j] != end) {\n                if (select(r(k, i), res[r(k, i)], col[++j]))\n\
    \                    res[r(k, i)] = col[j];\n            }\n        }\n    }\n\
    \n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class Select>\nstd::vector<int>\
    \ smawk(int h, int w, const Select &select) {\n    // r(k,*) : (0-indexed) k\u56DE\
    \u76EE\u306E\u30EB\u30FC\u30D7\u3067\u8003\u3048\u308B\u884C\u96C6\u5408\n   \
    \ constexpr static auto r = [](int k, int i) { return ((i + 1) << k) - 1; };\n\
    \n    // k \u756A\u76EE\u306B\u306F r(k,*) \u306E\u7B54\u3048\u3068\u306A\u308B\
    \u5217\u5019\u88DC\u304C\u5165\u308B\n    std::vector<std::vector<int>> cols(std::bit_width(size_t(h)));\n\
    \    cols[0].resize(w);\n    std::iota(cols[0].begin(), cols[0].end(), 0);\n\n\
    \    for (int k = 1; k < cols.size(); k++) {\n        const auto &col = cols[k\
    \ - 1];\n        auto &nxt = cols[k];\n        for (int j : col) {\n         \
    \   while (nxt.size() and select(r(k, nxt.size() - 1), nxt.back(), j))\n     \
    \           nxt.pop_back();\n            if (r(k, nxt.size()) < h)\n         \
    \       nxt.push_back(j);\n        }\n    }\n\n    std::vector<int> res(h);\n\n\
    \    for (int k = cols.size() - 1; k >= 0; k--) {\n        const auto &col = cols[k];\n\
    \        for (int i = 0, j = 0; r(k, i) < h; i += 2) {\n            res[r(k, i)]\
    \ = col[j];\n            int end = (r(k, i + 1) < h ? res[r(k, i + 1)] : col.back());\n\
    \            while (col[j] != end) {\n                if (select(r(k, i), res[r(k,\
    \ i)], col[++j]))\n                    res[r(k, i)] = col[j];\n            }\n\
    \        }\n    }\n\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convex/SMAWK.hpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/convex/SMAWK.hpp
layout: document
redirect_from:
- /library/library/convex/SMAWK.hpp
- /library/library/convex/SMAWK.hpp.html
title: library/convex/SMAWK.hpp
---
