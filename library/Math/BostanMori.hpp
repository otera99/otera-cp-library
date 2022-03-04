#ifndef OTERA_BOSTAN_MORI
#define OTERA_BOSTAN_MORI 1

#include<library/Math/FPS.hpp>

namespace otera {
    template<typename mint>
    // `[x^n]\frac{P(x)}{Q(x)}`
    mint bostan_mori(FPS<mint> P, FPS<mint> Q, ll n) {
        auto even = [&](FPS<mint> x) -> FPS<mint> {
            FPS<mint> ret;
            for(int i = 0; i < (int)x.size(); i += 2) {
                ret.emplace_back(x[i]);
            }
            return ret;
        };
        auto odd = [&](FPS<mint> x) -> FPS<mint> {
            FPS<mint> ret;
            for(int i = 1; i < (int)x.size(); i += 2) {
                ret.emplace_back(x[i]);
            }
            return ret;
        };
        while(n > 0) {
            FPS<mint> mQ = Q;
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

#endif // OTERA_BOSTAN_MORI
