#ifndef OTERA_TOPOLOGICAL_SORT_HPP
#define OTERA_TOPOLOGICAL_SORT_HPP 1

#include<otera/graph>

namespace otera {
    template<typename GraphType = graph<long long>>
    class topological_sort {
        public:
        topological_sort(const GraphType& g) {
            build(g);
        }
        bool is_dag() const { return (int)_ord.size() == _n; }
        const std::vector<int>& sorted() const { return _ord; }
        int operator[](int i) const { return _ord[i]; }
        private:
        int _n;
        std::vector<int> _ord;
        void build(const GraphType& g) {
            _n = g.size();
            std::vector<int> in_deg(_n);
            std::queue<int> que;
            for(int v = 0; v < _n; ++ v) {
                for(auto e: g[v]) {
                    int nv = e.to;
                    ++ in_deg[nv];
                }
            }
            for(int v = 0; v < _n; ++ v) {
                if(in_deg[v] == 0) que.push(v);
            }
            _ord.reserve(_n);
            while(que.size()) {
                int v = que.front(); que.pop();
                _ord.push_back(v);
                for(auto e: g[v]) {
                    int nv = e.to;
                    if(-- in_deg[nv] == 0) que.push(nv);
                }
            }
        }
    };
} // namespace otera

#endif // OTERA_TOPOLOGICAL_SORT_HPP
