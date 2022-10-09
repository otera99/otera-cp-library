#ifndef OTERA_FRACTION_DEBUG_HPP
#define OTERA_FRACTION_DEBUG_HPP 1

#include<otera/Rational>

namespace otera{
    template<typename T>
    struct FractionDebug {
        T val;
        Rational<long long> fval;

        FractionDebug(long long x) : val(x), fval(x) {}
        
    }
} // namespace otera

#endif // OTERA_FRACTION_DEBUG_HPP
