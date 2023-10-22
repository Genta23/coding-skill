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
ll nor_data[1000][1000], rev_data[1000][1000];

int main(){
    ll h, w, c; cin >> h >> w >> c;
    rep(i, h){
        rep(j, w){
            int temp; cin >> temp;
            nor_data[i][j] = temp;
            rev_data[i][w-1 - j] = temp;
        }
    }

    ll dp[1000][1000];
    rep(i, h){
        rep(j, w){
            if(i == 0 && j == 0) dp[i][j] = nor_data[i][j];
            else if(i == 0) dp[i][j] = min(nor_data[i][j], dp[i][j-1] + c);
            else if(j == 0) dp[i][j] = min(nor_data[i][j], dp[i-1][j] + c);
            else dp[i][j] = min(nor_data[i][j], min(dp[i-1][j] + c, dp[i][j-1] + c));
        }
    }
    
    /* ans */
    ll ans = infl;
    rep(i, h){
        rep(j, w){
            if(i == 0 && j == 0) continue;
            else if(i == 0) (ans > dp[i][j-1] + c + nor_data[i][j]) ? (ans = dp[i][j-1] + c + nor_data[i][j]) : 0;
            else if(j == 0) (ans > dp[i-1][j] + c + nor_data[i][j]) ? (ans = dp[i-1][j] + c + nor_data[i][j]) : 0;
            else (ans > min(dp[i][j-1] + c + nor_data[i][j], dp[i-1][j] + c + nor_data[i][j])) ? (ans = min(dp[i][j-1] + c + nor_data[i][j], dp[i-1][j] + c + nor_data[i][j])) : 0;
        }
    }

    /* 反転 */
    rep(i, h){
        rep(j, w){
            if(i == 0 && j == 0) dp[i][j] = rev_data[i][j];
            else if(i == 0) dp[i][j] = min(rev_data[i][j], dp[i][j-1] + c);
            else if(j == 0) dp[i][j] = min(rev_data[i][j], dp[i-1][j] + c);
            else dp[i][j] = min(rev_data[i][j], min(dp[i-1][j] + c, dp[i][j-1] + c));
        }
    }

    rep(i, h){
        rep(j, w){
            if(i == 0 && j == 0) continue;
            else if(i == 0) (ans > dp[i][j-1] + c + rev_data[i][j]) ? (ans = dp[i][j-1] + c + rev_data[i][j]) : 0;
            else if(j == 0) (ans > dp[i-1][j] + c + rev_data[i][j]) ? (ans = dp[i-1][j] + c + rev_data[i][j]) : 0;
            else (ans > min(dp[i][j-1] + c + rev_data[i][j], dp[i-1][j] + c + rev_data[i][j])) ? (ans = min(dp[i][j-1] + c + rev_data[i][j], dp[i-1][j] + c + rev_data[i][j])) : 0;
        }
    }
     
    cout << ans << endl;
    return 0;
}