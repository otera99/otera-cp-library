#ifndef OTERA_ENUMERATE_QUOTIENT_HPP
#define OTERA_ENUMERATE_QUOTIENT_HPP 1

namespace otera {
    template <typename T>
    std::vector<tuple<T, T, T>> enumerate_quotient(T x) {
        std::vector<tuple<T, T, T>> res;
        for(T l = 1, r = 1; l <= x; l = r + 1) {
            T val = x / l;
            res.emplace_back(l, r = x / val, val);
        }
        return res;
    }
} // namespace otera

#endif // OTERA_ENUMERATE_QUOTIENT_HPP
