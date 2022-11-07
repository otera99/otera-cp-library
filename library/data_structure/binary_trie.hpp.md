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
  bundledCode: "#line 1 \"library/data_structure/binary_trie.hpp\"\n// UNFINISHED\n\
    #ifndef OTERA_BINARY_TRIE_HPP\n#define OTERA_BINARY_TRIE_HPP 1\n\nnamespace otera\
    \ {\n    template<typename U = unsigned, int bit_length = 32>\n    class binary_trie\
    \ {\n        struct node {\n            int cnt;\n            node *ch[2] {nullptr,\
    \ nullptr};\n            node() : cnt(0) {}\n            ~node() {\n         \
    \       delete ch[0];\n                delete ch[1];\n            }\n        };\n\
    \        public:\n            binary_trie() : root(new node) {}\n            ~binary_trie()\
    \ { delete root; }\n\n\n        private:\n            node *root;\n    };\n} //\
    \ namespace otera\n\n#endif // OTERA_BINARY_TRIE_HPP\n"
  code: "// UNFINISHED\n#ifndef OTERA_BINARY_TRIE_HPP\n#define OTERA_BINARY_TRIE_HPP\
    \ 1\n\nnamespace otera {\n    template<typename U = unsigned, int bit_length =\
    \ 32>\n    class binary_trie {\n        struct node {\n            int cnt;\n\
    \            node *ch[2] {nullptr, nullptr};\n            node() : cnt(0) {}\n\
    \            ~node() {\n                delete ch[0];\n                delete\
    \ ch[1];\n            }\n        };\n        public:\n            binary_trie()\
    \ : root(new node) {}\n            ~binary_trie() { delete root; }\n\n\n     \
    \   private:\n            node *root;\n    };\n} // namespace otera\n\n#endif\
    \ // OTERA_BINARY_TRIE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/library/data_structure/binary_trie.hpp
- /library/library/data_structure/binary_trie.hpp.html
title: library/data_structure/binary_trie.hpp
---
