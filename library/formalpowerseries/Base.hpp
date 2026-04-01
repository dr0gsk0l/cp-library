#pragma once
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
#include "library/util/Valarray.hpp"

template <typename T, int MX = -1>
struct FormalPowerSeries : Valarray<FormalPowerSeries<T, MX>, T> {
    using Base = Valarray<FormalPowerSeries<T, MX>, T>;
    using FPS = FormalPowerSeries;
    using Base::Base;
    using Base::size;
    using Base::resize;
    using Base::at;
    using Base::begin;
    using Base::end;
    using Base::back;
    using Base::pop_back;
    using Base::operator+=;
    using Base::operator-=;
    using value_type = T;

    void strict(int n) { resize(std::min(size(), size_t(std::max(0, n)))); }

    FormalPowerSeries() = default;

    FormalPowerSeries(const std::vector<T> &f) : Base(f) {}

    static FPS unit() { return {1}; }
    static FPS x() { return {0, 1}; }
#pragma region operator
    FPS operator-() const {
        FPS res = *this;
        for (size_t i = 0; i < res.size(); i++)
            res[i] = -res[i];
        return res;
    }
    FPS &operator+=(const T &a) {
        if (!size())
            resize(1);
        at(0) += a;
        return *this;
    }
    FPS operator+(const T &a) const { return FPS(*this) += a; }
    friend FPS operator+(const T &a, const FPS &f) { return f + a; }

    FPS &operator-=(const T &a) {
        if (!size())
            resize(1);
        at(0) -= a;
        return *this;
    }
    FPS operator-(const T &a) { return FPS(*this) -= a; }
    friend FPS operator-(const T &a, const FPS &f) { return a + (-f); }

    FPS operator*(const FPS &g) const { return FPS(convolution(*this, g)); }
    FPS &operator*=(const FPS &g) { return (*this) = (*this) * g; }

    FPS &operator*=(const T &a) {
        for (size_t i = 0; i < size(); i++)
            at(i) *= a;
        return *this;
    }
    FPS operator*(const T &a) const { return FPS(*this) *= a; }
    friend FPS operator*(const T &a, const FPS &f) { return f * a; }

    FPS operator/(const FPS &g) const { return (*this) * g.inv(int(size())); }
    FPS &operator/=(const FPS &g) { return (*this) = (*this) / g; }

    FPS &operator/=(const T &a) { return *this *= a.inv(); }
    FPS operator/(const T &a) { return FPS(*this) /= a; }

    FPS &operator<<=(const int d) {
        if (d <= 0)
            return *this;
        if (size() == 0)
            return *this = FPS(0);
        resize(int(size()) + d);
        for (int i = int(size()) - 1 - d; i >= 0; i--)
            at(i + d) = at(i);
        for (int i = d - 1; i >= 0; i--)
            at(i) = 0;
        return *this;
    }
    FPS operator<<(const int d) const { return FPS(*this) <<= d; }
    FPS &operator>>=(const int d) {
        if (d <= 0)
            return *this;
        if (d >= size())
            return *this = FPS(0);
        for (size_t i = d; i < size(); i++)
            at(i - d) = at(i);
        strict(int(size()) - d);
        return *this;
    }
    FPS operator>>(const int d) const { return FPS(*this) >>= d; }
#pragma endregion operator

    FPS pre(int n) const {
        if (size() <= n)
            return *this;
        return FPS(this->begin(), this->begin() + n);
    }

    // 最小の非ゼロ次数（すべて 0 のときは size()）を返す
    int order() const {
        for (int i = 0; i < int(size()); i++) {
            if (at(i) != 0)
                return i;
        }
        return int(size());
    }

    void shrink() {
        while (size() && back() == T(0))
            pop_back();
    }

    FPS inv(int SZ = -1) const {
        if (SZ < 0)
            SZ = int(size());
        assert(size() and at(0) != 0);
        FPS res = {at(0).inv()};
        for (int n = 1; n < SZ; n <<= 1) {
            res *= (2 - this->pre(n << 1) * res);
            res.strict(n << 1);
        }
        res.strict(SZ);
        return res;
    }

    // *this = f_1 + f_2 x^n ⇒ [*this←f_1, return f_2]
    FPS separate(int n) {
        if (size() <= n)
            return FPS(0);
        FPS f_2(size() - n);
        for (size_t i = n; i < size(); i++)
            f_2[i - n] = at(i);
        strict(n);
        return f_2;
    }

    T operator()(T a) const {
        T res = 0, b = 1;
        for (size_t i = 0; i < size(); i++, b *= a)
            res += at(i) * b;
        return res;
    }
};
