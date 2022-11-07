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
  bundledCode: "#line 1 \"library/game/game_experiment.hpp\"\n\n\n\nnamespace otera\
    \ {\n    const auto S_cmp{[](auto &&a, auto &&b) -> bool {\n        return true;\n\
    \    }};\n    template<class T, class S>\n    using S_map = std::map<T, S, decltype(S_cmp)>;\n\
    \n    template<class S>\n    struct game : public S_map<S, bool> {\n        public:\n\
    \        game() : S_map<S, bool>(S_cmp) {}\n        bool win(S now) {\n      \
    \      bool res = dfs(now);\n            return res;\n        }\n        private:\n\
    \        bool dfs(S now) {\n            if((*this).count(now)) return (*this)[now];\n\
    \            if(now.end_game()) {\n                return now.win();\n       \
    \     }\n            std::vector<S> nexts = now.next_game();\n            for(int\
    \ i = 0; i < (int)nexts.size(); ++ i) {\n                S nxt = nexts[i];\n \
    \               assert(nxt.alice != now.alice);\n                if(!dfs(nxt))\
    \ {\n                    return (*this)[now] = true;\n                }\n    \
    \        } \n            return (*this)[now] = false;\n        };\n    };\n} //\
    \ namespace otera\n\n\n"
  code: "#ifndef OTERA_GAME_EXPERIMENT_HPP\n#define OTERA_GAME_EXPERIMENT_HPP 1\n\n\
    namespace otera {\n    const auto S_cmp{[](auto &&a, auto &&b) -> bool {\n   \
    \     return true;\n    }};\n    template<class T, class S>\n    using S_map =\
    \ std::map<T, S, decltype(S_cmp)>;\n\n    template<class S>\n    struct game :\
    \ public S_map<S, bool> {\n        public:\n        game() : S_map<S, bool>(S_cmp)\
    \ {}\n        bool win(S now) {\n            bool res = dfs(now);\n          \
    \  return res;\n        }\n        private:\n        bool dfs(S now) {\n     \
    \       if((*this).count(now)) return (*this)[now];\n            if(now.end_game())\
    \ {\n                return now.win();\n            }\n            std::vector<S>\
    \ nexts = now.next_game();\n            for(int i = 0; i < (int)nexts.size();\
    \ ++ i) {\n                S nxt = nexts[i];\n                assert(nxt.alice\
    \ != now.alice);\n                if(!dfs(nxt)) {\n                    return\
    \ (*this)[now] = true;\n                }\n            } \n            return\
    \ (*this)[now] = false;\n        };\n    };\n} // namespace otera\n\n#endif //\
    \ OTERA_GAME_EXPERIMENT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: library/game/game_experiment.hpp
  requiredBy: []
  timestamp: '2022-11-08 07:21:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/game/game_experiment.hpp
layout: document
title: "\u30B2\u30FC\u30E0\u306E\u5B9F\u9A13\u30B3\u30FC\u30C9\u306E\u7C21\u7565\u5316"
---

## 概要

ゲームの問題のゲームDPのメモ化再帰を自動で行う

## 使い方

ゲームの状態を表現した構造体```S```を定義して，

```cpp
Game<S> gm
S s
cout << gm.win(s) << endl;
```
などとすると良い．

なお，構造体```S```では```alice```というbool値のメンバー変数を持つ必要がある．(これは，AliceとBobがゲームをしている場合のどちらの手番かに相当する)

遷移しうる状態の集合```vector<S>```を返すメンバー関数```next_game```と，状態の勝敗を返すメンバー関数```win```と，ゲームが終了したかどうかを判定するメンバー関数```end_game```を定義する必要がある．

~~また，```std::map```を使う関係で```<```を定義しなければいけないことにも注意する~~ (2022/9/25に書き換えたので不要になった)

## 例

[ARC148D](https://atcoder.jp/contests/arc148/tasks/arc148_d)の場合

```cpp
struct S {
    vc<int> v;
    bool alice;
    int asum, bsum;
    //  mapを使う関係で < を定義しないといけない (2022/9/25に書き換えたので不要になった)
    // friend bool operator<(const S &l, const S&r) {
    //     return true;
    // }
    // 常に!aliceに遷移する
    vc<S> next_game() {
        auto get = [&](int i) -> vc<int> {
            vc<int> res;
            rep(j, si(v)) {
                if(i == j) continue;
                res.eb(v[j]);
            }
            return res;
        };
        vc<S> ret;
        if(alice) {
            rep(i, si(v)) {
                vc<int> nv = get(i);
                ret.pb(S{nv, !alice, asum + v[i], bsum});
            }
        } else {
            rep(i, si(v)) {
                vc<int> nv = get(i);
                // !aliceであることに注意する
                ret.pb(S{nv, !alice, asum, bsum + v[i]});
            }
        }
        return ret;
    }
    bool win() {
        if(alice) {
            return asum % m != bsum % m;
        } else {
            return asum % m == bsum % m;
        }
    }
    bool end_game() {
        return si(v) == 0;
    }
};
```

のような構造体```S```を定義し，次のようにすると良い

```cpp
int n, m;

// Sの定義

void solve() {
    game<S> gm;
    cin >> n >> m;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; ++ i) {
        cin >> a[i];
    }
    cout << (gm.win(S{a, true, 0, 0}) ? "Alice" : "Bob") << end;
}
```
## コメント

ゲームの問題は実験も大事だけど，実験結果からエスパーするだけでなく，対称戦略などの考察も含めて考えることも忘れないで！

