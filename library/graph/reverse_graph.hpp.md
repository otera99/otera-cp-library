---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: library/graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc304_h.test.cpp
    title: test/atcoder/abc304_h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/reverse_graph.hpp\"\n\n\n\n#include<library/graph/graph.hpp>\n\
    \nnamespace otera {\n    template<typename GraphType = graph<long long>>\n   \
    \ GraphType reverse_graph(const GraphType& g) {\n        assert(g.is_directed);\n\
    \        int n = (int)g.size();\n        GraphType rg(n, 1);\n        for(int\
    \ v = 0; v < n; ++ v) {\n            for(auto e: g[v]) {\n                rg.add_directed_edge(e.to,\
    \ v, e.weight, e.id);\n            }\n        }\n        return rg;\n    }\n}\
    \ // namespace otera\n\n\n"
  code: "#ifndef OTERA_REVERSE_GRAPH_HPP\n#define OTERA_REVERSE_GRAPH_HPP 1\n\n#include<library/graph/graph.hpp>\n\
    \nnamespace otera {\n    template<typename GraphType = graph<long long>>\n   \
    \ GraphType reverse_graph(const GraphType& g) {\n        assert(g.is_directed);\n\
    \        int n = (int)g.size();\n        GraphType rg(n, 1);\n        for(int\
    \ v = 0; v < n; ++ v) {\n            for(auto e: g[v]) {\n                rg.add_directed_edge(e.to,\
    \ v, e.weight, e.id);\n            }\n        }\n        return rg;\n    }\n}\
    \ // namespace otera\n\n#endif // OTERA_REVERSE_GRAPH_HPP"
  dependsOn:
  - library/graph/graph.hpp
  isVerificationFile: false
  path: library/graph/reverse_graph.hpp
  requiredBy: []
  timestamp: '2023-06-18 12:48:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc304_h.test.cpp
documentation_of: library/graph/reverse_graph.hpp
layout: document
redirect_from:
- /library/library/graph/reverse_graph.hpp
- /library/library/graph/reverse_graph.hpp.html
title: library/graph/reverse_graph.hpp
---
