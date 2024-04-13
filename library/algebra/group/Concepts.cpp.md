---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/datastructure/CumulativeGroup.cpp
    title: library/datastructure/CumulativeGroup.cpp
  - icon: ':question:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  - icon: ':x:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.cpp
    title: library/math/FactorialNumberSystem.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.cpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#include \"library/algebra/monoid/Concepts.cpp\"\n\n#pragma once\n\ntemplate\
    \ <class G>\nconcept group = monoid<G> and requires(typename G::value_type x)\
    \ {\n    { G::inverse(x) } -> std::same_as<typename G::value_type>;\n};\n\n//\
    \ todo : able_group"
  dependsOn:
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: false
  path: library/algebra/group/Concepts.cpp
  requiredBy:
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/datastructure/FenwickTree.cpp
  - library/datastructure/CumulativeGroup.cpp
  - library/math/FactorialNumberSystem.cpp
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/yukicoder/924.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
documentation_of: library/algebra/group/Concepts.cpp
layout: document
redirect_from:
- /library/library/algebra/group/Concepts.cpp
- /library/library/algebra/group/Concepts.cpp.html
title: library/algebra/group/Concepts.cpp
---
