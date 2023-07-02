#pragma once
#include "library/algebra/Reverse.cpp"
template<typename Lazy>
struct LazyReverse:Lazy{
  using MX=AlgebraReverse<typename Lazy::MX>;
};
