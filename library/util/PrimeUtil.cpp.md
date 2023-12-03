---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_1_C.test.cpp
    title: test/AOJ/ALDS1_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://twitter.com/climpet/status/1598974781138694144
  bundledCode: "#line 2 \"library/util/PrimeUtil.cpp\"\n// \u5BA3\u8A00\u306F\u30B0\
    \u30ED\u30FC\u30D0\u30EB\u3067\u3059\u308B\n// https://twitter.com/climpet/status/1598974781138694144\n\
    template<int MAX,bool PRIME_FACTOR=false,bool DIVISOR=false>\nclass PrimeUtil{\n\
    \  using ll=long long;\n  array<bool,MAX+1> isP;\n  static ll pow2(ll a){ return\
    \ a*a; }\npublic:\n  vector<int> primes;\n  conditional_t< PRIME_FACTOR, array<\
    \ vector<pair<int,int>>, MAX+1 >, bool> prime_factor;\n  conditional_t< DIVISOR,\
    \ array< vector<int>,MAX+1 >, bool> divisor; // \u81EA\u660E\u306A\u7D04\u6570\
    \u306F\u5165\u3089\u306A\u3044\n  \n  PrimeUtil(){\n    fill(isP.begin(),isP.end(),true);\n\
    \    isP[0]=isP[1]=false;\n    primes.reserve(MAX/10);\n    for(int i=2;i<=MAX;i++){\n\
    \      // \u7D04\u6570\u5217\u6319\n      if constexpr(DIVISOR){\n        for(int\
    \ j=2*i;j<=MAX;j+=i)\n          divisor[j].push_back(i);\n      }\n      // \u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n      if(!isP[i])continue;\n\
    \      primes.push_back(i);\n      for(ll j=pow2(i);j<=MAX;j+=i)isP[j]=false;\n\
    \      // \u7D20\u56E0\u6570\u5206\u89E3\n      if constexpr(PRIME_FACTOR){\n\
    \        for(int j=i;j<=MAX;j+=i)prime_factor[j].emplace_back(i,1);\n        int\
    \ limit=MAX/i+1;\n        for(ll j=pow2(i);j<=MAX;j*=i){\n          for(int k=j;k<=MAX;k+=j)\n\
    \            prime_factor[k].back().second++;\n          if(j>limit)break;\n \
    \       }\n      }\n    }\n  }\n\n  bool is_prime(ll x){\n    if(x<=MAX)return\
    \ isP[x];\n    for(int p:primes){\n      if(pow2(p)>x)return true;\n      if(x%p==0)return\
    \ false;\n    }\n    for(int p=primes.back()+1;pow2(p)<=x;p++)\n      if(x%p==0)return\
    \ false;\n    return true;\n  }\n};\n"
  code: "#pragma once\n// \u5BA3\u8A00\u306F\u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u3059\
    \u308B\n// https://twitter.com/climpet/status/1598974781138694144\ntemplate<int\
    \ MAX,bool PRIME_FACTOR=false,bool DIVISOR=false>\nclass PrimeUtil{\n  using ll=long\
    \ long;\n  array<bool,MAX+1> isP;\n  static ll pow2(ll a){ return a*a; }\npublic:\n\
    \  vector<int> primes;\n  conditional_t< PRIME_FACTOR, array< vector<pair<int,int>>,\
    \ MAX+1 >, bool> prime_factor;\n  conditional_t< DIVISOR, array< vector<int>,MAX+1\
    \ >, bool> divisor; // \u81EA\u660E\u306A\u7D04\u6570\u306F\u5165\u3089\u306A\u3044\
    \n  \n  PrimeUtil(){\n    fill(isP.begin(),isP.end(),true);\n    isP[0]=isP[1]=false;\n\
    \    primes.reserve(MAX/10);\n    for(int i=2;i<=MAX;i++){\n      // \u7D04\u6570\
    \u5217\u6319\n      if constexpr(DIVISOR){\n        for(int j=2*i;j<=MAX;j+=i)\n\
    \          divisor[j].push_back(i);\n      }\n      // \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\n      if(!isP[i])continue;\n      primes.push_back(i);\n\
    \      for(ll j=pow2(i);j<=MAX;j+=i)isP[j]=false;\n      // \u7D20\u56E0\u6570\
    \u5206\u89E3\n      if constexpr(PRIME_FACTOR){\n        for(int j=i;j<=MAX;j+=i)prime_factor[j].emplace_back(i,1);\n\
    \        int limit=MAX/i+1;\n        for(ll j=pow2(i);j<=MAX;j*=i){\n        \
    \  for(int k=j;k<=MAX;k+=j)\n            prime_factor[k].back().second++;\n  \
    \        if(j>limit)break;\n        }\n      }\n    }\n  }\n\n  bool is_prime(ll\
    \ x){\n    if(x<=MAX)return isP[x];\n    for(int p:primes){\n      if(pow2(p)>x)return\
    \ true;\n      if(x%p==0)return false;\n    }\n    for(int p=primes.back()+1;pow2(p)<=x;p++)\n\
    \      if(x%p==0)return false;\n    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/PrimeUtil.cpp
  requiredBy: []
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_1_C.test.cpp
documentation_of: library/util/PrimeUtil.cpp
layout: document
redirect_from:
- /library/library/util/PrimeUtil.cpp
- /library/library/util/PrimeUtil.cpp.html
title: library/util/PrimeUtil.cpp
---
