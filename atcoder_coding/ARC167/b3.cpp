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
#include <tuple>
#include <cassert>
#include <numeric>
//#include <atcoder/modint>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD = 998244353;
using namespace std;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// a ÷ b mod. MOD を計算してみる
int main() {
    ll a, b, p = 2; cin >> a >> b;
    map<int, int> data;
    /* これAが大きい素数だと計算量バグる */
    bool flag = false;
    while(1){
        if(a == 1) break;
        if(p*p > a) { data[a]++; break;}
        
        if(a%p == 0){
            a = a/p;
            data[p]++;
        }
        else p++; 
    }
    if(b%2 == 0) flag = true;
    b %= MOD;
    ll ans = b;
    for (const auto& [k, v] : data) {
        cout << k << " " << v << endl;
        ans *= b*v + 1;
        ans %= MOD;
        if((b%MOD)*(v%MOD)%MOD + 1 == 0) flag = true;
    }
    if(!flag) { ans--; ans = (ans + MOD) % MOD; }
    ans = (ans * modinv(2, MOD)) % MOD;
    cout << ans << endl;
    return 0;
}

//後日詳しくやる