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

int Hs(string s){
    int b = 30, m = 1000003;
    int val = 0;
    rep(i, s.size()){
        val *= b;
        val += (s[i] - 'a'+1);
        val %= m;
    }
    return val;
}

int main(){
    int n; cin >> n;
    vector<string> s(n); rep(i, n) cin >> s[i];

    map<int, int> mp;
    rep(i, n) mp[Hs(s[i])]++;

    int ans = 0;
    for(auto v : mp) chmax(ans, v.second);

    cout << ans << endl;
    return 0;
}