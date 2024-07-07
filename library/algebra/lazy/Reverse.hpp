#pragma once
#include "library/algebra/Reverse.hpp"
template <typename Lazy> struct LazyReverse : Lazy {
    using MX = AlgebraReverse<typename Lazy::MX>;
};
