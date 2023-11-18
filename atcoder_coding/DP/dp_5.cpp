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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
int cnt[503][10003];

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(n); rep(i, n) cin >> a[i] >> b[i];

    rep(i, n+1) rep(j, m+1) cnt[i][j] = inf;
    
    cnt[0][0] = 0;
    rep(i, n){
        rep(j, m+1){
            if(j - a[i] >= 0) cnt[i+1][j] = min(cnt[i][j - a[i]] + 1, cnt[i][j]);
            else cnt[i+1][j] = cnt[i][j];
        }
    }

    cout << (cnt[n][m] <= k ? "Yes" : "No") << endl;
    return 0;
}