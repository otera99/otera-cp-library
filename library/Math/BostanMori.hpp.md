---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/Math/FPS.hpp
    title: library/Math/FPS.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/Math/BostanMori.hpp\"\n\n\n\n#include<library/Math/FPS.hpp>\n\
    \nnamespace otera {\n    template<typename mint>\n    // `[x^n]\\frac{P(x)}{Q(x)}`\n\
    \    mint bostan_mori(FPS<mint> P, FPS<mint> Q, ll n) {\n        auto even = [&](FPS<mint>\
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
    \ otera\n\n\n"
  code: "#ifndef OTERA_BOSTAN_MORI\n#define OTERA_BOSTAN_MORI 1\n\n#include<library/Math/FPS.hpp>\n\
    \nnamespace otera {\n    template<typename mint>\n    // `[x^n]\\frac{P(x)}{Q(x)}`\n\
    \    mint bostan_mori(FPS<mint> P, FPS<mint> Q, ll n) {\n        auto even = [&](FPS<mint>\
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
    \ otera\n\n#endif // OTERA_BOSTAN_MORI\n"
  dependsOn:
  - library/Math/FPS.hpp
  isVerificationFile: false
  path: library/Math/BostanMori.hpp
  requiredBy: []
  timestamp: '2022-03-05 02:11:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Math/BostanMori.hpp
layout: document
redirect_from:
- /library/library/Math/BostanMori.hpp
- /library/library/Math/BostanMori.hpp.html
title: library/Math/BostanMori.hpp
---
