---
documentation_of: library/datastructure/unionfind/PartialPersistentUnionFind.hpp
---

# PartialPersistentUnionFind

## 概要
- パス: `library/datastructure/unionfind/PartialPersistentUnionFind.hpp`
- 時刻付きでマージを記録し、任意時刻の連結性やサイズを問い合わせられる部分永続 UnionFind。

## 公開 API
- `PartialPersistentUnionFind(int n)` — 初期化。計算量 O(n)。
- `int leader(int x, int t)` — 時刻 $t$ における代表。計算量 O(\log n)。
- `bool same(int x, int y, int t)` — 時刻 $t$ の連結判定。計算量 O(\log n)。
- `bool merge(int x, int y, int t)` — 時刻 $t$ でマージ。計算量 ならし O(lpha(n))。
- `int size(int x, int t)` — 時刻 $t$ の成分サイズ。計算量 O(\log n)。
