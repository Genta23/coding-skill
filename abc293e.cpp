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
#include "atcoder/modint.hpp" // #include "atcoder/modint.hpp" でも通る 理想は<atcoder/modint.hpp>だが
using namespace std;
using namespace atcoder;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
using mint = modint;

vector<vector<mint>> multi_gyo(vector<vector<mint>> a, vector<vector<mint>> b){
    vector<vector<mint>> c(2, vector<mint>(2));
    c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    return c;
}

int main(){
    ll a, x, m; cin >> a >> x >> m;
    mint::set_mod(m);

    vector<vector<mint>> r(2, vector<mint>(2));
    r[0][0] = a, r[0][1] = 1, r[1][1] = 1;

    /* 繰り返し二乗法 */
    string s;
    while(x > 0){
        if(x % 2 == 1) s += '1';
        else s += '0';
        x /= 2;
    }

    vector<vector<mint>> ans(2, vector<mint>(2)); // 単位元で初期化(単位行列)
    ans[0][0] = 1, ans[1][1] = 1;
    rep(i, s.size()){
        if(s[i] == '1') ans = multi_gyo(ans, r);
        r = multi_gyo(r, r);
    }
    cout << ans[0][1].val() << endl;
    return 0;
}