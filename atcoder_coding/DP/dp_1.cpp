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
bool flag[103][10003];
int main(){
    int n, m; cin >> n >> m;
    vector<int> w(n); rep(i, n) cin >> w[i];

    flag[0][0] = true;
    rep(i, n){
        rep(j, m+1){
            flag[i+1][j] = flag[i][j];
            if(j - w[i] >= 0 && flag[i][j - w[i]]) flag[i+1][j] = true;
        }
    }

    cout << (flag[n][m] ? "Yes" : "No") << endl;
    return 0;
}