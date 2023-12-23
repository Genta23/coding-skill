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
#define rep(i,n) for (int i=0; i<n; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
using Graph = vector<vector<int>>;

vector<pair<char,ll>> runlength(string s) {
    int x = s.size();
    vector<pair<char,ll>> res;
    char pre = s[0];
    ll cnt = 1;
    for(int i=1; i<x; i++) {
        if(pre !=s [i]) {
            res.push_back({pre,cnt});
            pre=s[i]; cnt=1;
        } else cnt++;
    }
    res.push_back({pre,cnt});
    return res;
}

int main() {
    string s; cin >> s;
    auto rl = runlength(s);

    // トリボナッチの計算
    vector<ll> tri(3,0);
    tri[2]=1;
    for(int i=3;i<=60;i++) tri.push_back(tri[i-1]+tri[i-2]+tri[i-3]);

    ll ans=1;
    for(auto u : rl) if(u.first == 'x') ans *= tri[u.second+3]; //ずれの修正

    cout << ans << endl;
    return 0;
}






