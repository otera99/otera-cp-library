#ifndef OTERA_CARTESIAN_TREE_HPP
#define OTERA_CARTESIAN_TREE_HPP 1

namespace otera {
    // 根を最小にしたいならless<T>, 根を最大にしたいならgreater<T>
    template<typename T, typename Comparator>
    struct CartesianTree {
        public:
            CartesianTree(const std::vector<T> &a) {
                build(a);
            }

            int parent(std::size_t i) const {
                assert(i < par.size()); 
                return par[i];
            }
            int operator[](std::size_t i) const {
                return parent(i);
            }
            std::vector<std::vector<int>> graph() const {
                return g;
            }
            int root() const {
                return _root;
            }
            int size() const {
                return (int)g.size();
            }

            void build(const std::vector<T> &a, Comparator comp = Comparator{}) {
                int n = (int)a.size();
                std::vector<T> st;
                st.reserve(n);
                par.assign(n, -1);
                g.resize(n);
                for(int i = 0; i < n; ++ i) {
                    int p = -1;
                    while(!st.empty() && comp(a[i], a[st.back()])) {
                        p = st.back();
                        st.pop_back();
                    }
                    if(p != -1) par[p] = i;
                    if(!st.empty()) par[i] = st.back();
                    st.push_back(i);
                }
                int _root = -1;
                for(int i = 0; i < n; ++ i) {
                    if(par[i] != -1) g[par[i]].push_back(i);
                    else _root = i;
                }
            }
        private:
            int _root;
            std::vector<std::vector<int>> g;
            std::vector<int> par;
    };
    
} // namespace otera

#endif // OTERA_CARTESIAN_TREE_HPP
