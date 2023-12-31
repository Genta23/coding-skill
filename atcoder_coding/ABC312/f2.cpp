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
    int n, m; cin >> n >> m;
    vector<ll> t(n), x(n); rep(i, n) cin >> t[i] >> x[i];

    set<int> o2;
    rep(i, n){
        if(t[i] == 2) o2.insert(i);
    }

    // 1のタイミングとその後の2のタイミングを記録
    // 2の満足度の高い順で取れるかの判定を行い、直前の1のxをディクリメントする
    vector<pair<ll, int>> order;
    rep(i, n) if(t[i] == 0 || t[i] == 1) order.push_back({x[i], i});
    sort(order.begin(), order.end());

    ll ans = 0;
    rep(i, order.size()){
        if(t[order[i].second] == 0){
            m--;
            ans += x[order[i].second];
        }
        else{
            auto e = o2.upper_bound(order[i].second);
            if(e == o2.begin()) continue;
            e--;

            if(x[*e] > 0){
                m--;
                ans += x[order[i].second];
                x[*e]--;
                if(x[*e] == 0){
                    o2.erase(e);
                }
            }
        }
        //int itr_1 = distance(o1.begin(), e); //これに時間かかるやんけ
    }
    cout << ans << endl;
    return 0;
}