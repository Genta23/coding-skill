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
#include <atcoder/modint>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD = 998244353;
using mint=atcoder::modint998244353;

int main(){
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
    mint ans = b;
    for (const auto& [k, v] : data) {
        ans *= b*v + 1;
        if(v%2 == 1) flag = true;
    }
    if(!flag) ans--;
    ans = ans/2;
    cout << ans.val() << endl;
    return 0;
}

//modで割られるタイミングが色々あるから12もmod7で5つまり偶奇はそこのみでは判別できない