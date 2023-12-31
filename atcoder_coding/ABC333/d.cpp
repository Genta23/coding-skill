
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
    Graph g(n);
    rep(i, n-1){
        int v, u; cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> dis(n, inf);
    dis[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int x : g[v]){
            if(dis[x] == inf){
                dis[x] = dis[v] + 1;
                que.push(x);
            }
        }
    }

    int ans = inf;
    rep(i, n){
        chmin(ans, dis[i]);
    }
    cout << ans << endl;
    return 0;
}