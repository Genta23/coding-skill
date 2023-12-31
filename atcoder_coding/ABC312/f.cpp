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
    
    ll ans = 0;
    rep(i, n) if(t[i] == 0) ans += x[i];

    vector<int> o1, o2;
    rep(i, n){
        if(t[i] == 1) o1.push_back(i);
        if(t[i] == 2) o2.push_back(i);
    }

    // 1のタイミングとその後の2のタイミングを記録
    // 2の満足度の高い順で取れるかの判定を行い、直前の1のxをディクリメントする
    vector<pair<ll, int>> order;
    rep(i, n) if(t[i] == 2) order.push_back({x[i], i});
    sort(order.begin(), order.end());


    rep(i, order.size()){
        int x_ = order[i].first;
        int itr_2 = order[i].second;
        auto e = upper_bound(o1.begin(), o1.end(), itr_2);
        int itr_1 = distance(o1.begin(), e);
        
        if(itr_1 == 0) continue;
        itr_1--;
        if(x[o1[itr_1]] > 0){
            x[o1[itr_1]]--;
            if(x[o1[itr_1]] == 0);
        } //vectorは削除に時間かかるからsetで保持する必要がある


        /*if(e == o1.begin()) continue; // これダメな理由あとで調べる
        e--;
        cout << o1[*e] << endl;*/
    }
    return 0;
}