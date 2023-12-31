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
    int n, m; cin >> n >> m;
    vector<ll> t(n), x(n); rep(i, n) cin >> t[i] >> x[i];

    vector<vector<ll>> g(3);
    rep(i, n) g[t[i]].push_back(x[i]);
    rep(i, 3) sort(g[i].begin(), g[i].end(), greater<ll>());  

    /* 累積和 */
    rep(i, 3) rep(j, g[i].size()) if(j > 0) g[i][j] += g[i][j-1];

    ll ans = 0;
    if(g[0].size() > 0) chmax(ans, g[0][min(m, (int)g[0].size())-1]);
    rep(i, g[1].size()){
        ll cnd = 0;
        int hp = m;
        int cnt = i + 1;
        hp -= cnt;
        if(hp <= 0) continue;
        cnd += g[1][i];

        if(g[2].size() == 0) continue;
        int it = distance(g[2].begin(), lower_bound(g[2].begin(), g[2].end(), cnt)) + 1;
        hp -= it;
        if(hp < 0) continue;
        if(hp == 0) {chmax(ans, cnd); continue;}

        if(g[0].size() == 0) continue;
        if(hp > g[0].size()) hp = g[0].size();
        cnd += g[0][hp-1];

        //cout << i << " " << hp << " " << cnd << endl;
        chmax(ans, cnd);
    }
    cout << ans << endl;
    return 0;
}