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
const int MOD = 998244353;

int main(){
    int t; cin >> t;
    rep(i, t){
        ll n; cin >> n;
        ll y = (ll)floor(sqrt(n-1))+10;
        while(y*y>n)y--;
        //if(y >= 100000) y = (ll)floor(sqrt(n-y));
        ll x = n - y*y;
        if(x == 0){
            y--;
            x = n - y*y;
        }
        //cout << y << endl;
        if(x < y) cout << (y-1)*(y-1) + 2*x << endl;
        else cout << y*y << endl;
    }
    return 0;
}