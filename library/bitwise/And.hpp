#pragma once
#include "library/bitwise/Util.hpp"
#define REP_(i, n) for (int i = 0; i < (n); i++)
struct BitwiseAnd {
    template <typename T> static void zeta(std::vector<T> &A) {
        int n = bitwise::log2(A.size());
        REP_(k, n)
        REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] += A[S ^ (1 << k)];
    }
    template <typename T> static void mobius(std::vector<T> &A) {
        int n = bitwise::log2(A.size());
        REP_(k, n)
        REP_(S, 1 << n) if (!bitwise::in(S, k)) A[S] -= A[S ^ (1 << k)];
    }
    template <typename T>
    static std::vector<T> convolution(std::vector<T> A, std::vector<T> B) {
        assert(A.size() == B.size());
        zeta(A);
        zeta(B);
        REP_(i, A.size()) A[i] *= B[i];
        mobius(A);
        return A;
    }
};
#undef REP_