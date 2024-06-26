#pragma once
template <typename T> struct XY {
    T x, y;
    XY() = default;
    XY(T x, T y) : x(x), y(y) {}
    XY(const std::pair<T, T> &xy) : x(xy.first), y(xy.second) {}

    XY operator+() const { return *this; }
    XY operator-() const { return XY(-x, -y); }

    XY &operator++() {
        x++;
        y++;
        return *this;
    }
    XY &operator--() {
        x--;
        y--;
        return *this;
    }
    XY &operator++(int) {
        XY a = *this;
        ++*this;
        return a;
    }
    XY &operator--(int) {
        XY a = *this;
        --*this;
        return a;
    }

    XY &operator+=(const XY &v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    XY &operator-=(const XY &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    XY &operator*=(const T &a) {
        x *= a;
        y *= a;
        return *this;
    }
    XY &operator/=(const T &a) {
        x /= a;
        y /= a;
        return *this;
    }

    friend XY operator+(const XY &u, const XY &v) { return XY(u) += v; }
    friend XY operator-(const XY &u, const XY &v) { return XY(u) -= v; }
    friend XY operator*(const XY &u, const T &a) { return XY(u) *= a; }
    friend XY operator*(const T &a, const XY &u) { return XY(u) *= a; }
    friend XY operator/(const XY &u, const T &a) { return XY(u) /= a; }

    bool operator<(const XY &v) const { return x != v.x ? x < v.x : y < v.y; }
    bool operator>(const XY &v) const { return x != v.x ? x > v.x : y > v.y; }
    bool operator==(const XY &v) const { return x == v.x and y == v.y; }
    bool operator<=(const XY &v) const { return !(*this > v); }
    bool operator>=(const XY &v) const { return !(*this < v); }
    bool operator!=(const XY &v) const { return !(*this == v); }

    double arg() const { return atan2(y, x); }

    // [0,2pi) で θ(u)<θ(v) の時 true
    // (0,0) は 2pi に相当
    // static bool angle_cmp(const XY&u,const XY&v){
    //  using U=conditional_t< is_same_v<T,int>,long long,T>;
    //  if(u==XY(0,0))return false;
    //  if(v==XY(0,0))return true;
    //  if(u.y==0){
    //    if(u.x>0)return true;
    //    if(v.y==0)return v.x<0;
    //    return v.y<0;
    //  }
    //  if(u.y>0){
    //    if(v.y==0)return v.x<0;
    //    if(v.y<0)return true;
    //    return U(v.x)*u.y <= U(u.x)*v.y;
    //  }
    //  if(v.y>=0)return false;
    //  return U(v.x)*u.y <= U(u.x)*v.y;
    //}

    friend T dot(const XY &u, const XY &v) { return u.x * v.x + u.y * v.y; }
    T norm() { return dot(*this, *this); }
    T abs() { return sqrt(norm()); }

    friend std::istream &operator>>(std::istream &is, XY &v) {
        is >> v.x >> v.y;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const XY &v) {
        os << v.x << " " << v.y;
        return os;
    }

    static XY direction(const char &c) {
        if (c == 'R')
            return {1, 0};
        if (c == 'L')
            return {-1, 0};
        if (c == 'U')
            return {0, -1};
        if (c == 'D')
            return {0, 1};
        return {0, 0};
    }
};