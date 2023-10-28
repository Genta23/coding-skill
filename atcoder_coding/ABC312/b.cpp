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
    vector<string> s(n); rep(i, n) cin >> s[i];
    // チェックを行う回数は 32回
    //n-9+1 * m-9+1回のチェックが入る
    string c[] = {"###.", "....", ".###"};
    rep(i, n-9+1){
        rep(j, m-9+1){
            if(s[i].substr(j, 4) != c[0]) continue;
            if(s[i+1].substr(j, 4) != c[0]) continue;
            if(s[i+2].substr(j, 4) != c[0]) continue;
            if(s[i+3].substr(j, 4) != c[1]) continue;

            if(s[i+5].substr(j+5, 4) != c[1]) continue;
            if(s[i+6].substr(j+5, 4) != c[2]) continue;
            if(s[i+7].substr(j+5, 4) != c[2]) continue;
            if(s[i+8].substr(j+5, 4) != c[2]) continue;

            cout << i+1 << " " << j+1 << endl;
        }
    }
    return 0;
}