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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/sequence/Trie.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/sequence/Trie.cpp\"\ntemplate <typename\
    \ CHAR, int SIGMA, typename AbelMonoid = GroupAdd<int>>\nclass AhoCorasick : Trie<CHAR,\
    \ SIGMA, AbelMonoid> {\n    using super = Trie<CHAR, SIGMA, AbelMonoid>;\n   \
    \ using super::nodes;\n    using X = typename AbelMonoid::value_type;\n    std::vector<int>\
    \ suffix;\n    bool prepared;\n\n  public:\n    using super::nxt, super::add,\
    \ super::node_idx, super::val,\n        super::prefix_prod, super::suffix_prod,\
    \ super::query, super::restore,\n        super::prod, super::size;\n\n    AhoCorasick()\
    \ : prepared(false) {}\n\n    bool is_prepared() const { return prepared; }\n\n\
    \    void build() {\n        assert(!prepared);\n        prepared = true;\n  \
    \      suffix.resize(nodes.size());\n        std::queue<int> que;\n        que.push(0);\n\
    \        while (que.size()) {\n            int now = que.front();\n          \
    \  que.pop();\n            for (int i = 0; i < SIGMA; i++) {\n               \
    \ int &nxt_id = nodes[now].nxt[i];\n                if (~nxt_id) {\n         \
    \           suffix[nxt_id] = (now ? nodes[suffix[now]].nxt[i] : 0);\n        \
    \            AbelMonoid::Rchop(val(nxt_id), val(suffix[nxt_id]));\n          \
    \          que.push(nxt_id);\n                } else\n                    nxt_id\
    \ = (now ? nodes[suffix[now]].nxt[i] : 0);\n            }\n        }\n    }\n\n\
    \    X path_prod(const std::vector<CHAR> &v) {\n        assert(prepared);\n  \
    \      X res = AbelMonoid::unit();\n        int now = 0;\n        for (const CHAR\
    \ &a : v) {\n            now = nxt(now, a);\n            AbelMonoid::Rchop(res,\
    \ val(now));\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/AhoCorasick.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/AhoCorasick.hpp
layout: document
redirect_from:
- /library/library/sequence/AhoCorasick.hpp
- /library/library/sequence/AhoCorasick.hpp.html
title: library/sequence/AhoCorasick.hpp
---
