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
  attributes: {}
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Pow.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include <library/formalpowerseries/Base.cpp>\n\
    \n#include <library/atcoder/modint>\n#include <library/atcoder/convolution>\n\
    using namespace atcoder;\nusing mint=modint998244353;\nostream& operator<<(ostream\
    \ &os,mint a){os<<a.val();return os;}\nistream& operator>>(istream &is,mint &a){\n\
    \  long long b;is>>b;a=b;\n  return is;\n}\n\nusing FPS=FormalPowerSeries<mint,500000>;\n\
    \nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int\
    \ n;\n  long long m;\n  cin>>n>>m;\n  FPS f(n);\n  for(int i=0;i<n;i++)cin>>f[i];\n\
    \  f=f.pow(m);\n  for(int i=0;i<n;i++)cout<<(i<f.size()?f[i]:0)<<\"\\n \"[i+1<n];\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <library/formalpowerseries/Base.cpp>\n\
    \n#include <library/atcoder/modint>\n#include <library/atcoder/convolution>\n\
    using namespace atcoder;\nusing mint=modint998244353;\nostream& operator<<(ostream\
    \ &os,mint a){os<<a.val();return os;}\nistream& operator>>(istream &is,mint &a){\n\
    \  long long b;is>>b;a=b;\n  return is;\n}\n\nusing FPS=FormalPowerSeries<mint,500000>;\n\
    \nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int\
    \ n;\n  long long m;\n  cin>>n>>m;\n  FPS f(n);\n  for(int i=0;i<n;i++)cin>>f[i];\n\
    \  f=f.pow(m);\n  for(int i=0;i<n;i++)cout<<(i<f.size()?f[i]:0)<<\"\\n \"[i+1<n];\n\
    }"
  dependsOn:
  - library/formalpowerseries/Base.cpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/Pow.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 23:12:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Pow.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Pow.test.cpp
- /verify/test/library-checker/Polynomial/Pow.test.cpp.html
title: test/library-checker/Polynomial/Pow.test.cpp
---
