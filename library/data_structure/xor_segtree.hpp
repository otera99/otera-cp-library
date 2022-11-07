#ifndef OTERA_XOR_SEGTREE_HPP
#define OTERA_XOR_SEGTREE_HPP 1

#include "atcoder/internal_bit"

namespace otera {
    template <class S, S (*op)(S, S), S (*e)()> struct xor_segtree {
        public:
            xor_segtree() : xor_segtree(0) {}
            explicit xor_segtree(int n) : xor_segtree(std::vector<S>(n, e())) {}
            explicit xor_segtree(const std::vector<S>& v) : _n(int(v.size())) {
                log = atcoder::internal::ceil_pow2(_n);
                size = 1 << log;
                d = std::vector<std::vector<S>>(2 * size - 1, std::vector<S>());
                for (int i = 0; i < _n; i++) d[size - 1 + i].push_back(v[i]);
                for (int i = size - 2; i >= 0; i--) {
                    update(i);
                }
            }

            S prod(int L, int R, int x, int i, int l, int r) {
                if (r <= L || R <= l){
                    return e();
                } else if (L <= l && r <= R){
                    return d[i][x];
                } else {
                    int p = (r - l) / 2;
                    int mid = (l + r) / 2;
                    if ((x & p) == 0){
                        S resL = prod(L, R, x, i * 2 + 1, l, mid);
                        S resR = prod(L, R, x, i * 2 + 2, mid, r);
                        return op(resL, resR);
                    } else {
                        S resL = e();
                        if (R >= mid){
                            resL = prod(std::max(L, mid) - p, R - p, x ^ p, i * 2 + 1, l, mid);
                        }
                        S resR = e();
                        if (L < mid){
                            resR = prod(L + p, std::min(R, mid) + p, x ^ p, i * 2 + 2, mid, r);
                        }
                        return op(resR, resL);
                    }
                }
            }

            S prod(int l, int r, int x) {
                return prod(l, r, x, 0, 0, size);
            }

        private:
            int _n, size, log;
            std::vector<std::vector<S>> d;

            void update(int k) { 
                int cnt = d[k * 2 + 1].size();
                for(int j = 0; j < cnt; ++ j) {
                    d[k].push_back(op(d[k * 2 + 1][j], d[k * 2 + 2][j]));
                }
                for(int j = 0; j < cnt; ++ j) {
                    d[k].push_back(op(d[k * 2 + 2][j], d[k * 2 + 1][j]));
                }
            }
        };
} // namespace otera

#endif // OTERA_XOR_SEGTREE_HPP