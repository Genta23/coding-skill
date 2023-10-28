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
bool flag[103];

int main(){
    int n, m; cin >> n >> m;

    Graph g(n);
    rep(i, m){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    rep(i, n){
        if(!flag[i]){
            cnt++;
            queue<int> que;
            flag[i] = true;
            que.push(i);
            while(!que.empty()){
                auto v = que.front();
                que.pop();
                for (int x : g[v]) {
                    if(flag[x]) continue; //探索済みのノードは調べない

                    flag[x] = true;
                    que.push(x);
                }   
            } 
        }
    }
    cout << cnt << endl;
    return 0;
}