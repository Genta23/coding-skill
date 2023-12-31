
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

int dfs(vector<bool>& flag, Graph& g, int v, vector<int>& ans){
    for(int x : g[v]){
        if(!flag[x]){
            flag[x] = true;
            ans[v] += (dfs(flag, g, x, ans) + 1);
        }
    }
    return ans[v];
}

int main(){
    int n; cin >> n;
    Graph g(n);
    rep(i, n-1){
        int v, u; cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    /*if(g[0].size() == 0){ // 葉の場合は即時終了
        cout << 1 << endl;
        return 0;
    }*/

    vector<bool> flag(n);
    vector<int> ans(n);
    flag[0] = true;
    dfs(flag, g, 0, ans);

    int sum = 0, max = 0;
    for(int x : g[0]){
        sum += (ans[x] + 1);
        chmax(max, ans[x] + 1);
    }
    cout << sum - max + 1 << endl; // +1 で自身の削除
    return 0;
}