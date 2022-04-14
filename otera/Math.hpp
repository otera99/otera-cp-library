#ifndef OTERA_MATH_HPP
#define OTERA_MATH_HPP 1

namespace otera {
    // return floor(x / y)
    template<typename T>
    constexpr inline T fld(const T x, const T y) {
        if((x ^ y) >= 0) return x / y;
        if(y > 0) return (x - (y - 1)) / y;
        else return (x - (y + 1)) / y;
    }
    // return ceil(x / y)
    template<typename T>
    constexpr inline T ced(const T x, const T y) {
        if((x ^ y) <= 0) return x / y;
        if(y > 0) return (x + (y - 1)) / y;
        else return (x + (y + 1)) / y;
    }
    // return x % y
    // y > 0
    template<typename T>
    constexpr inline T rem(const T x, const T y) {
        assert(y > 0);
        if(x > 0) return x % y;
        else return (y - x % y) % y;
    }
} // namespace otera

#endif // OTERA_MATH_HPP
