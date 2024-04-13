#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>

#include "library/datastructure/unionfind/UnionFind.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t)
            std::cout << uf.same(u, v) << "\n";
        else
            uf.merge(u, v);
    }
}