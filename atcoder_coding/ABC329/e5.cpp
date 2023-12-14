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
    // オリジナル
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    rep(i, n-m+1){
        bool flag = true;
        rep(j, m){
            if(s[i+j] == '#') continue;
            if(s[i+j] != t[j]) flag = false;
        }
        if(flag) rep(j, m) s[i+j] = '#';
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    rep(i, n-m+1){
        bool flag = true;
        rep(j, m){
            if(s[i+j] == '#') continue;
            if(s[i+j] != t[j]) flag = false;
        }
        if(flag) rep(j, m) s[i+j] = '#';
    }

    string ans;
    rep(i, n) ans += '#';

    cout << ((ans==s) ? "Yes" : "No") << endl;
}