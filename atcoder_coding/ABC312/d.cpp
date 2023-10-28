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
template<typename T> bool checker(T s, T t, T s__, T t__){ return ((s >= 0 && t >= 0 && s < s__ && t < t__) ? true : false); }
const int MOD = 998244353;
int cnt[1600][1600];

int main(){
    string s; cin >> s;
    int s__ = s.size();

    if(!(s__%2 == 0)) { cout << 0 << endl; return 0; }
    int n__ = s__/2;
    cnt[0][0] = 1; //第一<=第二とする
    rep(i, n__+1){
        rep(j, n__+1){
            if(i > j) cnt[i][j] = 0;

            if(s[i+j] == '?' || s[i+j] == '('){
                cnt[i][j+1] += cnt[i][j];
                cnt[i][j+1] %= MOD;
            }
            if(s[i+j] == '?' || s[i+j] == ')'){
                cnt[i+1][j] += cnt[i][j];
                cnt[i+1][j] %= MOD;
            }
        }
    }
    cout << cnt[n__][n__] << endl;

    return 0;
}