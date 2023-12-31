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

    vector<pair<int, int>> cnd;
    cnd.push_back({0, 0});
    rep(i, g[1].size()){
        auto it = lower_bound(g[2].begin(), g[2].end(), i+1);
        if(it == g[2].end()) continue; // その数を選択することは不可能
        int dis = distance(g[2].begin(), it) + 1;
        cnd.push_back({i+1, dis});
    }

    ll ans = 0;
    rep(i, cnd.size()){
        int hp = m - (cnd[i].first + cnd[i].second);
        if(hp < 0) continue; // この時は条件を満たさないため再現できない
        hp = min(hp, (int)g[0].size());

        ll tmp = 0;
        if(hp > 0) tmp += g[0][hp-1];
        if(cnd[i].first > 0) tmp += g[1][cnd[i].first-1];

        chmax(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}