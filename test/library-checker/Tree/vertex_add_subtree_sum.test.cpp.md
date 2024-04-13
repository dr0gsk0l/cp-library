---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  - icon: ':heavy_check_mark:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.cpp
    title: library/segtree/SegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/HLD.cpp
    title: library/tree/HLD.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.cpp
    title: library/tree/TreeMonoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/segtree/SegmentTree.cpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/group/Add.cpp\"\n#include\
    \ \"library/tree/Tree.cpp\"\n#include \"library/tree/TreeMonoid.cpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    using\
    \ G = GroupAdd<long long>;\n\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<long\
    \ long> a(n);\n    for (int i = 0; i < n; i++)\n        std::cin >> a[i];\n\n\
    \    Tree t(n);\n    t.scan_root(0);\n\n    TreeMonoid<Tree, G> TM(t, a);\n\n\
    \    while (q--) {\n        int c;\n        std::cin >> c;\n        if (c) {\n\
    \            int u;\n            std::cin >> u;\n            std::cout << TM.subtree_prod(u)\
    \ << \"\\n\";\n        } else {\n            int u, x;\n            std::cin >>\
    \ u >> x;\n            TM.multiply(u, x);\n        }\n    }\n}"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/tree/Tree.cpp
  - library/graph/Graph.cpp
  - library/tree/TreeMonoid.cpp
  - library/algebra/Reverse.cpp
  - library/segtree/SegmentTree.cpp
  - library/algebra/monoid/Concepts.cpp
  - library/tree/HLD.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
- /verify/test/library-checker/Tree/vertex_add_subtree_sum.test.cpp.html
title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
---
