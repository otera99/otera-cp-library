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
  bundledCode: "#line 1 \"library/Other/RandomGenerator.hpp\"\nnamespace otera {\n\
    \    class RandomGenerator {\n        public:\n            RandomGenerator() :\
    \ mt64(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n\n   \
    \         // [a, b)\n            long long operator()(long long a, long long b)\
    \ {\n                std::uniform_int_distribution<long long> dist(a, b - 1);\n\
    \                return dist(mt64);\n            }\n        private:\n       \
    \     std::mt19937_64 mt64;\n    };\n} // namespace otera\n"
  code: "namespace otera {\n    class RandomGenerator {\n        public:\n       \
    \     RandomGenerator() : mt64(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n            // [a, b)\n            long long operator()(long long a, long\
    \ long b) {\n                std::uniform_int_distribution<long long> dist(a,\
    \ b - 1);\n                return dist(mt64);\n            }\n        private:\n\
    \            std::mt19937_64 mt64;\n    };\n} // namespace otera\n"
  dependsOn: []
  isVerificationFile: false
  path: library/Other/RandomGenerator.hpp
  requiredBy: []
  timestamp: '2022-02-04 19:50:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Other/RandomGenerator.hpp
layout: document
redirect_from:
- /library/library/Other/RandomGenerator.hpp
- /library/library/Other/RandomGenerator.hpp.html
title: library/Other/RandomGenerator.hpp
---
