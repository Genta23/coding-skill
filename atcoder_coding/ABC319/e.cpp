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

int main(){
    int n; ll x, y; cin >> n >> x >> y;
    vector<ll> p(n-1), t(n-1); rep(i, n-1) cin >> p[i] >> t[i];
    int q; cin >> q;
    vector<int> query(q); rep(i, q) cin >> query[i];

    int mod = 840;
    vector<ll> data(mod);

    rep(i, mod){
        ll time = 0;
        time += x;
        rep(j, n-1){
            int r = (i+time) % p[j];
            if(r != 0) time += (p[j] - r); // 割り切れる時は何も足さない //whileからに改訂も書いておく
            time += t[j];
        }
        time += y;
        data[i] = time;
    }

    rep(i, q) cout << query[i] + data[query[i]%mod] << endl;
    return 0;
}