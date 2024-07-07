#include "library/bitwise/Ranked.cpp"
template <typename T> struct SetPowerSeries : std::vector<T> {
    using SPS = SetPowerSeries;
    using value_type = T;
    using std::vector<T>::vector;
    using std::vector<T>::resize;
    using std::vector<T>::at;
    using std::vector<T>::size;

    SetPowerSeries(const std::vector<T> &f) {
        resize(f.size());
        for (int i = 0; i < size(); i++)
            at(i) = f[i];
    }

    SPS operator-() const {
        SPS ret(*this);
        for (auto &a : ret)
            a = -a;
        return ret;
    }

    SPS &operator+=(const SPS &b) {
        if (size() < b.size())
            resize(b.size(), 0);
        for (int i = 0; i < size(); i++)
            at(i) += b[i];
        return *this;
    }
    SPS operator+(const SPS &b) const { return SPS(*this) += b; }

    SPS &operator-=(const SPS &b) {
        if (size() < b.size())
            resize(b.size(), 0);
        for (int i = 0; i < size(); i++)
            at(i) -= b[i];
        return *this;
    }
    SPS operator-(const SPS &b) const { return SPS(*this) -= b; }

    SPS operator*(const SPS &b) const {
        return SPS(BitwiseRanked::convolution<T>(*this, b));
    }
    SPS &operator*=(const SPS &b) { return (*this) = (*this) * b; }
};
