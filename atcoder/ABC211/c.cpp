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
#define rep(i,n) for (int i=0; i<n; i++)

int main(){
    string s; cin >> s;
    int size = s.size();
    ll cnt[8][100009] = {};
    string data = "chokudai";
    rep(i, 8){
        rep(j, size){
            if(data[i] == s[j]) {
                if(i == 0){
                    if(j == 0) cnt[i][j] = 1;
                    else cnt[i][j] = (cnt[i][j-1] + 1)%1000000007;
                }
                else{
                    if(j > 0) cnt[i][j] = (cnt[i-1][j-1] + cnt[i][j-1])%1000000007;
                }
            }
            else{
                if(j > 0) cnt[i][j] = cnt[i][j-1];
            }
        }
    }
    cout << cnt[7][size-1] << endl;
    return 0;
}