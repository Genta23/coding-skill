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
    vector<ll> t(n), d(n); rep(i, n) cin >> t[i] >> d[i];

    vector<ll> e(n); rep(i, n) e[i] = t[i] + d[i];

    vector<pair<ll, ll>> data(n);
    rep(i, n){
        data[i].first = t[i];
        data[i].second = e[i];
    }
    sort(data.begin(), data.end());

    ll piv = data[0].first;
    min_priority_queue<ll> que;
    ll ans = 0;
    auto itr = data.begin();
    while(itr != data.end()){
        // 時刻tに印字機に入るデータを全て優先度付きキューに挿入
        while((*itr).first == piv){
            que.push((*itr).second);
            itr++;
        }
        ll tmp = (*itr).first;

        // 次に新しい商品が印字機に入る場合処理を打ち切る
        while(piv != tmp){
            if(que.empty()){
                piv = tmp; // キューが空になったらtをスキップする
                break;
            }
            ll v = que.top(); que.pop();
            if(v < piv) continue;
            else{
                ans++;
                piv++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}