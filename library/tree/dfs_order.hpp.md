---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: library/graph/graph.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/arc161_c.cpp
    title: test/atcoder/arc161_c.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/dfs_order.hpp\"\n\n\n\n#include<library/graph/graph.hpp>\n\
    \nnamespace otera {\n    template<typename GraphType = graph<long long>>\n   \
    \ struct dfs_order {\n        int _n;\n        int root = -1;\n        std::vector<int>\
    \ _order, _depth, _parent;\n\n        dfs_order(const GraphType& g, int r = 0)\
    \ : _n((int)g.size()), root(r) {\n            build(g);\n        }\n\n       \
    \ int operator[](int i) const { return _order[i]; }\n        int depth(int v)\
    \ const { return _depth[v]; }\n        int parent(int v) const { return _parent[v];\
    \ }\n\n        private:\n        void dfs(const GraphType& g, int v, int pre =\
    \ -1) {\n            _parent[v] = pre;\n            for(int nv: g[v]) {\n    \
    \            if(nv == pre) continue;\n                _depth[nv] = _depth[v] +\
    \ 1;\n                dfs(g, nv, v);\n            }\n            _order.push_back(v);\n\
    \        }\n        void build(const GraphType& g) {\n            _order.reserve(_n);\n\
    \            _depth.assign(_n, 0);\n            _parent.assign(_n, -1);\n    \
    \        dfs(g, root);\n        }\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_DFS_ORDER_HPP\n#define OTERA_DFS_ORDER_HPP 1\n\n#include<library/graph/graph.hpp>\n\
    \nnamespace otera {\n    template<typename GraphType = graph<long long>>\n   \
    \ struct dfs_order {\n        int _n;\n        int root = -1;\n        std::vector<int>\
    \ _order, _depth, _parent;\n\n        dfs_order(const GraphType& g, int r = 0)\
    \ : _n((int)g.size()), root(r) {\n            build(g);\n        }\n\n       \
    \ int operator[](int i) const { return _order[i]; }\n        int depth(int v)\
    \ const { return _depth[v]; }\n        int parent(int v) const { return _parent[v];\
    \ }\n\n        private:\n        void dfs(const GraphType& g, int v, int pre =\
    \ -1) {\n            _parent[v] = pre;\n            for(int nv: g[v]) {\n    \
    \            if(nv == pre) continue;\n                _depth[nv] = _depth[v] +\
    \ 1;\n                dfs(g, nv, v);\n            }\n            _order.push_back(v);\n\
    \        }\n        void build(const GraphType& g) {\n            _order.reserve(_n);\n\
    \            _depth.assign(_n, 0);\n            _parent.assign(_n, -1);\n    \
    \        dfs(g, root);\n        }\n    };\n} // namespace otera\n\n#endif // OTERA_DFS_ORDER_HPP"
  dependsOn:
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/tree/dfs_order.hpp
  requiredBy:
  - test/atcoder/arc161_c.cpp
  timestamp: '2023-06-18 12:48:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/dfs_order.hpp
layout: document
redirect_from:
- /library/library/tree/dfs_order.hpp
- /library/library/tree/dfs_order.hpp.html
title: library/tree/dfs_order.hpp
---
