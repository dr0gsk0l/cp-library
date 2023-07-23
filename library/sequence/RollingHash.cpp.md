---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/mod/Modint61.cpp
    title: library/mod/Modint61.cpp
  - icon: ':heavy_check_mark:'
    path: library/sequence/ForString.cpp
    title: library/sequence/ForString.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/sequence/RollingHash.cpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n#pragma\
    \ once\n#include \"library/mod/Modint61.cpp\"\n#include \"library/sequence/ForString.cpp\"\
    \n\nrandom_device rollonghash_rnd;\nmt19937 rollonghash_mt(rollonghash_rnd());\n\
    \ntemplate<typename CHAR=char,typename MINT=Modint61>\nclass RollingHash{\n  using\
    \ ll=long long;\n  static constexpr ll mod = (1LL<<61)-1;\n  //using T = conditional_t<\
    \ less<ll>(mod,ll(numeric_limits<int>::max())), int, ll>;\n  using T=ll;\n  inline\
    \ static const MINT base=MINT::raw(rollonghash_mt()%(mod-2)+2);\n\n  int n;\n\
    \  vector<MINT> hash,power;\npublic:\n  RollingHash(const vector<CHAR>&v):n(v.size()),hash(n+1,0),power(n+1,1){\n\
    \    for(int i=0;i<n;i++){\n      hash[i+1]=nxt_hash(hash[i],v[i]);\n      power[i+1]=power[i]*base;\n\
    \    }\n  }\n  RollingHash()=default;\n\n  static MINT nxt_hash(MINT x,CHAR c){\
    \ return (x*base) + MINT::raw(c); }\n  \n  T get_hash(int l=0,int r=-1){\n   \
    \ if(r<0)r=n;\n    return (hash[r]-hash[l]*power[r-l]).v;\n  }\n  \n  static T\
    \ full_hash(const vector<CHAR>&v){\n    MINT res=0;\n    for(const char&c:v)res=nxt_hash(res,c);\n\
    \    return res.v;\n  }\n};"
  dependsOn:
  - library/mod/Modint61.cpp
  - library/sequence/ForString.cpp
  isVerificationFile: false
  path: library/sequence/RollingHash.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: library/sequence/RollingHash.cpp
layout: document
redirect_from:
- /library/library/sequence/RollingHash.cpp
- /library/library/sequence/RollingHash.cpp.html
title: library/sequence/RollingHash.cpp
---
