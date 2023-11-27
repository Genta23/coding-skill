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
    int n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<ll> a(n), b(n);
    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            if(s[i][j] == 'o') cnt++;
        }
        a[i] = cnt;
    }
    //rep(i, n) cout << a[i] << " ";
    //cout << endl;

    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            if(s[j][i] == 'o') cnt++;
        }
        b[i] = cnt;
    }
    //rep(i, n) cout << b[i] << " ";
    //cout << endl;

    ll ans = 0;
    rep(i, n){
        rep(j, n){
            if(s[i][j] == 'o') ans += (a[i]-1)*(b[j]-1);
        }
    }
    cout << ans << endl;
    return 0;
}