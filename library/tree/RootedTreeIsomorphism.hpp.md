---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
    title: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/RootedTreeIsomorphism.hpp\"\ntemplate <typename\
    \ TREE>\nstd::pair<int, std::vector<int>> rooted_tree_isomorphism(TREE &t) {\n\
    \    assert(~t.root);\n    std::vector<int> res(t.n);\n    std::map<std::vector<int>,\
    \ int> mp;\n    for (const int v : t.DFS) {\n        std::vector<int> h;\n   \
    \     for (int to : t.son(v))\n            h.push_back(res[to]);\n        std::ranges::sort(h);\n\
    \        if (!mp.count(h))\n            mp[h] = mp.size();\n        res[v] = mp[h];\n\
    \    }\n    return {mp.size(), res};\n}\n"
  code: "template <typename TREE>\nstd::pair<int, std::vector<int>> rooted_tree_isomorphism(TREE\
    \ &t) {\n    assert(~t.root);\n    std::vector<int> res(t.n);\n    std::map<std::vector<int>,\
    \ int> mp;\n    for (const int v : t.DFS) {\n        std::vector<int> h;\n   \
    \     for (int to : t.son(v))\n            h.push_back(res[to]);\n        std::ranges::sort(h);\n\
    \        if (!mp.count(h))\n            mp[h] = mp.size();\n        res[v] = mp[h];\n\
    \    }\n    return {mp.size(), res};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/RootedTreeIsomorphism.hpp
  requiredBy: []
  timestamp: '2024-07-08 10:24:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
documentation_of: library/tree/RootedTreeIsomorphism.hpp
layout: document
redirect_from:
- /library/library/tree/RootedTreeIsomorphism.hpp
- /library/library/tree/RootedTreeIsomorphism.hpp.html
title: library/tree/RootedTreeIsomorphism.hpp
---
