---
documentation_of: library/datastructure/2D/CumulativeSum.hpp
---

# CumulativeSum2D

## 概要
- パス: `library/datastructure/2D/CumulativeSum.hpp`
- 2 次元累積和で長方形和を $O(1)$ 取得する。

## 公開 API
- `CumulativeSum2D(int h, int w)` / `(const std::vector<std::vector<T>> &v)` — グリッドを初期化または配列から構築。計算量 O(hw)。
- `void add(int y, int x, const T& val = 1)` — マス $(y,x)$ に加算（build 前のみ）。計算量 O(1)。
- `void build()` — 累積和を前計算。計算量 O(hw)。
- `U sum(int u, int d, int l, int r)` — 長方形 $[u,d)	imes[l,r)$ の和。計算量 O(1)。
- `U sum()` — 全体の和。計算量 O(1)。
