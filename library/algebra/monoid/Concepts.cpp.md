---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Concepts.cpp
    title: library/algebra/group/Concepts.cpp
  - icon: ':warning:'
    path: library/datastructure/CumulativeGroup.cpp
    title: library/datastructure/CumulativeGroup.cpp
  - icon: ':warning:'
    path: library/datastructure/CumulativeMonoid.cpp
    title: library/datastructure/CumulativeMonoid.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/SWAG.cpp
    title: library/datastructure/SWAG.cpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.cpp
    title: library/math/FactorialNumberSystem.cpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.cpp
    title: library/segtree/SegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.cpp
    title: library/tree/TreeMonoid.cpp
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
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/monoid/Concepts.cpp\"\n\ntemplate <class\
    \ M>\nconcept monoid = requires(typename M::value_type x) {\n    { M::op(x, x)\
    \ } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x, x) };\n    { M::Rchop(x,\
    \ x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n};\n\n//\
    \ todo : able_monoid\n"
  code: "#pragma once\n\ntemplate <class M>\nconcept monoid = requires(typename M::value_type\
    \ x) {\n    { M::op(x, x) } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x,\
    \ x) };\n    { M::Rchop(x, x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n\
    };\n\n// todo : able_monoid"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Concepts.cpp
  requiredBy:
  - library/math/FactorialNumberSystem.cpp
  - library/tree/TreeMonoid.cpp
  - library/datastructure/SWAG.cpp
  - library/datastructure/FenwickTree.cpp
  - library/datastructure/CumulativeGroup.cpp
  - library/datastructure/CumulativeMonoid.cpp
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/algebra/group/Concepts.cpp
  - library/segtree/SegmentTree.cpp
  timestamp: '2023-12-10 20:25:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1036.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/algebra/monoid/Concepts.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Concepts.cpp
- /library/library/algebra/monoid/Concepts.cpp.html
title: library/algebra/monoid/Concepts.cpp
---
