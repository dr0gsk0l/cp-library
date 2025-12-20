#pragma once
#include <algorithm>
#include <cmath>
#include <ranges>
#include <vector>
template <typename MINT> class OnlineNTT {
    static_assert(MINT::mod == 998244353);
    int d;
    std::vector<MINT> f, g, fg, change_f, change_g, tmp;
    std::vector<std::vector<MINT>> F, G;
    // F[i] : 幅 1<<i の DFT 結果
    std::vector<std::vector<MINT>> cs, cs_inv;
    std::vector<int> x, fst, lst;
    std::vector<MINT> inv;
    int d_lst, lg;

    void DFT(std::vector<MINT> &f, std::vector<MINT> &g, const int lg) {
        // 1<<lg の DFT を行う
        const int n = 1 << lg;
        // f[n/2,n) , g[n/2,n) = 0 が保証されている
        std::ranges::fill(x | std::views::take(n), 0);
        for (int h : std::views::iota(0, lg)) {
            const auto S_range = std::views::iota(0, 1 << h);
            const auto T_range = std::views::iota(0, 1 << (lg - h - 1));
            for (int S : S_range) {
                for (int T : T_range) {
                    const int l = (S << (lg - h)) | T;
                    const int r = l | (1 << (lg - h - 1));

                    x[l] >>= 1;
                    (x[r] >>= 1) |= 1 << (lg - 1);

                    MINT a = f[l];
                    f[l] += f[r] * cs[lg][x[l]];
                    (f[r] *= cs[lg][x[r]]) += a;

                    a = g[l];
                    g[l] += g[r] * cs[lg][x[l]];
                    (g[r] *= cs[lg][x[r]]) += a;
                }
            }
        }
    }

    void IDFT(std::vector<MINT> &f, const int lg) {
        const int n = 1 << lg;
        std::ranges::fill(x | std::views::take(n), 0);
        for (int h : std::views::iota(0, lg) | std::views::reverse) {
            const auto S_range = std::views::iota(0, 1 << h);
            const auto T_range = std::views::iota(0, 1 << (lg - h - 1));
            for (int S : S_range) {
                for (int T : T_range) {
                    const int l = (S << (lg - h)) | T;
                    const int r = l | (1 << (lg - h - 1));

                    x[l] >>= 1;
                    (x[r] >>= 1) |= 1 << (lg - 1);

                    MINT a = f[l];
                    f[l] += f[r] * cs_inv[lg][x[l]];
                    (f[r] *= cs_inv[lg][x[r]]) += a;
                }
            }
        }
        for (int i : std::views::iota(0, n)) {
            f[i] *= inv[lg];
        }
    }

    void IDFT(std::vector<MINT> &f, std::vector<MINT> &g, const int lg) {
        const int n = 1 << lg;
        std::ranges::fill(x | std::views::take(n), 0);
        for (int h : std::views::iota(0, lg) | std::views::reverse) {
            const auto S_range = std::views::iota(0, 1 << h);
            const auto T_range = std::views::iota(0, 1 << (lg - h - 1));
            for (int S : S_range) {
                for (int T : T_range) {
                    const int l = (S << (lg - h)) | T;
                    const int r = l | (1 << (lg - h - 1));

                    x[l] >>= 1;
                    (x[r] >>= 1) |= 1 << (lg - 1);

                    MINT a = f[l];
                    f[l] += f[r] * cs_inv[lg][x[l]];
                    (f[r] *= cs_inv[lg][x[r]]) += a;
                    a = g[l];
                    g[l] += g[r] * cs_inv[lg][x[l]];
                    (g[r] *= cs_inv[lg][x[r]]) += a;
                }
            }
        }
        for (int i : std::views::iota(0, n)) {
            f[i] *= inv[lg];
            g[i] *= inv[lg];
        }
    }

  public:
    OnlineNTT(int n, int m)
        : d(0), d_lst(-1), lg(0), cs(1), cs_inv(1), inv(1), fg(n + m - 1) {}

    MINT query(MINT f_i, MINT g_i) {
        f.push_back(f_i);
        g.push_back(g_i);

        std::ranges::fill(change_f, 0);
        std::ranges::fill(change_g, 0);

        for (size_t h : std::views::iota(0uz, F.size())) {
            if (lst[h] + (1 << h) != d)
                continue;
            for (int i : std::views::iota(0, 1 << h)) {
                change_f[i] = f[d - (1 << h) + 1 + i];
                change_g[i] = g[d - (1 << h) + 1 + i];
            }
            DFT(change_f, change_g, h + 1);
            for (int i : std::views::iota(0, 1 << (h + 1))) {
                change_f[i] *= G[h][i];
                change_g[i] *= F[h][i];
            }
            IDFT(change_f, change_g, h + 1);
            for (int i : std::views::iota(0, (1 << (h + 1)) - 1)) {
                if (fst[h] + lst[h] + 1 + i >= static_cast<int>(fg.size()))
                    break;
                fg[fst[h] + lst[h] + 1 + i] += change_f[i] + change_g[i];
            }
            lst[h] = d;
        }

        if (d_lst + (1 << lg) == d) {
            // サイズ 1<<lg が完成（DFT 後のサイズは 1<<(lg+1))
            const int N = 1 << (lg + 1);
            F.emplace_back(std::vector<MINT>(N, 0));
            G.emplace_back(std::vector<MINT>(N, 0));
            for (int i : std::views::iota(0, 1 << lg)) {
                F.back()[i] = f[d - (1 << lg) + 1 + i];
                G.back()[i] = g[d - (1 << lg) + 1 + i];
            }

            x.resize(N);
            MINT c = MINT(3).pow((MINT::mod - 1) >> (lg + 1));
            cs.emplace_back(std::vector<MINT>(N));
            cs.back()[0] = 1;
            for (int i : std::views::iota(1, N)) {
                cs.back()[i] = cs.back()[i - 1] * c;
            }
            DFT(F.back(), G.back(), lg + 1);

            tmp.resize(N);
            for (int i : std::views::iota(0, N)) {
                tmp[i] = F.back()[i] * G.back()[i];
            }

            c = c.inv();
            cs_inv.emplace_back(std::vector<MINT>(N));
            cs_inv.back()[0] = 1;
            for (int i : std::views::iota(1, N)) {
                cs_inv.back()[i] = cs_inv.back()[i - 1] * c;
            }
            inv.push_back(MINT(N).inv());
            IDFT(tmp, lg + 1);

            for (int i : std::views::iota(0, N - 1)) {
                if ((d_lst + 1) * 2 + i >= static_cast<int>(fg.size()))
                    break;
                fg[(d_lst + 1) * 2 + i] += tmp[i];
            }

            change_f.resize(N);
            change_g.resize(N);

            fst.push_back(d - (1 << lg) + 1);
            lst.push_back(d);
            d_lst = d;
            lg++;
        }

        return fg[d++];
    }
};
