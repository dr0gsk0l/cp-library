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
  bundledCode: "#line 2 \"library/convex/SMAWK.cpp\"\n#include <vector>\n\ntemplate\
    \ <class Select>\nstd::vector<int> smawk(int h, int w, const Select &select) {\n\
    \    // r(k,*) : (0-indexed) k\u56DE\u76EE\u306E\u30EB\u30FC\u30D7\u3067\u8003\
    \u3048\u308B\u884C\u96C6\u5408\n    constexpr static auto r = [](int k, int i)\
    \ { return ((i + 1) << k) - 1; };\n\n    // k \u756A\u76EE\u306B\u306F r(k,*)\
    \ \u306E\u7B54\u3048\u3068\u306A\u308B\u5217\u5019\u88DC\u304C\u5165\u308B\n \
    \   std::vector<std::vector<int>> cols(std::bit_width(size_t(h)));\n    cols[0].resize(w);\n\
    \    std::iota(cols[0].begin(), cols[0].end(), 0);\n\n    for (int k = 1; k <\
    \ cols.size(); k++) {\n        const auto &col = cols[k - 1];\n        auto &nxt\
    \ = cols[k];\n        for (int j : col) {\n            while (nxt.size() and select(r(k,\
    \ nxt.size() - 1), nxt.back(), j))\n                nxt.pop_back();\n        \
    \    if (r(k, nxt.size()) < h)\n                nxt.push_back(j);\n        }\n\
    \    }\n\n    std::vector<int> res(h);\n\n    for (int k = cols.size() - 1; k\
    \ >= 0; k--) {\n        const auto &col = cols[k];\n        for (int i = 0, j\
    \ = 0; r(k, i) < h; i += 2) {\n            res[r(k, i)] = col[j];\n          \
    \  int end = (r(k, i + 1) < h ? res[r(k, i + 1)] : col.back());\n            while\
    \ (col[j] != end) {\n                if (select(r(k, i), res[r(k, i)], col[++j]))\n\
    \                    res[r(k, i)] = col[j];\n            }\n        }\n    }\n\
    \n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class Select>\nstd::vector<int>\
    \ smawk(int h, int w, const Select &select) {\n    // r(k,*) : (0-indexed) k\u56DE\
    \u76EE\u306E\u30EB\u30FC\u30D7\u3067\u8003\u3048\u308B\u884C\u96C6\u5408\n   \
    \ constexpr static auto r = [](int k, int i) { return ((i + 1) << k) - 1; };\n\
    \n    // k \u756A\u76EE\u306B\u306F r(k,*) \u306E\u7B54\u3048\u3068\u306A\u308B\
    \u5217\u5019\u88DC\u304C\u5165\u308B\n    std::vector<std::vector<int>> cols(std::bit_width(size_t(h)));\n\
    \    cols[0].resize(w);\n    std::iota(cols[0].begin(), cols[0].end(), 0);\n\n\
    \    for (int k = 1; k < cols.size(); k++) {\n        const auto &col = cols[k\
    \ - 1];\n        auto &nxt = cols[k];\n        for (int j : col) {\n         \
    \   while (nxt.size() and select(r(k, nxt.size() - 1), nxt.back(), j))\n     \
    \           nxt.pop_back();\n            if (r(k, nxt.size()) < h)\n         \
    \       nxt.push_back(j);\n        }\n    }\n\n    std::vector<int> res(h);\n\n\
    \    for (int k = cols.size() - 1; k >= 0; k--) {\n        const auto &col = cols[k];\n\
    \        for (int i = 0, j = 0; r(k, i) < h; i += 2) {\n            res[r(k, i)]\
    \ = col[j];\n            int end = (r(k, i + 1) < h ? res[r(k, i + 1)] : col.back());\n\
    \            while (col[j] != end) {\n                if (select(r(k, i), res[r(k,\
    \ i)], col[++j]))\n                    res[r(k, i)] = col[j];\n            }\n\
    \        }\n    }\n\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/convex/SMAWK.cpp
  requiredBy: []
  timestamp: '2024-05-26 19:55:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
docs: https://speakerdeck.com/tatyam_prime/monge-noshou-yin-shu
documentation_of: library/convex/SMAWK.cpp
layout: document
title: SMAWK
---
# totally monotone
$N\times M$ 行列 $A$ が任意の $y_1 < y_2, x_1<x_2$ に対し以下を満たすとき totally monotone と呼ぶ

$A_{y_1,x_1} < A_{y_1,x_2} \Rightarrow A_{y_2,x_1} < A_{y_2,x_2}$
# SMAWK
$b_i = \arg\min_{j} A_{i,j}$ とする．  
totally monotone 行列に対して $b$ を $O(N+M)$ で求めるアルゴリズム．  
# 使い方
* ```std::vector<int> monotone_minima(n, m, argmin)```
totally monotone 行列に対して $b$ を求める．  
計算時間 $O(N+M)$.  
ただし $select(i,j,k)$ は $A_{i,j} > A_{i,k}$ を返す．  

max についても使える．

# 使用例
```cpp
#include <bits/stdc++.h>
#include "library/convex/SMAWK.cpp"

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

    auto ans = smawk(
        n, n, [&](int i, int j, int k) { return score(i, j) > score(i, k); });

    for (int i = 0; i < n; i++)
        std::cout << score(i, ans[i]) << '\n';
}
```
[提出](https://atcoder.jp/contests/colopl2018-final/submissions/53922350)
