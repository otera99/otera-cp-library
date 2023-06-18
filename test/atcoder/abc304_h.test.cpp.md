---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graph/graph.hpp
    title: library/graph/graph.hpp
  - icon: ':x:'
    path: library/graph/reverse_graph.hpp
    title: library/graph/reverse_graph.hpp
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
    links: []
  bundledCode: "#line 1 \"test/atcoder/abc304_h.test.cpp\"\n/**\n *    author:  otera\n\
    **/\n#include<bits/stdc++.h>\n#include<library/graph/graph.hpp>\n#include<library/graph/topological_sort.hpp>\n\
    #include<library/graph/reverse_graph.hpp>\n\nnamespace otera {}\nusing namespace\
    \ std;\nusing namespace otera;\n\nstruct io_setup {\n    io_setup(int precision\
    \ = 20) {\n        ios::sync_with_stdio(false);\n        cin.tie(0);\n       \
    \ cout << fixed << setprecision(precision);\n    }\n} io_setup_ {};\n\n#define\
    \ int long long\n\nusing ll = long long;\nusing ld = long double;\nusing ull =\
    \ unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n#define\
    \ repa(i, n) for(int i = 0; i < (n); ++ i)\n#define repb(i, a, b) for(int i =\
    \ (a); i < (b); ++ i)\n#define repc(i, a, b, c) for(int i = (a); i < (b); i +=\
    \ (c))\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d,\
    \ ...) d\n#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)\n\
    #define rep1a(i, n) for(int i = 0; i <= (n); ++ i)\n#define rep1b(i, a, b) for(int\
    \ i = (a); i <= (b); ++ i)\n#define rep1c(i, a, b, c) for(int i = (a); i <= (b);\
    \ i += (c))\n#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)\n\
    #define rev_repa(i, n) for(int i=(n)-1;i>=0;i--)\n#define rev_repb(i, a, b) assert((a)\
    \ > (b));for(int i=(a);i>(b);i--)\n#define rev_rep(...) overload3(__VA_ARGS__,\
    \ rev_repb, rev_repa)(__VA_ARGS__)\n#define rev_rep1a(i, n) for(int i=(n);i>=1;i--)\n\
    #define rev_rep1b(i, a, b) assert((a) >= (b));for(int i=(a);i>=(b);i--)\n#define\
    \ rev_rep1(...) overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)\n#define\
    \ for_subset(t, s) for(ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    typedef pair<int, int> P;\ntypedef pair<ll, ll> LP;\n#define pb push_back\n#define\
    \ pf push_front\n#define ppb pop_back\n#define ppf pop_front\n#define eb emplace_back\n\
    #define mkp make_pair\n#define mkt make_tuple\n#define fr first\n#define sc second\n\
    #define all(c) std::begin(c), std::end(c)\n#define rall(c) std::rbegin(c), std::rend(c)\n\
    #define lb(c, x) distance(std::begin(c), lower_bound(all(c), (x)))\n#define ub(c,\
    \ x) distance(std::begin(c), upper_bound(all(c), (x)))\n#define Sort(a) sort(all(a))\n\
    #define Rev(a) reverse(all(a))\n#define Uniq(a) sort(all(a));(a).erase(unique(all(a)),std::end(a))\n\
    #define si(c) (int)(c).size()\ninline ll popcnt(ull a){ return __builtin_popcountll(a);\
    \ }\n#define kth_bit(x, k) ((x>>k)&1)\n#define unless(A) if(!(A))\n#define elif\
    \ else if\nll modulo(ll n, ll d){ return (n % d + d) % d; };\nll intpow(ll a,\
    \ ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans;\
    \ }\nll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %=\
    \ m; (a *= a) %= m; b /= 2; } return ans; }\ntemplate<class T> inline bool chmax(T&\
    \ a, T b) { if (a < b) { a = b; return 1; } return 0; }\ntemplate<class T> inline\
    \ bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }\n#define\
    \ INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)\n\
    #define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)\n#define vec(type,name,...) vector<type>name(__VA_ARGS__)\n\
    #define VEC(type,name,size) vector<type>name(size);in(name)\n#define vv(type,name,h,...)\
    \ vector<vector<type>>name(h,vector<type>(__VA_ARGS__))\n#define VV(type,name,h,w)\
    \ vector<vector<type>>name(h,vector<type>(w));in(name)\n#define vvv(type,name,h,w,...)\
    \ vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))\n\
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
    #define debug(...)\n#define dump(...)\n#endif\n\nvoid solve() {\n    INT(n, m);\n\
    \    graph g(n, 1);\n    g.read_directed_graph(m);\n    auto rg = reverse_graph(g);\n\
    \    vc<int> l(n), r(n);\n    rep(i, n) {\n        in(l[i], r[i]);\n        --\
    \ l[i], -- r[i];\n    }\n    topological_sort tpo(g);\n    if(!tpo.is_dag()) {\n\
    \        out(\"No\");\n        return;\n    }\n    auto li = tpo.sorted();\n \
    \   // for(int v: li) {\n    //     for(int nv: g[v]) {\n    //         chmax(l[nv],\
    \ l[v] + 1);\n    //     }\n    // }\n    Rev(li);\n    dump(li);\n    for(int\
    \ v: li) {\n        for(int nv: rg[v]) {\n            debug(v, nv);\n        \
    \    chmin(r[nv], r[v] - 1);\n        }\n    }\n    vvc<int> vs(n);\n    vc<int>\
    \ p(n, -1);\n    rep(v, n) {\n        if(l[v] > r[v]) {\n            out(\"No\"\
    );\n            return;\n        }\n        vs[l[v]].eb(v);\n    }\n    pqg<P>\
    \ pque;\n    vc<int> sz(n, 0);\n    rep(v, n) {\n        sz[v] = rg.deg(v);\n\
    \    }\n    vc<int> end(n, 0);\n    dump(l);\n    dump(r);\n    rep(i, n) {\n\
    \        for(int v: vs[i]) {\n            if(sz[v] == 0 and !end[v]) {\n     \
    \           pque.emplace(r[v], v);\n                end[v] = 1;\n            }\n\
    \        }\n        debug(si(pque));\n        if(pque.empty()) {\n           \
    \ out(\"No\");\n            return;\n        } else {\n            auto [val,\
    \ v] = pque.top(); pque.pop();\n            debug(val, v);\n            if(i >\
    \ val) {\n                out(\"No\");\n                return;\n            }\n\
    \            p[v] = i;\n            for(int nv: g[v]) {\n                -- sz[nv];\n\
    \                if(sz[nv] == 0 and l[nv] <= i and !end[nv]) {\n             \
    \       pque.emplace(r[nv], nv);\n                    end[nv] = 1;\n         \
    \       }\n            }\n        }\n    }\n    out(\"Yes\");\n    for(auto& x:\
    \ p) ++ x;\n    out(p);\n}\n\nsigned main() {\n    int testcase = 1;\n    // in(testcase);\n\
    \    while(testcase--) solve();\n    return 0;\n}\n"
  code: "/**\n *    author:  otera\n**/\n#include<bits/stdc++.h>\n#include<library/graph/graph.hpp>\n\
    #include<library/graph/topological_sort.hpp>\n#include<library/graph/reverse_graph.hpp>\n\
    \nnamespace otera {}\nusing namespace std;\nusing namespace otera;\n\nstruct io_setup\
    \ {\n    io_setup(int precision = 20) {\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(0);\n        cout << fixed << setprecision(precision);\n    }\n\
    } io_setup_ {};\n\n#define int long long\n\nusing ll = long long;\nusing ld =\
    \ long double;\nusing ull = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n#define repa(i, n) for(int i = 0; i < (n); ++ i)\n#define\
    \ repb(i, a, b) for(int i = (a); i < (b); ++ i)\n#define repc(i, a, b, c) for(int\
    \ i = (a); i < (b); i += (c))\n#define overload4(a, b, c, d, e, ...) e\n#define\
    \ overload3(a, b, c, d, ...) d\n#define rep(...) overload4(__VA_ARGS__, repc,\
    \ repb, repa)(__VA_ARGS__)\n#define rep1a(i, n) for(int i = 0; i <= (n); ++ i)\n\
    #define rep1b(i, a, b) for(int i = (a); i <= (b); ++ i)\n#define rep1c(i, a, b,\
    \ c) for(int i = (a); i <= (b); i += (c))\n#define rep1(...) overload4(__VA_ARGS__,\
    \ rep1c, rep1b, rep1a)(__VA_ARGS__)\n#define rev_repa(i, n) for(int i=(n)-1;i>=0;i--)\n\
    #define rev_repb(i, a, b) assert((a) > (b));for(int i=(a);i>(b);i--)\n#define\
    \ rev_rep(...) overload3(__VA_ARGS__, rev_repb, rev_repa)(__VA_ARGS__)\n#define\
    \ rev_rep1a(i, n) for(int i=(n);i>=1;i--)\n#define rev_rep1b(i, a, b) assert((a)\
    \ >= (b));for(int i=(a);i>=(b);i--)\n#define rev_rep1(...) overload3(__VA_ARGS__,\
    \ rev_rep1b, rev_rep1a)(__VA_ARGS__)\n#define for_subset(t, s) for(ll t = (s);\
    \ t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\ntypedef pair<int, int> P;\ntypedef\
    \ pair<ll, ll> LP;\n#define pb push_back\n#define pf push_front\n#define ppb pop_back\n\
    #define ppf pop_front\n#define eb emplace_back\n#define mkp make_pair\n#define\
    \ mkt make_tuple\n#define fr first\n#define sc second\n#define all(c) std::begin(c),\
    \ std::end(c)\n#define rall(c) std::rbegin(c), std::rend(c)\n#define lb(c, x)\
    \ distance(std::begin(c), lower_bound(all(c), (x)))\n#define ub(c, x) distance(std::begin(c),\
    \ upper_bound(all(c), (x)))\n#define Sort(a) sort(all(a))\n#define Rev(a) reverse(all(a))\n\
    #define Uniq(a) sort(all(a));(a).erase(unique(all(a)),std::end(a))\n#define si(c)\
    \ (int)(c).size()\ninline ll popcnt(ull a){ return __builtin_popcountll(a); }\n\
    #define kth_bit(x, k) ((x>>k)&1)\n#define unless(A) if(!(A))\n#define elif else\
    \ if\nll modulo(ll n, ll d){ return (n % d + d) % d; };\nll intpow(ll a, ll b){\
    \ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }\n\
    ll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m;\
    \ (a *= a) %= m; b /= 2; } return ans; }\ntemplate<class T> inline bool chmax(T&\
    \ a, T b) { if (a < b) { a = b; return 1; } return 0; }\ntemplate<class T> inline\
    \ bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }\n#define\
    \ INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)\n\
    #define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)\n#define vec(type,name,...) vector<type>name(__VA_ARGS__)\n\
    #define VEC(type,name,size) vector<type>name(size);in(name)\n#define vv(type,name,h,...)\
    \ vector<vector<type>>name(h,vector<type>(__VA_ARGS__))\n#define VV(type,name,h,w)\
    \ vector<vector<type>>name(h,vector<type>(w));in(name)\n#define vvv(type,name,h,w,...)\
    \ vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))\n\
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
    #define debug(...)\n#define dump(...)\n#endif\n\nvoid solve() {\n    INT(n, m);\n\
    \    graph g(n, 1);\n    g.read_directed_graph(m);\n    auto rg = reverse_graph(g);\n\
    \    vc<int> l(n), r(n);\n    rep(i, n) {\n        in(l[i], r[i]);\n        --\
    \ l[i], -- r[i];\n    }\n    topological_sort tpo(g);\n    if(!tpo.is_dag()) {\n\
    \        out(\"No\");\n        return;\n    }\n    auto li = tpo.sorted();\n \
    \   // for(int v: li) {\n    //     for(int nv: g[v]) {\n    //         chmax(l[nv],\
    \ l[v] + 1);\n    //     }\n    // }\n    Rev(li);\n    dump(li);\n    for(int\
    \ v: li) {\n        for(int nv: rg[v]) {\n            debug(v, nv);\n        \
    \    chmin(r[nv], r[v] - 1);\n        }\n    }\n    vvc<int> vs(n);\n    vc<int>\
    \ p(n, -1);\n    rep(v, n) {\n        if(l[v] > r[v]) {\n            out(\"No\"\
    );\n            return;\n        }\n        vs[l[v]].eb(v);\n    }\n    pqg<P>\
    \ pque;\n    vc<int> sz(n, 0);\n    rep(v, n) {\n        sz[v] = rg.deg(v);\n\
    \    }\n    vc<int> end(n, 0);\n    dump(l);\n    dump(r);\n    rep(i, n) {\n\
    \        for(int v: vs[i]) {\n            if(sz[v] == 0 and !end[v]) {\n     \
    \           pque.emplace(r[v], v);\n                end[v] = 1;\n            }\n\
    \        }\n        debug(si(pque));\n        if(pque.empty()) {\n           \
    \ out(\"No\");\n            return;\n        } else {\n            auto [val,\
    \ v] = pque.top(); pque.pop();\n            debug(val, v);\n            if(i >\
    \ val) {\n                out(\"No\");\n                return;\n            }\n\
    \            p[v] = i;\n            for(int nv: g[v]) {\n                -- sz[nv];\n\
    \                if(sz[nv] == 0 and l[nv] <= i and !end[nv]) {\n             \
    \       pque.emplace(r[nv], nv);\n                    end[nv] = 1;\n         \
    \       }\n            }\n        }\n    }\n    out(\"Yes\");\n    for(auto& x:\
    \ p) ++ x;\n    out(p);\n}\n\nsigned main() {\n    int testcase = 1;\n    // in(testcase);\n\
    \    while(testcase--) solve();\n    return 0;\n}"
  dependsOn:
  - library/graph/graph.hpp
  - library/graph/topological_sort.hpp
  - library/graph/reverse_graph.hpp
  isVerificationFile: true
  path: test/atcoder/abc304_h.test.cpp
  requiredBy: []
  timestamp: '2023-06-18 12:48:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc304_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc304_h.test.cpp
- /verify/test/atcoder/abc304_h.test.cpp.html
title: test/atcoder/abc304_h.test.cpp
---
