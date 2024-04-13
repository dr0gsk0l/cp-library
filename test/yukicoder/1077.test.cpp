#define PROBLEM "https://yukicoder.me/problems/no/1077"
#include <bits/stdc++.h>

#include "library/datastructure/SlopeTrick.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    SlopeTrick<int> ST;
    while (n--) {
        int v;
        std::cin >> v;
        ST.clear_inc();
        ST.add_abs(v);
    }
    std::cout << ST.min_f << std::endl;
}