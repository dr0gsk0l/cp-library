---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/segtree/DualSegmentTree.hpp\"\ntemplate <typename\
    \ Lazy> class DualSegmentTree {\n    using MX = typename Lazy::MX;\n    using\
    \ MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n    using F\
    \ = typename MF::value_type;\n    int n, log, size;\n    std::vector<X> dat;\n\
    \    std::vector<F> laz;\n\n    void point_apply(int k, const F &f) {\n      \
    \  if (k < size)\n            MF::Lchop(f, laz[k]);\n        else\n          \
    \  dat[k - size] = Lazy::mapping(f, dat[k - size]);\n    }\n    void push(int\
    \ k) {\n        point_apply(2 * k, laz[k]);\n        point_apply(2 * k + 1, laz[k]);\n\
    \        laz[k] = MF::unit();\n    }\n    void thrust(int k) {\n        for (int\
    \ i = log; i; i--)\n            push(k >> i);\n    }\n\n  public:\n    DualSegmentTree()\
    \ : DualSegmentTree(0) {}\n    DualSegmentTree(int n) : DualSegmentTree(std::vector<X>(n,\
    \ MX::unit())) {}\n    DualSegmentTree(const std::vector<X> &v) : n(v.size()),\
    \ dat(v) {\n        for (log = 1; (1 << log) < n; log++) {\n        }\n      \
    \  size = 1 << log;\n        laz.assign(size, MF::unit());\n    }\n\n    void\
    \ set(int p, X x) {\n        assert(0 <= p and p < n);\n        thrust(p + size);\n\
    \        dat[p] = x;\n    }\n\n    X operator[](int p) {\n        assert(0 <=\
    \ p and p < n);\n        thrust(p + size);\n        return dat[p];\n    }\n\n\
    \    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (l == r)\n            return;\n        thrust(l += size);\n\
    \        thrust(r += size - 1);\n        for (int L = l, R = r + 1; L < R; L >>=\
    \ 1, R >>= 1) {\n            if (L & 1)\n                point_apply(L++, f);\n\
    \            if (R & 1)\n                point_apply(--R, f);\n        }\n   \
    \ }\n};\n"
  code: "template <typename Lazy> class DualSegmentTree {\n    using MX = typename\
    \ Lazy::MX;\n    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n\
    \    using F = typename MF::value_type;\n    int n, log, size;\n    std::vector<X>\
    \ dat;\n    std::vector<F> laz;\n\n    void point_apply(int k, const F &f) {\n\
    \        if (k < size)\n            MF::Lchop(f, laz[k]);\n        else\n    \
    \        dat[k - size] = Lazy::mapping(f, dat[k - size]);\n    }\n    void push(int\
    \ k) {\n        point_apply(2 * k, laz[k]);\n        point_apply(2 * k + 1, laz[k]);\n\
    \        laz[k] = MF::unit();\n    }\n    void thrust(int k) {\n        for (int\
    \ i = log; i; i--)\n            push(k >> i);\n    }\n\n  public:\n    DualSegmentTree()\
    \ : DualSegmentTree(0) {}\n    DualSegmentTree(int n) : DualSegmentTree(std::vector<X>(n,\
    \ MX::unit())) {}\n    DualSegmentTree(const std::vector<X> &v) : n(v.size()),\
    \ dat(v) {\n        for (log = 1; (1 << log) < n; log++) {\n        }\n      \
    \  size = 1 << log;\n        laz.assign(size, MF::unit());\n    }\n\n    void\
    \ set(int p, X x) {\n        assert(0 <= p and p < n);\n        thrust(p + size);\n\
    \        dat[p] = x;\n    }\n\n    X operator[](int p) {\n        assert(0 <=\
    \ p and p < n);\n        thrust(p + size);\n        return dat[p];\n    }\n\n\
    \    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (l == r)\n            return;\n        thrust(l += size);\n\
    \        thrust(r += size - 1);\n        for (int L = l, R = r + 1; L < R; L >>=\
    \ 1, R >>= 1) {\n            if (L & 1)\n                point_apply(L++, f);\n\
    \            if (R & 1)\n                point_apply(--R, f);\n        }\n   \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/segtree/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2025-11-09 20:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
  - test/yukicoder/1038.test.cpp
documentation_of: library/segtree/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/library/segtree/DualSegmentTree.hpp
- /library/library/segtree/DualSegmentTree.hpp.html
title: library/segtree/DualSegmentTree.hpp
---
