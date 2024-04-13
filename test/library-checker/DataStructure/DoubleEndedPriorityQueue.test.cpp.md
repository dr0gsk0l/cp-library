---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/superstd/Multistd::set.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/double_ended_std::priority_queue\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/superstd/Multistd::set.cpp\"\n\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n    Multistd::set<int> s;\n    s.scan(n);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int x;\n            std::cin >> x;\n            s.insert(x);\n\
    \        }\n        if (t == 1) {\n            int a = s.pick_mn();\n        \
    \    std::cout << a << \"\\n\";\n        }\n        if (t == 2) {\n          \
    \  int a = s.pick_mx();\n            std::cout << a << \"\\n\";\n        }\n \
    \   }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
- /verify/test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp.html
title: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
---
