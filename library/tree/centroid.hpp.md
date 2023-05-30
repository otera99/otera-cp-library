---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: library/graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/centroid.hpp\"\n\n\n\n#include<library/graph/graph.hpp>\n\
    \nnamespace otera {\n    std::vector<int> centroid(const graph& g) {\n       \
    \ std::vector<int> ret;\n        std::vector<int> sz;\n        auto dfs = [&](auto&&dfs,\
    \ int v, int p) -> void {\n            sz[v] = 1;\n            bool flag = 1;\n\
    \            for(auto e: g[v]) {\n                int nv = e.to;\n           \
    \     if(nv == p) continue;\n                dfs(dfs, nv, v);\n              \
    \  if(sz[nv] > n / 2) flag = 0;\n                sz[v] += sz[nv];\n          \
    \  }\n            if(n - sz[v] > n / 2) flag = 0;\n            if(flag) {\n  \
    \              ret.emplace_back(v);\n            }\n        };\n        dfs(dfs,\
    \ 0, -1);\n        return ret;\n    }\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_CENTROID_HPP\n#define OTERA_CENTROID_HPP 1\n\n#include<library/graph/graph.hpp>\n\
    \nnamespace otera {\n    std::vector<int> centroid(const graph& g) {\n       \
    \ std::vector<int> ret;\n        std::vector<int> sz;\n        auto dfs = [&](auto&&dfs,\
    \ int v, int p) -> void {\n            sz[v] = 1;\n            bool flag = 1;\n\
    \            for(auto e: g[v]) {\n                int nv = e.to;\n           \
    \     if(nv == p) continue;\n                dfs(dfs, nv, v);\n              \
    \  if(sz[nv] > n / 2) flag = 0;\n                sz[v] += sz[nv];\n          \
    \  }\n            if(n - sz[v] > n / 2) flag = 0;\n            if(flag) {\n  \
    \              ret.emplace_back(v);\n            }\n        };\n        dfs(dfs,\
    \ 0, -1);\n        return ret;\n    }\n} // namespace otera\n\n#endif // OTERA_CENTROID_HPP\n"
  dependsOn:
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/tree/centroid.hpp
  requiredBy: []
  timestamp: '2023-05-31 05:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/centroid.hpp
layout: document
redirect_from:
- /library/library/tree/centroid.hpp
- /library/library/tree/centroid.hpp.html
title: library/tree/centroid.hpp
---
