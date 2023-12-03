---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/library-checker/Math/2Sat.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#include <atcoder/twosat>\nusing namespace atcoder;\n\nint\
    \ main(){\n  string hoge;cin>>hoge>>hoge;\n  int n,m;cin>>n>>m;\n  two_sat ts(n);\n\
    \  while(m--){\n    int a,b,c;cin>>a>>b>>c;\n    bool f_a=a>0,f_b=b>0;\n    ts.add_clause(abs(a)-1,f_a,abs(b)-1,f_b);\n\
    \  }\n  if(ts.satisfiable()){\n    cout<<\"s SATISFIABLE\\n\";\n    cout<<\"v\
    \ \";\n    auto A=ts.answer();\n    for(int i=0;i<n;i++)cout<<(A[i]?i+1:-(i+1))<<\"\
    \ \";\n    cout<<\"0\\n\";\n  }\n  else cout<<\"s UNSATISFIABLE\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include <atcoder/twosat>\nusing namespace atcoder;\n\n\
    int main(){\n  string hoge;cin>>hoge>>hoge;\n  int n,m;cin>>n>>m;\n  two_sat ts(n);\n\
    \  while(m--){\n    int a,b,c;cin>>a>>b>>c;\n    bool f_a=a>0,f_b=b>0;\n    ts.add_clause(abs(a)-1,f_a,abs(b)-1,f_b);\n\
    \  }\n  if(ts.satisfiable()){\n    cout<<\"s SATISFIABLE\\n\";\n    cout<<\"v\
    \ \";\n    auto A=ts.answer();\n    for(int i=0;i<n;i++)cout<<(A[i]?i+1:-(i+1))<<\"\
    \ \";\n    cout<<\"0\\n\";\n  }\n  else cout<<\"s UNSATISFIABLE\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Math/2Sat.test.cpp
  requiredBy: []
  timestamp: '2023-12-03 15:49:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Math/2Sat.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Math/2Sat.test.cpp
- /verify/test/library-checker/Math/2Sat.test.cpp.html
title: test/library-checker/Math/2Sat.test.cpp
---
