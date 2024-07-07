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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/matching/WeightedBipartiteMatching.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n#include\
    \ \"library/graph/matching/WeightedBipartiteMatching.cpp\"\nusing ll = long long;\n\
    constexpr ll INF = ll(1e9) + 1;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    WeightedBipartiteMatching<ll>\
    \ B(n, n);\n    REP (i, n)\n        REP (j, n) {\n            int a;\n       \
    \     std::cin >> a;\n            B.add_edge(i, j, INF - a);\n        }\n    auto\
    \ [sum, vec] = B.solve();\n\n    sum -= n * INF;\n    sum = -sum;\n\n    std::vector<int>\
    \ res(n);\n    for (const auto &[from, to, weight] : vec)\n        res[from] =\
    \ to;\n\n    std::cout << sum << \"\\n\";\n    REP (i, n)\n        std::cout <<\
    \ res[i] << \"\\n \"[i + 1 < n];\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Graph/AssignmentProblem.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/AssignmentProblem.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/AssignmentProblem.test.cpp
- /verify/test/library-checker/Graph/AssignmentProblem.test.cpp.html
title: test/library-checker/Graph/AssignmentProblem.test.cpp
---
