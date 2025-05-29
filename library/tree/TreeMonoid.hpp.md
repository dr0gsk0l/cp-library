---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.hpp
    title: library/algebra/Reverse.hpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.hpp
    title: library/algebra/monoid/Concepts.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/SegmentTree.hpp
    title: library/segtree/SegmentTree.hpp
  - icon: ':question:'
    path: library/tree/HLD.hpp
    title: library/tree/HLD.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/segtree/SegmentTree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include \"library/algebra/Reverse.hpp\"\n#include \"library/segtree/SegmentTree.hpp\"\
    \n#include \"library/tree/HLD.hpp\"\ntemplate <typename TREE, typename Monoid>\
    \ struct TreeMonoid {\n    using X = typename Monoid::value_type;\n    using Monoid_r\
    \ = AlgebraReverse<Monoid>;\n    int n;\n    TREE T;\n    HLD<Tree> hld;\n   \
    \ std::vector<int> hld_id, euler_in, euler_out;\n    SegmentTree<Monoid> seg;\n\
    \    SegmentTree<Monoid_r> seg_r;\n\n    TreeMonoid(TREE T, int r = 0) : T(T),\
    \ hld(T), n(T.n), seg(n), seg_r(n) {\n        T.build(r);\n        hld_id = hld.build(r);\n\
    \    }\n    TreeMonoid(TREE T, std::vector<X> a, int r = 0) : T(T), hld(T), n(T.n)\
    \ {\n        T.build(r);\n        hld_id = hld.build(r);\n        std::vector<X>\
    \ hld_a(n);\n        for (int v = 0; v < n; v++)\n            hld_a[hld_id[v]]\
    \ = a[v];\n        seg = SegmentTree<Monoid>(hld_a);\n        if (!Monoid::commute)\n\
    \            seg_r = SegmentTree<Monoid_r>(hld_a);\n    }\n\n    void set(int\
    \ v, X x) {\n        seg.set(hld_id[v], x);\n        if (!Monoid::commute)\n \
    \           seg_r.set(hld_id[v], x);\n    }\n    void multiply(int v, X x) {\n\
    \        seg.multiply(hld_id[v], x);\n        if (!Monoid::commute)\n        \
    \    seg_r.multiply(hld_id[v], x);\n    }\n    X get(int v) { return seg.get(hld_id[v]);\
    \ }\n\n    // [u,v]\u30D1\u30B9\u306E monoid \u7A4D\n    X path_prod(int u, int\
    \ v) {\n        auto [path_u, path_v] = hld.path(u, v);\n        X prod_u = Monoid::unit(),\
    \ prod_v = Monoid::unit();\n        for (const auto &[l, r] : path_u) {\n    \
    \        X val =\n                (Monoid::commute ? seg.prod(r, l + 1) : seg_r.prod(r,\
    \ l + 1));\n            Monoid::Rchop(prod_u, val);\n        }\n        for (const\
    \ auto &[l, r] : path_v) {\n            X val = seg.prod(r, l + 1);\n        \
    \    Monoid::Lchop(val, prod_v);\n        }\n        return Monoid::op(prod_u,\
    \ prod_v);\n    }\n    // root -> path\n    X path_root(int v) { return path(T.root,\
    \ v); }\n\n    X subtree_prod(int v) {\n        assert(Monoid::commute);\n   \
    \     auto [l, r] = hld.subtree(v);\n        return seg.prod(l, r);\n    }\n};"
  dependsOn:
  - library/algebra/Reverse.hpp
  - library/segtree/SegmentTree.hpp
  - library/algebra/monoid/Concepts.hpp
  - library/tree/HLD.hpp
  isVerificationFile: false
  path: library/tree/TreeMonoid.hpp
  requiredBy: []
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/tree/TreeMonoid.hpp
layout: document
redirect_from:
- /library/library/tree/TreeMonoid.hpp
- /library/library/tree/TreeMonoid.hpp.html
title: library/tree/TreeMonoid.hpp
---
