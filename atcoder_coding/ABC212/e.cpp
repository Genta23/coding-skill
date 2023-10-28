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
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
ll dp[5010][5010];

int main(){
    int MOD = 998244353;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> graph(n);
    //graph切断情報を使用する
    rep(i, m){
        int u, v; cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    dp[0][0] = 1;
    for(int i=1; i<=k; i++){
        // 前段階の合計をあらかじめ計算しておく
        ll sum = 0;
        rep(j, n) sum += dp[i-1][j];

        rep(j, n){
            dp[i][j] = sum;
            // 使用できない道の情報を組み込んでいく
            for(auto x : graph[j]){
                dp[i][j] -= dp[i-1][x];
            }
            // 自分を引き忘れていた
            dp[i][j] -= dp[i-1][j];
            // 割ったあまりを算出する
            dp[i][j] %= MOD;
        }
    }
    
    cout << dp[k][0] << endl;
    return 0;
}