#define PROBLEM "https://yukicoder.me/problems/no/117"
#include <bits/stdc++.h>

#include "library/mod/MintUtility.cpp"
#include "library/mod/Modint.cpp"

using mint = Mint<long long, 1000'000'007>;
MintUtility<mint> M;

mint solve() {
    std::string s;
    std::cin >> s;
    int comma = 0;
    while (s[comma] != ',')
        comma++;
    int n = stoi(s.substr(2, comma - 1));
    int k = stoi(s.substr(comma + 1, s.size() - comma - 1));
    if (s[0] == 'C')
        return M.nCk(n, k);
    if (s[0] == 'P')
        return M.nPk(n, k);
    return M.nHk(n, k);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testsize;
    std::cin >> testsize;
    while (testsize--)
        std::cout << solve() << '\n';
}