---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.hpp
    title: library/algebra/Reverse.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.hpp
    title: library/algebra/group/Add.hpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.hpp
    title: library/algebra/monoid/Concepts.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.hpp
    title: library/graph/Graph.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.hpp
    title: library/segtree/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/HLD.hpp
    title: library/tree/HLD.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.hpp
    title: library/tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.hpp
    title: library/tree/TreeMonoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/segtree/SegmentTree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include <bits/stdc++.h>\n\n#include \"library/algebra/group/Add.hpp\"\n#include\
    \ \"library/tree/Tree.hpp\"\n#include \"library/tree/TreeMonoid.hpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    using\
    \ G = GroupAdd<long long>;\n\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (int i = 0; i < n; i++)\n        std::cin >> a[i];\n\n\
    \    Tree t(n);\n    t.scan(0);\n\n    TreeMonoid<Tree, G> TM(t, a);\n\n    while\
    \ (q--) {\n        int c;\n        std::cin >> c;\n        if (c) {\n        \
    \    int u, v;\n            std::cin >> u >> v;\n            std::cout << TM.path_prod(u,\
    \ v) << \"\\n\";\n        } else {\n            int p, x;\n            std::cin\
    \ >> p >> x;\n            TM.multiply(p, x);\n        }\n    }\n}"
  dependsOn:
  - library/algebra/group/Add.hpp
  - library/tree/Tree.hpp
  - library/graph/Graph.hpp
  - library/tree/TreeMonoid.hpp
  - library/algebra/Reverse.hpp
  - library/segtree/SegmentTree.hpp
  - library/algebra/monoid/Concepts.hpp
  - library/tree/HLD.hpp
  isVerificationFile: true
  path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Tree/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/vertex_add_path_sum.test.cpp
- /verify/test/library-checker/Tree/vertex_add_path_sum.test.cpp.html
title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
---
