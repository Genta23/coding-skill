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
    ll n, m; cin >> n >> m;
    vector<ll> a(m); rep(i, m) cin >> a[i];
    int q; cin >> q;
    vector<pair<ll, ll>> data(q); rep(i, q) cin >> data[i].first >> data[i].second;

    vector<pair<ll, ll>> comp; // 始点終点

    ll cnt = 1, pos = a[0];
    vector<ll> start, goal;
    for(int i=1; i<m; i++){
        if(a[i] == pos + cnt){
            cnt++;
        }
        else{
            comp.push_back({pos, pos + cnt});
            start.push_back(pos);
            goal.push_back(pos + cnt);
            cnt = 1;
            pos = a[i];
        }
    }
    comp.push_back({pos, pos + cnt});
    start.push_back(pos);
    goal.push_back(pos + cnt);

    //rep(i, comp.size()) cout << comp[i].first << " " << comp[i].second << endl;

    rep(i, q){
        ll l = data[i].first, r = data[i].second;
        auto it = upper_bound(start.begin(), start.end(), l);
        /*if(it = start.end()){
            cout << 
        }*/
        ll d0 = distance(start.begin(), it);
        if(d0 == 0){
            cout << l << endl;
        }
        else if(d0 > 0){
            if(l < comp[d0-1].second){
                //　範囲内
                if(r < comp[d0-1].second){
                    cout << -1 << endl;
                }
                else{
                    cout << comp[d0-1].second << endl;
                }
            }
            else{
                // 範囲外
                cout << l << endl;
            }
        }
    }
    return 0;
}