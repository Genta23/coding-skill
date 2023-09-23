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
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll infl = 1e18;
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
    ll n, m, p; cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> sum_b(m);
    rep(i, m){
        if(i == 0) sum_b[i] = b[i];
        else sum_b[i] = sum_b[i-1] + b[i];
    }

    ll ans = 0;
    rep(i, n){
        int point = p - a[i];

        int cnt = 0;
        if(point <= 0){
            ;
        }
        else{
            auto q = upper_bound(b.begin(), b.end(), point);
            cnt = distance(b.begin(), q);
        }

        if(cnt == 0) ans += p*m; //ここでオーバーフローしたと...
        else  ans += (ll) a[i]*cnt + sum_b[cnt-1] + (ll) p*(m-cnt);
    }
    cout << ans << endl;
    return 0;
}