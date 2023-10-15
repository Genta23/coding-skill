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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ll a, b; cin >> a >> b;
    const int MOD = 998244353;
    //int v = floor(sqrt(a));

    int p = 2;
    map<int, int> data;
    while(1){
        if(a == 1) break;
        if(a%p == 0){
            data[p]++;
            a = a/p;
        }
        else{
            p++;
        }
    }

    ll cnt = 1;
    for (const auto& [k, v] : data) {
        cout << k << " " << v << endl;
        cnt *= (v+1);
    }

    ll ans = b;
    ans %= MOD;
    ans = ans*(ans-1)/2;
    ans %= MOD;
    ans += b;
    ans %= MOD;

    ll t = 1;
    for (const auto& [k, v] : data) {
        cout << k << " " << v << endl;
        t *= v*ans+1;
        t %= MOD;
    }

    cout << ans << endl;
    cout << t << endl;
    return 0;
}