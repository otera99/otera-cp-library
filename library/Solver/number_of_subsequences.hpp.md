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
  bundledCode: "#line 1 \"library/Solver/number_of_subsequences.hpp\"\n\n\n\n\nnamespace\
    \ otera {\n    template<typename Int, typename T>\n    auto number_of_subsequences(const\
    \ std::vector<T> &a) -> decltype(std::declval<T>() < std::declval<T>(), Int{})\
    \ {\n        const int _n = a.size();\n        std::vector<std::pair<T, int>>\
    \ sorted(_n);\n        for(int i = 0; i < _n; ++ i) {\n            sorted[i] =\
    \ {a[i], i};\n        }\n        std::sort(sorted.begin(), sorted.end());\n\n\
    \        std::vector<int> last(_n, -1);\n        for(int i = 1; i < _n; ++ i)\
    \ {\n            if(sorted[i - 1].first == sorted[i].first) {\n              \
    \  int pre_id = sorted[i - 1].second, id = sorted[i].second;\n               \
    \ last[id] = pre_id;\n            }\n        }\n\n        std::vector<Int> sdp(_n\
    \ + 2);\n        sdp[1] = 1;\n        for(int i = 0; i < _n; ++ i) {\n       \
    \     sdp[i + 2] = sdp[i + 1] + sdp[i + 1] - sdp[last[i] + 1];\n        }\n  \
    \      return sdp[_n + 1];\n    }\n\n    template<typename Int>\n    auto number_of_subsequences(const\
    \ std::string &s) -> decltype(Int{}) {\n        const int _n = s.size();\n   \
    \     std::vector<std::pair<char, int>> sorted(_n);\n        for(int i = 0; i\
    \ < _n; ++ i) {\n            sorted[i] = {s[i], i};\n        }\n        std::sort(sorted.begin(),\
    \ sorted.end());\n\n        std::vector<int> last(_n, -1);\n        for(int i\
    \ = 1; i < _n; ++ i) {\n            if(sorted[i - 1].first == sorted[i].first)\
    \ {\n                int pre_id = sorted[i - 1].second, id = sorted[i].second;\n\
    \                last[id] = pre_id;\n            }\n        }\n\n        std::vector<Int>\
    \ sdp(_n + 2);\n        sdp[1] = 1;\n        for(int i = 0; i < _n; ++ i) {\n\
    \            sdp[i + 2] = sdp[i + 1] + sdp[i + 1] - sdp[last[i] + 1];\n      \
    \  }\n        return sdp[_n + 1];\n    }\n} // namespace otera \n\n\n"
  code: "#ifndef OTERA_NUMBER_OF_SUBSEQUENCES_HPP\n#define OTERA_NUMBER_OF_SUBSEQUENCES_HPP\
    \ 1\n\n\nnamespace otera {\n    template<typename Int, typename T>\n    auto number_of_subsequences(const\
    \ std::vector<T> &a) -> decltype(std::declval<T>() < std::declval<T>(), Int{})\
    \ {\n        const int _n = a.size();\n        std::vector<std::pair<T, int>>\
    \ sorted(_n);\n        for(int i = 0; i < _n; ++ i) {\n            sorted[i] =\
    \ {a[i], i};\n        }\n        std::sort(sorted.begin(), sorted.end());\n\n\
    \        std::vector<int> last(_n, -1);\n        for(int i = 1; i < _n; ++ i)\
    \ {\n            if(sorted[i - 1].first == sorted[i].first) {\n              \
    \  int pre_id = sorted[i - 1].second, id = sorted[i].second;\n               \
    \ last[id] = pre_id;\n            }\n        }\n\n        std::vector<Int> sdp(_n\
    \ + 2);\n        sdp[1] = 1;\n        for(int i = 0; i < _n; ++ i) {\n       \
    \     sdp[i + 2] = sdp[i + 1] + sdp[i + 1] - sdp[last[i] + 1];\n        }\n  \
    \      return sdp[_n + 1];\n    }\n\n    template<typename Int>\n    auto number_of_subsequences(const\
    \ std::string &s) -> decltype(Int{}) {\n        const int _n = s.size();\n   \
    \     std::vector<std::pair<char, int>> sorted(_n);\n        for(int i = 0; i\
    \ < _n; ++ i) {\n            sorted[i] = {s[i], i};\n        }\n        std::sort(sorted.begin(),\
    \ sorted.end());\n\n        std::vector<int> last(_n, -1);\n        for(int i\
    \ = 1; i < _n; ++ i) {\n            if(sorted[i - 1].first == sorted[i].first)\
    \ {\n                int pre_id = sorted[i - 1].second, id = sorted[i].second;\n\
    \                last[id] = pre_id;\n            }\n        }\n\n        std::vector<Int>\
    \ sdp(_n + 2);\n        sdp[1] = 1;\n        for(int i = 0; i < _n; ++ i) {\n\
    \            sdp[i + 2] = sdp[i + 1] + sdp[i + 1] - sdp[last[i] + 1];\n      \
    \  }\n        return sdp[_n + 1];\n    }\n} // namespace otera \n\n#endif // OTERA_NUMBER_OF_SUBSEQUENCES_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/Solver/number_of_subsequences.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Solver/number_of_subsequences.hpp
layout: document
redirect_from:
- /library/library/Solver/number_of_subsequences.hpp
- /library/library/Solver/number_of_subsequences.hpp.html
title: library/Solver/number_of_subsequences.hpp
---
