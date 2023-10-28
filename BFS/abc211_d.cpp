#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
const int MOD = 1000000007;

int main(){
    int n, m; cin >> n >> m;
    Graph g(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dis(n, inf), cnt(n);
    dis[0] = 0, cnt[0] = 1;

    queue<int> que;
    que.push(0);
    while(!que.empty()){
        auto v = que.front();
        que.pop();
        for(int x : g[v]){
            if(dis[x] <= dis[v]) continue;
            if(dis[x] == inf){
                que.push(x); //ノードがキューに入るのは1回限定
                dis[x] = dis[v] + 1;
            }
            cnt[x] = (cnt[x] + cnt[v]) % MOD;
        }
    }
    cout << cnt[n-1] << endl;
    return 0;
}