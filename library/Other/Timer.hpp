namespace otera {
    struct Timer {
        public:
        Timer() {
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