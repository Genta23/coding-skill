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
//ll sq[2000007];
int main(){
    ll d; cin >> d;

    vector<ll> sq(2000000);
    rep(i, 2000000){
        sq[i] = i*i;
    }

    ll ans = infl;
    rep(i, 2000000){
        if(d-sq[i] >= 0){
            auto d1 = lower_bound(sq.begin(), sq.end(), d-sq[i]);
            int dd1 = distance(sq.begin(), d1);
            chmin(ans, abs(sq[i] + sq[dd1] - d)); 
        }
        //auto d2 = upper_bound(sq.begin(), sq.end(), d-sq[i]);
        //int dd2 = distance(sq.begin(), d2);
        //chmin(ans, min(abs(sq[i] + sq[dd1] - d), abs(sq[i] + sq[dd1-1] - d)));
        //chmin(ans, abs(sq[i] + sq[dd1] - d));
        //if(dd1 != 0) chmin(ans, abs(sq[i] + sq[dd1-1] - d));
        //chmin(ans, abs(sq[i] + sq[dd2] - d));
    }
    cout << ans << endl;
    return 0;
}