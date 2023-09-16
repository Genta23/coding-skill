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

string A[2023];
int memo[2023][2023];
bool seen[2023][2023] = {};
int h, w;

int dp(int i, int j){
    if(seen[i][j]) return memo[i][j]; //訪問済みの場合は値をすぐに返すことができる
    seen[i][j] = true;

    if(i == h-1 || j == w-1) return memo[i][j] = 0;

    int turn = (i+j)%2;
    if(turn == 0){
        int p, q;
        if(i+1 <= h-1) p = max(dp(i+1, j) + (A[i+1][j] == '+' ? 1 : -1), -10000);
        if(j+1 <= w-1) q = max(dp(i, j+1) + (A[i+1][j] == '+' ? 1 : -1), -10000);
        return memo[i][j] = max(p, q);
    }
    else{
        int p, q;
        if(i+1 <= h-1) p = min(dp(i+1, j) - (A[i+1][j] == '+' ? 1 : -1), 10000);//1e5 は double型
        if(j+1 <= w-1) q = min(dp(i, j+1) - (A[i+1][j] == '+' ? 1 : -1), 10000);
        return memo[i][j] = min(p, q);
    }
}
int main(){
    cin >> h >> w;
    rep(i, h){
        cin >> A[i];
    }

    int ans = dp(0, 0);

    if(ans > 0) cout << "Takahashi" << endl;
    else if(ans == 0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;

    return 0;
}