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

    vector<ll> deadline(n);
    rep(i, n) deadline[i] = t[i] + d[i];

    multiset<pair<ll, ll>> st;
    rep(i, n) st.insert({deadline[i], t[i]});

    ll piv = (*st.begin()).second;
    int cnt = 0;
    for(auto x : st){
        ll dead = x.first;
        ll start = x.second;
        //cout << x.first << " " << x.second << endl;

        if(piv > dead) continue;
        else if(piv < start){
            //cout << "1 : " << piv << endl;
            piv = start;
            cnt++;
            piv++;
        }
        else{
            //cout << "2 : " << piv << endl;
            cnt++;
            piv++;
        }
    }
    cout << cnt << endl;
    return 0;
}