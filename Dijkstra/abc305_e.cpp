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
template<typename T> using max_priority_queue = priority_queue<T, vector<T>, less<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
using Pair = pair<ll, int>; // point, node

int main(){
    int n, m, k; cin >> n >> m >> k;
    Graph g(n);
    rep(i, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    max_priority_queue<Pair> que;
    rep(i, k){
        int p; ll h; cin >> p >> h;
        p--;
        que.push({h, p});
    }

    vector<ll> hitpoint(n, -1);
    vector<int> ans;
    while(!que.empty()){
        auto [h, node] = que.top(); que.pop();
        if(hitpoint[node] >= h) continue;
        hitpoint[node] = h; // このタイミングで初めてnodeが保持する値が確定する
        ans.push_back(node);
        
        for(int x : g[node]){;
            if(hitpoint[x] < h - 1){
                que.push({h - 1, x}); // 解の候補として優先度付きキューにpush
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int x : ans) cout << x+1 << " ";
    cout << endl;
    return 0;
}