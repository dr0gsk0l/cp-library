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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/datastructure/unionfind/UnionFind.cpp:\
    \ line -1: no such header\n"
  code: "#include \"library/datastructure/unionfind/UnionFind.cpp\"\ntemplate <typename\
    \ WG, typename W = typename WG::weight_type>\nstd::pair<W, std::vector<int>> minimum_spanning_tree(const\
    \ WG &g) {\n    assert(g.is_prepared());\n    int n = g.n, m = g.edges.size();\n\
    \    UnionFind uf(n);\n    std::vector<int> id(m);\n    std::iota(id.begin(),\
    \ id.end(), 0);\n    std::ranges::sort(id, [&](const int i, const int j) {\n \
    \       return g.edges[i].weight < g.edges[j].weight;\n    });\n    W res = 0;\n\
    \    std::vector<int> tree;\n    tree.reserve(n - 1);\n    for (int i : id) {\n\
    \        const auto &[from, to, weight] = g.edges[i];\n        if (uf.same(from,\
    \ to))\n            continue;\n        tree.push_back(i);\n        uf.merge(from,\
    \ to);\n        res += weight;\n    }\n    assert(uf.count() == 1);\n    return\
    \ {res, tree};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/MinimumSpanningTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/MinimumSpanningTree.hpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningTree.hpp
- /library/library/graph/MinimumSpanningTree.hpp.html
title: library/graph/MinimumSpanningTree.hpp
---
