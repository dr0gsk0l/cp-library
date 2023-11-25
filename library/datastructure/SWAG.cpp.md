---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/datastructure/SWAG.cpp\"\ntemplate<typename Monoid>\n\
    class SWAG{\n  using X=typename Monoid::value_type;\n\n  stack<X> back_stack,front_stack;\
    \ // back \u306F\u5F8C\u308D\u306E\u5404\u8981\u7D20 front \u306F\u524D\u306E\u7D2F\
    \u7A4D\u548C\n  X back_value;\n\n  inline X front_value()const{\n    return front_stack.size()?front_stack.top():Monoid::unit();\n\
    \  }\npublic:\n  SWAG():back_value(Monoid::unit()){}\n  void push_back(X x){\n\
    \    back_stack.push(x);\n    Monoid::Rchop(back_value,x);\n  }\n  void push_front(X\
    \ x){\n    front_stack.push(Monoid::op(x,front_value()));\n  }\n  void pop_front(){\n\
    \    if(front_stack.empty()){\n      if(back_stack.empty())return;\n      while(back_stack.size()){\n\
    \        push_front(back_stack.top());\n        back_stack.pop();\n      }\n \
    \     back_value=Monoid::unit();\n    }\n    front_stack.pop();\n  }\n  X prod(){\n\
    \    return Monoid::op(front_value(),back_value);\n  }\n  int size(){\n    return\
    \ back_stack.size()+front_stack.size();\n  }\n};\n"
  code: "#pragma once\ntemplate<typename Monoid>\nclass SWAG{\n  using X=typename\
    \ Monoid::value_type;\n\n  stack<X> back_stack,front_stack; // back \u306F\u5F8C\
    \u308D\u306E\u5404\u8981\u7D20 front \u306F\u524D\u306E\u7D2F\u7A4D\u548C\n  X\
    \ back_value;\n\n  inline X front_value()const{\n    return front_stack.size()?front_stack.top():Monoid::unit();\n\
    \  }\npublic:\n  SWAG():back_value(Monoid::unit()){}\n  void push_back(X x){\n\
    \    back_stack.push(x);\n    Monoid::Rchop(back_value,x);\n  }\n  void push_front(X\
    \ x){\n    front_stack.push(Monoid::op(x,front_value()));\n  }\n  void pop_front(){\n\
    \    if(front_stack.empty()){\n      if(back_stack.empty())return;\n      while(back_stack.size()){\n\
    \        push_front(back_stack.top());\n        back_stack.pop();\n      }\n \
    \     back_value=Monoid::unit();\n    }\n    front_stack.pop();\n  }\n  X prod(){\n\
    \    return Monoid::op(front_value(),back_value);\n  }\n  int size(){\n    return\
    \ back_stack.size()+front_stack.size();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/SWAG.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:38:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/yukicoder/1036.test.cpp
documentation_of: library/datastructure/SWAG.cpp
layout: document
redirect_from:
- /library/library/datastructure/SWAG.cpp
- /library/library/datastructure/SWAG.cpp.html
title: library/datastructure/SWAG.cpp
---
