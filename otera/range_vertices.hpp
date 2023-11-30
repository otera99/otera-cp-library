#ifndef OTERA_RANGE_VERTICES_HPP
#define OTERA_RANGE_VERTICES_HPP 1

namespace otera {
    std::vector<int> range_vertices(int n, int l, int r) {
        std::vector<int> ret;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) {
                ret.emplace_back(l);
                l ++;
            } 
            if(r & 1) {
                -- r;
                ret.emplace_back(r);
            } 
        }
        return ret;
    }
} // namespace otera 

#endif // OTERA_VERTICES_HPP
