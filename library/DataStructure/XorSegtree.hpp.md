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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/internal_bit:\
    \ line -1: no such header\n"
  code: "#ifndef OTERA_XOR_SEGTREE_HPP\n#define OTERA_XOR_SEGTREE_HPP 1\n\n#include\
    \ \"atcoder/internal_bit\"\n\nnamespace otera {\n    template <class S, S (*op)(S,\
    \ S), S (*e)()> struct xor_segtree {\n        public:\n            xor_segtree()\
    \ : xor_segtree(0) {}\n            explicit xor_segtree(int n) : xor_segtree(std::vector<S>(n,\
    \ e())) {}\n            explicit xor_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n                log = atcoder::internal::ceil_pow2(_n);\n               \
    \ size = 1 << log;\n                d = std::vector<std::vector<S>>(2 * size -\
    \ 1, std::vector<S>());\n                for (int i = 0; i < _n; i++) d[size -\
    \ 1 + i].push_back(v[i]);\n                for (int i = size - 2; i >= 0; i--)\
    \ {\n                    update(i);\n                }\n            }\n\n    \
    \        S prod(int L, int R, int x, int i, int l, int r) {\n                if\
    \ (r <= L || R <= l){\n                    return e();\n                } else\
    \ if (L <= l && r <= R){\n                    return d[i][x];\n              \
    \  } else {\n                    int p = (r - l) / 2;\n                    int\
    \ mid = (l + r) / 2;\n                    if ((x & p) == 0){\n               \
    \         S resL = prod(L, R, x, i * 2 + 1, l, mid);\n                       \
    \ S resR = prod(L, R, x, i * 2 + 2, mid, r);\n                        return op(resL,\
    \ resR);\n                    } else {\n                        S resL = e();\n\
    \                        if (R >= mid){\n                            resL = prod(std::max(L,\
    \ mid) - p, R - p, x ^ p, i * 2 + 1, l, mid);\n                        }\n   \
    \                     S resR = e();\n                        if (L < mid){\n \
    \                           resR = prod(L + p, std::min(R, mid) + p, x ^ p, i\
    \ * 2 + 2, mid, r);\n                        }\n                        return\
    \ op(resR, resL);\n                    }\n                }\n            }\n\n\
    \            S prod(int l, int r, int x) {\n                return prod(l, r,\
    \ x, 0, 0, size);\n            }\n\n        private:\n            int _n, size,\
    \ log;\n            std::vector<std::vector<S>> d;\n\n            void update(int\
    \ k) { \n                int cnt = d[k * 2 + 1].size();\n                for(int\
    \ j = 0; j < cnt; ++ j) {\n                    d[k].push_back(op(d[k * 2 + 1][j],\
    \ d[k * 2 + 2][j]));\n                }\n                for(int j = 0; j < cnt;\
    \ ++ j) {\n                    d[k].push_back(op(d[k * 2 + 2][j], d[k * 2 + 1][j]));\n\
    \                }\n            }\n        };\n} // namespace otera\n\n#endif\
    \ // OTERA_XOR_SEGTREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/XorSegtree.hpp
  requiredBy: []
  timestamp: '2022-09-02 19:58:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/DataStructure/XorSegtree.hpp
layout: document
redirect_from:
- /library/library/DataStructure/XorSegtree.hpp
- /library/library/DataStructure/XorSegtree.hpp.html
title: library/DataStructure/XorSegtree.hpp
---
