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
  bundledCode: "#line 1 \"library/util/enumerate_quotient.hpp\"\n\n\n\nnamespace otera\
    \ {\n    template <typename T>\n    std::vector<tuple<T, T, T>> enumerate_quotient(T\
    \ x) {\n        std::vector<tuple<T, T, T>> res;\n        for(T l = 1, r = 1;\
    \ l <= x; l = r + 1) {\n            T val = x / l;\n            res.emplace_back(l,\
    \ r = x / val, val);\n        }\n        return res;\n    }\n} // namespace otera\n\
    \n\n"
  code: "#ifndef OTERA_ENUMERATE_QUOTIENT_HPP\n#define OTERA_ENUMERATE_QUOTIENT_HPP\
    \ 1\n\nnamespace otera {\n    template <typename T>\n    std::vector<tuple<T,\
    \ T, T>> enumerate_quotient(T x) {\n        std::vector<tuple<T, T, T>> res;\n\
    \        for(T l = 1, r = 1; l <= x; l = r + 1) {\n            T val = x / l;\n\
    \            res.emplace_back(l, r = x / val, val);\n        }\n        return\
    \ res;\n    }\n} // namespace otera\n\n#endif // OTERA_ENUMERATE_QUOTIENT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/util/enumerate_quotient.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/enumerate_quotient.hpp
layout: document
redirect_from:
- /library/library/util/enumerate_quotient.hpp
- /library/library/util/enumerate_quotient.hpp.html
title: library/util/enumerate_quotient.hpp
---
