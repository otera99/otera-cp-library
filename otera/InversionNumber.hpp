#ifndef OTERA_INVERSION_NUMBER_HPP
#define OTERA_INVERSION_NUMBER_HPP 1

#include<atcoder/fenwicktree>
#include<otera/Compressor>

namespace otera {
    long long InversionNumber(std::vector<long long> a) {
        int _n = (int)a.size();
        Compressor<long long> ca(a);
        int sz = (int)ca.size();
        atcoder::fenwick_tree<long long> bit(sz);
        long long res = 0;
        for(int i = 0; i < _n; ++ i) {
            res += bit.sum(ca.get(a[i]) + 1, sz);
            bit.add(ca.get(a[i]), 1);
        }
        return res;
    }
} // namespace otera

#endif // OTERA_INVERSION_NUMBER_HPP
