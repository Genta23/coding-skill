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
    ll n, a, b; cin >> n >> a >> b;
    ll c = lcm(a, b);

    ll na = a*(n/a)*(n/a + 1)/2;
    ll nb = b*(n/b)*(n/b + 1)/2;
    ll nc = c*(n/c)*(n/c + 1)/2;
    ll all = n*(n+1)/2;
    
    cout << all - na - nb + nc << endl;
    return 0;
}