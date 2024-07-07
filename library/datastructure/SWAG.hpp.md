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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/monoid/Concepts.cpp:\
    \ line -1: no such header\n"
  code: "#include \"library/algebra/monoid/Concepts.cpp\"\n\n#pragma once\ntemplate\
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
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/SWAG.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/SWAG.hpp
layout: document
redirect_from:
- /library/library/datastructure/SWAG.hpp
- /library/library/datastructure/SWAG.hpp.html
title: library/datastructure/SWAG.hpp
---
