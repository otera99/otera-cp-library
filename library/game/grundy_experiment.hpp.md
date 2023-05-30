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
  bundledCode: "#line 1 \"library/game/grundy_experiment.hpp\"\n\n\n\nnamespace otera\
    \ {\n    const auto S_cmp{[](auto &&a, auto &&b) -> bool {\n        return true;\n\
    \    }};\n    template<class T, class S>\n    using S_map = std::map<T, S, decltype(S_cmp)>;\n\
    \n    template<class S>\n    struct grundy : public S_map<S, int> {\n        public:\n\
    \        grundy() : S_map<S, int>(S_cmp) {}\n        int number(S now) {\n   \
    \         int res = dfs(now);\n            return res;\n        }\n        private:\n\
    \        int dfs(S now) {\n            if((*this).count(now)) return (*this)[now];\n\
    \            if(now.end_game()) {\n                return now.win();\n       \
    \     }\n            std::vector<S> nexts = now.next_game();\n            for(int\
    \ i = 0; i < (int)nexts.size(); ++ i) {\n                S nxt = nexts[i];\n \
    \               assert(nxt.alice != now.alice);\n                if(!dfs(nxt))\
    \ {\n                    return (*this)[now] = true;\n                }\n    \
    \        } \n            return (*this)[now] = false;\n        };\n    };\n} //\
    \ namespace otera\n\n\n"
  code: "#ifndef OTERA_GRUNDY_EXPERIMENT_HPP\n#define OTERA_GRUNDY_EXPERIMENT_HPP\
    \ 1\n\nnamespace otera {\n    const auto S_cmp{[](auto &&a, auto &&b) -> bool\
    \ {\n        return true;\n    }};\n    template<class T, class S>\n    using\
    \ S_map = std::map<T, S, decltype(S_cmp)>;\n\n    template<class S>\n    struct\
    \ grundy : public S_map<S, int> {\n        public:\n        grundy() : S_map<S,\
    \ int>(S_cmp) {}\n        int number(S now) {\n            int res = dfs(now);\n\
    \            return res;\n        }\n        private:\n        int dfs(S now)\
    \ {\n            if((*this).count(now)) return (*this)[now];\n            if(now.end_game())\
    \ {\n                return now.win();\n            }\n            std::vector<S>\
    \ nexts = now.next_game();\n            for(int i = 0; i < (int)nexts.size();\
    \ ++ i) {\n                S nxt = nexts[i];\n                assert(nxt.alice\
    \ != now.alice);\n                if(!dfs(nxt)) {\n                    return\
    \ (*this)[now] = true;\n                }\n            } \n            return\
    \ (*this)[now] = false;\n        };\n    };\n} // namespace otera\n\n#endif //\
    \ OTERA_GRUNDY_EXPERIMENT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/game/grundy_experiment.hpp
  requiredBy: []
  timestamp: '2023-05-31 05:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/game/grundy_experiment.hpp
layout: document
redirect_from:
- /library/library/game/grundy_experiment.hpp
- /library/library/game/grundy_experiment.hpp.html
title: library/game/grundy_experiment.hpp
---
