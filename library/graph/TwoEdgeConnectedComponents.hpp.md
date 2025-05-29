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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/unionfind/UnionFind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"datastructure/unionfind/UnionFind.hpp\"\n#include \"graph/LowLink.hpp\"\
    \n\nstd::vector<std::vector<int>> two_edge_connected_components(const Graph &g)\
    \ {\n    LowLink low_link(g);\n    UnionFind uf(g.n);\n    for (int i = 0; i <\
    \ g.n; i++)\n        for (int to : g[i]) {\n            if (i > to || low_link.is_bridge(i,\
    \ to))\n                continue;\n            uf.merge(i, to);\n        }\n \
    \   return uf.groups();\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/library/graph/TwoEdgeConnectedComponents.hpp
- /library/library/graph/TwoEdgeConnectedComponents.hpp.html
title: library/graph/TwoEdgeConnectedComponents.hpp
---
