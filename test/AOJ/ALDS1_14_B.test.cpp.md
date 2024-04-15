---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/mod/Modint61.cpp
    title: library/mod/Modint61.cpp
  - icon: ':question:'
    path: library/sequence/ForString.cpp
    title: library/sequence/ForString.cpp
  - icon: ':x:'
    path: library/sequence/RollingHash.cpp
    title: library/sequence/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/sequence/RollingHash.cpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/sequence/RollingHash.cpp\"\n\n\
    int main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    std::string t;\n    std::cin >> t;\n    RollingHash RH(FSa::change(t));\n\
    \n    std::string p;\n    std::cin >> p;\n    auto h = RollingHash<char>::full_hash(FSa::change(p));\n\
    \n    for (int i = 0; i + p.size() <= t.size(); i++)\n        if (RH.get_hash(i,\
    \ i + p.size()) == h)\n            std::cout << i << \"\\n\";\n}"
  dependsOn:
  - library/sequence/RollingHash.cpp
  - library/mod/Modint61.cpp
  - library/sequence/ForString.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_14_B.test.cpp
- /verify/test/AOJ/ALDS1_14_B.test.cpp.html
title: test/AOJ/ALDS1_14_B.test.cpp
---
