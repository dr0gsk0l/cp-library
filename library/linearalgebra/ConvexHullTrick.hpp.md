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
  code: "#pragma once\n#include \"library/linearalgebra/Linear.cpp\"\nnamespace convex_hull_trick\
    \ {\nenum Objective {\n    MINIMIZE = +1,\n    MAXIMIZE = -1,\n};\n\n// \u6700\
    \u5927\u5316\u306E\u5834\u5408\u306F\u53CD\u8EE2\u3057\u3066\u3001\u5185\u90E8\
    \u3067\u306F\u6700\u5C0F\u5316\u554F\u984C\u306E\u307F\u3092\u6271\u3046\n// \u50BE\
    \u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306B\u306A\u308B\u3088\u3046\
    \u306B\u4FDD\u5B58\n\ntemplate <typename T, Objective OBJ>\nclass ConvexHullTrick\
    \ : std::deque<Line<T>> {\n    using L = Line<T>;\n    using std::deque<L>::back;\n\
    \    using std::deque<L>::front;\n    using std::deque<L>::push_back;\n    using\
    \ std::deque<L>::push_front;\n    using std::deque<L>::pop_back;\n    using std::deque<L>::pop_front;\n\
    \    using std::deque<L>::at;\n\n    static bool check(const L &l1, const L &l2,\
    \ const L &l3) {\n        // l2 \u304C\u8981\u3089\u306A\u3044\u306A\u3089 true\
    \ \u3092\u8FD4\u3059\n        // \u50BE\u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\
    \u5C11\u306F\u4FDD\u8A3C\u3055\u308C\u3066\u308B\n        // \u4EA4\u70B9\u306E\
    \ x \u5EA7\u6A19\u306F (l2.b-l1.b)/(l1.a-l2.a) \u3068 (l3.b-l2.b)/(l2.a-l3.a)\n\
    \        // \u3053\u308C\u304C >= \u3060\u3068\u8981\u3089\u306A\u3044\n     \
    \   return (l2.b - l1.b) * (l2.a - l3.a) >= (l3.b - l2.b) * (l1.a - l2.a);\n \
    \   }\n\n    void internal_push_back(const L &l) {\n        if (size()) {\n  \
    \          if (back().a == l.a) {\n                if (back().b <= l.b)\n    \
    \                return;\n                else\n                    pop_back();\n\
    \            }\n            while (size() >= 2) {\n                L l1 = at(size()\
    \ - 2), l2 = back();\n                if (check(l1, l2, l))\n                \
    \    pop_back();\n                else\n                    break;\n         \
    \   }\n        }\n        push_back(l);\n    }\n\n    void internal_push_front(const\
    \ L &l) {\n        if (size()) {\n            if (front().a == l.a) {\n      \
    \          if (front().b <= l.b)\n                    return;\n              \
    \  else\n                    pop_front();\n            }\n            while (size()\
    \ >= 2) {\n                L l2 = at(0), l3 = at(1);\n                if (check(l,\
    \ l2, l3))\n                    pop_front();\n                else\n         \
    \           break;\n            }\n        }\n        push_front(l);\n    }\n\n\
    \  public:\n    using value_type = L;\n    using std::deque<L>::size;\n\n    ConvexHullTrick()\
    \ = default;\n    ConvexHullTrick(std::vector<L> lines) {\n        if (OBJ ==\
    \ -1)\n            for (auto &l : lines)\n                l = -l;\n        std::sort(lines.begin(),\
    \ lines.end());\n        for (const auto &l : lines)\n            internal_push_back(l);\n\
    \    }\n\n    void add(L l) {\n        if (OBJ == -1)\n            l = -l;\n \
    \       if (!size() or back().a >= l.a)\n            internal_push_back(l);\n\
    \        else if (l.a >= front().a)\n            internal_push_front(l);\n   \
    \     else\n            assert(false);\n    }\n\n    void add(T a, T b) { add(L(a,\
    \ b)); }\n\n    T query(T x) const {\n        assert(size());\n        int l =\
    \ -1, r = size() - 1;\n        while (r - l > 1) {\n            int m = (l + r)\
    \ >> 1;\n            (at(m)(x) >= at(m + 1)(x) ? l : r) = m;\n        }\n    \
    \    return at(r)(x) * OBJ;\n    }\n\n    T query_monotone_inc(T x) {\n      \
    \  assert(size());\n        while (size() >= 2 and at(0)(x) >= at(1)(x))\n   \
    \         pop_front();\n        return at(0)(x) * OBJ;\n    }\n\n    T query_monotone_dec(T\
    \ x) {\n        assert(size());\n        while (size() >= 2 and at(size() - 2)(x)\
    \ <= back()(x))\n            pop_back();\n        return back()(x) * OBJ;\n  \
    \  }\n\n    std::vector<T> query(const std::vector<T> &xs) {\n        int n =\
    \ xs.size();\n        std::vector<int> idx(n);\n        iota(idx.begin(), idx.end(),\
    \ 0);\n        std::sort(idx.begin(), idx.end(),\n                  [&](int i,\
    \ int j) { return xs[i] < xs[j]; });\n        std::vector<T> ans(n);\n       \
    \ for (int id : idx)\n            ans[id] = query_monotone_inc(xs[id]);\n    \
    \    return ans;\n    }\n\n    friend std::ostream &operator<<(std::ostream &os,\n\
    \                                    const ConvexHullTrick &cht) {\n        os\
    \ << \"[\";\n        for (int i = 0; i < cht.size(); i++)\n            os << (OBJ\
    \ == -1 ? -cht.at(i) : cht.at(i))\n               << \"],\"[i + 1 < cht.size()];\n\
    \        if (!cht.size())\n            os << \"]\";\n        return os;\n    }\n\
    };\n} // namespace convex_hull_trick\ntemplate <typename T>\nusing MinConvexHullTrick\
    \ =\n    convex_hull_trick::ConvexHullTrick<T,\n                             \
    \          convex_hull_trick::Objective::MINIMIZE>;\ntemplate <typename T>\nusing\
    \ MaxConvexHullTrick =\n    convex_hull_trick::ConvexHullTrick<T,\n          \
    \                             convex_hull_trick::Objective::MAXIMIZE>;"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linearalgebra/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/library/linearalgebra/ConvexHullTrick.hpp
- /library/library/linearalgebra/ConvexHullTrick.hpp.html
title: library/linearalgebra/ConvexHullTrick.hpp
---
