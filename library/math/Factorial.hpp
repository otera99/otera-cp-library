#ifndef OTERA_FACTORIAL_HPP
#define OTERA_FACTORIAL_HPP 1

#include<library/modint/modint.hpp>

namespace otera{
    template<typename T>
    class factorial {
        public:
        factorial() {}
        factorial(int n) {
            ensure(n);
        }
        T perm(const int n, const int k) {
            if(k < 0 or n < k) return 0;
            ensure(n);
            return fact_[n] * finv_[n - k];
        }
        T com(const int n, const int k) {
            if(n == k) return 1;
            if(n < k or n < 0 or k < 0) return 0;
            ensure(n);
            return fact_[n] * finv_[k] * finv_[n - k];
        }
        T hom(const int n, const int k) {
            if(n < 0 or k < 0) return 0;
            if(k == 0) return 1;
            return com(n + k - 1, k);
        }
        T fact(const int n) {
            if(n < 0) return 0;
            ensure(n);
            return fact_[n];
        }
        T inv(const int n) {
            if(n < 0) return 0;
            ensure(n);
            return inv_[n];
        }
        T finv(const int n) {
            if(n < 0) return 0;
            ensure(n);
            return finv_[n];
        }
        private:
        static std::vector<T> fact_, inv_, finv_;
        int MOD = T::mod();
        void ensure(const int n) {
            int sz = fact_.size();
            if(n + 1 <= sz) return;
            int next_sz = std::max(n + 1, sz * 2);
            fact_.resize(next_sz), inv_.resize(next_sz), finv_.resize(next_sz);
            for(int i = sz; i < next_sz; ++ i) {
                fact_[i] = fact_[i - 1] * i;
                inv_[i] = -inv_[MOD % i] * (MOD / i);
                finv_[i] = finv_[i - 1] * inv_[i];
            }
        }
    };
    template<typename T> std::vector<T> factorial<T>::fact_ {1, 1};
    template<typename T> std::vector<T> factorial<T>::inv_ {1, 1};
    template<typename T> std::vector<T> factorial<T>::finv_ {1, 1};
} // namespace otera

#endif // OTERA_FACTORAIL_HPP