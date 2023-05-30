---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/util/compressor.hpp
    title: library/util/compressor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/solver/inversion_number.hpp\"\n\n\n\n#include<atcoder/fenwicktree>\n\
    #include<library/util/compressor.hpp>\n\nnamespace otera {\n    template<typename\
    \ T>\n    long long inversion_number(std::vector<T> a) {\n        int _n = (int)a.size();\n\
    \        compressor<T> ca(a);\n        int _sz = (int)ca.size();\n        atcoder::fenwick_tree<T>\
    \ bit(sz);\n        long long res = 0;\n        for(int i = 0; i < _n; ++ i) {\n\
    \            int _pos = ca.get(a[i]);\n            res += (long long)bit.sum(_pos\
    \ + 1, _sz);\n            bit.add(_pos, 1);\n        }\n        return res;\n\
    \    }\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_INVERSION_NUMBER_HPP\n#define OTERA_INVERSION_NUMBER_HPP 1\n\
    \n#include<atcoder/fenwicktree>\n#include<library/util/compressor.hpp>\n\nnamespace\
    \ otera {\n    template<typename T>\n    long long inversion_number(std::vector<T>\
    \ a) {\n        int _n = (int)a.size();\n        compressor<T> ca(a);\n      \
    \  int _sz = (int)ca.size();\n        atcoder::fenwick_tree<T> bit(sz);\n    \
    \    long long res = 0;\n        for(int i = 0; i < _n; ++ i) {\n            int\
    \ _pos = ca.get(a[i]);\n            res += (long long)bit.sum(_pos + 1, _sz);\n\
    \            bit.add(_pos, 1);\n        }\n        return res;\n    }\n} // namespace\
    \ otera\n\n#endif // OTERA_INVERSION_NUMBER_HPP"
  dependsOn:
  - library/util/compressor.hpp
  isVerificationFile: false
  path: library/solver/inversion_number.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:48:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/solver/inversion_number.hpp
layout: document
redirect_from:
- /library/library/solver/inversion_number.hpp
- /library/library/solver/inversion_number.hpp.html
title: library/solver/inversion_number.hpp
---
