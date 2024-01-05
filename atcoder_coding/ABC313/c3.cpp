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
#define rep(i,n) for (ll i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    int n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) sum += a[i];
    
    ll p = sum/n;
    ll q = sum%n;

    sort(a.begin(), a.end());
    //rep(i, n) cout << a[i] << " ";
    //cout << endl;

    ll up = 0, down = 0;
    rep(i, n){
        ll th;
        if(i < n-q) th = p;
        else th = p+1;

        if(th > a[i]) up += (th - a[i]);
        else down += (a[i] - th);
    }
    cout << max(up, down) << endl;
    return 0;
}