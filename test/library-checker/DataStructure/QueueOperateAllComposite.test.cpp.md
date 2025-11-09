---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.hpp
    title: library/algebra/Reverse.hpp
  - icon: ':question:'
    path: library/algebra/group/Affine.hpp
    title: library/algebra/group/Affine.hpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.hpp
    title: library/algebra/monoid/Concepts.hpp
  - icon: ':question:'
    path: library/datastructure/SWAG.hpp
    title: library/datastructure/SWAG.hpp
  - icon: ':question:'
    path: library/linearalgebra/Linear.hpp
    title: library/linearalgebra/Linear.hpp
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
  - icon: ':question:'
    path: library/mod/Modint.hpp
    title: library/mod/Modint.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/datastructure/SWAG.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/std::queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/Reverse.hpp\"\n#include\
    \ \"library/algebra/group/Affine.hpp\"\n#include \"library/datastructure/SWAG.hpp\"\
    \n#include \"library/mod/Modint.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    using mint = Mint<long long>;\n    using G\
    \ = AlgebraReverse<GroupAffine<mint>>;\n    using F = G::value_type;\n\n    SWAG<G>\
    \ S;\n\n    int q;\n    std::cin >> q;\n    while (q--) {\n        int t;\n  \
    \      std::cin >> t;\n        if (t == 0) {\n            F f;\n            std::cin\
    \ >> f;\n            S.push_back(f);\n        }\n        if (t == 1)\n       \
    \     S.pop_front();\n        if (t == 2) {\n            int x;\n            std::cin\
    \ >> x;\n            F f = S.prod();\n            std::cout << f(x) << \"\\n\"\
    ;\n        }\n    }\n}"
  dependsOn:
  - library/algebra/Reverse.hpp
  - library/algebra/group/Affine.hpp
  - library/linearalgebra/Linear.hpp
  - library/datastructure/SWAG.hpp
  - library/algebra/monoid/Concepts.hpp
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
- /verify/test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp.html
title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
---
