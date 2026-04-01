---
documentation_of: library/datastructure/Imos.hpp
---

# Imos

## 概要
- パス: `library/datastructure/Imos.hpp`
- 1 次元いもす法で区間加算をまとめる簡易クラス。

## 公開 API
- `Imos(int n)` — 長さ $n$ のバッファを確保。計算量 O(n)。
- `void add(int l, int r, T a = 1)` — 区間 $[l,r)$ に $a$ を加算。計算量 O(1)。
- `std::vector<T> build()` — 累積結果を返す。計算量 O(n)。
