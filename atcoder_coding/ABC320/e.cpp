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
    int n, m; cin >> n >> m;
    vector<ll> t(m), w(m), s(m);
    rep(i, m){
        cin >> t[i] >> w[i] >> s[i];
    }

    // 1WA because of overflow
    min_priority_queue<tuple<ll, ll, ll>> que;
    set<ll> st;

    rep(i, m){
        que.push({t[i], 2, i});
    }
    rep(i, n){
        st.insert(i);
    }
    vector<ll> ans(n);
    // 誰もそうめんを得ないときがある
    // 同時刻にイベントが起こる時の順序がおかしい
    while(!que.empty()){
        auto v = que.top(); que.pop();
        if(get<1>(v) == 2){
            if(!st.empty()){
                que.push({get<0>(v) + s[get<2>(v)], 1, *st.begin()});
                ans[*st.begin()] += w[get<2>(v)];
                st.erase(st.begin());
            }
        }
        if(get<1>(v) == 1){
            st.insert(get<2>(v));
        }
    }
    
    rep(i, n){
        cout << ans[i] << endl;
    }

    // 最小値を判定するのであればsetを利用するべき
    return 0;
}