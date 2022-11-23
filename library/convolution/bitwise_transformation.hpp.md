---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/convolution/bitwise_transformation.hpp\"\n\n\n\n\
    namespace otera {\n    namespace internal {\n        template<typename T> \n \
    \       std::pair<T, T> subset_zeta_unit_transform(std::pair<T, T> a) {\n    \
    \        return std::make_pair(a.first, a.first + a.second);\n        }\n\n  \
    \      template<typename T> \n        std::pair<T, T> subset_mobius_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first, -a.first + a.second);\n\
    \        }\n\n        template<typename T> \n        std::pair<T, T> supset_zeta_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first + a.second, a.second);\n\
    \        }\n\n        template<typename T> \n        std::pair<T, T> supset_mobius_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first - a.second, a.second);\n\
    \        }\n\n        template<typename T> \n        std::pair<T, T> walsh_hadamard_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first + a.second, a.first - a.second);\n\
    \        }\n    } // namespace internal\n\n    template<typename T, std::pair<T,\
    \ T> (*unit_transform)(std::pair<T, T>)> \n    void kronecker_product(std::vector<T>\
    \ &x) {\n        const int n = (int)x.size();\n        // check n is power of\
    \ 2\n        assert(((n - 1) & n) == 0);\n        for(int bit = 1; bit < n; bit\
    \ <<= 1) {\n            int mask = ~bit;\n            for(int i = bit; i < n;\
    \ i = (i + 1) | bit) {\n                std::pair<T, T> res = unit_transform(std::make_pair(x[i\
    \ & mask], x[i]));\n                x[i & mask] = res.first;\n               \
    \ x[i] = res.second;\n            }\n        }\n    }\n\n    template<typename\
    \ T> void subset_zeta(std::vector<T> &x) {\n        kronecker_product<T, internal::subset_zeta_unit_transform<T>>(x);\n\
    \    }\n\n    template<typename T> void subset_mobius(std::vector<T> &x) {\n \
    \       kronecker_product<T, internal::subset_mobius_unit_transform<T>>(x);\n\
    \    }\n\n    template<typename T> void supset_zeta(std::vector<T> &x) {\n   \
    \     kronecker_product<T, internal::supset_zeta_unit_transform<T>>(x);\n    }\n\
    \n    template<typename T> void supset_mobius(std::vector<T> &x) {\n        kronecker_product<T,\
    \ internal::supset_mobius_unit_transform<T>>(x);\n    }\n\n    template<typename\
    \ T> void walsh_hadamard(std::vector<T> &x) {\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \    }\n\n    template<typename T> void walsh_hadamard_inv(std::vector<T> &x)\
    \ {\n        const int n = (int)x.size();\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \        for(auto &val: x) val /= n;\n    }\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_BITWISE_TRANSFORMATION\n#define OTERA_BITWISE_TRANSFORMATION\
    \ 1\n\nnamespace otera {\n    namespace internal {\n        template<typename\
    \ T> \n        std::pair<T, T> subset_zeta_unit_transform(std::pair<T, T> a) {\n\
    \            return std::make_pair(a.first, a.first + a.second);\n        }\n\n\
    \        template<typename T> \n        std::pair<T, T> subset_mobius_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first, -a.first + a.second);\n\
    \        }\n\n        template<typename T> \n        std::pair<T, T> supset_zeta_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first + a.second, a.second);\n\
    \        }\n\n        template<typename T> \n        std::pair<T, T> supset_mobius_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first - a.second, a.second);\n\
    \        }\n\n        template<typename T> \n        std::pair<T, T> walsh_hadamard_unit_transform(std::pair<T,\
    \ T> a) {\n            return std::make_pair(a.first + a.second, a.first - a.second);\n\
    \        }\n    } // namespace internal\n\n    template<typename T, std::pair<T,\
    \ T> (*unit_transform)(std::pair<T, T>)> \n    void kronecker_product(std::vector<T>\
    \ &x) {\n        const int n = (int)x.size();\n        // check n is power of\
    \ 2\n        assert(((n - 1) & n) == 0);\n        for(int bit = 1; bit < n; bit\
    \ <<= 1) {\n            int mask = ~bit;\n            for(int i = bit; i < n;\
    \ i = (i + 1) | bit) {\n                std::pair<T, T> res = unit_transform(std::make_pair(x[i\
    \ & mask], x[i]));\n                x[i & mask] = res.first;\n               \
    \ x[i] = res.second;\n            }\n        }\n    }\n\n    template<typename\
    \ T> void subset_zeta(std::vector<T> &x) {\n        kronecker_product<T, internal::subset_zeta_unit_transform<T>>(x);\n\
    \    }\n\n    template<typename T> void subset_mobius(std::vector<T> &x) {\n \
    \       kronecker_product<T, internal::subset_mobius_unit_transform<T>>(x);\n\
    \    }\n\n    template<typename T> void supset_zeta(std::vector<T> &x) {\n   \
    \     kronecker_product<T, internal::supset_zeta_unit_transform<T>>(x);\n    }\n\
    \n    template<typename T> void supset_mobius(std::vector<T> &x) {\n        kronecker_product<T,\
    \ internal::supset_mobius_unit_transform<T>>(x);\n    }\n\n    template<typename\
    \ T> void walsh_hadamard(std::vector<T> &x) {\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \    }\n\n    template<typename T> void walsh_hadamard_inv(std::vector<T> &x)\
    \ {\n        const int n = (int)x.size();\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \        for(auto &val: x) val /= n;\n    }\n} // namespace otera\n\n#endif //\
    \ OTERA_BITWISE_TRANSFORMATION"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/bitwise_transformation.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc212_h.test.cpp
documentation_of: library/convolution/bitwise_transformation.hpp
layout: document
redirect_from:
- /library/library/convolution/bitwise_transformation.hpp
- /library/library/convolution/bitwise_transformation.hpp.html
title: library/convolution/bitwise_transformation.hpp
---