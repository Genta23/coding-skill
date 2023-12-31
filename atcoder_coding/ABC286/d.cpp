#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <cmath>
#include <bitset>
#include <tuple>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;
bool dp[53][10003];

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    dp[0][0] = true;
    rep(i, n){
        dp[i+1][0] = true;
        rep(j, x){
            bool flag = false;
            rep(k, b[i]+1){
                //dp[i+1][j+1] = dp[i][j-a[i]*k]
                if(j+1-a[i]*k >= 0 && dp[i][j+1-a[i]*k]){
                    flag = true;
                    break;
                }
            }
            if(flag) dp[i+1][j+1] = true;
        }
    }

    /*rep(i, n+1){
        rep(j, 22){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << (dp[n][x] ? "Yes" : "No") << endl;
    return 0;
}