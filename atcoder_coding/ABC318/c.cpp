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
    ll n, d, p; cin >> n >> d >> p;
    vector<ll> f(n); rep(i, n) cin >> f[i];

    sort(f.begin(), f.end());
    float price = (float)p/d;
    auto itr = lower_bound(f.begin(), f.end(), price);
    int dis = distance(f.begin(), itr);
    int cnt = n - dis;

    //cout << cnt << endl;

    int cnt1 = cnt/d,  cnt2 = cnt/d + 1;

    sort(f.begin(), f.end(), greater<ll>());
    ll ans1 = cnt1*p;
    rep(i, n){
        if(i >= cnt1*d){
            ans1 += f[i];
        }
    }

    ll ans2 = cnt2*p;
    rep(i, n){
        if(i >= cnt2*d){
            ans2 += f[i];
        }
    }

    cout << min(ans1, ans2) << endl;
    return 0;
}