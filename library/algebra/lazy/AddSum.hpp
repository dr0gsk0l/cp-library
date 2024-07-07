#pragma once
#include "library/algebra/group/Add.hpp"
#include "library/algebra/group/CntSum.hpp"
template <typename X> struct LazyAddSum {
    using MX = GroupCntSum<X>;
    using MF = GroupAdd<X>;
    using S = typename MX::value_type;
    static constexpr S mapping(const X &f, const S &x) {
        return {x.first + f * x.second, x.second};
    }
};