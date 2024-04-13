---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':x:'
    path: library/sequence/ForString.cpp
    title: library/sequence/ForString.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/sequence/AhoCorasick.cpp
    title: AhoCorasick
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':x:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  - icon: ':x:'
    path: test/yukicoder/430_2.test.cpp
    title: test/yukicoder/430_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename X>\n\
    struct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x, const\
    \ X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 2 \"library/sequence/ForString.cpp\"\ntemplate <char MARGIN> struct ForString\
    \ {\n    static constexpr char change(char c) { return c - MARGIN; }\n    static\
    \ constexpr char restore(char a) { return a + MARGIN; }\n\n    static std::vector<char>\
    \ change(const std::string &s) {\n        std::vector<char> v(s.size());\n   \
    \     for (int i = 0; i < s.size(); i++)\n            v[i] = change(s[i]);\n \
    \       return v;\n    }\n    static std::string restore(const std::vector<char>\
    \ &v) {\n        std::string s(v.size(), '#');\n        for (int i = 0; i < v.size();\
    \ i++)\n            s[i] = restore(v[i]);\n        return s;\n    }\n};\nstruct\
    \ FSAa {\n    static constexpr char change(char c) {\n        return c <= 'Z'\
    \ ? c - 'A' : 26 + c - 'a';\n    }\n    static constexpr char restore(char a)\
    \ {\n        return a < 26 ? 'A' : a - 26 + 'a';\n    }\n    static std::vector<char>\
    \ change(const std::string &s) {\n        std::vector<char> v(s.size());\n   \
    \     for (int i = 0; i < s.size(); i++)\n            v[i] = change(s[i]);\n \
    \       return v;\n    }\n    static std::string restore(const std::vector<char>\
    \ &v) {\n        std::string s(v.size(), '#');\n        for (int i = 0; i < v.size();\
    \ i++)\n            s[i] = restore(v[i]);\n        return s;\n    }\n};\nusing\
    \ FSA = ForString<'A'>;\nusing FSa = ForString<'a'>;\nusing FS0 = ForString<'0'>;\n\
    \n#ifdef STR\n#define STRA(s)                                                \
    \                \\\n    STR(s##tomato);                                     \
    \                       \\\n    auto s = FSA::change(s##tomato);\n#define STRa(s)\
    \                                                                \\\n    STR(s##tomato);\
    \                                                            \\\n    auto s =\
    \ FSa::change(s##tomato);\n#define STR0(s)                                   \
    \                             \\\n    STR(s##tomato);                        \
    \                                    \\\n    auto s = FS0::change(s##tomato);\n\
    #endif\n#line 4 \"library/sequence/Trie.cpp\"\ntemplate <typename CHAR, int SIGMA,\
    \ typename AbelMonoid = GroupAdd<int>>\nclass Trie {\n  protected:\n    using\
    \ X = typename AbelMonoid::value_type;\n    struct Node {\n        std::array<int,\
    \ SIGMA> nxt;\n        int pre;\n        X val, suffix_val; // suffix_val \u306F\
    \u81EA\u8EAB\u3092\u542B\u307E\u306A\u3044\n        Node(int pre)\n          \
    \  : pre(pre), val(AbelMonoid::unit()),\n              suffix_val(AbelMonoid::unit())\
    \ {\n            fill(nxt.begin(), nxt.end(), -1);\n        }\n    };\n    std::vector<Node>\
    \ nodes;\n\n  public:\n    Trie() : nodes(1, Node(-1)) {}\n\n    int &nxt(int\
    \ now, const CHAR &a) { return nodes[now].nxt[a]; }\n    const int &nxt(int now,\
    \ const CHAR &a) const { return nodes[now].nxt[a]; }\n\n    int add(const std::vector<CHAR>\
    \ &v, X x = 1) {\n        int now = 0;\n        for (const CHAR &a : v) {\n  \
    \          assert(0 <= a and a < SIGMA);\n            if (!~nxt(now, a)) {\n \
    \               nxt(now, a) = nodes.size();\n                nodes.emplace_back(now);\n\
    \            }\n            AbelMonoid::Rchop(nodes[now].suffix_val, x);\n   \
    \         now = nxt(now, a);\n        }\n        AbelMonoid::Rchop(nodes[now].val,\
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
    \       }\n        std::reverse(res.begin(), res.end());\n        return res;\n\
    \    }\n    X prod() const { return nodes[0].suffix_val; }\n    int size() const\
    \ { return nodes.size(); }\n\n    template <typename F>\n    void query(const\
    \ std::vector<CHAR> &v, const F &f, int l = 0, int r = -1) {\n        if (r <\
    \ 0)\n            r = v.size();\n        int now = 0;\n        for (int i = l;\
    \ i < r; i++) {\n            now = nxt(now, v[i]);\n            if (~now)\n  \
    \              f(now);\n            else\n                break;\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/Add.cpp\"\n#include \"library/sequence/ForString.cpp\"\
    \ntemplate <typename CHAR, int SIGMA, typename AbelMonoid = GroupAdd<int>>\nclass\
    \ Trie {\n  protected:\n    using X = typename AbelMonoid::value_type;\n    struct\
    \ Node {\n        std::array<int, SIGMA> nxt;\n        int pre;\n        X val,\
    \ suffix_val; // suffix_val \u306F\u81EA\u8EAB\u3092\u542B\u307E\u306A\u3044\n\
    \        Node(int pre)\n            : pre(pre), val(AbelMonoid::unit()),\n   \
    \           suffix_val(AbelMonoid::unit()) {\n            fill(nxt.begin(), nxt.end(),\
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
    \       }\n        std::reverse(res.begin(), res.end());\n        return res;\n\
    \    }\n    X prod() const { return nodes[0].suffix_val; }\n    int size() const\
    \ { return nodes.size(); }\n\n    template <typename F>\n    void query(const\
    \ std::vector<CHAR> &v, const F &f, int l = 0, int r = -1) {\n        if (r <\
    \ 0)\n            r = v.size();\n        int now = 0;\n        for (int i = l;\
    \ i < r; i++) {\n            now = nxt(now, v[i]);\n            if (~now)\n  \
    \              f(now);\n            else\n                break;\n        }\n\
    \    }\n};\n"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/sequence/ForString.cpp
  isVerificationFile: false
  path: library/sequence/Trie.cpp
  requiredBy:
  - library/sequence/AhoCorasick.cpp
  timestamp: '2024-04-13 20:35:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/430_2.test.cpp
  - test/yukicoder/430.test.cpp
  - test/AOJ/2212.test.cpp
documentation_of: library/sequence/Trie.cpp
layout: document
redirect_from:
- /library/library/sequence/Trie.cpp
- /library/library/sequence/Trie.cpp.html
title: library/sequence/Trie.cpp
---
