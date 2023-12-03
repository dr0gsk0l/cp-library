---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/mod/CompositeMintUtility.cpp\"\n// set_mod \u3088\
    \u308A\u5F8C\u3067\u5BA3\u8A00\u3059\u308B\ntemplate<typename MINT>\nclass MintUtility{\n\
    \  vector<vector<MINT>> nCk_{vector<MINT>{1}};\n  int S=1;\n\n  void extend(const\
    \ int n){\n    if(n<S)return;\n    const int preS=S;\n    do{S<<=1;}while(S<=n);\n\
    \n    nCk_.resize(S);\n    for(int i=preS;i<S;i++){\n      nCk_[i].resize(i/2+1);\n\
    \      nCk_[i][0]=1;\n      for(int j=1;j<=i/2;j++)nCk_[i][j]=nCk_[i-1][min(j,i-1-j)]+nCk_[i-1][min(j-1,i-1-(j-1))];\n\
    \    }\n  }\npublic:\n  MINT nCk(int n,int k){\n    if(k<0 || n<k)return 0;\n\
    \    extend(n);\n    return nCk_[n][min(k,n-k)];\n  }\n};\n"
  code: "#pragma once\n// set_mod \u3088\u308A\u5F8C\u3067\u5BA3\u8A00\u3059\u308B\
    \ntemplate<typename MINT>\nclass MintUtility{\n  vector<vector<MINT>> nCk_{vector<MINT>{1}};\n\
    \  int S=1;\n\n  void extend(const int n){\n    if(n<S)return;\n    const int\
    \ preS=S;\n    do{S<<=1;}while(S<=n);\n\n    nCk_.resize(S);\n    for(int i=preS;i<S;i++){\n\
    \      nCk_[i].resize(i/2+1);\n      nCk_[i][0]=1;\n      for(int j=1;j<=i/2;j++)nCk_[i][j]=nCk_[i-1][min(j,i-1-j)]+nCk_[i-1][min(j-1,i-1-(j-1))];\n\
    \    }\n  }\npublic:\n  MINT nCk(int n,int k){\n    if(k<0 || n<k)return 0;\n\
    \    extend(n);\n    return nCk_[n][min(k,n-k)];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/CompositeMintUtility.cpp
  requiredBy: []
  timestamp: '2023-12-03 16:05:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mod/CompositeMintUtility.cpp
layout: document
redirect_from:
- /library/library/mod/CompositeMintUtility.cpp
- /library/library/mod/CompositeMintUtility.cpp.html
title: library/mod/CompositeMintUtility.cpp
---
