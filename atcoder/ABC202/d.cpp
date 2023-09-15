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
#define rep(i,n) for (int i=0; i<n; i++)

long long dp[50][50];

string check(int i, int j, ll k){
    if(i==0) return string(j, 'b');
    if(j==0) return string(i, 'a');
    
    if(dp[i-1][j] >= k) return string("a") + check(i-1, j, k);
    else return string("b") + check(i, j-1, k-dp[i-1][j]);
}



int main(){
    int a, b; cin >> a >> b;
    ll k; cin >> k;

    dp[0][0] = 1;
    rep(i, a+1){
        rep(j, b+1){
            if(i>0) dp[i][j] += dp[i-1][j];
            if(j>0) dp[i][j] += dp[i][j-1];
        }
    }

    string ans = check(a, b, k);
    cout << ans << endl;
    return 0;
}