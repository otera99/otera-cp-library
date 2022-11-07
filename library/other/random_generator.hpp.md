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
  bundledCode: "#line 1 \"library/other/random_generator.hpp\"\n\n\n\nnamespace otera\
    \ {\n    class random_gen {\n        public:\n            random_gen() : mt64(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n            // [a, b)\n            long long operator()(long long a, long\
    \ long b) {\n                std::uniform_int_distribution<long long> dist(a,\
    \ b - 1);\n                return dist(mt64);\n            }\n        private:\n\
    \            std::mt19937_64 mt64;\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_RANDOM_GENERATOR_HPP\n#define OTERA_RANDOM_GENERATOR_HPP 1\n\
    \nnamespace otera {\n    class random_gen {\n        public:\n            random_gen()\
    \ : mt64(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n\n \
    \           // [a, b)\n            long long operator()(long long a, long long\
    \ b) {\n                std::uniform_int_distribution<long long> dist(a, b - 1);\n\
    \                return dist(mt64);\n            }\n        private:\n       \
    \     std::mt19937_64 mt64;\n    };\n} // namespace otera\n\n#endif // OTERA_RANDOM_GENERATOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: library/other/random_generator.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/other/random_generator.hpp
layout: document
redirect_from:
- /library/library/other/random_generator.hpp
- /library/library/other/random_generator.hpp.html
title: library/other/random_generator.hpp
---
