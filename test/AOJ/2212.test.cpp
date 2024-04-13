#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212"
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/graph/Grid.cpp"
#include "library/sequence/AhoCorasick.cpp"

const std::map<char, int> mp{{'D', 0}, {'R', 1}, {'U', 2}, {'L', 3}};

int solve(int h, int w) {
    std::vector<std::string> s(h);
    REP (i, h)
        std::cin >> s[i];

    Grid<char> GR(s, '#');
    int S = GR.find('S'), T = GR.find('G');
    auto &G = GR.G;

    AhoCorasick<char, 4> AC;
    int m;
    std::cin >> m;
    REP (_, m) {
        std::string t;
        std::cin >> t;
        std::vector<char> tt(t.size());
        REP (i, t.size())
            tt[i] = mp.at(t[i]);
        AC.add(tt);
    }
    AC.build();

    std::vector dp(h * w, std::vector<int>(AC.size(), -1));
    std::queue<std::pair<int, int>> que;
    que.emplace(S, 0);
    dp[S][0] = 0;
    while (que.size()) {
        auto [idx, now] = que.front();
        que.pop();
        for (auto &e : G[idx]) {
            int nxt = AC.nxt(now, e.weight);
            if (AC.val(nxt))
                continue;
            if (dp[e.to][nxt] < 0) {
                dp[e.to][nxt] = dp[idx][now] + 1;
                que.emplace(e.to, nxt);
            }
            if (e.to == T)
                return dp[e.to][nxt];
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w;
    while (cin >> h >> w, h)
        std::cout << solve(h, w) << "\n";
}