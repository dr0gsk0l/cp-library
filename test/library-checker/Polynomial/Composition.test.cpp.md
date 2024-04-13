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
    PROBLEM: https://judge.yosupo.jp/problem/composition_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/composition_of_formal_power_series
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Composition.test.cpp\"\n\
    #define PROBLEM                                                              \
    \  \\\n    \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\n\n#include <library/formalpowerseries/Base.cpp>\n\n\
    #include <atcoder/convolution>\n#include <atcoder/modint>\nusing namespace atcoder;\n\
    using mint = modint998244353;\nstd::ostream &operator<<(std::ostream &os, mint\
    \ a) {\n    os << a.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, mint &a) {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n\
    }\n\nusing FPS = FormalPowerSeries<mint, 8000>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    FPS f(n), g(n);\n\
    \    for (int i = 0; i < n; i++)\n        std::cin >> f[i];\n    for (int i =\
    \ 0; i < n; i++)\n        std::cin >> g[i];\n    f = f(g);\n    for (int i = 0;\
    \ i < n; i++)\n        std::cout << f[i] << \"\\n \"[i + 1 < n];\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/composition_of_formal_power_series\"\
    \n#include <bits/stdc++.h>\n\n#include <library/formalpowerseries/Base.cpp>\n\n\
    #include <atcoder/convolution>\n#include <atcoder/modint>\nusing namespace atcoder;\n\
    using mint = modint998244353;\nstd::ostream &operator<<(std::ostream &os, mint\
    \ a) {\n    os << a.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, mint &a) {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n\
    }\n\nusing FPS = FormalPowerSeries<mint, 8000>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    FPS f(n), g(n);\n\
    \    for (int i = 0; i < n; i++)\n        std::cin >> f[i];\n    for (int i =\
    \ 0; i < n; i++)\n        std::cin >> g[i];\n    f = f(g);\n    for (int i = 0;\
    \ i < n; i++)\n        std::cout << f[i] << \"\\n \"[i + 1 < n];\n}"
  dependsOn:
  - library/formalpowerseries/Base.cpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/Composition.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Composition.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Composition.test.cpp
- /verify/test/library-checker/Polynomial/Composition.test.cpp.html
title: test/library-checker/Polynomial/Composition.test.cpp
---
