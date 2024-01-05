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
template<typename T> using max_priority_queue = priority_queue<T, vector<T>, less<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int n, m, k; cin >> n >> m >> k;
    Graph g(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> p(k), h(k); rep(i, k) cin >> p[i] >> h[i];
    rep(i, k) p[i]--;

    vector<bool> flag(n);
    max_priority_queue<pair<int, int>> que; //打ち切りにしているから不用意に潜れなくてバグっている可能性がある。
    rep(i, k) que.push({h[i], p[i]});
    while(!que.empty()){
        pair<int, int> v = que.top(); que.pop();
        if(flag[v.second]) continue; // これを追加した
        flag[v.second] = true;
        if(v.first == 0) continue;
        for(int x : g[v.second]){
            if(!flag[x]){
                que.push({v.first-1, x});
            }
        }
    }

    int cnt = 0;
    rep(i, n) if(flag[i]) cnt++;
    cout << cnt << endl;
    rep(i, n) if(flag[i]) cout << i+1 << " ";
    cout << endl;
    return 0;
}