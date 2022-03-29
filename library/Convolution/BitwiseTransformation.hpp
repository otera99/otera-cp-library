#ifndef OTERA_BITWISE_TRANSFORMATION
#define OTERA_BITWISE_TRANSFORMATION 1

namespace otera {
    namespace internal {
        template<typename T> 
        void subset_zeta_unit_transform(T &a, T &b) {
            T c = a, d = b;
            a = c;
            b = c + d;
        }

        template<typename T> 
        void subset_mobius_unit_transform(T &a, T &b) {
            T c = a, d = b;
            a = c;
            b = -c + d;
        }

        template<typename T> 
        void supset_zeta_unit_transform(T &a, T &b) {
            T c = a, d = b;
            a = c + d;
            b = d;
        }

        template<typename T> 
        void supset_mobius_unit_transform(T &a, T &b) {
            T c = a, d = b;
            a = c - d;
            b = d;
        }

        template<typename T> 
        void walsh_hadamard_unit_transform(T &a, T &b) {
            T c = a, d = b;
            a = c + d;
            b = c - d;
        }
    } // namespace internal

    template<typename T, std::pair<T, T> (*unit)(std::pair<T, T>)> 
    void kronecker_product(std::vector<T> &x) {
        const int n = (int)x.size();
        // check n is power of 2
        assert(((n - 1) & n) == 0);
        for(int bit = 1; bit < n; bit <<= 1) {
            int mask = ~bit;
            for(int i = bit; i < n; i = (i + 1) | bit) {
                std::pair<T, T> res = unit(x[i & mask], x[i]);
                x[i & mask] = res.first;
                x[i] = res.second;
            }
        }
    }

    template<T> subset_zeta(std::vector<T> &x) {
        kronecker_product<T, internal::subset_zeta_unit_transform<T>>(x);
    }

    template<T> subset_mobius(std::vector<T> &x) {
        kronecker_product<T, internal::subset_mobiu_unit_transform<T>>(x);
    }

    template<T> supset_zeta(std::vector<T> &x) {
        kronecker_product<T, internal::supset_unit_transform<T>>(x);
    }

    template<T> supset_mobius(std::vector<T> &x) {
        kronecker_product<T, internal::supset_mobius_unit_transform<T>>(x);
    }

    template<T> walsh_hadamard(std::vector<T> &x) {
        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);
    }

    template<T> walsh_hadamard_inv(std::vector<T> &x) {
        const int n = (int)x.size();
        kronecker_product<T, internal::walsh_hadamard_unit_transform<T>>(x);
        for(auto &val: x) val /= n;
    }
} // namespace otera

#endif OTERA_BITWISE_TRANSFORMATION