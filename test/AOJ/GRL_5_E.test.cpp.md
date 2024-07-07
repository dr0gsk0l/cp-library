---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/lazy/AddSum.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include \"library/algebra/lazy/AddSum.cpp\"\n#include \"library/tree/Tree.cpp\"\
    \n#include \"library/tree/TreeLazy.cpp\"\nusing ll = long long;\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int n;\n    std::cin >> n;\n\n    Tree t(n);\n    REP (i, n) {\n        int\
    \ k;\n        std::cin >> k;\n        REP (_, k) {\n            int c;\n     \
    \       std::cin >> c;\n            t.add_edge(i, c);\n        }\n    }\n    t.build(0);\n\
    \n    TreeLazy<Tree, LazyAddSum<ll>> TL(t, cnt_init(n, 0LL));\n    // \u8FBA\u306E\
    \u60C5\u5831\u306F\u5B50\u306B\u6301\u305F\u305B\u308B\n    // \u5404\u9802\u70B9\
    \ v \u306B\u3064\u3044\u3066\u3001\u6839\u304B\u3089 1 \u79FB\u52D5\u3057\u305F\
    \u70B9\u304C\u5FC5\u8981\n    // Tree \u306B jump \u3092\u5B9F\u88C5\u3057\u3066\
    \u306A\u3044\u306E\u3067\u7121\u7406\u304F\u308A\u6C42\u3081\u308B\n    std::vector<int>\
    \ root2(n, -1);\n    for (int v : t.BFS) {\n        if (v == 0)\n            continue;\n\
    \        int p = t.parent(v).to;\n        if (p == 0)\n            root2[v] =\
    \ v;\n        else\n            root2[v] = root2[p];\n    }\n\n    int q;\n  \
    \  std::cin >> q;\n    REP (_, q) {\n        int c;\n        std::cin >> c;\n\
    \        if (c) {\n            int u;\n            std::cin >> u;\n          \
    \  std::cout << TL.path_prod(u, root2[u]).first << \"\\n\";\n        } else {\n\
    \            int v, w;\n            std::cin >> v >> w;\n            TL.path_apply(v,\
    \ root2[v], w);\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/GRL_5_E.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_E.test.cpp
- /verify/test/AOJ/GRL_5_E.test.cpp.html
title: test/AOJ/GRL_5_E.test.cpp
---
