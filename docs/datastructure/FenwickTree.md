# FenwickTree

## 概要
- パス: `library/datastructure/FenwickTree.hpp`
- 群 (デフォルトは加法) に対する 1 次元 Fenwick 木。点更新と prefix/区間畳み込みを処理。

## 公開 API
- `FenwickTree(int n)` / `FenwickTree(const std::vector<T>& v)` — サイズまたは初期配列で構築。計算量 O(n) or O(n \log n)。
- `T operator[](int k) const` / `T get(int k) const` — 位置 $k$ の値を返す。計算量 O(1)。
- `void multiply(int k, const T& x)` / `void add(int k, const T& x)` — 位置 $k$ を群演算で更新。計算量 O(\log n)。
- `void set(int k, const T& x)` — 位置 $k$ を指定値に置き換え。計算量 O(\log n)。
- `T prod(int k) const` / `T sum(int k) const` — prefix $[0,k)$ の畳み込み。計算量 O(\log n)。
- `T prod(int L, int R) const` / `T sum(int L, int R) const` — 区間 $[L,R)$ の畳み込み。計算量 O(\log n)。
- `template<class F> int max_right(F check) const` — 単調性を満たす述語に対し、最大の $r$ を返す（$	ext{check}(igoplus_{i<r} a_i)$ が真）。計算量 O(\log n)。
- `int kth(T k) const` — 累積が $k$ を超えない最大位置を返す（`max_right` 利用）。計算量 O(\log n)。
