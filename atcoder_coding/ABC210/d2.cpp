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
const long long infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
ll a[1000][1000];

int main(){
    ll h, w, c; cin >> h >> w >> c;
    rep(i, h) rep(j, w) cin >> a[i][j];

    ll dp[1010][1010];

    //i == 0とかj == 0をinflで埋めてみる
    //無駄な場合分けが多いと可読性が下がるため
    rep(i, h+1) dp[i][0] = infl;
    rep(j, w+1) dp[0][j] = infl;

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            //ここaの部分が地味にズレるのが感覚的に分かりにくくしているような気がする　感覚的にはa[i][j]が正解
            dp[i][j] = min(a[i-1][j-1], min(dp[i-1][j] + c, dp[i][j-1] + c));
        }
    }
    
    /* ans */
    ll ans = infl;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(i == 1 && j == 1) continue;

            ans = min(ans, min(dp[i-1][j] + c + a[i-1][j-1], dp[i][j-1] + c + a[i-1][j-1]));
        }
    }

    /* 反転 */
    rep(i, h){
        rep(j, w/2){
            int temp;
            temp = a[i][j];
            a[i][j] = a[i][w-1 - j];
            a[i][w-1 - j] = temp;
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            //ここaの部分が地味にズレるのが感覚的に分かりにくくしているような気がする　感覚的にはa[i][j]が正解
            dp[i][j] = min(a[i-1][j-1], min(dp[i-1][j] + c, dp[i][j-1] + c));
        }
    }

    /* ans */
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(i == 1 && j == 1) continue;

            ans = min(ans, min(dp[i-1][j] + c + a[i-1][j-1], dp[i][j-1] + c + a[i-1][j-1]));
        }
    }
    cout << ans << endl;
    return 0;
}