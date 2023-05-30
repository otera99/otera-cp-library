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
  bundledCode: "#line 1 \"library/graph/heavy_light_decomposition.hpp\"\n\n\n\nnamespace\
    \ otera {\n    template<typename GraphType>\n    struct tree : GraphType {\n \
    \       public:\n\n        int la(int v, int k) {\n\n        }\n\n        int\
    \ lca(int u, int v) {\n\n        }\n\n        int jump(int a, int b, long long\
    \ k) {\n            \n        }\n        \n        private:\n        std::vector<int>\
    \ sz, order, head;\n        std::vector<int> parent;\n\n        auto dfs_sz =\
    \ [&](auto&&dfs_sz, int v, int p) -> void {\n            sz[v] = 1;\n        \
    \    for(auto e: g[v]) {\n                int nv = e.to;\n                if(nv\
    \ == p) continue;\n                dfs_sz(dfs_sz, nv, v);\n                sz[v]\
    \ += sz[nv];\n                if(sz[nv] > sz[g[v][0].to]) {\n                \
    \    swap(e, g[v][0]);\n                }\n            }\n        };\n       \
    \ auto dfs_hld = [&](auto&&dfs_hld, int v, int p, int &times) -> void {\n    \
    \        order[v] = times ++;\n            for(auto e: g[v]) {\n             \
    \   int nv = e.to;\n                if(nv == p) continue;\n                head[nv]\
    \ = (g[v][0].to == nv ? head[v] : nv);\n                dfs_hld(dfs_hld, nv, v,\
    \ times);\n            }\n        };\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_HEAVY_LIGHT_DECOMPOSITION_HPP\n#define OTERA_HEAVY_LIGHT_DECOMPOSITION_HPP\
    \ 1\n\nnamespace otera {\n    template<typename GraphType>\n    struct tree :\
    \ GraphType {\n        public:\n\n        int la(int v, int k) {\n\n        }\n\
    \n        int lca(int u, int v) {\n\n        }\n\n        int jump(int a, int\
    \ b, long long k) {\n            \n        }\n        \n        private:\n   \
    \     std::vector<int> sz, order, head;\n        std::vector<int> parent;\n\n\
    \        auto dfs_sz = [&](auto&&dfs_sz, int v, int p) -> void {\n           \
    \ sz[v] = 1;\n            for(auto e: g[v]) {\n                int nv = e.to;\n\
    \                if(nv == p) continue;\n                dfs_sz(dfs_sz, nv, v);\n\
    \                sz[v] += sz[nv];\n                if(sz[nv] > sz[g[v][0].to])\
    \ {\n                    swap(e, g[v][0]);\n                }\n            }\n\
    \        };\n        auto dfs_hld = [&](auto&&dfs_hld, int v, int p, int &times)\
    \ -> void {\n            order[v] = times ++;\n            for(auto e: g[v]) {\n\
    \                int nv = e.to;\n                if(nv == p) continue;\n     \
    \           head[nv] = (g[v][0].to == nv ? head[v] : nv);\n                dfs_hld(dfs_hld,\
    \ nv, v, times);\n            }\n        };\n    };\n} // namespace otera\n\n\
    #endif // OTERA_HEAVY_LIGHT_DECOMPOSITION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2023-05-31 05:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/library/graph/heavy_light_decomposition.hpp
- /library/library/graph/heavy_light_decomposition.hpp.html
title: library/graph/heavy_light_decomposition.hpp
---
