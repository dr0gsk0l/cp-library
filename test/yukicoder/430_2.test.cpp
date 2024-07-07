#define PROBLEM "https://yukicoder.me/problems/no/430"
#include <bits/stdc++.h>

#include "library/sequence/AhoCorasick.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    auto ss = FSA::change(s);

    AhoCorasick<char, 26> T;

    int m;
    std::cin >> m;
    while (m--) {
        std::string c;
        std::cin >> c;
        auto cc = FSA::change(c);
        T.add(cc);
    }
    T.build();

    std::cout << T.path_prod(ss) << std::endl;
}