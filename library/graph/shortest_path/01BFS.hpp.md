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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/WeightedGraph.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/graph/WeightedGraph.cpp\"\ntemplate <typename\
    \ WG, typename T = typename WG::weight_type>\nstd::pair<std::vector<T>, std::vector<int>>\
    \ bfs01(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n    std::vector<T>\
    \ d(g.n, -1);\n    std::vector<int> pre(g.n, -1);\n    std::deque<std::pair<T,\
    \ int>> deq;\n    d[s] = 0;\n    deq.emplace_back(0, s);\n    while (deq.size())\
    \ {\n        auto [now, id] = deq.front();\n        deq.pop_front();\n       \
    \ if (d[id] < now)\n            continue;\n        for (const auto &e : g[id])\
    \ {\n            assert(e.weight == 0 || e.weight == 1);\n            if (d[e.to]\
    \ == -1 || d[e.to] > now + e.weight) {\n                d[e.to] = now + e.weight;\n\
    \                pre[e.to] = id;\n                if (e.weight == 0)\n       \
    \             deq.emplace_front(d[e.to], e.to);\n                else\n      \
    \              deq.emplace_back(d[e.to], e.to);\n            }\n        }\n  \
    \  }\n    return {d, pre};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/shortest_path/01BFS.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/shortest_path/01BFS.hpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/01BFS.hpp
- /library/library/graph/shortest_path/01BFS.hpp.html
title: library/graph/shortest_path/01BFS.hpp
---
