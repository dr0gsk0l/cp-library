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
  bundledCode: "#line 1 \"library/util/ForAllPareto.cpp\"\ntemplate <typename F>\n\
    void for_all_pareto(const std::vector<int> &v, const F &f) {\n    int n = v.size();\n\
    \    std::vector<int> a(n, 0);\n    while (true) {\n        f(a);\n        int\
    \ idx = 0;\n        while (idx < n and a[idx] == v[idx])\n            a[idx++]\
    \ = 0;\n        if (idx == n)\n            break;\n        a[idx]++;\n    }\n\
    }\n"
  code: "template <typename F>\nvoid for_all_pareto(const std::vector<int> &v, const\
    \ F &f) {\n    int n = v.size();\n    std::vector<int> a(n, 0);\n    while (true)\
    \ {\n        f(a);\n        int idx = 0;\n        while (idx < n and a[idx] ==\
    \ v[idx])\n            a[idx++] = 0;\n        if (idx == n)\n            break;\n\
    \        a[idx]++;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/ForAllPareto.cpp
  requiredBy: []
  timestamp: '2024-04-14 23:11:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/ForAllPareto.cpp
layout: document
title: for_all_pareto
---

長さ $n$ の配列 $v$ と関数 $f$ を引数に取り、$0\leq a_i\leq v_i　\forall i\in[n]$ を満たす各 $a$ に対して、$f(a)$ を行う

例えば、$0\leq i\leq 2$, $0\leq j \leq 3$, $0\leq k\leq 1$ を満たす各 $i,j,k$ に対して $2^i 3^j 5^k$ を列挙したい時は

```cpp
vector<int> base={2,3,1};

auto f=[&](vector<int>a){
  int x=1;
  for(int i=0;i<3;i++)while(a[i]--)x*=base[i];
  std::cout<<x<<endl;
};
for_all_pareto({2,3,5},f);
```

のように書くと良い