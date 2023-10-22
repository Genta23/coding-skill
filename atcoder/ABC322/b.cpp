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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    bool flag_front = true;
    rep(i, n){
        if(s[i] == t[i]){
            ;
        }
        else{
            flag_front = false;
        }
    }

    bool flag_back = true;
    rep(i, n){
        if(s[i] == t[m-n+i]){
            ;
        }
        else{
            flag_back = false;
        }
    }

    if(flag_front && flag_back) cout << 0 << endl;
    else if(flag_front) cout << 1 << endl;
    else if(flag_back) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}