---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.cpp
    title: library/algebra/group/CntSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetSum.cpp
    title: library/algebra/lazy/SetSum.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Set.cpp
    title: library/algebra/monoid/Set.cpp
  - icon: ':question:'
    path: library/segtree/LazySegmentTree.cpp
    title: library/segtree/LazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"test/AOJ/DSL_2_I.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/algebra/group/CntSum.cpp\"\ntemplate\
    \ <typename X> struct GroupCntSum {\n    using P = std::pair<X, X>;\n    using\
    \ value_type = P;\n    static constexpr P op(const P &x, const P &y) {\n     \
    \   return {x.first + y.first, x.second + y.second};\n    }\n    static constexpr\
    \ void Rchop(P &x, const P &y) {\n        x.first += y.first;\n        x.second\
    \ += y.second;\n    }\n    static constexpr void Lchop(const P &x, P &y) {\n \
    \       y.first += x.first;\n        y.second += x.second;\n    }\n    static\
    \ constexpr P inverse(const P &x) { return {-x.fi, -x.se}; }\n    static constexpr\
    \ P unit() { return {0, 0}; }\n    static constexpr bool commute = true;\n};\n\
    template <typename X> std::vector<std::pair<X, X>> cnt_init(int n, const X &x)\
    \ {\n    return std::vector<std::pair<X, X>>(n, {x, 1});\n}\ntemplate <typename\
    \ X>\nstd::vector<std::pair<X, X>> cnt_init(const std::vector<X> &v) {\n    int\
    \ n = v.size();\n    std::vector<std::pair<X, X>> res(n);\n    for (int i = 0;\
    \ i < n; i++)\n        res[i] = {v[i], 1};\n    return res;\n}\n#line 2 \"library/algebra/monoid/Set.cpp\"\
    \n// \u5408\u6210\u306E\u9806\u756A\u306F\u95A2\u6570\u3068\u4E00\u7DD2\u3060\u3088\
    \ntemplate <typename X> struct MonoidSet {\n    using O = std::optional<X>;\n\
    \    using value_type = O;\n    static constexpr O op(const O &x, const O &y)\
    \ noexcept {\n        return (x.has_value() ? x : y);\n    }\n    static constexpr\
    \ void Rchop(O &x, const O &y) {\n        if (!x)\n            x = y;\n    }\n\
    \    static constexpr void Lchop(const O &x, O &y) {\n        if (x)\n       \
    \     y = x;\n    }\n    static constexpr O unit() noexcept { return std::nullopt;\
    \ }\n    static constexpr bool commute = false;\n};\n#line 4 \"library/algebra/lazy/SetSum.cpp\"\
    \ntemplate <typename X> struct LazySetSum {\n    using MX = GroupCntSum<X>;\n\
    \    using MF = MonoidSet<X>;\n    using P = typename MX::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr P mapping(const F &f, const\
    \ P &x) {\n        if (f.has_value())\n            return {f.value() * x.second,\
    \ x.second};\n        return x;\n    }\n};\n#line 2 \"library/segtree/LazySegmentTree.cpp\"\
    \n\ntemplate <typename Lazy> class LazySegmentTree {\n    using MX = typename\
    \ Lazy::MX;\n    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n\
    \    using F = typename MF::value_type;\n    int n, log, size;\n    std::vector<X>\
    \ dat;\n    std::vector<F> laz;\n\n    X reflect(int k) {\n        if (k < size)\n\
    \            return Lazy::mapping(laz[k], dat[k]);\n        return dat[k];\n \
    \   }\n    void point_apply(int k, const F &f) {\n        if (k < size)\n    \
    \        MF::Lchop(f, laz[k]);\n        else\n            dat[k] = Lazy::mapping(f,\
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
    \    recalc(l);\n        recalc(r);\n    }\n};\n#line 7 \"test/AOJ/DSL_2_I.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n    LazySegmentTree<LazySetSum<int>>\
    \ seg(cnt_init(n, 0));\n    while (q--) {\n        int t, l, r;\n        std::cin\
    \ >> t >> l >> r;\n        r++;\n        if (t)\n            std::cout << seg.prod(l,\
    \ r).first << \"\\n\";\n        else {\n            int x;\n            std::cin\
    \ >> x;\n            seg.apply(l, r, x);\n        }\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/lazy/SetSum.cpp\"\n#include\
    \ \"library/segtree/LazySegmentTree.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    LazySegmentTree<LazySetSum<int>>\
    \ seg(cnt_init(n, 0));\n    while (q--) {\n        int t, l, r;\n        std::cin\
    \ >> t >> l >> r;\n        r++;\n        if (t)\n            std::cout << seg.prod(l,\
    \ r).first << \"\\n\";\n        else {\n            int x;\n            std::cin\
    \ >> x;\n            seg.apply(l, r, x);\n        }\n    }\n}"
  dependsOn:
  - library/algebra/lazy/SetSum.cpp
  - library/algebra/group/CntSum.cpp
  - library/algebra/monoid/Set.cpp
  - library/segtree/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_I.test.cpp
- /verify/test/AOJ/DSL_2_I.test.cpp.html
title: test/AOJ/DSL_2_I.test.cpp
---
