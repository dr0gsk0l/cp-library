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
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\n#include\
    \ <atcoder/twosat>\nusing namespace atcoder;\n\nint main() {\n    string hoge;\n\
    \    cin >> hoge >> hoge;\n    int n, m;\n    cin >> n >> m;\n    two_sat ts(n);\n\
    \    while (m--) {\n        int a, b, c;\n        cin >> a >> b >> c;\n      \
    \  bool f_a = a > 0, f_b = b > 0;\n        ts.add_clause(abs(a) - 1, f_a, abs(b)\
    \ - 1, f_b);\n    }\n    if (ts.satisfiable()) {\n        std::cout << \"s SATISFIABLE\\\
    n\";\n        std::cout << \"v \";\n        auto A = ts.answer();\n        for\
    \ (int i = 0; i < n; i++)\n            std::cout << (A[i] ? i + 1 : -(i + 1))\
    \ << \" \";\n        std::cout << \"0\\n\";\n    } else\n        std::cout <<\
    \ \"s UNSATISFIABLE\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include <bits/stdc++.h>\n\
    \n#include <atcoder/twosat>\nusing namespace atcoder;\n\nint main() {\n    string\
    \ hoge;\n    cin >> hoge >> hoge;\n    int n, m;\n    cin >> n >> m;\n    two_sat\
    \ ts(n);\n    while (m--) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        bool f_a = a > 0, f_b = b > 0;\n        ts.add_clause(abs(a) - 1, f_a,\
    \ abs(b) - 1, f_b);\n    }\n    if (ts.satisfiable()) {\n        std::cout <<\
    \ \"s SATISFIABLE\\n\";\n        std::cout << \"v \";\n        auto A = ts.answer();\n\
    \        for (int i = 0; i < n; i++)\n            std::cout << (A[i] ? i + 1 :\
    \ -(i + 1)) << \" \";\n        std::cout << \"0\\n\";\n    } else\n        std::cout\
    \ << \"s UNSATISFIABLE\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Math/2Sat.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 17:39:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Math/2Sat.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Math/2Sat.test.cpp
- /verify/test/library-checker/Math/2Sat.test.cpp.html
title: test/library-checker/Math/2Sat.test.cpp
---
