#pragma once
#include <algorithm>
#include <bit>
#include <ranges>
#include <vector>

template <typename MINT>
std::vector<MINT> convolution(std::vector<MINT> f, std::vector<MINT> g) {
    size_t nf = f.size(), ng = g.size();
    if (!nf or !ng)
        return std::vector<MINT>{};
    size_t M = nf + ng - 1;

    if (nf <= 60 or ng <= 60) {
        std::vector<MINT> res(M, 0);
        for (size_t i : std::views::iota(0uz, nf))
            for (size_t j : std::views::iota(0uz, ng))
                res[i + j] += f[i] * g[j];
        return res;
    }

    const int N = std::bit_ceil(static_cast<unsigned>(M));
    const int lg = std::countr_zero(N);
    f.resize(N, 0);
    g.resize(N, 0);

    static_assert(MINT::mod == 998244353);
    MINT c = MINT(3).pow((MINT::mod - 1) >> lg);
    std::vector<MINT> cs(N);
    cs[0] = 1;
    for (int i : std::views::iota(1, N)) {
        cs[i] = cs[i - 1] * c;
    }

    std::vector<int> x(N, 0);
    for (int h : std::views::iota(0, lg)) {
        const auto S_range = std::views::iota(0, 1 << h);
        const auto T_range = std::views::iota(0, 1 << (lg - h - 1));
        for (int S : S_range) {
            for (int T : T_range) {
                int l = (S << (lg - h)) | T;
                int r = l | (1 << (lg - h - 1));

                x[l] >>= 1;
                (x[r] >>= 1) |= 1 << (lg - 1);

                MINT a = f[l];
                f[l] += f[r] * cs[x[l]];
                (f[r] *= cs[x[r]]) += a;

                a = g[l];
                g[l] += g[r] * cs[x[l]];
                (g[r] *= cs[x[r]]) += a;
            }
        }
    }
    for (auto &&[lhs, rhs] : std::views::zip(f, g))
        lhs *= rhs;

    std::ranges::fill(x, 0);
    c = c.inv();
    cs[0] = 1;
    for (int i : std::views::iota(1, N)) {
        cs[i] = cs[i - 1] * c;
    }
    for (int h : std::views::iota(0, lg) | std::views::reverse) {
        const auto S_range = std::views::iota(0, 1 << h);
        const auto T_range = std::views::iota(0, 1 << (lg - h - 1));
        for (int S : S_range) {
            for (int T : T_range) {
                int l = (S << (lg - h)) | T;
                int r = l | (1 << (lg - h - 1));

                x[l] >>= 1;
                (x[r] >>= 1) |= 1 << (lg - 1);

                MINT a = f[l];
                f[l] += f[r] * cs[x[l]];
                (f[r] *= cs[x[r]]) += a;
            }
        }
    }
    f.resize(M);
    MINT Ninv = MINT(N).inv();
    for (size_t i : std::views::iota(0uz, M)) {
        f[i] *= Ninv;
    }
    return f;
}
