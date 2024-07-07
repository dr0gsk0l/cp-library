#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include <bits/stdc++.h>

#include "library/util/InversionNumber.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    std::cout << inversion_number(v) << std::endl;
}