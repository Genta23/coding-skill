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
    int n; cin >> n;
    vector<ll> data(100000);
    data[0] = 0;
    for(int i=1; i<100000; i++){
        data[i] = data[i-1]*2 + i;
        data[i] %= MOD;
    }
    cout << data[n-1] << endl;
    return 0;
}