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
    vector<ll> x(n), y(n);
    vector<int> z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    int z_cnt = 0;
    int z_th = 0;
    rep(i, n){
        z_th += z[i];
    }
    vector<bool> z_flag(n);
    rep(i, n){
        if(x[i] > y[i]) z_cnt += z[i], z_flag[i] = true;
    }
    z_th /= 2;
    z_th++;

    if(z_cnt >= z_th){
        cout << 0 << endl;
        return 0;
    }

    vector<pair<ll, int>> memo;
    rep(i, n){
        if(!z_flag[i]){
            memo.push_back({(x[i]+y[i])/2 + 1 - x[i], i}); //ここの数の考え方特殊　平均との関係値
        }
    }

    sort(memo.begin(), memo.end());
    rep(i, n) cout << memo[i].first << " ";
    cout << endl;
    ll ans = 0;
    rep(i, memo.size()){
        ans += memo[i].first;
        z_cnt += z[memo[i].second];
        if(z_cnt >= z_th){
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}