#ifndef OTERA_CARTESIAN_TREE_HPP
#define OTERA_CARTESIAN_TREE_HPP 1

namespace otera {
    // 根を最小にしたいならless<T>, 根を最大にしたいならgreater<T>
    template<typename T, typename Comparator>
    struct cartesian_tree : public std::vector<std::array<int, 2>> {
        public:
            static constexpr int absent = -1;

            cartesian_tree(const std::vector<T> &a, Comparator comp = Comparator{}) {
                build(a, comp);
            }

            int parent(std::size_t i) const {
                assert(i < _par.size()); 
                return _par[i];
            }

            int root() const {
                return _root;
            }

        private:
            int _root;
            std::vector<int> _par;

            void build(const std::vector<T> &a, Comparator comp = Comparator{}) {
                int n = (int)a.size();
                std::vector<int> st;
                st.reserve(n);
                _par.assign(n, -1);
                for(int i = 0; i < n; ++ i) {
                    int p = -1;
                    while(!st.empty() && comp(a[i], a[st.back()])) {
                        p = st.back();
                        st.pop_back();
                    }
                    if(p != -1) _par[p] = i;
                    if(!st.empty()) _par[i] = st.back();
                    st.push_back(i);
                }
                int _root = -1;
                (*this).assign(n, { absent, absent });
                for(int i = 0; i < n; ++ i) {
                    int p = _par[i];
                    (p >= 0 ? (*this)[p][p <= i] : (*this)._root) = i;
                }
            }
    };
    
} // namespace otera

#endif // OTERA_CARTESIAN_TREE_HPP
