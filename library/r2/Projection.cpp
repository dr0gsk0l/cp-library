#pragma once
#include "library/r2/XY.cpp"
#include "library/util/Compress.cpp"
template <typename T> class Projection {
    using r2 = XY<T>;
    Compress<r2> C;

  public:
    Projection(const std::vector<r2> &v) : C(v) {}
    int size() { return C.size(); }
    int id(r2 xy) { return C[xy]; }
    int id(int x, int y) { return C[r2(x, y)]; }
    r2 r(int id) { return C.r(id); }
    //[l,r) を返す
    std::pair<int, int> interval(const T &l, const T &r) {
        if (C.max().x < l or r <= C.min().x)
            return std::make_pair(0, 0);
        T mn = std::numeric_limits<T>::min();
        int L = C.geq(r2(l, mn));
        int R = C.geq(r2(r, mn));
        return std::make_pair(L, R);
    }
};
