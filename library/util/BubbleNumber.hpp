#pragma once
#include "library/util/InversionNumber.hpp"
template <typename T>
long long bubble_number(const std::vector<T> &v, const std::vector<T> &w) {
    int n = v.size();
    assert(w.size() == n);
    std::map<T, std::queue<int>> mp;
    for (int i = 0; i < n; i++)
        mp[w[i]].push(i);
    std::vector<int> idx(n);
    REP (i, n) {
        if (!mp[v[i]].size())
            return -1;
        idx[i] = mp[v[i]].front();
        mp[v[i]].pop();
    }
    return inversion_number(idx);
}