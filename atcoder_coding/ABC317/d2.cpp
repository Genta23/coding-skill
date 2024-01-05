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
ll dp[101][100007];

int main(){
    rep(i, 101) rep(j, 100007) dp[i][j] = infl;
    // あれこれってちょっと視点を変えたナップザックじゃない?? -> 正しい

    int n; cin >> n;
    vector<ll> x(n), y(n);
    vector<int> z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    //vector<ll> data;
    int z_total = 0, z_cnt = 0;
    rep(i, n){
        z_total += z[i];
        if(x[i] > y[i]) z_cnt += z[i];
        //if(x[i] < y[i]) data.push_back((x[i]+y[i])/2 + 1 - x[i]);
    }
    
    int z_th = z_total/2 + 1;
    if(z_cnt >= z_th){
        cout << 0 << endl;
        return 0;
    }

    dp[0][z_cnt] = 0;
    rep(i, n){
        rep(j, 100007){
            dp[i+1][j] = dp[i][j];
            if(x[i] < y[i] && j-z[i] >= 0){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j-z[i]] + (x[i]+y[i])/2 + 1 - x[i]);
            }
        }
    }
    ll ans = infl;
    rep(i, 100007){
        if(i >= z_th) chmin(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}