#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2207"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.cpp"
#include "library/datastructure/unionfind/PotentialUnionFind.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n) {
        PotentialUnionFind<GroupAdd<int>> uf(2 * n);
        std::map<std::string, int> id;
        std::string ans = "Yes\n";
        while (n--) {
            int x;
            std::string a, b;
            char c;
            std::cin >> x >> a >> c >> x >> c >> x >> b;
            if (!id.count(a))
                id[a] = id.size();
            if (!id.count(b))
                id[b] = id.size();
            if (!uf.merge(id[a], id[b], x))
                ans = "No\n";
        }
        std::cout << ans;
    }
}
