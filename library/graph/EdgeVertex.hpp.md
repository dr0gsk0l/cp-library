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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/Graph.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/graph/Graph.cpp\"\nclass EdgeVertex {\n\
    \    int n, N;\n    std::vector<std::tuple<int, int, int>> edges;\n    std::vector<std::tuple<int,\
    \ int, int>> arcs;\n\n  public:\n    EdgeVertex(int n) : n(n), N(n) {}\n\n   \
    \ int add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        edges.emplace_back(u, v, N);\n        return N++;\n\
    \    }\n    int add_arc(int u, int v) {\n        assert(0 <= u and u < n);\n \
    \       assert(0 <= v and v < n);\n        arcs.emplace_back(u, v, N);\n     \
    \   return N++;\n    }\n\n    Graph build() {\n        Graph G(N);\n        for\
    \ (const auto &[u, v, e] : edges) {\n            G.add_edge(u, e);\n         \
    \   G.add_edge(e, v);\n        }\n        for (const auto &[u, v, e] : arcs) {\n\
    \            G.add_arc(u, e);\n            G.add_arc(e, v);\n        }\n     \
    \   G.build();\n        return G;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/EdgeVertex.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/EdgeVertex.hpp
layout: document
redirect_from:
- /library/library/graph/EdgeVertex.hpp
- /library/library/graph/EdgeVertex.hpp.html
title: library/graph/EdgeVertex.hpp
---
