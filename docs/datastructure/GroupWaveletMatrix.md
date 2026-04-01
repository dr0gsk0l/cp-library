---
documentation_of: library/datastructure/GroupWaveletMatrix.hpp
---

# GroupWaveletMatrix

## 概要
- パス: `library/datastructure/GroupWaveletMatrix.hpp`
- 波レット行列に群の重みを載せ、値による範囲和を $O(\log \sigma)$ で求める拡張。

## 公開 API
- `GroupWaveletMatrix(std::vector<T> v)` / `(std::vector<T> v, const std::vector<S>& w)` — 値列と重み列で構築。計算量 O(n \log \sigma)。
- `void add(int idx, const S& val)` — 位置 `idx` の重みに $val$ を加算。計算量 O(\log \sigma)。
- `S sum(int l, int r, const T& upper)` — 区間 $[l,r)$ かつ値 $<\,	ext{upper}$ の重み総和。計算量 O(\log \sigma)。
- `S sum(int l, int r, const T& lower, const T& upper)` — 値 $\in [	ext{lower},	ext{upper})$ の重み総和。計算量 O(\log \sigma)。
- `S kth_largest_sum(int l, int r, int k)` — 区間 $[l,r)$ の大きい順 $k$ 番目までの値に対応する重み総和。計算量 O(\log \sigma)。
- WaveletMatrix の rank/kth なども利用可（計算量はいずれも O(\log \sigma)）。
