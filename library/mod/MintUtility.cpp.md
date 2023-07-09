---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/mod/MintUtility.cpp\"\ntemplate<typename MINT>\n\
    class MintUtility{\n  vector<MINT> fact_={MINT::raw(1)};\n  vector<MINT> inv_fact_{MINT::raw(1)};\n\
    \  int S=1;//\u4ECA\u306E\u30B5\u30A4\u30BA\n\n  void extend(const int n){\n \
    \   if(n<S)return;\n    const int preS=S;\n    do{S<<=1;}while(S<=n);\n\n    fact_.resize(S);\n\
    \    for(int i=preS;i<S;i++)fact_[i]=fact_[i-1]*MINT::raw(i);\n\n    inv_fact_.resize(S);\n\
    \    inv_fact_.back()=fact_.back().inv();\n    for(int i=S-1;i>preS;i--)inv_fact_[i-1]=inv_fact_[i]*MINT::raw(i);\n\
    \  }\npublic:\n  MINT fact(const int n){\n    assert(n>=0);\n    extend(n);\n\
    \    return fact_[n];\n  }\n  MINT inv_fact(const int n){\n    assert(n>=0);\n\
    \    extend(n);\n    return inv_fact_[n];\n  }\n  MINT nCk(const int n,const int\
    \ k){\n    if(k<0||n<k)return MINT::raw(0);\n    extend(n);\n    return fact_[n]\
    \ * inv_fact_[k] * inv_fact_[n - k];\n  }\n  MINT nPk(const int n,const int k){\n\
    \    if(k<0||n<k)return MINT::raw(0);\n    extend(n);\n    return fact_[n] * inv_fact_[n-k];\n\
    \  }\n  MINT nHk(const int n,const int k){\n    return (n==0 and k==0?1:nCk(n+k-1,k));\n\
    \  }\n};\n"
  code: "template<typename MINT>\nclass MintUtility{\n  vector<MINT> fact_={MINT::raw(1)};\n\
    \  vector<MINT> inv_fact_{MINT::raw(1)};\n  int S=1;//\u4ECA\u306E\u30B5\u30A4\
    \u30BA\n\n  void extend(const int n){\n    if(n<S)return;\n    const int preS=S;\n\
    \    do{S<<=1;}while(S<=n);\n\n    fact_.resize(S);\n    for(int i=preS;i<S;i++)fact_[i]=fact_[i-1]*MINT::raw(i);\n\
    \n    inv_fact_.resize(S);\n    inv_fact_.back()=fact_.back().inv();\n    for(int\
    \ i=S-1;i>preS;i--)inv_fact_[i-1]=inv_fact_[i]*MINT::raw(i);\n  }\npublic:\n \
    \ MINT fact(const int n){\n    assert(n>=0);\n    extend(n);\n    return fact_[n];\n\
    \  }\n  MINT inv_fact(const int n){\n    assert(n>=0);\n    extend(n);\n    return\
    \ inv_fact_[n];\n  }\n  MINT nCk(const int n,const int k){\n    if(k<0||n<k)return\
    \ MINT::raw(0);\n    extend(n);\n    return fact_[n] * inv_fact_[k] * inv_fact_[n\
    \ - k];\n  }\n  MINT nPk(const int n,const int k){\n    if(k<0||n<k)return MINT::raw(0);\n\
    \    extend(n);\n    return fact_[n] * inv_fact_[n-k];\n  }\n  MINT nHk(const\
    \ int n,const int k){\n    return (n==0 and k==0?1:nCk(n+k-1,k));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/MintUtility.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/117.test.cpp
documentation_of: library/mod/MintUtility.cpp
layout: document
redirect_from:
- /library/library/mod/MintUtility.cpp
- /library/library/mod/MintUtility.cpp.html
title: library/mod/MintUtility.cpp
---
