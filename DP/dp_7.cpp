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
int cnt[1003][1003];

int main(){
    string s, t; cin >> s >> t;
    int s__ = s.size(), t__ = t.size();

    cnt[0][0] = 0;
    rep(i, s__){
        rep(j, t__){
            if(s[i] == t[j]) cnt[i+1][j+1] = cnt[i][j] + 1;
            else cnt[i+1][j+1] = max(cnt[i][j+1], cnt[i+1][j]);
        }
    }

    cout << cnt[s__][t__] << endl;
    return 0;
}