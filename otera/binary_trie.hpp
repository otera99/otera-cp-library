// UNFINISHED
#ifndef OTERA_BINARY_TRIE_HPP
#define OTERA_BINARY_TRIE_HPP 1

namespace otera {
    template<typename U = unsigned, int bit_length = 32>
    class binary_trie {
        struct node {
            int cnt;
            node *ch[2] {nullptr, nullptr};
            node() : cnt(0) {}
            ~node() {
                delete ch[0];
                delete ch[1];
            }
        };
        public:
            binary_trie() : root(new node) {}
            ~binary_trie() { delete root; }


        private:
            node *root;
    };
} // namespace otera

#endif // OTERA_BINARY_TRIE_HPP
