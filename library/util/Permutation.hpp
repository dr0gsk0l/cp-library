#pragma once
#include <cassert>
#include <map>
#include <ranges>
#include <utility>
#include <vector>
#include <algorithm>
struct Perm {
    using vi = std::vector<int>;
    // (v[i],i) で座圧
    template <typename T> static vi make_perm(const std::vector<T> &v) {
        vi w = v;
        std::ranges::sort(w);
        std::map<T, int> mp;
        for (size_t i : std::views::iota(0uz, v.size())) {
            if (!i || w[i - 1] != w[i]) {
                mp[w[i]] = static_cast<int>(i);
            }
        }
        for (size_t i : std::views::iota(0uz, v.size())) {
            w[i] = mp[v[i]]++;
        }
        return w;
    }
    // r[p[i]]=i;
    static vi rev(const vi &p) {
        assert(is_permutation(p));
        auto res = p;
        for (size_t i : std::views::iota(0uz, p.size())) {
            res[p[i]] = static_cast<int>(i);
        }
        return res;
    }
    // r[i] = p[q[i]]
    static vi composite(const vi &p, const vi &q) {
        assert(p.size() == q.size());
        assert(is_permutation(p));
        assert(is_permutation(q));
        auto res = p;
        for (size_t i : std::views::iota(0uz, p.size())) {
            res[i] = p[q[i]];
        }
        return res;
    }
    static std::vector<vi> divide_cycle(const vi &p) {
        assert(is_permutation(p));
        int n = p.size();
        std::vector<bool> used(n, false);
        std::vector<vi> res;
        for (int x : p) {
            if (used[x])
                continue;
            used[x] = true;
            res.emplace_back(vi{x});
            int now = p[x];
            while (now != x) {
                assert(!used[now]);
                used[now] = true;
                res.back().push_back(now);
                now = p[now];
            }
        }
        return res;
    }
    static bool is_permutation(const vi &p) {
        int n = p.size();
        std::vector<bool> used(n, false);
        for (int x : p) {
            if (used[x])
                return false;
            used[x] = true;
        }
        return true;
    }

  private:
    static void rearrange(const vi &p) {}
    template <typename T>
    static void execute_rearrange(const vi &p, std::vector<T> &v) {
        assert(p.size() == v.size());
        auto w = v;
        for (size_t i : std::views::iota(0uz, p.size())) {
            w[i] = v[p[i]];
        }
        std::swap(v, w);
    }

  public:
    // v を (p[i],v[i]) での昇順にする
    template <typename Head, typename... Tail>
    static void rearrange(const vi &p, Head &v, Tail &...tail) {
        execute_rearrange(p, v);
        rearrange(p, tail...);
    }
};
