#ifndef OTERA_GRAPH_HPP
#define OTERA_GRAPH_HPP 1

namespace otera {
    template<typename T = long long>
    struct edge {
        int to;
        T weight;
        int id;
        edge(int to, T weight, int id) : to(to), weight(weight), id(id) {}
        operator int() const { return to; }
    };

    template<typename T = long long>
    struct graph : std::vector<std::vector<edge<T>>> {
        int _n, _m;
        bool is_directed;
        using weight_type = T;
        using edge_type = edge<T>;

        graph() : _n(0), _m(0), is_directed(false) {}
        graph(int n, bool is_directed = false) : _n(n), _m(0), is_directed(is_directed) {
            (*this).assign(n, std::vector<edge<T>>());
        }

        void add_edge(int frm, int to, T weight = 1, int id = -1) {
            assert(0 <= frm and frm < _n and 0 <= to and to < _n);
            if(id == -1) id = _m;
            (*this)[frm].emplace_back(to, weight, id);
            (*this)[to].emplace_back(frm, weight, id);
            ++ _m;
        }

        void add_directed_edge(int frm, int to, T weight = 1, int id = -1) {
            assert(0 <= frm and frm < _n and 0 <= to and to < _n);
            assert(is_directed);
            if(id == -1) id = _m;
            (*this)[frm].emplace_back(to, weight, id);
            ++ _m;
        }

        void read_tree(bool wt = false, int off = 1) {
            read_graph(_n - 1, wt, off);
        }

        void read_graph(int m, bool wt = false, int off = 1) {
            assert(!is_directed);
            for(int i = 0; i < m; ++ i) {
                int a, b; std::cin >> a >> b;
                a -= off, b -= off;
                assert(0 <= a and a < _n and 0 <= b and b < _n);
                if(!wt) {
                    add_edge(a, b);
                } else {
                    T c; std::cin >> c;
                    add_edge(a, b, c);
                }
            }
        }

        void read_directed_graph(int m, bool wt = false, int off = 1) {
            assert(is_directed);
            for(int i = 0; i < m; ++ i) {
                int a, b; std::cin >> a >> b;
                a -= off, b -= off;
                assert(0 <= a and a < _n and 0 <= b and b < _n);
                if(!wt) {
                    add_directed_edge(a, b);
                } else {
                    T c; std::cin >> c;
                    add_directed_edge(a, b, c);
                }
            }
        }

        void read_parent(int off = 1) {
            for(int v = 1; v < _n; ++ v) {
                int p; std::cin >> p;
                p -= off;
                add_edge(p, v);
            }
        }

        int deg(int v) {
            return (int)size((*this)[v]);
        }
    };
} // namespace otera

#endif // OTERA_GRAPH_HPP