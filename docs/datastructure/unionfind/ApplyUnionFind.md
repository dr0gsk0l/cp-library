---
documentation_of: library/datastructure/unionfind/ApplyUnionFind.hpp
---

# ApplyUnionFind

## 概要
- パス: `library/datastructure/unionfind/ApplyUnionFind.hpp`
- 各成分に作用素を遅延適用できる UnionFind。作用はモノイドで合成。

## 公開 API
- `ApplyUnionFind(int n, const std::vector<X>& w)` — 初期値で構築。計算量 O(n)。
- `int leader(int x)` / `bool same(int x, int y)` / `int size(int x)` / `int count() const` — 基本操作。計算量 ならし O(lpha(n))。
- `X prod(int x)` — 成分の現在値。計算量 ならし O(lpha(n))。
- `void apply(int x, F f)` — 成分に作用 $f$ を遅延適用。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y)` — マージ。計算量 ならし O(lpha(n))。
