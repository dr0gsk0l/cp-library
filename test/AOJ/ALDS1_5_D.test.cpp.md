---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  - icon: ':x:'
    path: library/util/InversionNumber.cpp
    title: library/util/InversionNumber.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"test/AOJ/ALDS1_5_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/util/InversionNumber.cpp\"\n#include\
    \ <atcoder/fenwicktree>\nusing namespace atcoder;\n\n#line 2 \"library/util/Compress.cpp\"\
    \n#define ALL_(v) v.begin(),v.end()\ntemplate<typename T,bool Sentinel=false>\n\
    class Compress{\n  vector<T> v;\n  bool prepared;\npublic:\n  Compress():prepared(false){\n\
    \    if constexpr(Sentinel){\n      static_assert(std::numeric_limits<T>::is_specialized,\"\
    cannot use Sentinel\");\n      v={numeric_limits<T>::min(),numeric_limits<T>::max()};\n\
    \    }\n  }\n  Compress(const vector<T>&w):v(w),prepared(false){\n    if constexpr(Sentinel){\n\
    \      static_assert(std::numeric_limits<T>::is_specialized,\"cannot use Sentinel\"\
    );\n      v.push_back(numeric_limits<T>::min());\n      v.push_back(numeric_limits<T>::max());\n\
    \    }\n    build();\n  }\n  \n  void add(T a){ \n    assert(!prepared);\n   \
    \ v.push_back(a); \n  }\n  void build(){\n    assert(!prepared);\n    prepared=true;\n\
    \    sort(ALL_(v));\n    v.erase(unique(ALL_(v)),v.end());\n  }\n\n  bool is_prepared()const{\
    \ return prepared; }\n\n  int operator[](const T&a)const{\n    assert(prepared);\n\
    \    auto it=lower_bound(ALL_(v),a);\n    assert(*it==a);\n    return distance(v.begin(),it);\n\
    \  }\n  int geq(const T&a)const{\n    assert(prepared);\n    auto it=lower_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int gt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=upper_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n  }\n\
    \  int leq(const T&a)const{\n    assert(prepared);\n    auto it=--upper_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int lt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=--lower_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n \
    \ }\n  T r(int id)const{\n    assert(prepared);\n    return v[id];\n  }\n  bool\
    \ exist(const T&a)const{\n    assert(prepared);\n    return (*lower_bound(ALL_(v),a))==a;\n\
    \  }\n  int size()const{return v.size();}\n  T max()const{ return v.back(); }\n\
    \  T min()const{ return v[0]; }\n\n  friend ostream&operator<<(ostream&os, const\
    \ Compress&C){ \n    for(int i=0;i<C.v.size();i++)os<<C.v[i]<<\":\"<<i<<\" \"\
    ;\n    return os;\n  }\n};\n#undef ALL_\n#line 5 \"library/util/InversionNumber.cpp\"\
    \n\ntemplate <typename T>\nlong long inversion_number(const vector<T> &v){\n \
    \ Compress cmp(v);\n  fenwick_tree<int> ft(cmp.size());\n  long long res=0;\n\
    \  for(int i=int(v.size())-1;i>=0;i--){\n    int j=cmp[v[i]];\n    res+=ft.sum(0,j);\n\
    \    ft.add(j,1);\n  }\n  return res;\n}\n#line 5 \"test/AOJ/ALDS1_5_D.test.cpp\"\
    \n\nint main()\n{\n  int n;\n  std::cin >> n;\n  std::vector<int> v(n);\n  for\
    \ (int i = 0; i < n; i++)\n    std::cin >> v[i];\n  std::cout << inversion_number(v)\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/util/InversionNumber.cpp\"\n\n\
    int main()\n{\n  int n;\n  std::cin >> n;\n  std::vector<int> v(n);\n  for (int\
    \ i = 0; i < n; i++)\n    std::cin >> v[i];\n  std::cout << inversion_number(v)\
    \ << std::endl;\n}"
  dependsOn:
  - library/util/InversionNumber.cpp
  - library/util/Compress.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2023-09-28 16:40:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_5_D.test.cpp
- /verify/test/AOJ/ALDS1_5_D.test.cpp.html
title: test/AOJ/ALDS1_5_D.test.cpp
---
