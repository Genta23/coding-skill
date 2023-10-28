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
ll dp[1010][5010];
const int mod = 998244353;
int main(){
    ll n, m, k; cin >> n >> m >> k;
    rep(i, n){
        rep(j, m){
            if(i == 0) dp[i][j] = 1;
            else if(j == 0){
                rep(pos, m){
                    if(abs(j-pos) >= k){
                        dp[i][j] += dp[i-1][pos];
                        dp[i][j] %= mod;
                    }
                }
            }
            else{
                if(j-k >= 0 && j+k-1 < m){
                    dp[i][j] = dp[i][j-1] - dp[i-1][j+k-1] + dp[i-1][j-k];
                    dp[i][j] %= mod;
                }
                else if(j-k >= 0){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-k];
                    dp[i][j] %= mod;
                }
                else if(j+k-1 < m){
                    dp[i][j] = dp[i][j-1] - dp[i-1][j+k-1];
                    dp[i][j] %= mod;
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    ll ans = 0;
    rep(i, m){
        ans += dp[n-1][i];
        ans %= mod;
    }
    ans += mod;//この2行でACしてしまった -> 実行結果が負になったものがあった
    ans %= mod;
    cout << ans << endl;
    return 0;
}