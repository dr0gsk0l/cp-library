---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/formalpowerseries/Base.cpp
    title: library/formalpowerseries/Base.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Inv.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include <library/formalpowerseries/Base.cpp>\n\
    \n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace atcoder;\n\
    using mint=modint998244353;\nostream& operator<<(ostream &os,mint a){os<<a.val();return\
    \ os;}\nistream& operator>>(istream &is,mint &a){\n  long long b;is>>b;a=b;\n\
    \  return is;\n}\n\nusing FPS=FormalPowerSeries<mint,500000>;\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n;cin>>n;\n  FPS\
    \ f(n);\n  for(int i=0;i<n;i++)cin>>f[i];\n  auto g=f.inv();\n  for(int i=0;i<n;i++)cout<<g[i]<<\"\
    \\n \"[i+1<n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <library/formalpowerseries/Base.cpp>\n\
    \n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace atcoder;\n\
    using mint=modint998244353;\nostream& operator<<(ostream &os,mint a){os<<a.val();return\
    \ os;}\nistream& operator>>(istream &is,mint &a){\n  long long b;is>>b;a=b;\n\
    \  return is;\n}\n\nusing FPS=FormalPowerSeries<mint,500000>;\n\nint main(){\n\
    \  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n;cin>>n;\n  FPS\
    \ f(n);\n  for(int i=0;i<n;i++)cin>>f[i];\n  auto g=f.inv();\n  for(int i=0;i<n;i++)cout<<g[i]<<\"\
    \\n \"[i+1<n];\n}"
  dependsOn:
  - library/formalpowerseries/Base.cpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/Inv.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:38:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Inv.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Inv.test.cpp
- /verify/test/library-checker/Polynomial/Inv.test.cpp.html
title: test/library-checker/Polynomial/Inv.test.cpp
---
