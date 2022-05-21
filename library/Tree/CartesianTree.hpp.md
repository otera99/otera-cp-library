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
  bundledCode: "#line 1 \"library/Tree/CartesianTree.hpp\"\n\n\n\nnamespace otera\
    \ {\n    // \u6839\u3092\u6700\u5C0F\u306B\u3057\u305F\u3044\u306A\u3089less<T>,\
    \ \u6839\u3092\u6700\u5927\u306B\u3057\u305F\u3044\u306A\u3089greater<T>\n   \
    \ template<typename T, typename Comparator>\n    struct CartesianTree {\n    \
    \    public:\n            CartesianTree(const std::vector<T> &a) {\n         \
    \       build(a);\n            }\n\n            int parent(std::size_t i) const\
    \ {\n                assert(i < par.size()); \n                return par[i];\n\
    \            }\n            int operator[](std::size_t i) const {\n          \
    \      return parent(i);\n            }\n            std::vector<std::vector<int>>\
    \ graph() const {\n                return g;\n            }\n            int root()\
    \ const {\n                return _root;\n            }\n            int size()\
    \ const {\n                return (int)g.size();\n            }\n\n          \
    \  void build(const std::vector<T> &a, Comparator comp = Comparator{}) {\n   \
    \             int n = (int)a.size();\n                std::vector<T> st;\n   \
    \             st.reserve(n);\n                par.assign(n, -1);\n           \
    \     g.resize(n);\n                for(int i = 0; i < n; ++ i) {\n          \
    \          int p = -1;\n                    while(!st.empty() && comp(a[i], a[st.back()]))\
    \ {\n                        p = st.back();\n                        st.pop_back();\n\
    \                    }\n                    if(p != -1) par[p] = i;\n        \
    \            if(!st.empty()) par[i] = st.back();\n                    st.push_back(i);\n\
    \                }\n                int _root = -1;\n                for(int i\
    \ = 0; i < n; ++ i) {\n                    if(par[i] != -1) g[par[i]].push_back(i);\n\
    \                    else _root = i;\n                }\n            }\n     \
    \   private:\n            int _root;\n            std::vector<std::vector<int>>\
    \ g;\n            std::vector<int> par;\n    };\n    \n} // namespace otera\n\n\
    \n"
  code: "#ifndef OTERA_CARTESIAN_TREE_HPP\n#define OTERA_CARTESIAN_TREE_HPP 1\n\n\
    namespace otera {\n    // \u6839\u3092\u6700\u5C0F\u306B\u3057\u305F\u3044\u306A\
    \u3089less<T>, \u6839\u3092\u6700\u5927\u306B\u3057\u305F\u3044\u306A\u3089greater<T>\n\
    \    template<typename T, typename Comparator>\n    struct CartesianTree {\n \
    \       public:\n            CartesianTree(const std::vector<T> &a) {\n      \
    \          build(a);\n            }\n\n            int parent(std::size_t i) const\
    \ {\n                assert(i < par.size()); \n                return par[i];\n\
    \            }\n            int operator[](std::size_t i) const {\n          \
    \      return parent(i);\n            }\n            std::vector<std::vector<int>>\
    \ graph() const {\n                return g;\n            }\n            int root()\
    \ const {\n                return _root;\n            }\n            int size()\
    \ const {\n                return (int)g.size();\n            }\n\n          \
    \  void build(const std::vector<T> &a, Comparator comp = Comparator{}) {\n   \
    \             int n = (int)a.size();\n                std::vector<T> st;\n   \
    \             st.reserve(n);\n                par.assign(n, -1);\n           \
    \     g.resize(n);\n                for(int i = 0; i < n; ++ i) {\n          \
    \          int p = -1;\n                    while(!st.empty() && comp(a[i], a[st.back()]))\
    \ {\n                        p = st.back();\n                        st.pop_back();\n\
    \                    }\n                    if(p != -1) par[p] = i;\n        \
    \            if(!st.empty()) par[i] = st.back();\n                    st.push_back(i);\n\
    \                }\n                int _root = -1;\n                for(int i\
    \ = 0; i < n; ++ i) {\n                    if(par[i] != -1) g[par[i]].push_back(i);\n\
    \                    else _root = i;\n                }\n            }\n     \
    \   private:\n            int _root;\n            std::vector<std::vector<int>>\
    \ g;\n            std::vector<int> par;\n    };\n    \n} // namespace otera\n\n\
    #endif // OTERA_CARTESIAN_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: library/Tree/CartesianTree.hpp
  requiredBy: []
  timestamp: '2022-05-21 13:31:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Tree/CartesianTree.hpp
layout: document
redirect_from:
- /library/library/Tree/CartesianTree.hpp
- /library/library/Tree/CartesianTree.hpp.html
title: library/Tree/CartesianTree.hpp
---
