---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/pow_table.hpp\"\n\n\n\n#include<library/modint/modint.hpp>\n\
    \nnamespace otera{\n    template<typename T>\n    class pow_table {\n        public:\n\
    \        pow_table(T x) : x_(x), pw_(1, 1) {}\n        pow_table(T x, int n) :\
    \ x_(x), pw_(1, 1) {\n            ensure(n);\n        }\n        T pow(const int\
    \ n) {\n            assert(n >= 0);\n            ensure(n);\n            return\
    \ pw_[n];\n        }\n        T operator[](const int n) {\n            return\
    \ pow(n);\n        }\n        private:\n        T x_;\n        std::vector<T>\
    \ pw_;\n        void ensure(const int n) {\n            int sz = pw_.size();\n\
    \            if(n + 1 <= sz) return;\n            int next_sz = std::max(n + 1,\
    \ sz * 2);\n            pw_.resize(next_sz);\n            for(int i = sz; i <\
    \ next_sz; ++ i) {\n                pw_[i] = pw_[i - 1] * x_;\n            }\n\
    \        }\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_POW_TABLE_HPP\n#define OTERA_POW_TABLE_HPP 1\n\n#include<library/modint/modint.hpp>\n\
    \nnamespace otera{\n    template<typename T>\n    class pow_table {\n        public:\n\
    \        pow_table(T x) : x_(x), pw_(1, 1) {}\n        pow_table(T x, int n) :\
    \ x_(x), pw_(1, 1) {\n            ensure(n);\n        }\n        T pow(const int\
    \ n) {\n            assert(n >= 0);\n            ensure(n);\n            return\
    \ pw_[n];\n        }\n        T operator[](const int n) {\n            return\
    \ pow(n);\n        }\n        private:\n        T x_;\n        std::vector<T>\
    \ pw_;\n        void ensure(const int n) {\n            int sz = pw_.size();\n\
    \            if(n + 1 <= sz) return;\n            int next_sz = std::max(n + 1,\
    \ sz * 2);\n            pw_.resize(next_sz);\n            for(int i = sz; i <\
    \ next_sz; ++ i) {\n                pw_[i] = pw_[i - 1] * x_;\n            }\n\
    \        }\n    };\n} // namespace otera\n\n#endif // OTERA_POW_TABLE_HPP"
  dependsOn:
  - library/modint/modint.hpp
  isVerificationFile: false
  path: library/math/pow_table.hpp
  requiredBy: []
  timestamp: '2022-11-24 05:18:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/pow_table.hpp
layout: document
redirect_from:
- /library/library/math/pow_table.hpp
- /library/library/math/pow_table.hpp.html
title: library/math/pow_table.hpp
---
