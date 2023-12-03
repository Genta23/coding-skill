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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
ll dt[1007][1007];
ll n;

ll cal(ll a, ll b){
    if(a < 0 || b < 0) return 0;
    // ここはなくても通る
    /*else if(a < n && b < n) return dt[a][b];
    else if(a < n){
        ll e = b / n;
        b %= n;
        ll ans = dt[a][n-1]*e + dt[a][b];
        return ans;
    }
    else if(b < n){
        ll e = a / n;
        a %= n;
        ll ans = dt[n-1][b]*e + dt[a][b];
        return ans;
    }*/
    else{
        ll e = a / n;
        ll f = b / n;
        a %= n, b %= n;
        ll ans = dt[n-1][n-1]*e*f + dt[a][n-1]*f + dt[n-1][b]*e + dt[a][b];
        return ans;
    }
}
int main(){
    int q; cin >> n >> q;
    vector<string> p(n); rep(i, n) cin >> p[i];

    // 行の累積和計算
    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            if(p[i][j] == 'B') cnt++;
            dt[i][j] = cnt;
        }
    }

    // 列の累積和計算
    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            cnt += dt[j][i];
            dt[j][i] = cnt;
        }
    }

    // クエリに対応
    rep(i, q){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll ans =  (cal(c, d)) - (cal(c, b-1)) - (cal(a-1, d)) + (cal(a-1, b-1));
        cout << ans << endl;
    }
    return 0;
}