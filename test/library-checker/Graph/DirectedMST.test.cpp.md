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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/MinimumSpanningArborescence.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n#define\
    \ IGNORE\n#include <bits/stdc++.h>\n\n#include \"library/graph/MinimumSpanningArborescence.cpp\"\
    \n#include \"library/graph/WeightedGraph.cpp\"\nusing ll = long long;\n\nint main()\
    \ {\n    int n, m, s;\n    std::cin >> n >> m >> s;\n    WeightedGraph<ll> g(n,\
    \ m, true, 0);\n    auto ans = minimum_spanning_arborescence(g, s);\n    assert(ans.has_value());\n\
    \    auto [val, tree] = ans.value();\n    std::vector<int> p(n);\n    p[s] = s;\n\
    \    ll sum = 0;\n    for (int id : tree) {\n        const auto &e = g.edges[id];\n\
    \        sum += e.weight;\n        p[e.to] = e.from;\n    }\n    val = sum; //\
    \ assert(sum==val);\n    std::cout << val << \"\\n\";\n    for (int v = 0; v <\
    \ n; v++)\n        std::cout << p[v] << \"\\n \"[v + 1 < n];\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Graph/DirectedMST.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/DirectedMST.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/DirectedMST.test.cpp
- /verify/test/library-checker/Graph/DirectedMST.test.cpp.html
title: test/library-checker/Graph/DirectedMST.test.cpp
---
