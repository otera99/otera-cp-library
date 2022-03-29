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
  bundledCode: "#line 1 \"library/Convolution/BitwiseTransformation.hpp\"\n\n\n\n\
    namespace otera {\n    namespace internal {\n        template<typename T> \n \
    \       void subset_zeta_unit_transform(T &a, T &b) {\n            T c = a, d\
    \ = b;\n            a = c;\n            b = c + d;\n        }\n\n        template<typename\
    \ T> \n        void subset_mobius_unit_transform(T &a, T &b) {\n            T\
    \ c = a, d = b;\n            a = c;\n            b = -c + d;\n        }\n\n  \
    \      template<typename T> \n        void supset_zeta_unit_transform(T &a, T\
    \ &b) {\n            T c = a, d = b;\n            a = c + d;\n            b =\
    \ d;\n        }\n\n        template<typename T> \n        void supset_mobius_unit_transform(T\
    \ &a, T &b) {\n            T c = a, d = b;\n            a = c - d;\n         \
    \   b = d;\n        }\n\n        template<typename T> \n        void walsh_hadamard_unit_transform(T\
    \ &a, T &b) {\n            T c = a, d = b;\n            a = c + d;\n         \
    \   b = c - d;\n        }\n    } // namespace internal\n\n    template<typename\
    \ T, std::pair<T, T> (*unit)(std::pair<T, T>)> \n    void kronecker_product(std::vector<T>\
    \ &x) {\n        const int n = (int)x.size();\n        // check n is power of\
    \ 2\n        assert(((n - 1) & n) == 0);\n        for(int bit = 1; bit < n; bit\
    \ <<= 1) {\n            int mask = ~bit;\n            for(int i = bit; i < n;\
    \ i = (i + 1) | bit) {\n                std::pair<T, T> res = unit(x[i & mask],\
    \ x[i]);\n                x[i & mask] = res.first;\n                x[i] = res.second;\n\
    \            }\n        }\n    }\n\n    template<T> subset_zeta(std::vector<T>\
    \ &x) {\n        kronecker_product<T, internal::subset_zeta_unit_transform<T>>(x);\n\
    \    }\n\n    template<T> subset_mobius(std::vector<T> &x) {\n        kronecker_product<T,\
    \ internal::subset_mobiu_unit_transform<T>>(x);\n    }\n\n    template<T> supset_zeta(std::vector<T>\
    \ &x) {\n        kronecker_product<T, internal::supset_unit_transform<T>>(x);\n\
    \    }\n\n    template<T> supset_mobius(std::vector<T> &x) {\n        kronecker_product<T,\
    \ internal::supset_mobius_unit_transform<T>>(x);\n    }\n\n    template<T> walsh_hadamard(std::vector<T>\
    \ &x) {\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \    }\n\n    template<T> walsh_hadamard_inv(std::vector<T> &x) {\n        const\
    \ int n = (int)x.size();\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \        for(auto &val: x) val /= n;\n    }\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_BITWISE_TRANSFORMATION\n#define OTERA_BITWISE_TRANSFORMATION\
    \ 1\n\nnamespace otera {\n    namespace internal {\n        template<typename\
    \ T> \n        void subset_zeta_unit_transform(T &a, T &b) {\n            T c\
    \ = a, d = b;\n            a = c;\n            b = c + d;\n        }\n\n     \
    \   template<typename T> \n        void subset_mobius_unit_transform(T &a, T &b)\
    \ {\n            T c = a, d = b;\n            a = c;\n            b = -c + d;\n\
    \        }\n\n        template<typename T> \n        void supset_zeta_unit_transform(T\
    \ &a, T &b) {\n            T c = a, d = b;\n            a = c + d;\n         \
    \   b = d;\n        }\n\n        template<typename T> \n        void supset_mobius_unit_transform(T\
    \ &a, T &b) {\n            T c = a, d = b;\n            a = c - d;\n         \
    \   b = d;\n        }\n\n        template<typename T> \n        void walsh_hadamard_unit_transform(T\
    \ &a, T &b) {\n            T c = a, d = b;\n            a = c + d;\n         \
    \   b = c - d;\n        }\n    } // namespace internal\n\n    template<typename\
    \ T, std::pair<T, T> (*unit)(std::pair<T, T>)> \n    void kronecker_product(std::vector<T>\
    \ &x) {\n        const int n = (int)x.size();\n        // check n is power of\
    \ 2\n        assert(((n - 1) & n) == 0);\n        for(int bit = 1; bit < n; bit\
    \ <<= 1) {\n            int mask = ~bit;\n            for(int i = bit; i < n;\
    \ i = (i + 1) | bit) {\n                std::pair<T, T> res = unit(x[i & mask],\
    \ x[i]);\n                x[i & mask] = res.first;\n                x[i] = res.second;\n\
    \            }\n        }\n    }\n\n    template<T> subset_zeta(std::vector<T>\
    \ &x) {\n        kronecker_product<T, internal::subset_zeta_unit_transform<T>>(x);\n\
    \    }\n\n    template<T> subset_mobius(std::vector<T> &x) {\n        kronecker_product<T,\
    \ internal::subset_mobiu_unit_transform<T>>(x);\n    }\n\n    template<T> supset_zeta(std::vector<T>\
    \ &x) {\n        kronecker_product<T, internal::supset_unit_transform<T>>(x);\n\
    \    }\n\n    template<T> supset_mobius(std::vector<T> &x) {\n        kronecker_product<T,\
    \ internal::supset_mobius_unit_transform<T>>(x);\n    }\n\n    template<T> walsh_hadamard(std::vector<T>\
    \ &x) {\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \    }\n\n    template<T> walsh_hadamard_inv(std::vector<T> &x) {\n        const\
    \ int n = (int)x.size();\n        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);\n\
    \        for(auto &val: x) val /= n;\n    }\n} // namespace otera\n\n#endif OTERA_BITWISE_TRANSFORMATION"
  dependsOn: []
  isVerificationFile: false
  path: library/Convolution/BitwiseTransformation.hpp
  requiredBy: []
  timestamp: '2022-03-29 20:08:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Convolution/BitwiseTransformation.hpp
layout: document
redirect_from:
- /library/library/Convolution/BitwiseTransformation.hpp
- /library/library/Convolution/BitwiseTransformation.hpp.html
title: library/Convolution/BitwiseTransformation.hpp
---
