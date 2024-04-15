---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddMin.cpp
    title: library/algebra/lazy/AddMin.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Min.cpp
    title: library/algebra/monoid/Min.cpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/DualSegmentTree.cpp
    title: library/segtree/DualSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/AOJ/DSL_2_E.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename\
    \ X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 1 \"library/algebra/monoid/Min.cpp\"\ntemplate <typename X> struct MonoidMin\
    \ {\n    using value_type = X;\n    static constexpr X op(const X &x, const X\
    \ &y) noexcept {\n        return std::min(x, y);\n    }\n    static constexpr\
    \ void Rchop(X &x, const X &y) {\n        if (x > y)\n            x = y;\n   \
    \ }\n    static constexpr void Lchop(const X &x, X &y) {\n        if (y > x)\n\
    \            y = x;\n    }\n    static constexpr X unit() { return std::numeric_limits<X>::max()\
    \ / 2; }\n    static constexpr bool commute = true;\n};\n#line 4 \"library/algebra/lazy/AddMin.cpp\"\
    \ntemplate <typename X> struct LazyAddMin {\n    using MX = MonoidMin<X>;\n  \
    \  using MF = GroupAdd<X>;\n    static constexpr X mapping(const X &f, const X\
    \ &x) { return f + x; }\n};\n#line 1 \"library/segtree/DualSegmentTree.cpp\"\n\
    template <typename Lazy> class DualSegmentTree {\n    using MX = typename Lazy::MX;\n\
    \    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n \
    \   using F = typename MF::value_type;\n    int n, log, size;\n    std::vector<X>\
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
    \ }\n};\n#line 7 \"test/AOJ/DSL_2_E.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    DualSegmentTree<LazyAddMin<int>>\
    \ seg(std::vector<int>(n, 0));\n    while (q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t) {\n            int x;\n            std::cin >> x;\n  \
    \          x--;\n            std::cout << seg[x] << \"\\n\";\n        } else {\n\
    \            int l, r, x;\n            std::cin >> l >> r >> x;\n            l--;\n\
    \            seg.apply(l, r, x);\n        }\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/lazy/AddMin.cpp\"\n#include\
    \ \"library/segtree/DualSegmentTree.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    DualSegmentTree<LazyAddMin<int>>\
    \ seg(std::vector<int>(n, 0));\n    while (q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t) {\n            int x;\n            std::cin >> x;\n  \
    \          x--;\n            std::cout << seg[x] << \"\\n\";\n        } else {\n\
    \            int l, r, x;\n            std::cin >> l >> r >> x;\n            l--;\n\
    \            seg.apply(l, r, x);\n        }\n    }\n}\n"
  dependsOn:
  - library/algebra/lazy/AddMin.cpp
  - library/algebra/group/Add.cpp
  - library/algebra/monoid/Min.cpp
  - library/segtree/DualSegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_E.test.cpp
- /verify/test/AOJ/DSL_2_E.test.cpp.html
title: test/AOJ/DSL_2_E.test.cpp
---