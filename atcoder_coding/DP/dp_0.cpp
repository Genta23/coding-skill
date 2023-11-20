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
ll dp[107][100007];

int main(){
    int n, w; cin >> n >> w;
    vector<pair<ll, ll>> data(n); rep(i, n) cin >> data[i].first >> data[i].second;

    rep(i, n){
        rep(j, 100007){
            if(j - data[i].first >= 0) dp[i+1][j] = max(dp[i][j - data[i].first] + data[i].second, dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}