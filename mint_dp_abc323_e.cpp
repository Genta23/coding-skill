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
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;
using mint=atcoder::modint998244353;
mint p[100003];

int main(){
    int n, x; cin >> n >> x;
    vector<int> t(n); rep(i, n) cin >> t[i];

    p[0] = 1;
    rep(i, x){
        rep(j, n){
            if(i+1 - t[j] >= 0) p[i+1] += p[i+1 - t[j]];
        }
        p[i+1] /= n;
    }

    mint ans = 0;
    rep(i, t[0]){
        if(x - i >= 0) ans += p[x - i];
    }
    ans /= n;

    cout << ans.val() << endl;
    return 0;
}