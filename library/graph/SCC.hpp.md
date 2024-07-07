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
  code: "#pragma once\n#include \"library/graph/Graph.cpp\"\n#include \"library/graph/ReverseGraph.cpp\"\
    \n#define REP_(i, n) for (int i = 0; i < (n); i++)\ntemplate <typename DirectedGraph>\
    \ class SCC {\n    int n;\n    DirectedGraph G, R;\n    std::vector<int> visit,\
    \ belong;\n    std::vector<uint8_t> used;\n    void dfs(int v) {\n        used[v]\
    \ = true;\n        for (int to : G[v])\n            if (!used[to])\n         \
    \       dfs(to);\n        visit.push_back(v);\n    }\n    void rdfs(int v, int\
    \ k) {\n        used[v] = true;\n        belong[v] = k;\n        for (int to :\
    \ R[v])\n            if (!used[to])\n                rdfs(to, k);\n    }\n\n \
    \ public:\n    Graph DAG;\n    std::vector<std::vector<int>> component;\n    SCC(const\
    \ DirectedGraph &G) : n(G.n), G(G), belong(n), used(n, false) {\n        assert(G.is_prepared());\n\
    \        visit.reserve(n);\n        R = reverse_graph(G);\n        REP_(v, n)\
    \ if (!used[v]) dfs(v);\n        std::ranges::fill(used, false);\n        std::ranges::reverse(visit);\n\
    \        int k = 0;\n        for (const int &v : visit)\n            if (!used[v])\n\
    \                rdfs(v, k++);\n        std::vector<std::vector<int>> edges(k);\n\
    \        component.resize(k);\n        REP_(v, n) {\n            component[belong[v]].push_back(v);\n\
    \            for (int to : G[v])\n                if (belong[v] != belong[to])\n\
    \                    edges[belong[v]].push_back(belong[to]);\n        }\n    \
    \    DAG = Graph(k);\n        REP_(from, k) {\n            std::ranges::sort(edges[from]);\n\
    \            REP_(i, edges[from].size())\n            if (!i || edges[from][i]\
    \ != edges[from][i - 1])\n                DAG.add_arc(from, edges[from][i]);\n\
    \        }\n    }\n    int operator[](int k) { return belong[k]; }\n};\n#undef\
    \ REP_"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/SCC.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/SCC.hpp
layout: document
redirect_from:
- /library/library/graph/SCC.hpp
- /library/library/graph/SCC.hpp.html
title: library/graph/SCC.hpp
---
