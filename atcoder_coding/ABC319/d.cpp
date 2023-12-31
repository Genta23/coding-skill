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
    int n, m; cin >> n >> m;
    vector<ll> l(n); rep(i, n) {cin >> l[i]; l[i]++;}

    ll max = 0, sum = 0;
    rep(i, n){
        sum += l[i];
        chmax(max, l[i]); 
    }

    ll upper = sum;
    ll lower = max - 1;

    while(lower + 1 < upper){ // 二分探索の終了条件
        ll mid = (lower + upper) / 2;
        ll tmp = 0, cnt = 1;
        rep(i, n){
            if(tmp + l[i] > mid){
                cnt++, tmp = l[i];
            }
            else{
                tmp += l[i];
            }
        }
        if(cnt > m) lower = mid;
        else upper = mid;
    }
    cout << upper - 1 << endl;
    return 0;
}