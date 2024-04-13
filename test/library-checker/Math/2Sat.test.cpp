#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <bits/stdc++.h>

#include <atcoder/twosat>
using namespace atcoder;

int main() {
    std::string hoge;
    std::cin >> hoge >> hoge;
    int n, m;
    std::cin >> n >> m;
    two_sat ts(n);
    while (m--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        bool f_a = a > 0, f_b = b > 0;
        ts.add_clause(abs(a) - 1, f_a, abs(b) - 1, f_b);
    }
    if (ts.satisfiable()) {
        std::cout << "s SATISFIABLE\n";
        std::cout << "v ";
        auto A = ts.answer();
        for (int i = 0; i < n; i++)
            std::cout << (A[i] ? i + 1 : -(i + 1)) << " ";
        std::cout << "0\n";
    } else
        std::cout << "s UNSATISFIABLE\n";
}