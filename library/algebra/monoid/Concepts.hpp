#pragma once
#include <concepts>

template <class M>
concept monoid = requires(typename M::value_type x) {
    { M::op(x, x) } -> std::same_as<typename M::value_type>;
    { M::Lchop(x, x) };
    { M::Rchop(x, x) };
    { M::unit() } -> std::same_as<typename M::value_type>;
};

template <class M>
concept commutative_monoid = monoid<M> and requires {
    { M::commute } -> std::convertible_to<bool>;
} and M::commute;
