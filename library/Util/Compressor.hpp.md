---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/src/Util/Compressor.test.cpp
    title: test/src/Util/Compressor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/Util/Compressor.hpp\"\nnamespace otera {\n    template\
    \ <typename T>\n    struct Compressor {\n        public:\n            static constexpr\
    \ int absent = -1;\n\n            Compressor(const std::vector<T> &vs) {\n   \
    \             add(vs);\n            }\n\n            void add(const std::vector<T>\
    \ &vs) {\n                copy(vs.begin(), vs.end(), std::back_inserter(_xs));\n\
    \            }\n\n            void add(const T &e) {\n                _xs.emplace_back(e);\n\
    \            }\n\n            void build() {\n                std::sort(_xs.begin(),\
    \ _xs.end());\n                _xs.erase(std::unique(_xs.begin(), _xs.end()),\
    \ _xs.end());\n            }\n\n            int size() const {\n             \
    \   return _xs.size();\n            }\n\n            bool has_key(const T &e)\
    \ const {\n                return std::binary_search(_xs.begin(), _xs.end(), e);\n\
    \            }\n\n            std::vector<int> get(const std::vector<T> &vs) const\
    \ {\n                std::vector<int> res;\n                std::transform(vs.begin(),\
    \ vs.end(), std::back_inserter(res), [&](const T &e) {\n                    return\
    \ get(e);\n                });\n                return res;\n            }\n\n\
    \            int get(const T &e, int default_value = absent) const {\n       \
    \         const int id = min_geq_index(e);\n                return id != size()\
    \ and _xs[id] == e ? id : default_value;\n            }\n\n            const T\
    \ &operator[](int compressed_index) const {\n                return _xs[compressed_index];\n\
    \            }\n\n            // Return the minimum registered value greater than\
    \ `e`. if not exists, return `default_value`.\n            T min_gt(const T &e,\
    \ const T &default_value) const {\n                auto it = std::upper_bound(_xs.begin(),\
    \ _xs.end(), e);\n                return it == _xs.end() ? default_value : *it;\n\
    \            }\n            // Return the minimum registered value greater than\
    \ or equal to `e`. if not exists, return `default_value`.\n            T min_geq(const\
    \ T &e, const T &default_value) const {\n                auto it = std::lower_bound(_xs.begin(),\
    \ _xs.end(), e);\n                return it == _xs.end() ? default_value : *it;\n\
    \            }\n            // Return the maximum registered value less than `e`.\
    \ if not exists, return `default_value`\n            T max_lt(const T &e, const\
    \ T &default_value) const {\n                auto it = std::upper_bound(_xs.rbegin(),\
    \ _xs.rend(), e);\n                return it == _xs.rend() ? default_value : *it;\n\
    \            }\n            // Return the maximum registered value less than or\
    \ equal to `e`. if not exists, return `default_value`\n            T max_leq(const\
    \ T &e, const T &default_value) const {\n                auto it = std::lower_bound(_xs.rbegin(),\
    \ _xs.rend(), e);\n                return it == _xs.rend() ? default_value : *it;\n\
    \            }\n            // Return the compressed index of the minimum registered\
    \ value greater than `e`. if not exists, return `Compressor.size()`.\n       \
    \     int min_gt_index(const T &e) const {\n                return std::upper_bound(_xs.begin(),\
    \ _xs.end(), e) - _xs.begin();\n            }\n            // Return the compressed\
    \ index of the minimum registered value greater than or equal to `e`. if not exists,\
    \ return `Compressor.size()`.\n            int min_geq_index(const T &e) const\
    \ {\n                return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();\n\
    \            }\n            // Return the compressed index of the maximum registered\
    \ value less than `e`. if not exists, return -1.\n            int max_lt_index(const\
    \ T &e) const {\n                return int(_xs.rend() - std::upper_bound(_xs.rbegin(),\
    \ _xs.rend(), e)) - 1;\n            }\n            // Return the compressed index\
    \ of the maximum registered value less than or equal to `e`. if not exists, return\
    \ -1.\n            int max_leq_index(const T &e) const {\n                return\
    \ int(_xs.rend() - std::lower_bound(_xs.rbegin(), _xs.rend(), e)) - 1;\n     \
    \       }\n        private:\n            std::vector<T> _xs;\n    };\n} // namespace\
    \ otera\n"
  code: "namespace otera {\n    template <typename T>\n    struct Compressor {\n \
    \       public:\n            static constexpr int absent = -1;\n\n           \
    \ Compressor(const std::vector<T> &vs) {\n                add(vs);\n         \
    \   }\n\n            void add(const std::vector<T> &vs) {\n                copy(vs.begin(),\
    \ vs.end(), std::back_inserter(_xs));\n            }\n\n            void add(const\
    \ T &e) {\n                _xs.emplace_back(e);\n            }\n\n           \
    \ void build() {\n                std::sort(_xs.begin(), _xs.end());\n       \
    \         _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());\n       \
    \     }\n\n            int size() const {\n                return _xs.size();\n\
    \            }\n\n            bool has_key(const T &e) const {\n             \
    \   return std::binary_search(_xs.begin(), _xs.end(), e);\n            }\n\n \
    \           std::vector<int> get(const std::vector<T> &vs) const {\n         \
    \       std::vector<int> res;\n                std::transform(vs.begin(), vs.end(),\
    \ std::back_inserter(res), [&](const T &e) {\n                    return get(e);\n\
    \                });\n                return res;\n            }\n\n         \
    \   int get(const T &e, int default_value = absent) const {\n                const\
    \ int id = min_geq_index(e);\n                return id != size() and _xs[id]\
    \ == e ? id : default_value;\n            }\n\n            const T &operator[](int\
    \ compressed_index) const {\n                return _xs[compressed_index];\n \
    \           }\n\n            // Return the minimum registered value greater than\
    \ `e`. if not exists, return `default_value`.\n            T min_gt(const T &e,\
    \ const T &default_value) const {\n                auto it = std::upper_bound(_xs.begin(),\
    \ _xs.end(), e);\n                return it == _xs.end() ? default_value : *it;\n\
    \            }\n            // Return the minimum registered value greater than\
    \ or equal to `e`. if not exists, return `default_value`.\n            T min_geq(const\
    \ T &e, const T &default_value) const {\n                auto it = std::lower_bound(_xs.begin(),\
    \ _xs.end(), e);\n                return it == _xs.end() ? default_value : *it;\n\
    \            }\n            // Return the maximum registered value less than `e`.\
    \ if not exists, return `default_value`\n            T max_lt(const T &e, const\
    \ T &default_value) const {\n                auto it = std::upper_bound(_xs.rbegin(),\
    \ _xs.rend(), e);\n                return it == _xs.rend() ? default_value : *it;\n\
    \            }\n            // Return the maximum registered value less than or\
    \ equal to `e`. if not exists, return `default_value`\n            T max_leq(const\
    \ T &e, const T &default_value) const {\n                auto it = std::lower_bound(_xs.rbegin(),\
    \ _xs.rend(), e);\n                return it == _xs.rend() ? default_value : *it;\n\
    \            }\n            // Return the compressed index of the minimum registered\
    \ value greater than `e`. if not exists, return `Compressor.size()`.\n       \
    \     int min_gt_index(const T &e) const {\n                return std::upper_bound(_xs.begin(),\
    \ _xs.end(), e) - _xs.begin();\n            }\n            // Return the compressed\
    \ index of the minimum registered value greater than or equal to `e`. if not exists,\
    \ return `Compressor.size()`.\n            int min_geq_index(const T &e) const\
    \ {\n                return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();\n\
    \            }\n            // Return the compressed index of the maximum registered\
    \ value less than `e`. if not exists, return -1.\n            int max_lt_index(const\
    \ T &e) const {\n                return int(_xs.rend() - std::upper_bound(_xs.rbegin(),\
    \ _xs.rend(), e)) - 1;\n            }\n            // Return the compressed index\
    \ of the maximum registered value less than or equal to `e`. if not exists, return\
    \ -1.\n            int max_leq_index(const T &e) const {\n                return\
    \ int(_xs.rend() - std::lower_bound(_xs.rbegin(), _xs.rend(), e)) - 1;\n     \
    \       }\n        private:\n            std::vector<T> _xs;\n    };\n} // namespace\
    \ otera"
  dependsOn: []
  isVerificationFile: false
  path: library/Util/Compressor.hpp
  requiredBy: []
  timestamp: '2022-01-30 20:29:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/src/Util/Compressor.test.cpp
documentation_of: library/Util/Compressor.hpp
layout: document
redirect_from:
- /library/library/Util/Compressor.hpp
- /library/library/Util/Compressor.hpp.html
title: library/Util/Compressor.hpp
---