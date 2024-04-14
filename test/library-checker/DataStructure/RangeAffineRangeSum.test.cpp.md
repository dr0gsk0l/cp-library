---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.cpp
    title: library/algebra/group/CntSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AffineSum.cpp
    title: library/algebra/lazy/AffineSum.cpp
  - icon: ':question:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include <bits/stdc++.h>\n\n#line 2 \"library/linearalgebra/Linear.cpp\"\ntemplate\
    \ <typename T> struct Line {\n    T a, b;\n    Line() = default;\n    Line(T a,\
    \ T b) : a(a), b(b) {}\n    Line(std::pair<T, T> l) : a(l.first), b(l.second)\
    \ {}\n    Line(T c) : a(0), b(c) {}\n\n    T operator()(const T x) const { return\
    \ a * x + b; }\n    Line operator()(const Line &l) const { return Line(a * l.a,\
    \ a * l.b + b); }\n\n    bool operator==(const Line &l) const { return a == l.a\
    \ and b == l.b; }\n    bool operator!=(const Line &l) const { return !(*this ==\
    \ l); }\n    bool operator<(const Line &l) const {\n        return (a == l.a ?\
    \ a < l.a : b < l.b);\n    }\n\n    Line &operator+=(const Line &l) {\n      \
    \  a += l.a;\n        b += l.b;\n        return *this;\n    }\n    Line operator+(const\
    \ Line &l) const { return Line(*this) += l; }\n    Line &operator-=(const Line\
    \ &l) {\n        a -= l.a;\n        b -= l.b;\n        return *this;\n    }\n\
    \    Line operator-(const Line &l) const { return Line(*this) -= l; }\n    Line\
    \ operator-() const { return Line(-a, -b); }\n\n    Line &operator+=(const T &c)\
    \ {\n        b += c;\n        return *this;\n    }\n    Line operator+(const T\
    \ &c) const { return Line(*this) += c; }\n    Line &operator-=(const T &c) {\n\
    \        b -= c;\n        return *this;\n    }\n    Line operator-(const T &c)\
    \ const { return Line(*this) -= c; }\n    Line &operator*=(const T &c) {\n   \
    \     a *= c;\n        b *= c;\n        return *this;\n    }\n    Line operator*(const\
    \ T &c) const { return Line(*this) *= c; }\n    Line &operator/=(const T &c) {\n\
    \        a /= c;\n        b /= c;\n        return *this;\n    }\n    Line operator/(const\
    \ T &c) const { return Line(*this) /= c; }\n\n    Line inv() const {\n       \
    \ assert(a != 0);\n        return Line(T(1) / a, -b / a);\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &l) {\n        is >> l.a >>\
    \ l.b;\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &l) {\n        if (l.a == 0 and l.b == 0)\n            os <<\
    \ 0;\n        else if (l.a == 0)\n            os << l.b;\n        else if (l.b\
    \ == 0)\n            os << l.a << \"x\";\n        else if (l.b > 0)\n        \
    \    os << l.a << \"x+\" << l.b;\n        else\n            os << l.a << \"x-\"\
    \ << -l.b;\n        return os;\n    }\n};\n#line 3 \"library/algebra/group/Affine.cpp\"\
    \ntemplate<typename T>\nstruct GroupAffine{\n  using L = Line<T>;\n  using value_type\
    \ = L;\n  static constexpr L op(const L&f, const L&g)noexcept{ return f(g); }\n\
    \  static constexpr void Rchop(L&f, const L&g){\n    f.b += f.a*g.b;\n    f.a\
    \ *= g.a;\n  }\n  static constexpr void Lchop(const L&f, L&g){\n    (g.b *= f.a)\
    \ += f.b;\n    g.a *= f.a;\n  }\n  static constexpr L inverse(const L&f){ return\
    \ f.inv(); }\n  /*\n  static constexpr L power(const L& f,long long n) noexcept\
    \ {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr L unit(){ return L(1,0); }\n  static constexpr\
    \ bool commute = false;\n};\n#line 1 \"library/algebra/group/CntSum.cpp\"\ntemplate\
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
    \ i < n; i++)\n        res[i] = {v[i], 1};\n    return res;\n}\n#line 4 \"library/algebra/lazy/AffineSum.cpp\"\
    \ntemplate <typename X> struct LazyAffineSum {\n    using MX = GroupCntSum<X>;\n\
    \    using MF = GroupAffine<X>;\n    using P = typename MX::value_type;\n    using\
    \ F = typename MF::value_type;\n    static constexpr P mapping(const F &f, const\
    \ P &x) {\n        return {f.a * x.first + f.b * x.second, x.second};\n    }\n\
    };\n#line 2 \"library/math/ExtraGCD.cpp\"\nusing ll = long long;\nstd::pair<ll,\
    \ ll> ext_gcd(ll a, ll b) {\n    if (b == 0)\n        return {1, 0};\n    auto\
    \ [X, Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b = a -\
    \ b(a/b)\n    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X - (a\
    \ / b) * Y;\n    return {x, y};\n}\n#line 3 \"library/mod/Modint.cpp\"\ntemplate\
    \ <typename T, T MOD = 998244353> struct Mint {\n    inline static constexpr T\
    \ mod = MOD;\n    T v;\n    Mint() : v(0) {}\n    Mint(signed v) : v(v) {}\n \
    \   Mint(long long t) {\n        v = t % MOD;\n        if (v < 0)\n          \
    \  v += MOD;\n    }\n\n    static Mint raw(int v) {\n        Mint x;\n       \
    \ x.v = v;\n        return x;\n    }\n\n    Mint pow(long long k) const {\n  \
    \      Mint res(1), tmp(v);\n        while (k) {\n            if (k & 1)\n   \
    \             res *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    static Mint add_identity() { return\
    \ Mint(0); }\n    static Mint mul_identity() { return Mint(1); }\n\n    // Mint\
    \ inv()const{return pow(MOD-2);}\n    Mint inv() const { return Mint(ext_gcd(v,\
    \ mod).first); }\n\n    Mint &operator+=(Mint a) {\n        v += a.v;\n      \
    \  if (v >= MOD)\n            v -= MOD;\n        return *this;\n    }\n    Mint\
    \ &operator-=(Mint a) {\n        v += MOD - a.v;\n        if (v >= MOD)\n    \
    \        v -= MOD;\n        return *this;\n    }\n    Mint &operator*=(Mint a)\
    \ {\n        v = 1LL * v * a.v % MOD;\n        return *this;\n    }\n    Mint\
    \ &operator/=(Mint a) { return (*this) *= a.inv(); }\n\n    Mint operator+(Mint\
    \ a) const { return Mint(v) += a; }\n    Mint operator-(Mint a) const { return\
    \ Mint(v) -= a; }\n    Mint operator*(Mint a) const { return Mint(v) *= a; }\n\
    \    Mint operator/(Mint a) const { return Mint(v) /= a; }\n#define FRIEND(op)\
    \                                                             \\\n    friend Mint\
    \ operator op(int a, Mint b) { return Mint(a) op b; }\n    FRIEND(+);\n    FRIEND(-);\n\
    \    FRIEND(*);\n    FRIEND(/);\n#undef FRIEND\n    Mint operator+() const { return\
    \ *this; }\n    Mint operator-() const { return v ? Mint(MOD - v) : Mint(v); }\n\
    \n    bool operator==(const Mint a) const { return v == a.v; }\n    bool operator!=(const\
    \ Mint a) const { return v != a.v; }\n\n    static Mint comb(long long n, int\
    \ k) {\n        Mint num(1), dom(1);\n        for (int i = 0; i < k; i++) {\n\
    \            num *= Mint(n - i);\n            dom *= Mint(i + 1);\n        }\n\
    \        return num / dom;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Mint &m) {\n        os << m.v;\n        return os;\n    }\n    friend\
    \ std::istream &operator>>(std::istream &is, Mint &m) {\n        is >> m.v;\n\
    \        m.v %= MOD;\n        if (m.v < 0)\n            m.v += MOD;\n        return\
    \ is;\n    }\n};\n#line 2 \"library/segtree/LazySegmentTree.cpp\"\n\ntemplate\
    \ <typename Lazy> class LazySegmentTree {\n    using MX = typename Lazy::MX;\n\
    \    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n \
    \   using F = typename MF::value_type;\n    int n, log, size;\n    std::vector<X>\
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
    \    recalc(l);\n        recalc(r);\n    }\n};\n#line 7 \"test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp\"\
    \n\nusing mint = Mint<long long>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<mint>\
    \ v(n);\n    for (int i = 0; i < n; i++)\n        std::cin >> v[i];\n    LazySegmentTree<LazyAffineSum<mint>>\
    \ seg(cnt_init(v));\n\n    while (q--) {\n        int t, l, r;\n        std::cin\
    \ >> t >> l >> r;\n        if (t)\n            std::cout << seg.prod(l, r).first\
    \ << '\\n';\n        else {\n            Line<mint> f;\n            std::cin >>\
    \ f;\n            seg.apply(l, r, f);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/lazy/AffineSum.cpp\"\n\
    #include \"library/mod/Modint.cpp\"\n#include \"library/segtree/LazySegmentTree.cpp\"\
    \n\nusing mint = Mint<long long>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<mint>\
    \ v(n);\n    for (int i = 0; i < n; i++)\n        std::cin >> v[i];\n    LazySegmentTree<LazyAffineSum<mint>>\
    \ seg(cnt_init(v));\n\n    while (q--) {\n        int t, l, r;\n        std::cin\
    \ >> t >> l >> r;\n        if (t)\n            std::cout << seg.prod(l, r).first\
    \ << '\\n';\n        else {\n            Line<mint> f;\n            std::cin >>\
    \ f;\n            seg.apply(l, r, f);\n        }\n    }\n}"
  dependsOn:
  - library/algebra/lazy/AffineSum.cpp
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/Linear.cpp
  - library/algebra/group/CntSum.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  - library/segtree/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-04-14 21:36:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp.html
title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
---
