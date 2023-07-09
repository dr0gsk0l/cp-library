---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/New/NumberOfSubsequence.test.cpp
    title: test/library-checker/New/NumberOfSubsequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/Subsequence.cpp\"\ntemplate<typename T,typename\
    \ U>\nT sparse_subsequence(const vector<U>&v){\n  map<U,T> mp;\n  T res=1;\n \
    \ for(const U&p:v){\n    T tmp=res;\n    res=res*2-mp[p];\n    mp[p]=tmp;\n  }\n\
    \  return res;\n}\ntemplate<typename T,int SIZE>\nT subsequence(const vector<int>&v){\n\
    \  vector<T> memo(SIZE,0);\n  T res=1;\n  for(int p:v){\n    T tmp=res;\n    res=res*2-memo[p];\n\
    \    memo[p]=tmp;\n  }\n  return res;\n}\ntemplate<typename T>\nT subsequence_alphabet(const\
    \ string&s){\n  vector<int> v;v.reserve(s.size());\n  for(char c:s)v.push_back(c-(c<='Z'?'A':'a'));\n\
    \  return subsequence<T,26>(v);\n}\n"
  code: "template<typename T,typename U>\nT sparse_subsequence(const vector<U>&v){\n\
    \  map<U,T> mp;\n  T res=1;\n  for(const U&p:v){\n    T tmp=res;\n    res=res*2-mp[p];\n\
    \    mp[p]=tmp;\n  }\n  return res;\n}\ntemplate<typename T,int SIZE>\nT subsequence(const\
    \ vector<int>&v){\n  vector<T> memo(SIZE,0);\n  T res=1;\n  for(int p:v){\n  \
    \  T tmp=res;\n    res=res*2-memo[p];\n    memo[p]=tmp;\n  }\n  return res;\n\
    }\ntemplate<typename T>\nT subsequence_alphabet(const string&s){\n  vector<int>\
    \ v;v.reserve(s.size());\n  for(char c:s)v.push_back(c-(c<='Z'?'A':'a'));\n  return\
    \ subsequence<T,26>(v);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/Subsequence.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/New/NumberOfSubsequence.test.cpp
documentation_of: library/util/Subsequence.cpp
layout: document
redirect_from:
- /library/library/util/Subsequence.cpp
- /library/library/util/Subsequence.cpp.html
title: library/util/Subsequence.cpp
---
