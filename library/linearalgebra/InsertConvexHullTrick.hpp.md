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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/linearalgebra/Linear.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/linearalgebra/Linear.cpp\"\nnamespace insert_convex_hull_trick\
    \ {\nenum Objective {\n    MINIMIZE = +1,\n    MAXIMIZE = -1,\n};\n\n// \u6700\
    \u5927\u5316\u306E\u5834\u5408\u306F\u53CD\u8EE2\u3057\u3066\u3001\u5185\u90E8\
    \u3067\u306F\u6700\u5C0F\u5316\u554F\u984C\u306E\u307F\u3092\u6271\u3046\n// \u50BE\
    \u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306B\u306A\u308B\u3088\u3046\
    \u306B\u4FDD\u5B58\n\ntemplate <typename T, Objective OBJ> class InsertConvexHullTrick\
    \ {\n    using L = Line<T>;\n\n    std::map<T, T> mp1, mp2; // \u50BE\u304D \u2192\
    \ \u5207\u7247, \u533A\u9593\u306E\u53F3\u7AEF \u2192 \u50BE\u304D\n    // f(x)=ax+b\
    \ \u306B\u5BFE\u3057 r = max_x { f(x) = min_g g(x)} \u3068\u3057\u3066\n    //\
    \ mp1[a]=b, mp2[r]=a \u304C\u5165\u3063\u3066\u3044\u308B\n    // r = \\inf \u306E\
    \u6642\u306F mp2 \u306B\u306F\u5165\u308C\u306A\u3044\n\n    template <typename\
    \ IT> bool check(const IT it) {\n        // mp1 \u306E it \u304C\u8981\u3089\u306A\
    \u3044\u306A\u3089 true \u3092\u8FD4\u3059\n        if (it == mp1.begin() or it\
    \ == mp1.rbegin().base())\n            return false;\n        const auto &[a1,\
    \ b1] = *prev(it);\n        const auto &[a2, b2] = *it;\n        const auto &[a3,\
    \ b3] = *nxt(it);\n        // \u4EA4\u70B9\u306E x \u5EA7\u6A19\u306F\u305D\u308C\
    \u305E\u308C (b2-b1)/(a1-a2), (b3-b2)/(a2-a3)\n        // \u3053\u308C\u304C <=\
    \ \u306A\u3089\u8981\u3089\u306A\u3044\n        return (b2 - b1) * (a2 - a3) <=\
    \ (b3 - b2) * (a1 - a2);\n    }\n\n    template <typename IT> T r(const IT it)\
    \ {\n        // it \u304C\u6700\u5C0F\u3067\u3044\u3089\u308C\u308B\u6700\u5927\
    \u306E r \u3092\u8FD4\u3059\n    }\n\n  public:\n    using value_type = L;\n\n\
    \    InsertConvexHullTrick() = default;\n    InsertConvexHullTrick(const std::vector<L>\
    \ &lines) {\n        for (const auto &l : lines)\n            add(l);\n    }\n\
    \n    void add(L l) {\n        if (OBJ == -1)\n            l = -l;\n        if\
    \ (mp1.count(l.a)) {\n            if (mp1[l.a] <= l.b)\n                return;\n\
    \            mp1.erase(l.a);\n        }\n        auto [it, flag] = mp1.insert(std::make_pair(l.a,\
    \ l.b));\n        if (check(it)) {\n            mp1.erase(it);\n            return;\n\
    \        }\n        if (it != mp1.begin())\n            for (auto l = pre(it);\
    \ check(l); l = --mp1.erase(l)) {\n            }\n        if (nxt(it) != mp1.end())\n\
    \            for (auto r = nxt(it); check(r); r = mp1.erase(r)) {\n          \
    \  }\n    }\n    void add(T a, T b) { add(L(a, b)); }\n\n    T query(T x) const\
    \ {\n        assert(mp1.size());\n        if (mp2.begin())\n    }\n};\n} // namespace\
    \ insert_convex_hull_trick\ntemplate <typename T>\nusing MinConvexHullTrick =\n\
    \    convex_hull_trick::ConvexHullTrick<T,\n                                 \
    \      convex_hull_trick::Objective::MINIMIZE>;\ntemplate <typename T>\nusing\
    \ MaxConvexHullTrick =\n    convex_hull_trick::ConvexHullTrick<T,\n          \
    \                             convex_hull_trick::Objective::MAXIMIZE>;"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/InsertConvexHullTrick.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linearalgebra/InsertConvexHullTrick.hpp
layout: document
redirect_from:
- /library/library/linearalgebra/InsertConvexHullTrick.hpp
- /library/library/linearalgebra/InsertConvexHullTrick.hpp.html
title: library/linearalgebra/InsertConvexHullTrick.hpp
---
