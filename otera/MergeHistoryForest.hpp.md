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
  bundledCode: "#line 1 \"otera/MergeHistoryForest.hpp\"\n#include<atcoder/dsu>\n\n\
    namespace otera {\n    struct MergeHistoryForest {\n        MergeHistoryForest()\
    \ : MergeHistoryForest(0) {}\n        MergeHistoryForest(int n) : _n(n), g(2 *\
    \ n - 1), uf(n), ids(2 * n - 1), root(2 * n - 1), time(2 * n - 1) {\n        \
    \    ite = n;\n            count = 1;\n            for(int i = 0; i < n; ++ i)\
    \ {\n                ids[i] = i;\n                root[i] = true;\n          \
    \  }\n        }\n \n        int node_num() const {\n            return ite;\n\
    \        }\n        const auto& get_dsu() const {\n            return uf;\n  \
    \      }\n        const auto& get_forest() const {\n            return g;\n  \
    \      }\n        auto get_roots() const {\n            std::vector<int> roots;\n\
    \            for(int i = 0; i < 2 * _n - 1; ++ i) {\n                if(root[i])\
    \ {\n                    roots.emplace_back(i);\n                }\n         \
    \   }\n            return roots;\n        }\n \n        void merge(int a, int\
    \ b) {\n            if(uf.same(a, b)) return;\n            int ida = ids[uf.leader(a)],\
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
    \ otera\n"
  code: "#include<atcoder/dsu>\n\nnamespace otera {\n    struct MergeHistoryForest\
    \ {\n        MergeHistoryForest() : MergeHistoryForest(0) {}\n        MergeHistoryForest(int\
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
    \ otera"
  dependsOn: []
  isVerificationFile: false
  path: otera/MergeHistoryForest.hpp
  requiredBy: []
  timestamp: '2022-01-31 06:00:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: otera/MergeHistoryForest.hpp
layout: document
redirect_from:
- /library/otera/MergeHistoryForest.hpp
- /library/otera/MergeHistoryForest.hpp.html
title: otera/MergeHistoryForest.hpp
---
