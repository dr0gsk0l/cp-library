---
title: SMAWK
documentation_of: library/convex/SMAWK.cpp
docs: https://speakerdeck.com/tatyam_prime/monge-noshou-yin-shu
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
#include "library/convex/SMAWK.hpp"

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
