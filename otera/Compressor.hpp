namespace otera {
    template <typename T>
    struct Compressor {
        public:
            static constexpr int absent = -1;

            Compressor() : _xs(std::vector<T>{}) {}

            Compressor(const std::vector<T> &vs) {
                add(vs);
                build();
            }

            void add(const std::vector<T> &vs) {
                std::copy(vs.begin(), vs.end(), std::back_inserter(_xs));
            }

            void add(const T &e) {
                _xs.emplace_back(e);
            }

            void build() {
                std::sort(_xs.begin(), _xs.end());
                _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());
            }

            int size() const {
                return _xs.size();
            }

            bool has_key(const T &e) const {
                return std::binary_search(_xs.begin(), _xs.end(), e);
            }

            std::vector<int> get(const std::vector<T> &vs) const {
                std::vector<int> res;
                std::transform(vs.begin(), vs.end(), std::back_inserter(res), [&](const T &e) {
                    return get(e);
                });
                return res;
            }

            int get(const T &e, int default_value = absent) const {
                const int id = min_geq_index(e);
                return id != size() and _xs[id] == e ? id : default_value;
            }

            const T &operator[](int compressed_index) const {
                return _xs[compressed_index];
            }

            // Return the minimum registered value greater than `e`. if not exists, return `default_value`.
            T min_gt(const T &e, const T &default_value) const {
                auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.end() ? default_value : *it;
            }
            // Return the minimum registered value greater than or equal to `e`. if not exists, return `default_value`.
            T min_geq(const T &e, const T &default_value) const {
                auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.end() ? default_value : *it;
            }
            // Return the maximum registered value less than `e`. if not exists, return `default_value`
            T max_lt(const T &e, const T &default_value) const {
                auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.begin() ? default_value : *std::prev(it);
            }
            // Return the maximum registered value less than or equal to `e`. if not exists, return `default_value`
            T max_leq(const T &e, const T &default_value) const {
                auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
                return it == _xs.begin() ? default_value : *std::prev(it);
            }
            // Return the compressed index of the minimum registered value greater than `e`. if not exists, return `Compressor.size()`.
            int min_gt_index(const T &e) const {
                return std::upper_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
            }
            // Return the compressed index of the minimum registered value greater than or equal to `e`. if not exists, return `Compressor.size()`.
            int min_geq_index(const T &e) const {
                return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
            }
            // Return the compressed index of the maximum registered value less than `e`. if not exists, return -1.
            int max_lt_index(const T &e) const {
                return int(std::lower_bound(_xs.begin(), _xs.end(), e)- _xs.begin()) - 1;
            }
            // Return the compressed index of the maximum registered value less than or equal to `e`. if not exists, return -1.
            int max_leq_index(const T &e) const {
                return int(std::upper_bound(_xs.begin(), _xs.end(), e)- _xs.begin()) - 1;
            }
        private:
            std::vector<T> _xs;
    };
} // namespace otera
