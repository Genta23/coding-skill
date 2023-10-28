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
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n, vector<ll>(n)); rep(i, n) rep(j, n) cin >> d[i][j];

    vector<bool> flag_car(n);
    vector<ll> car_time(n, infl);
    flag_car[0] = true;
    car_time[0] = 0;
    int v = 0;

    rep(i, n){
        ll min = infl;
        rep(j, n){
            chmin(car_time[j], car_time[v] + d[v][j]*a);
        }
        rep(j, n){
            if(!flag_car[j] && chmin(min, car_time[j])) v = j;
        }
        flag_car[v] = true;
    }

    vector<bool> flag_train(n);
    vector<ll> train_time(n, infl);
    flag_car[n-1] = true;
    train_time[n-1] = 0;
    v = n-1;

    rep(i, n){
        ll min = infl;
        rep(j, n){
            chmin(train_time[j], train_time[v] + d[v][j]*b + c);
        }
        rep(j, n){
            if(!flag_train[j] && chmin(min, train_time[j])) v = j;
        }
        flag_train[v] = true;
    }

    ll ans = infl;
    rep(i, n){
        chmin(ans, car_time[i] + train_time[i]);
    }
    cout << ans << endl;
    return 0;
}