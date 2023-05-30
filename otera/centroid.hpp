#ifndef OTERA_CENTROID_HPP
#define OTERA_CENTROID_HPP 1

#include<otera/graph>

namespace otera {
    std::vector<int> centroid(const graph& g) {
        std::vector<int> ret;
        std::vector<int> sz;
        auto dfs = [&](auto&&dfs, int v, int p) -> void {
            sz[v] = 1;
            bool flag = 1;
            for(auto e: g[v]) {
                int nv = e.to;
                if(nv == p) continue;
                dfs(dfs, nv, v);
                if(sz[nv] > n / 2) flag = 0;
                sz[v] += sz[nv];
            }
            if(n - sz[v] > n / 2) flag = 0;
            if(flag) {
                ret.emplace_back(v);
            }
        };
        dfs(dfs, 0, -1);
        return ret;
    }
} // namespace otera

#endif // OTERA_CENTROID_HPP
