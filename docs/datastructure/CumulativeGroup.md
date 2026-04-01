---
documentation_of: library/datastructure/CumulativeGroup.hpp
---

# CumulativeGroup

## 概要
- パス: `library/datastructure/CumulativeGroup.hpp`
- 可換群に対する累積配列。逆元を用いて区間畳み込みを O(1) で返す。

## 公開 API
- `CumulativeGroup()` / `CumulativeGroup(const std::vector<T>& v)` — 初期化。計算量 O(n)。
- `void add(const T& a)` — 末尾に値を追加し累積を更新。計算量 O(1)。
- `T sum(int l, int r)` — 区間 $[l,r)$ の畳み込み。計算量 O(1)。
- `T sum()` — 全体の畳み込み。計算量 O(1)。
