#define PROBLEM "https://yukicoder.me/problems/no/1002"
#include <bits/stdc++.h>

#include "library/tree/CentroidDecomposition.hpp"
#include "library/tree/WeightedTree.hpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    WeightedTree<int> T(n);
    T.scan(1);

    ll ans = 0;

    CentroidDecomposition CD(T);
    std::map<std::pair<int, int>, int> m2; // m2[c1,c2]:c1,c2 組の数
    std::map<int, int> m1,                 // m1[c]:c 単色の数
        m2_sum;                            // m2_sum[c]:c を含む二色の数
    int m1_sum = 0;                        // 単色の合計
    bool empty = false;

    // k+1 : 色が三色以上
    // -1 : 色が未定
    // 色は後ろから埋まる 両方埋まった場合は minmax

    auto F = [&](const std::pair<int, int> &cc, const auto &e) {
        auto [c1, c2] = cc;
        int c = e.weight;
        if (c1 > k || c1 == c || c2 == c)
            return cc;
        if (~c1)
            return std::make_pair(k + 1, k + 1);
        if (c > c2)
            std::swap(c, c2);
        return std::make_pair(c, c2);
    };
    auto G = [&](std::pair<int, int> cc, bool add) {
        auto [c1, c2] = cc;
        if (c1 > k)
            return;
        ll sum = 0;
        if (~c1) {
            if (m2.count(cc))
                sum += m2[cc];
            if (m1.count(c1))
                sum += m1[c1];
            if (m1.count(c2))
                sum += m1[c2];
            if (empty)
                sum++;
            m2[cc]++;
            m2_sum[c1]++;
            m2_sum[c2]++;
        } else if (~c2) {
            sum += m1_sum;
            if (m1.count(c2))
                sum -= m1[c2];
            if (m2_sum.count(c2))
                sum += m2_sum[c2];
            m1_sum++;
            m1[c2]++;
        } else
            empty = true;

        if (add)
            ans += sum;
        else
            ans -= sum;
    };
    auto H = [&](bool add) {
        m2.clear();
        m1.clear();
        m2_sum.clear();
        m1_sum = empty = 0;
    };

    CD.all_calc(std::make_pair(-1, -1), F, G, H);

    std::cout << ans << std::endl;
}
