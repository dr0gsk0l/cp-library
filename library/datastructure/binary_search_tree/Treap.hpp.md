---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"library/datastructure/binary_search_tree/Treap.hpp\"\n//\
    \ https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n#line 1 \"library/math/XorShift.hpp\"\
    \nclass XorShift{\n  uint64_t x;\npublic:\n  XorShift(){\n    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    x=rnd();\n    for(int i=0;i<100;i++)(*this)();\n  }\n  uint64_t operator()(){\n\
    \    x = x^(x<<7);\n    return x = x^(x>>9);\n  }\n};\n#line 4 \"library/datastructure/binary_search_tree/Treap.hpp\"\
    \ntemplate <typename T> class Treap {\n    XorShift rnd;\n    struct Node {\n\
    \        T key;\n        int priority;\n        Node *l, *r;\n        Node(T key,\
    \ int priority = -1)\n            : key(key), priority(priority), l(nullptr),\
    \ r(nullptr) {\n            if (priority < 0)\n                priority = rnd();\n\
    \        }\n    };\n    Node *root = nullptr;\n    using Tree = Node *;\n\n  \
    \  // t \u3092 key \u672A\u6E80\u3068 key \u4EE5\u4E0A\u306B\u5206\u3051\u3001\
    \u305D\u308C\u305E\u308C l,r \u306B\u4EE3\u5165\n    void split(Tree t, T key,\
    \ Tree &l, Tree &r) {\n        if (!t)\n            l = r = nullptr;\n       \
    \ else if (t->key < key) {\n            // t \u306F l \u306E\u62C5\u5F53\n   \
    \         l = t;\n            split(t->r, key, t->r, r);\n        } else {\n \
    \           r = t;\n            split(t->l, key, l, t->l);\n        }\n    }\n\
    \n    // t \u306B item \u3092\u633F\u5165\n    void insert(Tree &t, Tree item)\
    \ {\n        if (!t)\n            t = item;\n        else if (item->priority >\
    \ t->priority) {\n            // t \u306E\u5834\u6240\u306B item \u3092\u7F6E\u304F\
    \n            // t \u3068\u305D\u306E\u90E8\u5206\u6728 \u306F item \u306E\u5DE6\
    \u53F3\u306B\u304F\u3063\u3064\u3051\u308B\n            split(t, item->key, item->l,\
    \ item->r);\n            t = item;\n        } else\n            insert(item->key\
    \ < t->key ? t->l : t->r, item);\n    }\n\n    //\n    void merge(Tree &t, Tree\
    \ l, Tree r) {\n        if (!l or !r)\n            t = l ? l : r;\n        else\
    \ if (l->priority > r->priority) {\n            merge(l->r, l->r, r);\n      \
    \      t = l;\n        } else {\n            merge(r->l, l, r->l);\n         \
    \   t = r;\n        }\n    }\n\n    void erase(Tree &t, T key) {\n        if (t->key\
    \ == key)\n            merge(t, t->l, t->r);\n        else\n            erase(key\
    \ < t->key ? t->l : t->r, key);\n    }\n\n    bool find(Tree &t, T key) {\n  \
    \      if (!t)\n            return false;\n        if (t->key == key)\n      \
    \      return true;\n        return find(key < t->key ? t->l : t->r, key);\n \
    \   }\n\n  public:\n    void insert(T key) { insert(root, new Node(key)); }\n\
    \    void erase(T key) { erase(root, key); }\n    bool find(T key) { return find(root,\
    \ key); }\n};\n"
  code: "#pragma once\n// https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n\
    #include \"library/math/XorShift.hpp\"\ntemplate <typename T> class Treap {\n\
    \    XorShift rnd;\n    struct Node {\n        T key;\n        int priority;\n\
    \        Node *l, *r;\n        Node(T key, int priority = -1)\n            : key(key),\
    \ priority(priority), l(nullptr), r(nullptr) {\n            if (priority < 0)\n\
    \                priority = rnd();\n        }\n    };\n    Node *root = nullptr;\n\
    \    using Tree = Node *;\n\n    // t \u3092 key \u672A\u6E80\u3068 key \u4EE5\
    \u4E0A\u306B\u5206\u3051\u3001\u305D\u308C\u305E\u308C l,r \u306B\u4EE3\u5165\n\
    \    void split(Tree t, T key, Tree &l, Tree &r) {\n        if (!t)\n        \
    \    l = r = nullptr;\n        else if (t->key < key) {\n            // t \u306F\
    \ l \u306E\u62C5\u5F53\n            l = t;\n            split(t->r, key, t->r,\
    \ r);\n        } else {\n            r = t;\n            split(t->l, key, l, t->l);\n\
    \        }\n    }\n\n    // t \u306B item \u3092\u633F\u5165\n    void insert(Tree\
    \ &t, Tree item) {\n        if (!t)\n            t = item;\n        else if (item->priority\
    \ > t->priority) {\n            // t \u306E\u5834\u6240\u306B item \u3092\u7F6E\
    \u304F\n            // t \u3068\u305D\u306E\u90E8\u5206\u6728 \u306F item \u306E\
    \u5DE6\u53F3\u306B\u304F\u3063\u3064\u3051\u308B\n            split(t, item->key,\
    \ item->l, item->r);\n            t = item;\n        } else\n            insert(item->key\
    \ < t->key ? t->l : t->r, item);\n    }\n\n    //\n    void merge(Tree &t, Tree\
    \ l, Tree r) {\n        if (!l or !r)\n            t = l ? l : r;\n        else\
    \ if (l->priority > r->priority) {\n            merge(l->r, l->r, r);\n      \
    \      t = l;\n        } else {\n            merge(r->l, l, r->l);\n         \
    \   t = r;\n        }\n    }\n\n    void erase(Tree &t, T key) {\n        if (t->key\
    \ == key)\n            merge(t, t->l, t->r);\n        else\n            erase(key\
    \ < t->key ? t->l : t->r, key);\n    }\n\n    bool find(Tree &t, T key) {\n  \
    \      if (!t)\n            return false;\n        if (t->key == key)\n      \
    \      return true;\n        return find(key < t->key ? t->l : t->r, key);\n \
    \   }\n\n  public:\n    void insert(T key) { insert(root, new Node(key)); }\n\
    \    void erase(T key) { erase(root, key); }\n    bool find(T key) { return find(root,\
    \ key); }\n};"
  dependsOn:
  - library/math/XorShift.hpp
  isVerificationFile: false
  path: library/datastructure/binary_search_tree/Treap.hpp
  requiredBy: []
  timestamp: '2024-07-08 10:24:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/binary_search_tree/Treap.hpp
layout: document
redirect_from:
- /library/library/datastructure/binary_search_tree/Treap.hpp
- /library/library/datastructure/binary_search_tree/Treap.hpp.html
title: library/datastructure/binary_search_tree/Treap.hpp
---
