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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/group/Affine.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/algebra/group/Affine.cpp\"\n\
    #include \"library/mod/Modint.cpp\"\n#include \"library/tree/Tree.cpp\"\n#include\
    \ \"library/tree/TreeMonoid.cpp\"\nusing mint = Mint<long long>;\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    using\
    \ G = AlgebraReverse<GroupAffine<mint>>;\n    using F = G::value_type;\n\n   \
    \ int n, q;\n    std::cin >> n >> q;\n\n    std::vector<F> f(n);\n    for (int\
    \ i = 0; i < n; i++)\n        std::cin >> f[i];\n\n    Tree t(n);\n    t.scan(0);\n\
    \n    TreeMonoid<Tree, G> TM(t, f);\n\n    while (q--) {\n        int c;\n   \
    \     std::cin >> c;\n        if (c) {\n            int u, v, x;\n           \
    \ std::cin >> u >> v >> x;\n            F g = TM.path_prod(u, v);\n          \
    \  std::cout << g(x) << std::endl;\n        } else {\n            int p;\n   \
    \         std::cin >> p;\n            F f;\n            std::cin >> f;\n     \
    \       TM.set(p, f);\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Tree/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/vertex_set_path_composite.test.cpp
- /verify/test/library-checker/Tree/vertex_set_path_composite.test.cpp.html
title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
---
