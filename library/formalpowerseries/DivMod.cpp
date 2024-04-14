#pragma once
#include "library/formalpowerseries/Base.cpp"
template <typename FPS> std::pair<FPS, FPS> div_mod(FPS f, FPS g) {
    f.shrink();
    g.shrink();
    assert(g.size());
    if (f.size() < g.size())
        return {FPS(0), f};
    std::ranges::reverse(f);
    std::ranges::reverse(g);
    int d = f.size() - g.size() + 1;
    FPS q = (f.pre(d) * g.inv(d)).pre(d);
    if (q.size() < d)
        q.resize(d, 0);
    std::ranges::reverse(q);
    std::ranges::reverse(f);
    std::ranges::reverse(g);
    return {q, f - q * g};
}
#undef REVERSE_