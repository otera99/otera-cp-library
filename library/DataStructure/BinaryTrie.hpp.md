---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/DataStructure/BinaryTrie.hpp\"\n// UNFINISHED\n\
    #ifndef OTERA_BINARY_TRIE_HPP\n#define OTERA_BINARY_TRIE_HPP 1\n\nnamespace otera\
    \ {\n    template<typename U = unsigned, int bit_length = 32>\n    class BinaryTrie\
    \ {\n        struct Node {\n            int cnt;\n            Node *ch[2] {nullptr,\
    \ nullptr};\n            Node() : cnt(0) {}\n            ~Node() {\n         \
    \       delete ch[0];\n                delete ch[1];\n            }\n        };\n\
    \        public:\n            BinaryTrie() : root(new Node) {}\n            ~BinaryTrie()\
    \ { delete root; }\n\n\n        private:\n            Node *root;\n    };\n} //\
    \ namespace otera\n\n#endif // OTERA_BINARY_TRIE_HPP\n"
  code: "// UNFINISHED\n#ifndef OTERA_BINARY_TRIE_HPP\n#define OTERA_BINARY_TRIE_HPP\
    \ 1\n\nnamespace otera {\n    template<typename U = unsigned, int bit_length =\
    \ 32>\n    class BinaryTrie {\n        struct Node {\n            int cnt;\n \
    \           Node *ch[2] {nullptr, nullptr};\n            Node() : cnt(0) {}\n\
    \            ~Node() {\n                delete ch[0];\n                delete\
    \ ch[1];\n            }\n        };\n        public:\n            BinaryTrie()\
    \ : root(new Node) {}\n            ~BinaryTrie() { delete root; }\n\n\n      \
    \  private:\n            Node *root;\n    };\n} // namespace otera\n\n#endif //\
    \ OTERA_BINARY_TRIE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/DataStructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2022-04-15 03:33:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/DataStructure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/library/DataStructure/BinaryTrie.hpp
- /library/library/DataStructure/BinaryTrie.hpp.html
title: library/DataStructure/BinaryTrie.hpp
---
