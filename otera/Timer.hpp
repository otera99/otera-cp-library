#ifndef OTERA_TIMER_HPP
#define OTERA_TIMER_HPP 1

namespace otera {
    struct timer {
        public:
        timer() {
            start();
        }
        void start() {
            time = std::clock();
        }   
        double elapsed() {
            return 1.0 * (std::clock() - time) / CLOCKS_PER_SEC;
        }
        private:
        int time;
    };
} // namespace otera

#endif // OTERA_TIMER_HPP
