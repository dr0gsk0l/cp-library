#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2647"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/graph/MinimumSpanningArborescence.hpp"
#include "library/graph/WeightedGraph.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<bool> koho(n, true);
    WeightedGraph<int> G(n);
    REP (_, m) {
        int a, b;
        std::cin >> a >> b;
        koho[b] = false;
        G.add_arc(a, b, 0);
        G.add_arc(b, a, 1);
    }

    int mn = 1e9;
    std::vector<int> ans;
    REP (i, n)
        if (koho[i]) {
            auto res = minimum_spanning_arborescence(G, i);
            assert(res.has_value());
            const auto &[val, tree] = res.value();
            if (mn == val)
                ans.push_back(i);
            if (mn > val) {
                mn = val;
                ans = {i};
            }
        }
    std::cout << ans.size() << " " << mn << "\n";
    REP (i, ans.size())
        std::cout << ans[i] << "\n "[i + 1 < ans.size()];
}