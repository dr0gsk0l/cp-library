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
    path: library/linearalgebra/Linear.hpp
    title: library/linearalgebra/Linear.hpp
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
  - icon: ':question:'
    path: library/mod/Modint.hpp
    title: library/mod/Modint.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.hpp
    title: library/segtree/SegmentTree.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/segtree/SegmentTree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/Reverse.hpp\"\n#include\
    \ \"library/algebra/group/Affine.hpp\"\n#include \"library/mod/Modint.hpp\"\n\
    #include \"library/segtree/SegmentTree.hpp\"\n\nusing ll = long long;\nusing mint\
    \ = Mint<ll>;\nusing G_ = GroupAffine<mint>;\nusing G = AlgebraReverse<G_>;\n\
    using F = G::value_type;\n\nint main() {\n    int n, q;\n    std::cin >> n >>\
    \ q;\n    std::vector<F> v(n);\n    for (int i = 0; i < n; i++)\n        std::cin\
    \ >> v[i];\n    SegmentTree<G> seg(v);\n    while (q--) {\n        int t, l, r,\
    \ x;\n        std::cin >> t >> l >> r >> x;\n        if (t) {\n            F f\
    \ = seg.prod(l, r);\n            std::cout << f(x) << \"\\n\";\n        } else\n\
    \            seg.set(l, F(r, x));\n    }\n}"
  dependsOn:
  - library/algebra/Reverse.hpp
  - library/algebra/group/Affine.hpp
  - library/linearalgebra/Linear.hpp
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  - library/segtree/SegmentTree.hpp
  - library/algebra/monoid/Concepts.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2024-07-08 10:24:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp.html
title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
---
