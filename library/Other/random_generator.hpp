#ifndef OTERA_RANDOM_GENERATOR_HPP
#define OTERA_RANDOM_GENERATOR_HPP 1

namespace otera {
    class random_gen {
        public:
            random_gen() : mt64(std::chrono::steady_clock::now().time_since_epoch().count()) {}

            // [a, b)
            long long operator()(long long a, long long b) {
                std::uniform_int_distribution<long long> dist(a, b - 1);
                return dist(mt64);
            }
        private:
            std::mt19937_64 mt64;
    };
} // namespace otera

#endif // OTERA_RANDOM_GENERATOR_HPP
