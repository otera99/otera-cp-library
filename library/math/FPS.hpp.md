---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/math/bostan_mori.hpp
    title: library/math/bostan_mori.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/FPS.hpp\"\n// UNFINISHED\n#ifndef OTERA_FPS_HPP\n\
    #define OTERA_FPS_HPP 1\n\nnamespace otera {\n    template<typename mint>\n  \
    \  struct FPS : std::vector<mint> {\n        public:\n\n        FPS operator -()\
    \ const {\n            FPS ret(*this);\n            for(auto &e: ret) e = -e;\n\
    \            return ret;\n        };\n        \n\n        private:\n    }\n} //\
    \ namespace otera\n\n#endif // OTERA_FPS_HPP\n"
  code: "// UNFINISHED\n#ifndef OTERA_FPS_HPP\n#define OTERA_FPS_HPP 1\n\nnamespace\
    \ otera {\n    template<typename mint>\n    struct FPS : std::vector<mint> {\n\
    \        public:\n\n        FPS operator -() const {\n            FPS ret(*this);\n\
    \            for(auto &e: ret) e = -e;\n            return ret;\n        };\n\
    \        \n\n        private:\n    }\n} // namespace otera\n\n#endif // OTERA_FPS_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/math/FPS.hpp
  requiredBy:
  - library/math/bostan_mori.hpp
  timestamp: '2022-11-08 07:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/FPS.hpp
layout: document
redirect_from:
- /library/library/math/FPS.hpp
- /library/library/math/FPS.hpp.html
title: library/math/FPS.hpp
---
