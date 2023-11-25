---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
    title: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/RootedTreeIsomorphism.cpp\"\ntemplate<typename\
    \ TREE>\npair<int,vector<int>> rooted_tree_isomorphism(TREE&t){\n  assert(~t.root);\n\
    \  vector<int> res(t.n);\n  map<vector<int>,int> mp;\n  for(const int v:t.DFS){\n\
    \    vector<int> h;\n    for(int to:t.son(v))h.push_back(res[to]);\n    sort(h.begin(),h.end());\n\
    \    if(!mp.count(h))mp[h]=mp.size();\n    res[v]=mp[h];\n  }\n  return {mp.size(),res};\n\
    }\n"
  code: "template<typename TREE>\npair<int,vector<int>> rooted_tree_isomorphism(TREE&t){\n\
    \  assert(~t.root);\n  vector<int> res(t.n);\n  map<vector<int>,int> mp;\n  for(const\
    \ int v:t.DFS){\n    vector<int> h;\n    for(int to:t.son(v))h.push_back(res[to]);\n\
    \    sort(h.begin(),h.end());\n    if(!mp.count(h))mp[h]=mp.size();\n    res[v]=mp[h];\n\
    \  }\n  return {mp.size(),res};\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/RootedTreeIsomorphism.cpp
  requiredBy: []
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
documentation_of: library/tree/RootedTreeIsomorphism.cpp
layout: document
redirect_from:
- /library/library/tree/RootedTreeIsomorphism.cpp
- /library/library/tree/RootedTreeIsomorphism.cpp.html
title: library/tree/RootedTreeIsomorphism.cpp
---
