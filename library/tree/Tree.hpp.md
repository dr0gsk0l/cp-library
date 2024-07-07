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
  code: "#pragma once\n#include \"library/graph/Graph.cpp\"\nstruct Tree : Graph {\n\
    \    using Graph::Graph;\n    Tree() = default;\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            std::cin >> p;\n     \
    \       add_edge(p - indexed, i);\n        }\n        build();\n    }\n    void\
    \ scan(int indexed = 1) {\n        Graph::scan(n - 1, false, indexed);\n     \
    \   build();\n    }\n\n    edge_type &parent(int v) {\n        assert(~root and\
    \ root != v);\n        return (*this)[v][0];\n    }\n    const edge_type &parent(int\
    \ v) const {\n        assert(~root and root != v);\n        return (*this)[v][0];\n\
    \    }\n\n    OutgoingEdges son(int v) {\n        assert(~root);\n        if (v\
    \ == root)\n            return {this, in_deg[v], in_deg[v + 1]};\n        return\
    \ {this, in_deg[v] + 1, in_deg[v + 1]};\n    }\n\n  private:\n    void dfs(int\
    \ v, int pre = -1) {\n        for (auto &e : (*this)[v]) {\n            if (e.to\
    \ == pre)\n                std::swap((*this)[v][0], e);\n            else {\n\
    \                depth[e.to] = depth[v] + 1;\n                dfs(e.to, v);\n\
    \            }\n        }\n        DFS.push_back(v);\n    }\n\n  public:\n   \
    \ void build(int r = 0) {\n        if (!is_prepared())\n            Graph::build();\n\
    \        if (~root) {\n            assert(r == root);\n            return;\n \
    \       }\n        root = r;\n        depth = std::vector<int>(n, 0);\n      \
    \  DFS.reserve(n);\n        BFS.reserve(n);\n        dfs(root);\n        std::queue<int>\
    \ que;\n        que.push(root);\n        while (que.size()) {\n            int\
    \ p = que.front();\n            que.pop();\n            BFS.push_back(p);\n  \
    \          for (const auto &e : son(p))\n                que.push(e.to);\n   \
    \     }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/Tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/Tree.hpp
layout: document
redirect_from:
- /library/library/tree/Tree.hpp
- /library/library/tree/Tree.hpp.html
title: library/tree/Tree.hpp
---
