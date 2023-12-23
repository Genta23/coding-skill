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
using Graph = vector<vector<int>>;

int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(k);
    rep(i, k) cin >> a[i];

    ll ans = 0;
    if(k%2 == 0){
        rep(i, k){
            if(i%2 == 0){
                ans += (a[i+1]-a[i]);
            }
        }
        cout << ans << endl;
        return 0;
    }
    else{
        ll min = infl;
        rep(i, k){
            if(i == 0) continue;
            if(i%2 == 0){
                ans += (a[i]-a[i-1]);
            }
        }
        chmin(min, ans);
        rep(i, k){
            if(i == k-1) continue;
            if(i%2 == 0){
                ans += (a[i+1]-a[i]);
                ans -= (a[i+2]-a[i+1]);
                chmin(min, ans);
            }
        }
        cout << min << endl;
    }
    return 0;
}