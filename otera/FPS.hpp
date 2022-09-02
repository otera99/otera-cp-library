// UNFINISHED
#ifndef OTERA_FPS_HPP
#define OTERA_FPS_HPP 1

namespace otera {
    template<typename mint>
    struct FPS : std::vector<mint> {
        public:

        FPS operator -() const {
            FPS ret(*this);
            for(auto &e: ret) e = -e;
            return ret;
        };
        

        private:
    }
} // namespace otera

#endif // OTERA_FPS_HPP
