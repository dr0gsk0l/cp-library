---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/superstd/Multiset.cpp
    title: library/superstd/Multiset.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"library/superstd/Multiset.cpp\"\
    \ntemplate<typename T>\nstruct Multiset:map<T,int>{\n  using map<T,int>::at;\n\
    \  using map<T,int>::size;\n  using map<T,int>::begin;\n  using map<T,int>::rbegin;\n\
    \  using map<T,int>::erase;\n  using map<T,int>::lower_bound;\n  using map<T,int>::upper_bound;\n\
    \n  int count(const T&a)const{ return (map<T,int>::count(a)?at(a):0); }\n  void\
    \ insert(const T&a){ (*this)[a]++; }\n  void erase1(const T&a){ if(map<T,int>::count(a)\
    \ and !--at(a))erase(a); }\n  void erase_k(const T&a,int k){\n    if(map<T,int>::count(a))return;\n\
    \    at(a)-=k;\n    if(at(a)<=0)erase(a);\n  }\n \n  T mn()const{ assert(size());\
    \ return begin()->first; }\n  T mx()const{ assert(size()); return rbegin()->first;\
    \ }\n  T pick_mn(){ // \u30D4\u30AF\u30DF\u30F3\n    T res=mn();\n    erase1(res);\n\
    \    return res;\n  }\n  T pick_mx(){\n    T res=mx();\n    erase1(res);\n   \
    \ return res;\n  }\n\n  T lt(const T&a)const{\n    assert(mn()<a);\n    if(mx()<a)return\
    \ mx();\n    return (--lower_bound(a))->first;\n  }\n  T leq(const T&a)const{\n\
    \    assert(mn()<=a);\n    if(mx()<=a)return mx();\n    return (--upper_bound(a))->first;\n\
    \  }\n  T gt(const T&a)const{\n    assert(mx()>a);\n    return upper_bound(a)->first;\n\
    \  }\n  T geq(const T&a)const{\n    assert(mx()>=a);\n    return lower_bound(a)->first;\n\
    \  }\n\n  Multiset()=default;\n  Multiset(const vector<T>&v){ for(const auto&p:v)insert(p);\
    \ }\n  \n  void scan(int n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n\
    \    }\n  }\n  \n  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n \
    \   insert(numeric_limits<T>::min()/2);\n  }\n};\n#line 6 \"test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,q;cin>>n>>q;\n  Multiset<int> s;\n  s.scan(n);\n  while(q--){\n    int t;cin>>t;\n\
    \    if(t==0){\n      int x;cin>>x;\n      s.insert(x);\n    }\n    if(t==1){\n\
    \      int a=s.pick_mn();\n      cout<<a<<\"\\n\";\n    }\n    if(t==2){\n   \
    \   int a=s.pick_mx();\n      cout<<a<<\"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/superstd/Multiset.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ n,q;cin>>n>>q;\n  Multiset<int> s;\n  s.scan(n);\n  while(q--){\n    int t;cin>>t;\n\
    \    if(t==0){\n      int x;cin>>x;\n      s.insert(x);\n    }\n    if(t==1){\n\
    \      int a=s.pick_mn();\n      cout<<a<<\"\\n\";\n    }\n    if(t==2){\n   \
    \   int a=s.pick_mx();\n      cout<<a<<\"\\n\";\n    }\n  }\n}"
  dependsOn:
  - library/superstd/Multiset.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
- /verify/test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp.html
title: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
---
