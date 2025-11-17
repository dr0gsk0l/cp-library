---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Concepts.hpp
    title: library/algebra/group/Concepts.hpp
  - icon: ':warning:'
    path: library/datastructure/CumulativeGroup.hpp
    title: library/datastructure/CumulativeGroup.hpp
  - icon: ':warning:'
    path: library/datastructure/CumulativeMonoid.hpp
    title: library/datastructure/CumulativeMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FenwickTree.hpp
    title: library/datastructure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.hpp
    title: library/datastructure/GroupWaveletMatrix.hpp
  - icon: ':question:'
    path: library/datastructure/SWAG.hpp
    title: library/datastructure/SWAG.hpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.hpp
    title: library/math/FactorialNumberSystem.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.hpp
    title: library/segtree/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.hpp
    title: library/tree/TreeMonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/monoid/Concepts.hpp\"\n\ntemplate <class\
    \ M>\nconcept monoid = requires(typename M::value_type x) {\n    { M::op(x, x)\
    \ } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x, x) };\n    { M::Rchop(x,\
    \ x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n};\n"
  code: "#pragma once\n\ntemplate <class M>\nconcept monoid = requires(typename M::value_type\
    \ x) {\n    { M::op(x, x) } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x,\
    \ x) };\n    { M::Rchop(x, x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n\
    };"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/algebra/monoid/Concepts.hpp
  requiredBy:
  - library/segtree/SegmentTree.hpp
  - library/algebra/group/Concepts.hpp
  - library/datastructure/CumulativeMonoid.hpp
  - library/datastructure/CumulativeGroup.hpp
  - library/datastructure/FenwickTree.hpp
  - library/datastructure/GroupWaveletMatrix.hpp
  - library/datastructure/SWAG.hpp
  - library/math/FactorialNumberSystem.hpp
  - library/tree/TreeMonoid.hpp
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1036.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/algebra/monoid/Concepts.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Concepts.hpp
- /library/library/algebra/monoid/Concepts.hpp.html
title: library/algebra/monoid/Concepts.hpp
---
