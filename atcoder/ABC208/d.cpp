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
using namespace std;
typedef long long ll;
const int inf = 1e9;
#define rep(i,n) for (int i=0; i<n; i++)
int dp[400][400];

int main(){
    int n, m; cin >> n >> m;

    rep(i, n) rep(j, n) dp[i][j] = inf; // 最短経路問題の一種であるため、大きい数を入れておく
    rep(i, n) dp[i][i] = 0; // 始点と終点が同じ場合は、0分

    rep(i, m){
        int a, b, c; cin >> a >> b >> c;
        dp[a-1][b-1] = c; //NはN-1の部分に格納するからね
    }

    ll ans = 0;
    rep(k, n){
        rep(i, n) rep(j, n) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        rep(i, n) rep(j, n) if(dp[i][j] < inf) ans += dp[i][j];
    }
    cout << ans << endl;
    return 0;
}