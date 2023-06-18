#ifndef OTERA_REVERSE_GRAPH_HPP
#define OTERA_REVERSE_GRAPH_HPP 1

#include<otera/graph>

namespace otera {
    template<typename GraphType = graph<long long>>
    GraphType reverse_graph(const GraphType& g) {
        assert(g.is_directed);
        int n = (int)g.size();
        GraphType rg(n, 1);
        for(int v = 0; v < n; ++ v) {
            for(auto e: g[v]) {
                rg.add_directed_edge(e.to, v, e.weight, e.id);
            }
        }
        return rg;
    }
} // namespace otera

#endif // OTERA_REVERSE_GRAPH_HPP
