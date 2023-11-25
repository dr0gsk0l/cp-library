---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/superstd/Set.cpp
    title: library/superstd/Set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/library-checker/DataStructure/PredecessorProblem.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"library/superstd/Set.cpp\"\
    \ntemplate<typename T>\nstruct Set:set<T>{\n  using set<T>::size;\n  using set<T>::begin;\n\
    \  using set<T>::rbegin;\n  using set<T>::insert;\n  using set<T>::erase;\n  using\
    \ set<T>::lower_bound;\n  using set<T>::upper_bound;\n  \n  T mn()const{ assert(size());return\
    \ *begin(); }\n  T mx()const{ assert(size());return *rbegin(); }\n  \n  T pop_front(){\n\
    \    assert(size());\n    T mn=*begin();\n    erase(begin());\n    return mn;\n\
    \  }\n  T pop_back(){\n    assert(size());\n    T mx=*rbegin();\n    erase(mx);\n\
    \    return mx;\n  }\n\n  T lt(const T&a)const{\n    assert(mn()<a);\n    if(mx()<a)return\
    \ mx();\n    return *--lower_bound(a);\n  }\n  T leq(const T&a)const{\n    assert(mn()<=a);\n\
    \    if(mx()<=a)return mx();\n    return *--upper_bound(a);\n  }\n  T gt(const\
    \ T&a)const{\n    assert(mx()>a);\n    return *upper_bound(a);\n  }\n  T geq(const\
    \ T&a){\n    assert(mx()>=a);\n    return *lower_bound(a);\n  }\n  \n  Set()=default;\n\
    \  Set(const vector<T>&v){ for(const auto&p:v)insert(p); }\n  \n  void scan(int\
    \ n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n    }\n  }\n  \n\
    \  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n    insert(numeric_limits<T>::min()/2);\n\
    \  }\n};\n#line 6 \"test/library-checker/DataStructure/PredecessorProblem.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,q;cin>>n>>q;\n  Set<int> se;\n  se.banpei();\n\n  for(int i=0;i<n;i++){\n\
    \    char c;cin>>c;\n    if(c=='1')se.insert(i);\n  }\n\n  while(q--){\n    int\
    \ c,k;cin>>c>>k;\n    if(c==0)se.insert(k);\n    if(c==1)se.erase(k);\n    if(c==2)cout<<se.count(k)<<\"\
    \\n\";\n    if(c==3){\n      int x=se.geq(k);\n      cout<<(x<n?x:-1)<<\"\\n\"\
    ;\n    }\n    if(c==4){\n      int x=se.leq(k);\n      cout<<(x>=0?x:-1)<<\"\\\
    n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/superstd/Set.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,q;cin>>n>>q;\n  Set<int> se;\n  se.banpei();\n\n  for(int i=0;i<n;i++){\n\
    \    char c;cin>>c;\n    if(c=='1')se.insert(i);\n  }\n\n  while(q--){\n    int\
    \ c,k;cin>>c>>k;\n    if(c==0)se.insert(k);\n    if(c==1)se.erase(k);\n    if(c==2)cout<<se.count(k)<<\"\
    \\n\";\n    if(c==3){\n      int x=se.geq(k);\n      cout<<(x<n?x:-1)<<\"\\n\"\
    ;\n    }\n    if(c==4){\n      int x=se.leq(k);\n      cout<<(x>=0?x:-1)<<\"\\\
    n\";\n    }\n  }\n}"
  dependsOn:
  - library/superstd/Set.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PredecessorProblem.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:03:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PredecessorProblem.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PredecessorProblem.test.cpp
- /verify/test/library-checker/DataStructure/PredecessorProblem.test.cpp.html
title: test/library-checker/DataStructure/PredecessorProblem.test.cpp
---
