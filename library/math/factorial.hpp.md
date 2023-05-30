---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/factorial.hpp\"\n\n\n\n#include<library/modint/modint.hpp>\n\
    \nnamespace otera{\n    template<typename T>\n    class factorial {\n        public:\n\
    \        factorial() {}\n        factorial(int n) {\n            ensure(n);\n\
    \        }\n        T perm(const int n, const int k) {\n            if(k < 0 or\
    \ n < k) return 0;\n            ensure(n);\n            return fact_[n] * finv_[n\
    \ - k];\n        }\n        T com(const int n, const int k) {\n            if(n\
    \ == k) return 1;\n            if(n < k or n < 0 or k < 0) return 0;\n       \
    \     ensure(n);\n            return fact_[n] * finv_[k] * finv_[n - k];\n   \
    \     }\n        T hom(const int n, const int k) {\n            if(n < 0 or k\
    \ < 0) return 0;\n            if(k == 0) return 1;\n            return com(n +\
    \ k - 1, k);\n        }\n        T fact(const int n) {\n            if(n < 0)\
    \ return 0;\n            ensure(n);\n            return fact_[n];\n        }\n\
    \        T finv(const int n) {\n            if(n < 0) return 0;\n            ensure(n);\n\
    \            return finv_[n];\n        }\n        private:\n        static std::vector<T>\
    \ fact_, inv_, finv_;\n        void ensure(const int n) {\n            int sz\
    \ = fact_.size();\n            if(n + 1 <= sz) return;\n            int next_sz\
    \ = std::max(n + 1, sz * 2);\n            fact_.resize(next_sz), finv_.resize(next_sz);\n\
    \            for(int i = sz; i < next_sz; ++ i) {\n                fact_[i] =\
    \ fact_[i - 1] * i;\n            }\n            finv_[next_sz - 1] = T(1) / fact_[next_sz\
    \ - 1];\n            for(int i = next_sz - 1; i > sz; -- i) {\n              \
    \  finv_[i - 1] = finv_[i] * i;\n            }\n        }\n    };\n    template<typename\
    \ T> std::vector<T> factorial<T>::fact_ {1, 1};\n    template<typename T> std::vector<T>\
    \ factorial<T>::finv_ {1, 1};\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_FACTORIAL_HPP\n#define OTERA_FACTORIAL_HPP 1\n\n#include<library/modint/modint.hpp>\n\
    \nnamespace otera{\n    template<typename T>\n    class factorial {\n        public:\n\
    \        factorial() {}\n        factorial(int n) {\n            ensure(n);\n\
    \        }\n        T perm(const int n, const int k) {\n            if(k < 0 or\
    \ n < k) return 0;\n            ensure(n);\n            return fact_[n] * finv_[n\
    \ - k];\n        }\n        T com(const int n, const int k) {\n            if(n\
    \ == k) return 1;\n            if(n < k or n < 0 or k < 0) return 0;\n       \
    \     ensure(n);\n            return fact_[n] * finv_[k] * finv_[n - k];\n   \
    \     }\n        T hom(const int n, const int k) {\n            if(n < 0 or k\
    \ < 0) return 0;\n            if(k == 0) return 1;\n            return com(n +\
    \ k - 1, k);\n        }\n        T fact(const int n) {\n            if(n < 0)\
    \ return 0;\n            ensure(n);\n            return fact_[n];\n        }\n\
    \        T finv(const int n) {\n            if(n < 0) return 0;\n            ensure(n);\n\
    \            return finv_[n];\n        }\n        private:\n        static std::vector<T>\
    \ fact_, inv_, finv_;\n        void ensure(const int n) {\n            int sz\
    \ = fact_.size();\n            if(n + 1 <= sz) return;\n            int next_sz\
    \ = std::max(n + 1, sz * 2);\n            fact_.resize(next_sz), finv_.resize(next_sz);\n\
    \            for(int i = sz; i < next_sz; ++ i) {\n                fact_[i] =\
    \ fact_[i - 1] * i;\n            }\n            finv_[next_sz - 1] = T(1) / fact_[next_sz\
    \ - 1];\n            for(int i = next_sz - 1; i > sz; -- i) {\n              \
    \  finv_[i - 1] = finv_[i] * i;\n            }\n        }\n    };\n    template<typename\
    \ T> std::vector<T> factorial<T>::fact_ {1, 1};\n    template<typename T> std::vector<T>\
    \ factorial<T>::finv_ {1, 1};\n} // namespace otera\n\n#endif // OTERA_FACTORAIL_HPP"
  dependsOn:
  - library/modint/modint.hpp
  isVerificationFile: false
  path: library/math/factorial.hpp
  requiredBy: []
  timestamp: '2023-05-31 05:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/factorial.hpp
layout: document
redirect_from:
- /library/library/math/factorial.hpp
- /library/library/math/factorial.hpp.html
title: library/math/factorial.hpp
---
