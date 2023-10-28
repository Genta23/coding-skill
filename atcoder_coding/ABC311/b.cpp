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
    int n, d; cin >> n >> d;
    vector<string> s(n); rep(i, n) cin >> s[i];
    vector<int> ans(d);
    rep(i, n){
        rep(j, d){
            if(s[i][j] == 'x') ans[j]++;
        }
    }

    int max = 0, cnt = 0;
    rep(i, d){
        if(ans[i] == 0) cnt++;
        else cnt = 0;

        chmax(max, cnt);
    }
    cout << max << endl;
    return 0;
} 