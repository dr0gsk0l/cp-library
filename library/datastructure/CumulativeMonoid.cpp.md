---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/monoid/Concepts.cpp\"\n\ntemplate <class\
    \ M>\nconcept monoid = requires(typename M::value_type x) {\n    { M::op(x, x)\
    \ } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x, x) };\n    { M::Rchop(x,\
    \ x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n};\n#line\
    \ 2 \"library/datastructure/CumulativeMonoid.cpp\"\n\ntemplate <monoid M> class\
    \ CumulativeMonoid {\n    using T = typename M::value_type;\n    std::vector<T>\
    \ pre, suf;\n\n  public:\n    CumulativeMonoid() : pre(1, M::unit()), suf(pre)\
    \ {}\n    CumulativeMonoid(const std::vector<T> &v)\n        : pre(v.size() +\
    \ 1, M::unit()), suf(pre) {\n        for (int i = 0; i < v.size(); i++)\n    \
    \        pre[i + 1] = M::op(pre[i], v[i]);\n        for (int i = v.size() - 1;\
    \ i >= 0; i--)\n            suf[i] = M::op(v[i], suf[i + 1]);\n        assert(pre.back()\
    \ == suf[0]);\n    }\n    //[0,r)\n    T pre_sum(int r) { return pre[r]; }\n \
    \   // [l,n)\n    T suf_sum(int l) { return suf[l]; }\n\n    T sum() { return\
    \ pre.back(); }\n};\n"
  code: "#include \"library/algebra/monoid/Concepts.cpp\"\n\ntemplate <monoid M> class\
    \ CumulativeMonoid {\n    using T = typename M::value_type;\n    std::vector<T>\
    \ pre, suf;\n\n  public:\n    CumulativeMonoid() : pre(1, M::unit()), suf(pre)\
    \ {}\n    CumulativeMonoid(const std::vector<T> &v)\n        : pre(v.size() +\
    \ 1, M::unit()), suf(pre) {\n        for (int i = 0; i < v.size(); i++)\n    \
    \        pre[i + 1] = M::op(pre[i], v[i]);\n        for (int i = v.size() - 1;\
    \ i >= 0; i--)\n            suf[i] = M::op(v[i], suf[i + 1]);\n        assert(pre.back()\
    \ == suf[0]);\n    }\n    //[0,r)\n    T pre_sum(int r) { return pre[r]; }\n \
    \   // [l,n)\n    T suf_sum(int l) { return suf[l]; }\n\n    T sum() { return\
    \ pre.back(); }\n};\n"
  dependsOn:
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: false
  path: library/datastructure/CumulativeMonoid.cpp
  requiredBy: []
  timestamp: '2024-04-13 18:08:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/CumulativeMonoid.cpp
layout: document
redirect_from:
- /library/library/datastructure/CumulativeMonoid.cpp
- /library/library/datastructure/CumulativeMonoid.cpp.html
title: library/datastructure/CumulativeMonoid.cpp
---
