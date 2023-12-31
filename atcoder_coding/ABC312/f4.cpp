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

    vector<pair<ll, int>> g;
    vector<ll> g2;
    rep(i, n){
        if(t[i] == 0 || t[i] == 1){
            g.push_back({x[i], t[i]});
        }
        else{
            g2.push_back(x[i]);
        }
    }
    sort(g.begin(), g.end(), greater<pair<ll, int>>());

    vector<int> it0, it1;
    vector<ll> g0, g1, g01;
    rep(i, g.size()){
        g01.push_back(g[i].first);
        if(g[i].second == 0) it0.push_back(i),  g0.push_back(g[i].first);
        else if(g[i].second == 1) it1.push_back(i), g1.push_back(g[i].first);
    }

    rep(i, g01.size()) if(i > 0) g01[i] += g01[i-1];
    rep(i, g0.size()) if(i > 0) g0[i] += g0[i-1];
    rep(i, g1.size()) if(i > 0) g1[i] += g1[i-1];
    rep(i, g2.size()) if(i > 0) g2[i] += g2[i-1];

    //rep(i, g01.size()) cout << g01[i] << " ";
    //cout << endl;
    if(g01.size() == 0){ // 2だけの入力の可能性がある
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i, g2.size()){
        ll xp = g2[i];
        int hp = m - (i+1);
        if(hp <= 0) continue;

        if(xp > g1.size()) xp = g1.size();

        ll cnd = 0;
        if(xp == 0){
            cnd += g01[hp-1];
        }
        else{
            int cnt = it1[xp-1]+1;
            if(hp <= cnt){
                if(hp > g01.size()) hp = g01.size();
                cnd += g01[hp-1];
            }
            else{
                cnd += g1[xp-1];
                hp -= xp;
                if(g0.size() > 0){
                    if(hp > g0.size()){
                        cnd += g0[hp-1];
                    }
                }
            }
        }
        chmax(ans, cnd);
    }
    cout << ans << endl;
    return 0;
}