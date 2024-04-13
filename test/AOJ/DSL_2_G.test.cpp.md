---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.cpp
    title: library/algebra/group/CntSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddSum.cpp
    title: library/algebra/lazy/AddSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/segtree/LazySegmentTree.cpp
    title: library/segtree/LazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/AOJ/DSL_2_G.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename\
    \ X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 1 \"library/algebra/group/CntSum.cpp\"\ntemplate <typename X> struct GroupCntSum\
    \ {\n    using P = std::pair<X, X>;\n    using value_type = P;\n    static constexpr\
    \ P op(const P &x, const P &y) {\n        return {x.first + y.first, x.second\
    \ + y.second};\n    }\n    static constexpr void Rchop(P &x, const P &y) {\n \
    \       x.first += y.first;\n        x.second += y.second;\n    }\n    static\
    \ constexpr void Lchop(const P &x, P &y) {\n        y.first += x.first;\n    \
    \    y.second += x.second;\n    }\n    static constexpr P inverse(const P &x)\
    \ { return {-x.fi, -x.se}; }\n    static constexpr P unit() { return {0, 0}; }\n\
    \    static constexpr bool commute = true;\n};\ntemplate <typename X> std::vector<std::pair<X,\
    \ X>> cnt_init(int n, const X &x) {\n    return std::vector<std::pair<X, X>>(n,\
    \ {x, 1});\n}\ntemplate <typename X>\nstd::vector<std::pair<X, X>> cnt_init(const\
    \ std::vector<X> &v) {\n    int n = v.size();\n    std::vector<std::pair<X, X>>\
    \ res(n);\n    for (int i = 0; i < n; i++)\n        res[i] = {v[i], 1};\n    return\
    \ res;\n}\n#line 4 \"library/algebra/lazy/AddSum.cpp\"\ntemplate <typename X>\
    \ struct LazyAddSum {\n    using MX = GroupCntSum<X>;\n    using MF = GroupAdd<X>;\n\
    \    using S = typename MX::value_type;\n    static constexpr S mapping(const\
    \ X &f, const S &x) {\n        return {x.first + f * x.second, x.second};\n  \
    \  }\n};\n#line 2 \"library/segtree/LazySegmentTree.cpp\"\n\ntemplate <typename\
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
    \    recalc(l);\n        recalc(r);\n    }\n};\n#line 7 \"test/AOJ/DSL_2_G.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    LazySegmentTree<LazyAddSum<ll>>\
    \ seg(cnt_init(n, 0LL));\n\n    while (q--) {\n        int t, l, r;\n        std::cin\
    \ >> t >> l >> r;\n        l--;\n        if (t)\n            std::cout << seg.prod(l,\
    \ r).first << \"\\n\";\n        else {\n            int x;\n            std::cin\
    \ >> x;\n            seg.apply(l, r, x);\n        }\n    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/lazy/AddSum.cpp\"\n#include\
    \ \"library/segtree/LazySegmentTree.cpp\"\n\nusing ll = long long;\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int n, q;\n    std::cin >> n >> q;\n    LazySegmentTree<LazyAddSum<ll>> seg(cnt_init(n,\
    \ 0LL));\n\n    while (q--) {\n        int t, l, r;\n        std::cin >> t >>\
    \ l >> r;\n        l--;\n        if (t)\n            std::cout << seg.prod(l,\
    \ r).first << \"\\n\";\n        else {\n            int x;\n            std::cin\
    \ >> x;\n            seg.apply(l, r, x);\n        }\n    }\n}"
  dependsOn:
  - library/algebra/lazy/AddSum.cpp
  - library/algebra/group/Add.cpp
  - library/algebra/group/CntSum.cpp
  - library/segtree/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_G.test.cpp
- /verify/test/AOJ/DSL_2_G.test.cpp.html
title: test/AOJ/DSL_2_G.test.cpp
---
