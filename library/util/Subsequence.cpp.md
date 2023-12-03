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
  timestamp: '2023-12-03 14:54:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/New/NumberOfSubsequence.test.cpp
documentation_of: library/util/Subsequence.cpp
layout: document
title: "\u90E8\u5206\u5217\u306E\u7A2E\u985E\u6570"
---

配列の（非連続を許す）部分列の種類数を求める
* ```<T,SIZE> T subsequence(const vector<int>&v)```  
要素が $[0,SIZE)$ であるような配列 $v$ に対して求める  
時間 $O(|v|)$  
空間 $O(SIZE)$

* ```<T> T subsequence_alphabet(const string&s)```  
英小文字のみ or 英大文字のみからなる文字列 $s$ に対して求める
時間 $O(|s|)$  
空間 $O(1)$

* ```<T,U> T sparse_subsequence(const vector<U>&v)```  
一般の配列 $v$ に対して求める  
時間 $O(|v|\log|v|)$  
空間 $O(|v|)$  
map を使うので $U$ に $<$ が定義されている必要がある  
あらかじめ $v$ の要素を座圧して ```subsequence``` に投げるのと本質的には同じ
