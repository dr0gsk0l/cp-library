#pragma once
#include "library/algebra/group/CntSum.hpp"
#include "library/algebra/monoid/Set.hpp"
template <typename X> struct LazySetSum {
    using MX = GroupCntSum<X>;
    using MF = MonoidSet<X>;
    using P = typename MX::value_type;
    using F = typename MF::value_type;
    static constexpr P mapping(const F &f, const P &x) {
        if (f.has_value())
            return {f.value() * x.second, x.second};
        return x;
    }
};