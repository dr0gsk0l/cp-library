#define PROBLEM "https://yukicoder.me/problems/no/2109"
#include <bits/stdc++.h>

#include "library/datetime/DateTime.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, d, k;
    cin >> m >> d >> k;

    DateTime now(1, m, d);
    set<char> se;
    for (int i = 0; i < 7; i++, now++) {
        string s = now.to_string();
        for (int i = 5; i < s.size(); i++)
            se.insert(s[i]);
    }
    std::cout << (se.size() <= k ? "No\n" : "Yes\n");
}