---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/cartesian_tree.test.cpp
    title: test/library_checker/tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structure/cartesian_tree.hpp\"\n\n\n\nnamespace\
    \ otera {\n    // \u6839\u3092\u6700\u5C0F\u306B\u3057\u305F\u3044\u306A\u3089\
    less<T>, \u6839\u3092\u6700\u5927\u306B\u3057\u305F\u3044\u306A\u3089greater<T>\n\
    \    template<typename T, typename Comparator>\n    struct cartesian_tree : public\
    \ std::vector<std::array<int, 2>> {\n        public:\n            static constexpr\
    \ int absent = -1;\n\n            cartesian_tree(const std::vector<T> &a, Comparator\
    \ comp = Comparator{}) {\n                build(a, comp);\n            }\n\n \
    \           int parent(std::size_t i) const {\n                assert(i < _par.size());\
    \ \n                return _par[i];\n            }\n\n            int root() const\
    \ {\n                return _root;\n            }\n\n        private:\n      \
    \      int _root;\n            std::vector<int> _par;\n\n            void build(const\
    \ std::vector<T> &a, Comparator comp = Comparator{}) {\n                int n\
    \ = (int)a.size();\n                std::vector<int> st;\n                st.reserve(n);\n\
    \                _par.assign(n, -1);\n                for(int i = 0; i < n; ++\
    \ i) {\n                    int p = -1;\n                    while(!st.empty()\
    \ && comp(a[i], a[st.back()])) {\n                        p = st.back();\n   \
    \                     st.pop_back();\n                    }\n                \
    \    if(p != -1) _par[p] = i;\n                    if(!st.empty()) _par[i] = st.back();\n\
    \                    st.push_back(i);\n                }\n                int\
    \ _root = -1;\n                (*this).assign(n, { absent, absent });\n      \
    \          for(int i = 0; i < n; ++ i) {\n                    int p = _par[i];\n\
    \                    (p >= 0 ? (*this)[p][p <= i] : (*this)._root) = i;\n    \
    \            }\n            }\n    };\n    \n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_CARTESIAN_TREE_HPP\n#define OTERA_CARTESIAN_TREE_HPP 1\n\n\
    namespace otera {\n    // \u6839\u3092\u6700\u5C0F\u306B\u3057\u305F\u3044\u306A\
    \u3089less<T>, \u6839\u3092\u6700\u5927\u306B\u3057\u305F\u3044\u306A\u3089greater<T>\n\
    \    template<typename T, typename Comparator>\n    struct cartesian_tree : public\
    \ std::vector<std::array<int, 2>> {\n        public:\n            static constexpr\
    \ int absent = -1;\n\n            cartesian_tree(const std::vector<T> &a, Comparator\
    \ comp = Comparator{}) {\n                build(a, comp);\n            }\n\n \
    \           int parent(std::size_t i) const {\n                assert(i < _par.size());\
    \ \n                return _par[i];\n            }\n\n            int root() const\
    \ {\n                return _root;\n            }\n\n        private:\n      \
    \      int _root;\n            std::vector<int> _par;\n\n            void build(const\
    \ std::vector<T> &a, Comparator comp = Comparator{}) {\n                int n\
    \ = (int)a.size();\n                std::vector<int> st;\n                st.reserve(n);\n\
    \                _par.assign(n, -1);\n                for(int i = 0; i < n; ++\
    \ i) {\n                    int p = -1;\n                    while(!st.empty()\
    \ && comp(a[i], a[st.back()])) {\n                        p = st.back();\n   \
    \                     st.pop_back();\n                    }\n                \
    \    if(p != -1) _par[p] = i;\n                    if(!st.empty()) _par[i] = st.back();\n\
    \                    st.push_back(i);\n                }\n                int\
    \ _root = -1;\n                (*this).assign(n, { absent, absent });\n      \
    \          for(int i = 0; i < n; ++ i) {\n                    int p = _par[i];\n\
    \                    (p >= 0 ? (*this)[p][p <= i] : (*this)._root) = i;\n    \
    \            }\n            }\n    };\n    \n} // namespace otera\n\n#endif //\
    \ OTERA_CARTESIAN_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2023-05-31 05:55:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/cartesian_tree.test.cpp
documentation_of: library/data_structure/cartesian_tree.hpp
layout: document
redirect_from:
- /library/library/data_structure/cartesian_tree.hpp
- /library/library/data_structure/cartesian_tree.hpp.html
title: library/data_structure/cartesian_tree.hpp
---
