---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1330.test.cpp
    title: test/AOJ/1330.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2207.test.cpp
    title: test/AOJ/2207.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2971.test.cpp
    title: test/AOJ/2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_B.test.cpp
    title: test/AOJ/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/UnionfindWithPotential.test.cpp
    title: test/library-checker/DataStructure/UnionfindWithPotential.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1420.test.cpp
    title: test/yukicoder/1420.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/datastructure/unionfind/PotentialUnionFind.hpp\"\
    \ntemplate <typename AbelGroup> class PotentialUnionFind {\n    using T = typename\
    \ AbelGroup::value_type;\n    int n, num;\n    std::vector<int> sz, parent;\n\
    \    std::vector<T> potential; // parent[x] \u3092\u57FA\u6E96\u3068\u3057\u305F\
    \u6642\u306E x \u306E\u5024\n  public:\n    PotentialUnionFind() = default;\n\
    \    PotentialUnionFind(int n)\n        : n(n), num(n), sz(n, 1), parent(n, 0),\n\
    \          potential(n, AbelGroup::unit()) {\n        assert(AbelGroup::commute);\n\
    \        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    std::pair<int,\
    \ T> from_root(int x) {\n        if (x == parent[x])\n            return {x, AbelGroup::unit()};\n\
    \        auto [r, add] = from_root(parent[x]);\n        parent[x] = r;\n     \
    \   AbelGroup::Rchop(potential[x], add);\n        return {r, potential[x]};\n\
    \    }\n\n    int leader(int x) { return from_root(x).first; }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    bool merge(int x, int y, T d)\
    \ {\n        // potential[y]-potential[x]=d \u306B\u3059\u308B\n        // \u77DB\
    \u76FE\u3059\u308B\u5834\u5408\u306F\u5909\u66F4\u306F\u305B\u305A false \u3092\
    \u8FD4\u3059\n        assert(0 <= x and x < n and 0 <= y and y < n);\n       \
    \ auto [rx, dx] = from_root(x);\n        auto [ry, dy] = from_root(y);\n     \
    \   AbelGroup::Rchop(d, dx);\n        AbelGroup::Rchop(d, AbelGroup::inverse(dy));\n\
    \        if (rx == ry)\n            return d == AbelGroup::unit();\n        if\
    \ (sz[rx] < sz[ry]) {\n            std::swap(rx, ry);\n            d = AbelGroup::inverse(d);\n\
    \        }\n        sz[rx] += sz[ry];\n        parent[ry] = rx;\n        potential[ry]\
    \ = d;\n        num--;\n        return true;\n    }\n\n    std::optional<T> diff(int\
    \ x, int y) {\n        // x \u3092\u57FA\u6E96\u3068\u3059\u308B\n        auto\
    \ [rx, dx] = from_root(x);\n        auto [ry, dy] = from_root(y);\n        if\
    \ (rx != ry)\n            return std::nullopt;\n        return AbelGroup::op(dy,\
    \ AbelGroup::inverse(dx));\n    }\n\n    int size(const int x) {\n        assert(0\
    \ <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int count() const\
    \ { return num; }\n};\n"
  code: "#pragma once\ntemplate <typename AbelGroup> class PotentialUnionFind {\n\
    \    using T = typename AbelGroup::value_type;\n    int n, num;\n    std::vector<int>\
    \ sz, parent;\n    std::vector<T> potential; // parent[x] \u3092\u57FA\u6E96\u3068\
    \u3057\u305F\u6642\u306E x \u306E\u5024\n  public:\n    PotentialUnionFind() =\
    \ default;\n    PotentialUnionFind(int n)\n        : n(n), num(n), sz(n, 1), parent(n,\
    \ 0),\n          potential(n, AbelGroup::unit()) {\n        assert(AbelGroup::commute);\n\
    \        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    std::pair<int,\
    \ T> from_root(int x) {\n        if (x == parent[x])\n            return {x, AbelGroup::unit()};\n\
    \        auto [r, add] = from_root(parent[x]);\n        parent[x] = r;\n     \
    \   AbelGroup::Rchop(potential[x], add);\n        return {r, potential[x]};\n\
    \    }\n\n    int leader(int x) { return from_root(x).first; }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    bool merge(int x, int y, T d)\
    \ {\n        // potential[y]-potential[x]=d \u306B\u3059\u308B\n        // \u77DB\
    \u76FE\u3059\u308B\u5834\u5408\u306F\u5909\u66F4\u306F\u305B\u305A false \u3092\
    \u8FD4\u3059\n        assert(0 <= x and x < n and 0 <= y and y < n);\n       \
    \ auto [rx, dx] = from_root(x);\n        auto [ry, dy] = from_root(y);\n     \
    \   AbelGroup::Rchop(d, dx);\n        AbelGroup::Rchop(d, AbelGroup::inverse(dy));\n\
    \        if (rx == ry)\n            return d == AbelGroup::unit();\n        if\
    \ (sz[rx] < sz[ry]) {\n            std::swap(rx, ry);\n            d = AbelGroup::inverse(d);\n\
    \        }\n        sz[rx] += sz[ry];\n        parent[ry] = rx;\n        potential[ry]\
    \ = d;\n        num--;\n        return true;\n    }\n\n    std::optional<T> diff(int\
    \ x, int y) {\n        // x \u3092\u57FA\u6E96\u3068\u3059\u308B\n        auto\
    \ [rx, dx] = from_root(x);\n        auto [ry, dy] = from_root(y);\n        if\
    \ (rx != ry)\n            return std::nullopt;\n        return AbelGroup::op(dy,\
    \ AbelGroup::inverse(dx));\n    }\n\n    int size(const int x) {\n        assert(0\
    \ <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int count() const\
    \ { return num; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/PotentialUnionFind.hpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/UnionfindWithPotential.test.cpp
  - test/AOJ/1330.test.cpp
  - test/AOJ/2207.test.cpp
  - test/AOJ/2971.test.cpp
  - test/AOJ/DSL_1_B.test.cpp
  - test/yukicoder/1420.test.cpp
documentation_of: library/datastructure/unionfind/PotentialUnionFind.hpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/PotentialUnionFind.hpp
- /library/library/datastructure/unionfind/PotentialUnionFind.hpp.html
title: library/datastructure/unionfind/PotentialUnionFind.hpp
---
