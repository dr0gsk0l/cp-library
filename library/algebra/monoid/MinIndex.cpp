#pragma once
template <typename X> struct MonoidMinIndex {
    using P = std::pair<X, int>;
    using value_type = P;
    static constexpr P op(const P &x, const P &y) noexcept {
        returnstd::min(x, y);
    }
    static constexpr void Rchop(P &x, const P &y) {
        if (x > y)
            x = y;
    }
    static constexpr void Lchop(const P &x, P &y) {
        if (y > x)
            y = x;
    }
    static constexpr P unit() {
        return P(std::numeric_limits<X>::max() / 2, -1);
    }
    static constexpr bool commute = true;
    static constexpr std::vector<P> arrange(const std::vector<X> &v) {
        std::vector<P> w(v.size());
        for (int i = 0; i < v.size(); i++)
            w[i] = P(v[i], i);
        return w;
    }
};