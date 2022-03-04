---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/AtCoder/modint.hpp
    title: library/AtCoder/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/Math/Factorial.hpp\"\n\n\n\n#include<library/AtCoder/modint.hpp>\n\
    \nnamespace otera{\n    template<typename T>\n    class factorial {\n        public:\n\
    \        factorial() {}\n        factorial(int n) {\n            ensure(n);\n\
    \        }\n        T com(const int n, const int k) {\n            if(n == k)\
    \ return 1;\n            if(n < k or n < 0 or k < 0) return 0;\n            ensure(n);\n\
    \            return fact_[n] * finv_[k] * finv_[n - k];\n        }\n        T\
    \ fact(const int n) {\n            if(n < 0) return 0;\n            ensure(n);\n\
    \            return fact_[n];\n        }\n        T inv(const int n) {\n     \
    \       if(n < 0) return 0;\n            ensure(n);\n            return inv_[n];\n\
    \        }\n        T finv(const int n) {\n            if(n < 0) return 0;\n \
    \           ensure(n);\n            return finv_[n];\n        }\n        private:\n\
    \        static std::vector<T> fact_, inv_, finv_;\n        int MOD = T::mod();\n\
    \        void ensure(const int n) {\n            int sz = fact_.size();\n    \
    \        if(n + 1 <= sz) return;\n            int next_sz = std::max(n + 1, sz\
    \ * 2);\n            fact_.resize(next_sz), inv_.resize(next_sz), finv_.resize(next_sz);\n\
    \            for(int i = sz; i < next_sz; ++ i) {\n                fact_[i] =\
    \ fact_[i - 1] * i;\n                inv_[i] = -inv_[MOD % i] * (MOD / i);\n \
    \               finv_[i] = finv_[i - 1] * inv_[i];\n            }\n        }\n\
    \    };\n    template<typename T> std::vector<T> factorial<T>::fact_ {1, 1};\n\
    \    template<typename T> std::vector<T> factorial<T>::inv_ {1, 1};\n    template<typename\
    \ T> std::vector<T> factorial<T>::finv_ {1, 1};\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_FACTORIAL_HPP\n#define OTERA_FACTORIAL_HPP 1\n\n#include<library/AtCoder/modint.hpp>\n\
    \nnamespace otera{\n    template<typename T>\n    class factorial {\n        public:\n\
    \        factorial() {}\n        factorial(int n) {\n            ensure(n);\n\
    \        }\n        T com(const int n, const int k) {\n            if(n == k)\
    \ return 1;\n            if(n < k or n < 0 or k < 0) return 0;\n            ensure(n);\n\
    \            return fact_[n] * finv_[k] * finv_[n - k];\n        }\n        T\
    \ fact(const int n) {\n            if(n < 0) return 0;\n            ensure(n);\n\
    \            return fact_[n];\n        }\n        T inv(const int n) {\n     \
    \       if(n < 0) return 0;\n            ensure(n);\n            return inv_[n];\n\
    \        }\n        T finv(const int n) {\n            if(n < 0) return 0;\n \
    \           ensure(n);\n            return finv_[n];\n        }\n        private:\n\
    \        static std::vector<T> fact_, inv_, finv_;\n        int MOD = T::mod();\n\
    \        void ensure(const int n) {\n            int sz = fact_.size();\n    \
    \        if(n + 1 <= sz) return;\n            int next_sz = std::max(n + 1, sz\
    \ * 2);\n            fact_.resize(next_sz), inv_.resize(next_sz), finv_.resize(next_sz);\n\
    \            for(int i = sz; i < next_sz; ++ i) {\n                fact_[i] =\
    \ fact_[i - 1] * i;\n                inv_[i] = -inv_[MOD % i] * (MOD / i);\n \
    \               finv_[i] = finv_[i - 1] * inv_[i];\n            }\n        }\n\
    \    };\n    template<typename T> std::vector<T> factorial<T>::fact_ {1, 1};\n\
    \    template<typename T> std::vector<T> factorial<T>::inv_ {1, 1};\n    template<typename\
    \ T> std::vector<T> factorial<T>::finv_ {1, 1};\n} // namespace otera\n\n#endif\
    \ // OTERA_FACTORAIL_HPP"
  dependsOn:
  - library/AtCoder/modint.hpp
  isVerificationFile: false
  path: library/Math/Factorial.hpp
  requiredBy: []
  timestamp: '2022-03-05 02:48:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Math/Factorial.hpp
layout: document
redirect_from:
- /library/library/Math/Factorial.hpp
- /library/library/Math/Factorial.hpp.html
title: library/Math/Factorial.hpp
---
