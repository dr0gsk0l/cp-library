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
  bundledCode: "#line 2 \"library/algebra/monoid/Concepts.hpp\"\n\ntemplate <class\
    \ M>\nconcept monoid = requires(typename M::value_type x) {\n    { M::op(x, x)\
    \ } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x, x) };\n    { M::Rchop(x,\
    \ x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n};\n"
  code: "#pragma once\n\ntemplate <class M>\nconcept monoid = requires(typename M::value_type\
    \ x) {\n    { M::op(x, x) } -> std::same_as<typename M::value_type>;\n    { M::Lchop(x,\
    \ x) };\n    { M::Rchop(x, x) };\n    { M::unit() } -> std::same_as<typename M::value_type>;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Concepts.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/Concepts.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Concepts.hpp
- /library/library/algebra/monoid/Concepts.hpp.html
title: library/algebra/monoid/Concepts.hpp
---
