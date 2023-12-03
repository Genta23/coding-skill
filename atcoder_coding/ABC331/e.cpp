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

int main(){
    ll n, m, l; cin >> n >> m >> l;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vector<pair<ll, ll>> dt(m);
    rep(i, m){
        dt[i].first = b[i];
        dt[i].second = (ll)i;
    }
    sort(dt.begin(), dt.end(), greater<pair<ll, ll>>());

    vector<set<ll>> g(n);
    rep(i, l){
        ll c, d; cin >> c >> d;
        c--, d--;
        g[c].insert(d);
    }

    ll ans = 0;
    rep(i, n){
        rep(j, m){
            if(g[i].find(dt[j].second) == g[i].end()){ // ダメな組み合わせにないなら
                chmax(ans, a[i]+dt[j].first);
                break; //break書き忘れ
            }
        }
    }

    cout << ans << endl;
    return 0;
}