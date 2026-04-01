#pragma once
#include <vector>
#include "library/bitwise/Ranked.hpp"
#include "library/util/Valarray.hpp"

template <typename T> struct SetPowerSeries : Valarray<SetPowerSeries<T>, T> {
    using Base = Valarray<SetPowerSeries<T>, T>;
    using SPS = SetPowerSeries;
    using Base::Base;
    using Base::size;
    using Base::at;
    using value_type = T;

    SetPowerSeries(const std::vector<T> &f) : Base(f) {}

    SPS operator*(const SPS &b) const {
        return SPS(BitwiseRanked::convolution<T>(*this, b));
    }
    SPS &operator*=(const SPS &b) { return (*this) = (*this) * b; }
};
