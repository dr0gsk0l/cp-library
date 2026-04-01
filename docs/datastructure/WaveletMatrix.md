---
documentation_of: library/datastructure/WaveletMatrix.hpp
---

# WaveletMatrix

## 概要
- パス: `library/datastructure/WaveletMatrix.hpp`
- 座圧した整数列に対し、$k$ 番目取得や rank/select、範囲内個数を $O(\log \sigma)$ で処理する波レット行列。

## 公開 API
- `WaveletMatrix(std::vector<T> v, int log = 0)` — 配列から構築。計算量 O(n \log \sigma)。
- `int rank(int l, int r, const T& x)` — 区間 $[l,r)$ に含まれる値 $x$ の個数。計算量 O(\log \sigma)。
- `int rank(int r, const T& x)` — 区間 $[0,r)$ に含まれる $x$ の個数。計算量 O(\log \sigma)。
- `int select(int k, const T& x)` — 値 $x$ の $k$ 番目 (1-indexed) の位置。存在しなければ $-1$。計算量 O(\log \sigma)。
- `T kth_largest(int l, int r, int k)` — 区間 $[l,r)$ の大きい順 $k$ 番目 ($k=0$ が最大)。計算量 O(\log \sigma)。
- `T kth_smallest(int l, int r, int k)` — 区間 $[l,r)$ の小さい順 $k$ 番目。計算量 O(\log \sigma)。
- `int range_freq(int l, int r, const T& upper)` — 区間 $[l,r)$ で値 $<\,	ext{upper}$ の個数。計算量 O(\log \sigma)。
- `int range_freq(int l, int r, const T& lower, const T& upper)` — 区間 $[l,r)$ で値 $\in [	ext{lower},	ext{upper})$ の個数。計算量 O(\log \sigma)。
- `std::optional<T> lt/leq/geq/gt(int l, int r, const T& x)` — 区間 $[l,r)$ で条件を満たす最寄りの値（$<$, $\le$, $\ge$, $>$）。計算量 O(\log \sigma)。
- `int height() const` — ビット長 (level 数)。計算量 O(1)。
- `std::vector<int> points(int idx)` — 値 $v_{idx}$ が各レベルでどこに移動するか。計算量 O(\log \sigma)。
- `intervals(...) / kth_largest_intervals(...) / kth_smallest_intervals(...)` — セグ木併用用のレベル区間情報。計算量 O(\log \sigma)。
