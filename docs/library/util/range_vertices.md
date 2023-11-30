---
title: 非再帰セグメント木の区間に対応する頂点集合
documentation_of: ../../../library/util/range_vertices.hpp
---

## 概要

長さ$n$の配列に対応する非再帰セグメント木の区間に対応する頂点集合を返す

### 長さ$n$の配列に対応する非再帰セグメント木

```cpp
int 2 * n; // 2n頂点
for(int i = 1; i < n; ++ i) {
    int cl = i<<1|0, cr = i<<1|1;
    // add an edge from i to cl
    // add an edge from i to cr
}

// 配列上のv(セグ木ではv + n)から区間[l, r)に辺を貼るとき
for(int u: range_vertices(n, l, r)) {
    // add an edge from v + n to u
}
```
配列上で$i$番目の要素に、セグメント木上では$i + n$番目の頂点が対応する

## 例

[Codeforces R912F](https://codeforces.com/contest/1903/problem/F)

```cpp
void solve() {
    INT(n, m);
    vc<int> u(m), v(m);
    rep(i, m) {
        in(u[i], v[i]);
        -- u[i], -- v[i];
    }

    auto check = [&](int x) -> bool {
        atcoder::two_sat ts(2 * n);

        for(int i = 1; i < n; ++ i) {
            int cl = i<<1|0, cr = i<<1|1;
            // cl = 1 -> i = 1
            // cl = 0 or i = 1
            ts.add_clause(cl, 0, i, 1);
            ts.add_clause(cr, 0, i, 1);
        }

        rep(i, m) {
            ts.add_clause(u[i] + n, 1, v[i] + n, 1);
        }

        auto add_range_edge = [&](int v, int f1, int l, int r, int f2) -> void {
            for(int u: range_vertices(n, l, r)) {
                ts.add_clause(v, f1, u, f2);
            }
        };
        
        rep(i, n) {
            // i + n = 1 -> (i - x, i) = 0
            // i + n = 0 or (i - x, i) = 0
            add_range_edge(i + n, 0, max(0LL, i - x + 1), i, 0);
            // i + n = 1 -> (i, i + x) = 0
            add_range_edge(i + n, 0, i + 1, min(i + x, n), 0);
        }
        return ts.satisfiable();
    };

    int ok = 0, ng = n + 1;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    out(ok);
}
```

##　参考

[区間に辺を張るテクの実装例（Dijkstra法セット）と使用例 by Lorentさん](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)