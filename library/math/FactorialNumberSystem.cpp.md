---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/algebra/group/Concepts.cpp
    title: library/algebra/group/Concepts.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  - icon: ':question:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.cpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#pragma once\n#include \"library/datastructure/FenwickTree.cpp\"\nnamespace\
    \ factorial_number_system {\n// std::vector<int> \u3067\u8868\u3059\n// v[i]*i!\
    \ \u306E\u7DCF\u548C\u3092\u8868\u73FE\u3057\u3066\u3044\u308B(0<=v[i]<=i)\n//\
    \ \u7279\u306B v[0]=0 \u306F\u78BA\u5B9A\n\n// N \u6841\u306E\u968E\u4E57\u9032\
    \u6570 K \u306B\u5BFE\u3057\u3066\u3001N \u306E\u9806\u5217\u3067 0-indexed K\
    \ \u756A\u76EE\u3092\u8FD4\u3059\nstatic std::vector<int> to_permutation(const\
    \ std::vector<int> &v) {\n    int N = v.size();\n    std::vector<int> p(N);\n\
    \    FenwickTree<GroupAdd<int>> ft(vector<int>(N, 1));\n    for (int i = 0; i\
    \ < N; i++) {\n        p[i] = ft.kth(v[N - 1 - i]);\n        ft.add(p[i], -1);\n\
    \    }\n    return p;\n}\n\n// N \u306E\u9806\u5217\u304C 0-indexed K \u756A\u76EE\
    \u3067\u3042\u308B\u3068\u304D\u3001N \u6841\u306E\u968E\u4E57\u9032\u6570 K \u3092\
    \u8FD4\u3059\nstatic std::vector<int> to_factorial(const std::vector<int> &p)\
    \ {\n    int N = p.size();\n    std::vector<int> v(N);\n    FenwickTree<GroupAdd<int>>\
    \ ft(vector<int>(N, 1));\n    for (int i = 0; i < N; i++) {\n        int k = ft.sum(p[i]);\n\
    \        v[N - 1 - i] = k;\n        ft.add(p[i], -1);\n    }\n    return v;\n\
    }\n\n// N \u6841\u306E\u968E\u4E57\u9032\u6570\u306E\u548C mod N!\nstd::vector<int>\
    \ sum(vector<int> p, const std::vector<int> &q) {\n    int N = p.size();\n   \
    \ assert(q.size() == N);\n    for (int i = 0; i < N; i++) {\n        p[i] += q[i];\n\
    \        if (p[i] > i) {\n            p[i] -= i + 1;\n            if (i + 1 <\
    \ N)\n                p[i + 1]++;\n        }\n    }\n    return p;\n}\n\n// sum(p,q)=0\
    \ \u3068\u306A\u308B q \u3092\u8FD4\u3059\nstd::vector<int> inv(vector<int> p)\
    \ {\n    int N = p.size();\n    std::vector<int> q(N);\n    for (int i = 0; i\
    \ < N; i++) {\n        if (p[i]) {\n            q[i] = i + 1 - p[i];\n       \
    \     if (i + 1 < N)\n                p[i + 1]++;\n        } else\n          \
    \  q[i] = 0;\n    }\n    return q;\n}\n} // namespace factorial_number_system\n"
  dependsOn:
  - library/datastructure/FenwickTree.cpp
  - library/algebra/group/Add.cpp
  - library/algebra/group/Concepts.cpp
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: false
  path: library/math/FactorialNumberSystem.cpp
  requiredBy: []
  timestamp: '2024-04-13 18:08:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/FactorialNumberSystem.cpp
layout: document
redirect_from:
- /library/library/math/FactorialNumberSystem.cpp
- /library/library/math/FactorialNumberSystem.cpp.html
title: library/math/FactorialNumberSystem.cpp
---
