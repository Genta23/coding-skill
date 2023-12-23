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
    ll n, q; cin >> n >> q;
    vector<ll> r(n);
    rep(i, n) cin >> r[i];

    sort(r.begin(), r.end());
    vector<ll> s(n);
    s[0] = r[0];
    for(int i=1; i<n; i++){
        s[i] = s[i-1] + r[i];
    }

    rep(i, q){
        ll tmp; cin >> tmp;
        auto it = upper_bound(s.begin(), s.end(), tmp);
        ll d = distance(s.begin(), it);
        cout << d << endl;
    }
    return 0;
}