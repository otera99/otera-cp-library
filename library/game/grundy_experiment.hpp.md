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
    \            std::vector<S> nexts = now.next_game();\n            std::vector<int>\
    \ cands;\n            for(int i = 0; i < (int)nexts.size(); ++ i) {\n        \
    \        S nxt = nexts[i];\n                cands.emplace_back(dfs(nxt));\n  \
    \          } \n            std::sort(cands.begin(), cands.end());\n          \
    \  cands.erase(std::unique(cands.begin(), cands.end()), cands.end());\n      \
    \      for(int i = 0; i < (int)cands.size(); ++ i) {\n                if(cands[i]\
    \ != i) {\n                    return (*this)[now] = i;\n                }\n \
    \           }\n            return (*this)[now] = (int)cands.size();\n        };\n\
    \    };\n} // namespace otera\n\n\n"
  code: "#ifndef OTERA_GRUNDY_EXPERIMENT_HPP\n#define OTERA_GRUNDY_EXPERIMENT_HPP\
    \ 1\n\nnamespace otera {\n    const auto S_cmp{[](auto &&a, auto &&b) -> bool\
    \ {\n        return true;\n    }};\n    template<class T, class S>\n    using\
    \ S_map = std::map<T, S, decltype(S_cmp)>;\n\n    template<class S>\n    struct\
    \ grundy : public S_map<S, int> {\n        public:\n        grundy() : S_map<S,\
    \ int>(S_cmp) {}\n        int number(S now) {\n            int res = dfs(now);\n\
    \            return res;\n        }\n        private:\n        int dfs(S now)\
    \ {\n            if((*this).count(now)) return (*this)[now];\n            std::vector<S>\
    \ nexts = now.next_game();\n            std::vector<int> cands;\n            for(int\
    \ i = 0; i < (int)nexts.size(); ++ i) {\n                S nxt = nexts[i];\n \
    \               cands.emplace_back(dfs(nxt));\n            } \n            std::sort(cands.begin(),\
    \ cands.end());\n            cands.erase(std::unique(cands.begin(), cands.end()),\
    \ cands.end());\n            for(int i = 0; i < (int)cands.size(); ++ i) {\n \
    \               if(cands[i] != i) {\n                    return (*this)[now] =\
    \ i;\n                }\n            }\n            return (*this)[now] = (int)cands.size();\n\
    \        };\n    };\n} // namespace otera\n\n#endif // OTERA_GRUNDY_EXPERIMENT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/game/grundy_experiment.hpp
  requiredBy: []
  timestamp: '2023-11-30 04:10:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/game/grundy_experiment.hpp
layout: document
title: "Grundy\u6570\u306E\u5B9F\u9A13\u30B3\u30FC\u30C9\u306E\u7C21\u7565\u5316"
---

## 概要

ゲームの問題のGrundy数の計算を行う

## 使い方

ゲームの状態を表現した構造体```S```を定義して，

```cpp
Grundy<S> gm;
S s
cout << gm.number(s) << endl;
```
などとすると良い．

遷移しうる状態の集合```vector<S>```を返すメンバー関数```next_game```を定義する必要がある．

## 例

[ABC297G](https://atcoder.jp/contests/abc297/tasks/abc297_g)の場合

```cpp
struct S {
    int val;

    vc<S> next_game() {
        vc<S> ret;
        for(int i = l; i <= r; ++ i) {
            if(0 <= val - i) {
                ret.pb(S{val - i});
            }
        }
        return ret;
    }
};
```
のような構造体```S```を定義し，次のようにすると良い

```cpp
int n, l, r;

// Sの定義

void solve() {
    in(n, l, r);
    grundy<S> gr;
    int sum = 0;
    rep(i, n) {
        INT(a);
        sum ^= gr.number(S{a});
    }
    out(sum == 0 ? "Second" : "First");
}
```



