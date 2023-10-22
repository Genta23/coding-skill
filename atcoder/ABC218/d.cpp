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
    vector<pair<int, int>> data(n);
    rep(i, n) cin >> data[i].first >> data[i].second;

    //multisetを使用する 整理したらすぐに解けそう
    

    map<int, int> mpx, mpy;
    rep(i, n) mpx[data[i].first]++;
    rep(i, n) mpy[data[i].second]++;

    rep(i, n){
        int x = data[i].first, y = data[i].second;

    }
    return 0;
}