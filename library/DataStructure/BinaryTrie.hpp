// UNFINISHED
#ifndef OTERA_BINARY_TRIE_HPP
#define OTERA_BINARY_TRIE_HPP 1

namespace otera {
    template<typename U = unsigned, int bit_length = 32>
    class BinaryTrie {
        struct Node {
            int cnt;
            Node *ch[2] {nullptr, nullptr};
            Node() : cnt(0) {}
            ~Node() {
                delete ch[0];
                delete ch[1];
            }
        };
        public:
            BinaryTrie() : root(new Node) {}
            ~BinaryTrie() { delete root; }


        private:
            Node *root;
    };
} // namespace otera

#endif // OTERA_BINARY_TRIE_HPP