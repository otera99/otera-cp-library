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
  bundledCode: "#line 1 \"library/DataStructure/Healthy2DSegtree.hpp\"\n\n\n\n#include<atcoder/segtree>\n\
    \nnamespace otera {\n    template <class S, S (*op)(S, S), S (*e)()> struct health_2d_segtree\
    \ {\n    public:\n        health_2d_segtree() : health_2d_segtree(0) {}\n    \
    \    explicit health_2d_segtree(const std::vector<std::vector<long long>>& v)\
    \ : _n((int)v.size()) {\n            log = atcoder::internal::ceil_pow2(_n);\n\
    \            size = 1 << log;\n            index.resize(2 * size);\n         \
    \   for(int i = 0; i < _n; ++ i) {\n                for(int id: v[i]) {\n    \
    \                index[size + i].push_back(id);\n                }\n         \
    \   }\n            for(int i = 2 * size - 1; i >= 1; -- i) {\n               \
    \ std::sort(index[i].begin(), index[i].end());\n                index[i].erase(std::unique(index[i].begin(),\
    \ index[i].end()), index[i].end());\n                for(int id: index[i]) {\n\
    \                    index[i >> 1].push_back(id);\n                }\n       \
    \     }\n            seg.resize(2 * size);\n            for(int i = 1; i < 2 *\
    \ size; ++ i) {\n                seg[i] = atcoder::segtree<S, op, e>(index[i].size());\n\
    \            }\n        }\n\n        void set(int x, int y, S val) {\n       \
    \     assert(x < size);\n            x += size;\n            int posy = std::lower_bound(index[x].begin(),\
    \ index[x].end(), y) - index[x].begin();\n            assert(posy < index[x].size());\n\
    \            assert(y == index[x][posy]);\n            seg[x].set(posy, val);\n\
    \            for(int i = 1; i <= log; ++ i) {\n                x >>= 1;\n    \
    \            posy = std::lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();\n\
    \                assert(posy < (int)index[x].size());\n                assert(y\
    \ == index[x][posy]);\n                S nval = op(seg[x].get(posy), val);\n \
    \               seg[x].set(posy, nval);\n            }\n        }\n\n        S\
    \ get(int x, int y) const {\n            assert(x < size);\n            x += size;\n\
    \            int posy = std::lower_bound(index[x].begin(), index[x].end(), y)\
    \ - index[x].begin();\n            assert(posy < (int)index[x].size());\n    \
    \        assert(y == index[x][posy]);\n            return seg[x].get(posy);\n\
    \        }\n\n        S prod(int sx, int tx, int sy, int ty) const {\n       \
    \     return prod(sx, tx, sy, ty, 1, 0, size);\n        }\n\n        S all_prod()\
    \ const { return seg[1].all_prod(); }\n\n    private:\n        int _n, size, log;\n\
    \        std::vector<atcoder::segtree<S, op, e>> seg;\n        std::vector<std::vector<int>>\
    \ index;\n\n        S prod(int sx, int tx, int sy, int ty, int k, int l, int r)\
    \ const {\n            assert(k < 2 * size);\n            assert(l < r);\n   \
    \         if(r <= sx or tx <= l) return e();\n            if(sx <= l and r <=\
    \ tx) {\n                int pos_sy = std::lower_bound(index[k].begin(), index[k].end(),\
    \ sy) - index[k].begin();\n                int pos_ty = std::lower_bound(index[k].begin(),\
    \ index[k].end(), ty) - index[k].begin();\n                return seg[k].prod(pos_sy,\
    \ pos_ty);\n            }\n            int mid = (l + r) / 2;\n            S le\
    \ = prod(sx, tx, sy, ty, k * 2, l, mid);\n            S ri = prod(sx, tx, sy,\
    \ ty, k * 2 + 1, mid, r);\n            return op(le, ri);\n        }\n    };\n\
    } // namespace otera\n\n\n"
  code: "#ifndef OTERA_HEALTHY_2D_SEGTREE_HPP \n#define OTERA_HEALTHY_2D_SEGTREE_HPP\
    \ 1\n\n#include<atcoder/segtree>\n\nnamespace otera {\n    template <class S,\
    \ S (*op)(S, S), S (*e)()> struct health_2d_segtree {\n    public:\n        health_2d_segtree()\
    \ : health_2d_segtree(0) {}\n        explicit health_2d_segtree(const std::vector<std::vector<long\
    \ long>>& v) : _n((int)v.size()) {\n            log = atcoder::internal::ceil_pow2(_n);\n\
    \            size = 1 << log;\n            index.resize(2 * size);\n         \
    \   for(int i = 0; i < _n; ++ i) {\n                for(int id: v[i]) {\n    \
    \                index[size + i].push_back(id);\n                }\n         \
    \   }\n            for(int i = 2 * size - 1; i >= 1; -- i) {\n               \
    \ std::sort(index[i].begin(), index[i].end());\n                index[i].erase(std::unique(index[i].begin(),\
    \ index[i].end()), index[i].end());\n                for(int id: index[i]) {\n\
    \                    index[i >> 1].push_back(id);\n                }\n       \
    \     }\n            seg.resize(2 * size);\n            for(int i = 1; i < 2 *\
    \ size; ++ i) {\n                seg[i] = atcoder::segtree<S, op, e>(index[i].size());\n\
    \            }\n        }\n\n        void set(int x, int y, S val) {\n       \
    \     assert(x < size);\n            x += size;\n            int posy = std::lower_bound(index[x].begin(),\
    \ index[x].end(), y) - index[x].begin();\n            assert(posy < index[x].size());\n\
    \            assert(y == index[x][posy]);\n            seg[x].set(posy, val);\n\
    \            for(int i = 1; i <= log; ++ i) {\n                x >>= 1;\n    \
    \            posy = std::lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();\n\
    \                assert(posy < (int)index[x].size());\n                assert(y\
    \ == index[x][posy]);\n                S nval = op(seg[x].get(posy), val);\n \
    \               seg[x].set(posy, nval);\n            }\n        }\n\n        S\
    \ get(int x, int y) const {\n            assert(x < size);\n            x += size;\n\
    \            int posy = std::lower_bound(index[x].begin(), index[x].end(), y)\
    \ - index[x].begin();\n            assert(posy < (int)index[x].size());\n    \
    \        assert(y == index[x][posy]);\n            return seg[x].get(posy);\n\
    \        }\n\n        S prod(int sx, int tx, int sy, int ty) const {\n       \
    \     return prod(sx, tx, sy, ty, 1, 0, size);\n        }\n\n        S all_prod()\
    \ const { return seg[1].all_prod(); }\n\n    private:\n        int _n, size, log;\n\
    \        std::vector<atcoder::segtree<S, op, e>> seg;\n        std::vector<std::vector<int>>\
    \ index;\n\n        S prod(int sx, int tx, int sy, int ty, int k, int l, int r)\
    \ const {\n            assert(k < 2 * size);\n            assert(l < r);\n   \
    \         if(r <= sx or tx <= l) return e();\n            if(sx <= l and r <=\
    \ tx) {\n                int pos_sy = std::lower_bound(index[k].begin(), index[k].end(),\
    \ sy) - index[k].begin();\n                int pos_ty = std::lower_bound(index[k].begin(),\
    \ index[k].end(), ty) - index[k].begin();\n                return seg[k].prod(pos_sy,\
    \ pos_ty);\n            }\n            int mid = (l + r) / 2;\n            S le\
    \ = prod(sx, tx, sy, ty, k * 2, l, mid);\n            S ri = prod(sx, tx, sy,\
    \ ty, k * 2 + 1, mid, r);\n            return op(le, ri);\n        }\n    };\n\
    } // namespace otera\n\n#endif // OTERA_HEALTHY_2D_SEGTREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/Healthy2DSegtree.hpp
  requiredBy: []
  timestamp: '2022-09-02 19:58:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/DataStructure/Healthy2DSegtree.hpp
layout: document
redirect_from:
- /library/library/DataStructure/Healthy2DSegtree.hpp
- /library/library/DataStructure/Healthy2DSegtree.hpp.html
title: library/DataStructure/Healthy2DSegtree.hpp
---
