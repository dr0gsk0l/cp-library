---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/datastructure/CumulativeSum.cpp
    title: library/datastructure/CumulativeSum.cpp
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
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"library/datastructure/CumulativeSum.cpp\"\
    \ntemplate<typename T>\nstruct CumulativeSum{\n  using U=conditional_t< is_same_v<T,int>,long\
    \ long,T >;\n  vector<U> A;\n  CumulativeSum():A(1,0){}\n  CumulativeSum(const\
    \ vector<T>&v):A(v.size()+1,0){\n    for(int i=0;i<v.size();i++)A[i+1]=A[i]+v[i];\n\
    \  }\n  void add(const T&a){ A.push_back(A.back()+a); }\n  U sum(int l,int r){\
    \ return A[r]-A[l]; }\n  U sum(){ return A.back(); }\n};\n#line 6 \"test/library-checker/DataStructure/StaticRangeSum.test.cpp\"\
    \n\nint main() {\n  int n,q;cin>>n>>q;\n  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  auto wa=CumulativeSum(v);\n  while(q--){\n    int l,r;cin>>l>>r;\n    cout<<wa.sum(l,r)<<'\\\
    n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/datastructure/CumulativeSum.cpp\"\
    \n\nint main() {\n  int n,q;cin>>n>>q;\n  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  auto wa=CumulativeSum(v);\n  while(q--){\n    int l,r;cin>>l>>r;\n    cout<<wa.sum(l,r)<<'\\\
    n';\n  }\n}"
  dependsOn:
  - library/datastructure/CumulativeSum.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/StaticRangeSum.test.cpp
  requiredBy: []
  timestamp: '2023-12-10 20:25:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/StaticRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/StaticRangeSum.test.cpp.html
title: test/library-checker/DataStructure/StaticRangeSum.test.cpp
---
