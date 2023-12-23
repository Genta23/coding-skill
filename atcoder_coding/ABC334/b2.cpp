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

int main(){
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    a %= m;

    l -= a;
    r -= a;

    if(r == 0 && l == 0) cout << 1 << endl;
    else if(r == 0 && l < 0) cout << - l/m + 1 << endl;
    else if(l == 0 && r > 0) cout << r/m + 1 << endl;
    else if(r > 0 && l > 0){
        if(l%m == 0) cout << r/m - l/m + 1 << endl;
        else cout << r/m - l/m << endl;
    }
    else if(r > 0 && l < 0){
        cout << r/m - l/m + 1 << endl;
    }
    else if(r < 0 && l < 0){
        if(r%m == 0) cout << r/m - l/m + 1 << endl;
        else cout << r/m - l/m << endl;
    }

    return 0;
}