---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/unionfind/PotentialUnionFind.cpp
    title: library/datastructure/unionfind/PotentialUnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/AOJ/DSL_1_B.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename\
    \ X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 2 \"library/datastructure/unionfind/PotentialUnionFind.cpp\"\ntemplate <typename\
    \ AbelGroup> class PotentialUnionFind {\n    using T = typename AbelGroup::value_type;\n\
    \    int n, num;\n    std::vector<int> sz, parent;\n    std::vector<T> potential;\
    \ // parent[x] \u3092\u57FA\u6E96\u3068\u3057\u305F\u6642\u306E x \u306E\u5024\
    \n  public:\n    PotentialUnionFind() = default;\n    PotentialUnionFind(int n)\n\
    \        : n(n), num(n), sz(n, 1), parent(n, 0),\n          potential(n, AbelGroup::unit())\
    \ {\n        assert(AbelGroup::commute);\n        std::iota(parent.begin(), parent.end(),\
    \ 0);\n    }\n\n    std::pair<int, T> from_root(int x) {\n        if (x == parent[x])\n\
    \            return {x, AbelGroup::unit()};\n        auto [r, add] = from_root(parent[x]);\n\
    \        parent[x] = r;\n        AbelGroup::Rchop(potential[x], add);\n      \
    \  return {r, potential[x]};\n    }\n\n    int leader(int x) { return from_root(x).first;\
    \ }\n\n    bool same(int x, int y) {\n        assert(0 <= x and x < n and 0 <=\
    \ y and y < n);\n        return leader(x) == leader(y);\n    }\n\n    bool merge(int\
    \ x, int y, T d) {\n        // potential[y]-potential[x]=d \u306B\u3059\u308B\n\
    \        // \u77DB\u76FE\u3059\u308B\u5834\u5408\u306F\u5909\u66F4\u306F\u305B\
    \u305A false \u3092\u8FD4\u3059\n        assert(0 <= x and x < n and 0 <= y and\
    \ y < n);\n        auto [rx, dx] = from_root(x);\n        auto [ry, dy] = from_root(y);\n\
    \        AbelGroup::Rchop(d, dx);\n        AbelGroup::Rchop(d, AbelGroup::inverse(dy));\n\
    \        if (rx == ry)\n            return d == AbelGroup::unit();\n        if\
    \ (sz[rx] < sz[ry]) {\n            std::swap(rx, ry);\n            d = AbelGroup::inverse(d);\n\
    \        }\n        sz[rx] += sz[ry];\n        parent[ry] = rx;\n        potential[ry]\
    \ = d;\n        num--;\n        return true;\n    }\n\n    std::optional<T> diff(int\
    \ x, int y) {\n        // x \u3092\u57FA\u6E96\u3068\u3059\u308B\n        auto\
    \ [rx, dx] = from_root(x);\n        auto [ry, dy] = from_root(y);\n        if\
    \ (rx != ry)\n            return std::nullopt;\n        return AbelGroup::op(dy,\
    \ AbelGroup::inverse(dx));\n    }\n\n    int size(const int x) {\n        assert(0\
    \ <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int count() const\
    \ { return num; }\n};\n#line 7 \"test/AOJ/DSL_1_B.test.cpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    PotentialUnionFind<GroupAdd<int>> PUF(n);\n\
    \    while (q--) {\n        int t, x, y;\n        std::cin >> t >> x >> y;\n \
    \       if (t) {\n            auto diff = PUF.diff(x, y);\n            if (diff)\n\
    \                std::cout << diff.value() << \"\\n\";\n            else\n   \
    \             std::cout << \"?\\n\";\n        } else {\n            int d;\n \
    \           std::cin >> d;\n            assert(PUF.merge(x, y, d));\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/group/Add.cpp\"\n#include\
    \ \"library/datastructure/unionfind/PotentialUnionFind.cpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    PotentialUnionFind<GroupAdd<int>> PUF(n);\n\
    \    while (q--) {\n        int t, x, y;\n        std::cin >> t >> x >> y;\n \
    \       if (t) {\n            auto diff = PUF.diff(x, y);\n            if (diff)\n\
    \                std::cout << diff.value() << \"\\n\";\n            else\n   \
    \             std::cout << \"?\\n\";\n        } else {\n            int d;\n \
    \           std::cin >> d;\n            assert(PUF.merge(x, y, d));\n        }\n\
    \    }\n}"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/datastructure/unionfind/PotentialUnionFind.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 12:10:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_1_B.test.cpp
- /verify/test/AOJ/DSL_1_B.test.cpp.html
title: test/AOJ/DSL_1_B.test.cpp
---
