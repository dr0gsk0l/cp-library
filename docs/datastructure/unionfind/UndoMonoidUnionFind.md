---
documentation_of: library/datastructure/unionfind/UndoMonoidUnionFind.hpp
---

# UndoMonoidUnionFind

## 概要
- パス: `library/datastructure/unionfind/UndoMonoidUnionFind.hpp`
- モノイド値を保持しつつ巻き戻し可能な UnionFind。

## 公開 API
- `UndoMonoidUnionFind(int n, const std::vector<T>& v)` — 初期値列で構築。計算量 O(n)。
- `int leader(int x)` / `bool same(int x, int y)` / `int size(int x)` / `int count() const` — 基本操作。計算量 ならし O(lpha(n))。
- `T prod(int x)` — 成分のモノイド値。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y)` — マージ（履歴に記録）。計算量 ならし O(lpha(n))。
- `int snapshot()` — 現在の履歴サイズ。計算量 O(1)。
- `void rollback(int to)` — 指定スナップショットまで戻す。計算量 O(	ext{巻き戻し長})。
