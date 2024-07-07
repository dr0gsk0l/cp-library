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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/superstd/Set.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include <bits/stdc++.h>\n\n#include \"library/superstd/Set.cpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int n, q;\n    std::cin >> n >> q;\n    Set<int> se;\n    se.banpei();\n\n \
    \   for (int i = 0; i < n; i++) {\n        char c;\n        std::cin >> c;\n \
    \       if (c == '1')\n            se.insert(i);\n    }\n\n    while (q--) {\n\
    \        int c, k;\n        std::cin >> c >> k;\n        if (c == 0)\n       \
    \     se.insert(k);\n        if (c == 1)\n            se.erase(k);\n        if\
    \ (c == 2)\n            std::cout << se.count(k) << \"\\n\";\n        if (c ==\
    \ 3) {\n            int x = se.geq(k);\n            std::cout << (x < n ? x :\
    \ -1) << \"\\n\";\n        }\n        if (c == 4) {\n            int x = se.leq(k);\n\
    \            std::cout << (x >= 0 ? x : -1) << \"\\n\";\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/DataStructure/PredecessorProblem.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PredecessorProblem.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PredecessorProblem.test.cpp
- /verify/test/library-checker/DataStructure/PredecessorProblem.test.cpp.html
title: test/library-checker/DataStructure/PredecessorProblem.test.cpp
---
