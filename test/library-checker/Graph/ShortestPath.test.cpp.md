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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/WeightedGraph.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"library/graph/WeightedGraph.cpp\"\n#include \"\
    library/graph/shortest_path/Dijkstra.cpp\"\n\nusing ll = long long;\n\nint main()\
    \ {\n    int n, m, s, t;\n    std::cin >> n >> m >> s >> t;\n    WeightedGraph<ll>\
    \ g(n, m, true, 0);\n    auto [d, pre] = dijkstra(g, s);\n\n    std::cout << d[t];\n\
    \    if (d[t] < 0) {\n        std::cout << \"\\n\";\n        return 0;\n    }\n\
    \n    std::vector<std::pair<int, int>> ans;\n    while (t != s) {\n        ans.emplace_back(pre[t],\
    \ t);\n        t = pre[t];\n    }\n    std::ranges::reverse(ans);\n    std::cout\
    \ << \" \" << ans.size() << \"\\n\";\n    for (const auto &[from, to] : ans)\n\
    \        std::cout << from << \" \" << to << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Graph/ShortestPath.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Graph/ShortestPath.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Graph/ShortestPath.test.cpp
- /verify/test/library-checker/Graph/ShortestPath.test.cpp.html
title: test/library-checker/Graph/ShortestPath.test.cpp
---
