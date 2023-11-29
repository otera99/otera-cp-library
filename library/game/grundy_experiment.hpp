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
            std::vector<S> nexts = now.next_game();
            std::vector<int> cands;
            for(int i = 0; i < (int)nexts.size(); ++ i) {
                S nxt = nexts[i];
                cands.emplace_back(dfs(nxt));
            } 
            std::sort(cands.begin(), cands.end());
            cands.erase(std::unique(cands.begin(), cands.end()), cands.end());
            for(int i = 0; i < (int)cands.size(); ++ i) {
                if(cands[i] != i) {
                    return (*this)[now] = i;
                }
            }
            return (*this)[now] = (int)cands.size();
        };
    };
} // namespace otera

#endif // OTERA_GRUNDY_EXPERIMENT_HPP