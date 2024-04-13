#define PROBLEM "https://yukicoder.me/problems/no/650"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/algebra/group/Multiply.cpp"
#include "library/linearalgebra/SquareMatrix.cpp"
#include "library/mod/Modint.cpp"
#include "library/tree/EdgeVertex.cpp"
#include "library/tree/Tree.cpp"
#include "library/tree/TreeMonoid.cpp"

using mint = Mint<long long, 1000'000'007>;
using MAT = SquareMatrix<mint, 2>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    EdgeVertex EV(n);
    REP (_, n - 1) {
        int u, v;
        cin >> u >> v;
        EV.add_edge(u, v);
    }
    Tree T = EV.build();

    TreeMonoid<Tree, GroupMultiply<MAT, false>> TM(T);

    int q;
    cin >> q;
    REP (_, q) {
        char c;
        cin >> c;
        if (c == 'x') {
            int idx;
            cin >> idx;
            MAT M;
            REP (i, 2)
                REP (j, 2)
                    cin >> M[i][j];
            TM.set(n + idx, M);
        } else {
            int l, r;
            cin >> l >> r;
            MAT M = TM.path_prod(l, r);
            REP (i, 2)
                REP (j, 2)
                    std::cout << M[i][j] << "\n "[i + j < 2];
        }
    }
}
