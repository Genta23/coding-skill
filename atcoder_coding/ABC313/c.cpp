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
    ll n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    auto sum = accumulate(a.begin(), a.end(), 0);
    cout << typeid(ll).name() << endl;
    cout << typeid(sum).name() << endl;
    cout << typeid(0).name() << endl;;
    /*ll sum = 0;
    rep(i, n){
        sum += a[i];
    }*/
    ll p = sum / n, q = sum % n;
    ll cnt = 0;
    cout << p << " " << q << endl;
    sort(a.begin(), a.end());
    rep(i, n){
        if(i < n-q) cnt += abs(a[i] - p);
        else cnt += abs(a[i] - (p+1));
    }
    cnt /= 2;
    cout << cnt << endl;
    return 0;
}