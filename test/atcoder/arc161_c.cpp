#define PROBLEM "https://atcoder.jp/contests/arc161/tasks/arc161_c"
#include<bits/stdc++.h>
#include<library/tree/dfs_order.hpp>

namespace otera {}
using namespace std;
using namespace otera;

struct io_setup {
    io_setup(int precision = 20) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(precision);
    }
} io_setup_ {};

#define int long long

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
#define repa(i, n) for(int i = 0; i < (n); ++ i)
#define repb(i, a, b) for(int i = (a); i < (b); ++ i)
#define repc(i, a, b, c) for(int i = (a); i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, repc, repb, repa)(__VA_ARGS__)
#define rep1a(i, n) for(int i = 0; i <= (n); ++ i)
#define rep1b(i, a, b) for(int i = (a); i <= (b); ++ i)
#define rep1c(i, a, b, c) for(int i = (a); i <= (b); i += (c))
#define rep1(...) overload4(__VA_ARGS__, rep1c, rep1b, rep1a)(__VA_ARGS__)
#define rev_repa(i, n) for(int i=(n)-1;i>=0;i--)
#define rev_repb(i, a, b) assert((a) > (b));for(int i=(a);i>(b);i--)
#define rev_rep(...) overload3(__VA_ARGS__, rev_repb, rev_repa)(__VA_ARGS__)
#define rev_rep1a(i, n) for(int i=(n);i>=1;i--)
#define rev_rep1b(i, a, b) assert((a) >= (b));for(int i=(a);i>=(b);i--)
#define rev_rep1(...) overload3(__VA_ARGS__, rev_rep1b, rev_rep1a)(__VA_ARGS__)
#define for_subset(t, s) for(ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define mkp make_pair
#define mkt make_tuple
#define fr first
#define sc second
#define all(c) std::begin(c), std::end(c)
#define rall(c) std::rbegin(c), std::rend(c)
#define lb(c, x) distance(std::begin(c), lower_bound(all(c), (x)))
#define ub(c, x) distance(std::begin(c), upper_bound(all(c), (x)))
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));(a).erase(unique(all(a)),std::end(a))
#define si(c) (int)(c).size()
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
#define kth_bit(x, k) ((x>>k)&1)
#define unless(A) if(!(A))
#define elif else if
ll modulo(ll n, ll d){ return (n % d + d) % d; };
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll intpow(ll a, ll b, ll m) {ll ans = 1; while(b){ if(b & 1) (ans *= a) %= m; (a *= a) %= m; b /= 2; } return ans; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T, class U> using umap = unordered_map<T, U>;
template<class T> void scan(T& a){ cin >> a; }
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ cout << ' '; }
template<class T> void print(const T& a){ cout << a; }
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout << ' '; print(*i); } }
int out(){ cout << '\n'; return 0; }
template<class T> int out(const T& t){ print(t); cout << '\n'; return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); cout << ' '; out(tail...); return 0; }
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#define dump(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...)
#define dump(...)
#endif

void solve() {
    INT(n);
    graph g(n);
    g.read_tree();
    STR(s);
    dfs_order order(g);
    rep(i, n) {
        debug(i, order[i]);
    }
    string ans(n, '?');
    // rep(i, n) {
    //     int v = order[i];
    //     if(si(g[v]) == 1) {
    //         int nv = g[v][0];
    //         if(ans[nv] == '?') {
    //             ans[nv] = s[v];
    //         } else if(ans[nv] != s[v]) {
    //             out(-1);
    //             return;
    //         }
    //     }
    // }
    rep(i, n) {
        int v = order[i];
        int par = order.parent(v);
        debug(v, par);
        int cb = 0, cw = 0;
        for(int nv: g[v]) {
            if(nv == par) continue;
            debug(v, nv);
            if(ans[nv] == 'B') ++ cb;
            else if(ans[nv] == 'W') ++ cw;
            else {
                assert(0);
            }
        }
        if(cb < cw and s[v] == 'B') {
            out(-1);
            return;
        }
        if(cw < cb and s[v] == 'W') {
            out(-1);
            return;
        }
        if(cw == cb) {
            assert(par != -1);
            if(ans[par] != '?' and ans[par] != s[v]) {
                out(-1);
                return;
            }
            ans[par] = s[v];
        }
        if(ans[v] == '?') {
            if(par != -1) ans[v] = s[par];
            else ans[v] = 'B';
        }
    }
    out(ans);
}

signed main() {
    int testcase = 1;
    in(testcase);
    while(testcase--) solve();
    return 0;
}