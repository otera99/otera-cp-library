#ifndef OTERA_DFS_ORDER_HPP
#define OTERA_DFS_ORDER_HPP 1

#include<otera/graph>

namespace otera {
    template<typename GraphType = graph<long long>>
    struct dfs_order {
        int _n;
        int root = -1;
        std::vector<int> _order, _depth, _parent;

        dfs_order(const GraphType& g, int r = 0) : _n((int)g.size()), root(r) {
            build(g);
        }

        int operator[](int i) const { return _order[i]; }
        int depth(int v) const { return _depth[v]; }
        int parent(int v) const { return _parent[v]; }

        private:
        void dfs(const GraphType& g, int v, int pre = -1) {
            _parent[v] = pre;
            for(int nv: g[v]) {
                if(nv == pre) continue;
                _depth[nv] = _depth[v] + 1;
                dfs(g, nv, v);
            }
            _order.push_back(v);
        }
        void build(const GraphType& g) {
            _order.reserve(_n);
            _depth.assign(_n, 0);
            _parent.assign(_n, -1);
            dfs(g, root);
        }
    };
} // namespace otera

#endif // OTERA_DFS_ORDER_HPP
