#pragma once
#include <queue>
#include <tuple>
#include <vector>

template <typename F>
std::vector<int> monotone_minima(int n, int m, const F &argmin) {
    // argmin(i,l,r) : argmin_{j\in[l,r)} A[i][j]
    std::vector<int> res(n);
    std::queue<std::tuple<int, int, int, int>> que;
    que.emplace(0, n, 0, m);

    while (que.size()) {
        auto [u, d, l, r] = que.front();
        que.pop();

        if (u == d)
            return;
        int m = (u + d) >> 1;
        res[m] = argmin(m, l, r);
        que.emplace(u, m, l, res[m] + 1);
        que.emplace(m + 1, d, res[m], r);
    }
    return res;
}