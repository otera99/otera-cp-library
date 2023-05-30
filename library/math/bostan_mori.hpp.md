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
  bundledCode: "#line 1 \"library/math/bostan_mori.hpp\"\n// UNFINISHED\n#ifndef OTERA_BOSTAN_MORI_HPP\n\
    #define OTERA_BOSTAN_MORI_HPP 1\n\n#include<library/math/fps.hpp>\n\nnamespace\
    \ otera {\n    template<typename mint>\n    // `[x^n]\\frac{P(x)}{Q(x)}`\n   \
    \ mint bostan_mori(fps<mint> P, fps<mint> Q, long long n) {\n        auto even\
    \ = [&](fps<mint> x) -> fps<mint> {\n            fps<mint> ret;\n            for(int\
    \ i = 0; i < (int)x.size(); i += 2) {\n                ret.emplace_back(x[i]);\n\
    \            }\n            return ret;\n        };\n        auto odd = [&](fps<mint>\
    \ x) -> fps<mint> {\n            fps<mint> ret;\n            for(int i = 1; i\
    \ < (int)x.size(); i += 2) {\n                ret.emplace_back(x[i]);\n      \
    \      }\n            return ret;\n        };\n        while(n > 0) {\n      \
    \      fps<mint> mQ = Q;\n            for(int i = 1; i < (int)Q.size(); i += 2)\
    \ {\n                mQ[i] = -mQ[i];\n            }\n            if(n % 2 == 0)\
    \ P = even(P * mQ);\n            else P = odd(P * mQ);\n            Q = even(Q\
    \ * mQ);\n            n >>= 1;\n        }\n        return P[0];\n    }\n} // namesapce\
    \ otera\n\n#endif // OTERA_BOSTAN_MORI_HPP\n"
  code: "// UNFINISHED\n#ifndef OTERA_BOSTAN_MORI_HPP\n#define OTERA_BOSTAN_MORI_HPP\
    \ 1\n\n#include<library/math/fps.hpp>\n\nnamespace otera {\n    template<typename\
    \ mint>\n    // `[x^n]\\frac{P(x)}{Q(x)}`\n    mint bostan_mori(fps<mint> P, fps<mint>\
    \ Q, long long n) {\n        auto even = [&](fps<mint> x) -> fps<mint> {\n   \
    \         fps<mint> ret;\n            for(int i = 0; i < (int)x.size(); i += 2)\
    \ {\n                ret.emplace_back(x[i]);\n            }\n            return\
    \ ret;\n        };\n        auto odd = [&](fps<mint> x) -> fps<mint> {\n     \
    \       fps<mint> ret;\n            for(int i = 1; i < (int)x.size(); i += 2)\
    \ {\n                ret.emplace_back(x[i]);\n            }\n            return\
    \ ret;\n        };\n        while(n > 0) {\n            fps<mint> mQ = Q;\n  \
    \          for(int i = 1; i < (int)Q.size(); i += 2) {\n                mQ[i]\
    \ = -mQ[i];\n            }\n            if(n % 2 == 0) P = even(P * mQ);\n   \
    \         else P = odd(P * mQ);\n            Q = even(Q * mQ);\n            n\
    \ >>= 1;\n        }\n        return P[0];\n    }\n} // namesapce otera\n\n#endif\
    \ // OTERA_BOSTAN_MORI_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/bostan_mori.hpp
  requiredBy: []
  timestamp: '2023-05-31 05:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/bostan_mori.hpp
layout: document
redirect_from:
- /library/library/math/bostan_mori.hpp
- /library/library/math/bostan_mori.hpp.html
title: library/math/bostan_mori.hpp
---
