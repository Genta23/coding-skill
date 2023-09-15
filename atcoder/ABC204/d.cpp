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

int main(){
    int n; cin >> n;
    vector<int> t;
    int s = 0;
    rep(i, n){
        int tmp; cin >> tmp;
        s += tmp;
        t.push_back(tmp);
    }

    //bool dp[101][100001] = {false};メモリが死ぬ
    //再起する際に過去の情報しか見ないように設計できるのなら何とか節約できるのではないか
    //ごっちゃになるから無理そう 更新後のデータを参照してしまっている
    bool dp[2][1000001] = {false};
    int ans = 0;
    dp[0][0] = true;
    rep(i, n){
        dp[i%2][t[i]] = true;
        rep(j, s+1){
            if(i>0){
                if(dp[(i+1)%2][j]) dp[i%2][j] = true;
                if(j-t[i] >= 0){
                    if(dp[(i+1)%2][j - t[i]]) dp[i%2][j] = true;
                }
            }
        }
    }
    int ans_s = ceil(s/2.0);
    rep(i, s+1){
        if(dp[(n-1)%2][i] && i>=ans_s){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}