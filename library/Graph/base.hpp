#ifndef OTERA_GRAPH_BASE_HPP
#define OTERA_GRAPH_BASE_HPP 1

namespace otera {
    template<typename T>
    struct Edge {
        int frm, to;
        T cost;
        int id;
    };

    template<typename T = int, bool directed = false>
    struct Graph {
        using cost_type = T;
        using edge_type = Edge<T>

        int _n, _m;

        void read_tree(int offset) {
            read_graph(_n - 1, offset);
        }

        void read_graph(int m, int offset) {
            for(int i = 0; i < m; ++ i) {
                int a, b; std::cin >> a >> b;
                a -= offset, b -= offset;
            }
            build();
        }

        void build() {

        }
    };
} // namespace otera

#endif // OTERA_GRAPH_BASE_HPP