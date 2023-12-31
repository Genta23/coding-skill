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

    vector<pair<ll, ll>> g;
    vector<ll> h;
    rep(i, n){
        if(t[i] == 0 || t[i] == 1) g.push_back({x[i], t[i]});
        else h.push_back(x[i]);
    }
    sort(g.begin(), g.end(), greater<pair<ll, ll>>());
    sort(h.begin(), h.end(), greater<ll>());

    vector<pair<ll, ll>> gds(g.size());
    vector<pair<ll, ll>> dat0, dat1;

    rep(i, g.size()){
        gds[i] = {i, g[i].first};
        if(g[i].second == 0) dat0.push_back({i, g[i].first});
        else if(g[i].second == 1) dat1.push_back({i, g[i].first});
    }

    /* ここでseg fault */
    rep(i, gds.size()) if(i>0) gds[i].second += gds[i-1].second;
    rep(i, dat0.size()) if(i>0) dat0[i].second += dat0[i-1].second;
    rep(i, dat1.size()) if(i>0) dat1[i].second += dat1[i-1].second;
    rep(i, h.size()) if(i>0) h[i] += h[i-1];

    ll ans = 0;
    rep(i, h.size()){
        ll xp = h[i];
        ll hp = m - (i+1);
        if(hp <= 0) continue;

        if(xp > dat1.size()) xp = dat1.size();

        ll cnt;
        if(xp > 0) cnt = dat1[xp-1].first + 1;

        ll cand = 0;
        if(dat1.size() == 0 || hp <= cnt){
            cand += gds[hp-1].second;
        }
        else{
            cand += dat1[xp-1].second;
            hp -= xp;
            cand += dat0[hp-1].second;
        }
        chmax(ans, cand);
    }
    cout << ans << endl;
    return 0;
}