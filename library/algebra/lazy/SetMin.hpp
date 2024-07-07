#pragma once
#include "library/algebra/monoid/Min.hpp"
#include "library/algebra/monoid/Set.hpp"
template <typename X> struct LazySetMin {
    using MX = MonoidMin<X>;
    using MF = MonoidSet<X>;
    using F = typename MF::value_type;
    static constexpr X mapping(const F &f, const X &x) { return f.value_or(x); }
};