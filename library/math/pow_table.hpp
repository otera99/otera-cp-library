#ifndef OTERA_POW_TABLE_HPP
#define OTERA_POW_TABLE_HPP 1

#include<library/modint/modint.hpp>

namespace otera{
    template<typename T>
    class pow_table {
        public:
        pow_table(T x) : x_(x), pw_(1, 1) {}
        pow_table(T x, int n) : x_(x), pw_(1, 1) {
            ensure(n);
        }
        T pow(const int n) {
            assert(n >= 0);
            ensure(n);
            return pw_[n];
        }
        T operator[](const int n) {
            return pow(n);
        }
        private:
        T x_;
        std::vector<T> pw_;
        void ensure(const int n) {
            int sz = pw_.size();
            if(n + 1 <= sz) return;
            int next_sz = std::max(n + 1, sz * 2);
            pw_.resize(next_sz);
            for(int i = sz; i < next_sz; ++ i) {
                pw_[i] = pw_[i - 1] * x_;
            }
        }
    };
} // namespace otera

#endif // OTERA_POW_TABLE_HPP