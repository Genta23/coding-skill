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
    int n, k; cin >> n >> k;
    vector<pair<int, int>> data(n);
    rep(i, n) cin >> data[i].first >> data[i].second;

    int x_min = inf, x_max = 0, y_min = inf, y_max = 0;
    rep(i, n){
        chmin(x_min, data[i].first);
        chmax(x_max, data[i].first);
        chmin(y_min, data[i].second);
        chmax(y_max, data[i].second);
    }

    vector<int> cnt(8);
    rep(i, n){
        int x = data[i].first, y = data[i].second;
        if(x == x_min && y == y_min) cnt[0]++;
        else if(x == x_max && y == y_min) cnt[2]++;
        else if(x == x_max && y == y_max) cnt[4]++;
        else if(x == x_min && y == y_max) cnt[6]++;
        else if(y == y_min) cnt[1]++;
        else if(x == x_max) cnt[3]++;
        else if(y == y_max) cnt[5]++;
        else if(x == x_min) cnt[7]++;
    }
    rep(i, 8) cout << cnt[i] << " ";
    cout << endl;

    cout << max(x_max - x_min, y_max - y_min) << endl;
    return 0;
}