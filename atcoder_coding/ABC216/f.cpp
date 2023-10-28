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
const int mod = 998244353;
ll dp[5050][5050];

int main(){
    int n; cin >> n;
    vector<pair<int, int>> data(n);
    rep(i, n) cin >> data[i].first;
    rep(i, n) cin >> data[i].second;
    sort(data.begin(), data.end());

    dp[0][0] = 1;
    ll ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=5000; j++){
            dp[i][j] += dp[i-1][j];
            if(j - data[i-1].second >= 0){
                dp[i][j] += dp[i-1][j - data[i-1].second];
                dp[i][j] %= mod;

                //その文字が最大値として使用されるパターンであり、maxを超過していないものをカウントする
                //条件を満たさないが、今後条件領域内に入る可能性があるものがあるので、それをカウントしないように除くことがこの条件の目的
                if(j <= data[i-1].first){
                    ans += dp[i-1][j - data[i-1].second];
                    ans %= mod;
                }
            }
        }
    }
    rep(i, n+1){
        rep(j, 40){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}