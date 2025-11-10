---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
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
  bundledCode: "#line 1 \"test/AOJ/NTL_1_E.test.cpp\"\n#define PROBLEM           \
    \                                                     \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/math/ExtraGCD.hpp\"\nusing ll\
    \ = long long;\nstd::pair<ll, ll> ext_gcd(ll a, ll b) {\n    if (b == 0)\n   \
    \     return {1, 0};\n    auto [X, Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y\
    \ = gcd(a,b)\n    // a%b = a - b(a/b)\n    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n\
    \    ll x = Y, y = X - (a / b) * Y;\n    return {x, y};\n}\n#line 6 \"test/AOJ/NTL_1_E.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int a, b;\n    std::cin >> a >> b;\n    auto [x, y] = ext_gcd(a, b);\n \
    \   std::cout << x << \" \" << y << std::endl;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/math/ExtraGCD.hpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int a, b;\n    std::cin >> a >> b;\n    auto [x, y] = ext_gcd(a, b);\n    std::cout\
    \ << x << \" \" << y << std::endl;\n}"
  dependsOn:
  - library/math/ExtraGCD.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_E.test.cpp
- /verify/test/AOJ/NTL_1_E.test.cpp.html
title: test/AOJ/NTL_1_E.test.cpp
---
