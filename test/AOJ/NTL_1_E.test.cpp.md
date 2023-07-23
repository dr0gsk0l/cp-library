---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/AOJ/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/math/ExtraGCD.cpp\"\
    \nusing ll=long long;\npair<ll,ll> ext_gcd(ll a,ll b){\n  if(b==0)return {1,0};\n\
    \  auto [X,Y]=ext_gcd(b,a%b);\n  // bX + (a%b)Y = gcd(a,b)\n  // a%b = a - b(a/b)\n\
    \  // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n  ll x=Y,y=X-(a/b)*Y;\n  return {x,y};\n\
    }\n#line 6 \"test/AOJ/NTL_1_E.test.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int a,b;cin>>a>>b;\n  auto [x,y]=ext_gcd(a,b);\n  cout<<x<<\"\
    \ \"<<y<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/math/ExtraGCD.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int\
    \ a,b;cin>>a>>b;\n  auto [x,y]=ext_gcd(a,b);\n  cout<<x<<\" \"<<y<<endl;\n}"
  dependsOn:
  - library/math/ExtraGCD.cpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_E.test.cpp
- /verify/test/AOJ/NTL_1_E.test.cpp.html
title: test/AOJ/NTL_1_E.test.cpp
---