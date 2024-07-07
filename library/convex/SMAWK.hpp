#pragma once
#include <vector>

template <class Select>
std::vector<int> smawk(int h, int w, const Select &select) {
    // r(k,*) : (0-indexed) k回目のループで考える行集合
    constexpr static auto r = [](int k, int i) { return ((i + 1) << k) - 1; };

    // k 番目には r(k,*) の答えとなる列候補が入る
    std::vector<std::vector<int>> cols(std::bit_width(size_t(h)));
    cols[0].resize(w);
    std::iota(cols[0].begin(), cols[0].end(), 0);

    for (int k = 1; k < cols.size(); k++) {
        const auto &col = cols[k - 1];
        auto &nxt = cols[k];
        for (int j : col) {
            while (nxt.size() and select(r(k, nxt.size() - 1), nxt.back(), j))
                nxt.pop_back();
            if (r(k, nxt.size()) < h)
                nxt.push_back(j);
        }
    }

    std::vector<int> res(h);

    for (int k = cols.size() - 1; k >= 0; k--) {
        const auto &col = cols[k];
        for (int i = 0, j = 0; r(k, i) < h; i += 2) {
            res[r(k, i)] = col[j];
            int end = (r(k, i + 1) < h ? res[r(k, i + 1)] : col.back());
            while (col[j] != end) {
                if (select(r(k, i), res[r(k, i)], col[++j]))
                    res[r(k, i)] = col[j];
            }
        }
    }

    return res;
}