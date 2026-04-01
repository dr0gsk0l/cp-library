---
documentation_of: library/datastructure/unionfind/PotentialUnionFind.hpp
---

# PotentialUnionFind

## 概要
- パス: `library/datastructure/unionfind/PotentialUnionFind.hpp`
- 各辺に可換群の重みを持たせ、ポテンシャル差を管理する UnionFind。

## 公開 API
- `PotentialUnionFind(int n)` — 初期化。計算量 O(n)。
- `int leader(int x)` / `bool same(int x, int y)` / `int size(int x)` / `int count() const` — 基本操作。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y, T d)` — $	ext{potential}(y)-	ext{potential}(x)=d$ を課してマージ。矛盾時は `false`。計算量 ならし O(lpha(n))。
- `std::optional<T> diff(int x, int y)` — 同成分なら $	ext{potential}(y)-	ext{potential}(x)$ を返す。計算量 ならし O(lpha(n))。
