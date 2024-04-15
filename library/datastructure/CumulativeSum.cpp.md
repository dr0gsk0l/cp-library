---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
    title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/CumulativeSum.cpp\"\ntemplate <typename\
    \ T> struct CumulativeSum {\n    using U = std::conditional_t<std::is_same_v<T,\
    \ int>, long long, T>;\n    std::vector<U> A;\n    CumulativeSum() : A(1, 0) {}\n\
    \    CumulativeSum(const std::vector<T> &v) : A(v.size() + 1, 0) {\n        for\
    \ (int i = 0; i < v.size(); i++)\n            A[i + 1] = A[i] + v[i];\n    }\n\
    \    void add(const T &a) { A.push_back(A.back() + a); }\n    U sum(int l, int\
    \ r) { return A[r] - A[l]; }\n    U sum() { return A.back(); }\n};\n"
  code: "template <typename T> struct CumulativeSum {\n    using U = std::conditional_t<std::is_same_v<T,\
    \ int>, long long, T>;\n    std::vector<U> A;\n    CumulativeSum() : A(1, 0) {}\n\
    \    CumulativeSum(const std::vector<T> &v) : A(v.size() + 1, 0) {\n        for\
    \ (int i = 0; i < v.size(); i++)\n            A[i + 1] = A[i] + v[i];\n    }\n\
    \    void add(const T &a) { A.push_back(A.back() + a); }\n    U sum(int l, int\
    \ r) { return A[r] - A[l]; }\n    U sum() { return A.back(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/StaticRangeSum.test.cpp
documentation_of: library/datastructure/CumulativeSum.cpp
layout: document
redirect_from:
- /library/library/datastructure/CumulativeSum.cpp
- /library/library/datastructure/CumulativeSum.cpp.html
title: library/datastructure/CumulativeSum.cpp
---
