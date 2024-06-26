#pragma once
template <typename T> struct YX {
    T y, x;
    YX() = default;
    YX(T y, T x) : y(y), x(x) {}
    YX(const std::pair<T, T> &yx) : y(yx.first), x(yx.second) {}

    YX operator+() const { return *this; }
    YX operator-() const { return YX(-y, -x); }

    YX &operator++() {
        y++;
        x++;
        return *this;
    }
    YX &operator--() {
        y--;
        x--;
        return *this;
    }
    YX &operator++(int) {
        YX a = *this;
        ++*this;
        return a;
    }
    YX &operator--(int) {
        YX a = *this;
        --*this;
        return a;
    }

    YX &operator+=(const YX &v) {
        y += v.y;
        x += v.x;
        return *this;
    }
    YX &operator-=(const YX &v) {
        y -= v.y;
        x -= v.x;
        return *this;
    }
    YX &operator*=(const T &a) {
        y *= a;
        x *= a;
        return *this;
    }
    YX &operator/=(const T &a) {
        y /= a;
        x /= a;
        return *this;
    }

    friend YX operator+(const YX &u, const YX &v) { return YX(u) += v; }
    friend YX operator-(const YX &u, const YX &v) { return YX(u) -= v; }
    friend YX operator*(const YX &u, const T &a) { return YX(u) *= a; }
    friend YX operator*(const T &a, const YX &u) { return YX(u) *= a; }
    friend YX operator/(const YX &u, const T &a) { return YX(u) /= a; }

    bool operator<(const YX &v) const { return y != v.y ? y < v.y : x < v.x; }
    bool operator>(const YX &v) const { return y != v.y ? y > v.y : x > v.x; }
    bool operator==(const YX &v) const { return y == v.y and x == v.x; }
    bool operator<=(const YX &v) const { return !(*this > v); }
    bool operator>=(const YX &v) const { return !(*this < v); }
    bool operator!=(const YX &v) const { return !(*this == v); }

    friend T dot(const YX &u, const YX &v) { return u.y * v.y + u.x * v.x; }
    T square_abs() { return dot(*this, *this); }
    T abs() { return sqrt(square_abs()); }

    friend std::istream &operator>>(std::istream &is, YX &v) {
        is >> v.y >> v.x;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const YX &v) {
        os << v.y << " " << v.x;
        return os;
    }

    static YX direction(const char &c) {
        if (c == 'R')
            return {0, 1};
        if (c == 'L')
            return {0, -1};
        if (c == 'U')
            return {-1, 0};
        if (c == 'D')
            return {1, 0};
        return {0, 0};
    }
};