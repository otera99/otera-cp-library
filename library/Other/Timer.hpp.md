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
  bundledCode: "#line 1 \"library/Other/Timer.hpp\"\n\n\n\nnamespace otera {\n   \
    \ struct timer {\n        public:\n        timer() {\n            start();\n \
    \       }\n        void start() {\n            time = std::clock();\n        }\
    \   \n        double elapsed() {\n            return 1.0 * (std::clock() - time)\
    \ / CLOCKS_PER_SEC;\n        }\n        private:\n        int time;\n    };\n\
    } // namespace otera\n\n\n"
  code: "#ifndef OTERA_TIMER_HPP\n#define OTERA_TIMER_HPP 1\n\nnamespace otera {\n\
    \    struct timer {\n        public:\n        timer() {\n            start();\n\
    \        }\n        void start() {\n            time = std::clock();\n       \
    \ }   \n        double elapsed() {\n            return 1.0 * (std::clock() - time)\
    \ / CLOCKS_PER_SEC;\n        }\n        private:\n        int time;\n    };\n\
    } // namespace otera\n\n#endif // OTERA_TIMER_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/Other/Timer.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Other/Timer.hpp
layout: document
redirect_from:
- /library/library/Other/Timer.hpp
- /library/library/Other/Timer.hpp.html
title: library/Other/Timer.hpp
---
