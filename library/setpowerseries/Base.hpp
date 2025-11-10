#pragma once
#include "library/bitwise/Ranked.hpp"
#include "library/util/Valarray.hpp"

template <typename T> struct SetPowerSeries : Valarray<T> {
    using SPS = SetPowerSeries;
    using Valarray<T>::Valarray;
    using Valarray<T>::size;
    using Valarray<T>::at;
    using value_type = T;

    SetPowerSeries(const std::vector<T> &f) : Valarray<T>(f) {}

    SPS operator*(const SPS &b) const {
        return SPS(BitwiseRanked::convolution<T>(*this, b));
    }
    SPS &operator*=(const SPS &b) { return (*this) = (*this) * b; }
};
