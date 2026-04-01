---
documentation_of: library/datastructure/SlopeTrick.hpp
---

# SlopeTrick

## 概要
- パス: `library/datastructure/SlopeTrick.hpp`
- 区分線形かつ傾きが単調に変化する凸関数を扱う Slope Trick 実装。

## 公開 API
- `std::tuple<T,T,T> get_min_range() const` — 最小値とそれを達成する区間 $[l,r]$。計算量 O(1)。
- `void operator+=(const T& a)` — 関数全体に定数加算。計算量 O(1)。
- `T operator()(T x)` — 現在の $f(x)$ を評価。計算量 O(n)（ヒープ走査）。
- `SlopeTrick& operator+=(SlopeTrick g)` — 2 つの凸関数を足し合わせる。計算量 O(n \log n)。
