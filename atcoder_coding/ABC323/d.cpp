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
template<typename T> using max_priority_queue = priority_queue<T, vector<T>, less<T>>;

int main(){
    int n; cin >> n;
    map<ll, ll> data;
    rep(i, n){
        int x, y; cin >> x >> y;
        data[x] = y;
    }

    //下の方から再起的にやっていくのでは??
    //問題なのはサイズの種類が豊富なので...配列のサイズを十分に取ることができないこと
    ll ans = 0;
    while(data.size() != 0){
        auto v = data.begin();
        if(v->second/2 != 0) data[2*v->first] += v->second/2;
        ans += v->second % 2;
        data.erase(data.begin());
    }

    cout << ans << endl;
    return 0;
}