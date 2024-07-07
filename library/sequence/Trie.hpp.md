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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/group/Add.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/algebra/group/Add.cpp\"\n#include \"library/sequence/ForString.cpp\"\
    \ntemplate <typename CHAR, int SIGMA, typename AbelMonoid = GroupAdd<int>>\nclass\
    \ Trie {\n  protected:\n    using X = typename AbelMonoid::value_type;\n    struct\
    \ Node {\n        std::array<int, SIGMA> nxt;\n        int pre;\n        X val,\
    \ suffix_val; // suffix_val \u306F\u81EA\u8EAB\u3092\u542B\u307E\u306A\u3044\n\
    \        Node(int pre)\n            : pre(pre), val(AbelMonoid::unit()),\n   \
    \           suffix_val(AbelMonoid::unit()) {\n            std::ranges::fill(nxt,\
    \ -1);\n        }\n    };\n    std::vector<Node> nodes;\n\n  public:\n    Trie()\
    \ : nodes(1, Node(-1)) {}\n\n    int &nxt(int now, const CHAR &a) { return nodes[now].nxt[a];\
    \ }\n    const int &nxt(int now, const CHAR &a) const { return nodes[now].nxt[a];\
    \ }\n\n    int add(const std::vector<CHAR> &v, X x = 1) {\n        int now = 0;\n\
    \        for (const CHAR &a : v) {\n            assert(0 <= a and a < SIGMA);\n\
    \            if (!~nxt(now, a)) {\n                nxt(now, a) = nodes.size();\n\
    \                nodes.emplace_back(now);\n            }\n            AbelMonoid::Rchop(nodes[now].suffix_val,\
    \ x);\n            now = nxt(now, a);\n        }\n        AbelMonoid::Rchop(nodes[now].val,\
    \ x);\n        return now;\n    }\n    int node_idx(const std::vector<CHAR> &v)\
    \ const {\n        // s \u306E Node \u3092\u8FD4\u3059\u3000\u8FFD\u52A0\u3055\
    \u308C\u3066\u7121\u3051\u308C\u3070 -1\n        int now = 0;\n        for (const\
    \ CHAR &a : v) {\n            if (!~nxt(now, a))\n                return -1;\n\
    \            now = nxt(now, a);\n        }\n        return now;\n    }\n    X\
    \ val(const std::vector<CHAR> &v) {\n        int id = node_idx(v);\n        return\
    \ (~id ? nodes[id].val : AbelMonoid::unit());\n    }\n    X &val(int node_id)\
    \ { return nodes[node_id].val; }\n    // v\u306F\u542B\u307E\u306A\u3044\n   \
    \ X prefix_prod(const std::vector<CHAR> &v) {\n        int now = 0;\n        X\
    \ sum = AbelMonoid::unit();\n        for (const CHAR &a : v) {\n            if\
    \ (!~nxt(now, a))\n                break;\n            AbelMonoid::Rchop(sum,\
    \ nodes[now].val);\n            now = nxt(now, a);\n        }\n        return\
    \ sum;\n    }\n    // v\u306F\u542B\u307E\u306A\u3044\n    X suffix_prod(const\
    \ std::vector<CHAR> &v) const {\n        int id = node_idx(v);\n        return\
    \ (~id ? nodes[id].suffix_val : AbelMonoid::unit());\n    }\n    std::vector<CHAR>\
    \ restore(int node_id) {\n        assert(0 <= node_id and node_id < nodes.size());\n\
    \        std::vector<CHAR> res;\n        while (~nodes[node_id].pre) {\n     \
    \       int pre = nodes[node_id].pre;\n            for (int j = 0; j < SIGMA;\
    \ j++)\n                if (nxt(pre, j) == node_id) {\n                    res.push_back(j);\n\
    \                    break;\n                }\n            node_id = pre;\n \
    \       }\n        std::ranges::reverse(res);\n        return res;\n    }\n  \
    \  X prod() const { return nodes[0].suffix_val; }\n    int size() const { return\
    \ nodes.size(); }\n\n    template <typename F>\n    void query(const std::vector<CHAR>\
    \ &v, const F &f, int l = 0, int r = -1) {\n        if (r < 0)\n            r\
    \ = v.size();\n        int now = 0;\n        for (int i = l; i < r; i++) {\n \
    \           now = nxt(now, v[i]);\n            if (~now)\n                f(now);\n\
    \            else\n                break;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/Trie.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/Trie.hpp
layout: document
redirect_from:
- /library/library/sequence/Trie.hpp
- /library/library/sequence/Trie.hpp.html
title: library/sequence/Trie.hpp
---
