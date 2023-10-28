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

int main(){
    int n; cin >> n;
    Graph g(n);
    rep(i, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, n) sort(g[i].begin(), g[i].end(), greater<int>());

    vector<int> ans, parent(n), flag(n);
    rep(i, n) parent[i] = i;

    stack<int> st;
    st.push(0);
    parent[0] = -1;
    while(!st.empty()){
        int v = st.top(); st.pop();

        ans.push_back(v);
        
        if(flag[v]) continue;
        flag[v] = true;
        for(int x : g[v]) if(!flag[x]) st.push(v), st.push(x);
    }
    
    rep(i, ans.size()) cout << ans[i]+1 << " ";
    cout << endl;
    return 0;
}