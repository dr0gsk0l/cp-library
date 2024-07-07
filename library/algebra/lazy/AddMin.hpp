#pragma once
#include "library/algebra/group/Add.hpp"
#include "library/algebra/monoid/Min.hpp"
template <typename X> struct LazyAddMin {
    using MX = MonoidMin<X>;
    using MF = GroupAdd<X>;
    static constexpr X mapping(const X &f, const X &x) { return f + x; }
};