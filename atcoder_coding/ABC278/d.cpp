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
    vector<ll> a(n); rep(i, n) cin >> a[i];
    int q; cin >> q;

    ll base = 0;
    vector<ll> add(n);
    queue<int> que;
    bool flag = false;
    rep(i, q){
        int tmp; cin >> tmp;
        if(tmp == 1){
            ll x; cin >> x;
            flag = true;
            base = x;
            while(!que.empty()){
                ll v = que.front(); que.pop();
                add[v] = 0;
            }
        }
        else if(tmp == 2){
            int i, x; cin >> i >> x; i--;
            add[i] += x;
            que.push(i);
        }
        else if(tmp == 3){
            ll i; cin >> i; i--;
            if(!flag) cout << a[i] + add[i] << endl;
            else cout << base + add[i] << endl; 
        }
    }
    return 0;
}