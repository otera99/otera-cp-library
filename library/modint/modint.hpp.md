---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/math/factorial.hpp
    title: library/math/factorial.hpp
  - icon: ':warning:'
    path: library/math/pow_table.hpp
    title: library/math/pow_table.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc277_g.test.cpp
    title: test/atcoder/abc277_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_subsequences.test.cpp
    title: test/library_checker/string/number_of_subsequences.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/modint/modint.hpp\"\n\n\n\n#include<atcoder/modint>\n\
    \nnamespace otera {\n    using modint107 = atcoder::modint1000000007;\n    using\
    \ modint998 = atcoder::modint998244353;\n    using modint = atcoder::modint;\n\
    }; //namespace otera\n\nstd::ostream& operator<<(std::ostream& out, const atcoder::modint1000000007\
    \ &e) {\n    out << e.val();\n    return out;\n}\n\nstd::ostream& operator<<(std::ostream&\
    \ out, const atcoder::modint998244353 &e) {\n    out << e.val();\n    return out;\n\
    }\n\nstd::ostream& operator<<(std::ostream& out, const atcoder::modint &e) {\n\
    \    out << e.val();\n    return out;\n}\n\n\n"
  code: "#ifndef OTERA_MODINT\n#define OTERA_MODINT 1\n\n#include<atcoder/modint>\n\
    \nnamespace otera {\n    using modint107 = atcoder::modint1000000007;\n    using\
    \ modint998 = atcoder::modint998244353;\n    using modint = atcoder::modint;\n\
    }; //namespace otera\n\nstd::ostream& operator<<(std::ostream& out, const atcoder::modint1000000007\
    \ &e) {\n    out << e.val();\n    return out;\n}\n\nstd::ostream& operator<<(std::ostream&\
    \ out, const atcoder::modint998244353 &e) {\n    out << e.val();\n    return out;\n\
    }\n\nstd::ostream& operator<<(std::ostream& out, const atcoder::modint &e) {\n\
    \    out << e.val();\n    return out;\n}\n\n#endif // OTERA_MODINT"
  dependsOn: []
  isVerificationFile: false
  path: library/modint/modint.hpp
  requiredBy:
  - library/math/pow_table.hpp
  - library/math/factorial.hpp
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc212_h.test.cpp
  - test/atcoder/abc277_g.test.cpp
  - test/library_checker/string/number_of_subsequences.test.cpp
documentation_of: library/modint/modint.hpp
layout: document
redirect_from:
- /library/library/modint/modint.hpp
- /library/library/modint/modint.hpp.html
title: library/modint/modint.hpp
---
