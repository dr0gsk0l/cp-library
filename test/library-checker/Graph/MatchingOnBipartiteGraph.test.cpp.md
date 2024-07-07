---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/matching/BipartiteMatching.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"library/graph/matching/BipartiteMatching.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int l, r, m;\n    std::cin >> l >> r >> m;\n\n    BipartiteMatching BM(l,\
    \ r);\n    while (m--) {\n        int a, b;\n        std::cin >> a >> b;\n   \
    \     BM.add_edge(a, b);\n    }\n    auto ans = BM.solve();\n    std::cout <<\
    \ ans.size() << \"\\n\";\n    for (const auto &[u, v] : ans)\n        std::cout\
    \ << u << \" \" << v << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
- /verify/test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp.html
title: test/library-checker/Graph/MatchingOnBipartiteGraph.test.cpp
---
