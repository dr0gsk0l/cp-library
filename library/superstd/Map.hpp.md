---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/superstd/Map.hpp\"\ntemplate <typename Key, typename\
    \ Val> struct Map : std::map<Key, Val> {\n    using std::map<Key, Val>::erase;\n\
    \n    void operator()(Key key, Val val) {\n        if (!((*this)[key] += val))\n\
    \            erase(key);\n    }\n};\n"
  code: "template <typename Key, typename Val> struct Map : std::map<Key, Val> {\n\
    \    using std::map<Key, Val>::erase;\n\n    void operator()(Key key, Val val)\
    \ {\n        if (!((*this)[key] += val))\n            erase(key);\n    }\n};"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/superstd/Map.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/superstd/Map.hpp
layout: document
redirect_from:
- /library/library/superstd/Map.hpp
- /library/library/superstd/Map.hpp.html
title: library/superstd/Map.hpp
---
