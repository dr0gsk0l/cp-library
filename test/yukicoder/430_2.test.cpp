#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <bits/stdc++.h>

#include "library/sequence/AhoCorasick.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    cin >> s;
    auto ss = FSA::change(s);

    AhoCorasick<char, 26> T;

    int m;
    cin >> m;
    while (m--) {
        string c;
        cin >> c;
        auto cc = FSA::change(c);
        T.add(cc);
    }
    T.build();

    std::cout << T.path_prod(ss) << std::endl;
}