#ifndef OTERA_RUNLENGTH
#define OTERA_RUNLENGTH 1

namespace otera{
    template <typename Container>
    class RunLength {
        public:
            using content_type = typename Container::value_type;
            using value_type = std::pair<content_type, long long>;
            RunLength(const Container &c) noexcept {
                _compressed = compress(c);
            }

            void clear() {
                _compressed.clear();
            }

            int size() const noexcept {
                return (int)_compressed.size();
            }
            const value_type &operator[](int compressed_index) const {
                return _compressed[compressed_index];
            }

            auto begin()   const noexcept { return _compressed.begin();   }
            auto end()     const noexcept { return _compressed.end();     }
            auto rbegin()  const noexcept { return _compressed.rbegin();  }
            auto rend()    const noexcept { return _compressed.rend();    }
            auto back()    const noexcept { return _compressed.back();    }
            auto front()    const noexcept { return _compressed.front();    }

            void push_back(const content_type &val, const long long cnt = 1) {
                if (_compressed.size() and _compressed.back().first == val) {
                    _compressed.back().second += cnt;
                } else {
                    _compressed.emplace_back(val, cnt);
                }
            }

            void pop_back(long long cnt = 1) {
                while(_compressed.size() and cnt > 0) {
                    if(cnt < _compressed.back().second) {
                        _compressed.back().second -= cnt;
                        cnt = 0;
                    } else {
                        cnt -= _compressed.back().second;
                        _compressed.pop_back();
                    }
                }
            }

            static std::vector<value_type> compress(const Container &c) {
                std::vector<value_type> res;
                for(auto ite_l = c.begin(), ite_r = c.begin(); ite_l != c.end(); ite_l = ite_r) {
                    while (ite_r != c.end() and *ite_l == *ite_r) ++ite_r;
                    res.emplace_back(*ite_l, ite_r - ite_l);
                }
                return res;
            }
        private:
            std::vector<value_type> _compressed;
    };
} // namespace otera

#endif // OTERA_RUNLENGTH