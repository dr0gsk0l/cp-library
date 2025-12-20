#pragma once
#include <cassert>
#include <deque>
#include <numeric>
#include <ostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include "library/linearalgebra/Linear.hpp"
namespace convex_hull_trick {
enum Objective {
    MINIMIZE = +1,
    MAXIMIZE = -1,
};

// 最大化の場合は反転して、内部では最小化問題のみを扱う
// 傾きが狭義単調減少になるように保存

template <typename T, Objective OBJ>
class ConvexHullTrick : std::deque<Line<T>> {
    using L = Line<T>;
    using std::deque<L>::push_back;
    using std::deque<L>::push_front;
    using std::deque<L>::pop_back;
    using std::deque<L>::pop_front;

    const L& at(int i) const { 
        return i >= 0 ? std::deque<L>::at(i) : std::deque<L>::at(size() + i);
    }

    static bool check(const L &l1, const L &l2, const L &l3) {
        // l2 が要らないなら true を返す
        // 傾きが狭義単調減少は保証されてる
        // 交点の x 座標は (l2.b-l1.b)/(l1.a-l2.a) と (l3.b-l2.b)/(l2.a-l3.a)
        // これが >= だと要らない
        return (l2.b - l1.b) * (l2.a - l3.a) >= (l3.b - l2.b) * (l1.a - l2.a);
    }

    static T apply_objective(const T &value) {
        if constexpr (OBJ == Objective::MINIMIZE)
            return value;
        else
            return -value;
    }

    void internal_push_back(const L &l) {
        assert(!size() or at(-1).a >= l.a);

        if(size() and at(-1).a == l.a) 
            if(at(-1).b <= l.b)
                return;
            else
                pop_back();
        
        while (size() >= 2 and check(at(-2), at(-1), l)) 
            pop_back();
        
        push_back(l);
    }

    void internal_push_front(const L &l) {
        assert(!size() or l.a >= at(0).a);

        if(size() and at(0).a == l.a)
            if(at(0).b <= l.b)
                return;
            else
                pop_front();

        while (size() >= 2 and check(l, at(0), at(1)))
            pop_front();
        
        push_front(l);
    }
  public:
    using value_type = L;
    using std::deque<L>::size;

    ConvexHullTrick() = default;
    ConvexHullTrick(std::vector<L> lines) {
        if (OBJ == -1)
            for (auto &l : lines)
                l = -l;
        std::ranges::sort(lines);
        for (const auto &l : lines)
            internal_push_back(l);
    }

    void add(L l) {
        if (OBJ == -1)
            l = -l;
        if (!size() or at(-1).a >= l.a)
            internal_push_back(l);
        else if (l.a >= at(0).a)
            internal_push_front(l);
        else
            assert(false);
    }

    void add(T a, T b) { add(L(a, b)); }

    // return min_f{f(x)}
    T query(T x) const {
        assert(size());
        int l = -1, r = size() - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            (at(m)(x) >= at(m + 1)(x) ? l : r) = m;
        }
        return apply_objective(at(r)(x));
    }

    // return min_f{f(x)}
    // 任意の X<x に対して f = argmin_f{f(X)} とならない f を全て削除する
    T query_monotone_inc(T x) {
        assert(size());
        while (size() >= 2 and at(0)(x) >= at(1)(x))
            pop_front();
        return apply_objective(at(0)(x));
    }

    // return min_f{f(x)}
    // 任意の X>x に対して f = argmin_f{f(X)} とならない f を全て削除する
    T query_monotone_dec(T x) {
        assert(size());
        while (size() >= 2 and at(-2)(x) <= at(-1)(x))
            pop_back();
        return apply_objective(at(-1)(x));
    }

    std::vector<T> query(const std::vector<T> &xs) {
        int n = xs.size();
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::ranges::sort(idx, std::ranges::less{}, [&](int i) { return xs[i]; });
        std::vector<T> ans(n);
        for (int id : idx)
            ans[id] = query_monotone_inc(xs[id]); 
        return ans;
    }

    friend std::ostream &operator<<(std::ostream &os,
                                    const ConvexHullTrick &cht) {
        os << "[";
        for (int i = 0; i < cht.size(); i++)
            os << (OBJ == -1 ? -cht.at(i) : cht.at(i))
               << "],"[i + 1 < cht.size()];
        if (!cht.size())
            os << "]";
        return os;
    }
};
} // namespace convex_hull_trick
template <typename T>
using MinConvexHullTrick =
    convex_hull_trick::ConvexHullTrick<T,
                                       convex_hull_trick::Objective::MINIMIZE>;
template <typename T>
using MaxConvexHullTrick =
    convex_hull_trick::ConvexHullTrick<T,
                                       convex_hull_trick::Objective::MAXIMIZE>;
