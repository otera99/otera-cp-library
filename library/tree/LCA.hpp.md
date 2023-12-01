---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/lca.test.cpp
    title: test/library_checker/tree/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/LCA.hpp\"\n\n\n\nnamespace otera {\n    class\
    \ LCA {\n        public:\n            LCA(const std::vector<std::vector<int>>\
    \ &g, int root = 0) {\n                int _n = (int)g.size();\n             \
    \   int _N = 1;\n                while((1<<_N) < _n) ++ _N;\n                parent.assign(_N,\
    \ std::vector<int>(_n, -1));\n                dep.assign(_n, -1);\n          \
    \      dfs(g, root);\n                for(int i = 0; i + 1 < (int)parent.size();\
    \ ++ i) {\n                    for(int v = 0; v < _n; ++ v) {\n              \
    \          if(parent[i][v] != -1) {\n                            parent[i + 1][v]\
    \ = parent[i][parent[i][v]];\n                        }\n                    }\n\
    \                }\n            }\n            \n            int lca(int u, int\
    \ v) const {\n                if(dep[u] > dep[v]) std::swap(u, v);\n         \
    \       for(int i = 0; i < (int)parent.size(); ++ i) {\n                    if((dep[u]\
    \ - dep[v]) & (1<<i)) {\n                        v = parent[i][v];\n         \
    \           }\n                }\n                if(u == v) return u;\n     \
    \           for(int i = (int)parent.size() - 1; i >= 0; -- i) {\n            \
    \        if(parent[i][u] != parent[i][v]) {\n                        u = parent[i][u];\n\
    \                        v = parent[i][v];\n                    }\n          \
    \      }\n                return parent[0][u];\n            }\n            int\
    \ depth(int u) const { return dep[u]; }\n            int dist(int u, int v) const\
    \ { return dep[u] + dep[v] - 2 * dep[operator()(u, v)]; }\n            int operator()(int\
    \ u, int v) const { return lca(u, v); }\n        private:\n            std::vector<int>\
    \ dep;\n            std::vector<std::vector<int>> parent;\n\n            void\
    \ dfs(const std::vector<std::vector<int>> &g, int root) {\n                auto\
    \ rec = [&](auto &&self, int v, int p, int d) -> void {\n                    dep[v]\
    \ = d;\n                    parent[0][v] = p;\n                    for(int nv:\
    \ g[v]) {\n                        if(nv == p) continue;\n                   \
    \     self(self, nv, v, d + 1);\n                    }\n                };\n \
    \               rec(rec, root, -1, 0);\n            }\n    };\n} // namespace\
    \ otera\n\n\n"
  code: "#ifndef OTERA_LCA_HPP\n#define OTERA_LCA_HPP 1\n\nnamespace otera {\n   \
    \ class LCA {\n        public:\n            LCA(const std::vector<std::vector<int>>\
    \ &g, int root = 0) {\n                int _n = (int)g.size();\n             \
    \   int _N = 1;\n                while((1<<_N) < _n) ++ _N;\n                parent.assign(_N,\
    \ std::vector<int>(_n, -1));\n                dep.assign(_n, -1);\n          \
    \      dfs(g, root);\n                for(int i = 0; i + 1 < (int)parent.size();\
    \ ++ i) {\n                    for(int v = 0; v < _n; ++ v) {\n              \
    \          if(parent[i][v] != -1) {\n                            parent[i + 1][v]\
    \ = parent[i][parent[i][v]];\n                        }\n                    }\n\
    \                }\n            }\n            \n            int lca(int u, int\
    \ v) const {\n                if(dep[u] > dep[v]) std::swap(u, v);\n         \
    \       for(int i = 0; i < (int)parent.size(); ++ i) {\n                    if((dep[u]\
    \ - dep[v]) & (1<<i)) {\n                        v = parent[i][v];\n         \
    \           }\n                }\n                if(u == v) return u;\n     \
    \           for(int i = (int)parent.size() - 1; i >= 0; -- i) {\n            \
    \        if(parent[i][u] != parent[i][v]) {\n                        u = parent[i][u];\n\
    \                        v = parent[i][v];\n                    }\n          \
    \      }\n                return parent[0][u];\n            }\n            int\
    \ depth(int u) const { return dep[u]; }\n            int dist(int u, int v) const\
    \ { return dep[u] + dep[v] - 2 * dep[operator()(u, v)]; }\n            int operator()(int\
    \ u, int v) const { return lca(u, v); }\n        private:\n            std::vector<int>\
    \ dep;\n            std::vector<std::vector<int>> parent;\n\n            void\
    \ dfs(const std::vector<std::vector<int>> &g, int root) {\n                auto\
    \ rec = [&](auto &&self, int v, int p, int d) -> void {\n                    dep[v]\
    \ = d;\n                    parent[0][v] = p;\n                    for(int nv:\
    \ g[v]) {\n                        if(nv == p) continue;\n                   \
    \     self(self, nv, v, d + 1);\n                    }\n                };\n \
    \               rec(rec, root, -1, 0);\n            }\n    };\n} // namespace\
    \ otera\n\n#endif // OTERA_LCA_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/LCA.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:42:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/lca.test.cpp
documentation_of: library/tree/LCA.hpp
layout: document
redirect_from:
- /library/library/tree/LCA.hpp
- /library/library/tree/LCA.hpp.html
title: library/tree/LCA.hpp
---