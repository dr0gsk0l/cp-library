template <typename CHAR = char> struct MonoidRollingHash {
    using u64 = std::uint64_t;
    using u128 = unsigned __int128;
    using value_type = std::pair<u64, u64>;
    using X = value_type;
    static constexpr u64 mod = (1ULL << 61) - 1, base = 20120620;
    static constexpr u64 mul(u64 a, u64 b) {
        u128 u = static_cast<u128>(a) * b;
        a = (u >> 61) + u & mod;
        return a >= mod ? a - mod : a;
    }

    static constexpr X op(const X &x, const X &y) {
        const auto &[vx, px] = x;
        const auto &[vy, py] = y;
        return X((mul(vx, py) + vy) & mod, mul(px, py));
    }
    static constexpr void Rchop(X &x, const X &y) { x = op(x, y); }
    static constexpr void Lchop(const X &x, X &y) { y = op(x, y); }
    static constexpr X unit() { return X(0, 1); }
    static constexpr bool commute = false;

    static constexpr X to_X(const CHAR &c) { return X(c, base); }

    template <typename STRING>
    static constexpr std::vector<X> to_vec(const STRING &s) {
        std::vector<X> ret(s.size());
        for (int i = 0; i < s.size(); i++)
            ret[i] = to_X(s[i]);
        return ret;
    }
};