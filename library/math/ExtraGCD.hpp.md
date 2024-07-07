---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/ExtraGCD.hpp\"\nusing ll = long long;\nstd::pair<ll,\
    \ ll> ext_gcd(ll a, ll b) {\n    if (b == 0)\n        return {1, 0};\n    auto\
    \ [X, Y] = ext_gcd(b, a % b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b = a -\
    \ b(a/b)\n    // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X - (a\
    \ / b) * Y;\n    return {x, y};\n}\n"
  code: "#pragma once\nusing ll = long long;\nstd::pair<ll, ll> ext_gcd(ll a, ll b)\
    \ {\n    if (b == 0)\n        return {1, 0};\n    auto [X, Y] = ext_gcd(b, a %\
    \ b);\n    // bX + (a%b)Y = gcd(a,b)\n    // a%b = a - b(a/b)\n    // \u2234 aY\
    \ + b(X-(a/b)Y) = gcd(a,b)\n    ll x = Y, y = X - (a / b) * Y;\n    return {x,\
    \ y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/ExtraGCD.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/ExtraGCD.hpp
layout: document
redirect_from:
- /library/library/math/ExtraGCD.hpp
- /library/library/math/ExtraGCD.hpp.html
title: library/math/ExtraGCD.hpp
---
