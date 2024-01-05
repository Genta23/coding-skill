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
double dp[5007][5007];

int main(){
    int n; cin >> n;
    vector<double> p(n); rep(i, n) cin >> p[i];

    rep(i, n){
        rep(j, n){
            if(j == 0) dp[i+1][j+1] = max(dp[i][j+1], p[i]);
            else if(i != j) dp[i+1][j+1] = max(dp[i][j+1], 0.9 * dp[i][j] + p[i]);
            else if(i == j) dp[i+1][j+1] = 0.9 * dp[i][j] + p[i];
        }
    }

    /*rep(i, n+1){
        rep(j, n+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    vector<double> data09(n);
    double ini = 1.0;
    rep(i, n){
        if(i == 0) data09[i] = ini;
        else data09[i] = data09[i-1] + ini;
        ini *= 0.9;
    }
    //rep(i, n) cout << data09[i] << endl;

    double ans = -1000000000.0;
    for(int i=1; i<=n; i++) chmax(ans, dp[n][i]/data09[i-1] - 1200.0/sqrt((double)i));

    cout << ans << endl;
    return 0;
}