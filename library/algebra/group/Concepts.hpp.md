---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.hpp
    title: library/algebra/monoid/Concepts.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/datastructure/CumulativeGroup.hpp
    title: library/datastructure/CumulativeGroup.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FenwickTree.hpp
    title: library/datastructure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.hpp
    title: library/datastructure/GroupWaveletMatrix.hpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.hpp
    title: library/math/FactorialNumberSystem.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.hpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#include \"library/algebra/monoid/Concepts.hpp\"\n\n#pragma once\n\ntemplate\
    \ <class G>\nconcept group = monoid<G> and requires(typename G::value_type x)\
    \ {\n    { G::inverse(x) } -> std::same_as<typename G::value_type>;\n};\n\n//\
    \ todo : able_group"
  dependsOn:
  - library/algebra/monoid/Concepts.hpp
  isVerificationFile: false
  path: library/algebra/group/Concepts.hpp
  requiredBy:
  - library/math/FactorialNumberSystem.hpp
  - library/datastructure/FenwickTree.hpp
  - library/datastructure/CumulativeGroup.hpp
  - library/datastructure/GroupWaveletMatrix.hpp
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/yukicoder/924.test.cpp
documentation_of: library/algebra/group/Concepts.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Concepts.hpp
- /library/library/algebra/group/Concepts.hpp.html
title: library/algebra/group/Concepts.hpp
---
