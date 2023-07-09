---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Composition.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <formalpowerseries/Base.cpp>\n\
    \n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace atcoder;\n\
    using mint=modint998244353;\nostream& operator<<(ostream &os,mint a){os<<a.val();return\
    \ os;}\nistream& operator>>(istream &is,mint &a){\n  long long b;is>>b;a=b;\n\
    \  return is;\n}\n\nusing FPS=FormalPowerSeries<mint,8000>;\n\nint main(){\n \
    \ ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n;cin>>n;\n  FPS\
    \ f(n),g(n);\n  for(int i=0;i<n;i++)cin>>f[i];\n  for(int i=0;i<n;i++)cin>>g[i];\n\
    \  f=f(g);\n  for(int i=0;i<n;i++)cout<<f[i]<<\"\\n \"[i+1<n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <formalpowerseries/Base.cpp>\n\
    \n#include <atcoder/modint>\n#include <atcoder/convolution>\nusing namespace atcoder;\n\
    using mint=modint998244353;\nostream& operator<<(ostream &os,mint a){os<<a.val();return\
    \ os;}\nistream& operator>>(istream &is,mint &a){\n  long long b;is>>b;a=b;\n\
    \  return is;\n}\n\nusing FPS=FormalPowerSeries<mint,8000>;\n\nint main(){\n \
    \ ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n;cin>>n;\n  FPS\
    \ f(n),g(n);\n  for(int i=0;i<n;i++)cin>>f[i];\n  for(int i=0;i<n;i++)cin>>g[i];\n\
    \  f=f(g);\n  for(int i=0;i<n;i++)cout<<f[i]<<\"\\n \"[i+1<n];\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Polynomial/Composition.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:09:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Composition.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Composition.test.cpp
- /verify/test/library-checker/Polynomial/Composition.test.cpp.html
title: test/library-checker/Polynomial/Composition.test.cpp
---
