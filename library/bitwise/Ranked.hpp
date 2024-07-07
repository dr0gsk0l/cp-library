#pragma once
#include "library/bitwise/Util.hpp"
#define REP_(i, n) for (int i = 0; i < (n); i++)
#define RREP_(i, n) for (int i = (n) - 1; i >= 0; i--)
class BitwiseRanked {
    static int popcount(int S) { return __builtin_popcount(S); }

  public:
    template <typename T>
    static std::vector<std::vector<T>> zeta(const std::vector<T> &A) {
        const int n = bitwise::log2(A.size());
        std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));
        REP_(S, 1 << n) RA[S][popcount(S)] = A[S];
        REP_(i, n)
        REP_(S, 1 << n)
        if (!bitwise::in(S, i))
            REP_(d, n + 1) RA[S | (1 << i)][d] += RA[S][d];
        return RA;
    }
    template <typename T>
    static std::vector<T> mobius(std::vector<std::vector<T>> RA) {
        const int n = bitwise::log2(RA.size());
        REP_(i, n)
        REP_(S, 1 << n)
        if (!bitwise::in(S, i))
            REP_(d, n + 1) RA[S | (1 << i)][d] -= RA[S][d];
        std::vector<T> A(1 << n);
        REP_(S, 1 << n) A[S] = RA[S][popcount(S)];
        return A;
    }
    template <typename T>
    static std::vector<T> convolution(const std::vector<T> &A,
                                      const std::vector<T> &B) {
        const int n = bitwise::log2(A.size());
        auto RA = zeta(A);
        auto RB = zeta(B);
        REP_(S, 1 << n) {
            auto &ra = RA[S], rb = RB[S];
            RREP_(d, n + 1) {
                ra[d] *= rb[0];
                REP_(i, d) ra[d] += ra[i] * rb[d - i];
            }
        }
        return mobius(RA);
    }
};
#undef REP_
#undef RREP_