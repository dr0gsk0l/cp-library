#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include <bits/stdc++.h>

#include "library/geometry/UtilFunction.hpp"
using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Polygon P(n);
    std::cin >> P;

    Polygon Q = convex_hull(P);
    std::cout << Q.size() << "\n";
    for (const Point &p : Q)
        std::cout << p << "\n";
}