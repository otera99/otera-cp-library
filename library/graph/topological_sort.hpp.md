---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/typical90_bs.test.cpp
    title: test/atcoder/typical90_bs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/topological_sort.hpp\"\n\n\n\nnamespace otera\
    \ {\n    template<typename GraphType>\n    class topological_sort {\n        public:\n\
    \        topological_sort(const GraphType& g) {\n            build(g);\n     \
    \   }\n        bool is_dag() const { return (int)_ord.size() == _n; }\n      \
    \  const std::vector<int>& sorted() const { return _ord; }\n        int operator[](int\
    \ i) const { return _ord[i]; }\n        private:\n        int _n;\n        std::vector<int>\
    \ _ord;\n        void build(const GraphType& g) {\n            _n = g.size();\n\
    \            std::vector<int> in_deg(_n);\n            std::queue<int> que;\n\
    \            for(int v = 0; v < _n; ++ v) {\n                for(auto e: g[v])\
    \ {\n                    int nv = e.to;\n                    ++ in_deg[nv];\n\
    \                }\n            }\n            for(int v = 0; v < _n; ++ v) {\n\
    \                if(in_deg[v] == 0) que.push(v);\n            }\n            _ord.reserve(_n);\n\
    \            while(que.size()) {\n                int v = que.front(); que.pop();\n\
    \                _ord.push_back(v);\n                for(auto e: g[v]) {\n   \
    \                 int nv = e.to;\n                    if(-- in_deg[nv] == 0) que.push(nv);\n\
    \                }\n            }\n        }\n    };\n} // namespace otera\n\n\
    \n"
  code: "#ifndef OTERA_TOPOLOGICAL_SORT_HPP\n#define OTERA_TOPOLOGICAL_SORT_HPP 1\n\
    \nnamespace otera {\n    template<typename GraphType>\n    class topological_sort\
    \ {\n        public:\n        topological_sort(const GraphType& g) {\n       \
    \     build(g);\n        }\n        bool is_dag() const { return (int)_ord.size()\
    \ == _n; }\n        const std::vector<int>& sorted() const { return _ord; }\n\
    \        int operator[](int i) const { return _ord[i]; }\n        private:\n \
    \       int _n;\n        std::vector<int> _ord;\n        void build(const GraphType&\
    \ g) {\n            _n = g.size();\n            std::vector<int> in_deg(_n);\n\
    \            std::queue<int> que;\n            for(int v = 0; v < _n; ++ v) {\n\
    \                for(auto e: g[v]) {\n                    int nv = e.to;\n   \
    \                 ++ in_deg[nv];\n                }\n            }\n         \
    \   for(int v = 0; v < _n; ++ v) {\n                if(in_deg[v] == 0) que.push(v);\n\
    \            }\n            _ord.reserve(_n);\n            while(que.size()) {\n\
    \                int v = que.front(); que.pop();\n                _ord.push_back(v);\n\
    \                for(auto e: g[v]) {\n                    int nv = e.to;\n   \
    \                 if(-- in_deg[nv] == 0) que.push(nv);\n                }\n  \
    \          }\n        }\n    };\n} // namespace otera\n\n#endif // OTERA_TOPOLOGICAL_SORT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2022-11-23 16:33:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/typical90_bs.test.cpp
documentation_of: library/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/library/graph/topological_sort.hpp
- /library/library/graph/topological_sort.hpp.html
title: library/graph/topological_sort.hpp
---
