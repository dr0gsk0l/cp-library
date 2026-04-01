---
documentation_of: library/datastructure/CumulativeSum.hpp
---

# CumulativeSum

## 概要
- パス: `library/datastructure/CumulativeSum.hpp`
- 加法に限定した 1 次元累積和。`int` の場合は内部で `long long` に昇格。

## 公開 API
- `CumulativeSum()` / `CumulativeSum(const std::vector<T>& v)` — 初期化。計算量 O(n)。
- `void add(const T& a)` — 末尾に値を追加。計算量 O(1)。
- `U sum(int l, int r)` — 区間 $[l,r)$ の和。計算量 O(1)。
- `U sum()` — 全体の和。計算量 O(1)。
