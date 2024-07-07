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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/tree/HLD.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"library/tree/HLD.cpp\"\n#include \"library/tree/Tree.cpp\"\
    \n#include \"library/tree/WeightedTree.cpp\"\n#include \"library/util/Compress.cpp\"\
    \n\ntemplate <typename TREE>\nstd::pair<WeightedTree<int>, std::vector<int>>\n\
    auxiliary_tree(const HLD<TREE> &hld, std::vector<int> vs) {\n    assert(hld.prepared);\n\
    \    std::ranges::sort(vs, [&](int u, int v) { return hld.id[u] < hld.id[v]; });\n\
    \n    std::vector<std::pair<int, int>> edges;\n    std::stack<int> sta;\n    sta.push(vs[0]);\n\
    \n    for (int i = 0; i + 1 < vs.size(); i++) {\n        int w = hld.lca(vs[i],\
    \ vs[i + 1]);\n        if (w != vs[i]) {\n            int l = sta.top();\n   \
    \         sta.pop();\n            while (sta.size() and hld.T.depth[w] < hld.T.depth[sta.top()])\
    \ {\n                edges.emplace_back(sta.top(), l);\n                l = sta.top();\n\
    \                sta.pop();\n            }\n            if (sta.empty() or sta.top()\
    \ != w)\n                sta.push(w);\n            edges.emplace_back(w, l);\n\
    \        }\n        sta.push(vs[i + 1]);\n    }\n    while (sta.size() > 1) {\n\
    \        int c = sta.top();\n        sta.pop();\n        edges.emplace_back(c,\
    \ sta.top());\n    }\n\n    Compress<int> C;\n    for (const auto &[u, v] : edges)\n\
    \        C.add(u), C.add(v);\n\n    C.build();\n\n    WeightedTree<int> t(C.size());\n\
    \    for (const auto &[u, v] : edges)\n        t.add_edge(C[u], C[v], abs(hld.T.depth[u]\
    \ - hld.T.depth[v]));\n    t.build();\n\n    std::vector<int> pre_vertex(C.size());\n\
    \    for (int i = 0; i < C.size(); i++)\n        pre_vertex[i] = C.r(i);\n   \
    \ return std::make_pair(t, pre_vertex);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/AuxiliaryTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/AuxiliaryTree.hpp
layout: document
redirect_from:
- /library/library/tree/AuxiliaryTree.hpp
- /library/library/tree/AuxiliaryTree.hpp.html
title: library/tree/AuxiliaryTree.hpp
---
