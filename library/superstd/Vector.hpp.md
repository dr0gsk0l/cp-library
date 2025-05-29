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
  bundledCode: "#line 2 \"library/superstd/Vector.hpp\"\ntemplate <typename T> class\
    \ Vector {\n    int m;\n    std::vector<T> v;\n\n    Vector() = default;\n   \
    \ Vector(int n, T x = {}) : v(n, x), m(0) {}\n    Vector(int L, int R, T x) :\
    \ v(L + R, x), m(L) {}\n};\n"
  code: "#pragma once\ntemplate <typename T> class Vector {\n    int m;\n    std::vector<T>\
    \ v;\n\n    Vector() = default;\n    Vector(int n, T x = {}) : v(n, x), m(0) {}\n\
    \    Vector(int L, int R, T x) : v(L + R, x), m(L) {}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/superstd/Vector.hpp
  requiredBy: []
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/superstd/Vector.hpp
layout: document
redirect_from:
- /library/library/superstd/Vector.hpp
- /library/library/superstd/Vector.hpp.html
title: library/superstd/Vector.hpp
---
