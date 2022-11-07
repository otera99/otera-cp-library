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
  bundledCode: "#line 1 \"library/Math/FPS.hpp\"\n// UNFINISHED\n#ifndef OTERA_FPS_HPP\n\
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
  path: library/Math/FPS.hpp
  requiredBy: []
  timestamp: '2022-09-02 19:58:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Math/FPS.hpp
layout: document
redirect_from:
- /library/library/Math/FPS.hpp
- /library/library/Math/FPS.hpp.html
title: library/Math/FPS.hpp
---
