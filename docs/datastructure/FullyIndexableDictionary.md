# FullyIndexableDictionary

## 概要
- パス: `library/datastructure/FullyIndexableDictionary.hpp`
- ビット列に対する rank/select を O(1) で提供する静的ビットベクトル。

## 公開 API
- `FullyIndexableDictionary(const std::vector<U>& bits)` — 符号なし整数列 `bits` を受け取り、各要素が 0 以外なら 1 と見なして構築。計算量 O(n/64)。
- `bool operator[](int k) const` — 位置 `k` のビットを返す。計算量 O(1)。
- `rank(int j, bool b = 1) const` — 区間 $[0,j)$ に含まれるビット $b$ の個数。計算量 O(1)。
- `select(int k, bool b = 1) const` — ビット $b$ が $k$ 番目に現れる位置 (0-indexed)。存在しなければ $-1$。計算量 O(\log n)。
- `select(int k, bool b, int l) const` — 区間開始 $l$ 以降でビット $b$ が $k$ 番目に現れる位置。計算量 O(\log n)。
