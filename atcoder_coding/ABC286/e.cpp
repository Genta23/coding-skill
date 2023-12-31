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
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int q; cin >> q;
    vector<ll> u(q), v(q);
    rep(i, q) cin >> u[i] >> v[i];
    rep(i, q) u[i]--, v[i]--;

    Graph g(n);
    rep(i, n){
        rep(j, n){
            if(s[i][j] == 'Y') g[i].push_back(j);
        }
    }

    rep(i, q){
        vector<ll> dis(n, inf);
        vector<ll> w(n);
        queue<pair<ll, ll>> que;
        que.push({u[i], a[u[i]]});
        dis[u[i]] = 0;
        w[u[i]] = a[u[i]];
        while(!que.empty()){
            auto vq = que.front(); que.pop();
            if(dis[v[i]] != inf && dis[vq.first] > dis[v[i]]) break;
            chmax(w[vq.first], vq.second);
            for(int x : g[vq.first]){
                if(dis[x] >= dis[vq.first] + 1){
                    dis[x] = dis[vq.first] + 1;
                    que.push({x, vq.second + a[x]});
                }
            }
        }
        if(dis[v[i]] == inf) cout << "Impossible" << endl;
        else cout << dis[v[i]] << " " << w[v[i]] << endl;
    }
    return 0;
}