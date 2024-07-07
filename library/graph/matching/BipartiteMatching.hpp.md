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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/flow/Dinic.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n// \u91CD\u307F\u7121\u3057\n#include \"library/flow/Dinic.cpp\"\
    \nclass BipartiteMatching {\n    int A, B; // \u5DE6\u53F3\u306E\u9802\u70B9\u6570\
    \n    int S, T;\n    Dinic<int> fl;\n\n  public:\n    BipartiteMatching(int A,\
    \ int B)\n        : A(A), B(B), S(A + B), T(A + B + 1), fl(A + B + 2, S, T) {\n\
    \        for (int i = 0; i < A; i++)\n            fl.add_arc(S, i, 1);\n     \
    \   for (int j = 0; j < B; j++)\n            fl.add_arc(A + j, T, 1);\n    }\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u and u < A);\n      \
    \  assert(0 <= v and v < B);\n        fl.add_arc(u, A + v, 1);\n    }\n    std::vector<std::pair<int,\
    \ int>> solve() {\n        int K = fl.flow(std::min(A, B));\n        std::vector<std::pair<int,\
    \ int>> res;\n        res.reserve(K);\n        auto all_edge = fl.all_edge();\n\
    \        for (int i = A + B; i < all_edge.size(); i++) {\n            const auto\
    \ &[from, to, flow] = all_edge[i];\n            if (flow)\n                res.emplace_back(from,\
    \ to - A);\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/matching/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/matching/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/library/graph/matching/BipartiteMatching.hpp
- /library/library/graph/matching/BipartiteMatching.hpp.html
title: library/graph/matching/BipartiteMatching.hpp
---
