---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc235_Ex.test.cpp
    title: test/atcoder/abc235_Ex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structure/merge_history_forest.hpp\"\n\n\n\n\
    #include<atcoder/dsu>\n\nnamespace otera {\n    struct merge_history_forest {\n\
    \        merge_history_forest() : merge_history_forest(0) {}\n        merge_history_forest(int\
    \ n) : _n(n), g(2 * n - 1), uf(n), ids(2 * n - 1), root(2 * n - 1), time(2 * n\
    \ - 1) {\n            ite = n;\n            count = 1;\n            for(int i\
    \ = 0; i < n; ++ i) {\n                ids[i] = i;\n                root[i] =\
    \ true;\n            }\n        }\n \n        int node_num() const {\n       \
    \     return ite;\n        }\n        const auto& get_dsu() const {\n        \
    \    return uf;\n        }\n        const auto& get_forest() const {\n       \
    \     return g;\n        }\n        auto get_roots() const {\n            std::vector<int>\
    \ roots;\n            for(int i = 0; i < 2 * _n - 1; ++ i) {\n               \
    \ if(root[i]) {\n                    roots.emplace_back(i);\n                }\n\
    \            }\n            return roots;\n        }\n \n        void merge(int\
    \ a, int b) {\n            if(uf.same(a, b)) return;\n            int ida = ids[uf.leader(a)],\
    \ idb = ids[uf.leader(b)];\n            root[ida] = root[idb] = false;\n     \
    \       uf.merge(a, b);\n            ids[uf.leader(a)] = ite;\n            root[ite]\
    \ = true;\n            g[ite].emplace_back(ida);\n            g[ite].emplace_back(idb);\n\
    \            ++ ite;\n        }\n \n        void merge_simultaneously(std::vector<std::pair<int,\
    \ int>> edges) {\n            for(auto &[a, b]: edges) {\n                if(!uf.same(a,\
    \ b)) {\n                    int ida = ids[uf.leader(a)], idb = ids[uf.leader(b)];\n\
    \                    if(count == time[ida]) {\n                        if(count\
    \ == time[idb]) {\n                            if((int)g[ida].size() < (int)g[idb].size())\
    \ {\n                                std::swap(a, b);\n                      \
    \          std::swap(ida, idb);\n                            }\n             \
    \               for(int nv: g[idb]) {\n                                g[ida].emplace_back(nv);\n\
    \                            }\n                            root[idb] = false;\n\
    \                            uf.merge(a, b);\n                            ids[uf.leader(a)]\
    \ = ida;\n                        } else {\n                            g[ida].emplace_back(idb);\n\
    \                            root[idb] = false;\n                            uf.merge(a,\
    \ b);\n                            ids[uf.leader(a)] = ida;\n                \
    \        }\n                    } else if(count == time[idb]) {\n            \
    \            g[idb].emplace_back(ida);\n                        root[ida] = false;\n\
    \                        uf.merge(a, b);\n                        ids[uf.leader(a)]\
    \ = idb;\n                    } else {\n                        time[ite] = count;\n\
    \                        merge(a, b);\n                    }\n               \
    \ }\n            }\n            ++ count;\n        }\n \n    private:\n      \
    \  int _n;\n        mutable int ite;\n        mutable int count;\n        std::vector<std::vector<int>>\
    \ g;\n        mutable atcoder::dsu uf;\n        std::vector<int> ids;\n      \
    \  std::vector<bool> root;\n        std::vector<int> time;\n    };\n} // namespace\
    \ otera\n\n\n"
  code: "#ifndef OTERA_MERGE_HISTORY_FOREST\n#define OTERA_MERGE_HISTORY_FOREST 1\n\
    \n#include<atcoder/dsu>\n\nnamespace otera {\n    struct merge_history_forest\
    \ {\n        merge_history_forest() : merge_history_forest(0) {}\n        merge_history_forest(int\
    \ n) : _n(n), g(2 * n - 1), uf(n), ids(2 * n - 1), root(2 * n - 1), time(2 * n\
    \ - 1) {\n            ite = n;\n            count = 1;\n            for(int i\
    \ = 0; i < n; ++ i) {\n                ids[i] = i;\n                root[i] =\
    \ true;\n            }\n        }\n \n        int node_num() const {\n       \
    \     return ite;\n        }\n        const auto& get_dsu() const {\n        \
    \    return uf;\n        }\n        const auto& get_forest() const {\n       \
    \     return g;\n        }\n        auto get_roots() const {\n            std::vector<int>\
    \ roots;\n            for(int i = 0; i < 2 * _n - 1; ++ i) {\n               \
    \ if(root[i]) {\n                    roots.emplace_back(i);\n                }\n\
    \            }\n            return roots;\n        }\n \n        void merge(int\
    \ a, int b) {\n            if(uf.same(a, b)) return;\n            int ida = ids[uf.leader(a)],\
    \ idb = ids[uf.leader(b)];\n            root[ida] = root[idb] = false;\n     \
    \       uf.merge(a, b);\n            ids[uf.leader(a)] = ite;\n            root[ite]\
    \ = true;\n            g[ite].emplace_back(ida);\n            g[ite].emplace_back(idb);\n\
    \            ++ ite;\n        }\n \n        void merge_simultaneously(std::vector<std::pair<int,\
    \ int>> edges) {\n            for(auto &[a, b]: edges) {\n                if(!uf.same(a,\
    \ b)) {\n                    int ida = ids[uf.leader(a)], idb = ids[uf.leader(b)];\n\
    \                    if(count == time[ida]) {\n                        if(count\
    \ == time[idb]) {\n                            if((int)g[ida].size() < (int)g[idb].size())\
    \ {\n                                std::swap(a, b);\n                      \
    \          std::swap(ida, idb);\n                            }\n             \
    \               for(int nv: g[idb]) {\n                                g[ida].emplace_back(nv);\n\
    \                            }\n                            root[idb] = false;\n\
    \                            uf.merge(a, b);\n                            ids[uf.leader(a)]\
    \ = ida;\n                        } else {\n                            g[ida].emplace_back(idb);\n\
    \                            root[idb] = false;\n                            uf.merge(a,\
    \ b);\n                            ids[uf.leader(a)] = ida;\n                \
    \        }\n                    } else if(count == time[idb]) {\n            \
    \            g[idb].emplace_back(ida);\n                        root[ida] = false;\n\
    \                        uf.merge(a, b);\n                        ids[uf.leader(a)]\
    \ = idb;\n                    } else {\n                        time[ite] = count;\n\
    \                        merge(a, b);\n                    }\n               \
    \ }\n            }\n            ++ count;\n        }\n \n    private:\n      \
    \  int _n;\n        mutable int ite;\n        mutable int count;\n        std::vector<std::vector<int>>\
    \ g;\n        mutable atcoder::dsu uf;\n        std::vector<int> ids;\n      \
    \  std::vector<bool> root;\n        std::vector<int> time;\n    };\n} // namespace\
    \ otera\n\n#endif // OTERA_MERGE_HISTORY_FOREST"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/merge_history_forest.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc235_Ex.test.cpp
documentation_of: library/data_structure/merge_history_forest.hpp
layout: document
title: "\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u68EE"
---

- 概要

UnionFindと同様にして使うと、マージ過程を表す森を構築し、ある時点から辿り着ける頂点の集合をEuler Tour上の区間として表現できる。

なお、生成される森は、高々$2 n - 1$頂点の有向森として`std::vector<std::vector<int>>`で隣接リストとして表現される。

### マージ
- シグネチャ
```cp
void merge(int a, int b)
```

- 概要

要素$a$と$b$がまだマージされていないなら、マージしつつ、マージ過程を表す頂点を生成し、$a$と$b$に辺をはる

### 同時にマージ
- シグネチャ
```cp
void merge_simultaneously(std::vector<std::pair<int, int>> edges)
```

- 概要

`edges`に`std::pair<int, int>`として含まれるそれぞれの要素$a$と$b$がまだマージされていないなら、マージしつつ、`edges`に含まれる全てのマージ過程を表すような頂点を生成し（このマージ過程で同時にマージされたものは一頂点で表現される）、全てのマージした頂点に有向辺をはる