---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bitwise/Ranked.cpp:\
    \ line -1: no such header\n"
  code: "#include \"bitwise/Ranked.cpp\"\ntemplate <typename T> struct SetPowerSeries\
    \ : std::vector<T> {\n    using SPS = SetPowerSeries;\n    using value_type =\
    \ T;\n    using std::vector<T>::vector;\n    using std::vector<T>::resize;\n \
    \   using std::vector<T>::at;\n    using std::vector<T>::size;\n\n    SetPowerSeries(const\
    \ std::vector<T> &f) {\n        resize(f.size());\n        for (int i = 0; i <\
    \ size(); i++)\n            at(i) = f[i];\n    }\n\n    SPS operator-() const\
    \ {\n        SPS ret(*this);\n        for (auto &a : ret)\n            a = -a;\n\
    \        return ret;\n    }\n\n    SPS &operator+=(const SPS &b) {\n        if\
    \ (size() < b.size())\n            resize(b.size(), 0);\n        for (int i =\
    \ 0; i < size(); i++)\n            at(i) += b[i];\n        return *this;\n   \
    \ }\n    SPS operator+(const SPS &b) const { return SPS(*this) += b; }\n\n   \
    \ SPS &operator-=(const SPS &b) {\n        if (size() < b.size())\n          \
    \  resize(b.size(), 0);\n        for (int i = 0; i < size(); i++)\n          \
    \  at(i) -= b[i];\n        return *this;\n    }\n    SPS operator-(const SPS &b)\
    \ const { return SPS(*this) -= b; }\n\n    SPS operator*(const SPS &b) const {\n\
    \        return SPS(BitwiseRanked::convolution<T>(*this, b));\n    }\n    SPS\
    \ &operator*=(const SPS &b) { return (*this) = (*this) * b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/setpowerseries/Base.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/setpowerseries/Base.cpp
layout: document
redirect_from:
- /library/library/setpowerseries/Base.cpp
- /library/library/setpowerseries/Base.cpp.html
title: library/setpowerseries/Base.cpp
---
