---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  - icon: ':question:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  - icon: ':question:'
    path: library/datastructure/SWAG.cpp
    title: library/datastructure/SWAG.cpp
  - icon: ':question:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/std::queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/std::queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/datastructure/SWAG.cpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/std::queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/Reverse.cpp\"\n#include\
    \ \"library/algebra/group/Affine.cpp\"\n#include \"library/datastructure/SWAG.cpp\"\
    \n#include \"library/mod/Modint.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    using mint = Mint<long long>;\n    using G\
    \ = AlgebraReverse<GroupAffine<mint>>;\n    using F = G::value_type;\n\n    SWAG<G>\
    \ S;\n\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int t;\n  \
    \      std::cin >> t;\n        if (t == 0) {\n            F f;\n            std::cin\
    \ >> f;\n            S.push_back(f);\n        }\n        if (t == 1)\n       \
    \     S.pop_front();\n        if (t == 2) {\n            int x;\n            std::cin\
    \ >> x;\n            F f = S.prod();\n            std::cout << f(x) << \"\\n\"\
    ;\n        }\n    }\n}"
  dependsOn:
  - library/algebra/Reverse.cpp
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/Linear.cpp
  - library/datastructure/SWAG.cpp
  - library/algebra/monoid/Concepts.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
- /verify/test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp.html
title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
---
