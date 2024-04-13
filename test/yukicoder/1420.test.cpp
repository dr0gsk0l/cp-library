#define PROBLEM "https://yukicoder.me/problems/no/1420"
#define ERROR 1 // Check only whether the answer is -1 or not (by hitonanode)
#include <bits/stdc++.h>

#include "library/algebra/group/Xor.cpp"
#include "library/datastructure/unionfind/PotentialUnionFind.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    PotentialUnionFind<GroupXor<int>> UF(n);
    while (m--) {
        int a, b, y;
        cin >> a >> b >> y;
        a--;
        b--;
        if (!UF.merge(a, b, y)) {
            std::cout << -1 << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << UF.from_root(i).second << "\n";
}