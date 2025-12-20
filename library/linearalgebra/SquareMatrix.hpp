#pragma once
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <istream>
#include <ranges>
#include <ostream>
#include <utility>
#include <vector>
template <typename K, size_t N> struct SquareMatrix {
    using value_type = K;
    using vec = std::array<K, N>;
    using mat = std::array<vec, N>;
    mat M;

    SquareMatrix(K a = 0) {
        for (vec &v : M)
            v.fill(0);
        if (a != 0)
            for (size_t i : std::views::iota(0uz, N)) {
                M[i][i] = a;
            }
    }
    SquareMatrix(const mat &A) : M(A) {}
    SquareMatrix(const std::vector<std::vector<K>> &v) {
        assert(v.size() == N and v[0].size() == N);
        for (size_t i : std::views::iota(0uz, N)) {
            for (size_t j : std::views::iota(0uz, N)) {
                M[i][j] = v[i][j];
            }
        }
    }

    vec &operator[](size_t k) { return M[k]; }
    const vec &operator[](size_t k) const { return M[k]; }

    SquareMatrix &operator+=(const SquareMatrix &A) {
        for (size_t i : std::views::iota(0uz, N)) {
            for (size_t j : std::views::iota(0uz, N)) {
                M[i][j] += A[i][j];
            }
        }
        return *this;
    }
    SquareMatrix &operator-=(const SquareMatrix &A) {
        for (size_t i : std::views::iota(0uz, N)) {
            for (size_t j : std::views::iota(0uz, N)) {
                M[i][j] -= A[i][j];
            }
        }
        return *this;
    }
    SquareMatrix operator+(const SquareMatrix &A) const {
        return SquareMatrix(M) += A;
    }
    SquareMatrix operator-(const SquareMatrix &A) const {
        return SquareMatrix(M) -= A;
    }

    friend SquareMatrix operator*(const SquareMatrix &A,
                                  const SquareMatrix &B) {
        SquareMatrix res;
        for (size_t i : std::views::iota(0uz, N)) {
            for (size_t k : std::views::iota(0uz, N)) {
                for (size_t j : std::views::iota(0uz, N)) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return res;
    }
    SquareMatrix &operator*=(const SquareMatrix &A) {
        M = ((*this) * A).M;
        return *this;
    }

    SquareMatrix &operator/=(const SquareMatrix &A) {
        return (*this) *= A.inv();
    }
    SquareMatrix operator/(const SquareMatrix &A) const {
        return SquareMatrix(M) /= A;
    }

    bool operator==(const SquareMatrix &A) {
        for (size_t i : std::views::iota(0uz, N))
            for (size_t j : std::views::iota(0uz, N))
                if (M[i][j] != A[i][j])
                    return false;
        return true;
    }
    bool operator!=(const SquareMatrix &A) { return !((*this) == A); }

    static SquareMatrix I() { return SquareMatrix(1); }

    SquareMatrix pow(long long n) const {
        assert(n >= 0);
        SquareMatrix A(M), res(1);
        while (n) {
            if (n & 1)
                res *= A;
            A *= A;
            n >>= 1;
        }
        return res;
    }

    std::pair<int, int> GaussJordan() {
        int rnk = 0, cnt = 0;
        for (size_t k : std::views::iota(0uz, N)) {
            if (M[rnk][k] == 0) {
                auto pivot_range = std::views::iota(rnk + 1, static_cast<int>(N));
                auto pivot = std::ranges::find_if(
                    pivot_range, [&](int i) { return M[i][k] != 0; });
                if (pivot != pivot_range.end()) {
                    std::swap(M[*pivot], M[rnk]);
                    cnt ^= 1;
                }
            }
            if (M[rnk][k] == 0)
                continue;
            for (size_t i : std::views::iota(0uz, N)) {
                if (static_cast<int>(i) == rnk) {
                    continue;
                }
                K x = M[i][k] / M[rnk][k];
                for (size_t j : std::views::iota(0uz, N)) {
                    M[i][j] -= M[rnk][j] * x;
                }
            }
            if (++rnk == N)
                break;
        }
        return {rnk, cnt};
    }

    K det() const {
        SquareMatrix A(M);
        const auto &[rnk, cnt] = A.GaussJordan();
        if (rnk != N)
            return 0;
        K res = 1;
        for (size_t i : std::views::iota(0uz, N)) {
            res *= A[i][i];
        }
        return (cnt ? -res : res);
    }

    SquareMatrix inv() const {
        SquareMatrix A(M), B(1);
        for (size_t k : std::views::iota(0uz, N)) {
            if (A[k][k] == 0) {
                auto pivot_range = std::views::iota(k + 1, static_cast<int>(N));
                auto pivot = std::ranges::find_if(
                    pivot_range, [&](int i) { return A[i][k] != 0; });
                if (pivot != pivot_range.end()) {
                    std::swap(A[*pivot], A[k]);
                    std::swap(B[*pivot], B[k]);
                }
            }
            assert(A[k][k] != 0);
            for (size_t i : std::views::iota(0uz, N)) {
                if (static_cast<int>(i) == k) {
                    continue;
                }
                K x = A[i][k] / A[k][k];
                for (size_t j : std::views::iota(0uz, N)) {
                    A[i][j] -= A[k][j] * x;
                    B[i][j] -= B[k][j] * x;
                }
            }
            K x = A[k][k];
            for (size_t j : std::views::iota(0uz, N)) {
                A[k][j] /= x;
                B[k][j] /= x;
            }
        }
        return B;
    }

    friend std::ostream &operator<<(std::ostream &os, const SquareMatrix &M) {
        for (size_t i : std::views::iota(0uz, N)) {
            for (size_t j : std::views::iota(0uz, N)) {
                os << M.M[i][j] << "\n "[j + 1 < N];
            }
        }
        return os;
    }
    friend std::istream &operator>>(std::istream &is, SquareMatrix &M) {
        for (size_t i : std::views::iota(0uz, N)) {
            for (size_t j : std::views::iota(0uz, N)) {
                is >> M.M[i][j];
            }
        }
        return is;
    }
};
