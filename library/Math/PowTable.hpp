#ifndef OTERA_POW_TABLE_HPP
#define OTERA_POW_TABLE_HPP 1

#include<library/AtCoder/modint.hpp>

namespace otera{
    template<typename T>
    class powtable {
        public:
        powtable(long long x) : x_(T(x)), pw_(1, 1) {}
        powtable(long long x, int n) : x_(T(x)), pw_(1, 1) {
            ensure(n);
        }
        T pow(const int n) {
            assert(n >= 0);
            ensure(n);
            return pw_[n];
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