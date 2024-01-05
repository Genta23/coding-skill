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
//using Graph = vector<vector<int>>;

struct Edge{ ll to, cost; };
using Graph = vector<vector<Edge>>;

// { distance, from }
using Pair = pair<ll, int>;

void dijkstra(const Graph& g, vector<ll>& distance, vector<ll>& parent, int start){
    min_priority_queue<Pair> que;
    distance[start] = 0;
    que.push({0LL, start});
    while(!que.empty()){
        auto [cand_cost, cand_pos] = que.top(); que.pop();
        if(distance[cand_pos] < cand_cost) continue;

        for(auto [to, cost] : g[cand_pos]){
            if(chmin(distance[to], cand_cost + cost)){ //値の更新が起きている
                que.push({cand_cost + cost, to});
                parent[to] = cand_pos;
            }
        }
    }
}

void shortestPath(vector<ll>& parent, vector<int>& ans, int goal){
    int v = goal;
    while(v != -1){
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    int n, m; ll t; cin >> n >> m >> t;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    Graph g1(n), g2(n);
    rep(i, m){
        int a, b; ll c; cin >> a >> b >> c;
        a--, b--;
        g1[a].push_back({b, c});
        g2[b].push_back({a, c});
    }

    vector<ll> dist1(n, infl), parent1(n, -1);
    dijkstra(g1, dist1, parent1, 0);

    vector<ll> dist2(n, infl), parent2(n, -1);
    dijkstra(g2, dist2, parent2, 0);

    ll max = 0;
    rep(i, n){
        ll tmp = t - (dist1[i] + dist2[i]);
        if(tmp > 0) chmax(max, a[i]*tmp);
    }

    cout << max << endl;
    return 0;
}