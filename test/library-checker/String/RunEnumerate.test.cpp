#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include <bits/stdc++.h>

#include "library/sequence/RunEnumerate.cpp"

int main() {
    std::string s;
    std::cin >> s;
    RunEnumerate RE(s);
    std::cout << RE.ans.size() << "\n";
    for (const auto &[t, l, r] : RE.ans)
        std::cout << t << " " << l << " " << r << "\n";
}