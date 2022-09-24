---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/MergeHistoryForest.hpp
    title: "\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u68EE"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc235/tasks/abc235_Ex
    links:
    - https://atcoder.jp/contests/abc235/submissions/28582201
    - https://atcoder.jp/contests/abc235/tasks/abc235_Ex
  bundledCode: "#line 1 \"test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc235/tasks/abc235_Ex\"\n#define\
    \ VERIFY \"https://atcoder.jp/contests/abc235/submissions/28582201\"\n\n#line\
    \ 1 \"library/DataStructure/MergeHistoryForest.hpp\"\n\n\n\n#include<atcoder/dsu>\n\
    \nnamespace otera {\n    struct MergeHistoryForest {\n        MergeHistoryForest()\
    \ : MergeHistoryForest(0) {}\n        MergeHistoryForest(int n) : _n(n), g(2 *\
    \ n - 1), uf(n), ids(2 * n - 1), root(2 * n - 1), time(2 * n - 1) {\n        \
    \    ite = n;\n            count = 1;\n            for(int i = 0; i < n; ++ i)\
    \ {\n                ids[i] = i;\n                root[i] = true;\n          \
    \  }\n        }\n \n        int node_num() const {\n            return ite;\n\
    \        }\n        const auto& get_dsu() const {\n            return uf;\n  \
    \      }\n        const auto& get_forest() const {\n            return g;\n  \
    \      }\n        auto get_roots() const {\n            std::vector<int> roots;\n\
    \            for(int i = 0; i < 2 * _n - 1; ++ i) {\n                if(root[i])\
    \ {\n                    roots.emplace_back(i);\n                }\n         \
    \   }\n            return roots;\n        }\n \n        void merge(int a, int\
    \ b) {\n            if(uf.same(a, b)) return;\n            int ida = ids[uf.leader(a)],\
    \ idb = ids[uf.leader(b)];\n            root[ida] = root[idb] = false;\n     \
    \       uf.merge(a, b);\n            ids[uf.leader(a)] = ite;\n            root[ite]\
    \ = true;\n            g[ite].emplace_back(ida);\n            g[ite].emplace_back(idb);\n\
    \            ++ ite;\n        }\n \n        void merge_simultaneously(std::vector<std::pair<int,\
    \ int>> edges) {\n            for(auto &[a, b]: edges) {\n                if(!uf.same(a,\
    \ b)) {\n                    int ida = ids[uf.leader(a)], idb = ids[uf.leader(b)];\n\
    \                    if(count == time[ida]) {\n                        if(count\
    \ == time[idb]) {\n                            if((int)g[ida].size() < (int)g[idb].size())\
    \ {\n                                std::swap(a, b);\n                      \
    \          std::swap(ida, idb);\n                            }\n             \
    \               for(int nv: g[idb]) {\n                                g[ida].emplace_back(nv);\n\
    \                            }\n                            root[idb] = false;\n\
    \                            uf.merge(a, b);\n                            ids[uf.leader(a)]\
    \ = ida;\n                        } else {\n                            g[ida].emplace_back(idb);\n\
    \                            root[idb] = false;\n                            uf.merge(a,\
    \ b);\n                            ids[uf.leader(a)] = ida;\n                \
    \        }\n                    } else if(count == time[idb]) {\n            \
    \            g[idb].emplace_back(ida);\n                        root[ida] = false;\n\
    \                        uf.merge(a, b);\n                        ids[uf.leader(a)]\
    \ = idb;\n                    } else {\n                        time[ite] = count;\n\
    \                        merge(a, b);\n                    }\n               \
    \ }\n            }\n            ++ count;\n        }\n \n    private:\n      \
    \  int _n;\n        mutable int ite;\n        mutable int count;\n        std::vector<std::vector<int>>\
    \ g;\n        mutable atcoder::dsu uf;\n        std::vector<int> ids;\n      \
    \  std::vector<bool> root;\n        std::vector<int> time;\n    };\n} // namespace\
    \ otera\n\n\n#line 5 \"test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp\"\
    \n// #include<otera/MergeHistoryForest>\nusing namespace otera;\n\n#include<bits/stdc++.h>\n\
    #include<atcoder/modint>\n#include<atcoder/convolution>\nusing namespace std;\n\
    \nusing ll = long long;\nusing ld = long double;\nusing ull = unsigned long long;\n\
    using uint = unsigned;\n#define repa(i, n) for(int i = 0; i < n; ++ i)\n#define\
    \ repb(i, a, b) for(int i = a; i < b; ++ i)\n#define repc(i, a, b, c) for(int\
    \ i = a; i < b; i += c)\n#define overload4(a, b, c, d, e, ...) e\n#define rep(...)\
    \ overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)\n#define rep1a(i, n) for(int\
    \ i = 0; i <= n; ++ i)\n#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)\n\
    #define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)\n#define rep1(...) overload4(__VA_ARGS__,\
    \ rep1c, rep1b, rep1a)(__VA_ARGS__)\n#define per(i,n) for(int i=n-1;i>=0;i--)\n\
    #define per1(i,n) for(int i=n;i>=1;i--)\ntypedef pair<int, int> P;\ntypedef pair<ll,\
    \ ll> LP;\n#define pb push_back\n#define eb emplace_back\n#define fr first\n#define\
    \ sc second\n#define all(c) c.begin(),c.end()\n#define lb(c, x) distance((c).begin(),\
    \ lower_bound(all(c), (x)))\n#define ub(c, x) distance((c).begin(), upper_bound(all(c),\
    \ (x)))\n#define Sort(a) sort(all(a))\n#define Rev(a) reverse(all(a))\n#define\
    \ Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))\n#define si(c) (int)(c).size()\n\
    inline ll popcnt(ull a){ return __builtin_popcountll(a); }\n#define tpow(n) (1LL<<(n))\n\
    #define unless(A) if(!(A))\nll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b\
    \ & 1) ans *= a; a *= a; b /= 2; } return ans; }\nll intpow(ll a, ll b, ll m)\
    \ {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return\
    \ ans; }\ntemplate<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b;\
    \ return 1; } return 0; }\ntemplate<class T> inline bool chmin(T& a, T b) { if\
    \ (a > b) { a = b; return 1; } return 0; }\n#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)\n#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__;in(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)\n\
    #define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)\n\
    #define vec(type,name,...) vector<type>name(__VA_ARGS__)\n#define VEC(type,name,size)\
    \ vector<type>name(size);in(name)\n#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))\n\
    #define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)\n\
    #define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))\n\
    template <class T> using vc = vector<T>;\ntemplate <class T> using vvc = vector<vc<T>>;\n\
    template <class T> using vvvc = vector<vvc<T>>;\ntemplate <class T> using vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T> using pq = priority_queue<T>;\ntemplate\
    \ <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\ntemplate<class\
    \ T> void scan(T& a){ cin >> a; }\ntemplate<class T> void scan(vector<T>& a){\
    \ for(auto&& i : a) scan(i); }\nvoid in(){}\ntemplate <class Head, class... Tail>\
    \ void in(Head& head, Tail&... tail){ scan(head); in(tail...); }\nvoid print(){\
    \ cout << ' '; }\ntemplate<class T> void print(const T& a){ cout << a; }\ntemplate<class\
    \ T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto\
    \ i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }\nint out(){ cout\
    \ << '\\n'; return 0; }\ntemplate<class T> int out(const T& t){ print(t); cout\
    \ << '\\n'; return 0; }\ntemplate<class Head, class... Tail> int out(const Head&\
    \ head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0;\
    \ }\n#define CHOOSE(a) CHOOSE2 a\n#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x\n#define\
    \ debug_1(x1) cout<<#x1<<\": \"<<x1<<endl\n#define debug_2(x1,x2) cout<<#x1<<\"\
    : \"<<x1<<\", \"#x2<<\": \"<<x2<<endl\n#define debug_3(x1,x2,x3) cout<<#x1<<\"\
    : \"<<x1<<\", \"#x2<<\": \"<<x2<<\", \"#x3<<\": \"<<x3<<endl\n#define debug_4(x1,x2,x3,x4)\
    \ cout<<#x1<<\": \"<<x1<<\", \"#x2<<\": \"<<x2<<\", \"#x3<<\": \"<<x3<<\", \"\
    #x4<<\": \"<<x4<<endl\n#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<\": \"<<x1<<\"\
    , \"#x2<<\": \"<<x2<<\", \"#x3<<\": \"<<x3<<\", \"#x4<<\": \"<<x4<<\", \"#x5<<\"\
    : \"<<x5<<endl\n#ifdef DEBUG\n#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)\n\
    #define dump(...) { print(#__VA_ARGS__); print(\":\"); out(__VA_ARGS__); }\n#else\n\
    #define debug(...)\n#define dump(...)\n#endif\n\nusing mint = atcoder::modint998244353;\n\
    \ntypedef pair<ll, P> P2;\n\nvoid solve() {\n    INT(n, m, k);\n    map<int, vc<P>>\
    \ mp;\n    rep(i, m) {\n        INT(a, b); -- a, -- b; LL(c);\n        mp[c].eb(a,\
    \ b);\n    }\n    MergeHistoryForest uf(n);\n    for(auto &[c, es]: mp) {\n  \
    \      uf.merge_simultaneously(es);\n    }\n    vvc<mint> dp(2 * n - 1);\n   \
    \ vvc<int> g = uf.get_forest();\n    auto dfs = [&](auto&&dfs, int v) -> void\
    \ {\n        if(g[v].empty()) {\n            dp[v] = {1, 1};\n            return;\n\
    \        }\n        for(int nv: g[v]) dfs(dfs, nv);\n        int sv = g[v][0];\n\
    \        vc<mint> dp2 = dp[sv], ndp2;\n        int cnt = 1;\n        rep(i, si(g[v]))\
    \ {\n            if(i == 0) continue;\n            int nv = g[v][i];\n       \
    \     int sz = si(dp2);\n            int sz2 = min({sz + si(dp[nv]) - 1, k + 1});\n\
    \            ndp2.assign(sz2, 0);\n            rep(i, si(dp[nv])) {\n        \
    \        rep(j, sz) {\n                    if(i + j > k) break;\n            \
    \        ndp2[i + j] += dp[nv][i] * dp2[j];\n                }\n            }\n\
    \            ++ cnt;\n            swap(dp2, ndp2);\n        }\n        dp2[1]\
    \ ++;\n        dp2[cnt] --;\n        dp[v] = dp2;\n        return;\n    };\n \
    \   vc<mint> now = {1};\n    for(int i: uf.get_roots()) {\n        dfs(dfs, i);\n\
    \        now = atcoder::convolution(now, dp[i]);\n        if(si(now) > k) now.resize(k\
    \ + 1);\n    }\n    mint ans = 0;\n    for(int i = 0; i <= min(k, si(now) - 1);\
    \ ++ i) {\n        ans += now[i];\n    }\n    out(ans.val());\n}\n\nsigned main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    // cout << fixed <<\
    \ setprecision(20);\n    // INT(t); rep(i, t)solve();\n    solve();\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc235/tasks/abc235_Ex\"\n\
    #define VERIFY \"https://atcoder.jp/contests/abc235/submissions/28582201\"\n\n\
    #include\"library/DataStructure/MergeHistoryForest.hpp\"\n// #include<otera/MergeHistoryForest>\n\
    using namespace otera;\n\n#include<bits/stdc++.h>\n#include<atcoder/modint>\n\
    #include<atcoder/convolution>\nusing namespace std;\n\nusing ll = long long;\n\
    using ld = long double;\nusing ull = unsigned long long;\nusing uint = unsigned;\n\
    #define repa(i, n) for(int i = 0; i < n; ++ i)\n#define repb(i, a, b) for(int\
    \ i = a; i < b; ++ i)\n#define repc(i, a, b, c) for(int i = a; i < b; i += c)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define rep(...) overload4(__VA_ARGS__,\
    \ repc, repb, repa)(__VA_ARGS__)\n#define rep1a(i, n) for(int i = 0; i <= n; ++\
    \ i)\n#define rep1b(i, a, b) for(int i = a; i <= b; ++ i)\n#define rep1c(i, a,\
    \ b, c) for(int i = a; i <= b; i += c)\n#define rep1(...) overload4(__VA_ARGS__,\
    \ rep1c, rep1b, rep1a)(__VA_ARGS__)\n#define per(i,n) for(int i=n-1;i>=0;i--)\n\
    #define per1(i,n) for(int i=n;i>=1;i--)\ntypedef pair<int, int> P;\ntypedef pair<ll,\
    \ ll> LP;\n#define pb push_back\n#define eb emplace_back\n#define fr first\n#define\
    \ sc second\n#define all(c) c.begin(),c.end()\n#define lb(c, x) distance((c).begin(),\
    \ lower_bound(all(c), (x)))\n#define ub(c, x) distance((c).begin(), upper_bound(all(c),\
    \ (x)))\n#define Sort(a) sort(all(a))\n#define Rev(a) reverse(all(a))\n#define\
    \ Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))\n#define si(c) (int)(c).size()\n\
    inline ll popcnt(ull a){ return __builtin_popcountll(a); }\n#define tpow(n) (1LL<<(n))\n\
    #define unless(A) if(!(A))\nll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b\
    \ & 1) ans *= a; a *= a; b /= 2; } return ans; }\nll intpow(ll a, ll b, ll m)\
    \ {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return\
    \ ans; }\ntemplate<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b;\
    \ return 1; } return 0; }\ntemplate<class T> inline bool chmin(T& a, T b) { if\
    \ (a > b) { a = b; return 1; } return 0; }\n#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)\n#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__;in(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)\n\
    #define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)\n\
    #define vec(type,name,...) vector<type>name(__VA_ARGS__)\n#define VEC(type,name,size)\
    \ vector<type>name(size);in(name)\n#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))\n\
    #define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)\n\
    #define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))\n\
    template <class T> using vc = vector<T>;\ntemplate <class T> using vvc = vector<vc<T>>;\n\
    template <class T> using vvvc = vector<vvc<T>>;\ntemplate <class T> using vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T> using pq = priority_queue<T>;\ntemplate\
    \ <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\ntemplate<class\
    \ T> void scan(T& a){ cin >> a; }\ntemplate<class T> void scan(vector<T>& a){\
    \ for(auto&& i : a) scan(i); }\nvoid in(){}\ntemplate <class Head, class... Tail>\
    \ void in(Head& head, Tail&... tail){ scan(head); in(tail...); }\nvoid print(){\
    \ cout << ' '; }\ntemplate<class T> void print(const T& a){ cout << a; }\ntemplate<class\
    \ T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto\
    \ i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }\nint out(){ cout\
    \ << '\\n'; return 0; }\ntemplate<class T> int out(const T& t){ print(t); cout\
    \ << '\\n'; return 0; }\ntemplate<class Head, class... Tail> int out(const Head&\
    \ head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0;\
    \ }\n#define CHOOSE(a) CHOOSE2 a\n#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x\n#define\
    \ debug_1(x1) cout<<#x1<<\": \"<<x1<<endl\n#define debug_2(x1,x2) cout<<#x1<<\"\
    : \"<<x1<<\", \"#x2<<\": \"<<x2<<endl\n#define debug_3(x1,x2,x3) cout<<#x1<<\"\
    : \"<<x1<<\", \"#x2<<\": \"<<x2<<\", \"#x3<<\": \"<<x3<<endl\n#define debug_4(x1,x2,x3,x4)\
    \ cout<<#x1<<\": \"<<x1<<\", \"#x2<<\": \"<<x2<<\", \"#x3<<\": \"<<x3<<\", \"\
    #x4<<\": \"<<x4<<endl\n#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<\": \"<<x1<<\"\
    , \"#x2<<\": \"<<x2<<\", \"#x3<<\": \"<<x3<<\", \"#x4<<\": \"<<x4<<\", \"#x5<<\"\
    : \"<<x5<<endl\n#ifdef DEBUG\n#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)\n\
    #define dump(...) { print(#__VA_ARGS__); print(\":\"); out(__VA_ARGS__); }\n#else\n\
    #define debug(...)\n#define dump(...)\n#endif\n\nusing mint = atcoder::modint998244353;\n\
    \ntypedef pair<ll, P> P2;\n\nvoid solve() {\n    INT(n, m, k);\n    map<int, vc<P>>\
    \ mp;\n    rep(i, m) {\n        INT(a, b); -- a, -- b; LL(c);\n        mp[c].eb(a,\
    \ b);\n    }\n    MergeHistoryForest uf(n);\n    for(auto &[c, es]: mp) {\n  \
    \      uf.merge_simultaneously(es);\n    }\n    vvc<mint> dp(2 * n - 1);\n   \
    \ vvc<int> g = uf.get_forest();\n    auto dfs = [&](auto&&dfs, int v) -> void\
    \ {\n        if(g[v].empty()) {\n            dp[v] = {1, 1};\n            return;\n\
    \        }\n        for(int nv: g[v]) dfs(dfs, nv);\n        int sv = g[v][0];\n\
    \        vc<mint> dp2 = dp[sv], ndp2;\n        int cnt = 1;\n        rep(i, si(g[v]))\
    \ {\n            if(i == 0) continue;\n            int nv = g[v][i];\n       \
    \     int sz = si(dp2);\n            int sz2 = min({sz + si(dp[nv]) - 1, k + 1});\n\
    \            ndp2.assign(sz2, 0);\n            rep(i, si(dp[nv])) {\n        \
    \        rep(j, sz) {\n                    if(i + j > k) break;\n            \
    \        ndp2[i + j] += dp[nv][i] * dp2[j];\n                }\n            }\n\
    \            ++ cnt;\n            swap(dp2, ndp2);\n        }\n        dp2[1]\
    \ ++;\n        dp2[cnt] --;\n        dp[v] = dp2;\n        return;\n    };\n \
    \   vc<mint> now = {1};\n    for(int i: uf.get_roots()) {\n        dfs(dfs, i);\n\
    \        now = atcoder::convolution(now, dp[i]);\n        if(si(now) > k) now.resize(k\
    \ + 1);\n    }\n    mint ans = 0;\n    for(int i = 0; i <= min(k, si(now) - 1);\
    \ ++ i) {\n        ans += now[i];\n    }\n    out(ans.val());\n}\n\nsigned main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    // cout << fixed <<\
    \ setprecision(20);\n    // INT(t); rep(i, t)solve();\n    solve();\n    return\
    \ 0;\n}"
  dependsOn:
  - library/DataStructure/MergeHistoryForest.hpp
  isVerificationFile: true
  path: test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp
  requiredBy: []
  timestamp: '2022-09-24 19:32:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp
layout: document
redirect_from:
- /verify/test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp
- /verify/test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp.html
title: test/src/DataStructure/MergeHistoryForest/MergeHistoryForest.test.cpp
---
