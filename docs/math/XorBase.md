---
documentation_of: library/math/XorBase.hpp
---

# XorBase

## パス

`library/math/XorBase.hpp`

## 概要

`unsigned` 整数列に対する XOR 線形基底。追加・簡約・所属判定を扱える。

## 保持する性質

- `basis` の各要素は 0 でなく、互いに一次独立。
- `basis` の張る空間は、これまでに `add` に渡した値全体の張る空間と一致する。
- `basis` の各要素の `msb` は相異なり、ある `b` の `msb` は他のどの基底ベクトルにも立っていない。
- `add(x)` では、まず既存基底で `x` を簡約することで `x` の `msb` を既存基底のどれとも異なるようにし、その後 `b = min(b, b ^ x)` により既存基底からその `msb` を消している。
- 内部配列の順序は保証しない。特に `vectors()` が pivot の降順や行基本変形後の一意な形を返すとは限らない。

## 提供インターフェース

- `XorBase()`
- `XorBase(const std::vector<T>& v)`
- `bool add(T x)`: `x` を基底に追加する。一次独立なら `true`。
- `T reduce(T x) const`: 基底で `x` をできるだけ小さくした値を返す。
- `bool contains(T x) const`: `x` が基底の線形結合で作れるなら `true`。
- `size_t size() const`
- `bool empty() const`
- `const std::vector<T>& vectors() const`: 内部で保持している基底ベクトルを返す。

## 計算量

- `add`, `reduce`, `contains`: `O(rank)`
- `size`, `empty`, `vectors`: `O(1)`

## 使用例

```cpp
#include "library/math/XorBase.hpp"

XorBase<unsigned long long> basis;
basis.add(3);
basis.add(5);

bool ok = basis.contains(6);
auto y = basis.reduce(7);
```
