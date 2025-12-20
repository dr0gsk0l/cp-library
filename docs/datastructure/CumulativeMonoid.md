# CumulativeMonoid

## 概要
- パス: `library/datastructure/CumulativeMonoid.hpp`
- 逆元のないモノイド向けの前後累積表。prefix/suffix を保持して区間計算を支援。

## 公開 API
- `CumulativeMonoid(const std::vector<T>& v)` — 配列から前後累積を構築。計算量 O(n)。
- `T pre_sum(int r)` — 区間 $[0,r)$ の畳み込み。計算量 O(1)。
- `T suf_sum(int l)` — 区間 $[l,n)$ の畳み込み。計算量 O(1)。
- `T sum()` — 全体の畳み込み。計算量 O(1)。
