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
  bundledCode: "#line 1 \"library/graph/graph.hpp\"\n\n\n\nnamespace otera {\n   \
    \ template<typename T>\n    struct edge {\n        int to;\n        T cost;\n\
    \        int id;\n\n        edge(int to, T cost, int id) : to(to), cost(cost),\
    \ id(id) {}\n    };\n\n    template<typename T = int>\n    struct graph : std::vector<std::vector<edge<T>>>\
    \ {\n        int _n, _m;\n        bool is_directed;\n        using cost_type =\
    \ T;\n        using edge_type = edge<T>;\n\n        graph() : _n(0), _m(0), is_directed(false)\
    \ {}\n        graph(int n, bool is_directed = false) : _n(n), _m(0), is_directed(is_directed)\
    \ {\n            (*this).assign(n, std::vector<edge<T>>());\n        }\n\n   \
    \     void add_edge(int frm, int to, T cost = 1, int id = -1) {\n            assert(0\
    \ <= frm and frm < _n and 0 <= to and to < _n);\n            if(id == -1) id =\
    \ _m;\n            (*this)[frm].emplace_back(to, cost, id);\n            (*this)[to].emplace_back(frm,\
    \ cost, id);\n            ++ _m;\n        }\n\n        void add_directed_edge(int\
    \ frm, int to, T cost = 1, int id = -1) {\n            assert(0 <= frm and frm\
    \ < _n and 0 <= to and to < _n);\n            if(id == -1) id = _m;\n        \
    \    (*this)[frm].emplace_back(to, cost, id);\n            ++ _m;\n        }\n\
    \n        void read_tree(bool wt = false, int off = 1) {\n            read_graph(_n\
    \ - 1, wt, off);\n        }\n\n        void read_graph(int m, bool wt = false,\
    \ int off = 1) {\n            assert(!is_directed);\n            for(int i = 0;\
    \ i < m; ++ i) {\n                int a, b; std::cin >> a >> b;\n            \
    \    a -= off, b -= off;\n                assert(0 <= a and a < _n and 0 <= b\
    \ and b < _n);\n                if(!wt) {\n                    add_edge(a, b);\n\
    \                } else {\n                    T c; std::cin >> c;\n         \
    \           add_edge(a, b, c);\n                }\n            }\n        }\n\n\
    \        void read_directed_graph(int m, bool wt = false, int off = 1) {\n   \
    \         assert(is_directed);\n            for(int i = 0; i < m; ++ i) {\n  \
    \              int a, b; std::cin >> a >> b;\n                a -= off, b -= off;\n\
    \                assert(0 <= a and a < _n and 0 <= b and b < _n);\n          \
    \      if(!wt) {\n                    add_directed_edge(a, b);\n             \
    \   } else {\n                    T c; std::cin >> c;\n                    add_directed_edge(a,\
    \ b, c);\n                }\n            }\n        }\n\n        void read_parent(int\
    \ off = 1) {\n            for(int v = 1; v < _n; ++ v) {\n                int\
    \ p; std::cin >> p;\n                p -= off;\n                add_edge(p, v);\n\
    \            }\n        }\n\n        int deg(int v) {\n            return (int)size((*this)[v]);\n\
    \        }\n    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_GRAPH_BASE_HPP\n#define OTERA_GRAPH_BASE_HPP 1\n\nnamespace\
    \ otera {\n    template<typename T>\n    struct edge {\n        int to;\n    \
    \    T cost;\n        int id;\n\n        edge(int to, T cost, int id) : to(to),\
    \ cost(cost), id(id) {}\n    };\n\n    template<typename T = int>\n    struct\
    \ graph : std::vector<std::vector<edge<T>>> {\n        int _n, _m;\n        bool\
    \ is_directed;\n        using cost_type = T;\n        using edge_type = edge<T>;\n\
    \n        graph() : _n(0), _m(0), is_directed(false) {}\n        graph(int n,\
    \ bool is_directed = false) : _n(n), _m(0), is_directed(is_directed) {\n     \
    \       (*this).assign(n, std::vector<edge<T>>());\n        }\n\n        void\
    \ add_edge(int frm, int to, T cost = 1, int id = -1) {\n            assert(0 <=\
    \ frm and frm < _n and 0 <= to and to < _n);\n            if(id == -1) id = _m;\n\
    \            (*this)[frm].emplace_back(to, cost, id);\n            (*this)[to].emplace_back(frm,\
    \ cost, id);\n            ++ _m;\n        }\n\n        void add_directed_edge(int\
    \ frm, int to, T cost = 1, int id = -1) {\n            assert(0 <= frm and frm\
    \ < _n and 0 <= to and to < _n);\n            if(id == -1) id = _m;\n        \
    \    (*this)[frm].emplace_back(to, cost, id);\n            ++ _m;\n        }\n\
    \n        void read_tree(bool wt = false, int off = 1) {\n            read_graph(_n\
    \ - 1, wt, off);\n        }\n\n        void read_graph(int m, bool wt = false,\
    \ int off = 1) {\n            assert(!is_directed);\n            for(int i = 0;\
    \ i < m; ++ i) {\n                int a, b; std::cin >> a >> b;\n            \
    \    a -= off, b -= off;\n                assert(0 <= a and a < _n and 0 <= b\
    \ and b < _n);\n                if(!wt) {\n                    add_edge(a, b);\n\
    \                } else {\n                    T c; std::cin >> c;\n         \
    \           add_edge(a, b, c);\n                }\n            }\n        }\n\n\
    \        void read_directed_graph(int m, bool wt = false, int off = 1) {\n   \
    \         assert(is_directed);\n            for(int i = 0; i < m; ++ i) {\n  \
    \              int a, b; std::cin >> a >> b;\n                a -= off, b -= off;\n\
    \                assert(0 <= a and a < _n and 0 <= b and b < _n);\n          \
    \      if(!wt) {\n                    add_directed_edge(a, b);\n             \
    \   } else {\n                    T c; std::cin >> c;\n                    add_directed_edge(a,\
    \ b, c);\n                }\n            }\n        }\n\n        void read_parent(int\
    \ off = 1) {\n            for(int v = 1; v < _n; ++ v) {\n                int\
    \ p; std::cin >> p;\n                p -= off;\n                add_edge(p, v);\n\
    \            }\n        }\n\n        int deg(int v) {\n            return (int)size((*this)[v]);\n\
    \        }\n    };\n} // namespace otera\n\n#endif // OTERA_GRAPH_BASE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/graph.hpp
  requiredBy: []
  timestamp: '2022-11-17 09:49:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/graph.hpp
layout: document
redirect_from:
- /library/library/graph/graph.hpp
- /library/library/graph/graph.hpp.html
title: library/graph/graph.hpp
---
