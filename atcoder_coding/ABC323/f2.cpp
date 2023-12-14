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
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    bool flag_bc = true;
    if(xb == xc) flag_bc = false;
    if(yb == yc) flag_bc = false;

    bool flag_abc = true, flag_ab = false;
    if((xa < xb && xb < xc) || (xc < xb && xb < xa)) flag_abc = false;
    else if((ya < yb && yb < yc) || (yc < yb && yb < ya)) flag_abc = false;
    else{ if((xa == xb && xb == xc) || (ya == yb && yb == yc)) flag_ab = true; } 
    // else{ if(!flag_bc) flag_ab = true; } // 弾けない例はb, cならんでいて、aだけ違うケースだった 条件不足
    
    ll ans = 0;
    ans += (abs(xa - xb) + abs(ya - yb));
    ans += (abs(xb - xc) + abs(yb - yc));
    ans += (flag_bc ? 2 : 0);
    ans += (flag_abc ? 1 : -1);
    ans += (flag_ab ? 2 : 0);

    cout << ans << endl;
    return 0;
}