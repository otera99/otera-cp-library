// UNFINISHED
#ifndef OTERA_BOSTAN_MORI_HPP
#define OTERA_BOSTAN_MORI_HPP 1

#include<otera/fps>

namespace otera {
    template<typename mint>
    // `[x^n]\frac{P(x)}{Q(x)}`
    mint bostan_mori(fps<mint> P, fps<mint> Q, long long n) {
        auto even = [&](fps<mint> x) -> fps<mint> {
            fps<mint> ret;
            for(int i = 0; i < (int)x.size(); i += 2) {
                ret.emplace_back(x[i]);
            }
            return ret;
        };
        auto odd = [&](fps<mint> x) -> fps<mint> {
            fps<mint> ret;
            for(int i = 1; i < (int)x.size(); i += 2) {
                ret.emplace_back(x[i]);
            }
            return ret;
        };
        while(n > 0) {
            fps<mint> mQ = Q;
            for(int i = 1; i < (int)Q.size(); i += 2) {
                mQ[i] = -mQ[i];
            }
            if(n % 2 == 0) P = even(P * mQ);
            else P = odd(P * mQ);
            Q = even(Q * mQ);
            n >>= 1;
        }
        return P[0];
    }
} // namesapce otera

#endif // OTERA_BOSTAN_MORI_HPP
