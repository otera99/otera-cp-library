#ifndef OTERA_HEAVY_LIGHT_DECOMPOSITION_HPP
#define OTERA_HEAVY_LIGHT_DECOMPOSITION_HPP 1

namespace otera {
    template<typename GraphType>
    struct tree : GraphType {
        public:

        int la(int v, int k) {

        }

        int lca(int u, int v) {

        }

        int jump(int a, int b, long long k) {
            
        }
        
        private:
        std::vector<int> sz, order, head;
        std::vector<int> parent;

        auto dfs_sz = [&](auto&&dfs_sz, int v, int p) -> void {
            sz[v] = 1;
            for(auto e: g[v]) {
                int nv = e.to;
                if(nv == p) continue;
                dfs_sz(dfs_sz, nv, v);
                sz[v] += sz[nv];
                if(sz[nv] > sz[g[v][0].to]) {
                    swap(e, g[v][0]);
                }
            }
        };
        auto dfs_hld = [&](auto&&dfs_hld, int v, int p, int &times) -> void {
            order[v] = times ++;
            for(auto e: g[v]) {
                int nv = e.to;
                if(nv == p) continue;
                head[nv] = (g[v][0].to == nv ? head[v] : nv);
                dfs_hld(dfs_hld, nv, v, times);
            }
        };
    };
} // namespace otera

#endif // OTERA_HEAVY_LIGHT_DECOMPOSITION_HPP