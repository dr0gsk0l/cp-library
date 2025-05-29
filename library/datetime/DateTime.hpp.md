---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2109.test.cpp
    title: test/yukicoder/2109.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datetime/DateTime.hpp\"\nclass DateTime {\n    static\
    \ int day_of_week; // 1\u5E741\u67081\u65E5\u306E\u66DC\u65E5\n  public:\n   \
    \ int year, month, day;\n    DateTime(int y, int m, int d) : year(y), month(m),\
    \ day(d) {}\n\n    static bool is_leap_year(int y) {\n        return !(y % 400)\
    \ or (!(y % 4) and y % 100);\n    }\n    static int month_days(int y, int m) {\n\
    \        if (m == 2)\n            return 28 + is_leap_year(y);\n        return\
    \ 31 - (m == 4 || m == 6 || m == 9 || m == 11);\n    }\n\n    // 1\u5E741\u6708\
    1\u65E5\u304C 0 \u3068\u306A\u308B\u3088\u3046\u306B\u5909\u63DB\n    int to_int()\
    \ const {\n        int y = (month <= 2 ? year - 1 : year);\n        int m = (month\
    \ <= 2 ? month + 12 : month);\n        int d = day;\n        return 365 * y +\
    \ y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d -\n               429;\n\
    \    }\n\n    // to_int() \u306E\u9006\u95A2\u6570\n    static DateTime from_int(int\
    \ x) {\n        int y = x * 400 / 146097 + 1;\n        int d = x - DateTime(y,\
    \ 1, 1).to_int();\n        int m = 1;\n        while (d >= 28) {\n           \
    \ int k = month_days(y, m);\n            if (d < k)\n                break;\n\
    \            ++m;\n            d -= k;\n        }\n        if (m == 13) {\n  \
    \          ++y;\n            m = 1;\n        }\n        ++d;\n        return DateTime(y,\
    \ m, d);\n    }\n\n    void set_day_of_week(int day_of_week_) {\n        int now\
    \ = to_int() % 7;\n        day_of_week = day_of_week_ - now;\n        if (day_of_week\
    \ < 0)\n            day_of_week += 7;\n    }\n\n    int weekday() const { return\
    \ (day_of_week + to_int()) % 7; }\n\n    DateTime &operator++() {\n        if\
    \ (++day > month_days(year, month)) {\n            day = 1;\n            if (++month\
    \ > 12) {\n                ++year;\n                month = 1;\n            }\n\
    \        }\n        return *this;\n    }\n    DateTime &operator++(int) { return\
    \ ++(*this); }\n    DateTime &operator--() {\n        if (--day < 0) {\n     \
    \       if (--month < 0) {\n                assert(--year >= 1);\n           \
    \     month = 12;\n            }\n            day = month_days(year, month);\n\
    \        }\n        return *this;\n    }\n    DateTime &operator--(int) { return\
    \ --(*this); }\n    DateTime &operator+=(int d) {\n        year += (d / 400) *\
    \ 146097;\n        d %= 400;\n        while (d--)\n            (*this)++;\n  \
    \      return *this;\n    }\n    DateTime &operator-=(int d) {\n        year -=\
    \ (d / 400) * 146097;\n        d %= 400;\n        while (d--)\n            (*this)--;\n\
    \        return *this;\n    }\n    DateTime operator+(int d) { return DateTime(year,\
    \ month, day) += d; }\n    DateTime operator-(int d) { return DateTime(year, month,\
    \ day) -= d; }\n\n    // yyyy[sep]mm[sep]dd\n    std::string to_string(std::string\
    \ sep = \"-\") {\n        std::string y = std::to_string(year);\n        std::string\
    \ m = std::to_string(month);\n        std::string d = std::to_string(day);\n \
    \       while (y.size() < 4)\n            y = \"0\" + y;\n        while (m.size()\
    \ < 2)\n            m = \"0\" + m;\n        while (d.size() < 2)\n           \
    \ d = \"0\" + d;\n        return y + sep + m + sep + d;\n    }\n\n    std::tuple<int,\
    \ int, int> to_tuple() const { return {year, month, day}; }\n\n#define define_cmp(op)\
    \                                                         \\\n    bool operator\
    \ op(const DateTime &a) const {                                \\\n        return\
    \ to_tuple() op a.to_tuple();                                     \\\n    }\n\
    \    define_cmp(==) define_cmp(!=) define_cmp(<) define_cmp(>) define_cmp(<=)\n\
    \        define_cmp(>=)\n#undef define_cmp\n};\n"
  code: "class DateTime {\n    static int day_of_week; // 1\u5E741\u67081\u65E5\u306E\
    \u66DC\u65E5\n  public:\n    int year, month, day;\n    DateTime(int y, int m,\
    \ int d) : year(y), month(m), day(d) {}\n\n    static bool is_leap_year(int y)\
    \ {\n        return !(y % 400) or (!(y % 4) and y % 100);\n    }\n    static int\
    \ month_days(int y, int m) {\n        if (m == 2)\n            return 28 + is_leap_year(y);\n\
    \        return 31 - (m == 4 || m == 6 || m == 9 || m == 11);\n    }\n\n    //\
    \ 1\u5E741\u67081\u65E5\u304C 0 \u3068\u306A\u308B\u3088\u3046\u306B\u5909\u63DB\
    \n    int to_int() const {\n        int y = (month <= 2 ? year - 1 : year);\n\
    \        int m = (month <= 2 ? month + 12 : month);\n        int d = day;\n  \
    \      return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d -\n\
    \               429;\n    }\n\n    // to_int() \u306E\u9006\u95A2\u6570\n    static\
    \ DateTime from_int(int x) {\n        int y = x * 400 / 146097 + 1;\n        int\
    \ d = x - DateTime(y, 1, 1).to_int();\n        int m = 1;\n        while (d >=\
    \ 28) {\n            int k = month_days(y, m);\n            if (d < k)\n     \
    \           break;\n            ++m;\n            d -= k;\n        }\n       \
    \ if (m == 13) {\n            ++y;\n            m = 1;\n        }\n        ++d;\n\
    \        return DateTime(y, m, d);\n    }\n\n    void set_day_of_week(int day_of_week_)\
    \ {\n        int now = to_int() % 7;\n        day_of_week = day_of_week_ - now;\n\
    \        if (day_of_week < 0)\n            day_of_week += 7;\n    }\n\n    int\
    \ weekday() const { return (day_of_week + to_int()) % 7; }\n\n    DateTime &operator++()\
    \ {\n        if (++day > month_days(year, month)) {\n            day = 1;\n  \
    \          if (++month > 12) {\n                ++year;\n                month\
    \ = 1;\n            }\n        }\n        return *this;\n    }\n    DateTime &operator++(int)\
    \ { return ++(*this); }\n    DateTime &operator--() {\n        if (--day < 0)\
    \ {\n            if (--month < 0) {\n                assert(--year >= 1);\n  \
    \              month = 12;\n            }\n            day = month_days(year,\
    \ month);\n        }\n        return *this;\n    }\n    DateTime &operator--(int)\
    \ { return --(*this); }\n    DateTime &operator+=(int d) {\n        year += (d\
    \ / 400) * 146097;\n        d %= 400;\n        while (d--)\n            (*this)++;\n\
    \        return *this;\n    }\n    DateTime &operator-=(int d) {\n        year\
    \ -= (d / 400) * 146097;\n        d %= 400;\n        while (d--)\n           \
    \ (*this)--;\n        return *this;\n    }\n    DateTime operator+(int d) { return\
    \ DateTime(year, month, day) += d; }\n    DateTime operator-(int d) { return DateTime(year,\
    \ month, day) -= d; }\n\n    // yyyy[sep]mm[sep]dd\n    std::string to_string(std::string\
    \ sep = \"-\") {\n        std::string y = std::to_string(year);\n        std::string\
    \ m = std::to_string(month);\n        std::string d = std::to_string(day);\n \
    \       while (y.size() < 4)\n            y = \"0\" + y;\n        while (m.size()\
    \ < 2)\n            m = \"0\" + m;\n        while (d.size() < 2)\n           \
    \ d = \"0\" + d;\n        return y + sep + m + sep + d;\n    }\n\n    std::tuple<int,\
    \ int, int> to_tuple() const { return {year, month, day}; }\n\n#define define_cmp(op)\
    \                                                         \\\n    bool operator\
    \ op(const DateTime &a) const {                                \\\n        return\
    \ to_tuple() op a.to_tuple();                                     \\\n    }\n\
    \    define_cmp(==) define_cmp(!=) define_cmp(<) define_cmp(>) define_cmp(<=)\n\
    \        define_cmp(>=)\n#undef define_cmp\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datetime/DateTime.hpp
  requiredBy: []
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2109.test.cpp
documentation_of: library/datetime/DateTime.hpp
layout: document
redirect_from:
- /library/library/datetime/DateTime.hpp
- /library/library/datetime/DateTime.hpp.html
title: library/datetime/DateTime.hpp
---
