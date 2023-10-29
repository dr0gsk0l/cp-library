#include "library/template/output.hpp"

void outputs() {}

TYPES(T, Ts)
void outputs(const std::ostream &os, const T &a, const Ts &...b) {
  os << a;
  (os << ...(os << ' ', b));
}

void print() { std::cout << '\n'; }

TYPES(T, Ts)
void print(const T &a, const Ts &...b) {
  outputs(std::cout, a, b);
  std::cout << "\n";
}

TYPES(T, Ts)
void fin(const T &a, const Ts &...b) {
  print(a, b);
  exit(0);
}