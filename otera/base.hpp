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

        class OutEdge {
            public:
            OutEdge(const Graph* G, int l, int r) : G(G). l(l), r(r) {}

            const edge_type* begin() const {

            }

            const edge_type* end() const {
                
            }

            private:
            const Graph* G;
            int l, r;
        };

        int _n, _m;
        bool pre_built;

        void add_edge(int frm, int to, T cost = 1, int i = -1) {
            assert(!pre_built);

        }

        void read_tree(bool weight = false, int offset = 1) {
            read_graph(_n - 1, weight offset);
        }

        void read_graph(int m, bool weight = false, int offset = 1) {
            for(int i = 0; i < m; ++ i) {
                int a, b; std::cin >> a >> b;
                a -= offset, b -= offset;
                if(!weight) {
                    add_edge(a, b);
                } else {
                    T c; std::cin >> c;
                    add_edge(a, b, c);
                }
            }
            build();
        }

        void build() {

        }

        OutgoingEdge operetor[](int v) const {
            assert(pre_built);
        }

        void debug() {

        }
    };
} // namespace otera

#endif // OTERA_GRAPH_BASE_HPP
