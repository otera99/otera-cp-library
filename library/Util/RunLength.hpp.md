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
  bundledCode: "#line 1 \"library/Util/RunLength.hpp\"\n\n\n\nnamespace otera{\n \
    \   template <typename Container>\n    class RunLength {\n        public:\n  \
    \          using content_type = typename Container::value_type;\n            using\
    \ value_type = std::pair<content_type, long long>;\n            RunLength(const\
    \ Container &c) noexcept {\n                _compressed = compress(c);\n     \
    \       }\n\n            void clear() {\n                _compressed.clear();\n\
    \            }\n\n            int size() const noexcept {\n                return\
    \ (int)_compressed.size();\n            }\n            const value_type &operator[](int\
    \ compressed_index) const {\n                return _compressed[compressed_index];\n\
    \            }\n\n            auto begin()   const noexcept { return _compressed.begin();\
    \   }\n            auto end()     const noexcept { return _compressed.end(); \
    \    }\n            auto rbegin()  const noexcept { return _compressed.rbegin();\
    \  }\n            auto rend()    const noexcept { return _compressed.rend(); \
    \   }\n            auto back()    const noexcept { return _compressed.back();\
    \    }\n            auto front()   const noexcept { return _compressed.front();\
    \    }\n\n            void push_back(const content_type &val, const long long\
    \ cnt = 1) {\n                if (_compressed.size() and _compressed.back().first\
    \ == val) {\n                    _compressed.back().second += cnt;\n         \
    \       } else {\n                    _compressed.emplace_back(val, cnt);\n  \
    \              }\n            }\n\n            void pop_back(long long cnt = 1)\
    \ {\n                while(_compressed.size() and cnt > 0) {\n               \
    \     if(cnt < _compressed.back().second) {\n                        _compressed.back().second\
    \ -= cnt;\n                        cnt = 0;\n                    } else {\n  \
    \                      cnt -= _compressed.back().second;\n                   \
    \     _compressed.pop_back();\n                    }\n                }\n    \
    \        }\n\n            static std::vector<value_type> compress(const Container\
    \ &c) {\n                std::vector<value_type> res;\n                for(auto\
    \ ite_l = c.begin(), ite_r = c.begin(); ite_l != c.end(); ite_l = ite_r) {\n \
    \                   while (ite_r != c.end() and *ite_l == *ite_r) ++ite_r;\n \
    \                   res.emplace_back(*ite_l, ite_r - ite_l);\n               \
    \ }\n                return res;\n            }\n        private:\n          \
    \  std::vector<value_type> _compressed;\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_RUNLENGTH_HPP\n#define OTERA_RUNLENGTH_HPP 1\n\nnamespace otera{\n\
    \    template <typename Container>\n    class RunLength {\n        public:\n \
    \           using content_type = typename Container::value_type;\n           \
    \ using value_type = std::pair<content_type, long long>;\n            RunLength(const\
    \ Container &c) noexcept {\n                _compressed = compress(c);\n     \
    \       }\n\n            void clear() {\n                _compressed.clear();\n\
    \            }\n\n            int size() const noexcept {\n                return\
    \ (int)_compressed.size();\n            }\n            const value_type &operator[](int\
    \ compressed_index) const {\n                return _compressed[compressed_index];\n\
    \            }\n\n            auto begin()   const noexcept { return _compressed.begin();\
    \   }\n            auto end()     const noexcept { return _compressed.end(); \
    \    }\n            auto rbegin()  const noexcept { return _compressed.rbegin();\
    \  }\n            auto rend()    const noexcept { return _compressed.rend(); \
    \   }\n            auto back()    const noexcept { return _compressed.back();\
    \    }\n            auto front()   const noexcept { return _compressed.front();\
    \    }\n\n            void push_back(const content_type &val, const long long\
    \ cnt = 1) {\n                if (_compressed.size() and _compressed.back().first\
    \ == val) {\n                    _compressed.back().second += cnt;\n         \
    \       } else {\n                    _compressed.emplace_back(val, cnt);\n  \
    \              }\n            }\n\n            void pop_back(long long cnt = 1)\
    \ {\n                while(_compressed.size() and cnt > 0) {\n               \
    \     if(cnt < _compressed.back().second) {\n                        _compressed.back().second\
    \ -= cnt;\n                        cnt = 0;\n                    } else {\n  \
    \                      cnt -= _compressed.back().second;\n                   \
    \     _compressed.pop_back();\n                    }\n                }\n    \
    \        }\n\n            static std::vector<value_type> compress(const Container\
    \ &c) {\n                std::vector<value_type> res;\n                for(auto\
    \ ite_l = c.begin(), ite_r = c.begin(); ite_l != c.end(); ite_l = ite_r) {\n \
    \                   while (ite_r != c.end() and *ite_l == *ite_r) ++ite_r;\n \
    \                   res.emplace_back(*ite_l, ite_r - ite_l);\n               \
    \ }\n                return res;\n            }\n        private:\n          \
    \  std::vector<value_type> _compressed;\n    };\n} // namespace otera\n\n#endif\
    \ // OTERA_RUNLENGTH_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/Util/RunLength.hpp
  requiredBy: []
  timestamp: '2022-03-05 02:48:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Util/RunLength.hpp
layout: document
redirect_from:
- /library/library/Util/RunLength.hpp
- /library/library/Util/RunLength.hpp.html
title: library/Util/RunLength.hpp
---
