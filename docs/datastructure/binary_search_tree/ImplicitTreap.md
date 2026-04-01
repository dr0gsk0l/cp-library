---
documentation_of: library/datastructure/binary_search_tree/ImplicitTreap.hpp
---

# ImplicitTreap

## 概要
- パス: `library/datastructure/binary_search_tree/ImplicitTreap.hpp`
- 配列を暗に保持する Treap。Lazy テンプレートに依存して区間更新・反転・回転などを提供。

## 公開 API (平均 O(\log n))
- `void insert(int pos, int x)` — 位置 `pos` に値を挿入。
- `void erase(int pos)` — 位置 `pos` の要素を削除。
- `void add(int l, int r, int x)` — 区間 $[l,r)$ に Lazy の加算を適用（Lazy 実装依存）。
- `int findmin(int l, int r)` — 区間 $[l,r)$ の最小値を取得（Lazy 実装依存）。
- `void reverse(int l, int r)` — 区間 $[l,r)$ を反転。
- `void rotate(int l, int m, int r)` — 区間 $[l,r)$ を先頭が $m$ になるよう回転。
- `void dump()` — 全要素を出力（デバッグ用途）。
