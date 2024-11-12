---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.hpp
    title: library/tree/TreeLazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/segtree/LazySegmentTree.hpp\"\n\ntemplate <typename\
    \ Lazy> class LazySegmentTree {\n    using MX = typename Lazy::MX;\n    using\
    \ MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n    using F\
    \ = typename MF::value_type;\n    int n, log, size;\n    std::vector<X> dat;\n\
    \    std::vector<F> laz;\n\n    X reflect(int k) {\n        if (k < size)\n  \
    \          return Lazy::mapping(laz[k], dat[k]);\n        return dat[k];\n   \
    \ }\n    void point_apply(int k, const F &f) {\n        if (k < size)\n      \
    \      MF::Lchop(f, laz[k]);\n        else\n            dat[k] = Lazy::mapping(f,\
    \ dat[k]);\n    }\n    void push(int k) {\n        dat[k] = reflect(k);\n    \
    \    point_apply(2 * k, laz[k]);\n        point_apply(2 * k + 1, laz[k]);\n  \
    \      laz[k] = MF::unit();\n    }\n    void thrust(int k) {\n        for (int\
    \ i = log; i; i--)\n            push(k >> i);\n    }\n    void update(int i) {\
    \ dat[i] = MX::op(reflect(2 * i), reflect(2 * i + 1)); }\n    void recalc(int\
    \ k) {\n        while (k >>= 1)\n            update(k);\n    }\n\n  public:\n\
    \    LazySegmentTree() : LazySegmentTree(0) {}\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<X>(n,\
    \ MX::unit())) {}\n    LazySegmentTree(const std::vector<X> &v) : n(v.size())\
    \ {\n        for (log = 1; (1 << log) < n; log++) {\n        }\n        size =\
    \ 1 << log;\n        dat.assign(size << 1, MX::unit());\n        laz.assign(size,\
    \ MF::unit());\n        for (int i = 0; i < n; ++i)\n            dat[size + i]\
    \ = v[i];\n        for (int i = size - 1; i >= 1; --i)\n            update(i);\n\
    \    }\n\n    void set(int p, X x) {\n        assert(0 <= p and p < n);\n    \
    \    thrust(p += size);\n        dat[p] = x;\n        recalc(p);\n    }\n\n  \
    \  X operator[](int p) {\n        assert(0 <= p and p < n);\n        thrust(p\
    \ += size);\n        return reflect(p);\n    }\n\n    X prod(int L, int R) {\n\
    \        assert(0 <= L and L <= R and R <= n);\n        if (L == R)\n        \
    \    return MX::unit();\n        thrust(L += size);\n        thrust((R += size\
    \ - 1)++);\n        X vl = MX::unit(), vr = MX::unit();\n        while (L < R)\
    \ {\n            if (L & 1)\n                MX::Rchop(vl, reflect(L++));\n  \
    \          if (R & 1)\n                MX::Lchop(reflect(--R), vr);\n        \
    \    L >>= 1, R >>= 1;\n        }\n        return MX::op(vl, vr);\n    }\n\n \
    \   void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r)\n            return;\n        thrust(l += size);\n      \
    \  thrust(r += size - 1);\n        for (int L = l, R = r + 1; L < R; L >>= 1,\
    \ R >>= 1) {\n            if (L & 1)\n                point_apply(L++, f);\n \
    \           if (R & 1)\n                point_apply(--R, f);\n        }\n    \
    \    recalc(l);\n        recalc(r);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename Lazy> class LazySegmentTree {\n    using\
    \ MX = typename Lazy::MX;\n    using MF = typename Lazy::MF;\n    using X = typename\
    \ MX::value_type;\n    using F = typename MF::value_type;\n    int n, log, size;\n\
    \    std::vector<X> dat;\n    std::vector<F> laz;\n\n    X reflect(int k) {\n\
    \        if (k < size)\n            return Lazy::mapping(laz[k], dat[k]);\n  \
    \      return dat[k];\n    }\n    void point_apply(int k, const F &f) {\n    \
    \    if (k < size)\n            MF::Lchop(f, laz[k]);\n        else\n        \
    \    dat[k] = Lazy::mapping(f, dat[k]);\n    }\n    void push(int k) {\n     \
    \   dat[k] = reflect(k);\n        point_apply(2 * k, laz[k]);\n        point_apply(2\
    \ * k + 1, laz[k]);\n        laz[k] = MF::unit();\n    }\n    void thrust(int\
    \ k) {\n        for (int i = log; i; i--)\n            push(k >> i);\n    }\n\
    \    void update(int i) { dat[i] = MX::op(reflect(2 * i), reflect(2 * i + 1));\
    \ }\n    void recalc(int k) {\n        while (k >>= 1)\n            update(k);\n\
    \    }\n\n  public:\n    LazySegmentTree() : LazySegmentTree(0) {}\n    LazySegmentTree(int\
    \ n) : LazySegmentTree(std::vector<X>(n, MX::unit())) {}\n    LazySegmentTree(const\
    \ std::vector<X> &v) : n(v.size()) {\n        for (log = 1; (1 << log) < n; log++)\
    \ {\n        }\n        size = 1 << log;\n        dat.assign(size << 1, MX::unit());\n\
    \        laz.assign(size, MF::unit());\n        for (int i = 0; i < n; ++i)\n\
    \            dat[size + i] = v[i];\n        for (int i = size - 1; i >= 1; --i)\n\
    \            update(i);\n    }\n\n    void set(int p, X x) {\n        assert(0\
    \ <= p and p < n);\n        thrust(p += size);\n        dat[p] = x;\n        recalc(p);\n\
    \    }\n\n    X operator[](int p) {\n        assert(0 <= p and p < n);\n     \
    \   thrust(p += size);\n        return reflect(p);\n    }\n\n    X prod(int L,\
    \ int R) {\n        assert(0 <= L and L <= R and R <= n);\n        if (L == R)\n\
    \            return MX::unit();\n        thrust(L += size);\n        thrust((R\
    \ += size - 1)++);\n        X vl = MX::unit(), vr = MX::unit();\n        while\
    \ (L < R) {\n            if (L & 1)\n                MX::Rchop(vl, reflect(L++));\n\
    \            if (R & 1)\n                MX::Lchop(reflect(--R), vr);\n      \
    \      L >>= 1, R >>= 1;\n        }\n        return MX::op(vl, vr);\n    }\n\n\
    \    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (l == r)\n            return;\n        thrust(l += size);\n\
    \        thrust(r += size - 1);\n        for (int L = l, R = r + 1; L < R; L >>=\
    \ 1, R >>= 1) {\n            if (L & 1)\n                point_apply(L++, f);\n\
    \            if (R & 1)\n                point_apply(--R, f);\n        }\n   \
    \     recalc(l);\n        recalc(r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/segtree/LazySegmentTree.hpp
  requiredBy:
  - library/tree/TreeLazy.hpp
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/segtree/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/library/segtree/LazySegmentTree.hpp
- /library/library/segtree/LazySegmentTree.hpp.html
title: library/segtree/LazySegmentTree.hpp
---
