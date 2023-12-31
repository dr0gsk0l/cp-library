template<typename X,bool COMMUTE=true>
struct GroupMultiply{
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x * y; }
  static constexpr void Rchop(X&x, const X&y){ x*=y; }
  static constexpr void Lchop(const X&x, X&y){ 
    if constexpr(COMMUTE){ y*=x; }
    else{ y=x*y;} 
  }
  static constexpr X inverse(const X &x) noexcept { return X(1)/x; }
  static constexpr X power(const X &x, long long n) noexcept { return x.pow(n); }
  static constexpr X unit() { return X(1); }
  static constexpr bool commute = COMMUTE;
};