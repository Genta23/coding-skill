#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
#include <bitset>
#include <tuple>
#include <cassert>
#include <numeric>
#include "atcoder/modint.hpp" // #include "atcoder/modint.hpp" でも通る 理想は<atcoder/modint.hpp>だが
using namespace std;
using namespace atcoder;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
using mint = modint998244353;
/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(a,b,x): 区間[a,b) の要素に x を加算。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/
template <typename T>
class RMQ {
public:
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, {1, 0}), lazy(n_ * 4, {1, 0}) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k].first = x.first;
            lazy[k].second = x.second;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            //dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); 区間取得しないため使用しない
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return {-1, -1};
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return {dat[k].first, dat[k].second};
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return (vl.first == -1 ? vr : vl);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

private:
    /* lazy eval */
    void eval(int k) {
        if (lazy[k].first == 1 && lazy[k].second == 0) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1].first = lazy[k].first * lazy[k * 2 + 1].first;
            lazy[k * 2 + 1].second = lazy[k].first * lazy[k * 2 + 1].second + lazy[k].second;
            lazy[k * 2 + 2].first = lazy[k].first * lazy[k * 2 + 2].first;
            lazy[k * 2 + 2].second = lazy[k].first * lazy[k * 2 + 2].second + lazy[k].second;
        }
        // 自身を更新
        dat[k].first = lazy[k].first * dat[k].first;
        dat[k].second = lazy[k].first * dat[k].second + lazy[k].second;
        lazy[k].first = 1;
        lazy[k].second = 0;
    }
};

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n); rep(i, n) cin >> a[i];
    vector<int> l(m), r(m), x(m); rep(i, m) cin >> l[i] >> r[i] >> x[i];
    rep(i, m) l[i]--, r[i]--;

    RMQ<pair<mint, mint>> rmq(n);

    rep(i, n) rmq.update(i, i+1, {(mint)a[i], (mint)0});

    rep(i, m){
        mint p = r[i] - l[i] + 1;
        rmq.update(l[i], r[i]+1, {(p-1)/p, x[i]/p});
    }

    rep(i, n){
        auto v = rmq.query(i, i+1);
        mint ans = v.first + v.second;
        cout << ans.val() << " ";
    }
    cout << endl;
    return 0;
}