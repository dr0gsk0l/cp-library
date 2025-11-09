---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetMin.hpp
    title: library/algebra/lazy/SetMin.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Min.hpp
    title: library/algebra/monoid/Min.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Set.hpp
    title: library/algebra/monoid/Set.hpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/DualSegmentTree.hpp
    title: library/segtree/DualSegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/AOJ/DSL_2_D.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/algebra/monoid/Min.hpp\"\ntemplate\
    \ <typename X> struct MonoidMin {\n    using value_type = X;\n    static constexpr\
    \ X op(const X &x, const X &y) noexcept {\n        return std::min(x, y);\n  \
    \  }\n    static constexpr void Rchop(X &x, const X &y) {\n        if (x > y)\n\
    \            x = y;\n    }\n    static constexpr void Lchop(const X &x, X &y)\
    \ {\n        if (y > x)\n            y = x;\n    }\n    static constexpr X unit()\
    \ { return std::numeric_limits<X>::max() / 2; }\n    static constexpr bool commute\
    \ = true;\n};\n#line 2 \"library/algebra/monoid/Set.hpp\"\n// \u5408\u6210\u306E\
    \u9806\u756A\u306F\u95A2\u6570\u3068\u4E00\u7DD2\u3060\u3088\ntemplate <typename\
    \ X> struct MonoidSet {\n    using O = std::optional<X>;\n    using value_type\
    \ = O;\n    static constexpr O op(const O &x, const O &y) noexcept {\n       \
    \ return (x.has_value() ? x : y);\n    }\n    static constexpr void Rchop(O &x,\
    \ const O &y) {\n        if (!x)\n            x = y;\n    }\n    static constexpr\
    \ void Lchop(const O &x, O &y) {\n        if (x)\n            y = x;\n    }\n\
    \    static constexpr O unit() noexcept { return std::nullopt; }\n    static constexpr\
    \ bool commute = false;\n};\n#line 4 \"library/algebra/lazy/SetMin.hpp\"\ntemplate\
    \ <typename X> struct LazySetMin {\n    using MX = MonoidMin<X>;\n    using MF\
    \ = MonoidSet<X>;\n    using F = typename MF::value_type;\n    static constexpr\
    \ X mapping(const F &f, const X &x) { return f.value_or(x); }\n};\n#line 1 \"\
    library/segtree/DualSegmentTree.hpp\"\ntemplate <typename Lazy> class DualSegmentTree\
    \ {\n    using MX = typename Lazy::MX;\n    using MF = typename Lazy::MF;\n  \
    \  using X = typename MX::value_type;\n    using F = typename MF::value_type;\n\
    \    int n, log, size;\n    std::vector<X> dat;\n    std::vector<F> laz;\n\n \
    \   void point_apply(int k, const F &f) {\n        if (k < size)\n           \
    \ MF::Lchop(f, laz[k]);\n        else\n            dat[k - size] = Lazy::mapping(f,\
    \ dat[k - size]);\n    }\n    void push(int k) {\n        point_apply(2 * k, laz[k]);\n\
    \        point_apply(2 * k + 1, laz[k]);\n        laz[k] = MF::unit();\n    }\n\
    \    void thrust(int k) {\n        for (int i = log; i; i--)\n            push(k\
    \ >> i);\n    }\n\n  public:\n    DualSegmentTree() : DualSegmentTree(0) {}\n\
    \    DualSegmentTree(int n) : DualSegmentTree(std::vector<X>(n, MX::unit())) {}\n\
    \    DualSegmentTree(const std::vector<X> &v) : n(v.size()), dat(v) {\n      \
    \  for (log = 1; (1 << log) < n; log++) {\n        }\n        size = 1 << log;\n\
    \        laz.assign(size, MF::unit());\n    }\n\n    void set(int p, X x) {\n\
    \        assert(0 <= p and p < n);\n        thrust(p + size);\n        dat[p]\
    \ = x;\n    }\n\n    X operator[](int p) {\n        assert(0 <= p and p < n);\n\
    \        thrust(p + size);\n        return dat[p];\n    }\n\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l\
    \ == r)\n            return;\n        thrust(l += size);\n        thrust(r +=\
    \ size - 1);\n        for (int L = l, R = r + 1; L < R; L >>= 1, R >>= 1) {\n\
    \            if (L & 1)\n                point_apply(L++, f);\n            if\
    \ (R & 1)\n                point_apply(--R, f);\n        }\n    }\n};\n#line 7\
    \ \"test/AOJ/DSL_2_D.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    DualSegmentTree<LazySetMin<int>>\
    \ seg(std::vector<int>(n, (1LL << 31) - 1));\n    while (q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t) {\n            int i;\n            std::cin\
    \ >> i;\n            std::cout << seg[i] << \"\\n\";\n        } else {\n     \
    \       int l, r, x;\n            std::cin >> l >> r >> x;\n            r++;\n\
    \            seg.apply(l, r, x);\n        }\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/lazy/SetMin.hpp\"\n#include\
    \ \"library/segtree/DualSegmentTree.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    DualSegmentTree<LazySetMin<int>>\
    \ seg(std::vector<int>(n, (1LL << 31) - 1));\n    while (q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t) {\n            int i;\n            std::cin\
    \ >> i;\n            std::cout << seg[i] << \"\\n\";\n        } else {\n     \
    \       int l, r, x;\n            std::cin >> l >> r >> x;\n            r++;\n\
    \            seg.apply(l, r, x);\n        }\n    }\n}"
  dependsOn:
  - library/algebra/lazy/SetMin.hpp
  - library/algebra/monoid/Min.hpp
  - library/algebra/monoid/Set.hpp
  - library/segtree/DualSegmentTree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_D.test.cpp
- /verify/test/AOJ/DSL_2_D.test.cpp.html
title: test/AOJ/DSL_2_D.test.cpp
---
