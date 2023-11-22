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
    // 1WA オーバーフロー
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m), x(m), y(m);
    rep(i, m) cin >> a[i] >> b[i] >> x[i] >> y[i];

    rep(i, m) a[i]--, b[i]--;
    
    vector<vector<tuple<ll, ll, ll>>> g(n);// to , x, y;
    rep(i, m){
        g[a[i]].push_back({b[i], x[i], y[i]});
        g[b[i]].push_back({a[i], -x[i], -y[i]});
    }
    
    vector<bool> flag(n); flag[0] = true;
    queue<int> que; que.push(0);
    vector<pair<ll, ll>> ans(n); ans[0] = {0, 0};
    
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto x : g[v]){
            if(!flag[get<0>(x)]){
                flag[get<0>(x)] = true;
                que.push(get<0>(x));
                ans[get<0>(x)].first = ans[v].first + get<1>(x);
                ans[get<0>(x)].second = ans[v].second + get<2>(x);
            }
            else{
                if(ans[get<0>(x)].first != ans[v].first + get<1>(x)){
                    ans[get<0>(x)] = {infl+1, infl+1};
                }
                if(ans[get<0>(x)].second != ans[v].second + get<2>(x)){
                    ans[get<0>(x)] = {infl+1, infl+1};
                }
            }
        }
    }
    
    rep(i, n){
        if(flag[i]){
            if(ans[i].first == infl+1 && ans[i].second == infl+1){
                cout << "undecidable" << endl;
            }
            else{
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
        else{
            cout << "undecidable" << endl;
        }
    }
    return 0;
}