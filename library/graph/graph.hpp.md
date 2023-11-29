---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/graph/reverse_graph.hpp
    title: library/graph/reverse_graph.hpp
  - icon: ':x:'
    path: library/graph/topological_sort.hpp
    title: library/graph/topological_sort.hpp
  - icon: ':warning:'
    path: library/tree/centroid.hpp
    title: library/tree/centroid.hpp
  - icon: ':warning:'
    path: library/tree/dfs_order.hpp
    title: library/tree/dfs_order.hpp
  - icon: ':warning:'
    path: test/atcoder/arc161_c.cpp
    title: test/atcoder/arc161_c.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc277_g.test.cpp
    title: test/atcoder/abc277_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc304_h.test.cpp
    title: test/atcoder/abc304_h.test.cpp
  - icon: ':x:'
    path: test/atcoder/typical90_bs.test.cpp
    title: test/atcoder/typical90_bs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graph/graph.hpp\"\n\n\n\nnamespace otera {\n   \
    \ template<typename T = long long>\n    struct edge {\n        int to;\n     \
    \   T weight;\n        int id;\n        edge(int to, T weight, int id) : to(to),\
    \ weight(weight), id(id) {}\n        operator int() const { return to; }\n   \
    \ };\n\n    template<typename T = long long>\n    struct graph : std::vector<std::vector<edge<T>>>\
    \ {\n        int _n, _m;\n        bool is_directed;\n        using weight_type\
    \ = T;\n        using edge_type = edge<T>;\n\n        graph() : _n(0), _m(0),\
    \ is_directed(false) {}\n        graph(int n, bool is_directed = false) : _n(n),\
    \ _m(0), is_directed(is_directed) {\n            (*this).assign(n, std::vector<edge<T>>());\n\
    \        }\n\n        void add_edge(int frm, int to, T weight = 1, int id = -1)\
    \ {\n            assert(0 <= frm and frm < _n and 0 <= to and to < _n);\n    \
    \        if(id == -1) id = _m;\n            (*this)[frm].emplace_back(to, weight,\
    \ id);\n            (*this)[to].emplace_back(frm, weight, id);\n            ++\
    \ _m;\n        }\n\n        void add_directed_edge(int frm, int to, T weight =\
    \ 1, int id = -1) {\n            assert(0 <= frm and frm < _n and 0 <= to and\
    \ to < _n);\n            assert(is_directed);\n            if(id == -1) id = _m;\n\
    \            (*this)[frm].emplace_back(to, weight, id);\n            ++ _m;\n\
    \        }\n\n        void read_tree(bool wt = false, int off = 1) {\n       \
    \     read_graph(_n - 1, wt, off);\n        }\n\n        void read_graph(int m,\
    \ bool wt = false, int off = 1) {\n            assert(!is_directed);\n       \
    \     for(int i = 0; i < m; ++ i) {\n                int a, b; std::cin >> a >>\
    \ b;\n                a -= off, b -= off;\n                assert(0 <= a and a\
    \ < _n and 0 <= b and b < _n);\n                if(!wt) {\n                  \
    \  add_edge(a, b);\n                } else {\n                    T c; std::cin\
    \ >> c;\n                    add_edge(a, b, c);\n                }\n         \
    \   }\n        }\n\n        void read_directed_graph(int m, bool wt = false, int\
    \ off = 1) {\n            assert(is_directed);\n            for(int i = 0; i <\
    \ m; ++ i) {\n                int a, b; std::cin >> a >> b;\n                a\
    \ -= off, b -= off;\n                assert(0 <= a and a < _n and 0 <= b and b\
    \ < _n);\n                if(!wt) {\n                    add_directed_edge(a,\
    \ b);\n                } else {\n                    T c; std::cin >> c;\n   \
    \                 add_directed_edge(a, b, c);\n                }\n           \
    \ }\n        }\n\n        void read_parent(int off = 1) {\n            for(int\
    \ v = 1; v < _n; ++ v) {\n                int p; std::cin >> p;\n            \
    \    p -= off;\n                add_edge(p, v);\n            }\n        }\n\n\
    \        int deg(int v) {\n            return (int)size((*this)[v]);\n       \
    \ }\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_GRAPH_HPP\n#define OTERA_GRAPH_HPP 1\n\nnamespace otera {\n\
    \    template<typename T = long long>\n    struct edge {\n        int to;\n  \
    \      T weight;\n        int id;\n        edge(int to, T weight, int id) : to(to),\
    \ weight(weight), id(id) {}\n        operator int() const { return to; }\n   \
    \ };\n\n    template<typename T = long long>\n    struct graph : std::vector<std::vector<edge<T>>>\
    \ {\n        int _n, _m;\n        bool is_directed;\n        using weight_type\
    \ = T;\n        using edge_type = edge<T>;\n\n        graph() : _n(0), _m(0),\
    \ is_directed(false) {}\n        graph(int n, bool is_directed = false) : _n(n),\
    \ _m(0), is_directed(is_directed) {\n            (*this).assign(n, std::vector<edge<T>>());\n\
    \        }\n\n        void add_edge(int frm, int to, T weight = 1, int id = -1)\
    \ {\n            assert(0 <= frm and frm < _n and 0 <= to and to < _n);\n    \
    \        if(id == -1) id = _m;\n            (*this)[frm].emplace_back(to, weight,\
    \ id);\n            (*this)[to].emplace_back(frm, weight, id);\n            ++\
    \ _m;\n        }\n\n        void add_directed_edge(int frm, int to, T weight =\
    \ 1, int id = -1) {\n            assert(0 <= frm and frm < _n and 0 <= to and\
    \ to < _n);\n            assert(is_directed);\n            if(id == -1) id = _m;\n\
    \            (*this)[frm].emplace_back(to, weight, id);\n            ++ _m;\n\
    \        }\n\n        void read_tree(bool wt = false, int off = 1) {\n       \
    \     read_graph(_n - 1, wt, off);\n        }\n\n        void read_graph(int m,\
    \ bool wt = false, int off = 1) {\n            assert(!is_directed);\n       \
    \     for(int i = 0; i < m; ++ i) {\n                int a, b; std::cin >> a >>\
    \ b;\n                a -= off, b -= off;\n                assert(0 <= a and a\
    \ < _n and 0 <= b and b < _n);\n                if(!wt) {\n                  \
    \  add_edge(a, b);\n                } else {\n                    T c; std::cin\
    \ >> c;\n                    add_edge(a, b, c);\n                }\n         \
    \   }\n        }\n\n        void read_directed_graph(int m, bool wt = false, int\
    \ off = 1) {\n            assert(is_directed);\n            for(int i = 0; i <\
    \ m; ++ i) {\n                int a, b; std::cin >> a >> b;\n                a\
    \ -= off, b -= off;\n                assert(0 <= a and a < _n and 0 <= b and b\
    \ < _n);\n                if(!wt) {\n                    add_directed_edge(a,\
    \ b);\n                } else {\n                    T c; std::cin >> c;\n   \
    \                 add_directed_edge(a, b, c);\n                }\n           \
    \ }\n        }\n\n        void read_parent(int off = 1) {\n            for(int\
    \ v = 1; v < _n; ++ v) {\n                int p; std::cin >> p;\n            \
    \    p -= off;\n                add_edge(p, v);\n            }\n        }\n\n\
    \        int deg(int v) {\n            return (int)size((*this)[v]);\n       \
    \ }\n    };\n} // namespace otera\n\n#endif // OTERA_GRAPH_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/graph.hpp
  requiredBy:
  - library/tree/centroid.hpp
  - library/tree/dfs_order.hpp
  - library/graph/reverse_graph.hpp
  - library/graph/topological_sort.hpp
  - test/atcoder/arc161_c.cpp
  timestamp: '2023-06-18 12:48:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/typical90_bs.test.cpp
  - test/atcoder/abc304_h.test.cpp
  - test/atcoder/abc277_g.test.cpp
documentation_of: library/graph/graph.hpp
layout: document
redirect_from:
- /library/library/graph/graph.hpp
- /library/library/graph/graph.hpp.html
title: library/graph/graph.hpp
---
