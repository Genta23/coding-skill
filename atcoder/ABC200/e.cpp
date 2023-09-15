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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    int n; cin >> n;
    int dp[4][50] = {0}; //コンパイル時に配列サイズが既知である必要がある
    dp[0][0] = 1;
    rep(i, 3){
        for(int j=0; j <= i*n; j++){
            dp[i+1][j+1]+=dp[i][j];
            if(j != i*n) dp[i+1][j+n+1]-=dp[i][j];
        }
        for(int j=1;j<=(i+1)*n;j++){
            dp[i+1][j]+=dp[i+1][j-1];
        }
    }

    rep(i, 4){
        rep(j, 50){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}