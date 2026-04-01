---
documentation_of: library/datastructure/unionfind/UndoUnionFind.hpp
---

# UndoUnionFind

## 概要
- パス: `library/datastructure/unionfind/UndoUnionFind.hpp`
- マージ操作を巻き戻せる UnionFind。

## 公開 API
- `UndoUnionFind(int n)` — 初期化。計算量 O(n)。
- `int leader(int x)` / `bool same(int x, int y)` — 代表取得・連結判定。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y)` — マージし、成功した場合のみ履歴を積む。計算量 ならし O(lpha(n))。
- `int size(int x)` / `int count() const` — 成分サイズと個数。計算量 ならし O(lpha(n))。
- `int snapshot()` — 現在の履歴サイズ。計算量 O(1)。
- `void rollback(int to)` — スナップショット `to` まで巻き戻す。計算量 O(	ext{巻き戻す回数})。
