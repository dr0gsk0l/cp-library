---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cumulativesum.cpp
    title: datastructure/cumulativesum.cpp
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
    \ <bits/stdc++.h>\n\n\n#line 1 \"datastructure/cumulativesum.cpp\"\
    \ntemplate<typename T>\nstruct CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T >;\n  std::vector<U> A;\n  CumulativeSum(const std::vector<T>&v){\n    A.resize(v.size()+1,0);\n\
    \    for(int i=0;i<v.size();i++)A[i+1]=A[i]+v[i];\n  }\n  void add(const T& a){\n\
    \    A.push_back(A.back()+a);\n  }\n  U sum(int l,int r){\n    return A[r]-A[l];\n\
    \  }\n};\n#line 6 \"test/library-checker/DataStructure/StaticRangeSum.test.cpp\"\
    \n\nint main() {\n  int n,q;cin>>n>>q;\n  std::vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  auto wa=CumulativeSum(v);\n  while(q--){\n    int l,r;cin>>l>>r;\n    std::cout<<wa.sum(l,r)<<'\\\
    n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\n\n\n#include \"datastructure/cumulativesum.cpp\"\
    \n\nint main() {\n  int n,q;cin>>n>>q;\n  std::vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  auto wa=CumulativeSum(v);\n  while(q--){\n    int l,r;cin>>l>>r;\n    std::cout<<wa.sum(l,r)<<'\\\
    n';\n  }\n}"
  dependsOn:
  - datastructure/cumulativesum.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  requiredBy: []
  timestamp: '2022-09-07 12:14:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: library/test/library-checker/DataStructure/StaticRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp.html
title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
---
