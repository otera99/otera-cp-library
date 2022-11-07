#ifndef OTERA_MERGE_HISTORY_FOREST
#define OTERA_MERGE_HISTORY_FOREST 1

#include<atcoder/dsu>

namespace otera {
    struct merge_history_forest {
        merge_history_forest() : merge_history_forest(0) {}
        merge_history_forest(int n) : _n(n), g(2 * n - 1), uf(n), ids(2 * n - 1), root(2 * n - 1), time(2 * n - 1) {
            ite = n;
            count = 1;
            for(int i = 0; i < n; ++ i) {
                ids[i] = i;
                root[i] = true;
            }
        }
 
        int node_num() const {
            return ite;
        }
        const auto& get_dsu() const {
            return uf;
        }
        const auto& get_forest() const {
            return g;
        }
        auto get_roots() const {
            std::vector<int> roots;
            for(int i = 0; i < 2 * _n - 1; ++ i) {
                if(root[i]) {
                    roots.emplace_back(i);
                }
            }
            return roots;
        }
 
        void merge(int a, int b) {
            if(uf.same(a, b)) return;
            int ida = ids[uf.leader(a)], idb = ids[uf.leader(b)];
            root[ida] = root[idb] = false;
            uf.merge(a, b);
            ids[uf.leader(a)] = ite;
            root[ite] = true;
            g[ite].emplace_back(ida);
            g[ite].emplace_back(idb);
            ++ ite;
        }
 
        void merge_simultaneously(std::vector<std::pair<int, int>> edges) {
            for(auto &[a, b]: edges) {
                if(!uf.same(a, b)) {
                    int ida = ids[uf.leader(a)], idb = ids[uf.leader(b)];
                    if(count == time[ida]) {
                        if(count == time[idb]) {
                            if((int)g[ida].size() < (int)g[idb].size()) {
                                std::swap(a, b);
                                std::swap(ida, idb);
                            }
                            for(int nv: g[idb]) {
                                g[ida].emplace_back(nv);
                            }
                            root[idb] = false;
                            uf.merge(a, b);
                            ids[uf.leader(a)] = ida;
                        } else {
                            g[ida].emplace_back(idb);
                            root[idb] = false;
                            uf.merge(a, b);
                            ids[uf.leader(a)] = ida;
                        }
                    } else if(count == time[idb]) {
                        g[idb].emplace_back(ida);
                        root[ida] = false;
                        uf.merge(a, b);
                        ids[uf.leader(a)] = idb;
                    } else {
                        time[ite] = count;
                        merge(a, b);
                    }
                }
            }
            ++ count;
        }
 
    private:
        int _n;
        mutable int ite;
        mutable int count;
        std::vector<std::vector<int>> g;
        mutable atcoder::dsu uf;
        std::vector<int> ids;
        std::vector<bool> root;
        std::vector<int> time;
    };
} // namespace otera

#endif // OTERA_MERGE_HISTORY_FOREST