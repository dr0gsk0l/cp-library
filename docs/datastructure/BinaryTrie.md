# BinaryTrie

## 概要
- パス: `library/datastructure/BinaryTrie.hpp`
- 0/1 トライによる multiset。xor を絡めた順位取得が得意。
- ここでの `LOG` は値域のビット長（テンプレート引数）。`LOG=30` なら $0 \le \text{value} < 2^{30}$ を前提に動作し、計算量の $\mathrm{LOG}$ もこのビット長を指す。

## 公開 API
- `int add(const T& a, COUNT num = 1)` — 値を `num` 回追加し終端ノード番号を返す。計算量 $O(\mathrm{LOG})$.
- `int node_idx(const T& a)` — 値が存在すれば終端ノード番号、無ければ $-1$。計算量 $O(\mathrm{LOG})$.
- `COUNT count(const T& a)` — 値の出現回数。計算量 $O(\mathrm{LOG})$.
- `COUNT size()` — 全要素数。計算量 O(1)。
- `T k_th(COUNT k, T xor_add = 0)` — 各値に $\oplus\,\mathrm{xor\_add}$ を加えたと仮定したときの $k$ 番目 (0-indexed) の値。計算量 $O(\mathrm{LOG})$.
- `T min(T xor_add = 0)` / `T max(T xor_add = 0)` — xor 適用後の最小/最大値。計算量 $O(\mathrm{LOG})$.
