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
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/Reverse.cpp\"\n#include\
    \ \"library/algebra/group/Affine.cpp\"\n#include \"library/mod/Modint.cpp\"\n\
    #include \"library/segtree/SegmentTree.cpp\"\n\nusing ll = long long;\nusing mint\
    \ = Mint<ll>;\nusing G_ = GroupAffine<mint>;\nusing G = AlgebraReverse<G_>;\n\
    using F = G::value_type;\n\nint main() {\n    int n, q;\n    std::cin >> n >>\
    \ q;\n    std::vector<F> v(n);\n    for (int i = 0; i < n; i++)\n        std::cin\
    \ >> v[i];\n    SegmentTree<G> seg(v);\n    while (q--) {\n        int t, l, r,\
    \ x;\n        std::cin >> t >> l >> r >> x;\n        if (t) {\n            F f\
    \ = seg.prod(l, r);\n            std::cout << f(x) << \"\\n\";\n        } else\n\
    \            seg.set(l, F(r, x));\n    }\n}"
  dependsOn:
  - library/algebra/Reverse.cpp
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/Linear.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  - library/segtree/SegmentTree.cpp
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2024-04-14 21:36:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp.html
title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
---
