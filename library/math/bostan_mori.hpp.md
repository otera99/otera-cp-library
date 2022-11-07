---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/math/FPS.hpp
    title: library/math/FPS.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/bostan_mori.hpp\"\n// UNFINISHED\n#ifndef OTERA_BOSTAN_MORI_HPP\n\
    #define OTERA_BOSTAN_MORI_HPP 1\n\n#include<library/math/FPS.hpp>\n\nnamespace\
    \ otera {\n    template<typename mint>\n    // `[x^n]\\frac{P(x)}{Q(x)}`\n   \
    \ mint bostan_mori(FPS<mint> P, FPS<mint> Q, ll n) {\n        auto even = [&](FPS<mint>\
    \ x) -> FPS<mint> {\n            FPS<mint> ret;\n            for(int i = 0; i\
    \ < (int)x.size(); i += 2) {\n                ret.emplace_back(x[i]);\n      \
    \      }\n            return ret;\n        };\n        auto odd = [&](FPS<mint>\
    \ x) -> FPS<mint> {\n            FPS<mint> ret;\n            for(int i = 1; i\
    \ < (int)x.size(); i += 2) {\n                ret.emplace_back(x[i]);\n      \
    \      }\n            return ret;\n        };\n        while(n > 0) {\n      \
    \      FPS<mint> mQ = Q;\n            for(int i = 1; i < (int)Q.size(); i += 2)\
    \ {\n                mQ[i] = -mQ[i];\n            }\n            if(n % 2 == 0)\
    \ P = even(P * mQ);\n            else P = odd(P * mQ);\n            Q = even(Q\
    \ * mQ);\n            n >>= 1;\n        }\n        return P[0];\n    }\n} // namesapce\
    \ otera\n\n#endif // OTERA_BOSTAN_MORI_HPP\n"
  code: "// UNFINISHED\n#ifndef OTERA_BOSTAN_MORI_HPP\n#define OTERA_BOSTAN_MORI_HPP\
    \ 1\n\n#include<library/math/FPS.hpp>\n\nnamespace otera {\n    template<typename\
    \ mint>\n    // `[x^n]\\frac{P(x)}{Q(x)}`\n    mint bostan_mori(FPS<mint> P, FPS<mint>\
    \ Q, ll n) {\n        auto even = [&](FPS<mint> x) -> FPS<mint> {\n          \
    \  FPS<mint> ret;\n            for(int i = 0; i < (int)x.size(); i += 2) {\n \
    \               ret.emplace_back(x[i]);\n            }\n            return ret;\n\
    \        };\n        auto odd = [&](FPS<mint> x) -> FPS<mint> {\n            FPS<mint>\
    \ ret;\n            for(int i = 1; i < (int)x.size(); i += 2) {\n            \
    \    ret.emplace_back(x[i]);\n            }\n            return ret;\n       \
    \ };\n        while(n > 0) {\n            FPS<mint> mQ = Q;\n            for(int\
    \ i = 1; i < (int)Q.size(); i += 2) {\n                mQ[i] = -mQ[i];\n     \
    \       }\n            if(n % 2 == 0) P = even(P * mQ);\n            else P =\
    \ odd(P * mQ);\n            Q = even(Q * mQ);\n            n >>= 1;\n        }\n\
    \        return P[0];\n    }\n} // namesapce otera\n\n#endif // OTERA_BOSTAN_MORI_HPP\n"
  dependsOn:
  - library/math/FPS.hpp
  isVerificationFile: false
  path: library/math/bostan_mori.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/bostan_mori.hpp
layout: document
redirect_from:
- /library/library/math/bostan_mori.hpp
- /library/library/math/bostan_mori.hpp.html
title: library/math/bostan_mori.hpp
---
