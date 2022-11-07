#ifndef OTERA_NUMBER_OF_SUBSEQUENCES_HPP
#define OTERA_NUMBER_OF_SUBSEQUENCES_HPP 1


namespace otera {
    template<typename Int, typename T>
    auto number_of_subsequences(const std::vector<T> &a) -> decltype(std::declval<T>() < std::declval<T>(), Int{}) {
        const int _n = a.size();
        std::vector<std::pair<T, int>> sorted(_n);
        for(int i = 0; i < _n; ++ i) {
            sorted[i] = {a[i], i};
        }
        std::sort(sorted.begin(), sorted.end());

        std::vector<int> last(_n, -1);
        for(int i = 1; i < _n; ++ i) {
            if(sorted[i - 1].first == sorted[i].first) {
                int pre_id = sorted[i - 1].second, id = sorted[i].second;
                last[id] = pre_id;
            }
        }

        std::vector<Int> sdp(_n + 2);
        sdp[1] = 1;
        for(int i = 0; i < _n; ++ i) {
            sdp[i + 2] = sdp[i + 1] + sdp[i + 1] - sdp[last[i] + 1];
        }
        return sdp[_n + 1];
    }

    template<typename Int>
    auto number_of_subsequences(const std::string &s) -> decltype(Int{}) {
        const int _n = s.size();
        std::vector<std::pair<char, int>> sorted(_n);
        for(int i = 0; i < _n; ++ i) {
            sorted[i] = {s[i], i};
        }
        std::sort(sorted.begin(), sorted.end());

        std::vector<int> last(_n, -1);
        for(int i = 1; i < _n; ++ i) {
            if(sorted[i - 1].first == sorted[i].first) {
                int pre_id = sorted[i - 1].second, id = sorted[i].second;
                last[id] = pre_id;
            }
        }

        std::vector<Int> sdp(_n + 2);
        sdp[1] = 1;
        for(int i = 0; i < _n; ++ i) {
            sdp[i + 2] = sdp[i + 1] + sdp[i + 1] - sdp[last[i] + 1];
        }
        return sdp[_n + 1];
    }
} // namespace otera 

#endif // OTERA_NUMBER_OF_SUBSEQUENCES_HPP
