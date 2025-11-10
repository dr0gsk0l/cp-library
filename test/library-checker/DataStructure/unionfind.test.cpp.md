---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.hpp
    title: library/datastructure/unionfind/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/library-checker/DataStructure/unionfind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    \n#line 3 \"library/datastructure/unionfind/UnionFind.hpp\"\n\nclass UnionFind\
    \ {\n    int n, num;\n    std::vector<int> sz, parent;\n\n  public:\n    UnionFind()\
    \ = default;\n    UnionFind(int n) : n(n), num(n), sz(n, 1), parent(n, 0) {\n\
    \        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    int leader(int\
    \ x) {\n        assert(0 <= x and x < n);\n        return (x == parent[x] ? x\
    \ : parent[x] = leader(parent[x]));\n    }\n\n    bool same(int x, int y) {\n\
    \        assert(0 <= x and x < n and 0 <= y and y < n);\n        return leader(x)\
    \ == leader(y);\n    }\n\n    bool merge(int x, int y) {\n        assert(0 <=\
    \ x and x < n and 0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y)\n            return false;\n        if (sz[x] < sz[y])\n\
    \            std::swap(x, y);\n        sz[x] += sz[y];\n        parent[y] = x;\n\
    \        num--;\n        return true;\n    }\n\n    int size(const int x) {\n\
    \        assert(0 <= x and x < n);\n        return sz[leader(x)];\n    }\n\n \
    \   int count() const { return num; }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<std::vector<int>> res(n);\n        for (int i = 0; i\
    \ < n; i++)\n            res[leader(i)].push_back(i);\n        std::erase_if(res,\
    \ [](const auto &vec) { return vec.empty(); });\n        return res;\n    }\n\
    };\n#line 5 \"test/library-checker/DataStructure/unionfind.test.cpp\"\n\nint main()\
    \ {\n    int n, q;\n    std::cin >> n >> q;\n    UnionFind uf(n);\n    while (q--)\
    \ {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n        if (t)\n\
    \            std::cout << uf.same(u, v) << \"\\n\";\n        else\n          \
    \  uf.merge(u, v);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <bits/stdc++.h>\n\
    \n#include \"library/datastructure/unionfind/UnionFind.hpp\"\n\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    UnionFind uf(n);\n    while (q--)\
    \ {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n        if (t)\n\
    \            std::cout << uf.same(u, v) << \"\\n\";\n        else\n          \
    \  uf.merge(u, v);\n    }\n}"
  dependsOn:
  - library/datastructure/unionfind/UnionFind.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/unionfind.test.cpp
- /verify/test/library-checker/DataStructure/unionfind.test.cpp.html
title: test/library-checker/DataStructure/unionfind.test.cpp
---
