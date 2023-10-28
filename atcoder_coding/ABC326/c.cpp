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
    int n, m; cin >> n >> m;
    vector<ll> a(n); rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    int max = 0;
    rep(i, n){
        auto dl = lower_bound(a.begin(), a.end(), a[i]);
        auto dr = lower_bound(a.begin(), a.end(), a[i]+m);
        int dis = distance(dl, dr);
        chmax(max, dis);
    }
    cout << max << endl;
    return 0;
}