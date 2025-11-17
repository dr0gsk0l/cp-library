---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/SetXor-Min.test.cpp
    title: test/library-checker/DataStructure/SetXor-Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/BinaryTrie.hpp\"\ntemplate <int LOG,\
    \ typename COUNT> class BinaryTrie {\n    static_assert(LOG <= 64, \"Binary Trie\
    \ overflow\");\n    using T = std::conditional_t<LOG <= 32, unsigned int, unsigned\
    \ long long>;\n    struct Node {\n        std::array<int, 2> nxt_node;\n     \
    \   COUNT count; //\n        Node() : count(0) { std::ranges::fill(nxt_node, -1);\
    \ }\n    };\n    std::vector<Node> nodes;\n    int &nxt(int now, bool f) { return\
    \ nodes[now].nxt_node[f]; }\n    bool bit(const T &a, int i) const { return (a\
    \ >> i) & 1; }\n\n  public:\n    BinaryTrie() : nodes(1, Node()) {}\n\n    int\
    \ add(const T &a, COUNT num = 1) {\n        int now = 0;\n        for (int i =\
    \ LOG - 1; i >= 0; i--) {\n            if (!~nxt(now, bit(a, i))) {\n        \
    \        nxt(now, bit(a, i)) = nodes.size();\n                nodes.emplace_back();\n\
    \            }\n            nodes[now].count += num;\n            now = nxt(now,\
    \ bit(a, i));\n        }\n        nodes[now].count += num;\n        return now;\n\
    \    }\n\n    int node_idx(const T &a) {\n        int now = 0;\n        for (int\
    \ i = LOG - 1; i >= 0; i--) {\n            if (!~nxt(now, bit(a, i)))\n      \
    \          return -1;\n            now = nxt(now, bit(a, i));\n        }\n   \
    \     return now;\n    }\n    COUNT count(const T &a) {\n        int id = node_idx(a);\n\
    \        return (~id ? nodes[id].count : 0);\n    }\n\n    COUNT size() { return\
    \ nodes[0].count; }\n\n    // \u6570\u5217\u306E\u5404\u6570\u306B xor_add \u3092\
    \u3057\u305F\u5F8C\u30010-indexed \u3067\u6607\u9806 k \u756A\u76EE\u3092\u51FA\
    \u529B\n    T k_th(COUNT k, T xor_add = 0) {\n        assert(size() > k);\n  \
    \      T res = 0;\n        int now = 0;\n        for (int i = LOG - 1; i >= 0;\
    \ i--) {\n            int f = bit(xor_add, i);\n            int s = f ^ 1;\n \
    \           if (nxt(now, f) == -1) {\n                now = nxt(now, s);\n   \
    \             res += T{1} << i;\n                continue;\n            }\n  \
    \          if (nodes[nxt(now, f)].count <= k) {\n                k -= nodes[nxt(now,\
    \ f)].count;\n                now = nxt(now, s);\n                res += T{1}\
    \ << i;\n            } else\n                now = nxt(now, f);\n        }\n \
    \       return res;\n    }\n    T min(T xor_add = 0) { return k_th(0, xor_add);\
    \ }\n    T max(T xor_add = 0) { return k_th(size() - 1, xor_add); }\n};\n"
  code: "template <int LOG, typename COUNT> class BinaryTrie {\n    static_assert(LOG\
    \ <= 64, \"Binary Trie overflow\");\n    using T = std::conditional_t<LOG <= 32,\
    \ unsigned int, unsigned long long>;\n    struct Node {\n        std::array<int,\
    \ 2> nxt_node;\n        COUNT count; //\n        Node() : count(0) { std::ranges::fill(nxt_node,\
    \ -1); }\n    };\n    std::vector<Node> nodes;\n    int &nxt(int now, bool f)\
    \ { return nodes[now].nxt_node[f]; }\n    bool bit(const T &a, int i) const {\
    \ return (a >> i) & 1; }\n\n  public:\n    BinaryTrie() : nodes(1, Node()) {}\n\
    \n    int add(const T &a, COUNT num = 1) {\n        int now = 0;\n        for\
    \ (int i = LOG - 1; i >= 0; i--) {\n            if (!~nxt(now, bit(a, i))) {\n\
    \                nxt(now, bit(a, i)) = nodes.size();\n                nodes.emplace_back();\n\
    \            }\n            nodes[now].count += num;\n            now = nxt(now,\
    \ bit(a, i));\n        }\n        nodes[now].count += num;\n        return now;\n\
    \    }\n\n    int node_idx(const T &a) {\n        int now = 0;\n        for (int\
    \ i = LOG - 1; i >= 0; i--) {\n            if (!~nxt(now, bit(a, i)))\n      \
    \          return -1;\n            now = nxt(now, bit(a, i));\n        }\n   \
    \     return now;\n    }\n    COUNT count(const T &a) {\n        int id = node_idx(a);\n\
    \        return (~id ? nodes[id].count : 0);\n    }\n\n    COUNT size() { return\
    \ nodes[0].count; }\n\n    // \u6570\u5217\u306E\u5404\u6570\u306B xor_add \u3092\
    \u3057\u305F\u5F8C\u30010-indexed \u3067\u6607\u9806 k \u756A\u76EE\u3092\u51FA\
    \u529B\n    T k_th(COUNT k, T xor_add = 0) {\n        assert(size() > k);\n  \
    \      T res = 0;\n        int now = 0;\n        for (int i = LOG - 1; i >= 0;\
    \ i--) {\n            int f = bit(xor_add, i);\n            int s = f ^ 1;\n \
    \           if (nxt(now, f) == -1) {\n                now = nxt(now, s);\n   \
    \             res += T{1} << i;\n                continue;\n            }\n  \
    \          if (nodes[nxt(now, f)].count <= k) {\n                k -= nodes[nxt(now,\
    \ f)].count;\n                now = nxt(now, s);\n                res += T{1}\
    \ << i;\n            } else\n                now = nxt(now, f);\n        }\n \
    \       return res;\n    }\n    T min(T xor_add = 0) { return k_th(0, xor_add);\
    \ }\n    T max(T xor_add = 0) { return k_th(size() - 1, xor_add); }\n};\n"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/datastructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/SetXor-Min.test.cpp
documentation_of: library/datastructure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/library/datastructure/BinaryTrie.hpp
- /library/library/datastructure/BinaryTrie.hpp.html
title: library/datastructure/BinaryTrie.hpp
---
