#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <istream>
#include <optional>
#include <ostream>
#include <ranges>
#include <utility>
#include <vector>
template <typename K> struct Matrix {
    using value_type = K;
    using vec = std::vector<K>;
    using mat = std::vector<vec>;
    size_t r, c;
    mat M;

    Matrix(size_t r, size_t c) : r(r), c(c), M(r, vec(c, K())) {}
    Matrix(mat A) : M(A), r(A.size()), c(A[0].size()) {}

    vec &operator[](size_t k) { return M[k]; }
    const vec &operator[](size_t k) const { return M[k]; }

    Matrix &operator+=(const Matrix &A) {
        assert(r == A.r && c == A.c);
        for (size_t i : std::views::iota(0uz, r)) {
            for (size_t j : std::views::iota(0uz, c)) {
                M[i][j] += A[i][j];
            }
        }
        return *this;
    }
    Matrix &operator-=(const Matrix &A) {
        assert(r == A.r && c == A.c);
        for (size_t i : std::views::iota(0uz, r)) {
            for (size_t j : std::views::iota(0uz, c)) {
                M[i][j] -= A[i][j];
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix &A) { return Matrix(M) += A; }
    Matrix operator-(const Matrix &A) { return Matrix(M) -= A; }

    friend Matrix operator*(const Matrix &A, const Matrix &B) {
        assert(A.c == B.r);
        Matrix res(A.r, B.c);
        for (size_t i : std::views::iota(0uz, A.r)) {
            for (size_t k : std::views::iota(0uz, A.c)) {
                for (size_t j : std::views::iota(0uz, B.c)) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return res;
    }
    Matrix &operator*=(const Matrix &A) {
        M = ((*this) * A).M;
        return *this;
    }

    bool operator==(const Matrix &A) {
        if (r != A.r || c != A.c)
            return false;
        for (size_t i : std::views::iota(0uz, r))
            for (size_t j : std::views::iota(0uz, c))
                if (M[i][j] != A[i][j])
                    return false;
        return true;
    }
    bool operator!=(const Matrix &A) { return !((*this) == A); }

    static Matrix I(size_t n) {
        Matrix res(n, n);
        for (size_t i : std::views::iota(0uz, n)) {
            res[i][i] = K(1);
        }
        return res;
    }

    Matrix pow(long long n) const {
        assert(n >= 0 && r == c);
        Matrix A(M), res = I(r);
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
        for (int k : std::views::iota(0, static_cast<int>(c))) {
            if (M[rnk][k] == 0) {
                auto pivot_range = std::views::iota(rnk + 1, static_cast<int>(r));
                auto pivot = std::ranges::find_if(
                    pivot_range, [&](int i) { return M[i][k] != 0; });
                if (pivot != pivot_range.end()) {
                    std::swap(M[*pivot], M[rnk]);
                    cnt ^= 1;
                }
            }
            if (M[rnk][k] == 0)
                continue;
            for (size_t i : std::views::iota(0uz, r)) {
                if (static_cast<int>(i) == rnk) {
                    continue;
                }
                K x = M[i][k] / M[rnk][k];
                for (size_t j : std::views::iota(0uz, c)) {
                    M[i][j] -= M[rnk][j] * x;
                }
            }
            if (++rnk == r)
                break;
        }
        return {rnk, cnt};
    }

    K det() const {
        assert(r == c);
        Matrix A(M);
        const auto &[rnk, cnt] = A.GaussJordan();
        if (rnk != r)
            return 0;
        K res = 1;
        for (size_t i : std::views::iota(0uz, r)) {
            res *= A[i][i];
        }
        return (cnt ? -res : res);
    }

    std::optional<Matrix> inv() const {
        assert(r == c);
        Matrix A(r, c + c);
        for (size_t i : std::views::iota(0uz, r)) {
            for (size_t j : std::views::iota(0uz, c)) {
                A[i][j] = M[i][j];
            }
            for (size_t j : std::views::iota(0uz, c)) {
                A[i][c + j] = K(i == j);
            }
        }
        A.GaussJordan();
        for (size_t i : std::views::iota(0uz, r))
            if (A[i][i] == 0)
                return std::nullopt;
        Matrix res(r, c);
        for (size_t i : std::views::iota(0uz, r)) {
            for (size_t j : std::views::iota(0uz, c)) {
                res[i][j] = A[i][c + j] / A[i][i];
            }
        }
        return res;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &M) {
        os << M.M;
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Matrix &M) {
        for (size_t i : std::views::iota(0uz, M.r)) {
            for (size_t j : std::views::iota(0uz, M.c)) {
                is >> M.M[i][j];
            }
        }
        return is;
    }
};
