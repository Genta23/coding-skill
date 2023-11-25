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

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

/*int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to, weight));
    }
}*/
ll dfs(Graph& g, vector<bool>& flag){
    if(count(flag.begin(), flag.end(), true)){
        return 0;
    }
    int dis = find(flag.begin(), flag.end(), false) - flag.begin();
    flag[dis] = true;
    ll cnd = 0; 
    for(int i = dis+1; i<flag.size(); i++){
        if(!flag[i]){
            flag[i] = true;
            cnd = max(cnd, g[dis][i] + dfs(g, flag));
            flag[i] = false;
        }
    }
    flag[dis] = false;
    return cnd;
}
int main(){
    int n; cin >> n;
    Graph g(n);
    rep(i, n-1){
        for(int j=i+1; j<n; j++){
            ll d; cin >> d;
            g[i].push_back(Edge(j, d));
            g[j].push_back(Edge(i, d));
        }
    }

    vector<bool> flag(n);
    ll ans = 0;
    if(n%2 == 0) ans = dfs(g, flag);
    else{
        rep(i, n){
            flag[i] = true;
            ans = max(ans, dfs(g, flag));
            flag[i] = false;
        }
    }
    cout << ans << endl;
    return 0;
}