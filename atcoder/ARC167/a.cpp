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
    int n, m; cin >> n >> m;
    vector<int> a(n); rep(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    vector<ll> ans(m);
    int f;
    rep(i, m) ans[i] = a[i];
    rep(i, n-m) ans[m-1 - i] += a[m + i];

    ll unb = 0;
    rep(i, m) unb += ans[i]*ans[i];
    
    cout << unb << endl;
    return 0;
}