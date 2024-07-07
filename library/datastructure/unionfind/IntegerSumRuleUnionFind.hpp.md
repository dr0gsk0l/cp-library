---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp\"\
    \nclass IntegerSumRuleUnionFind {\n    using ll = long long;\n    int n, num;\n\
    \    std::vector<int> sz, parent;\n    std::vector<std::pair<int, ll>> potential;\n\
    \    std::vector<std::optional<ll>> value;\n\n  public:\n    IntegerSumRuleUnionFind()\
    \ = default;\n    IntegerSumRuleUnionFind(int n)\n        : n(n), num(n), sz(n,\
    \ 1), parent(n, 0), potential(n, {1, 0}),\n          value(n, std::nullopt) {\n\
    \        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    std::tuple<int,\
    \ int, ll> from_root(int x) {\n        if (x == parent[x])\n            return\
    \ {x, 1, 0LL};\n        auto [r, a, b] = from_root(parent[x]);\n        auto [c,\
    \ d] = potential[x];\n        parent[x] = r;\n        potential[x] = {a * c, b\
    \ * c + d};\n        return {r, a * c, b * c + d};\n    }\n\n    int leader(int\
    \ x) { return get<0>(from_root(x)); }\n\n    bool same(int x, int y) {\n     \
    \   assert(0 <= x and x < n and 0 <= y and y < n);\n        return leader(x) ==\
    \ leader(y);\n    }\n\n    bool merge(int x, int y, ll sum) {\n        // \u77DB\
    \u76FE\u3059\u308B\u5834\u5408\u306F\u5909\u66F4\u306F\u305B\u305A false \u3092\
    \u8FD4\u3059\n        assert(0 <= x and x < n and 0 <= y and y < n);\n       \
    \ auto [rx, a, b] = from_root(x);\n        auto [ry, c, d] = from_root(y);\n \
    \       if (rx == ry) {\n            // ar+b + cr+d = sum\n            if (a ==\
    \ -c)\n                return b + d == sum;\n            if ((sum - b - d) & 1)\n\
    \                return false;\n            ll r = (sum - b - d) / (a + c);\n\
    \            if (value[rx] and value[rx].value() != r)\n                return\
    \ false; // \u3053\u308C\u8D77\u304D\u308B\uFF1F\n            value[rx] = r;\n\
    \            return true;\n        }\n        if (sz[rx] < sz[ry]) {\n       \
    \     std::swap(rx, ry);\n            std::swap(a, c);\n            std::swap(b,\
    \ d);\n        }\n        // a * rx + b + c * ry + d == sum\n        // rx = -c/a\
    \ ry + (sum-b-d)/a\n        // ry = -a/c rx + (sum-b-d)/c\n        if (value[ry])\
    \ {\n            ll k = -c * a * value[ry].value() + (sum - b - d) * a;\n    \
    \        if (value[rx] and value[rx].value() != k)\n                return false;\n\
    \            value[rx] = k;\n        }\n        sz[rx] += sz[ry];\n        parent[ry]\
    \ = rx;\n        potential[ry] = {-a * c, (sum - b - d) * c};\n        num--;\n\
    \        return true;\n    }\n\n    std::optional<ll> val(int x) {\n        auto\
    \ [r, a, b] = from_root(x);\n        if (value[r])\n            return value[r].value()\
    \ * a + b;\n        return std::nullopt;\n    }\n\n    // x \u3068 y \u304C\u96A3\
    \u63A5\u3057\u3066\u306A\u3044\u306A\u3089 std::nullopt\n    // x \u3068 y \u304C\
    \u96A3\u63A5\u3057\u3066\u3044\u308B\u304C\u3001sum \u304C\u4E00\u610F\u3067\u306A\
    \u3044\u5834\u5408\u3082 std::nullopt\n    std::optional<ll> sum(int x, int y)\
    \ {\n        auto [rx, a, b] = from_root(x);\n        auto [ry, c, d] = from_root(y);\n\
    \        if (rx != ry)\n            return std::nullopt;\n        if (a == c)\
    \ {\n            assert(b == d);\n            return std::nullopt;\n        }\n\
    \        return b + d;\n    }\n\n    int size(const int x) {\n        assert(0\
    \ <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int count() const\
    \ { return num; }\n};\n"
  code: "class IntegerSumRuleUnionFind {\n    using ll = long long;\n    int n, num;\n\
    \    std::vector<int> sz, parent;\n    std::vector<std::pair<int, ll>> potential;\n\
    \    std::vector<std::optional<ll>> value;\n\n  public:\n    IntegerSumRuleUnionFind()\
    \ = default;\n    IntegerSumRuleUnionFind(int n)\n        : n(n), num(n), sz(n,\
    \ 1), parent(n, 0), potential(n, {1, 0}),\n          value(n, std::nullopt) {\n\
    \        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    std::tuple<int,\
    \ int, ll> from_root(int x) {\n        if (x == parent[x])\n            return\
    \ {x, 1, 0LL};\n        auto [r, a, b] = from_root(parent[x]);\n        auto [c,\
    \ d] = potential[x];\n        parent[x] = r;\n        potential[x] = {a * c, b\
    \ * c + d};\n        return {r, a * c, b * c + d};\n    }\n\n    int leader(int\
    \ x) { return get<0>(from_root(x)); }\n\n    bool same(int x, int y) {\n     \
    \   assert(0 <= x and x < n and 0 <= y and y < n);\n        return leader(x) ==\
    \ leader(y);\n    }\n\n    bool merge(int x, int y, ll sum) {\n        // \u77DB\
    \u76FE\u3059\u308B\u5834\u5408\u306F\u5909\u66F4\u306F\u305B\u305A false \u3092\
    \u8FD4\u3059\n        assert(0 <= x and x < n and 0 <= y and y < n);\n       \
    \ auto [rx, a, b] = from_root(x);\n        auto [ry, c, d] = from_root(y);\n \
    \       if (rx == ry) {\n            // ar+b + cr+d = sum\n            if (a ==\
    \ -c)\n                return b + d == sum;\n            if ((sum - b - d) & 1)\n\
    \                return false;\n            ll r = (sum - b - d) / (a + c);\n\
    \            if (value[rx] and value[rx].value() != r)\n                return\
    \ false; // \u3053\u308C\u8D77\u304D\u308B\uFF1F\n            value[rx] = r;\n\
    \            return true;\n        }\n        if (sz[rx] < sz[ry]) {\n       \
    \     std::swap(rx, ry);\n            std::swap(a, c);\n            std::swap(b,\
    \ d);\n        }\n        // a * rx + b + c * ry + d == sum\n        // rx = -c/a\
    \ ry + (sum-b-d)/a\n        // ry = -a/c rx + (sum-b-d)/c\n        if (value[ry])\
    \ {\n            ll k = -c * a * value[ry].value() + (sum - b - d) * a;\n    \
    \        if (value[rx] and value[rx].value() != k)\n                return false;\n\
    \            value[rx] = k;\n        }\n        sz[rx] += sz[ry];\n        parent[ry]\
    \ = rx;\n        potential[ry] = {-a * c, (sum - b - d) * c};\n        num--;\n\
    \        return true;\n    }\n\n    std::optional<ll> val(int x) {\n        auto\
    \ [r, a, b] = from_root(x);\n        if (value[r])\n            return value[r].value()\
    \ * a + b;\n        return std::nullopt;\n    }\n\n    // x \u3068 y \u304C\u96A3\
    \u63A5\u3057\u3066\u306A\u3044\u306A\u3089 std::nullopt\n    // x \u3068 y \u304C\
    \u96A3\u63A5\u3057\u3066\u3044\u308B\u304C\u3001sum \u304C\u4E00\u610F\u3067\u306A\
    \u3044\u5834\u5408\u3082 std::nullopt\n    std::optional<ll> sum(int x, int y)\
    \ {\n        auto [rx, a, b] = from_root(x);\n        auto [ry, c, d] = from_root(y);\n\
    \        if (rx != ry)\n            return std::nullopt;\n        if (a == c)\
    \ {\n            assert(b == d);\n            return std::nullopt;\n        }\n\
    \        return b + d;\n    }\n\n    int size(const int x) {\n        assert(0\
    \ <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int count() const\
    \ { return num; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp
- /library/library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp.html
title: library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp
---
