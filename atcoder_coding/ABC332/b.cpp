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

int main(){
    ll k, g, m; cin >> k >> g >> m;

    ll gg = 0, mm = 0;
    rep(i, k){
        //cout << gg << " " << mm << endl;
        if(gg == g){
            gg = 0;
        }
        else if(mm == 0){
            mm = m;
        }
        else{
            if(g - gg >= mm){
                gg += mm;
                mm = 0;
            }
            else{
                mm -= (g - gg);
                gg = g;
            }
        }
    }

    cout << gg << " " << mm << endl;
    return 0;
}