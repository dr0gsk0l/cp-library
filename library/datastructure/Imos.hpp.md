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
  bundledCode: "#line 1 \"library/datastructure/Imos.hpp\"\ntemplate <typename T>\
    \ class Imos {\n    std::vector<T> data;\n\n  public:\n    Imos() = default;\n\
    \    Imos(int n) : data(n + 1, 0) {}\n    // [0,n] \u3092\u4F5C\u308B\n\n    //[l,r)\
    \ \u306B a \u3092\u8FFD\u52A0\n    void add(int l, int r, T a = 1) {\n       \
    \ assert(0 <= l and l <= r and r < data.size());\n        data[l] += a;\n    \
    \    data[r] -= a;\n    }\n\n    std::vector<T> build() {\n        for (int i\
    \ = 0; i + 1 < data.size(); i++)\n            data[i + 1] += data[i];\n      \
    \  return data;\n    }\n};\n"
  code: "template <typename T> class Imos {\n    std::vector<T> data;\n\n  public:\n\
    \    Imos() = default;\n    Imos(int n) : data(n + 1, 0) {}\n    // [0,n] \u3092\
    \u4F5C\u308B\n\n    //[l,r) \u306B a \u3092\u8FFD\u52A0\n    void add(int l, int\
    \ r, T a = 1) {\n        assert(0 <= l and l <= r and r < data.size());\n    \
    \    data[l] += a;\n        data[r] -= a;\n    }\n\n    std::vector<T> build()\
    \ {\n        for (int i = 0; i + 1 < data.size(); i++)\n            data[i + 1]\
    \ += data[i];\n        return data;\n    }\n};\n"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/datastructure/Imos.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/Imos.hpp
layout: document
redirect_from:
- /library/library/datastructure/Imos.hpp
- /library/library/datastructure/Imos.hpp.html
title: library/datastructure/Imos.hpp
---
