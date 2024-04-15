---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.cpp
    title: library/segtree/SegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
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
    \ library/segtree/SegmentTree.cpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\n\n#include \"library/algebra/group/Add.cpp\"\n#include\
    \ \"library/segtree/SegmentTree.cpp\"\n\nusing ll = long long;\nusing G = GroupAdd<ll>;\n\
    \nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<ll> v(n);\n\
    \    for (int i = 0; i < n; i++)\n        std::cin >> v[i];\n    SegmentTree<G>\
    \ seg(v);\n    while (q--) {\n        int t, l, r;\n        std::cin >> t >> l\
    \ >> r;\n        if (t)\n            std::cout << seg.prod(l, r) << \"\\n\";\n\
    \        else\n            seg.multiply(l, r);\n    }\n}"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/segtree/SegmentTree.cpp
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 12:10:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointAddRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/PointAddRangeSum.test.cpp.html
title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
---
