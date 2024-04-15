---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/superstd/Map.cpp\"\ntemplate <typename Key, typename\
    \ Val> struct Map : std::map<Key, Val> {\n    using std::map<Key, Val>::erase;\n\
    \n    void operator()(Key key, Val val) {\n        if (!((*this)[key] += val))\n\
    \            erase(key);\n    }\n};\n"
  code: "template <typename Key, typename Val> struct Map : std::map<Key, Val> {\n\
    \    using std::map<Key, Val>::erase;\n\n    void operator()(Key key, Val val)\
    \ {\n        if (!((*this)[key] += val))\n            erase(key);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/superstd/Map.cpp
  requiredBy: []
  timestamp: '2024-04-15 09:29:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/superstd/Map.cpp
layout: document
redirect_from:
- /library/library/superstd/Map.cpp
- /library/library/superstd/Map.cpp.html
title: library/superstd/Map.cpp
---
