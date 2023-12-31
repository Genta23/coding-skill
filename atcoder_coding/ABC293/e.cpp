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
#include <iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (ll i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    ll a, x, m; cin >> a >> x >> m;
    ll t = 1; // 床関数 √x を求める
    while(t*t <= x){
        t++;
    }
    t--;

    ll b = 0, r = 1; // 分割パートの計算
    rep(i, t){
        b += r, b %= m;
        r *= a, r %= m;
    }

    ll ans = 0, c = 1; // 分割した計算をさらに繰り返す
    rep(i, t){
        ans += b*c, ans %= m;
        c *= r, c %= m;
    }

    rep(i, x - t*t){ // 残りを計算する
        ans *= a, ans %= m;
        ans++, ans %= m;
    }
    cout << ans << endl;
    return 0;
}