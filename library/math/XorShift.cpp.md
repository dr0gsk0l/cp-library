---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/datastructure/binary_search_tree/ImplicitTreap.cpp
    title: library/datastructure/binary_search_tree/ImplicitTreap.cpp
  - icon: ':warning:'
    path: library/datastructure/binary_search_tree/Treap.cpp
    title: library/datastructure/binary_search_tree/Treap.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/XorShift.cpp\"\nclass XorShift{\n  uint64_t\
    \ x;\npublic:\n  XorShift(){\n    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    x=rnd();\n    for(int i=0;i<100;i++)(*this)();\n  }\n  uint64_t operator()(){\n\
    \    x = x^(x<<7);\n    return x = x^(x>>9);\n  }\n};\n"
  code: "class XorShift{\n  uint64_t x;\npublic:\n  XorShift(){\n    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    x=rnd();\n    for(int i=0;i<100;i++)(*this)();\n  }\n  uint64_t operator()(){\n\
    \    x = x^(x<<7);\n    return x = x^(x>>9);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/XorShift.cpp
  requiredBy:
  - library/datastructure/binary_search_tree/ImplicitTreap.cpp
  - library/datastructure/binary_search_tree/Treap.cpp
  timestamp: '2024-04-13 18:08:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/XorShift.cpp
layout: document
redirect_from:
- /library/library/math/XorShift.cpp
- /library/library/math/XorShift.cpp.html
title: library/math/XorShift.cpp
---
