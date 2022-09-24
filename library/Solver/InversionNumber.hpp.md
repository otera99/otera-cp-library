---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/Util/Compressor.hpp
    title: library/Util/Compressor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/Solver/InversionNumber.hpp\"\n\n\n\n#include<atcoder/fenwicktree>\n\
    #include<library/Util/Compressor.hpp>\n\nnamespace otera {\n    long long InversionNumber(std::vector<long\
    \ long> a) {\n        int _n = (int)a.size();\n        Compressor<long long> ca(a);\n\
    \        int sz = (int)ca.size();\n        atcoder::fenwick_tree<long long> bit(sz);\n\
    \        long long res = 0;\n        for(int i = 0; i < _n; ++ i) {\n        \
    \    res += bit.sum(ca.get(a[i]) + 1, sz);\n            bit.add(ca.get(a[i]),\
    \ 1);\n        }\n        return res;\n    }\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_INVERSION_NUMBER_HPP\n#define OTERA_INVERSION_NUMBER_HPP 1\n\
    \n#include<atcoder/fenwicktree>\n#include<library/Util/Compressor.hpp>\n\nnamespace\
    \ otera {\n    long long InversionNumber(std::vector<long long> a) {\n       \
    \ int _n = (int)a.size();\n        Compressor<long long> ca(a);\n        int sz\
    \ = (int)ca.size();\n        atcoder::fenwick_tree<long long> bit(sz);\n     \
    \   long long res = 0;\n        for(int i = 0; i < _n; ++ i) {\n            res\
    \ += bit.sum(ca.get(a[i]) + 1, sz);\n            bit.add(ca.get(a[i]), 1);\n \
    \       }\n        return res;\n    }\n} // namespace otera\n\n#endif // OTERA_INVERSION_NUMBER_HPP"
  dependsOn:
  - library/Util/Compressor.hpp
  isVerificationFile: false
  path: library/Solver/InversionNumber.hpp
  requiredBy: []
  timestamp: '2022-09-25 01:06:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Solver/InversionNumber.hpp
layout: document
redirect_from:
- /library/library/Solver/InversionNumber.hpp
- /library/library/Solver/InversionNumber.hpp.html
title: library/Solver/InversionNumber.hpp
---
