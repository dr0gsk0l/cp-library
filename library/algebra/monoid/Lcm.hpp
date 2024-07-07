template <typename X> struct MonoidLcm {
    using value_type = X;
    static constexpr X op(const X &x, const X &y) noexcept {
        return std::lcm(x, y);
    }
    static constexpr void Rchop(X &x, const X &y) { x = std::lcm(x, y); }
    static constexpr void Lchop(const X &x, X &y) { y = std::lcm(x, y); }
    static constexpr X unit() { return 1; }
    static constexpr bool commute = true;
};