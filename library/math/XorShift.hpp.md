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
  bundledCode: "#line 1 \"library/math/XorShift.hpp\"\nclass XorShift{\n  uint64_t\
    \ x;\npublic:\n  XorShift(){\n    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    x=rnd();\n    for(int i=0;i<100;i++)(*this)();\n  }\n  uint64_t operator()(){\n\
    \    x = x^(x<<7);\n    return x = x^(x>>9);\n  }\n};\n"
  code: "class XorShift{\n  uint64_t x;\npublic:\n  XorShift(){\n    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    x=rnd();\n    for(int i=0;i<100;i++)(*this)();\n  }\n  uint64_t operator()(){\n\
    \    x = x^(x<<7);\n    return x = x^(x>>9);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/XorShift.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/XorShift.hpp
layout: document
redirect_from:
- /library/library/math/XorShift.hpp
- /library/library/math/XorShift.hpp.html
title: library/math/XorShift.hpp
---
