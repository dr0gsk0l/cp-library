#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include <bits/stdc++.h>

#include "library/sequence/RollingHash.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string t;
    cin >> t;
    RollingHash RH(FSa::change(t));

    string p;
    cin >> p;
    auto h = RollingHash<char>::full_hash(FSa::change(p));

    for (int i = 0; i + p.size() <= t.size(); i++)
        if (RH.get_hash(i, i + p.size()) == h)
            std::cout << i << "\n";
}