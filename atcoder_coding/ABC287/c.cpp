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
    int n, m; cin >> n >> m;
    Graph g(n);
    rep(i, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int v = -1;
    rep(i, n){
        if(g[i].size() == 1) v = i;
    }

    if(v == -1){
        cout << "No" << endl;
        return 0;
    }

    queue<int> que;
    vector<int> dis(n, -1);
    dis[v] = 0;
    que.push(v);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int x : g[v]){
            if(dis[x] == -1){
                dis[x] = dis[v] + 1;
                que.push(x);
            }
        }
    }

    rep(i, n){
        if(dis[i] == n-1){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}