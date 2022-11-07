#ifndef OTERA_HEALTHY_2D_SEGTREE_HPP 
#define OTERA_HEALTHY_2D_SEGTREE_HPP 1

#include<atcoder/segtree>

namespace otera {
    template <class S, S (*op)(S, S), S (*e)()> struct health_2d_segtree {
    public:
        health_2d_segtree() : health_2d_segtree(0) {}
        explicit health_2d_segtree(const std::vector<std::vector<long long>>& v) : _n((int)v.size()) {
            log = atcoder::internal::ceil_pow2(_n);
            size = 1 << log;
            index.resize(2 * size);
            for(int i = 0; i < _n; ++ i) {
                for(int id: v[i]) {
                    index[size + i].push_back(id);
                }
            }
            for(int i = 2 * size - 1; i >= 1; -- i) {
                std::sort(index[i].begin(), index[i].end());
                index[i].erase(std::unique(index[i].begin(), index[i].end()), index[i].end());
                for(int id: index[i]) {
                    index[i >> 1].push_back(id);
                }
            }
            seg.resize(2 * size);
            for(int i = 1; i < 2 * size; ++ i) {
                seg[i] = atcoder::segtree<S, op, e>(index[i].size());
            }
        }

        void set(int x, int y, S val) {
            assert(x < size);
            x += size;
            int posy = std::lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(posy < index[x].size());
            assert(y == index[x][posy]);
            seg[x].set(posy, val);
            for(int i = 1; i <= log; ++ i) {
                x >>= 1;
                posy = std::lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
                assert(posy < (int)index[x].size());
                assert(y == index[x][posy]);
                S nval = op(seg[x].get(posy), val);
                seg[x].set(posy, nval);
            }
        }

        S get(int x, int y) const {
            assert(x < size);
            x += size;
            int posy = std::lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(posy < (int)index[x].size());
            assert(y == index[x][posy]);
            return seg[x].get(posy);
        }

        S prod(int sx, int tx, int sy, int ty) const {
            return prod(sx, tx, sy, ty, 1, 0, size);
        }

        S all_prod() const { return seg[1].all_prod(); }

    private:
        int _n, size, log;
        std::vector<atcoder::segtree<S, op, e>> seg;
        std::vector<std::vector<int>> index;

        S prod(int sx, int tx, int sy, int ty, int k, int l, int r) const {
            assert(k < 2 * size);
            assert(l < r);
            if(r <= sx or tx <= l) return e();
            if(sx <= l and r <= tx) {
                int pos_sy = std::lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
                int pos_ty = std::lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
                return seg[k].prod(pos_sy, pos_ty);
            }
            int mid = (l + r) / 2;
            S le = prod(sx, tx, sy, ty, k * 2, l, mid);
            S ri = prod(sx, tx, sy, ty, k * 2 + 1, mid, r);
            return op(le, ri);
        }
    };
} // namespace otera

#endif // OTERA_HEALTHY_2D_SEGTREE_HPP