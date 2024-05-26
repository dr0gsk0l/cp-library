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
  bundledCode: "#line 2 \"library/convex/MonotoneMinima.cpp\"\n#include <queue>\n\
    #include <tuple>\n#include <vector>\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F &argmin) {\n    // argmin(i,l,r) : argmin_{j\\\
    in[l,r)} A[i][j]\n    std::vector<int> res(n);\n    std::queue<std::tuple<int,\
    \ int, int, int>> que;\n    que.emplace(0, n, 0, m);\n\n    while (que.size())\
    \ {\n        auto [u, d, l, r] = que.front();\n        que.pop();\n\n        if\
    \ (u == d)\n            continue;\n        int m = (u + d) >> 1;\n        res[m]\
    \ = argmin(m, l, r);\n        que.emplace(u, m, l, res[m] + 1);\n        que.emplace(m\
    \ + 1, d, res[m], r);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <tuple>\n#include <vector>\n\ntemplate\
    \ <typename F>\nstd::vector<int> monotone_minima(int n, int m, const F &argmin)\
    \ {\n    // argmin(i,l,r) : argmin_{j\\in[l,r)} A[i][j]\n    std::vector<int>\
    \ res(n);\n    std::queue<std::tuple<int, int, int, int>> que;\n    que.emplace(0,\
    \ n, 0, m);\n\n    while (que.size()) {\n        auto [u, d, l, r] = que.front();\n\
    \        que.pop();\n\n        if (u == d)\n            continue;\n        int\
    \ m = (u + d) >> 1;\n        res[m] = argmin(m, l, r);\n        que.emplace(u,\
    \ m, l, res[m] + 1);\n        que.emplace(m + 1, d, res[m], r);\n    }\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convex/MonotoneMinima.cpp
  requiredBy: []
  timestamp: '2024-05-26 19:55:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
docs: https://speakerdeck.com/tatyam_prime/monge-noshou-yin-shu
documentation_of: library/convex/MonotoneMinima.cpp
layout: document
title: monotone_minima
---
# monotone
$N\times M$ 行列 $A$ に対し $b_i \coloneqq \arg\min_{j\in[m]} A_{i,j}$ とする．

$b$ が広義単調増加であるような行列を monotone と呼ぶ．
# monotone_minima
monotone 行列に対して $b$ を $O(N+M\log M)$ で求めるアルゴリズム．  
最初に $b[\lfloor N/2\rfloor]$ を $O(M)$ で求めて再帰的に解く．
# 使い方
* ```std::vector<int> monotone_minima(n, m, argmin)```
monotone 行列に対して $b$ を求める．  
計算時間 $O(N+M\log M)$.  
ただし $\arg\min(i,l,r)$ を$O(r-l)$ で$\arg\min_{j\in[l,r)} A_{i,j}$ を返す関数とする．

# 使用例
```cpp
#include <bits/stdc++.h>
#include "library/convex/MonotoneMinima.cpp"

using ll = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> v(n);
    for (ll &x : v)
        std::cin >> x;

    auto score = [&v](ll canon_id, ll area_id) {
        return v[area_id] + (canon_id - area_id) * (canon_id - area_id);
    };

    auto ans = monotone_minima(n, n, [&](int i, int l, int r) {
        int res = l;
        for (int j = l + 1; j < r; j++)
            if (score(i, res) > score(i, j))
                res = j;
        return res;
    });

    for (int i = 0; i < n; i++)
        std::cout << score(i, ans[i]) << '\n';
}
```
[提出](https://atcoder.jp/contests/colopl2018-final/submissions/53923676)
