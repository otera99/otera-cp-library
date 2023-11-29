---
title: Grundy数の実験コードの簡略化
documentation_of: ../../../library/game/grundy_experiment.hpp
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



