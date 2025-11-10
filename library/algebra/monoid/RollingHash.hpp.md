---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/RollingHash.hpp\"\ntemplate <typename\
    \ CHAR = char> struct MonoidRollingHash {\n    using u64 = std::uint64_t;\n  \
    \  using u128 = unsigned __int128;\n    using value_type = std::pair<u64, u64>;\n\
    \    using X = value_type;\n    static constexpr u64 mod = (1ULL << 61) - 1, base\
    \ = 20120620;\n    static constexpr u64 mul(u64 a, u64 b) {\n        u128 u =\
    \ static_cast<u128>(a) * b;\n        a = (u >> 61) + u & mod;\n        return\
    \ a >= mod ? a - mod : a;\n    }\n\n    static constexpr X op(const X &x, const\
    \ X &y) {\n        const auto &[vx, px] = x;\n        const auto &[vy, py] = y;\n\
    \        return X((mul(vx, py) + vy) & mod, mul(px, py));\n    }\n    static constexpr\
    \ void Rchop(X &x, const X &y) { x = op(x, y); }\n    static constexpr void Lchop(const\
    \ X &x, X &y) { y = op(x, y); }\n    static constexpr X unit() { return X(0, 1);\
    \ }\n    static constexpr bool commute = false;\n\n    static constexpr X to_X(const\
    \ CHAR &c) { return X(c, base); }\n\n    template <typename STRING>\n    static\
    \ constexpr std::vector<X> to_vec(const STRING &s) {\n        std::vector<X> ret(s.size());\n\
    \        for (int i = 0; i < s.size(); i++)\n            ret[i] = to_X(s[i]);\n\
    \        return ret;\n    }\n};\n"
  code: "template <typename CHAR = char> struct MonoidRollingHash {\n    using u64\
    \ = std::uint64_t;\n    using u128 = unsigned __int128;\n    using value_type\
    \ = std::pair<u64, u64>;\n    using X = value_type;\n    static constexpr u64\
    \ mod = (1ULL << 61) - 1, base = 20120620;\n    static constexpr u64 mul(u64 a,\
    \ u64 b) {\n        u128 u = static_cast<u128>(a) * b;\n        a = (u >> 61)\
    \ + u & mod;\n        return a >= mod ? a - mod : a;\n    }\n\n    static constexpr\
    \ X op(const X &x, const X &y) {\n        const auto &[vx, px] = x;\n        const\
    \ auto &[vy, py] = y;\n        return X((mul(vx, py) + vy) & mod, mul(px, py));\n\
    \    }\n    static constexpr void Rchop(X &x, const X &y) { x = op(x, y); }\n\
    \    static constexpr void Lchop(const X &x, X &y) { y = op(x, y); }\n    static\
    \ constexpr X unit() { return X(0, 1); }\n    static constexpr bool commute =\
    \ false;\n\n    static constexpr X to_X(const CHAR &c) { return X(c, base); }\n\
    \n    template <typename STRING>\n    static constexpr std::vector<X> to_vec(const\
    \ STRING &s) {\n        std::vector<X> ret(s.size());\n        for (int i = 0;\
    \ i < s.size(); i++)\n            ret[i] = to_X(s[i]);\n        return ret;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/RollingHash.hpp
  requiredBy: []
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/RollingHash.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/RollingHash.hpp
- /library/library/algebra/monoid/RollingHash.hpp.html
title: library/algebra/monoid/RollingHash.hpp
---
