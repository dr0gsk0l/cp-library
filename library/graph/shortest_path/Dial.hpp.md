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
    \ dial(const WG &g, int s = 0) {\n    assert(g.is_prepared());\n    std::vector<T>\
    \ d(g.n, -1);\n    std::vector<int> pre(g.n, -1);\n    std::vector<bool> used(g.n,\
    \ false);\n\n    T K = 0, rem = 0;\n    for (const auto &e : g.edges)\n      \
    \  K = std::max(K, e.weight);\n    std::vector<std::queue<int>> que(K + 1);\n\
    \    auto cmp = [&](T a, T b) {\n        if (a == rem || b == rem)\n         \
    \   return b == rem;\n        if ((a < rem) ^ (b < rem))\n            return a\
    \ < rem;\n        return a > b;\n    };\n    std::priority_queue<T, std::vector<T>,\
    \ decltype(cmp)> nxt{cmp};\n\n    d[s] = 0;\n    que[0].push(0);\n    nxt.push(0);\n\
    \n    while (nxt.size()) {\n        rem = nxt.top();\n        nxt.pop();\n   \
    \     auto &Q = que[rem];\n        while (Q.size()) {\n            int v = Q.front();\n\
    \            Q.pop();\n            if (used[v])\n                continue;\n \
    \           used[v] = true;\n            for (const auto &e : g[v]) {\n      \
    \          if (d[e.to] == -1 || d[e.to] > d[v] + e.weight) {\n               \
    \     d[e.to] = d[v] + e.weight;\n                    pre[e.to] = v;\n       \
    \             T x = rem + e.weight;\n                    if (x >= K + 1)\n   \
    \                     x -= K + 1;\n                    if (!que[x].size())\n \
    \                       nxt.push(x);\n                    que[x].push(e.to);\n\
    \                }\n            }\n        }\n    }\n    return {d, pre};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/shortest_path/Dial.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/shortest_path/Dial.hpp
layout: document
redirect_from:
- /library/library/graph/shortest_path/Dial.hpp
- /library/library/graph/shortest_path/Dial.hpp.html
title: library/graph/shortest_path/Dial.hpp
---
