---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PredecessorProblem.test.cpp
    title: test/library-checker/DataStructure/PredecessorProblem.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/superstd/Set.cpp\"\ntemplate<typename T>\nstruct\
    \ Set:set<T>{\n  using set<T>::size;\n  using set<T>::begin;\n  using set<T>::rbegin;\n\
    \  using set<T>::insert;\n  using set<T>::erase;\n  using set<T>::lower_bound;\n\
    \  using set<T>::upper_bound;\n  \n  T mn()const{ assert(size());return *begin();\
    \ }\n  T mx()const{ assert(size());return *rbegin(); }\n  \n  T pop_front(){\n\
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
    \  }\n};\n"
  code: "template<typename T>\nstruct Set:set<T>{\n  using set<T>::size;\n  using\
    \ set<T>::begin;\n  using set<T>::rbegin;\n  using set<T>::insert;\n  using set<T>::erase;\n\
    \  using set<T>::lower_bound;\n  using set<T>::upper_bound;\n  \n  T mn()const{\
    \ assert(size());return *begin(); }\n  T mx()const{ assert(size());return *rbegin();\
    \ }\n  \n  T pop_front(){\n    assert(size());\n    T mn=*begin();\n    erase(begin());\n\
    \    return mn;\n  }\n  T pop_back(){\n    assert(size());\n    T mx=*rbegin();\n\
    \    erase(mx);\n    return mx;\n  }\n\n  T lt(const T&a)const{\n    assert(mn()<a);\n\
    \    if(mx()<a)return mx();\n    return *--lower_bound(a);\n  }\n  T leq(const\
    \ T&a)const{\n    assert(mn()<=a);\n    if(mx()<=a)return mx();\n    return *--upper_bound(a);\n\
    \  }\n  T gt(const T&a)const{\n    assert(mx()>a);\n    return *upper_bound(a);\n\
    \  }\n  T geq(const T&a){\n    assert(mx()>=a);\n    return *lower_bound(a);\n\
    \  }\n  \n  Set()=default;\n  Set(const vector<T>&v){ for(const auto&p:v)insert(p);\
    \ }\n  \n  void scan(int n){\n    while(n--){\n      T a;cin>>a;\n      insert(a);\n\
    \    }\n  }\n  \n  void banpei(){\n    insert(numeric_limits<T>::max()/2);\n \
    \   insert(numeric_limits<T>::min()/2);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/superstd/Set.cpp
  requiredBy: []
  timestamp: '2023-12-10 20:25:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PredecessorProblem.test.cpp
documentation_of: library/superstd/Set.cpp
layout: document
redirect_from:
- /library/library/superstd/Set.cpp
- /library/library/superstd/Set.cpp.html
title: library/superstd/Set.cpp
---
