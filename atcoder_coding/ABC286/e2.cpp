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

    vector<vector<ll>> dis(n, vector<ll>(n, inf));
    vector<vector<ll>> w(n, vector<ll>(n));
    rep(i, n){
        queue<pair<ll, ll>> que;
        que.push({i, a[i]});
        dis[i][i] = 0;
        w[i][i] = a[i];
        while(!que.empty()){
            auto vq = que.front(); que.pop();
            chmax(w[i][vq.first], vq.second);
            for(int x : g[vq.first]){
                if(dis[i][x] >= dis[i][vq.first] + 1){
                    dis[i][x] = dis[i][vq.first] + 1;
                    que.push({x, vq.second + a[x]});
                }
            }
        }
    }

    rep(i, q){
        if(dis[u[i]][v[i]] == inf) cout << "Impossible" << endl;
        else cout << dis[u[i]][v[i]] << " " << w[u[i]][v[i]] << endl;
    }
    return 0;
}