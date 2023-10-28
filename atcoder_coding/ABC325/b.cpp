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
    int n; cin >> n;
    vector<pair<ll, ll>> data(n); rep(i, n) cin >> data[i].first >> data[i].second;
    vector<ll> ans(48);
    rep(i, n){
        for(int j=9; j<18; j++){
            ans[j+data[i].second] += data[i].first;
        }
    }

    ll f_ans = 0;
    rep(i, 24){
        if(f_ans < ans[i] + ans[i+24]) f_ans = ans[i] + ans[i+24];
    }
    cout << f_ans << endl;
    return 0;
}