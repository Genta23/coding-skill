#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

int main(){
    int n; cin >> n;
    string s; cin >> s;
    sort(s.begin(), s.end());
    ll max_value = pow(10, n);
    int ans = 0;
    for(ll i=0; i*i<max_value; i++){
        string t = to_string(i*i);
        t.resize(n, '0');
        sort(t.begin(), t.end());
        if(s == t) ans++;
    }
    cout << ans << endl;
    return 0;
}