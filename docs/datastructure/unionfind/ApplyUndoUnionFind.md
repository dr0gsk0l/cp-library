# ApplyUndoUnionFind

## 概要
- パス: `library/datastructure/unionfind/ApplyUndoUnionFind.hpp`
- 作用付き UnionFind の巻き戻し可能版。

## 公開 API
- `ApplyUndoUnionFind(int n, const std::vector<X>& w)` — 初期化。計算量 O(n)。
- `int leader(int x)` / `bool same(int x, int y)` / `int size(int x)` / `int count() const` — 基本操作。計算量 ならし O(lpha(n))。
- `X prod(int x)` — 成分値。計算量 ならし O(lpha(n))。
- `void apply(int x, F f)` — 成分に作用を合成。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y)` — マージ（履歴保存）。計算量 ならし O(lpha(n))。
- `int snapshot()` / `void rollback(int to)` — スナップショット取得と巻き戻し。計算量 O(1) / O(	ext{巻き戻し長})。
