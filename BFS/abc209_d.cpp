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

int main(){
    int n, q; cin >> n >> q;
    Graph g(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int, int>> query(q);
    rep(i, q){
        int c, d; cin >> c >> d;
        c--, d--;
        query[i].first = c;
        query[i].second = d;
    }

    vector<int> d(n, inf);
    queue<int> que;
    que.push(0);
    d[0] = 0;
    while(!que.empty()){
        auto v = que.front();
        que.pop();
        for(int x : g[v]){
            if(d[x] != inf) continue;

            que.push(x);
            d[x] = d[v] + 1;
        }
    }
    rep(i, q) cout << (abs(d[query[i].first] - d[query[i].second])%2 == 0 ? "Town" : "Road") << endl;
    return 0;
}