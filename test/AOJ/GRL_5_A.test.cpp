#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include <bits/stdc++.h>

#include "library/tree/ReRooting.hpp"
#include "library/tree/WeightedTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    WeightedTree<int> t(n);
    t.scan(0);

    ReRooting<WeightedTree<int>, int> RR(t);
    auto score = [&](int now, auto &e) { return now + e.weight; };
    auto merge = [&](int &now, int add) {
        if (now < add)
            now = add;
    };
    auto ans = RR.build(score, merge, 0);

    int fans = 0;
    for (int p : ans)
        fans = std::max(fans, p);
    std::cout << fans << std::endl;
}