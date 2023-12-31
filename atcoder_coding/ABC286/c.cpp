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
template<typename T> T floor_multiple(T k, T m){ return k - ((k%m+m)%m); }
using Graph = vector<vector<int>>;

int main(){
    // 偶数の要素と奇数の要素に着目する
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    ll ans = infl;
    rep(i, n){
        int __s = s.size() / 2;
        ll cnt = 0;
        rep(i, __s){
            if(s[i] != s[s.size()-1 - i]) cnt++;
        }

        chmin(ans, a*i + b*cnt);

        s = s.substr(1) + s[0];
        //cout << s << endl;
    }
    cout << ans << endl;
    return 0;
}