---
documentation_of: library/datastructure/unionfind/MonoidUnionFind.hpp
---

# MonoidUnionFind

## 概要
- パス: `library/datastructure/unionfind/MonoidUnionFind.hpp`
- 各成分にモノイド値を保持し、マージ時に畳み込む UnionFind。

## 公開 API
- `UnionFind(int n)` / `UnionFind(const std::vector<T>& v)` — サイズまたは初期値列で構築。計算量 O(n)。
- `int leader(int x)` — 代表元を返す。計算量 ならし O(lpha(n))。
- `T sum(int x)` — 要素 $x$ の成分に対応するモノイド値。計算量 ならし O(lpha(n))。
- `void multiply(int x, T a)` — 成分値に $a$ を畳み込み。計算量 ならし O(lpha(n))。
- `bool same(int x, int y)` / `bool merge(int x, int y)` / `int size(int x)` / `int count() const` — 基本操作。計算量 ならし O(lpha(n))。
