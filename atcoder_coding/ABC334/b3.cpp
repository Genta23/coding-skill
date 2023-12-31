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
    
    // mの倍数で考えれるようにする
    l -= a, r -= a;

    // l未満で最大のmの倍数 -> l-1以下で最大のmの倍数、r以下で最大のmの倍数を考える
    ll l_m = (l-1) - ((l-1)%m + m) % m;
    ll r_m = r - (r%m + m) % m;

    cout << r_m/m - l_m/m << endl;
    return 0;
}