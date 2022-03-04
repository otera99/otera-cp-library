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
  bundledCode: "#line 1 \"library/Other/Timer.hpp\"\nnamespace otera {\n    struct\
    \ Timer {\n        public:\n        Timer() {\n            start();\n        }\n\
    \        void start() {\n            time = std::clock();\n        }   \n    \
    \    double elapsed() {\n            return 1.0 * (std::clock() - time) / CLOCKS_PER_SEC;\n\
    \        }\n        private:\n        int time;\n    };\n} // namespace otera\n"
  code: "namespace otera {\n    struct Timer {\n        public:\n        Timer() {\n\
    \            start();\n        }\n        void start() {\n            time = std::clock();\n\
    \        }   \n        double elapsed() {\n            return 1.0 * (std::clock()\
    \ - time) / CLOCKS_PER_SEC;\n        }\n        private:\n        int time;\n\
    \    };\n} // namespace otera"
  dependsOn: []
  isVerificationFile: false
  path: library/Other/Timer.hpp
  requiredBy: []
  timestamp: '2022-03-05 02:11:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Other/Timer.hpp
layout: document
redirect_from:
- /library/library/Other/Timer.hpp
- /library/library/Other/Timer.hpp.html
title: library/Other/Timer.hpp
---
