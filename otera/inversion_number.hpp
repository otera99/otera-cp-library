#ifndef OTERA_INVERSION_NUMBER_HPP
#define OTERA_INVERSION_NUMBER_HPP 1

#include<atcoder/fenwicktree>
#include<otera/compressor>

namespace otera {
    template<typename T>
    long long inversion_number(std::vector<T> a) {
        int _n = (int)a.size();
        compressor<T> ca(a);
        int _sz = (int)ca.size();
        atcoder::fenwick_tree<T> bit(sz);
        long long res = 0;
        for(int i = 0; i < _n; ++ i) {
            int _pos = ca.get(a[i]);
            res += (long long)bit.sum(_pos + 1, _sz);
            bit.add(_pos, 1);
        }
        return res;
    }
} // namespace otera

#endif // OTERA_INVERSION_NUMBER_HPP
