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

struct Edge{ int to; ll cost; };
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
    int n, a, b, c; cin >> n >> a >> b >> c;
    Graph g1(n), g2(n);
    rep(i, n){
        rep(j, n){
            ll d; cin >> d;
            g1[i].push_back({j, d*a});
            g2[i].push_back({j, d*b + c});
        }
    }

    vector<ll> dist_s(n, infl), parent_s(n, -1);
    dijkstra(g1, dist_s, parent_s, 0);
    
    vector<ll> dist_g(n, infl), parent_g(n, -1);
    dijkstra(g2, dist_g, parent_g, n-1);

    ll min = infl;
    rep(i, n) chmin(min, dist_s[i] + dist_g[i]);

    cout << min << endl;
}