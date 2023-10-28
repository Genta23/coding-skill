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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

#define mod 998244353
ll dp[1024][1024][10];

int main(){
    int n; string s; cin >> n >> s;
    for(int i=1; i<=n; i++){
        int x = s[i-1]-'A';
        // 同一集合内遷移
        rep(j, 1024){
            rep(k, 10){
                dp[i][j][k] += dp[i-1][j][k];
                if(x == k){
                    dp[i][j][k] += dp[i-1][j][k];
                    dp[i][j][k] %= mod;
                }
            }
        }
        // 新しいコンテストに出場する
        rep(j, 1024){
            // 集合jがxを含んでいたらcontinue;
            if(j&(1<<x)) continue;// ここの演算まとめる
            rep(k, 10){
                dp[i][j|(1<<x)][x] += dp[i-1][j][k];
                dp[i][j|(1<<x)][x] %= mod;
            }
        }

        //初めてコンテストに参加する
        dp[i][(1<<x)][x]++;
        dp[i][(1<<x)][x] %= mod; // ここそんなに大きい数でないのでは??
    }

    ll ans = 0;
    rep(i, 1024){
        rep(j, 10){
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}