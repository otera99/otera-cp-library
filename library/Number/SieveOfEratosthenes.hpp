#ifndef OTERA_SIEVE_OF_ERATOSTHENES_HPP
#define OTERA_SIEVE_OF_ERATOSTHENES_HPP 1

namespace otera {
    struct Eratos {
        public:
            Eratos() : Eratos(0) {}
            Eratos(int N) { init(N); }

            void init(int N) {
                _N = N;
                _primes.clear();
                _isprime.assign(_N + 1, true);
                _min_factor.assign(_N + 1, -1);
                _isprime[0] = _isprime[1] = false;
                _min_factor[0] = 0, _min_factor[1] = 1;
                for (int i = 2; i <= _N; ++i) {
                    if (!_isprime[i]) continue;
                    _primes.push_back(i);
                    _min_factor[i] = i;
                    for (int j = i * 2; j <= _N; j += i) {
                        _isprime[j] = false;
                        if (_min_factor[j] == -1) _min_factor[j] = i;
                    }
                }
            }

            bool isprime(int n) {
                assert(0 <= n and n <= _N);
                return _isprime[n];
            }

            std::vector<int> primes() {
                return _primes;
            }

            std::vector<std::pair<int,int>> prime_factors(int n) {
                std::vector<std::pair<int,int>> res;
                while (n != 1) {
                    int prime = _min_factor[n];
                    int exp = 0;
                    while (_min_factor[n] == prime) {
                        ++exp;
                        n /= prime;
                    }
                    res.push_back(std::make_pair(prime, exp));
                }
                return res;
            }

            std::vector<int> divisors(int n) {
                std::vector<int> res({1});
                auto pf = prime_factors(n);
                for (auto p :pf) {
                    int n = (int)res.size();
                    for (int i = 0; i < n; ++i) {
                        int v = 1;
                        for (int j = 0; j < p.second; ++j) {
                            v *= p.first;
                            res.push_back(res[i] * v);
                        }
                    }
                }
                return res;
            }

        private:
            int _N;
            std::vector<int> _primes;
            std::vector<bool> _isprime;
            std::vector<int> _min_factor;
    };
} // namespace otera

#endif // OTERA_SIEVE_OF_ERATOSTHENES_HPP