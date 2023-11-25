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
// vectorではなくグラフを使用して、状態を表してみよう


ll dfs(vector<vector<ll>>& d, vector<bool>& flag){
    if(count(flag.begin(), flag.end(), true) == flag.size()) return 0;
    int dis = find(flag.begin(), flag.end(), false) - flag.begin();
    flag[dis] = true;
    ll cnd = 0;
    for(int i=dis+1; i<flag.size(); i++){
        if(!flag[i]){
            flag[i] = true;
            cnd = max(cnd, d[dis][i] + dfs(d, flag));
            flag[i] = false;
        }
    }
    flag[dis] = false;
    return cnd;
}
int main(){
    int n; cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));

    rep(i, n-1){
        for(int j=i+1; j<n; j++){
            ll tmp; cin >> tmp;
            d[i][j] = tmp;
            d[j][i] = tmp;
        }
    }

    vector<bool> flag(n);
    ll ans = 0;
    if(n%2 == 0) ans = dfs(d, flag);
    else{
        rep(i, n){
            flag[i] = true;
            ans = max(ans, dfs(d, flag));
            flag[i] = false;
        }
    }
    cout << ans << endl;
    return 0;
}

// これはもう一回解きたい面白い問題