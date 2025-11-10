---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.hpp
    title: library/algebra/monoid/Concepts.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/datastructure/SWAG.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"library/algebra/monoid/Concepts.hpp\"\n\n#pragma once\ntemplate\
    \ <monoid M> class SWAG {\n    using X = typename M::value_type;\n\n    std::stack<X>\
    \ back_stack,\n        front_stack; // back \u306F\u5F8C\u308D\u306E\u5404\u8981\
    \u7D20 front \u306F\u524D\u306E\u7D2F\u7A4D\u548C\n    X back_value;\n\n    inline\
    \ X front_value() const {\n        return front_stack.size() ? front_stack.top()\
    \ : M::unit();\n    }\n\n  public:\n    SWAG() : back_value(M::unit()) {}\n  \
    \  void push_back(X x) {\n        back_stack.push(x);\n        M::Rchop(back_value,\
    \ x);\n    }\n    void push_front(X x) { front_stack.push(M::op(x, front_value()));\
    \ }\n    void pop_front() {\n        if (front_stack.empty()) {\n            if\
    \ (back_stack.empty())\n                return;\n            while (back_stack.size())\
    \ {\n                push_front(back_stack.top());\n                back_stack.pop();\n\
    \            }\n            back_value = M::unit();\n        }\n        front_stack.pop();\n\
    \    }\n    X prod() { return M::op(front_value(), back_value); }\n    int size()\
    \ { return back_stack.size() + front_stack.size(); }\n};"
  dependsOn:
  - library/algebra/monoid/Concepts.hpp
  isVerificationFile: false
  path: library/datastructure/SWAG.hpp
  requiredBy: []
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/yukicoder/1036.test.cpp
documentation_of: library/datastructure/SWAG.hpp
layout: document
redirect_from:
- /library/library/datastructure/SWAG.hpp
- /library/library/datastructure/SWAG.hpp.html
title: library/datastructure/SWAG.hpp
---
