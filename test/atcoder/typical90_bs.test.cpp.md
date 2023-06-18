---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: library/graph/graph.hpp
  - icon: ':x:'
    path: library/graph/topological_sort.hpp
    title: library/graph/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/typical90/tasks/typical90_071
    links:
    - https://atcoder.jp/contests/typical90/tasks/typical90_071
  bundledCode: "#line 1 \"test/atcoder/typical90_bs.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/typical90/tasks/typical90_071\"\n#include<bits/stdc++.h>\n\
    #include<library/graph/graph.hpp>\n#include<library/graph/topological_sort.hpp>\n\
    \nnamespace otera {}\nusing namespace std;\nusing namespace otera;\n\nstruct io_setup\
    \ {\n    io_setup(int precision = 20) {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(precision);\n    }\n\
    } io_setup_ {};\n\nusing ll = long long;\nusing ld = long double;\nusing ull =\
    \ unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n#define\
    \ repa(i, n) for(int i = 0; i < n; ++ i)\n#define repb(i, a, b) for(int i = a;\
    \ i < b; ++ i)\n#define repc(i, a, b, c) for(int i = a; i < b; i += c)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)\n#define rep1a(i,\
    \ n) for(int i = 0; i <= n; ++ i)\n#define rep1b(i, a, b) for(int i = a; i <=\
    \ b; ++ i)\n#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)\n#define\
    \ rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)\n#define\
    \ rev_repa(i, n) for(int i=n-1;i>=0;i--)\n#define rev_repb(i, a, b) assert(a >\
    \ b);for(int i=a;i>b;i--)\n#define rev_rep(...) overload3(__VA_ARGS__, rev_repb,\
    \ rev_repa)(__VA_ARGS__)\n#define rev_rep1a(i, n) for(int i=n;i>=1;i--)\n#define\
    \ rev_rep1b(i, a, b) assert(a >= b);for(int i=a;i>=b;i--)\n#define rev_rep1(...)\
    \ overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)\n#define for_subset(t,\
    \ s) for(ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))\ntypedef pair<int,\
    \ int> P;\ntypedef pair<ll, ll> LP;\n#define pb push_back\n#define pf push_front\n\
    #define ppb pop_back\n#define ppf pop_front\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fr first\n#define sc second\n#define\
    \ all(c) c.begin(),c.end()\n#define rall(c) c.rbegin(), c.rend()\n#define lb(c,\
    \ x) distance((c).begin(), lower_bound(all(c), (x)))\n#define ub(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define Sort(a) sort(all(a))\n#define Rev(a) reverse(all(a))\n\
    #define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))\n#define si(c) (int)(c).size()\n\
    inline ll popcnt(ull a){ return __builtin_popcountll(a); }\n#define kth_bit(x,\
    \ k) ((x>>k)&1)\n#define unless(A) if(!(A))\n#define elif else if\nll modulo(ll\
    \ n, ll d){ return (n % d + d) % d; };\nll intpow(ll a, ll b){ ll ans = 1; while(b){\
    \ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }\nll intpow(ll a, ll b, ll\
    \ m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2;\
    \ } return ans; }\ntemplate<class T> inline bool chmax(T& a, T b) { if (a < b)\
    \ { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T& a,\
    \ T b) { if (a > b) { a = b; return 1; } return 0; }\n#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n\
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
    \ <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\ntemplate <class\
    \ T, class U> using umap = unordered_map<T, U>;\ntemplate<class T> void scan(T&\
    \ a){ cin >> a; }\ntemplate<class T> void scan(vector<T>& a){ for(auto&& i : a)\
    \ scan(i); }\nvoid in(){}\ntemplate <class Head, class... Tail> void in(Head&\
    \ head, Tail&... tail){ scan(head); in(tail...); }\nvoid print(){ cout << ' ';\
    \ }\ntemplate<class T> void print(const T& a){ cout << a; }\ntemplate<class T>\
    \ void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto\
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
    #define debug(...)\n#define dump(...)\n#endif\n\nvoid solve() {\n    INT(n, m,\
    \ k);\n    graph<int> g(n, 1);\n    g.read_directed_graph(m);\n    topological_sort<graph<int>>\
    \ tpo(g);\n    auto vs = tpo.sorted();\n    dump(vs);\n    if(!tpo.is_dag()) {\n\
    \        out(-1);\n        return;\n    }\n    vc<int> in_deg(n);\n    rep(i,\
    \ n) {\n        for(auto e: g[i]) {\n            in_deg[e.to] ++;\n        }\n\
    \    }\n    vvc<int> ans;\n    vc<int> que;\n    rep(i, n) {\n        if(in_deg[i]\
    \ == 0) que.push_back(i);\n    }\n    vc<int> ord;\n    auto dfs = [&](auto&&dfs)\
    \ -> void {\n        if(si(ans) >= k) return;\n        int sz = si(que);\n   \
    \     if(sz == 0 and si(ans) < k) {\n            ans.eb(ord);\n            return;\n\
    \        }\n        rep(i, sz) {\n            int v = que[i];\n            ord.push_back(v);\n\
    \            swap(que[i], que.back());\n            que.pop_back();\n        \
    \    for(auto e: g[v]) {\n                int nv = e.to;\n                if(--\
    \ in_deg[nv] == 0) que.push_back(nv);\n            }\n            dfs(dfs);\n\
    \            if(si(ans) >= k) return;\n            for(auto e: g[v]) {\n     \
    \           int nv = e.to;\n                if(in_deg[nv] ++ == 0) que.pop_back();\n\
    \            }\n            que.push_back(v);\n            ord.pop_back();\n \
    \           swap(que[i], que.back());\n        }\n    };\n    dfs(dfs);\n    if(si(ans)\
    \ < k) {\n        out(-1);\n        return;\n    }\n    for(auto vs: ans) {\n\
    \        for(auto& v: vs) ++ v;\n        out(vs);\n    }\n}\n\nsigned main() {\n\
    \    int testcase = 1;\n    // in(testcase);\n    while(testcase--) solve();\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/typical90/tasks/typical90_071\"\
    \n#include<bits/stdc++.h>\n#include<library/graph/graph.hpp>\n#include<library/graph/topological_sort.hpp>\n\
    \nnamespace otera {}\nusing namespace std;\nusing namespace otera;\n\nstruct io_setup\
    \ {\n    io_setup(int precision = 20) {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(precision);\n    }\n\
    } io_setup_ {};\n\nusing ll = long long;\nusing ld = long double;\nusing ull =\
    \ unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n#define\
    \ repa(i, n) for(int i = 0; i < n; ++ i)\n#define repb(i, a, b) for(int i = a;\
    \ i < b; ++ i)\n#define repc(i, a, b, c) for(int i = a; i < b; i += c)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)\n#define rep1a(i,\
    \ n) for(int i = 0; i <= n; ++ i)\n#define rep1b(i, a, b) for(int i = a; i <=\
    \ b; ++ i)\n#define rep1c(i, a, b, c) for(int i = a; i <= b; i += c)\n#define\
    \ rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)\n#define\
    \ rev_repa(i, n) for(int i=n-1;i>=0;i--)\n#define rev_repb(i, a, b) assert(a >\
    \ b);for(int i=a;i>b;i--)\n#define rev_rep(...) overload3(__VA_ARGS__, rev_repb,\
    \ rev_repa)(__VA_ARGS__)\n#define rev_rep1a(i, n) for(int i=n;i>=1;i--)\n#define\
    \ rev_rep1b(i, a, b) assert(a >= b);for(int i=a;i>=b;i--)\n#define rev_rep1(...)\
    \ overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)\n#define for_subset(t,\
    \ s) for(ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))\ntypedef pair<int,\
    \ int> P;\ntypedef pair<ll, ll> LP;\n#define pb push_back\n#define pf push_front\n\
    #define ppb pop_back\n#define ppf pop_front\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fr first\n#define sc second\n#define\
    \ all(c) c.begin(),c.end()\n#define rall(c) c.rbegin(), c.rend()\n#define lb(c,\
    \ x) distance((c).begin(), lower_bound(all(c), (x)))\n#define ub(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define Sort(a) sort(all(a))\n#define Rev(a) reverse(all(a))\n\
    #define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))\n#define si(c) (int)(c).size()\n\
    inline ll popcnt(ull a){ return __builtin_popcountll(a); }\n#define kth_bit(x,\
    \ k) ((x>>k)&1)\n#define unless(A) if(!(A))\n#define elif else if\nll modulo(ll\
    \ n, ll d){ return (n % d + d) % d; };\nll intpow(ll a, ll b){ ll ans = 1; while(b){\
    \ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }\nll intpow(ll a, ll b, ll\
    \ m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2;\
    \ } return ans; }\ntemplate<class T> inline bool chmax(T& a, T b) { if (a < b)\
    \ { a = b; return 1; } return 0; }\ntemplate<class T> inline bool chmin(T& a,\
    \ T b) { if (a > b) { a = b; return 1; } return 0; }\n#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n\
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
    \ <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;\ntemplate <class\
    \ T, class U> using umap = unordered_map<T, U>;\ntemplate<class T> void scan(T&\
    \ a){ cin >> a; }\ntemplate<class T> void scan(vector<T>& a){ for(auto&& i : a)\
    \ scan(i); }\nvoid in(){}\ntemplate <class Head, class... Tail> void in(Head&\
    \ head, Tail&... tail){ scan(head); in(tail...); }\nvoid print(){ cout << ' ';\
    \ }\ntemplate<class T> void print(const T& a){ cout << a; }\ntemplate<class T>\
    \ void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto\
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
    #define debug(...)\n#define dump(...)\n#endif\n\nvoid solve() {\n    INT(n, m,\
    \ k);\n    graph<int> g(n, 1);\n    g.read_directed_graph(m);\n    topological_sort<graph<int>>\
    \ tpo(g);\n    auto vs = tpo.sorted();\n    dump(vs);\n    if(!tpo.is_dag()) {\n\
    \        out(-1);\n        return;\n    }\n    vc<int> in_deg(n);\n    rep(i,\
    \ n) {\n        for(auto e: g[i]) {\n            in_deg[e.to] ++;\n        }\n\
    \    }\n    vvc<int> ans;\n    vc<int> que;\n    rep(i, n) {\n        if(in_deg[i]\
    \ == 0) que.push_back(i);\n    }\n    vc<int> ord;\n    auto dfs = [&](auto&&dfs)\
    \ -> void {\n        if(si(ans) >= k) return;\n        int sz = si(que);\n   \
    \     if(sz == 0 and si(ans) < k) {\n            ans.eb(ord);\n            return;\n\
    \        }\n        rep(i, sz) {\n            int v = que[i];\n            ord.push_back(v);\n\
    \            swap(que[i], que.back());\n            que.pop_back();\n        \
    \    for(auto e: g[v]) {\n                int nv = e.to;\n                if(--\
    \ in_deg[nv] == 0) que.push_back(nv);\n            }\n            dfs(dfs);\n\
    \            if(si(ans) >= k) return;\n            for(auto e: g[v]) {\n     \
    \           int nv = e.to;\n                if(in_deg[nv] ++ == 0) que.pop_back();\n\
    \            }\n            que.push_back(v);\n            ord.pop_back();\n \
    \           swap(que[i], que.back());\n        }\n    };\n    dfs(dfs);\n    if(si(ans)\
    \ < k) {\n        out(-1);\n        return;\n    }\n    for(auto vs: ans) {\n\
    \        for(auto& v: vs) ++ v;\n        out(vs);\n    }\n}\n\nsigned main() {\n\
    \    int testcase = 1;\n    // in(testcase);\n    while(testcase--) solve();\n\
    \    return 0;\n}"
  dependsOn:
  - library/graph/graph.hpp
  - library/graph/topological_sort.hpp
  isVerificationFile: true
  path: test/atcoder/typical90_bs.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 12:48:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/typical90_bs.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/typical90_bs.test.cpp
- /verify/test/atcoder/typical90_bs.test.cpp.html
title: test/atcoder/typical90_bs.test.cpp
---
