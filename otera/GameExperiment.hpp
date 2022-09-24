#ifndef OTERA_GAME_EXPERIMENT_HPP
#define OTERA_GAME_EXPERIMENT_HPP 1

namespace otera {
    template<class S>
    struct Game : public std::map<S, bool> {
        public:
        bool win(S now) {
            bool res = dfs(now);
            return res;
        }
        private:
        bool dfs(S now) {
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

#endif // OTERA_GAME_EXPERIMENT_HPP
