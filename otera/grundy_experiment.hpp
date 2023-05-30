#ifndef OTERA_GRUNDY_EXPERIMENT_HPP
#define OTERA_GRUNDY_EXPERIMENT_HPP 1

namespace otera {
    const auto S_cmp{[](auto &&a, auto &&b) -> bool {
        return true;
    }};
    template<class T, class S>
    using S_map = std::map<T, S, decltype(S_cmp)>;

    template<class S>
    struct grundy : public S_map<S, int> {
        public:
        grundy() : S_map<S, int>(S_cmp) {}
        int number(S now) {
            int res = dfs(now);
            return res;
        }
        private:
        int dfs(S now) {
            if((*this).count(now)) return (*this)[now];
            if(now.end_game()) {
                return now.win();
            }
            std::vector<S> nexts = now.next_game();
            for(int i = 0; i < (int)nexts.size(); ++ i) {
                S nxt = nexts[i];
                assert(nxt.alice != now.alice);
                if(!dfs(nxt)) {
                    return (*this)[now] = true;
                }
            } 
            return (*this)[now] = false;
        };
    };
} // namespace otera

#endif // OTERA_GRUNDY_EXPERIMENT_HPP
