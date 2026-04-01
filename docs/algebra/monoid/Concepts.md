---
documentation_of: library/algebra/monoid/Concepts.hpp
---

# Concepts

- パス: `library/algebra/monoid/Concepts.hpp`
- 概要: モノイド関連の `concept` を定義する。
- 提供インターフェース:
  - `monoid<M>`: `value_type`, `op`, `Lchop`, `Rchop`, `unit` を持つ型を受理する。
  - `commutative_monoid<M>`: `monoid<M>` を満たし、かつ `M::commute` が `true` な型を受理する。
- 計算量: TODO
- 使用例: TODO
