namespace otera {
    class RandomGenerator {
        public:
            RandomGenerator() : mt64(std::chrono::steady_clock::now().time_since_epoch().count()) {}

            // [a, b)
            long long operator()(long long a, long long b) {
                std::uniform_int_distribution<long long> dist(a, b - 1);
                return dist(mt64);
            }
        private:
            std::mt19937_64 mt64;
    };
} // namespace otera
