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
  bundledCode: "#line 1 \"library/Graph/base.hpp\"\n\n\n\nnamespace otera {\n    template<typename\
    \ T>\n    struct Edge {\n        int frm, to;\n        T cost;\n        int id;\n\
    \    };\n\n    template<typename T = int, bool directed = false>\n    struct Graph\
    \ {\n        using cost_type = T;\n        using edge_type = Edge<T>\n\n     \
    \   int _n, _m;\n\n        void read_tree(int offset) {\n            read_graph(_n\
    \ - 1, offset);\n        }\n\n        void read_graph(int m, int offset) {\n \
    \           for(int i = 0; i < m; ++ i) {\n                int a, b; std::cin\
    \ >> a >> b;\n                a -= offset, b -= offset;\n            }\n     \
    \       build();\n        }\n\n        void build() {\n\n        }\n    };\n}\
    \ // namespace otera\n\n\n"
  code: "#ifndef OTERA_GRAPH_BASE_HPP\n#define OTERA_GRAPH_BASE_HPP 1\n\nnamespace\
    \ otera {\n    template<typename T>\n    struct Edge {\n        int frm, to;\n\
    \        T cost;\n        int id;\n    };\n\n    template<typename T = int, bool\
    \ directed = false>\n    struct Graph {\n        using cost_type = T;\n      \
    \  using edge_type = Edge<T>\n\n        int _n, _m;\n\n        void read_tree(int\
    \ offset) {\n            read_graph(_n - 1, offset);\n        }\n\n        void\
    \ read_graph(int m, int offset) {\n            for(int i = 0; i < m; ++ i) {\n\
    \                int a, b; std::cin >> a >> b;\n                a -= offset, b\
    \ -= offset;\n            }\n            build();\n        }\n\n        void build()\
    \ {\n\n        }\n    };\n} // namespace otera\n\n#endif // OTERA_GRAPH_BASE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/Graph/base.hpp
  requiredBy: []
  timestamp: '2022-10-01 04:27:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/Graph/base.hpp
layout: document
redirect_from:
- /library/library/Graph/base.hpp
- /library/library/Graph/base.hpp.html
title: library/Graph/base.hpp
---
