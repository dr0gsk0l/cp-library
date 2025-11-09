#pragma once
#include "library/mod/Modint.hpp"
#include <optional>
#include <random>
#include <chrono>

template <typename T, T MOD>
bool is_quadratic_residue(Mint<T, MOD> a) {
    if (a == 0) return true;
    return a.pow((MOD - 1) / 2) == 1;
}

template <typename T, T MOD>
std::optional<Mint<T, MOD>> mod_sqrt(Mint<T, MOD> a) {
    if (a == 0) return Mint<T, MOD>(0);
    if (MOD == 2) return a;
    if (!is_quadratic_residue(a)) return std::nullopt;

    if (MOD % 4 == 3) {
        return a.pow((MOD + 1) / 4);
    }

    // Tonelli-Shanks
    long long s = 0, q = MOD - 1;
    while (q % 2 == 0) {
        q /= 2;
        s++;
    }

    // Find a non-quadratic residue z
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    Mint<T, MOD> z;
    do {
        z = rng() % MOD;
    } while (is_quadratic_residue(z));

    long long m = s;
    Mint<T, MOD> c = z.pow(q);
    Mint<T, MOD> t = a.pow(q);
    Mint<T, MOD> r = a.pow((q + 1) / 2);

    while (t != 1) {
        if (t == 0) return Mint<T, MOD>(0);
        long long i = 0;
        Mint<T, MOD> temp = t;
        while (temp != 1) {
            temp *= temp;
            i++;
            if (i == m) return std::nullopt; // Should not happen for quadratic residues
        }

        Mint<T, MOD> b = c.pow(1LL << (m - i - 1));
        m = i;
        c = b * b;
        t *= c;
        r *= b;
    }
    return r;
}
