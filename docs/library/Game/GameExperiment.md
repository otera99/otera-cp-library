---
title: ゲームの実験コードの簡略化
documentation_of: ../../../library/Game/GameExperiment.hpp
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

また，```std::map```を使う関係で```<```を定義しなければいけないことにも注意する

## 例

[ARC148D](https://atcoder.jp/contests/arc148/tasks/arc148_d)の場合

```cpp
struct S {
    vc<int> v;
    bool alice;
    int asum, bsum;
    // mapを使う関係で < を定義しないといけない
    friend bool operator<(const S &l, const S&r) {
        return true;
    }
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
    Game<S> gm;
    cin >> n >> m;
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; ++ i) {
        cin >> a[i];
    }
    cout << (gm.win(S{a, true, 0, 0}) ? "Alice" : "Bob") << end;
}
```

