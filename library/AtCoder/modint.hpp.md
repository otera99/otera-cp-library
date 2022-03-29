---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/Math/Factorial.hpp
    title: library/Math/Factorial.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/AtCoder/modint.hpp\"\n\n\n\n#include<atcoder/modint>\n\
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
  path: library/AtCoder/modint.hpp
  requiredBy:
  - library/Math/Factorial.hpp
  timestamp: '2022-03-29 09:25:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/AtCoder/modint.hpp
layout: document
redirect_from:
- /library/library/AtCoder/modint.hpp
- /library/library/AtCoder/modint.hpp.html
title: library/AtCoder/modint.hpp
---
