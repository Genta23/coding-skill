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
int cnt = 0;

int dfs(Graph& g, vector<bool>& flag, int v){
    cnt++;
    if(cnt >= 1e6) return 0;
    for(int x : g[v]){
        if(!flag[x]){
            flag[x] = true;
            dfs(g, flag, x);
            flag[x] = false;
        }
    }
    return 0;
}
int main(){
    int n, m; cin >> n >> m;
    Graph g(n);
    rep(i, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> flag(n);
    flag[0] = true;

    dfs(g, flag, 0);
    cout << min(cnt, (int)1e6) << endl;
}