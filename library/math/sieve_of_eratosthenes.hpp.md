---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1611.test.cpp
    title: test/yukicoder/1611.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/math/sieve_of_eratosthenes.hpp\"\n\n\n\nnamespace\
    \ otera {\n    struct eratos {\n        public:\n            eratos() : eratos(0)\
    \ {}\n            eratos(int N) { init(N); }\n\n            void init(int N) {\n\
    \                _N = N;\n                _primes.clear();\n                _isprime.assign(_N\
    \ + 1, true);\n                _min_factor.assign(_N + 1, -1);\n             \
    \   _isprime[0] = _isprime[1] = false;\n                _min_factor[0] = 0, _min_factor[1]\
    \ = 1;\n                for (int i = 2; i <= _N; ++i) {\n                    if\
    \ (!_isprime[i]) continue;\n                    _primes.push_back(i);\n      \
    \              _min_factor[i] = i;\n                    for (int j = i * 2; j\
    \ <= _N; j += i) {\n                        _isprime[j] = false;\n           \
    \             if (_min_factor[j] == -1) _min_factor[j] = i;\n                \
    \    }\n                }\n            }\n\n            bool isprime(int n) {\n\
    \                assert(0 <= n and n <= _N);\n                return _isprime[n];\n\
    \            }\n\n            std::vector<int> primes() {\n                return\
    \ _primes;\n            }\n\n            std::vector<std::pair<int,int>> prime_factors(int\
    \ n) {\n                std::vector<std::pair<int,int>> res;\n               \
    \ while (n != 1) {\n                    int prime = _min_factor[n];\n        \
    \            int exp = 0;\n                    while (_min_factor[n] == prime)\
    \ {\n                        ++exp;\n                        n /= prime;\n   \
    \                 }\n                    res.push_back(std::make_pair(prime, exp));\n\
    \                }\n                return res;\n            }\n\n           \
    \ std::vector<int> divisors(int n) {\n                std::vector<int> res({1});\n\
    \                auto pf = prime_factors(n);\n                for (auto p :pf)\
    \ {\n                    int n = (int)res.size();\n                    for (int\
    \ i = 0; i < n; ++i) {\n                        int v = 1;\n                 \
    \       for (int j = 0; j < p.second; ++j) {\n                            v *=\
    \ p.first;\n                            res.push_back(res[i] * v);\n         \
    \               }\n                    }\n                }\n                return\
    \ res;\n            }\n\n        private:\n            int _N;\n            std::vector<int>\
    \ _primes;\n            std::vector<bool> _isprime;\n            std::vector<int>\
    \ _min_factor;\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_SIEVE_OF_ERATOSTHENES_HPP\n#define OTERA_SIEVE_OF_ERATOSTHENES_HPP\
    \ 1\n\nnamespace otera {\n    struct eratos {\n        public:\n            eratos()\
    \ : eratos(0) {}\n            eratos(int N) { init(N); }\n\n            void init(int\
    \ N) {\n                _N = N;\n                _primes.clear();\n          \
    \      _isprime.assign(_N + 1, true);\n                _min_factor.assign(_N +\
    \ 1, -1);\n                _isprime[0] = _isprime[1] = false;\n              \
    \  _min_factor[0] = 0, _min_factor[1] = 1;\n                for (int i = 2; i\
    \ <= _N; ++i) {\n                    if (!_isprime[i]) continue;\n           \
    \         _primes.push_back(i);\n                    _min_factor[i] = i;\n   \
    \                 for (int j = i * 2; j <= _N; j += i) {\n                   \
    \     _isprime[j] = false;\n                        if (_min_factor[j] == -1)\
    \ _min_factor[j] = i;\n                    }\n                }\n            }\n\
    \n            bool isprime(int n) {\n                assert(0 <= n and n <= _N);\n\
    \                return _isprime[n];\n            }\n\n            std::vector<int>\
    \ primes() {\n                return _primes;\n            }\n\n            std::vector<std::pair<int,int>>\
    \ prime_factors(int n) {\n                std::vector<std::pair<int,int>> res;\n\
    \                while (n != 1) {\n                    int prime = _min_factor[n];\n\
    \                    int exp = 0;\n                    while (_min_factor[n] ==\
    \ prime) {\n                        ++exp;\n                        n /= prime;\n\
    \                    }\n                    res.push_back(std::make_pair(prime,\
    \ exp));\n                }\n                return res;\n            }\n\n  \
    \          std::vector<int> divisors(int n) {\n                std::vector<int>\
    \ res({1});\n                auto pf = prime_factors(n);\n                for\
    \ (auto p :pf) {\n                    int n = (int)res.size();\n             \
    \       for (int i = 0; i < n; ++i) {\n                        int v = 1;\n  \
    \                      for (int j = 0; j < p.second; ++j) {\n                \
    \            v *= p.first;\n                            res.push_back(res[i] *\
    \ v);\n                        }\n                    }\n                }\n \
    \               return res;\n            }\n\n        private:\n            int\
    \ _N;\n            std::vector<int> _primes;\n            std::vector<bool> _isprime;\n\
    \            std::vector<int> _min_factor;\n    };\n} // namespace otera\n\n#endif\
    \ // OTERA_SIEVE_OF_ERATOSTHENES_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/math/sieve_of_eratosthenes.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1611.test.cpp
documentation_of: library/math/sieve_of_eratosthenes.hpp
layout: document
redirect_from:
- /library/library/math/sieve_of_eratosthenes.hpp
- /library/library/math/sieve_of_eratosthenes.hpp.html
title: library/math/sieve_of_eratosthenes.hpp
---
