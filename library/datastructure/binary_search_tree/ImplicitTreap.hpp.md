---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  - icon: ':warning:'
    path: library/math/XorShift.hpp
    title: library/math/XorShift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
  bundledCode: "#line 2 \"library/datastructure/binary_search_tree/ImplicitTreap.hpp\"\
    \n// https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n#line 1 \"library/math/XorShift.hpp\"\
    \nclass XorShift{\n  uint64_t x;\npublic:\n  XorShift(){\n    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    x=rnd();\n    for(int i=0;i<100;i++)(*this)();\n  }\n  uint64_t operator()(){\n\
    \    x = x^(x<<7);\n    return x = x^(x>>9);\n  }\n};\n#line 4 \"library/datastructure/binary_search_tree/ImplicitTreap.hpp\"\
    \ntemplate <typename Lazy> class ImplicitTreap {\n    using MX = typename Lazy::MX;\n\
    \    using MF = typename Lazy::MF;\n    using X = typename MX::value_type;\n \
    \   using F = typename MF::value_type;\n    struct Node {\n        X val, prod;\n\
    \        F lazy;\n        int priority, cnt;\n        bool rev;\n        Node\
    \ *l, *r;\n        Node(X val, int priority = -1)\n            : value(val), prod(MX::unit()),\
    \ lazy(MF::unit()),\n              priority(priority), cnt(1), rev(false), l(nullptr),\
    \ r(nullptr) {\n            if (priority < 0)\n                priority = rnd();\n\
    \        }\n    };\n    Node *root = nullptr;\n    using Tree = Node *;\n\n  \
    \  int size(Tree t) { return t ? t->cnt : 0; }\n    X prod(Tree t) { return t\
    \ ? Lazy::mapping(t->lazy, t->prod) : MX::unit(); }\n\n    void pushup(Tree t)\
    \ {\n        if (!t)\n            return;\n        t->cnt = 1 + size(t->l) + size(t->r);\n\
    \        t->prod = MX::op(t->val, MX::op(prod(t->l), prod(t->r)));\n    }\n  \
    \  void pushdown(Tree t) {\n        if (!t)\n            return;\n        if (t->lazy\
    \ != MF::unit()) {\n            t->val = Lazy::mapping(t->val, t->lazy);\n   \
    \         if (t->l)\n                MF::Rchop(t->l->lazy, t->lazy);\n       \
    \     if (t->r)\n                MF::Rchop(t->r->lazy, t->lazy);\n           \
    \ t->lazy = MF::unit();\n        }\n        pushup(t);\n    }\n\n    void split(Tree\
    \ t, int key, Tree &l, Tree &r) {\n        if (!t) {\n            l = r = nullptr;\n\
    \            return;\n        }\n        pushdown(t);\n        int implicit_key\
    \ = size(t->l) + 1;\n        if (key < implicit_key) {\n            r = t;\n \
    \           split(t->l, key, l, t->l);\n        } else {\n            l = t;\n\
    \            split(t->r, key - implicit_key, t->r, r), l = t;\n        }\n   \
    \     pushup(t);\n    }\n\n    void insert(Tree &t, int key, Tree item) {\n  \
    \      Tree t1, t2;\n        split(t, key, t1, t2);\n        merge(t1, t1, item);\n\
    \        merge(t, t1, t2);\n    }\n\n    void merge(Tree &t, Tree l, Tree r) {\n\
    \        pushdown(l);\n        pushdown(r);\n        if (!l or !r)\n         \
    \   t = l ? l : r;\n        else if (l->priority > r->priority) {\n          \
    \  t = l;\n            merge(l->r, l->r, r);\n        } else {\n            t\
    \ = r;\n            merge(r->l, l, r->l);\n        }\n        pushup(t);\n   \
    \ }\n\n    void erase(Tree &t, int key) {\n        Tree t1, t2, t3;\n        split(t,\
    \ key + 1, t1, t2);\n        split(t1, key, t1, t3);\n        merge(t, t1, t2);\n\
    \    }\n\n    void add(Tree t, int l, int r, int x) {\n        Tree t1, t2, t3;\n\
    \        split(t, l, t1, t2);\n        split(t2, r - l, t2, t3);\n        t2->lazy\
    \ += x;\n        t2->min += x;\n        merge(t2, t2, t3);\n        merge(t, t1,\
    \ t2);\n    }\n\n    int findmin(Tree t, int l, int r) {\n        Tree t1, t2,\
    \ t3;\n        split(t, l, t1, t2);\n        split(t2, r - l, t2, t3);\n     \
    \   int ret = t2->min;\n        merge(t2, t2, t3);\n        merge(t, t1, t2);\n\
    \        return ret;\n    }\n\n    // [l, r)\u306E\u5148\u982D\u304Cm\u306B\u306A\
    \u308B\u3088\u3046\u306B\u5DE6\u30B7\u30D5\u30C8\u3055\u305B\u308B\u3002std::rotate\u3068\
    \u540C\u3058\u4ED5\u69D8\n    void rotate(Tree t, int l, int m, int r) {\n   \
    \     reverse(t, l, r);\n        reverse(t, l, l + r - m);\n        reverse(t,\
    \ l + r - m, r);\n    }\n\n    void dump(Tree t) {\n        if (!t)\n        \
    \    return;\n        pushdown(t);\n        dump(t->l);\n        std::cout <<\
    \ t->value << \" \";\n        dump(t->r);\n    }\n\n  public:\n    void insert(int\
    \ pos, int x) {\n        insert(root, pos, new Node(x, rnd.random()));\n    }\n\
    \n    void add(int l, int r, int x) { add(root, l, r, x); }\n\n    int findmin(int\
    \ l, int r) { return findmin(root, l, r); }\n\n    void erase(int pos) { erase(root,\
    \ pos); }\n\n    void reverse(int l, int r) { reverse(root, l, r); }\n\n    void\
    \ rotate(int l, int m, int r) { rotate(root, l, m, r); }\n\n    void dump() {\n\
    \        dump(root);\n        std::cout << std::endl;\n    }\n};\n"
  code: "#pragma once\n// https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n\
    #include \"library/math/XorShift.hpp\"\ntemplate <typename Lazy> class ImplicitTreap\
    \ {\n    using MX = typename Lazy::MX;\n    using MF = typename Lazy::MF;\n  \
    \  using X = typename MX::value_type;\n    using F = typename MF::value_type;\n\
    \    struct Node {\n        X val, prod;\n        F lazy;\n        int priority,\
    \ cnt;\n        bool rev;\n        Node *l, *r;\n        Node(X val, int priority\
    \ = -1)\n            : value(val), prod(MX::unit()), lazy(MF::unit()),\n     \
    \         priority(priority), cnt(1), rev(false), l(nullptr), r(nullptr) {\n \
    \           if (priority < 0)\n                priority = rnd();\n        }\n\
    \    };\n    Node *root = nullptr;\n    using Tree = Node *;\n\n    int size(Tree\
    \ t) { return t ? t->cnt : 0; }\n    X prod(Tree t) { return t ? Lazy::mapping(t->lazy,\
    \ t->prod) : MX::unit(); }\n\n    void pushup(Tree t) {\n        if (!t)\n   \
    \         return;\n        t->cnt = 1 + size(t->l) + size(t->r);\n        t->prod\
    \ = MX::op(t->val, MX::op(prod(t->l), prod(t->r)));\n    }\n    void pushdown(Tree\
    \ t) {\n        if (!t)\n            return;\n        if (t->lazy != MF::unit())\
    \ {\n            t->val = Lazy::mapping(t->val, t->lazy);\n            if (t->l)\n\
    \                MF::Rchop(t->l->lazy, t->lazy);\n            if (t->r)\n    \
    \            MF::Rchop(t->r->lazy, t->lazy);\n            t->lazy = MF::unit();\n\
    \        }\n        pushup(t);\n    }\n\n    void split(Tree t, int key, Tree\
    \ &l, Tree &r) {\n        if (!t) {\n            l = r = nullptr;\n          \
    \  return;\n        }\n        pushdown(t);\n        int implicit_key = size(t->l)\
    \ + 1;\n        if (key < implicit_key) {\n            r = t;\n            split(t->l,\
    \ key, l, t->l);\n        } else {\n            l = t;\n            split(t->r,\
    \ key - implicit_key, t->r, r), l = t;\n        }\n        pushup(t);\n    }\n\
    \n    void insert(Tree &t, int key, Tree item) {\n        Tree t1, t2;\n     \
    \   split(t, key, t1, t2);\n        merge(t1, t1, item);\n        merge(t, t1,\
    \ t2);\n    }\n\n    void merge(Tree &t, Tree l, Tree r) {\n        pushdown(l);\n\
    \        pushdown(r);\n        if (!l or !r)\n            t = l ? l : r;\n   \
    \     else if (l->priority > r->priority) {\n            t = l;\n            merge(l->r,\
    \ l->r, r);\n        } else {\n            t = r;\n            merge(r->l, l,\
    \ r->l);\n        }\n        pushup(t);\n    }\n\n    void erase(Tree &t, int\
    \ key) {\n        Tree t1, t2, t3;\n        split(t, key + 1, t1, t2);\n     \
    \   split(t1, key, t1, t3);\n        merge(t, t1, t2);\n    }\n\n    void add(Tree\
    \ t, int l, int r, int x) {\n        Tree t1, t2, t3;\n        split(t, l, t1,\
    \ t2);\n        split(t2, r - l, t2, t3);\n        t2->lazy += x;\n        t2->min\
    \ += x;\n        merge(t2, t2, t3);\n        merge(t, t1, t2);\n    }\n\n    int\
    \ findmin(Tree t, int l, int r) {\n        Tree t1, t2, t3;\n        split(t,\
    \ l, t1, t2);\n        split(t2, r - l, t2, t3);\n        int ret = t2->min;\n\
    \        merge(t2, t2, t3);\n        merge(t, t1, t2);\n        return ret;\n\
    \    }\n\n    // [l, r)\u306E\u5148\u982D\u304Cm\u306B\u306A\u308B\u3088\u3046\
    \u306B\u5DE6\u30B7\u30D5\u30C8\u3055\u305B\u308B\u3002std::rotate\u3068\u540C\u3058\
    \u4ED5\u69D8\n    void rotate(Tree t, int l, int m, int r) {\n        reverse(t,\
    \ l, r);\n        reverse(t, l, l + r - m);\n        reverse(t, l + r - m, r);\n\
    \    }\n\n    void dump(Tree t) {\n        if (!t)\n            return;\n    \
    \    pushdown(t);\n        dump(t->l);\n        std::cout << t->value << \" \"\
    ;\n        dump(t->r);\n    }\n\n  public:\n    void insert(int pos, int x) {\n\
    \        insert(root, pos, new Node(x, rnd.random()));\n    }\n\n    void add(int\
    \ l, int r, int x) { add(root, l, r, x); }\n\n    int findmin(int l, int r) {\
    \ return findmin(root, l, r); }\n\n    void erase(int pos) { erase(root, pos);\
    \ }\n\n    void reverse(int l, int r) { reverse(root, l, r); }\n\n    void rotate(int\
    \ l, int m, int r) { rotate(root, l, m, r); }\n\n    void dump() {\n        dump(root);\n\
    \        std::cout << std::endl;\n    }\n};"
  dependsOn:
  - build/pch/stdc++.hpp
  - library/math/XorShift.hpp
  isVerificationFile: false
  path: library/datastructure/binary_search_tree/ImplicitTreap.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/binary_search_tree/ImplicitTreap.hpp
layout: document
redirect_from:
- /library/library/datastructure/binary_search_tree/ImplicitTreap.hpp
- /library/library/datastructure/binary_search_tree/ImplicitTreap.hpp.html
title: library/datastructure/binary_search_tree/ImplicitTreap.hpp
---
