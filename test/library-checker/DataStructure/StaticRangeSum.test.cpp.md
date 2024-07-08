---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/datastructure/CumulativeSum.hpp
    title: library/datastructure/CumulativeSum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/library-checker/DataStructure/StaticRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\n\n#line 1 \"library/datastructure/CumulativeSum.hpp\"\ntemplate\
    \ <typename T> struct CumulativeSum {\n    using U = std::conditional_t<std::is_same_v<T,\
    \ int>, long long, T>;\n    std::vector<U> A;\n    CumulativeSum() : A(1, 0) {}\n\
    \    CumulativeSum(const std::vector<T> &v) : A(v.size() + 1, 0) {\n        for\
    \ (int i = 0; i < v.size(); i++)\n            A[i + 1] = A[i] + v[i];\n    }\n\
    \    void add(const T &a) { A.push_back(A.back() + a); }\n    U sum(int l, int\
    \ r) { return A[r] - A[l]; }\n    U sum() { return A.back(); }\n};\n#line 5 \"\
    test/library-checker/DataStructure/StaticRangeSum.test.cpp\"\n\nint main() {\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> v(n);\n    for (int\
    \ i = 0; i < n; i++)\n        std::cin >> v[i];\n    auto wa = CumulativeSum(v);\n\
    \    while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << wa.sum(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"library/datastructure/CumulativeSum.hpp\"\n\n\
    int main() {\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> v(n);\n\
    \    for (int i = 0; i < n; i++)\n        std::cin >> v[i];\n    auto wa = CumulativeSum(v);\n\
    \    while (q--) {\n        int l, r;\n        std::cin >> l >> r;\n        std::cout\
    \ << wa.sum(l, r) << '\\n';\n    }\n}"
  dependsOn:
  - library/datastructure/CumulativeSum.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  requiredBy: []
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/StaticRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp.html
title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
---
