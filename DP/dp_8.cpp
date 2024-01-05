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
int cst[103][103];

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> c(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> c[i][j];

    rep(i, n){
        rep(j, m){
            if(i != 0 & j != 0) cst[i+1][j+1] = min({cst[i][j], cst[i+1][j], cst[i][j+1]}) + c[i][j];
            else if(i == 0) cst[i+1][j+1] = cst[i+1][j] + c[i][j];
            else if(j == 0) cst[i+1][j+1] = cst[i][j+1] + c[i][j];
        }
    }

    cout << cst[n][m] << endl;
    return 0;
}