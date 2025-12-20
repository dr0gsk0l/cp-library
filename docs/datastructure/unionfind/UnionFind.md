# UnionFind

## 概要
- パス: `library/datastructure/unionfind/UnionFind.hpp`
- 経路圧縮＋ union-by-size の素集合データ構造。

## 公開 API
- `UnionFind(int n)` — 要素数 $n$ で初期化。計算量 O(n)。
- `int leader(int x)` — 要素 $x$ の代表元。計算量 ならし O(lpha(n))。
- `bool same(int x, int y)` — 連結判定。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y)` — 成分を併合し、変化したら `true`。計算量 ならし O(lpha(n))。
- `int size(int x)` — 要素 $x$ を含む成分サイズ。計算量 ならし O(lpha(n))。
- `int count() const` — 連結成分数。計算量 O(1)。
- `std::vector<std::vector<int>> groups()` — 各成分の要素リスト。計算量 O(n)。
