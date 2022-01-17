#include<vector>

namespace otera {
    class LCA {
        public:
            LCA(const std::vector<std::vector<int>> &g, int root = 0) {
                int _n = (int)g.size();
                int _N = 1;
                while((1<<_N) < _n) ++ _N;
                parent.assign(_N, std::vector<int>(_n, -1));
                dep.assign(_n, -1);
                dfs(g, root);
                for(int i = 0; i + 1 < (int)parent.size(); ++ i) {
                    for(int v = 0; v < _n; ++ v) {
                        if(parent[i][v] != -1) {
                            parent[i + 1][v] = parent[i][parent[i][v]];
                        }
                    }
                }
            }
            
            int lca(int u, int v) const {
                if(dep[u] > dep[v]) std::swap(u, v);
                for(int i = 0; i < (int)parent.size(); ++ i) {
                    if((dep[u] - dep[v]) & (1<<i)) {
                        v = parent[i][v];
                    }
                }
                if(u == v) return u;
                for(int i = (int)parent.size() - 1; i >= 0; -- i) {
                    if(parent[i][u] != parent[i][v]) {
                        u = parent[i][u];
                        v = parent[i][v];
                    }
                }
                return parent[0][u];
            }
            int dist(int u, int v) const {
                return dep[u] + dep[v] - 2 * dep[operator()(u, v)];
            }
            int operator()(int u, int v) const { return lca(u, v); }
        private:
            std::vector<int> dep;
            std::vector<std::vector<int>> parent;

            void dfs(const std::vector<std::vector<int>> &g, int root) {
                auto rec = [&](auto &&self, int v, int p, int d) -> void {
                    dep[v] = d;
                    parent[0][v] = p;
                    for(int nv: g[v]) {
                        if(nv == p) continue;
                        self(self, nv, v, d + 1);
                    }
                };
                rec(rec, root, -1, 0);
            }
    };
} // namespace otera